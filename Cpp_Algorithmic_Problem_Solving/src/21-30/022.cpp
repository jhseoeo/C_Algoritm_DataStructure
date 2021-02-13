/*
	Problem 022
	ID : OCR
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include "../Problems.h"
#include "../AutoInput.h"

using namespace std;

static double cache[502][102];
// all words cases
static string Words[501];
// getting chances of [j]th word is followed [i]th word
// 501th words is chances of words are loacted in front of sentence
static double chancesWordsAfter[502][501];
// getting chances of when [j]th word is followed [i]
static double chancesWordsClassify[501][501];
// sentence that maximizing possibility
static int choice[502][102];
// sentence to process the chance
static int R[101];
// number of words, length of sentences(number of words in single sentence) 
static int words, lenSentence;

// maximum chances of origin sentences of given one.
static double recognize(int prevWord, int position) {
	
	if (position == lenSentence)
		return 0;
	
	double &ret = cache[prevWord][position];
	if (ret != 1.0) return ret;
	// initializing minimum value
	ret = -1e200;

	// saving each words that maxmizies chance
	int& choose = choice[prevWord][position];

	for (int i = 0; i < words; i++) {
		// because it uses log, adds chances, not multiplies
		double tmp = recognize(i, position + 1)
			+ chancesWordsClassify[i][R[position]]
			+ chancesWordsAfter[prevWord][i];

		if (ret < tmp) {
			ret = tmp;
			choose = i;
		}
	}

	return ret;
}

// Traceback the origin sentence that has maximum chance
static string reconstruct(int prevWord, int position) {
	int choose = choice[prevWord][position];
	string ret = Words[choose];

	// get origin sentence recursively 
	if (position < lenSentence - 1)
		ret = ret + " " + reconstruct(choose, position+1);
	return ret;
}

void p022() {
	AutomatedInput Input;
	Input.set(
		"5 3 "
		"I am a boy buy "
		
		"1.0 0.0 0.0 0.0 0.0 "
		""
		"0.1 0.6 0.1 0.1 0.1 "
		"0.1 0.1 0.6 0.1 0.1 "
		"0.1 0.1 0.1 0.6 0.1 "
		"0.2 0.2 0.2 0.2 0.2 "
		"0.2 0.2 0.2 0.2 0.2 "
		
		"0.8 0.1 0.0 0.1 0.0 "
		"0.1 0.7 0.0 0.2 0.0 "
		"0.0 0.1 0.8 0.0 0.1 "
		"0.0 0.0 0.0 0.5 0.5 "
		"0.0 0.0 0.0 0.5 0.5 "

		"4 I am a buy "
		"4 I I a boy "
		"4 I am am boy "
	);

	int trial;
	Input >> words >> trial;

	// getting all words casss
	for (int i = 0; i < words; i++) {
		Input >> Words[i];
	}

	double Ftemp;
	
	// getting chances of each words are located in front of sentence
	for (int i = 0; i < words; i++) {
		Input >> Ftemp;
		chancesWordsAfter[501][i] = log10(Ftemp);
	}

	// getting chances of [j]th word is followed [i]th word
	for (int i = 0; i < words; i++) {
		for (int j = 0; j < words; j++) {
			Input >> Ftemp;
			chancesWordsAfter[i][j] = log10(Ftemp);
		}
	}

	// getting chances of when [j]th word is followed [i]
	for (int i = 0; i < words; i++) {
		for (int j = 0; j < words; j++) {
			Input >> Ftemp;
			chancesWordsClassify[i][j] = log10(Ftemp);
		}
	}

	string Stemp;
	for (int i = 0; i < trial; i++) {
		Input >> lenSentence;
		
		// getting 
		for (int i = 0; i < lenSentence; i++) {
			Input >> Stemp;
			R[i] = distance(Words, find(Words, Words+500, Stemp));
		}

		for (int i1 = 0; i1 < 502; i1++) {
			for (int j1 = 0; j1 < 101; j1++) {
				cache[i1][j1] = 1.0;
				choice[i1][j1] = 0;
				
			}
		}
		recognize(501, 0);
		cout << reconstruct(501, 0) << endl;
	}
}