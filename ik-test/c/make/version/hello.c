#include <stdio.h>

#include "hello.h"

static char *hello_version_string =
    "hello v" HELLO_BUILD_VER
    " built by " HELLO_BUILD_USER " on " HELLO_BUILD_HOST " at " HELLO_BUILD_DATE;

static const char *hello_compiler =
#if defined(__INTEL_COMPILER)
#define __(x) #x
#define _(x) __(x)
  "icc " _(__INTEL_COMPILER) " (" __VERSION__ ")";
#undef _
#undef __
#elif defined(__clang__)
  "Clang/LLVM " __clang_version__;
#elif defined (__GNUC__)
  "GCC " __VERSION__;
#else
  "unknown compiler";
#endif

int
main()
{
    fprintf(stdout, "\n# show version\n%s\n\n", hello_version_string);
    fprintf(stdout, "# show version verbose\n"
        "%-25s%s\n"
        "%-25s%s\n"
        "%-25s%s\n"
        "%-25s%s\n"
        "%-25s%s\n"
        "%-25s%s\n\n",
        "Version", "v" HELLO_BUILD_VER,
        "Compiled by", HELLO_BUILD_USER,
        "Compile host", HELLO_BUILD_HOST,
        "Compile date", HELLO_BUILD_DATE,
        "Compile location", HELLO_BUILD_TOPDIR,
        "Compiler", hello_compiler);

    return 0;
}
