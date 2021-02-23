#pragma once
#ifndef LTIME
#define LTIME
#include<string>
using namespace std;

class Ltime
{

private:
    string date;
public:
    Ltime();//获得系统时间并且赋值给date，并截取到年月日时
    void setDate(string Date);
    string getDate();
    bool IsLeap(int year);//IsLeap函数判断一个年份是否为闰年
    bool StringToDate(string date, int& year, int& month, int& day); //取出日期中的年月日时并判断日期是否合法
    int DayInYear(int year, int month, int day);//根据给定的日期，求出它在该年的第几天
    int DaysBetween2Date(string date1, string date2);//计算日期之间的天数
};
#endif // LTIME
