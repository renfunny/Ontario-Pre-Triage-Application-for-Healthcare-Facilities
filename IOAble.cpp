/* Citation and Sources...
Final Project Milestone 4
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "IOAble.h"

using namespace std;
namespace seneca {
	IOAble::~IOAble() {
	}

	ostream& operator<<(ostream& ostr, const IOAble& io) {
		return io.write(ostr);
	}

	istream& operator>>(istream& istr, IOAble& io) {
		return io.read(istr);
	}
}