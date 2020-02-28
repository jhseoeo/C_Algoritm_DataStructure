/*
	String searching algorithm.
*/

#include "../../Base/Base.h"
#include <string.h>
#include <limits.h>

static int bf_match(const char* txt, const char* pat); // Brute-force method.
static int bm_match(const char* txt, const char* pat); // Boyer-Moore method. Commonly used.
int String_Main();