/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H
#include "Patient.h"
#include <iostream>

using namespace std;

namespace seneca {
	
	extern int nextTriagePatient;

	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		~TriagePatient() override;
		virtual char type() const override;
		virtual ostream& write(ostream& ostr = cout) const override;
		virtual istream& read(istream& istr = cin) override;
	};
}

#endif // TRIAGEPATIENT_H