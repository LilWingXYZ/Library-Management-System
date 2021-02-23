#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Class.h"
#include "User.h"
//声明管理员下的函数
class Manager{
private:
	char _adminAccount[20];
	char _adminPassword[20];

public:
	//添加一本书
	static void add_single_book(StateBook statebook);

	//删除一本书
	static bool delete_single_book(StateBook statebook);

	//添加用户，同时增加一条借阅信息record.dat
	static bool add_user(User user);

	//删除用户，同时删除相应的借阅信息
	static bool delete_user(char id[20]);

	//查看用户的借阅信息
	static void getUserRecord(char id[20]);

	//初始化系统
	static void initSystem();

	//初始化书籍
	static void initBook(const char *fileName);

	//初始化用户
	static void initUser(const char *fileName);

	//得到Id
	static void getId(char string[20]);

	//得到用户历史借阅操作
	static void getUserLog(char id[20]);

	static void manager_single_show(int);

	static void manager_union_show(int flag);

	//一键随机借阅书籍
	static void random();

	//随机得到一本书
	static StateBook randomGetBook(int flag);


	//显示全部书籍信息
	static void showAllBookMsg();

	//显示全部用户信息
	static void showAllUserMsg();

	//随机显示十本书籍信息
	static void showTenBookMsg();

	//显示所有的日志信息
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

	//修改书籍信息（名称，类型，作者，价格）
	static void updatebook(StateBook book);

	//修改用户信息(姓名，密码)
	static void updateuser(char user_id[20]);
};

#endif // MANAGER_H_INCLUDED

