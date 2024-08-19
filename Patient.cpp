/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.cpp
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

-Removed isValid() function and rewrote bool operator function
-----------------------------------------------------------*/
#include <iostream>
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "Utils.h"

using namespace std;

namespace seneca {

	// constructor
	Patient::Patient(int ticketNumber) : m_ticket(ticketNumber) {
		m_name = nullptr;
		m_ohip = 0;
	}

	// copy constructor
	Patient::Patient(const Patient& P) : m_ticket(P.m_ticket) {
		m_name = new char[strlen(P.m_name) + 1];
		m_ohip = P.m_ohip;
		U.strcpy(m_name, P.m_name);
		m_name[strlen(P.m_name)] = '\0';
	}

	// copy assignment operator
	Patient& Patient::operator=(const Patient& P) {
		m_ticket = P.m_ticket;
		m_ohip = P.m_ohip;
		delete[] m_name;
		m_name = new char[strlen(P.m_name) + 1];
		U.strcpy(m_name, P.m_name);
		m_name[strlen(P.m_name)] = '\0';

		return *this;
	}

	// destructor
	Patient::~Patient() {
		delete[] m_name;
	}

	// returns true if the object is valid
	bool Patient::operator==(char rhs) const {
		return type() == rhs;
	}

	bool Patient::operator==(const Patient& p) const {
		return type() == p.type();
	}

	void Patient::setArrivalTime() {
		m_ticket.resetTime();
	}

	Time Patient::time() const {
		return m_ticket.time();
	}

	int Patient::number() const {
		return m_ticket.number();
	}

	Patient::operator bool() const {
		return (m_ohip != 0) && (m_name != nullptr);
	}

	Patient::operator const char* () const {
		return m_name;
	}

	ostream& Patient::write(ostream& ostr) const {
		if (&ostr == &clog) {
			if (!bool(*this)) {
				ostr << "Invalid Patient Record";
			}
			else {
				ostr.width(53);
				ostr.fill('.');
				ostr.setf(ios::left);
				ostr << m_name;
				ostr << m_ohip;
				ostr.fill(' ');
				ostr.unsetf(ios::left);
				ostr.setf(ios::right);
				ostr.width(5);
				ostr << m_ticket.number();
				ostr.unsetf(ios::right);
				ostr << " " << m_ticket.time();
			}
		}
		else if (&ostr == &cout) {
			if (!bool(*this)) {
				ostr << "Invalid Patient Record" << endl;
			}
			else {
				m_ticket.write(ostr);
				ostr << endl;
				ostr << m_name << ", OHIP: " << m_ohip << endl;
				return ostr;
			}
		}
		else {
			ostr << type() << "," << m_name << "," << m_ohip << ",";
			m_ticket.write(ostr);
		}
		return ostr;
	}

	istream& Patient::read(istream& istr) {
		if (&istr == &cin) {
			char name[51];
			cout << "Name: ";
			if (istr.peek() == '\n') {
				istr.clear();
				istr.ignore();
			}
			istr.get(name, 51, '\n');
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			U.strcpy(m_name, name);
			m_name[strlen(name)] = '\0';
			istr.ignore(1000, '\n');
			cout << "OHIP: ";
			m_ohip = U.getInt(100000000, 999999999);
		}
		else {
			char name[51];
			istr.get(name, 51, ',');
			delete[] m_name;
			m_name = new char[strlen(name) + 1];
			U.strcpy(m_name, name);
			istr.ignore(1000, ',');
			istr >> m_ohip;
			istr.ignore(1000, ',');
			istr >> m_ticket;
		}
		if (istr.fail()) {
			delete[] m_name;
			m_name = nullptr;
		}
		return istr;
	}


}