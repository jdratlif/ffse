AUTOMAKE_OPTIONS = subdir-objects
CLEANFILES = res/ffse.cc
EXTRA_DIST = res/ffse.cc res/ffse.xrc res/Info.plist res/orb.ico \
	res/orb32x32.xpm

bin_PROGRAMS = ffse
ffse_SOURCES = ffse.cc ffse.hh \
	model/SaveSlot.cc model/SaveSlot.hh \
	res/ffse.cc \
	view/MainFrame.cc view/MainFrame.hh \
	view/FileDropTarget.cc view/FileDropTarget.hh

if WINDOWS
ffse_SOURCES += res/windows.rc
endif

.rc.o:
	windres @WX_INCLUDES@ -o $@ $<

.xrc.cc:
	wxrc -c -o $@ $<

