/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <cstring>
#include <iostream>
#include "TriagePatient.h"
#include "Utils.h"

using namespace std;

namespace seneca {

	int nextTriagePatient = 1;
	
	TriagePatient::TriagePatient() : Patient(nextTriagePatient) {
		nextTriagePatient++;
		m_symptoms = nullptr;
	}

	TriagePatient::~TriagePatient() {
		delete [] m_symptoms;
	}

	char TriagePatient::type() const {
		return 'T';
	}

	ostream& TriagePatient::write(ostream& ostr) const {
		if (&ostr == &cout) {
			ostr << "TRIAGE" << endl;
		} 
		Patient::write(ostr);

		if (&ostr == &cout) {
			ostr << "Symptoms: " << m_symptoms << endl;
		}
		else if (&ostr != &clog) {
			ostr << "," << m_symptoms;
		}
		return ostr;
	}

	istream& TriagePatient::read(istream& istr) {
		char temp[512];
		delete[] m_symptoms;
		Patient::read(istr);
		if (&istr != &cin) {
			istr.ignore();
			istr.getline(temp, 512);
			m_symptoms = new char[strlen(temp) + 1];
			U.strcpy(m_symptoms, temp);
			nextTriagePatient = Patient::number() + 1;
		} else {
			cout << "Symptoms: ";
			istr.clear();
			istr.ignore(1000, '\n');
			istr.getline(temp, 512);
			m_symptoms = new char[strlen(temp) + 1];
			U.strcpy(m_symptoms, temp);
		}

		if (istr.fail()) {
			delete[] m_symptoms;
			m_symptoms = nullptr;
		}
		return istr;
	}
}