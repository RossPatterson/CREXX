#ifndef __CMS__
#  error Do not compile the split parser under this operating system.
#endif

/* Declare structs, etc. */
#define __SPLIT_PARSER__ 1
#include "rxcpbgmr.c"
#undef __SPLIT_PARSER__

/* Compile a section of the parser. */
#define __SPLIT_PARSER__ 10
#include "rxcpbgmr.c"
