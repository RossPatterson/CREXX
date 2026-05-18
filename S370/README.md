# CREXX for CMS370

## Contents
* [Status](#status)
* [Issues Encountered](#issues-encountered)

## Status
As of 2026-08-07:

* GitHub build for CMS370 works as well as can be tested with code in its
  current state.  All other builds have been disabled, but should be re-enabled
  at completion of this work.
* Several parts build and can at least run and print their versions:
  * rxas
  * rxcpack
  * rxlink
  * rxdas
* Compiler compiles, but cannot be linked because of a dependency on
  interpreter.
* This build has only been tested with VM/370 Community Edition 1.1.2,
  but should work on any system based on VM/370 Release 6 (_e.g._, the SixPack
  series), as long as it has `bREXX`, `GCC`, the native-CMS `GCCLIB` C library,
  and `VMARC`.  In a pinch, the `CMSMAKE EXEC` could be easily re-written in
  "EXEC Classic", if `bREXX` is not available.

## Issues Encountered

In no particular order:

1. Problem: GitHub & Docker issues
   Resolution: Switched to `rosspatterson/vm370:builder`.
2. Problem: Building `DSL-Syntax-Highlighter` requires a higher version of
   `CMAKE` than `Ubuntu` provides.
   Resolution: Added install of `cmake` 3.31 to GitHub `build.yml` for `vm/370`
   platform.
   Notes:
	  1. I can't remember why 3.29 wasn't good enough.
3. Problem: No CMS370 C++ compiler
   Resolution: Modified `build.yml` for `vm/370` to build and run them on the
   Ubuntu host machine, and upload their output as part of the source code.
4. Problem: Duplicate extername symbols cause CMS loader errors.
   Resolution:
     1. Make all the "inline" functions (`RX_INLINE`, `RX_MOSTLYINLINE`, and
	    `RX_FLATTEN`) static.
5. Problem: CMS's GCCLIB lacks stdlib's strdup()
   Resolution: Wrote one and added it to `cmsutil.c`.
   Notes:
6. Problem:  CMS's GCC can't compile rxvmintp.c because it's too large.
   Resolution: None yet.
   Notes:
     1. Attempted to use the same technique as `compiler/rxcpbgmr.c` below,
	    which partially worked, but `run()` is too large or complex even when
		compiled on its own.
	 2. Attempted to use something more like the "threaded" interpreter instead
	    of the `switch` mechanism, but it didn't help.
7. Problem: `S370/cmsbuild.sh` is out of date
   Resolution: Added lots of things :-)
8. Problem: Source filenames (the "xxx" portion of `xxx.c`) are limited to 8 characters.
   Resolution: Created `S370/cmsfixc.sh` to rename all long `xxx.c` files to
   shorter names.  Changed `S370/cmsmake.exec` to use the new names.
   Notes: Filetypes (the "c" portion) are similarly limited, but C code rarely
   hits that limit.
9. Problem: Header filenames (the "xxx" portion of `xxx.h`) are limited to 8 characters.
   Resolution: Created `S370/cmsfixh.sh` to rename all long `xxx.h` files to
   shorter names, and to change all "`#include`" lines in all `xxx.c` files
   to include them by the new names.
10. Problem: CMS GCCLIB doesn't have some header files.
    Resolution: Searched all .c files for header files and created the missing
    ones, containing only "#error This header does not exist in CMS" to make
    compilation fail if they are actually included.  Updated `S370/cmsfixh.sh`
    to include them by the new names instead.
    Notes:
	  1. Most aren't included in a CMS370 compilation.  When this project is
	     complete, they should be deleted.
11. Problem: Non-static symbols (what CMS calls "entry symbols") are limited to
    8 characters.
    Resolution: Started to write `S370/cmsfns.h` to rename all long functions
    in all `xxx.h` files to shorter names via
    "`#define LongFunctionName LngFnam`", using unique and mnemonic
    abbreviations.  Gave up after seeing there were over 700 of them, and
    wrote a program to give the rest unique meaningless names (_e.g._,
    `_FN1234`).  Modified all `xxx.h` files to `#include "cmsfns.h"` to get
    the renames.
    Notes:
      1. This makes debugging harder, and someone whose eyes aren't glazed over
          by this might want to finish assigning mnemonic names.
      2. Just to make things even harder, several functions in different files
         share the same name, or share names with static functions in other
         files, so `S370/cmsfns.h` needs to know which header file it's
         being included from.
12. Problem: `S370/cmsbuild.sh` is out of date
    Resolution: Added some stuff :-)
13. Problem: `S370/cmsmake.exec` is out of date
    Resolution: Rewrote it almost entirely.  Will probably rewrite it again
    once this build is fully working.
    Notes:
14. Problem: The "Level B" parser assembler code is too large to write to disk.
    Resolution: Copied and modified the Lemon parser template file
    (`lemon\lempar.c` -> `lemon\lempar-rxcpbgmr.c`), and wrote
    `S370/cmsparpp.sh`, to make it possible to compile each section of the
    parser separately, producing output files `rxcpb03.c` through `rxcpb10.c`,
    which are then linked together.
    Notes:
      1. This is only done for CMS370 builds.  All other builds use the
         modified template, but the modifications are ignored via `#ifdef`s.
15. Problem: CMS's GCCLIB lacks strings.h.
    Resolution: Wrote `S370/strings.h` and wrote `strcasecmp()` and
    `strncasecmp()` in `S370/cmsutil.c` based on the existing `strcmp()` and `strncmp()`.
16. Problem: `S370/stdint.h` is missing some things.
    Resolution: Added some `typedef`s and `#define`s.
17. Problem: `assembler/rxasscan.re` has hard-coded Unicode values 0xc2
    (A-hat?) and 0xa7 (section symbol) in the `id` production, but those are
    EBCDIC letters "A" and "x".  Causes compilation errors in `rxasscan.c`.
    Resolution: Temporarily changed `id` to
    `(letter | [_]) (letter | digit | [_\-.#])*;`.
    Notes:
      1. This needs a proper fix.
18. Problem: There are lots of long function names that are not in any header
    file.
    Resolution: Added them to the ever-growing list in `S370/cmsfns.h`.
    Notes: They probably need to be changed to `static` instead    .
19. Problem: The `yata` tool happily replaces files when extracting on CMS.
    Resolution: Renamed the files to fix #8 above.
    Notes:
      1. Given `yata`'s intended purpose, this should probably be a fatal
    error instead.  For example, `crexxsaa_tool.c` and `crexxsaa.c` both get
    written to `CREXXSAA C`, and which one survives depends upon their order in
    the input `archive.yata` file.
20. Problem: `meta_narg()` is defined in both r`xcp_ctx.h` and `rxcp_emit.h`
    and `rxcp_exit_bridge_invoke()` is defined in both `rxcpmain.h` and
    `rxcp_exit.h`.
    Resolution: Ignored it.
21. Problem: The VM/370 Docker container needs a small update to Hercules to
    make `hercctl` reliable.
    Resolution: Updated Hercules 3.13 "spinhawk" and pinned the container to
    Ubuntu 24.04 "Noble", because Hercules 3.13 can't be compiled with the GCC
    versions on later Ubuntu releases.
    Notes:
      1. The "Spinhawk" update was done some time ago for bREXX, but this build
         needs it too.
      2. Considered switching to SDL Hercules 4.x "Hyperion", but building it
         is a nightmare compared to "Spinhawk".
22. Problem: `compiler/rxcp_opt.c` `#ifdef NUTF8` is wrong.
    Resolution: Replaced `#ifdef NUTF8` with `#ifndef NUTF8`
    Notes:
23. Problem: `compiler/rxcp_val_sym.c` includes `utf.h` on non-UTF-8 platforms.
    Resolution: `#ifndef NUTF8`'ed it out.
24. Problem: `interpreter/rxvmvars.h` uses 64-bit ints.
    Symptom: GCC internal errors when compiling
    Resolution: Modified `extract_double_decimal()` and `number_of_digits()` to
    honor `#define __32BIT__`.
25. Problem: `platform/platform.c` defines functions that are also in
    `S370/cmsutil.c`
    Resolution: `#ifndef __CMS__`'ed out `file2buf()`, `fileexists(), and
    `openfile()`.
    Notes:
      1. Maybe those belong in a separate "platform/unix.c"?
