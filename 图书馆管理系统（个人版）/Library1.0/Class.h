#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

//各个类的定义及声明
#include<iostream>
#include<string.h>
#include<stdio.h>
#include <time.h>
using namespace std;

/*
	日期类：                                    用于显示归还的截止日期
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
借阅记录。
用于存储用户的操作： 借阅 归还 续借
不可更改。
*/
class Record{
	private:
		char _userId[20];
		char  _bookId[20];
		int _borrowState;// 借阅状态 0表示未借阅  1表示已借阅  2已续借
		Date _startTime;//系统当前时间
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
	图书馆中可进行操作的书
*/
class StateBook{
private:
	char _bookId[20];
	char _bookName[40];
	char _author[40];
	char _kind[40];             // 书籍的类别,例如：计算机类，管理类，励志类等等
	double _price;
	int _borrowState;			//借阅状态 1表示已借阅 0表示未借阅 2已续借
	char _borrowUserId[20];		//借阅人的id
	int _appointmentState;		//预约状态 1表示已预约  0表示未预约
	char _appointmentUserId[20];//预约人的id
	Date _deadlineTime;			//归还的截止日期 例如：2017-10-15  若没有借出则不显示
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
存放每个用户的借阅信息
*/
class UserState{
private:
	char _userId[20]; // 用户Id
	int _account;//已借书籍数量
	StateBook _stateBook[10]; //已经借的书的id集合
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
