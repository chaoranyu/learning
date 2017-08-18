#ifndef FRIDAY_H
#define FRIDAY_H

#include "test.h"

#undef EXTERN
#ifdef TEST_MAIN
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN TEST_T g_my_test;

#endif /* FRIDAY_H */
