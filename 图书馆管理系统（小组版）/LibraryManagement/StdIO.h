#pragma once
#ifndef STDIO_H
#define STDIO_H
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <cstring>
using namespace std;
class StdIO
{
private:
        void clearBlank(string &temp,const string &mark){
            unsigned int nSize = mark.size();
            while(1)
            {
                unsigned int pos = temp.find(mark);
                if(pos == string::npos)
                {
                    return;
                }
                temp.erase(pos, nSize);
            }
        }
        int getIntDigit(unsigned int num)
        {
                //get how many digits the number has
                int ret = 0;
                unsigned int temp = num;
                for (; temp != 0; ret ++, temp /= 10);
                return ret;
        }
        unsigned int intCut(unsigned int obj, int begPosition, int endPosition)
        {
                /*this function is used to get specific part of an int data, begPosition < endPosition,begPosition is where it begin to cut
                  it's how many times that the number divide 10, example: 12345,cut '234', begPosition = 1, endPosition = 4
                */
                if (begPosition >= endPosition) return 0; //begPosition < endPosition
                else if (begPosition < 0) return 0; //begPosition,endPosition>0
                else if (endPosition > getIntDigit(obj)) return 0; //endPosition should be smaller than the length of the number
                return ((obj / (int)pow(10.0, begPosition)) % ((int)pow(10.0, endPosition - begPosition)));
                // return the number, first cut the tail by dividing, then, cut the head by mod operation
        }
        bool idTest_B(unsigned int bookId, string fname)
        {
                if (bookId <= 0) return false;
                int temp = getIntDigit(bookId);
                if (temp < 8) return false;
                else if (temp > 9) return false; //if the length of the id is illegal
                int get = intCut(bookId, 7, getIntDigit(bookId));
                if (get > 25 || get < 1) return false;
                return true;
        }
        bool idTest_P(unsigned int peopleId, string fname)
        {
                if (peopleId <= 10000) return false;
                return true;
        }
        bool rangeTest(unsigned int test, int begPostition, int endPosition, unsigned int minmum, unsigned int maxmum)
        {
                int temp = intCut(test, begPostition, endPosition);
                if (temp < minmum || temp > maxmum) return false;
                return true;
        }
        bool rangeTest(double test, int begPostition, int endPosition, double minmum, double maxmum)
        {
                if (test > maxmum || test < minmum) return true;
                return true;
        }
        bool isNumber(string test)
        {
                string temp = test;
                double get_d;
                char get_c;
                stringstream rec(temp);
                if (!(rec >> get_d)) return false;
                if (rec >> get_c) return false;
                return true;
        }
        int getDotPosition(string test)
        {
                /*this function is used to find whether the string has a '.', and if it doesn't have such a '.', return 0*/
                string temp = test;
                unsigned int dotPosition = 0;
                dotPosition = temp.find('.');
                if (temp.rfind('.') != dotPosition) return -2; //if the string contine more than one '.' return -2
                if (dotPosition == string::npos) return -1;
                return ((int)dotPosition);
        }
public:
    enum LetterColor
    {
        enmCFC_Red          = FOREGROUND_INTENSITY | FOREGROUND_RED,
        enmCFC_Green        = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
        enmCFC_Blue         = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
        enmCFC_Yellow       = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
        enmCFC_Purple       = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
        enmCFC_Cyan         = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
        enmCFC_Gray         = FOREGROUND_INTENSITY,
        enmCFC_White        = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        enmCFC_HighWhite    = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        enmCFC_Black        = 0,
    };
    enum GroundColor
    {
        enmCBC_Red          = BACKGROUND_INTENSITY | BACKGROUND_RED,
        enmCBC_Green        = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
        enmCBC_Blue         = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
        enmCBC_Yellow       = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
        enmCBC_Purple       = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
        enmCBC_Cyan         = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
        enmCBC_White        = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
        enmCBC_HighWhite    = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
        enmCBC_Black        = 0,
    };
        int get_Int()
        {
                string temp;
                cin >> temp;
                clearBlank(temp," ");
                if (getDotPosition(temp) != -1 || !isNumber(temp)) return 0;
                return (atoi(temp.c_str()));
        }
        int get_Int(int maxLength){
            string temp,result;
            cin >> temp;
            clearBlank(temp," ");
            if (getDotPosition(temp) != -1 || !isNumber(temp)) return 0;
            if (temp.length() > maxLength){
                result = temp.substr(0,maxLength);
            }
            else {
                result = temp;
            }
            return (atoi(result.c_str()));
        }
        double get_Double()
        {
                /*return a float number*/
                string temp;
                cin >> temp;
                clearBlank(temp," ");
                if (!isNumber(temp)) return 0.0;
                int rec = getDotPosition(temp);
                if (rec == -2) return 0.0;
                return ((double)atof(temp.c_str()));
        }
        double get_Double(int maxLength){
                /*return a float number*/
                string temp,result;
                cin >> temp;
                clearBlank(temp," ");
                if (!isNumber(temp)) return 0.0;
                int rec = getDotPosition(temp);
                if (rec == -2) return 0.0;
                if(temp.length() < maxLength){
                    result = temp.substr(0,maxLength);
                }
                else{
                        result = temp;
                }
                return ((double)atof(result.c_str()));
        }
        float get_Float()
        {
                /*return a float number*/
                string temp;
                cin >> temp;
                clearBlank(temp," ");
                if (!isNumber(temp)) return 0.0;
                int rec = getDotPosition(temp);
                if (rec == -2) return 0.0;
                return (atof(temp.c_str()));
        }
        float get_Float(int maxLength){
            /*return a float number*/
                string temp,result;
                cin >> temp;
                clearBlank(temp," ");
                if (!isNumber(temp)) return 0.0;
                int rec = getDotPosition(temp);
                if (rec == -2) return 0.0;
                if(temp.length() < maxLength){
                    result = temp.substr(0,maxLength);
                }
                else{
                    result = temp;
                }
                return (atof(result.c_str()));
        }
        char get_Char()
        {
                /*return a char(the first character)*/
                string temp;
                cin >> temp;
                clearBlank(temp," ");
                return ((char)temp[0]);
        }
       string get_String()
        {
                /*return string*/
                string temp;
                cin >> temp;
                return temp;
        }

        void get_CharArr(int maxLength,char arr[]){
                /*return string*/
                string temp;
                cin >> temp;
                clearBlank(temp," ");
                char *p;
                p = (char *)temp.c_str();
                for(int i = 0;i < maxLength;i++){
                    arr[i] = p[i];
                }
        }
        bool get_Bool()
        {
                /**this function is used to get bool data,if the input is illegal or 'false', just return false*/
                string temp;
                cin >> temp;
                clearBlank(temp," ");
                if (temp.compare("true") == 0 || temp.compare("1") == 0) return true;
                else if (temp.compare("false") == 0 || temp.compare("0") == 0) return false;
                cout << endl <<  "input illegal, set as false" << endl;
                return false;
        }
        void get_pwd(char pwd[10])
        {
                char temp[10];
                int index = 0;
                while (((temp[index] = getch()) != '\r') && index < 9)
                {
                        if(temp[index] == 8 && index >= 0){
                            index --;//backspace
                            cout << "\b\b";
                        }
                        else cout << "*";
                        index ++;
                }
                temp[index] = '\0';
                cout << endl;
                for(int i = 0;i < 10;i ++) pwd[i] = temp[i];
        }
        void setColor(LetterColor ltColor = enmCFC_White, GroundColor bgColor = enmCBC_Black)
        {
                /** set color */
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, ltColor | bgColor);
        }
        bool charArrCmp(char* ori, char* tar, int length){
            int index = 0;
            for(;index < length && ori && tar; index ++){
                if(ori[index] != tar[index]) return false;
            }
            return true;
        }
};



#endif // STDIO_H_INCLUDED
