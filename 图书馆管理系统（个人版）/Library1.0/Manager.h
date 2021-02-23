#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Class.h"
#include "User.h"
//��������Ա�µĺ���
class Manager{
private:
	char _adminAccount[20];
	char _adminPassword[20];

public:
	//���һ����
	static void add_single_book(StateBook statebook);

	//ɾ��һ����
	static bool delete_single_book(StateBook statebook);

	//����û���ͬʱ����һ��������Ϣrecord.dat
	static bool add_user(User user);

	//ɾ���û���ͬʱɾ����Ӧ�Ľ�����Ϣ
	static bool delete_user(char id[20]);

	//�鿴�û��Ľ�����Ϣ
	static void getUserRecord(char id[20]);

	//��ʼ��ϵͳ
	static void initSystem();

	//��ʼ���鼮
	static void initBook(const char *fileName);

	//��ʼ���û�
	static void initUser(const char *fileName);

	//�õ�Id
	static void getId(char string[20]);

	//�õ��û���ʷ���Ĳ���
	static void getUserLog(char id[20]);

	static void manager_single_show(int);

	static void manager_union_show(int flag);

	//һ����������鼮
	static void random();

	//����õ�һ����
	static StateBook randomGetBook(int flag);


	//��ʾȫ���鼮��Ϣ
	static void showAllBookMsg();

	//��ʾȫ���û���Ϣ
	static void showAllUserMsg();

	//�����ʾʮ���鼮��Ϣ
	static void showTenBookMsg();

	//��ʾ���е���־��Ϣ
	static void showLogMsg();

	char* getAccount(){
		return _adminAccount;
	}
	char* getPassword(){
		return _adminPassword;
	}

	void setAccount(char account[20]){
		strcpy(_adminAccount, account);
	}
	void setPassword(char password[20]){
		strcpy(_adminPassword, password);
	}
	static void showNowRecord(UserState user);

	//�޸��鼮��Ϣ�����ƣ����ͣ����ߣ��۸�
	static void updatebook(StateBook book);

	//�޸��û���Ϣ(����������)
	static void updateuser(char user_id[20]);
};

#endif // MANAGER_H_INCLUDED

