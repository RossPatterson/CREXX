//
// CMS Build Fixes
//

#ifndef CREXX_CMS_H
#define CREXX_CMS_H

/* VM/370 doesn't like to have  multiple external symbols with the same name,
 * so we make the "inline" functions static always.
 */
#undef RX_INLINE
#undef RX_MOSTLYINLINE
#undef RX_FLATTEN
#ifdef NDEBUG  // RELEASE
#  define RX_INLINE static inline __attribute__((always_inline))
#  define RX_MOSTLYINLINE static inline
#  define RX_FLATTEN __attribute__((flatten))
#else // DEBUG
#  define RX_INLINE static
#  define RX_MOSTLYINLINE static
#  define RX_FLATTEN
#endif

/* VM/370 has a 32 bit (or 24/32) architecture */
#define __32BIT__

/*
 * GCC in VM/370 can't seem to handle all the computed gotos - so use a
 * classic bytecode architecture
 */
#undef NTHREADED
#define NTHREADED

/*
 * VM/370 does not support UTF-8.
 */
#define NUTF8


/* Date / time stubs */
struct timeval {
    long    tv_sec;        /* seconds */
    long    tv_usec;    /* and microseconds */
};
#define timezone 0
static char* tzname[] = {"",""};
static void tzset(void) {};
#define daylight 0


/* Shocking hack ... todo - need to replace with fixed buffer logic for cms */
#define snprintf(s,sz,...) sprintf(s,__VA_ARGS__)
#define vsnprintf(s,sz,...) vsprintf(s,__VA_ARGS__)

/* CMS's GCCLIB lacks stdlib's strdup(), so we wrote one in cmsutil.c. */
char *strdup(const char *input);

/* CMS's GCC can't compile rxvminto.c because it's too large.  So we split it. */
#define __SPLIT_INTERPRETER__

#endif //CREXX_CMS_H
