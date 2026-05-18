#!/usr/bin/bash
# Make CREXX on CMS

# Exit if there is an error
set -euo pipefail

# Show the commands
set -x

# Start Hercules.
. /usr/local/hercules/setup.sh
(cd /opt/hercules/vm370 ; hercules -f hercules.conf >/dev/null 2>/dev/null -d) &
# (cd /opt/hercules/vm370 ; hercules -f hercules.conf -d) &

# Collect the source code.
mkdir src

cp ./*.c                    src
cp ./*.h                    src
cp ./*.exec                 src
cp ./*.parm                 src
cp ../*.h                   src
cp ../assembler/*.c         src
cp ../assembler/*.h         src
cp ../avl_tree/*.c          src
cp ../avl_tree/*.h          src
cp ../binutils/include/*.h  src
cp ../binutils/include/*.c  src
cp ../compiler/*.c          src
cp ../compiler/*.h          src
#  ../compiler/exits?
cp ../cpacker/*.c           src
cp ../debugger/*.rexx       src
cp ../disassembler/*.c      src
cp ../disassembler/*.h      src
cp ../inc/*.h               src
cp ../interpreter/*.c       src
cp ../interpreter/*.h       src
cp ../interpreter/rxvml/*.c src
#  ../interpreter/rxvml/*.h - none
cp ../interpreter/rxvmplugin/*.c src
cp ../interpreter/rxvmplugin/*.h src
#  ../lib ?
cp ../linker/*.c            src
cp ../packcc/*.c            src
cp ../platform/*.c          src
cp ../platform/*.h          src
cp ../rxpa/*.c              src
cp ../rxpa/*.h              src
cp ../tests/ascommon.rxas   src
cp ../tests/asebcdic.rxas   src
cp ../tests/basic.rexx      src/basic.exec
cp ../tests/levelbfunc.rexx src/levelbfunc.exec

# Fix up things GCCCMS can't compile.
./cmsfixc.sh
./cmsfixh.sh

sleep 5 # Let Hercules get started

# IPL
herccontrol "ipl 6A1" -w "USER DSC LOGOFF AS AUTOLOG1"
herccontrol "/cp start 00c" -w "RDR"
herccontrol "/cp start 00d class a" -w "PUN"

# Logon CMSUSER.
herccontrol "/cp disc" -w "^VM/370 Online"
herccontrol "/logon CMSUSER CMSUSER" -w "^VM Community Edition"
herccontrol "/" -w "^Ready;"
herccontrol "/purge rdr" -w "^Ready;"

# Get source.
# TODO: WARNING: file src/rxdb.rexx skipped - not an included filetype
yata -c -d src -f archive.yata
MARK=`herccontrol -m`
echo "USERID CMSUSER NAME ARCHIVE YATA" > tmp
echo ":READ ARCHIVE YATA" >> tmp
cat archive.yata >> tmp
netcat -q 0 localhost 3505 < tmp
herccontrol -w "HHCRD012I" -f "$MARK"
herccontrol "/yata -x -f READER -d d" -w "^Ready;"
rm archive.yata tmp

# Make source tape and VMARC.
herccontrol "/cp disc" -w "^VM/370 Online"
herccontrol "/logon operator operator" -w "RECONNECTED AT"
hetinit -n -d ../crexxsrc.aws
herccontrol "devinit 480 io/crexxsrc.aws" -w "^HHCPN098I"
herccontrol "/attach 480 to CMSUSER as 181" -w "TAPE 480 ATTACH"
herccontrol "devinit 00d io/crexxsrc.vmarc" -w "^HHCPN098I"
herccontrol "/cp disc" -w "^VM/370 Online"
herccontrol "/logon CMSUSER CMSUSER" -w "RECONNECTED AT"
herccontrol "/begin"
herccontrol "/tape dump * * d" -w "^Ready;"
herccontrol "/detach 181" -w "^Ready;"
herccontrol "/vmarc pack * * d crexxsrc vmarc a (append notrace" -w "^Ready;"
herccontrol "/punch crexxsrc vmarc a (noheader" -w "^Ready;"
herccontrol "devinit 00d dummy" -w "^HHCPN098I"
sleep 5	# Because "devinit" is timing-related :-(
# Remove the trailing lace card:
truncate -s-80 ../crexxsrc.vmarc
herccontrol "/erase crexxsrc vmarc a" -w "^Ready;"

# Build.
# herccontrol "/cmsmake" -w "^Ready;" -t 250

# Make binary tape and VMARC.
# herccontrol "/cp disc" -w "^VM/370 Online"
# herccontrol "/logon operator operator" -w "RECONNECTED AT"
# hetinit -n -d ../crexxbin.aws
# herccontrol "devinit 480 io/crexxbin.aws" -w "^HHCPN098I"
# herccontrol "/attach 480 to CMSUSER as 181" -w "TAPE 480 ATTACH"
# herccontrol "devinit 00d io/crexxbin.vmarc" -w "^HHCPN098I"
# herccontrol "/cp disc" -w "^VM/370 Online"
# herccontrol "/logon CMSUSER CMSUSER" -w "RECONNECTED AT"
# herccontrol "/begin"
# herccontrol "/tape dump * * e" -w "^Ready;"
# herccontrol "/detach 181" -w "^Ready;"
# herccontrol "/vmarc pack * * e crexxbin vmarc a (append notrace" -w "^Ready;"
# herccontrol "/punch crexxbin vmarc a (noheader" -w "^Ready;"
# herccontrol "devinit 00d dummy" -w "^HHCPN098I"
# sleep 5	# Because "devinit" is timing-related :-(
# Remove the trailing lace card:
# truncate -s-80 ../crexxbin.vmarc
# herccontrol "/erase crexxbin vmarc a" -w "^Ready;"

# Logoff.
herccontrol "/logoff" -w "^VM/370 Online"

# Shutdown.
herccontrol "/logon operator operator" -w "RECONNECTED AT"
herccontrol "/shutdown" -w "^HHCCP011I"
