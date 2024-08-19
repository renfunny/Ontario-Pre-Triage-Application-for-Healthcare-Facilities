/* Citation and Sources...
Final Project Milestone 4
Module: IOAble
Filename: IOAble.h
Version 1.0
Author   Renato Cordova
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>

using namespace std;
namespace seneca {
	class IOAble {
	public:
		virtual ostream& write(ostream& ostr = cout) const = 0;
		virtual istream& read(istream& istr = cin) = 0;
		virtual ~IOAble();
	};

	ostream& operator<<(ostream& ostr, const IOAble& io);
	istream& operator>>(istream& istr, IOAble& io);
}







#endif // !IOABLE_H