/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.h
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include <iostream>
#include "Time.h"
#include "Ticket.h"
#include "IOAble.h"

using namespace std;

namespace seneca {
	class Patient : public IOAble {
		char* m_name;
		int m_ohip;
		Ticket m_ticket;

	public:
		Patient(int ticketNumber = 0); // constructor
		Patient(const Patient& P); // copy constructor
		Patient& operator=(const Patient& P); // copy assignment operator
		~Patient(); // destructor

		virtual char type() const = 0; // returns 'C' or 'T'
		bool operator==(char rhs) const; // returns true if the type is the same as the argument
		bool operator==(const Patient& p) const; // returns true if the type is the same in both objects
		void setArrivalTime(); // sets the arrival time to the current time
		Time time() const; // returns the arrival time
		int number() const; // returns the ticket number
		operator bool() const; // returns true if the object is valid
		operator const char* () const; // returns the name of the patient

		ostream& write(ostream& ostr = cout) const override; // writes the patient information to the ostream object
		istream& read(istream& istr = cin) override; // reads the patient information from the istream object

	};


}

#endif // !SENECA_PATIENT_H