#include <iostream>
#include "Ltime.h"
#include<string.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;




Ltime::Ltime(){//获得系统时间并且赋值给date，并截取到年月日时

time_t t = time(0);
char ch[64];
strftime(ch, sizeof(ch), "%Y%m%d%H%M%S", localtime(&t)); //年-月-日 时-分-秒
date = string(ch).substr(0,10);////char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx规定日期的格式是yyyy-mm-dd


}
void Ltime::setDate(string Date){

  date = Date;

}
string Ltime::getDate(){

  return date;

}

//IsLeap函数判断一个年份是否为闰年
bool Ltime::IsLeap(int year)
{
   return (year % 4 ==0 || year % 400 ==0) && (year % 100 !=0);
}

//上面的StringToDate函数用于取出日期中的年月日时并判断日期是否合法
bool Ltime::StringToDate(string date, int& year, int& month, int& day)
{
    year = atoi((date.substr(0,4)).c_str());
    month = atoi((date.substr(4,2)).c_str());
    day = atoi((date.substr(6,2)).c_str());
    int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(IsLeap(year)){
         DAY[1] = 29;
    }
    return year >= 0 && month<=12 && month>0 && day<=DAY[month] && day>0;
}

//DayInYear能根据给定的日期，求出它在该年的第几天
int Ltime::DayInYear(int year, int month, int day)
{

    int DAY[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(IsLeap(year))
        DAY[1] = 29;
    for(int i=0; i<month - 1; ++i)
    {
        day += DAY[i];
    }
    return day;
}

int Ltime::DaysBetween2Date(string date1, string date2)
{
     //取出日期中的年月日
     int year1, month1, day1;
     int year2, month2, day2;
     if(!StringToDate(date1, year1, month1, day1) || !StringToDate(date2, year2,month2,day2))
     {
        cout<<"输入的日期格式不正确";
        return -1;
     }
     if(year1 == year2 && month1 == month2)
     {
          return day1 > day2 ? day1 - day2 : day2 - day1;

     //如果年相同
     }else if(year1 == year2)
     {
         int d1, d2;
         d1 = DayInYear(year1, month1, day1);
         d2 = DayInYear(year2, month2, day2);
         return d1 > d2 ? d1 - d2 : d2 - d1;

     //年月都不相同
     }else{
         //确保year1年份比year2早
         if(year1 > year2)
         {
             //swap进行两个值的交换
             swap(year1, year2);
             swap(month1, month2);
             swap(day1, day2);
         }
         int d1,d2,d3;
         if(IsLeap(year1))
             d1 = 366 - DayInYear(year1,month1, day1); //取得这个日期在该年还于下多少天
         else
             d1 = 365 - DayInYear(year1,month1, day1);
         d2 = DayInYear(year2,month2,day2); //取得在当年中的第几天
         cout<<"d1:"<<d1<<", d2:"<<d2;

         d3 = 0;
         for(int year = year1 + 1; year < year2; year++)
         {
             if(IsLeap(year))
                 d3 += 366;
             else
                 d3 += 365;
         }
         return d1 + d2 + d3;
     }
}

