#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Class.h"
using namespace std ;

class System{
public:
    //��¼
	UserState user_login(char userId[20], char userPassword[20]);
	//ע��
    void user_register(char userId[20], char userPassword[20],char username[40]);

    //��ѯ�鼮����������ͨ��ѯ��
	static void search_single_book(char* , char* );

	//��ѯ�鼮�����������ϲ�ѯ��
	static void search_union_book(char* ,char* );
};

#endif // SYSTEM_H_INCLUDED
