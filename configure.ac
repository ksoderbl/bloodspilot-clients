dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([BloodsPilot], 1.4.0, kps at users.sourceforge.net, bloodspilot-clients)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR(src/client/sysdeps.h)

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE
AM_CONFIG_HEADER(config.h)

dnl  Copyright & stuff.
XP_AUTHORS="Bjørn Stabell, Ken Ronny Schouten, Bert Gijsbers, Dick Balaska, Uoti Urpala, Juha Lindström, Kristian Söderblom and Erik Andersson"
AC_SUBST([XP_AUTHORS])

XP_COPYRIGHTDATE="1991-2007"
AC_SUBST([XP_COPYRIGHTDATE])

XP_COPYRIGHT="Copyright © $XP_COPYRIGHTDATE by $XP_AUTHORS"
AC_SUBST([XP_COPYRIGHT])

AC_SUBST([XP_RELEASEDATE],["Dec 11, 2007"])
dnl  kps - Should be bloodspilot-clients ???
AC_SUBST([XP_DATADIR],"$prefix/share/bloodspilot-clients")

dnl  Checks for options.
dnl  We should have some general macro for these.
AC_ARG_ENABLE(dbe,
	AC_HELP_STRING([--enable-dbe],
			[support for X Doublebuffer Extension in client]),
[if test x$enable_dbe = xyes; then
	AC_DEFINE([DBE], 1, [support for X Doublebuffer Extension in client])
fi])

AC_ARG_ENABLE(mbx,
	AC_HELP_STRING([--enable-mbx],
			[support for X Multibuffer Extension in client]),
[if test x$enable_mbx = xyes; then
	AC_DEFINE([MBX], 1, [support for X Multibuffer Extension in client])
fi])

AC_ARG_ENABLE(development,
	AC_HELP_STRING([--enable-development],
			[enable development code]),
[if test x$enable_development = xyes; then
	AC_DEFINE([DEVELOPMENT], 1, [enable development code])
fi])

AC_ARG_ENABLE(replay,
	AC_HELP_STRING([--disable-replay],
			[disable building of replay program]),
[], [enable_replay=yes; need_x=yes])

AC_ARG_ENABLE(x11_client,
	AC_HELP_STRING([--disable-x11-client],
			[disable X11 client]),
[], [enable_x11_client=yes; need_x=yes])

AC_ARG_ENABLE(454_client,
	AC_HELP_STRING([--disable-454-client],
			[disable XPilot 4.5.4 style client]),
[], [enable_454_client=yes; need_x=yes])

AC_ARG_ENABLE(sound,
	AC_HELP_STRING([--enable-sound],
			[enable OpenAL sound]), [])

dnl  Checks for programs.
AC_PROG_CC
dnl AC_PROG_GCC_TRADITIONAL
dnl AC_PROG_CPP

dnl Needed if you want to compile with g++ e.g.
dnl AC_PROG_CXX
dnl AC_PROG_CXXCPP

dnl AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_INSTALL

dnl  Checks for libraries.
dnl kps - these should be cleaned up and not use the autoconf internal
dnl shell variables.
AC_CHECK_LIB(m, cos)
if test x$ac_cv_lib_m_cos != xyes; then
	AC_MSG_ERROR([*** Math library not found!
		     *** Install package libc6-dev or equivalent.
	])
fi
AC_CHECK_LIB(z, gzopen)
if test x$ac_cv_lib_z_gzopen != xyes; then
	AC_MSG_WARN([*** Library zlib not found!
                    *** If you want support for texture downloads from
		    *** XPilot NG servers, install package zlib1g-dev or
		    *** equivalent and run configure again.
	])
fi
dnl AC_CHECK_LIB(expat, XML_ParserCreate)
dnl if test x$ac_cv_lib_expat_XML_ParserCreate != xyes; then
dnl	AC_MSG_ERROR([*** Required library Expat not found!])
dnl fi

dnl Figure out which math library to use
dnl (borrowed from from http://www.libsdl.org/opengl/SDLgears-1.0.2.tar.gz)
case "$target" in
    *-*-mingw32*)
	MATHLIB=""
	SYS_GL_LIBS="-lopengl32 -lglu32"
	windows_target=yes
	;;
    *-*-beos*)
	MATHLIB=""
	SYS_GL_LIBS="-lGL"
	;;
    *-*-linux*)
	MATHLIB="-lm"
	SYS_GL_LIBS="-L/usr/X11R6/lib -lGL -lGLU"
	;;
    *-*-freebsd*)
	MATHLIB="-lm"
	SYS_GL_LIBS="-L/usr/X11R6/lib -lGL -lGLU"
	CPPFLAGS="$CPPFLAGS -I/usr/X11R6/include -I/usr/local/include"
	LDFLAGS="$LDFLAGS -L/usr/local/lib"
	;;
    *-*-netbsd*)
	MATHLIB="-lm"
	SYS_GL_LIBS="-L/usr/X11R6/lib -lGL -lGLU"
	CPPFLAGS="$CPPFLAGS -I/usr/X11R6/include -I/usr/local/include"
	LDFLAGS="$LDFLAGS -L/usr/pkg/lib -L/usr/X11R6/lib -Wl,-rpath,/usr/pkg/lib:/usr/X11R6/lib"
	;;
    *)
	MATHLIB="-lm"
	SYS_GL_LIBS="-lGL -lGLU"
	;;
esac

# kps - this checks also for xf86misc
#AC_PATH_X
#if test x$need_x = xyes; then
#	if test x$no_x == xyes; then
#		AC_MSG_ERROR([*** Couldn't find X headers or libraries!
#                  *** You need to install package libx11-dev or equivalent.
#		])
#	fi
#	
#	AC_PATH_XTRA
#
#	AC_MSG_CHECKING(for xf86misc extensions)
#	AC_COMPILE_IFELSE([
#	 #include <X11/X.h>
#	 #include <X11/Xlib.h>
#	 #include <X11/extensions/xf86misc.h>
#	 int main(int argc, char** argv) { return 0; }
#	],[
#	have_xf86misc=yes
#	],[
#	have_xf86misc=no])
#	AC_MSG_RESULT($have_xf86misc)
#
#	dnl kps - Hack to link with libXext if DBE or MBX is configured
#	if test x$enable_dbe = xyes || test x$enable_mbx = xyes || test x$have_xf86misc = xyes; then
#		X_EXTENSIONS_LIB="-lXext"
#	else
#		X_EXTENSIONS_LIB=
#	fi
#	
#	if test x$have_xf86misc = xyes; then
#		X_EXTENSIONS_LIB="-lXxf86misc $X_EXTENSIONS_LIB"
#		AC_DEFINE([HAVE_XF86MISC], 1, [Define to 1 if you have the Xf86Misc library])
#	fi
#	
#	AC_SUBST(X_EXTENSIONS_LIB)
#fi
#

AC_PATH_X
if test x$need_x = xyes; then
	if test x$no_x == xyes; then
		AC_MSG_ERROR([*** Couldn't find X headers or libraries!
                  *** You need to install package libx11-dev or equivalent.
		])
	fi
	
	AC_PATH_XTRA

	dnl kps - link with libXext if DBE or MBX is configured
	if test x$enable_dbe = xyes || test x$enable_mbx = xyes; then
		X_EXTENSIONS_LIB="-lXext"
	else
		X_EXTENSIONS_LIB=
	fi
	
	AC_SUBST(X_EXTENSIONS_LIB)
fi

if test x$enable_x11_client = xyes; then
	AC_DEFINE([X11_CLIENT], 1, [enable x11 client])
fi

if test x$enable_454_client = xyes; then
	AC_DEFINE([XP454_CLIENT], 1, [enable XPilot 4.5.4 style x11 client])
fi

if test x$enable_replay = xyes; then
	AC_DEFINE([REPLAY], 1, [enable replay program])
fi

AM_CONDITIONAL([COND_REPLAY], [test x$enable_replay = xyes])
AM_CONDITIONAL([COND_X11_CLIENT], [test x$enable_x11_client = xyes])
AM_CONDITIONAL([COND_454_CLIENT], [test x$enable_454_client = xyes])

dnl OpenAL client sound support.
if test x$enable_sound = xyes; then
	have_openal=no
	have_alut=no
	have_sound=no
	AC_CHECK_LIB(
		openal, 
		main, 
		[have_openal=yes],
		[])
	AC_CHECK_LIB(
		alut, 
		main, 
		[have_alut=yes],
		[])
	if test x$have_openal = xyes; then
		if test x$have_alut = xyes; then
			have_sound=yes
			SOUND_LIBS="-lopenal -lalut"
			AC_DEFINE([SOUND], 1, [Define to 1 if you want OpenAL sound.])
		else
			echo "*** Client sound disabled. Check that you have OpenAL installed."
		fi
	fi
	AC_SUBST(SOUND_LIBS)
fi

AM_CONDITIONAL([COND_SOUND], [test x$have_sound = xyes])

dnl  Checks for header files.
dnl AC_HEADER_STDC
AC_HEADER_TIME
dnl AC_HEADER_STDBOOL
AC_CHECK_HEADERS([ \
	assert.h \
	ctype.h \
	errno.h \
	limits.h \
	math.h \
	signal.h \
	stdarg.h \
	setjmp.h \
	sys/stat.h \
	sys/socket.h \
	sys/sockio.h \
	sys/time.h \
	sys/ioctl.h \
	sys/fcntl.h \
	netinet/in.h \
	arpa/inet.h \
	netdb.h \
	pwd.h \
	])
AC_CHECK_HEADERS([net/if.h],[],[],[
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
])


dnl	unistd.h \
dnl	sys/types.h \

dnl	arpa/inet.h \

dnl	ctype.h \

dnl	fcntl.h \
dnl	float.h \
dnl	limits.h \

dnl	netinet/in.h \
dnl	netinet/tcp.h \

dnl	setjmp.h \
dnl	stddef.h \
dnl	sys/file.h \
dnl	sys/inttypes.h \
dnl	sys/ioctl.h \
dnl	sys/lock.h \
dnl	sys/mman.h \
dnl	sys/param.h \
dnl	sys/socket.h \
dnl	sys/time.h \
dnl	arpa/nameser.h \
dnl	bstring.h \
dnl	sys/filio.h \
dnl	resolv.h \
dnl	values.h \

dnl 	X11/extensions/Xdbe.h
dnl	X11/extensions/multibuf.h
dnl	X11/X.h \
dnl	X11/Xlib.h \
dnl	X11/Xos.h \
dnl	X11/Xutil.h \
dnl	X11/keysym.h \
dnl	X11/Xatom.h \
dnl	X11/Xmd.h \

dnl  Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE
AC_TYPE_MODE_T
AC_TYPE_SIGNAL
AC_TYPE_SIZE_T
AC_STRUCT_TM

dnl Check for socklen_t (in Unix98)
AC_MSG_CHECKING(for socklen_t)
AC_TRY_COMPILE([
	#include <sys/types.h>
	#include <sys/socket.h>
	socklen_t x;
], [],
[
	AC_MSG_RESULT(yes)
], [
	AC_TRY_COMPILE([
		#include <sys/types.h>
		#include <sys/socket.h>
		int accept(int, struct sockaddr *, size_t *);
	], [], [
		AC_MSG_RESULT(size_t)
		AC_DEFINE(socklen_t, size_t, [socklen_t size])
	], [
		AC_MSG_RESULT(int)
		AC_DEFINE(socklen_t, int, [socklen_t size])
	])
])

dnl  Checks for library functions.

dnl We probably don't need GNU compatible malloc and realloc functions,
dnl so these are disabled for now.
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC

AC_FUNC_MEMCMP
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_SETVBUF_REVERSED
AC_FUNC_STAT
AC_FUNC_STRFTIME
AC_FUNC_STRTOD
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([ \
	gettimeofday \
	strcasecmp \
	strdup \
	strlcat \
	strlcpy \
	strncasecmp \
	])


dnl	alarm \
dnl	floor \
dnl	gethostbyaddr \
dnl	gethostbyname \
dnl	gethostname \
dnl	inet_ntoa \
dnl	isascii \
dnl	memchr \
dnl	memmove \
dnl	memset \
dnl	mkdir \
dnl	pow \
dnl	rint \
dnl	select \
dnl	socket \
dnl	sqrt \
dnl	strchr \
dnl	strerror \
dnl	strpbrk \
dnl	strrchr \
dnl	strspn \
dnl	strstr \
dnl	strtol \
dnl	strtoul \


AC_CONFIG_FILES([ \
	Makefile \
	doc/Makefile \
	doc/man/Makefile \
	share/Makefile \
	share/textures/Makefile \
	share/sound/Makefile \
	src/Makefile \
	src/client/Makefile \
	src/client/version.h \
	src/client/items/Makefile \
	src/client/454/Makefile \
	src/client/x11/Makefile \
	src/replay/Makefile \
	src/replay/tools/Makefile \
	])
AC_OUTPUT

