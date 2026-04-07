
bin_PROGRAMS = bloodspilot-replay
AM_CPPFLAGS = -DCONF_DATADIR=\"$(pkgdatadir)/\" -I$(top_srcdir)/src/client
bloodspilot_replay_SOURCES = buttons.c buttons.h const.h item.h recordfmt.h types.h xpcommon.h xpconfig.h xp-replay.c xp-replay.h

bloodspilot_replay_LDADD = @X_LIBS@ @X_PRE_LIBS@ @X_EXTRA_LIBS@ -lX11
SUBDIRS = tools

