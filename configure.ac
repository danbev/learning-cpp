# Input file to Autoconf
# The autoconf tool translates a configure.ac file into a configure shell script 
# that executes the tests that determines what the build environment is.
AC_INIT(leaningcxx, version-0.0.1)
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([configure.ac])
AC_MSG_NOTICE([Leaning C++11 examples])
AC_CHECK_HEADER(iostream, string)
AC_CONFIG_MACRO_DIR([m4])
echo "                             Testing for a C++ compiler"
AC_PROG_CXX
AC_LANG_PUSH([C++])
CXXFLAGS="-std=c++14 -g"
AC_CONFIG_FILES([Makefile
                 lib/Makefile lib/gtest-1.6.0/Makefile lib/gmock-1.6.0/Makefile
                 src/classes/Makefile 
                 src/new/Makefile 
                 src/algorithms/fundamental/Makefile 
                 src/algorithms/searching/Makefile 
                 src/algorithms/sorting/Makefile 
                 src/algorithms/datastructures/Makefile 
                 src/algorithms/recursive/Makefile 
                 src/algorithms/graphs/Makefile
                 src/concurrency/Makefile
                 src/Makefile 
                 test/Makefile])

AC_COMPILE_IFELSE([AC_LANG_SOURCE(
    [[template <typename T>
    struct check
    {
        static_assert(sizeof(int) <= sizeof(T), "not big enough");
    };

    typedef check<check<bool>> right_angle_brackets;
    int a;
    decltype(a) b;
    typedef check<int> check_type;
    check_type c;
    check_type&& cr = static_cast<check_type&&>(c);]])],,
AC_MSG_FAILURE(['$CXX $CXXFLAGS' does not accept ISO C++11]))

LT_INIT

AC_SUBST([GTEST_VERSION], ["1.6.0"])
if test "x$have_pthread" = "xyes"; then
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=1 -I\$(top_srcdir)/lib/gtest-$GTEST_VERSION"
  GTEST_CXXFLAGS="$PTHREAD_CFLAGS"
  GTEST_LDFLAGS="-L\$(top_builddir)/lib/gtest-$GTEST_VERSION"
  GTEST_LIBS="$PTHREAD_LIBS"
else
  GTEST_CPPFLAGS="-DGTEST_HAS_PTHREAD=0 -I\$(top_srcdir)/lib/gtest-$GTEST_VERSION"
  GTEST_CXXFLAGS=
  GTEST_LDFLAGS="-L\$(top_builddir)/lib/gtest-$GTEST_VERSION"
  GTEST_LIBS=
fi
AC_SUBST([GTEST_CPPFLAGS])
AC_SUBST([GTEST_CXXFLAGS])
AC_SUBST([GTEST_LDFLAGS])
AC_SUBST([GTEST_LIBS])

AC_ARG_ENABLE([gmock],
              [AS_HELP_STRING([--disable-gmock],
                              [Disables use of built-in gmock. If you don't use gmock,
                               you can avoid unnecessary gmock's build by using this option.
                               (Default is enabled.)])],
              [],
              [enable_gmock=yes])
AM_CONDITIONAL([ENABLE_GMOCK], [test "x$enable_gmock" = "xyes"])

if test "x$enable_gmock" = "xyes"; then
  # Define variables for unit test using gtest and gmock
  # TODO: extract GMOCK_VERSION from gmock's directory
  AC_SUBST([GMOCK_VERSION], ["1.6.0"])
  if test "x$have_pthread" = "xyes"; then
    GMOCK_CPPFLAGS="-DGTEST_HAS_PTHREAD=1 -I\$(top_srcdir)/lib/gmock-$GMOCK_VERSION"
    GMOCK_CXXFLAGS="$PTHREAD_CFLAGS"
    GMOCK_LDFLAGS="-L\$(top_builddir)/lib/gmock-$GMOCK_VERSION"
    GMOCK_LIBS="$PTHREAD_LIBS"
  else
    GMOCK_CPPFLAGS="-DGTEST_HAS_PTHREAD=0 -I\$(top_srcdir)/lib/gmock-$GMOCK_VERSION"
    GMOCK_CXXFLAGS=
    GMOCK_LDFLAGS="-L\$(top_builddir)/lib/gmock-$GMOCK_VERSION"
    GMOCK_LIBS=
  fi
  AC_SUBST([GMOCK_CPPFLAGS])
  AC_SUBST([GMOCK_CXXFLAGS])
  AC_SUBST([GMOCK_LDFLAGS])
  AC_SUBST([GMOCK_LIBS])
fi
AC_OUTPUT
