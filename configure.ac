dnl Initialize autoconf
AC_INIT([ffse], [0.90], [emuWorks@technoplaza.net])

dnl require autoconf >= 2.57
AC_PREREQ([2.57])

dnl use the config.h header
AC_CONFIG_HEADERS([config.h])

dnl initialize automake and allow bzipped distributions
AM_INIT_AUTOMAKE([1.8 dist-bzip2])

dnl enable xrcprefix variable
AC_ARG_VAR([XRC_PREFIX], [path to the XRC files])

if test x$XRC_PREFIX = x; then
    AC_DEFINE_UNQUOTED(XRC_FILE, "xrc/ffse.xrc", [XRC path])
else
    AC_DEFINE_UNQUOTED(XRC_FILE, "$XRC_PREFIX/ffse.xrc", [XRC path])
fi

dnl host system check
AC_CANONICAL_HOST

dnl AM_CONDITIONAL([WINDOWS], test x$host_os = xmingw32)
AM_CONDITIONAL([WINDOWS],
               [case $host_os in
               mingw32 | cygwin ) test x = x ;;
               * ) test 0 = 1 ;;
               esac])

dnl check for c++ compiler and BSD install
AC_PROG_CXX
AC_PROG_INSTALL

dnl tests for wxWidgets
AM_OPTIONS_WXCONFIG
AM_PATH_WXCONFIG([2.4.2], HAVE_WXWIDGETS=1, HAVE_WXWIDGETS=0)

if test $HAVE_WXWIDGETS -eq 1; then
    CPPFLAGS="$CPPFLAGS $WX_CPPFLAGS"
    CXXFLAGS="$CXXFLAGS $WX_CXXFLAGS_ONLY"
    LIBS="$LIBS $WX_LIBS"
else
    AC_MSG_ERROR([wxWidgets >= 2.4.2 is required.
                  
                  Please install wxWidgets 2.4.2 from http://www.wxwidgets.org.
                  
                  This error could also be the result of a non-standard install
                  path or a missing wx-config program.])
fi

dnl configure files to produce
AC_CONFIG_FILES([Makefile source/Makefile])
AC_OUTPUT
