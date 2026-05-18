#ifndef __CMS__
#  error Do not compile rxbin.c under this operating system.
#endif

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "platform.h"
#include "rxdefs.h"

#define __SPLIT_RXBIN__ 1
#include "rxbin.h"
