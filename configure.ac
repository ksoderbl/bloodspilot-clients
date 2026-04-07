dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([BloodsPilot], [1.4.0], [https://github.com/ksoderbl/bloodspilot-clients/issues], [bloodspilot-clients])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_SRCDIR([src/client/sysdeps.h])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE([disable])

AC_USE_SYSTEM_EXTENSIONS

dnl Copyright & metadata.
XP_AUTHORS="Bjørn Stabell, Ken Ronny Schouten, Bert Gijsbers, Dick Balaska, Uoti Urpala, Juha Lindström, Kristian Söderblom and Erik Andersson"
AC_SUBST([XP_AUTHORS])

XP_COPYRIGHTDATE="1991-2007"
AC_SUBST([XP_COPYRIGHTDATE])

XP_COPYRIGHT="Copyright © $XP_COPYRIGHTDATE by $XP_AUTHORS"
AC_SUBST([XP_COPYRIGHT])

AC_SUBST([XP_RELEASEDATE], ["Dec 11, 2007"])
AC_SUBST([XP_DATADIR], ['${datarootdir}/bloodspilot-clients'])

dnl ------------------------------------------------------------------
dnl Options
dnl ------------------------------------------------------------------

need_x=no
have_sound=no
enable_replay=yes
enable_x11_client=yes
enable_454_client=yes
enable_sound=no

AC_ARG_ENABLE([dbe],
  AS_HELP_STRING([--enable-dbe], [support for X Doublebuffer Extension in client]),
  [if test "x$enableval" = "xyes"; then
     AC_DEFINE([DBE], [1], [support for X Doublebuffer Extension in client])
   fi],
  [])

AC_ARG_ENABLE([mbx],
  AS_HELP_STRING([--enable-mbx], [support for X Multibuffer Extension in client]),
  [if test "x$enableval" = "xyes"; then
     AC_DEFINE([MBX], [1], [support for X Multibuffer Extension in client])
   fi],
  [])

AC_ARG_ENABLE([development],
  AS_HELP_STRING([--enable-development], [enable development code]),
  [if test "x$enableval" = "xyes"; then
     AC_DEFINE([DEVELOPMENT], [1], [enable development code])
   fi],
  [])

AC_ARG_ENABLE([replay],
  AS_HELP_STRING([--disable-replay], [disable building of replay program]),
  [enable_replay="$enableval"],
  [enable_replay=yes])

if test "x$enable_replay" = "xyes"; then
  need_x=yes
fi

AC_ARG_ENABLE([x11-client],
  AS_HELP_STRING([--disable-x11-client], [disable X11 client]),
  [enable_x11_client="$enableval"],
  [enable_x11_client=yes])

if test "x$enable_x11_client" = "xyes"; then
  need_x=yes
fi

AC_ARG_ENABLE([454-client],
  AS_HELP_STRING([--disable-454-client], [disable XPilot 4.5.4 style client]),
  [enable_454_client="$enableval"],
  [enable_454_client=yes])

if test "x$enable_454_client" = "xyes"; then
  need_x=yes
fi

AC_ARG_ENABLE([sound],
  AS_HELP_STRING([--enable-sound], [enable OpenAL sound]),
  [enable_sound="$enableval"],
  [enable_sound=no])

dnl Compatibility no-op options so existing helper scripts work cleanly.
AC_ARG_ENABLE([sdl-client],
  AS_HELP_STRING([--disable-sdl-client], [compatibility no-op; SDL client is not built in this tree]),
  [],
  [])

AC_ARG_ENABLE([ng-x11-client],
  AS_HELP_STRING([--disable-ng-x11-client], [compatibility no-op; NG X11 client is not built in this tree]),
  [],
  [])

dnl ------------------------------------------------------------------
dnl Programs
dnl ------------------------------------------------------------------

AC_PROG_CC
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_INSTALL

dnl ------------------------------------------------------------------
dnl Libraries
dnl ------------------------------------------------------------------

AC_CHECK_LIB([m], [cos], [],
  [AC_MSG_ERROR([*** Math library not found!
*** Install package libc6-dev or equivalent.])])

AC_CHECK_LIB([z], [gzopen],
  [],
  [AC_MSG_WARN([*** Library zlib not found!
*** If you want support for texture downloads from
*** XPilot NG servers, install package zlib1g-dev or
*** equivalent and run configure again.])])

dnl Figure out which math/OpenGL library settings to use.
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

AC_SUBST([MATHLIB])
AC_SUBST([SYS_GL_LIBS])

dnl ------------------------------------------------------------------
dnl X11
dnl ------------------------------------------------------------------

AC_PATH_X

if test "x$need_x" = "xyes"; then
  if test "x$no_x" = "xyes"; then
    AC_MSG_ERROR([*** Couldn't find X headers or libraries!
*** You need to install package libx11-dev or equivalent.])
  fi

  AC_PATH_XTRA

  dnl Link with libXext if DBE or MBX is configured.
  if test "x$enable_dbe" = "xyes" || test "x$enable_mbx" = "xyes"; then
    X_EXTENSIONS_LIB="-lXext"
  else
    X_EXTENSIONS_LIB=""
  fi

  AC_SUBST([X_EXTENSIONS_LIB])
else
  X_EXTENSIONS_LIB=""
  AC_SUBST([X_EXTENSIONS_LIB])
fi

if test "x$enable_x11_client" = "xyes"; then
  AC_DEFINE([X11_CLIENT], [1], [enable x11 client])
fi

if test "x$enable_454_client" = "xyes"; then
  AC_DEFINE([XP454_CLIENT], [1], [enable XPilot 4.5.4 style x11 client])
fi

if test "x$enable_replay" = "xyes"; then
  AC_DEFINE([REPLAY], [1], [enable replay program])
fi

AM_CONDITIONAL([COND_REPLAY], [test "x$enable_replay" = "xyes"])
AM_CONDITIONAL([COND_X11_CLIENT], [test "x$enable_x11_client" = "xyes"])
AM_CONDITIONAL([COND_454_CLIENT], [test "x$enable_454_client" = "xyes"])

dnl ------------------------------------------------------------------
dnl OpenAL sound
dnl ------------------------------------------------------------------

if test "x$enable_sound" = "xyes"; then
  have_openal=no
  have_alut=no
  have_sound=no

  AC_CHECK_LIB([openal], [main], [have_openal=yes], [])
  AC_CHECK_LIB([alut], [main], [have_alut=yes], [])

  if test "x$have_openal" = "xyes"; then
    if test "x$have_alut" = "xyes"; then
      have_sound=yes
      SOUND_LIBS="-lopenal -lalut"
      AC_DEFINE([SOUND], [1], [Define to 1 if you want OpenAL sound.])
    else
      AC_MSG_WARN([*** Client sound disabled. Check that you have OpenAL/ALUT installed.])
    fi
  else
    AC_MSG_WARN([*** Client sound disabled. Check that you have OpenAL/ALUT installed.])
  fi
fi

AC_SUBST([SOUND_LIBS])
AM_CONDITIONAL([COND_SOUND], [test "x$have_sound" = "xyes"])

dnl ------------------------------------------------------------------
dnl Header checks
dnl ------------------------------------------------------------------

AC_HEADER_TIME

AC_CHECK_HEADERS([
  assert.h
  ctype.h
  errno.h
  limits.h
  math.h
  signal.h
  stdarg.h
  setjmp.h
  sys/stat.h
  sys/socket.h
  sys/sockio.h
  sys/time.h
  sys/ioctl.h
  sys/fcntl.h
  netinet/in.h
  arpa/inet.h
  netdb.h
  pwd.h
])

AC_CHECK_HEADERS([net/if.h], [], [], [[
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
]])

dnl ------------------------------------------------------------------
dnl Types / compiler characteristics
dnl ------------------------------------------------------------------

AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE
AC_TYPE_MODE_T
AC_TYPE_SIGNAL
AC_TYPE_SIZE_T
AC_STRUCT_TM

dnl Check for socklen_t
AC_MSG_CHECKING([for socklen_t])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM([[#include <sys/types.h>
#include <sys/socket.h>]], [[socklen_t x;]])],
  [AC_MSG_RESULT([yes])],
  [AC_COMPILE_IFELSE(
     [AC_LANG_PROGRAM([[#include <sys/types.h>
#include <sys/socket.h>
int accept(int, struct sockaddr *, size_t *);]], [[]])],
     [AC_MSG_RESULT([size_t])
      AC_DEFINE([socklen_t], [size_t], [socklen_t size])],
     [AC_MSG_RESULT([int])
      AC_DEFINE([socklen_t], [int], [socklen_t size])])])

dnl ------------------------------------------------------------------
dnl Functions
dnl ------------------------------------------------------------------

AC_FUNC_MEMCMP
AC_FUNC_SELECT_ARGTYPES
AC_FUNC_SETVBUF_REVERSED
AC_FUNC_STAT
AC_FUNC_STRFTIME
AC_FUNC_STRTOD
AC_FUNC_VPRINTF

AC_CHECK_FUNCS([
  gettimeofday
  strcasecmp
  strdup
  strlcat
  strlcpy
  strncasecmp
])

dnl ------------------------------------------------------------------
dnl Output files
dnl ------------------------------------------------------------------

AC_CONFIG_FILES([
  Makefile
  doc/Makefile
  doc/man/Makefile
  share/Makefile
  share/textures/Makefile
  share/sound/Makefile
  src/Makefile
  src/client/Makefile
  src/client/version.h
  src/client/items/Makefile
  src/client/454/Makefile
  src/client/x11/Makefile
  src/replay/Makefile
  src/replay/tools/Makefile
])

AC_OUTPUT
