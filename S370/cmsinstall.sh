#!/usr/bin/bash
# Install CREXX on CMS

# Exit if there is an error
set -euo pipefail

# IPL
herccontrol -v
herccontrol "ipl 6A1" -w "USER DSC LOGOFF AS AUTOLOG1"

# Logon MAINT and read tape
herccontrol "/cp disc" -w "^VM/370 Online"
herccontrol "/logon maint cpcms" -w "^VM Community Edition"
herccontrol "/" -w "^Ready;"
herccontrol "devinit 480 io/crexxbin.aws" -w "^HHCPN098I"
herccontrol "/attach 480 to maint as 181" -w "TAPE 480 ATTACH TO MAINT"
herccontrol "/access 19e c" -w "^Ready;"
herccontrol "/tape load * * c2" -w "^Ready;"
# herccontrol "/rename rxas module c1 = = c2"  -w "^Ready;"
herccontrol "/detach 181" -w "^Ready;"
herccontrol "/release c"  -w "^Ready;"
herccontrol "/ipl 190" -w "^VM Community Edition"
herccontrol "/savesys cms" -w "^VM Community Edition"
herccontrol "/" -w "^Ready;"
herccontrol "/logoff" -w "^VM/370 Online"

# Logon MAINTC
herccontrol "/logon maintc maintc" -w "^VM Community Edition"
herccontrol "/" -w "^Ready;"

# Sanity test
herccontrol "/rxas -v" -w "^Ready;"

# Logoff
herccontrol "/logoff" -w "^VM/370 Online"

# Shutdown
herccontrol "/logon operator operator" -w "RECONNECTED AT"
herccontrol "/shutdown" -w "^HHCCP011I"
