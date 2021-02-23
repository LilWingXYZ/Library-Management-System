#pragma once
#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <iomanip>
#include <iostream>
using namespace std;

inline void showWelcome(string s) {
        for (int i = 0; i < 4; i++)
        {
            cout << endl;
        }
        cout << setw(55);
        cout << "********************************" << endl;
        cout << setw(27);
        cout << "*   "<<s<<"  *" << endl;
        cout << setw(55);
        cout << "********************************" << endl;
}
#endif

