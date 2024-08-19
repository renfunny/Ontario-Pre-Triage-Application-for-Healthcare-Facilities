/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.cpp
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <cstring>
#include <iostream>
#include "TestPatient.h"

using namespace std;

namespace seneca {

	int nextTestPatient = 1;

	TestPatient::TestPatient() : Patient(nextTestPatient) {
		nextTestPatient++;
	}

	char TestPatient::type() const {
		return 'C';
	}

	ostream& TestPatient::write(ostream& ostr) const {
		if (&ostr == &cout) {
			ostr << "Contagion TEST" << endl;
		}
			Patient::write(ostr);
		return ostr;
	}

	istream& TestPatient::read(istream& istr) {
		Patient::read(istr);
		if (&istr != &cin) {
			nextTestPatient = Patient::number() + 1;
		}
		return istr;
	}
}