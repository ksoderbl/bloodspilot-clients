bin_PROGRAMS = bloodspilot-client-x11
AM_CPPFLAGS = -DCONF_DATADIR=\"$(pkgdatadir)/\" -I$(top_srcdir)/src/client
bloodspilot_client_x11_SOURCES = \
about.c audio.h bitmaps.c bitmaps.h colors.c configure.c dbuff.c dbuff.h guimap.c guiobjects.c icon.h join.c paintdata.c paintdata.h painthud.c painthudradar.c paintmessages.c paintscorelist.c record.c record.h talk.c welcome.c widget.c widget.h xdefault.c xevent.c xevent.h xeventhandlers.c xeventhandlers.h xhacks.h xinit.c xinit.h xpaint.c xpaint.h xpclient_x11.h xpilot.c
#xpilot_CFLAGS = @X_CFLAGS@

bloodspilot_client_x11_LDADD = $(top_builddir)/src/client/libxpclient.a @X_LIBS@ @X_PRE_LIBS@ @X_EXTENSIONS_LIB@ @X_EXTRA_LIBS@ -lX11 @SOUND_LIBS@
#EXTRA_xpilot_SOURCES = debugaudio.c
