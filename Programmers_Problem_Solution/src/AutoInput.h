#pragma once

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class AutomatedInput {
public:
	void set(string str) {
		asd << str;
	}

	template <class T>
	AutomatedInput& operator>>(T& n) {
		this->asd >> n;
		return *this;
	}

private:
	stringstream asd;
};