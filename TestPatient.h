/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.h
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef TESTPATIENT_H
#define TESTPATIENT_H
#include "Patient.h"
#include <iostream>

using namespace std;

namespace seneca {

	extern int nextTestPatient;

	class TestPatient : public Patient {
	public:
		TestPatient();
		virtual char type() const override;
		virtual ostream& write(ostream& ostr = cout) const override;
		virtual istream& read(istream& istr = cin) override;
	};
}



#endif // TESTPATIENT_H