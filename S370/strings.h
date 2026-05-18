#ifndef _STRINGS_H
#define _STRINGS_H

/* CMS doesn't have strings.h, so we define the functions that CREXX uses. */
int strcasecmp(const char *s1, const char *s2);
int strncasecmp(const char *s1, const char *s2, size_t n);

#endif //_STRINGS_H
