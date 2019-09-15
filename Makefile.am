SUBDIRS = source
EXTRA_DIST = apidocs docs/*.txt Doxyfile sav \
	vstudio/ffse.sln vstudio/ffse.vcxproj \
	vstudio/ffse.vcxproj.filters vstudio/ffse.vcxproj.user

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
