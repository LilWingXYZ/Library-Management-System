#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Class.h"
using namespace std ;

class System{
public:
    //登录
	UserState user_login(char userId[20], char userPassword[20]);
	//注册
    void user_register(char userId[20], char userPassword[20],char username[40]);

    //查询书籍（单属性普通查询）
	static void search_single_book(char* , char* );

	//查询书籍（多属性联合查询）
	static void search_union_book(char* ,char* );
};

#endif // SYSTEM_H_INCLUDED
