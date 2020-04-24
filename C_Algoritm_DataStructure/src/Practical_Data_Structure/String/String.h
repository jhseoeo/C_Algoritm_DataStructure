/*
	String searching algorithm.
*/

#ifndef STRING_H
#define STRING_H

#include "../../Base/Base.h"
#include <string.h>
#include <limits.h>

// Brute-force method.
static int bf_match(const char* txt, const char* pat); 

// Boyer-Moore method. Commonly used.
static int bm_match(const char* txt, const char* pat); 

// Main function to test some of string search method.
int String_Main();

#endif