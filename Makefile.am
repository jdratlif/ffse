SUBDIRS = source
EXTRA_DIST = apidocs docs/*.txt Doxyfile vc.net/ffse/ffse.sln \
	vc.net/ffse/ffse.vcproj

.PHONY: allclean apidocs touch

allclean: clean
	-rm -rf apidocs
	-rm -f *.bz2 *.gz
	-find -iname "*~" -exec rm -f {} \;

apidocs: Doxyfile
	@doxygen

touch:
	-find -iname "*.cc" -exec touch {} \;
	-find -iname "*.hh" -exec touch {} \;
	-find -iname "*.xrc" -exec touch {} \;

