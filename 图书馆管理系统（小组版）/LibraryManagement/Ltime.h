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
    Ltime();//���ϵͳʱ�䲢�Ҹ�ֵ��date������ȡ��������ʱ
    void setDate(string Date);
    string getDate();
    bool IsLeap(int year);//IsLeap�����ж�һ������Ƿ�Ϊ����
    bool StringToDate(string date, int& year, int& month, int& day); //ȡ�������е�������ʱ���ж������Ƿ�Ϸ�
    int DayInYear(int year, int month, int day);//���ݸ��������ڣ�������ڸ���ĵڼ���
    int DaysBetween2Date(string date1, string date2);//��������֮�������
};
#endif // LTIME
