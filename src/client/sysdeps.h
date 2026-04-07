/*
 * BloodsPilot, a multiplayer space war game.  Copyright (C) 2005-2007 by
 *
 *      Kristian S�derblom   kps at users.sourceforge.net
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

/* $Id: sysdeps.h,v 1.8 2007/09/27 22:19:46 kps Exp $ */

#ifndef SYSDEPS_H
#define SYSDEPS_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#ifdef STDC_HEADERS
#include <stdlib.h>
#include <stddef.h>
#else
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#endif

#ifdef HAVE_STRING_H
#if !defined STDC_HEADERS && defined HAVE_MEMORY_H
#include <memory.h>
#endif
#include <string.h>
#endif

#if 0
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#else
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#endif
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_ASSERT_H
#include <assert.h>
#endif

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_MATH_H
#include <math.h>
#endif

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

#ifdef TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#endif

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#ifdef HAVE_PWD_H
#include <pwd.h>
#endif

#ifdef HAVE_SETJMP_H
#include <setjmp.h>
#endif

#if 0
#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>
#endif
#endif

#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif

#if 0
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#if 0
#ifdef HAVE_SYS_INTTYPES_H
#include <sys/inttypes.h>
#endif
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif

#ifdef HAVE_NET_IF_H
#include <net/if.h>
#endif

#if 0
#ifdef HAVE_NETINET_TCP_H
#include <netinet/tcp.h>
#endif
#endif

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#if 0
/* Platform specific hacks. */

/* SGI hack. */
#ifdef HAVE_BSTRING_H
#include <bstring.h>
#endif

/* System V R4 hacks. */
#ifdef HAVE_SYS_FILIO_H
#include <sys/filio.h>
#endif
#endif

#ifdef HAVE_SYS_SOCKIO_H
#include <sys/sockio.h>
#endif

#ifdef HAVE_SYS_FCNTL_H
#include <sys/fcntl.h>
#endif

#if 0
/* Sun hacks. */
#ifdef HAVE_ARPA_NAMESER_H
#include <arpa/nameser.h>
#endif

#ifdef HAVE_RESOLV_H
#include <resolv.h>
#endif
#endif

/*
 * Makes sense to include portability
 * along with the sysdeps.
 */
#include "portability.h"

#endif /* SYSDEPS_H */
