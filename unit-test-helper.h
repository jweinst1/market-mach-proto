#ifndef UNIT_TEST_HELPER_H
#define UNIT_TEST_HELPER_H

#include <stdio.h>
#include <stdlib.h>

static void __unit_test_check(const char* exp, const char* func, unsigned lineno, const char* file)
{
	fprintf(stderr, "***FAILED: exp:'%s' func:'%s' line:'%u', file:'%s'\n", exp, func, lineno, file);
	exit(3);
}

#define UNIT_CHECK(cond) if(!(cond)) __unit_test_check(#cond, __func__, (unsigned)__LINE__, __FILE__)

#endif // UNIT_TEST_HELPER_H
