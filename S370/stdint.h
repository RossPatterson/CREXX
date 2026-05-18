//
// Fake stdint.h for VM/370 Build
//

#ifndef _STDINT_H
#define _STDINT_H
#include <stdlib.h> /* size_t */

#define SIZE_MAX ((size_t)(-1))

typedef signed char int8_t;
typedef signed int int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
typedef unsigned int uint8_t;
typedef unsigned int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

#define INT8_C(c)   c
#define INT16_C(c)  c
#define INT32_C(c)  c
#define INT64_C(c)  c ##LL
#define UINT8_C(c)  c
#define UINT16_C(c) c
#define UINT32_C(c) c ##U
#define UINT64_C(c) c ##ULL

#endif //_STDINT_H
