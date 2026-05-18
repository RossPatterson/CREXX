# Limitations of VM/370 CMS

* Non-static symbols (what CMS calls "entry symbols") are limited to 8
  characters.
* Duplicate extername symbols will cause loader errors.
* Filenames (the "xxx" portion of `xxx.c` _etc_) are limited to 8 characters.
  Filetypes (the "c" portion) are too, but C code rarely hits that limit
* Non-static symbols cannot contain "_".  GCC solves this for most cases, by
  converting "_" to "@", but not for main-control-section (CSECT) names.

# Notes on building CREXX for VM/370 CMS

* The VM/370 build has only been tested with VM/370 Community Edition 1.1.2,
  but should work on any system based on VM/370 Release 6 (_e.g._, the SixPack
  series), as long as it has `bREXX`, `GCC`, the native-CMS `GCCLIB` C library,
  and `VMARC`.  In a pinch, the `CMSMAKE EXEC` could be easily re-written in
  "EXEC Classic", if `bREXX` is not available.

* The VM/370 build builds a few things in the Linux container that runs Hercules,
  because they are C++ and we don't have a VM/370 C++ compiler.

* The Docker container used by the VM/370 build is pinned to Ubuntu 24.04
  "Noble", because it needs a small update to Hercules, and Hercules 3.13 (the
  version on Ubuntu) can't be compiled with the GCC versions on later Ubuntu
  releases.

* The `.github/workflows/build.yml` `Update toolchain (CMS)` step downloads
  `cmake` version 3.31 becuase Ubuntu 24.04 doesn't have anything newer than
  `cmake` 2.38.3, and while that's good enough for `crexx`, it isn't good enough
  for `DSL Syntax Highlighter`, which `crexx` includes.

* A bunch of source files have long names with collisions in the first 8
  characters.  These will need to be renamed before building the YATA file for
  upload to CMS.

* Any renamed files will need to be #defined to make #include and linking
  work correctly.

* YATA happily replaces files when extracting on CMS.  Given its intended
  purpose, this should probably be a fatal error instead.  For example,
  `crexxsaa_tool.c` and `crexxsaa.c` both get written to `CREXXSAA C`, and
  which one survives depends upon their order in the input `archive.yata`
  file.

* `meta_narg()` is defined in both r`xcp_ctx.h` and `rxcp_emit.h`.
* `rxcp_exit_bridge_invoke()` is defined in both `rxcpmain.h` and `rxcp_exit.h`.

* There are lots of long function names that are not in any header file.  They
  probably need to be `static`.

* What are the CMAKE options, and how should they be set for CMS?
  * ENABLE_PARSER_MODE

* `assembler/rxasscan.re` has hard-coded Unicode values 0xc2 (A-hat?) and 0xa7
  (section symbol) in the `id` production, but those are EBCDIC letters "A"
  and "x".  Causes compilation errors in `rxasscan.c`.

