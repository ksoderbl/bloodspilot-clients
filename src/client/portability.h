/*
 * BloodsPilot, a multiplayer space war game.  Copyright (C) 1991-2005 by
 *
 *      Bjørn Stabell        <bjoern@xpilot.org>
 *      Ken Ronny Schouten   <ken@xpilot.org>
 *      Bert Gijsbers        <bert@xpilot.org>
 *      Dick Balaska         <dick@xpilot.org>
 *      Kristian Söderblom   kps at users.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * Include portability related stuff in one file.
 */
#ifndef PORTABILITY_H
#define PORTABILITY_H

#include "sysdeps.h"

#define PATHNAME_SEP    '/'

int micro_delay(unsigned usec);

void Get_login_name(char *buf, size_t size);

#ifndef HAVE_STRDUP
char *strdup(const char *);
#endif
char *xp_safe_strdup(const char *old_string);

#ifndef HAVE_STRCASECMP
int strcasecmp(const char *str1, const char *str2);
#endif
#ifndef HAVE_STRNCASECMP
int strncasecmp(const char *str1, const char *str2, size_t n);
#endif

#ifndef HAVE_STRLCPY
size_t strlcpy(char *dest, const char *src, size_t size);
#endif
#ifndef HAVE_STRLCAT
size_t strlcat(char *dest, const char *src, size_t size);
#endif

void *xp_safe_malloc(size_t size);
void *xp_safe_realloc(void *oldptr, size_t size);
void *xp_safe_calloc(size_t nmemb, size_t size);
void xp_safe_free(void *p);

#ifdef _WINDOWS

#undef max
#undef min

/* there are tons of "conversion from 'double ' to 'int '", stop warning us */
#pragma warning (disable : 4244)

#endif				/* _WINDOWS */

/*
 * In Windows, just exiting won't tell the user the reason.
 * So, try to gracefully shutdown just the server thread
 */
#ifdef _WINDOWS
extern int ServerKilled;
#define	ServerExit() ServerKilled = TRUE; return;
#else
#define	ServerExit() exit(1);
#endif

/*
 * Macros to block out Windows only code (and never Windows code)
 */
#ifdef _WINDOWS
#define IFWINDOWS(x)	x
#else
#define IFWINDOWS(x)
#endif

#ifndef _WINDOWS
#define IFNWINDOWS(x)	x
#else
#define IFNWINDOWS(x)
#endif


#ifdef _WINDOWS
#define PATHNAME_SEP    '\\'
#else
#define PATHNAME_SEP    '/'
#endif


/*
 * Prototypes for OS function wrappers in portability.c.
 */
extern int Get_process_id(void);	/* getpid */
extern void Get_login_name(char *buf, size_t size);
extern int xpprintf(const char *fmt, ...);

/*
 * Prototypes for testing if we are running under a certain OS.
 */
/*extern bool is_this_windows(void);*/


/*
 * Round to nearest integer.
 */
#ifdef _WINDOWS
double rint(double x);
#endif

#ifdef _MSC_VER
typedef unsigned short uint16_t;	/* e.g. in client.c */
typedef unsigned int uint32_t;
typedef int int32_t;
#endif

#ifdef _WINDOWS
/*
 * Defines gettimeofday
 *
 * Based on timeval.h by Wu Yongwei
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#  ifndef __GNUC__
#    define EPOCHFILETIME (116444736000000000i64)
#  else
#    define EPOCHFILETIME (116444736000000000LL)
#  endif

struct timezone {
	int tz_minuteswest;	/* minutes W of Greenwich */
	int tz_dsttime;		/* type of dst correction */
};


#  ifndef HAVE_GETTIMEOFDAY
#define NEED_GETTIMEOFDAY
extern gettimeofday(struct timeval *tv, struct timezone *tz);

#  define HAVE_GETTIMEOFDAY 1

#  endif			/* HAVE_GETTIMEOFDAY */
#endif				/* _WINDOWS */

#ifndef HAVE_GETTIMEOFDAY
#  error "This program needs gettimeofday() to work. Have a nice day."
#endif

static inline struct timeval seconds_to_timeval(double t)
{
	struct timeval tv;

	tv.tv_sec = (unsigned) t;
	tv.tv_usec = (unsigned) (((t - (double) tv.tv_sec) * 1e6) + 0.5);

	return tv;
}

/* returns 'tv2 - tv1' */
static inline int timeval_sub(struct timeval *tv2, struct timeval *tv1)
{
	int s, us;

	s = tv2->tv_sec - tv1->tv_sec;
	us = tv2->tv_usec - tv1->tv_usec;

	return 1000000 * s + us;
}


#endif				/* PORTABILITY_H */
