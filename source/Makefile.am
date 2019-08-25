.rc.o:
	windres -o $@ $<

AUTOMAKE_OPTIONS = subdir-objects
EXTRA_DIST = xrc/ffse.xrc res/orb.ico res/orb16x16.bmp res/orb32x32.bmp

bin_PROGRAMS = ffse
ffse_SOURCES = ffse.cc ffse.hh \
	view/MainFrame.cc view/MainFrame.hh \
	view/FileDropTarget.cc view/FileDropTarget.hh \
	model/SaveSlot.cc model/SaveSlot.hh

if WINDOWS
ffse_SOURCES += windows.rc
endif

