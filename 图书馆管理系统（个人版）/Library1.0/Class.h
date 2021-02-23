#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

//������Ķ��弰����
#include<iostream>
#include<string.h>
#include<stdio.h>
#include <time.h>
using namespace std;

/*
	�����ࣺ                                    ������ʾ�黹�Ľ�ֹ����
*/
class Date{
private:
	int _year;
	int _month;
	int _day;
public:
	Date() {
		time_t timep;
		struct tm *p;
		time(&timep);
		p = gmtime(&timep);
		_year = p->tm_year+1900;
		_month = p->tm_mon+1;
		_day = p->tm_mday;
	}

	int getYear(){
		return _year;
	}
	int getMonth(){
		return _month;
	}
	int getDay(){
		return _day;
	}
	void setYear(int year){
		_year = year;
	}
	void setMonth(int month){
		_month = month;
	}
	void setDay(int day){
		_day = day;
	}

	void showDate() {
		cout<<_year<<"-"<<_month<<"-"<<_day;
	}

};

/*
���ļ�¼��
���ڴ洢�û��Ĳ����� ���� �黹 ����
���ɸ��ġ�
*/
class Record{
	private:
		char _userId[20];
		char  _bookId[20];
		int _borrowState;// ����״̬ 0��ʾδ����  1��ʾ�ѽ���  2������
		Date _startTime;//ϵͳ��ǰʱ��
public:
	int getBorrowState(){
		return _borrowState;
	}

	void setBorrowState(int borrowState){
		_borrowState =  borrowState;
	}

	Date getStartTime(){
		return _startTime;
	}

	void setStartTime(Date startTime){
		_startTime =  startTime;
	}

	char* getUserId(){
		return _userId;
	}

	void setUserId(char userId[20]){
		strcpy(_userId, userId);
	}

	char* getBookId() {
		return _bookId;
	}

	void setBookId(char bookId[20]){
		strcpy(_bookId, bookId);
	}
};

/*
	ͼ����пɽ��в�������
*/
class StateBook{
private:
	char _bookId[20];
	char _bookName[40];
	char _author[40];
	char _kind[40];             // �鼮�����,���磺������࣬�����࣬��־��ȵ�
	double _price;
	int _borrowState;			//����״̬ 1��ʾ�ѽ��� 0��ʾδ���� 2������
	char _borrowUserId[20];		//�����˵�id
	int _appointmentState;		//ԤԼ״̬ 1��ʾ��ԤԼ  0��ʾδԤԼ
	char _appointmentUserId[20];//ԤԼ�˵�id
	Date _deadlineTime;			//�黹�Ľ�ֹ���� ���磺2017-10-15  ��û�н������ʾ
public:
	void setBookId(const char bookId[20]){
		strcpy(_bookId, bookId);
	}
	void setBookName(const char bookName[40]){
		strcpy(_bookName, bookName);
	}
	void setAuthor(const char author[40]){
		strcpy(_author, author);
	}
	void setKind(const char kind[40]){
		strcpy(_kind, kind);
	}
	void setPrice(double price)
	{
		_price=price;
	}
	void setBorrowState(int borrowState){
		_borrowState = borrowState;
	}
	void setBorrowUserID(const char borrowUserId[20]){
		strcpy(_borrowUserId, borrowUserId);
	}
	void setAppointmentState(int appointmentState){
		_appointmentState = appointmentState;
	}
	void setAppointmentUserId(const char appointmentUserId[20]){
		strcpy(_appointmentUserId, appointmentUserId);
	}
	void setDeadlineTime(Date date){
		_deadlineTime.setYear(date.getYear());
		_deadlineTime.setMonth(date.getMonth());
		_deadlineTime.setDay(date.getDay());
	}
	char* getBookId(){
		return  _bookId;
	}
	char* getBookName(){
		return  _bookName;
	}
	char* getAuthor(){
		return  _author;
	}
	char* getKind(){
		return  _kind;
	}
	double getPrice(){
		return _price;
	}
	int getBorrowState(){
		return _borrowState;
	}
	char* getBorrowUserID(){
		return  _borrowUserId;
	}
	int getAppointmentState(){
		return _appointmentState;
	}
	char* getAppointmentUserId(){
		return  _appointmentUserId;
	}
	Date getDeadlineTime(){
		return _deadlineTime;
	}
};

/*
���ÿ���û��Ľ�����Ϣ
*/
class UserState{
private:
	char _userId[20]; // �û�Id
	int _account;//�ѽ��鼮����
	StateBook _stateBook[10]; //�Ѿ�������id����
public:
	char* getUserId() {
		return _userId;
	}
	void setUserId(const char id[20]) {
		strcpy(_userId, id);
	}
	int getAccount() {
		return _account;
	}
	void setAccount(int account) {
		_account = account;
	}
	StateBook * getStateBooks() {
		return _stateBook;
	}
	void setStateBooks(StateBook stateBook ,int n) {

			_stateBook[n] = stateBook;

	}
};

#endif // CLASS_H_INCLUDED
