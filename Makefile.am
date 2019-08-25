# $Id: Makefile.am,v 1.6 2008/12/17 00:36:23 jdratlif Exp $

SUBDIRS = source
EXTRA_DIST = apidocs docs/*.txt Doxyfile sav \
	vstudio/ffse/ffse.sln vstudio/ffse/ffse.vcproj

sav:
	-mkdir sav
	-cp source/res/Final\ Fantasy\ \(U\)\ \[\!\].sav sav

.PHONY: allclean apidocs bundle touch

allclean: clean
	-rm -rf apidocs
	-rm -rf source/ffse.app
	-rm -f *.bz2
	-find -iname "*~" -exec rm -f {} \;

apidocs: Doxyfile
	@doxygen
    
bundle:
	-cd source && make ffse.app

touch:
	-find -iname "*.cc" -exec touch {} \;
	-find -iname "*.hh" -exec touch {} \;
	-find -iname "*.xrc" -exec touch {} \;

