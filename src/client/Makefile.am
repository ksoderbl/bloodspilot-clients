
AM_CPPFLAGS = -DCONF_DATADIR=\"$(pkgdatadir)/\"

noinst_LIBRARIES = libxpclient.a
libxpclient_a_SOURCES = \
	arraylist.c arraylist.h astershape.h bit.h blockmap.c checknames.c clientcommand.c \
	color-codes.c const.h datagram.c datagram.h \
	error.c error.h event.c frame.c frame.h gfx2d.h global.c global.h item.h keys.h \
	list.c list.h math.c mapdata.c messages.c meta.c meta.h metaserver.h \
	msg-bms.c msg-parser.c \
	option.c option.h other.c other.h pack.h pack-ng.h packet.c packet.h pkttypes.h \
	paintmap.c paintobjects.c polymap.c portability.c portability.h proto.h query.c query.h \
	randommt.c recordfmt.h rules.h setup.h sockbuf.c sockbuf.h socklib.c socklib.h \
	shipshape.c shipshape.h sysdeps.h talkmacros.c types.h wreckshape.h \
	xpconfig.c xpconfig.h xpilotrc.c \
	client.c client.h clientrank.c clientrank.h \
	default.c gfx2d.c gfx2d.h netclient.c textinterface.c \
	paint.c version.h


if COND_SOUND
libxpclient_a_SOURCES += caudio.c caudio.h oalaudio.c
endif

# From section Conditional subdirectories with AM_CONDITIONAL
# in GNU automake manual.

if COND_X11_CLIENT
  MAYBE_X11 = x11
else
  MAYBE_X11 =
endif

if COND_454_CLIENT
  MAYBE_454 = 454
else
  MAYBE_454 =
endif

# kps - . in SUBDIRS is needed to make sure libxpclient.a is compiled before
# SDL client
SUBDIRS = . items $(MAYBE_X11) $(MAYBE_454)
