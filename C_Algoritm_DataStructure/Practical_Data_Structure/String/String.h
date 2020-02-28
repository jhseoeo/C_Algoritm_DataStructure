/*
	String searching algorithm.
*/

#ifndef STRING_H
#define STRING_H

#include "../../Base/Base.h"
#include <string.h>
#include <limits.h>

static int bf_match(const char* txt, const char* pat); // Brute-force method.
static int bm_match(const char* txt, const char* pat); // Boyer-Moore method. Commonly used.
int String_Main();

#endif