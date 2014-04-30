AC_INIT(leaningcxx, version-0.0.1)
AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_CONFIG_SRCDIR([configure.ac])
AC_MSG_NOTICE([Leaning C++11 examples])
AC_CHECK_HEADER(iostream, string)
echo "                             Testing for a C++ compiler"
AC_PROG_CXX
AC_LANG_PUSH([C++])
CXXFLAGS="-std=c++0x"
AC_CONFIG_FILES([
    Makefile
    src/Makefile
])
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
AC_OUTPUT
