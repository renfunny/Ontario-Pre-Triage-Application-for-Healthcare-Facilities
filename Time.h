/* Citation and Sources...
Final Project Milestone 4
Module: Time
Filename: Time.h
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef TIME_H
#define TIME_H

using namespace std;
namespace seneca {

	class Time {

		unsigned int m_min;

	public:

		Time& reset();
		Time(unsigned int min = 0u);
		ostream& write(ostream& ostr = cout) const;
		istream& read(istream& istr = cin);
		operator unsigned int()const;
		Time& operator *= (int val);
		Time& operator-=(const Time& D);
		Time operator-(const Time& T)const;

	};
	ostream& operator<<(ostream& ostr, const Time& time);
	istream& operator>>(istream& istr, Time& time);
}
#endif // TIME_H
