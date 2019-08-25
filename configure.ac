AC_INIT([ffse], [1.2], [webmaster@technoplaza.net])
AC_PREREQ([2.59])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.9.6 dist-bzip2])

AC_CANONICAL_HOST
AM_CONDITIONAL([WINDOWS],
               [case $host_os in
               mingw32 | cygwin ) test x = x ;;
               * ) test 0 = 1 ;;
               esac])

AC_PROG_CXX
AC_PROG_INSTALL
AM_OPTIONS_WXCONFIG
AM_PATH_WXCONFIG([2.6.0], HAVE_WXWIDGETS=1, HAVE_WXWIDGETS=0)

if test $HAVE_WXWIDGETS -eq 1; then
    CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
    CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
    LIBS="$LIBS $WX_LIBS"
else
    AC_MSG_ERROR([wxWidgets 2.6 is required.
                  
                  Please install wxWidgets 2.6 from http://www.wxwidgets.org.
                  
                  This error could also be the result of a non-standard install
                  path or a missing wx-config program.])
fi

WX_INCLUDES=""
for opt in $WX_CPPFLAGS
do
    case "$opt" in
        -I*)
            WX_INCLUDES="$WX_INCLUDES $opt"
            ;;
    esac
done
AC_SUBST(WX_INCLUDES)

AC_CONFIG_FILES([Makefile source/Makefile])
AC_OUTPUT

