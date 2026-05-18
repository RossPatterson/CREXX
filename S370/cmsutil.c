/* CMS Platform - Utility Functions */

#include <stdlib.h>
#include <stdio.h>
#include "platform.h"
#include <strings.h>
#include <errno.h>
#include "cmsstat.h"
#include "cmstime.h"
#include "cmstypes.h"

/* Read a file into a buffer - this function mallocs the buffer to the right size */
char *file2buf(FILE *file, size_t *l) {
    int i;
    size_t buf_size = 1024 * 4;
    char *buffer;
    long len;

    /* GCCLIB function to try to get the file size */
    len = fgetlen(file);
    if (len == 0) return 0; /* Empty file */
    /* Note fgetlen() returns -1 for a variable length file */

    /* Disable cache and rewind file to the beginning */
    setbuf(file, 0);
    rewind(file);

    if (len > 0) {
        *l = (size_t)len;
        /* Read the file in one go */
        buffer = malloc(*l + 2);
        *l = fread(buffer, 1, *l, file);

        /* Null terminate */
        buffer[*l] = 0;
        buffer[*l + 1]  = 0;
    } else {
        /* Don't know file size - have to read the file line by line */
        *l = 0;
        buffer = malloc(buf_size);
        while ((i = nextrecLen(file)) > 0) {
            while (*l + i + 1 > buf_size) {
                buf_size *= 2;
                buffer = realloc(buffer, buf_size);
            }
            fgets(buffer + *l, i + 1, file);
            *l += i;
        }

        /* Give back unwanted memory */
        buffer = realloc(buffer, *l + 2);

        /* Null terminate */
        buffer[*l] = 0;
        buffer[*l + 1] = 0;
    }

    return buffer;
}

/*
 * Function opens and returns a file handle
 * dir can be null - the default is platform specific (e.g. ./ )
 * mode - is the fopen() file mode
 */
FILE *openfile(char *name, char *type, char *dir, char *mode) {
    size_t len;
    char *file_name;
    FILE *stream;
    if (!dir)
        dir = "A";

    len = strlen(name) + strlen(type) + strlen(dir) + 3;

    file_name = malloc(len);
    snprintf(file_name, len,
             "%s %s %s", name, type, dir);

    stream = fopen(file_name, mode);

    free(file_name);

    return stream;
}

/* CMS's GCCLIB lacks stdlib's strdup(). */
char *strdup(const char *input) {
    char *output;

    if ( NULL != (output = malloc(strlen(input)+1)) ) strcpy(output, input);
    return output;
}

/* CMS's GCCLIB lacks strings.h. So we provide versions based on its strcmp()
   and strncmp().  Those functions are described in string.h as follows:

      This Program Written by Paul Edwards.
      Released to the Public Domain

*/

/* NOTE: UPCASE() is EBCDIC-specific. */
#define UPCASE(c) (c | 0x40)

int strcasecmp(const char *s1, const char *s2) {
    const unsigned char *p1;
    const unsigned char *p2;

    p1 = (const unsigned char *) s1;
    p2 = (const unsigned char *) s2;
    while (*p1 != '\0') {
        if (UPCASE(*p1) < UPCASE(*p2)) return (-1);
        else if (UPCASE(*p1) > UPCASE(*p2)) return (1);
        p1++;
        p2++;
    }
    if (*p2 == '\0') return (0);
    else return (-1);
}

int strncasecmp(const char *s1, const char *s2, size_t n) {
    const unsigned char *p1;
    const unsigned char *p2;
    size_t x = 0;

    p1 = (const unsigned char *) s1;
    p2 = (const unsigned char *) s2;
    while (x < n) {
        if (UPCASE(p1[x]) < UPCASE(p2[x])) return (-1);
        else if (UPCASE(p1[x]) > UPCASE(p2[x])) return (1);
        else if (UPCASE(p1[x]) == '\0') return (0);
        x++;
    }
    return (0);
}
