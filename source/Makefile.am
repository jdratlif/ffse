AUTOMAKE_OPTIONS = subdir-objects
CLEANFILES = res/ffse.cc
EXTRA_DIST = res/ffse.icns res/ffse.xrc res/Info.plist \
	res/orb32x32.ico res/orb32x32.xpm res/windows.rc

bin_PROGRAMS = ffse

ffse_SOURCES = ffseApp.cc ffseApp.hh \
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

ffse.app: ffse res/ffse.icns res/Info.plist
	-mkdir ffse.app
	-mkdir ffse.app/Contents
	-mkdir ffse.app/Contents/MacOS
	-mkdir ffse.app/Contents/Resources
	cp ffse ffse.app/Contents/MacOS
	cp res/Info.plist ffse.app/Contents
	cp res/ffse.icns ffse.app/Contents/Resources
	echo -n 'APPL????' > ffse.app/Contents/PkgInfo
