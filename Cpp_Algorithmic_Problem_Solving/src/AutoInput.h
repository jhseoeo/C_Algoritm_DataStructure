#ifndef AUTOINPUT
#define AUTOINPUT

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class AutomatedInput {
public:
	void set(string str);

	template <class T>
	void operator>>(T& n) {
		this->asd >> n;
	}

private:
	stringstream asd;
};

#endif