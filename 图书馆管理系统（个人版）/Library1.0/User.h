#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Class.h"
using namespace std ;

class User{
private:
	char _userId[20];
	char _name[40];
	char _password[40];


public:

	User(){
		strcpy(_userId, "-1");
		strcpy(_name, "");
		strcpy(_password, "");
	}

    User(char id[20],char name[40],  char password[20]){
        strcpy(_userId,id);
		strcpy(_name,name);
        strcpy(_password,password);
    }

	void setStudentId(const char id[20]){
		strcpy(_userId, id);
	}

	void setName(const char name[40]){
		strcpy(_name, name);
	}

	void setPassword(const char password[40]){
		strcpy(_password, password);
	}

	char* getUserId(){
		return _userId;
	}
	char* getName(){
		return _name;
	}

	char* getPassword(){
		return _password;
	}

	//��ѯ�û��Ľ�����Ϣ
	void search_user(char userId[20]);

	//�û�����
	void borrow_book(char userId[20], StateBook book,int flag);

	//�û�����
	void return_book(char userId[20], StateBook book);

	//ԤԼ��
	void appoint_book(char userId[20], StateBook book);

	//����
	void renew_book(char userId[20], StateBook book);


};
#endif // USER_H_INCLUDED
