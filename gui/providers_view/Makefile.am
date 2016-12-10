## Makefile.am for gtk+/demos
#include $(top_srcdir)/Makefile.decl

#democodedir=$(datadir)/gtk-2.0/demo

## These should be in the order you want them to appear in the
## demo app, which means alphabetized by demo title, not filename
demos =						\
	appwindow.o				\
	assistant.o				\
	builder.o				\
	button_box.o				\
	changedisplay.o				\
	clipboard.o				\
	colorsel.o				\
	combobox.o				\
	dialog.o				\
	drawingarea.o				\
	editable_cells.o			\
	entry_buffer.o				\
	entry_completion.o			\
	expander.o  				\
	hypertext.o				\
	iconview.o				\
	iconview_edit.o				\
	images.o				\
	infobar.o				\
	links.o					\
	list_store.o				\
	menus.o					\
	offscreen_window.o			\
	offscreen_window2.o			\
	panes.o					\
	pickers.o				\
	pixbufs.o				\
	printing.o				\
	rotated_text.o				\
	search_entry.o				\
	sizegroup.o				\
	spinner.o				\
	stock_browser.o				\
	textview.o				\
	textscroll.o				\
	toolpalette.o				\
	tree_store.o				\
	ui_manager.o

INCLUDES = \
	-DDEMOCODEDIR="\"$(democodedir)\""	\
	-I$(top_srcdir) 			\
	-I$(top_builddir)/gdk			\
	-DGDK_DISABLE_DEPRECATED		\
	-DGTK_DISABLE_DEPRECATED 		\
	$(GTK_DEBUG_FLAGS)			\
	$(GTK_DEP_CFLAGS)

DEPS = \
	$(top_builddir)/gdk/$(gdktargetlib) 				\
	$(top_builddir)/gtk/$(gtktargetlib)

LDADDS = \
	$(top_builddir)/gdk/$(gdktargetlib)        			\
	$(top_builddir)/gtk/$(gtktargetlib)				\
	$(GTK_DEP_LIBS) 						\
	-lm

bin_PROGRAMS = gtk-demo

BUILT_SOURCES = demos.h

EXTRA_DIST += 		\
	$(IMAGEFILES)	\
	demo.ui

#demos.h: @REBUILD@ $(demos) geninclude.pl
#	(here=`pwd` ; cd $(srcdir) && $(PERL) $$here/geninclude.pl $(demos)) > demos.h

gtk_demo_SOURCES = 		\
	$(demos)		\
	demo-common.h		\
	main.o			\
	demos.h

gtk_demo_DEPENDENCIES = $(DEPS)
gtk_demo_LDADD = $(LDADDS)
gtk_demo_LDFLAGS = -export-dynamic

IMAGEFILES=	alphatest.png		\
	        apple-red.png		\
		background.jpg		\
		floppybuddy.gif		\
		gnome-applets.png	\
		gnome-calendar.png	\
		gnome-fs-directory.png	\
		gnome-fs-regular.png	\
		gnome-foot.png		\
		gnome-gimp.png		\
		gnome-gmush.png		\
		gnome-gsame.png		\
		gnu-keys.png		\
		gtk-logo-rgb.gif		

democode_DATA = $(demos) $(IMAGEFILES) demo.ui

# ------------------- MSVC Projects --------------------
MSVCPROJS = gtk-demo

gtk_demo_FILES = $(gtk_demo_SOURCES)
gtk_demo_EXCLUDES = gtkdemodummy

#include $(top_srcdir)/build/Makefile.msvcproj

# dist-hook: $(top_builddir)/build/win32/vs9/gtk-demo.vcproj

DISTCLEANFILES = demos.h

-include $(top_srcdir)/git.mk
