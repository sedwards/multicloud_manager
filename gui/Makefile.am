## Makefile.am for gtk+/demos
#include $(top_srcdir)/Makefile.decl

## These should be in the order you want them to appear in the
## demo app, which means alphabetized by demo title, not filename
demos_base =					\
	application_demo.o			\
	assistant.o				\
	builder.o				\
	button_box.o				\
	changedisplay.o				\
	clipboard.o				\
	colorsel.o				\
	combobox.o				\
	css_accordion.o                         \
	css_basics.o				\
	css_multiplebgs.o			\
	css_pixbufs.o				\
	css_shadows.o				\
	cursors.o				\
	dialog.o				\
	drawingarea.o				\
	editable_cells.o			\
	entry_buffer.o				\
	entry_completion.o			\
	event_axes.o				\
	expander.o  				\
        filtermodel.o				\
	foreigndrawing.o			\
	gestures.o				\
	glarea.o				\
	headerbar.o				\
	hypertext.o				\
	iconview.o				\
	iconview_edit.o				\
	images.o				\
	infobar.o				\
	links.o					\
	listbox.o				\
	flowbox.o				\
	list_store.o				\
	markup.o				\
	menus.o					\
	modelbutton.o				\
	offscreen_window.o			\
	offscreen_window2.o			\
	overlay.o				\
	overlay2.o				\
	panes.o					\
	pickers.o				\
	pixbufs.o				\
	popover.o				\
	printing.o				\
	revealer.o				\
	rotated_text.o				\
	scale.o					\
	search_entry.o				\
	search_entry2.o				\
	shortcuts.o				\
	sidebar.o				\
	sizegroup.o				\
	spinbutton.o				\
	spinner.o				\
	stack.o					\
	textmask.o				\
	textview.o				\
	textscroll.o				\
	theming_style_classes.o			\
	toolpalette.o				\
	transparent.o				\
	tree_store.o

#demos_opt =

#if BUILD_FONT_DEMO
demos_opt += font_features.o
#endif

#if OS_UNIX
demos_opt += pagesetup.o
#endif

demos = $(demos_base) $(demos_opt)

AM_CPPFLAGS = \
	-I$(top_srcdir) 			\
	-I$(top_builddir)/gdk			\
	-DGDK_DISABLE_DEPRECATED		\
	-DGTK_DISABLE_DEPRECATED 		\
	$(GTK_DEBUG_FLAGS)			\
	$(GTK_DEP_CFLAGS)

DEPS = \
	$(top_builddir)/gtk/libgtk-3.la

LDADDS = \
	$(top_builddir)/gtk/libgtk-3.la		\
	$(top_builddir)/gdk/libgdk-3.la		\
	$(GTK_DEP_LIBS)				\
	$(GDK_DEP_LIBS)				\
	-lm

#if BUILD_FONT_DEMO
AM_CPPFLAGS += $(FONTDEMO_CFLAGS)
LDADDS += $(FONTDEMO_LIBS)
#endif

bin_PROGRAMS = gtk3-demo gtk3-demo-application

desktopdir = $(datadir)/applications
dist_desktop_DATA = gtk3-demo.desktop

BUILT_SOURCES = demos.h demo_resources.o

EXTRA_DIST += 				\
	data/source.svg			\
	data/symbolic-source.svg	\
	demo.gresource.xml		\
	$(resource_files)		\
	org.gtk.Demo.gschema.xml	\
	demos.h.win32

gsettings_SCHEMAS = \
	org.gtk.Demo.gschema.xml

#@GSETTINGS_RULES@

demos.h: $(demos) geninclude.pl
	 $(AM_V_GEN) (here=`pwd` ; cd $(srcdir) && $(PERL) $$here/geninclude.pl $(demos)) > demos.h

demos.h.win32: $(demos_base) geninclude.pl
	 $(AM_V_GEN) (here=`pwd` ; cd $(srcdir) && $(PERL) $$here/geninclude.pl $(demos_base)) > demos.h.win32

nodist_gtk3_demo_SOURCES = demos.h

gtk3_demo_SOURCES = 		\
	$(demos)		\
	demo_resources.o	\
	main.o

gtk3_demo_DEPENDENCIES = $(DEPS)
gtk3_demo_LDADD = $(LDADDS)
gtk3_demo_LDFLAGS = -export-dynamic

gtk3_demo_application_SOURCES = \
	application.o 		\
	demo_resources.o

gtk3_demo_application_LDADD = $(LDADDS)

#resource_files = $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(builddir)/demo.gresource.xml)

demo_resources.o: demo.gresource.xml $(resource_files)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(srcdir) --generate-source $(srcdir)/demo.gresource.xml

iconthemedir = $(datadir)/icons/hicolor

appsicon16dir = $(iconthemedir)/16x16/apps
appsicon22dir = $(iconthemedir)/22x22/apps
appsicon24dir = $(iconthemedir)/24x24/apps
appsicon32dir = $(iconthemedir)/32x32/apps
appsicon48dir = $(iconthemedir)/48x48/apps
appsicon256dir = $(iconthemedir)/256x256/apps
appsiconscalabledir = $(iconthemedir)/scalable/apps

dist_appsicon16_DATA = data/16x16/gtk3-demo.png data/16x16/gtk3-demo-symbolic.symbolic.png
dist_appsicon22_DATA = data/22x22/gtk3-demo.png data/22x22/gtk3-demo-symbolic.symbolic.png
dist_appsicon24_DATA = data/24x24/gtk3-demo.png data/24x24/gtk3-demo-symbolic.symbolic.png
dist_appsicon32_DATA = data/32x32/gtk3-demo.png data/32x32/gtk3-demo-symbolic.symbolic.png
dist_appsicon48_DATA = data/48x48/gtk3-demo.png data/48x48/gtk3-demo-symbolic.symbolic.png
dist_appsicon256_DATA = data/256x256/gtk3-demo.png data/256x256/gtk3-demo-symbolic.symbolic.png

update_icon_cache = $(top_builddir)/gtk/gtk-update-icon-cache$(EXEEXT) --ignore-theme-index --force

install-data-hook: install-update-icon-cache
uninstall-hook: uninstall-update-icon-cache

install-update-icon-cache:
	$(AM_V_at)$(POST_INSTALL)
	test -n "$(DESTDIR)" || $(update_icon_cache) "$(iconthemedir)"

uninstall-update-icon-cache:
	$(AM_V_at)$(POST_UNINSTALL)
	test -n "$(DESTDIR)" || $(update_icon_cache) "$(iconthemedir)"

# ------------------- MSVC Build Items ----------------
MSVCPROJS = gtk3-demo gtk3-demo-application

gtk3_demo_FILES = $(gtk3_demo_SOURCES)
gtk3_demo_EXCLUDES = font_features.o|pagesetup.o

gtk3_demo_application_FILES = $(gtk3_demo_application_SOURCES)
gtk3_demo_application_EXCLUDES = dummy

#include $(top_srcdir)/build/Makefile.msvcproj

dist-hook: \
	$(top_builddir)/build/win32/vs9/gtk3-demo.vcproj	\
	$(top_builddir)/build/win32/vs9/gtk3-demo-application.vcproj

DISTCLEANFILES = demos.h demos.h.win32

#-include $(top_srcdir)/git.mk
