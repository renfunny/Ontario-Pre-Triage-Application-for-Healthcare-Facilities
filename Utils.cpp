/***********************************************************************
// OOP244 Project
//
// File  Utils.cpp
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
    // start provided code
    bool debug = false;
    Utils U;
    int Utils::getTime() {
        int mins = -1;
        if (debug) {
            int duration[]{ 3,5,9,20,30 };
            mins = (m_testMins %= 1440);
            m_testMins += duration[m_testIndex++ % 5];
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    void Utils::setDebugTime(int hour, int min) {
        seneca::debug = true;
        m_testMins = hour * 60 + min;
    }

    int Utils::strcmp(const char* s1, const char* s2)const {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    // end provided code

    int Utils::getInt(int min, int max) {
        int value;
        bool done = false;
        while (!done) {
            cin >> value;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Bad integer value, try again: ";
            }
            else {
                if (value < min || value > max) {
                    cout << "Invalid value enterd, retry[" << min << " <= value <= " << max << "]: ";
                }
                else {
                    done = true;
                }
            }
        }
        return value;
    }

    char* Utils::strcpy(char* des, const char* src) {
        char* temp = des;
        while (*src) {
            *des = *src;
            des++;
            src++;
        }
        *des = 0;
        return temp;
    }
}