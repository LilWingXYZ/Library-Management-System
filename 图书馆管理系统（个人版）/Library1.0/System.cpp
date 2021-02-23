#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Class.h"
#include "Manager.h"
#include "User.h"
#include "System.h"
using namespace std;

//用户登录
UserState System::user_login(char userId[20], char userPassword[20])
{
    UserState temp,temp2;
    User tempUser;
	FILE *fp,*fp2;//fp用来打开user.dat,用于验证登录；fp2用来打开borrow.dat，用于赋值temp
    fp=fopen("user.dat","rb");
	temp.setUserId("-1");
    if(!fp)
    {
        cout<<"open error!"<<endl;
    }
    else{
        while(!feof(fp)){
			fread(&tempUser, sizeof(User), 1, fp);
			//cout<<tempUser.getUserId()<<"   ";
			//cout<<tempUser.getPassword()<<endl;
            if(strcmp(tempUser.getUserId(),userId)==0 && strcmp(tempUser.getPassword() , userPassword)==0)
			{
				temp.setUserId(userId);
				//对temp进行赋值
				fp2=fopen("borrow.dat","rb");
				if(!fp2)
				{
					cout<<"open error!"<<endl;
				}
				else
				{
					while(!feof(fp2))
					{
						fread(&temp2, sizeof(UserState), 1, fp2);
						if(strcmp(temp2.getUserId(),userId)==0)
						{
							return temp2;
							break;
						}
					}
				}
				break;
			}
        }
    }
	fclose(fp);
	return temp;
}

//用户注册
//System--------------------------------------------------------------------------------------------
void System::user_register(char userid[20], char userpassword[20],char username[40])
{
    User tempUser,user;
	FILE *fp;
	strcpy(userid, strlwr(userid));
	strcpy(userpassword, strlwr(userpassword)); //将用户名和密码全部改为小写
	user.setStudentId(userid);
	user.setPassword(userpassword);
	user.setName(username);

	//验证输入的合法性
	string s = "1234567890abcdefghijklmnopqrstuvwxyz";
	int mark = 0;
	int mark2=0;
	//int usermark = 1;
	for (int i = 0; userid[i] != '\0'; i++)
		{
			mark = 0;
			for (size_t j = 0; j < s.length(); j++)
			{
				if (s[j] == userid[i])mark = 1;
			}
			if (mark == 0)
				break;
		}
	for (int i = 0; userpassword[i] != '\0'; i++)
	{
		mark2 = 0;
		for (size_t j = 0; j < s.length(); j++)
		{
			if (s[j] == userpassword[i])mark2 = 1;
		}
		if (mark2 == 0)
			break;
	}

	if (mark != 0&&mark2!=0)
	{
		fp=fopen("user.dat","rb");
		if(!fp)
		{
			cout<<"open error!"<<endl;
		}
		else
		{
			 while(!feof(fp))
			 {
				fread(&tempUser, sizeof(User), 1, fp);
				 if(strcmp(tempUser.getUserId(),userid)==0||strcmp(tempUser.getUserId(),"admin")==0)
				 {
					 break;
				 }
			 }
		}
		if(!feof(fp))
			cout<<"fail,注册失败."<<endl;
		else
		{
			cout<<"success,注册成功"<<endl;
			fclose(fp);
			Manager::add_user(user);
		}
	}
	else
		cout<<"fail,输入的用户id或密码非法"<<endl;

}

void System::search_single_book(char* content, char* flag)
{
    cout << "查询" << endl;
	//从book.dat中查询书籍
	FILE *fp;
	FILE *fo;
	StateBook book;
	StateBook book2;

	if(NULL==(fp=fopen("book.dat","rb")))//文件不存在
	{
		cout<<"文件不存在"<<endl;
		//exit(0);
	}

	//将上次查询的内容清空
	if(NULL==(fo=fopen("search_single.dat","w")))//文件不存在
	{
		cout<<"文件不存在"<<endl;
		exit(0);
	}
	fclose(fo);
	if(strcmp(flag,"id") == 0)  //按ID查询,精确查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(content,book.getBookId()) == 0)  //输入书的ID进行精确查找
			{
				fo=fopen("search_single.dat","ab");//以追加的方式打开，追加到文件末尾
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
				break;//ID唯一，找到后即可退出
			}
		}
	}
	//根据书名查询，如果content是name的子集，则查询成功
	else if(strcmp(flag,"name") == 0)//书名支持模糊查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(book.getBookId(), book2.getBookId()) == 0) {
				break;
			}
			char* bookName = book.getBookName();
			if(strstr(bookName,content))
			{
				fo=fopen("search_single.dat","ab");
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
			}
			book2 = book;
		}
	}
	else if(strcmp(flag,"kind") == 0)//按类型查询，不可模糊查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(book.getBookId(), book2.getBookId()) == 0) {
				break;
			}
			if(strstr(book.getKind(),content))
			{
				fo=fopen("search_single.dat","ab");
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
			}
			book2 = book;
		}
	}
	else if(strcmp(flag,"author") == 0)//按书的作者，精确查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(book.getBookId(), book2.getBookId()) == 0) {
				break;
			}
			if(strstr(book.getAuthor(),content))
			{
				fo=fopen("search_single.dat","ab");
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
			}
			book2 = book;
		}
	}
	fclose(fp);

}

	//联合查询书籍
	//flag:标志查询的属性 id，name，kind ，author，other
	// content：查询内容
   //将查询的内容放到search_union.dat中
void System::search_union_book(char* content,char* flag)
{
	FILE *fp;
	FILE *fo;
	StateBook book;
	StateBook book2;
	if(NULL==(fp=fopen("search_single.dat","rb")))//文件不存在
	{
		cout<<"文件不存在"<<endl;
		exit(0);
	}

	//将上次查询的内容清空
	if(NULL==(fo=fopen("search_union.dat","w")))//文件不存在
	{
		cout<<"文件不存在"<<endl;
		exit(0);
	}
	fclose(fo);

	if(strcmp(flag,"id") == 0)  //按ID查询,精确查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(content,book.getBookId()) == 0)  //输入书的ID进行精确查找
			{
				fo=fopen("search_union.dat","ab");//以追加的方式打开，追加到文件末尾
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
				break;//id唯一，查完即可退出
			}
		}
	}
	else if(strcmp(flag,"name") == 0)//书名支持模糊查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(book.getBookId(), book2.getBookId()) == 0) {
				break;
			}
			char* bookName = book.getBookName();
			if(strstr(bookName,content))
			{
				fo=fopen("search_union.dat","ab");
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
			}
			book2 = book;
		}
	}
	else if(strcmp(flag,"kind") == 0)//按类型查询，精确查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(book.getBookId(), book2.getBookId()) == 0) {
				break;
			}
			if(strstr(book.getKind(),content))
			{
				fo=fopen("search_union.dat","ab");
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
			}
			book2 = book;
		}
	}
	else if(strcmp(flag,"author") == 0)//按书的作者，精确查询
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strstr(book.getAuthor(),content))
			{
				fo=fopen("search_union.dat","ab");
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
			}
			book2 = book;
		}
	}
	fclose(fp);
}
