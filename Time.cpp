/* Citation and Sources...
Final Project Milestone 4
Module: Time
Filename: Time.cpp
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "Time.h"
#include "Utils.h"

using namespace std;
namespace seneca {

	Time& Time::reset() {
		m_min = U.getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		m_min = min;
	}

	ostream& Time::write(ostream& ostr)const {
		int hours = m_min / 60;
		int minutes = m_min % 60;

		ostr.width(2);
		ostr.fill('0');
		ostr << hours << ":";
		ostr.width(2);
		ostr.fill('0');
		ostr << minutes;

		return ostr;
	}

	istream& Time::read(istream& is) {
		int hour = 0;
		is >> hour;

		if (is.peek() != ':') {
			is.setstate(ios::failbit);
		}
		else {
			is.ignore();
		}

		is >> m_min;

		if (is) {
			m_min += hour * 60;
		}

		return is;
	}


	Time::operator unsigned int()const {
		return m_min;
	}

	Time& Time::operator *= (int val) {
		m_min *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D) {
		if (m_min < D.m_min)
			m_min += 1440;

		m_min -= D.m_min;

		return *this;
	}

	Time Time::operator-(const Time& T)const {
		Time temp(*this);
		temp -= T;

		return temp;
	}

	ostream& operator<<(ostream& ostr, const Time& time) {
		time.write(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Time& time) {
		time.read(istr);
		return istr;
	}
}