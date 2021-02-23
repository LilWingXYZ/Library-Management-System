#include<iostream>
#include <conio.h>
#include<windows.h>
using namespace std;
string get_pwd(){
            char temp[10];
            int index = 0;
            while(((temp[index]=getch())!='\r')&&index < 10){
                cout << "*";
                index ++;
            }
            cout << endl;
            return temp;
        }
void setColor(char groundColor,char letterColor){
                /*transfer string as
                0=dark 1=blue 2=green 3=lake blue 4=red 5=purple 6=yellow 7=white 8=gray 9=shallow blue 
                A=shallow green B= very shallow green C=shallow red D=shallow purple E=shallow yellow F=bright white
                */
                string temp = "color ",temp_char_con;
                temp += groundColor;
                temp += letterColor;
                system(temp.data());
        }

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

void setColor(LetterColor ltColor = enmCFC_White, GroundColor bgColor = enmCBC_Black)
{
        /** set color */
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, ltColor | bgColor);
}
int main(){
        string temp = get_pwd();
        setColor('0','1');
        cout <<temp;
        //setColor('0','0');
        cout << "fasdfads";
        return 0;
}
