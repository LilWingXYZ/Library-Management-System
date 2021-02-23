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

//�û���¼
UserState System::user_login(char userId[20], char userPassword[20])
{
    UserState temp,temp2;
    User tempUser;
	FILE *fp,*fp2;//fp������user.dat,������֤��¼��fp2������borrow.dat�����ڸ�ֵtemp
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
				//��temp���и�ֵ
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

//�û�ע��
//System--------------------------------------------------------------------------------------------
void System::user_register(char userid[20], char userpassword[20],char username[40])
{
    User tempUser,user;
	FILE *fp;
	strcpy(userid, strlwr(userid));
	strcpy(userpassword, strlwr(userpassword)); //���û���������ȫ����ΪСд
	user.setStudentId(userid);
	user.setPassword(userpassword);
	user.setName(username);

	//��֤����ĺϷ���
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
			cout<<"fail,ע��ʧ��."<<endl;
		else
		{
			cout<<"success,ע��ɹ�"<<endl;
			fclose(fp);
			Manager::add_user(user);
		}
	}
	else
		cout<<"fail,������û�id������Ƿ�"<<endl;

}

void System::search_single_book(char* content, char* flag)
{
    cout << "��ѯ" << endl;
	//��book.dat�в�ѯ�鼮
	FILE *fp;
	FILE *fo;
	StateBook book;
	StateBook book2;

	if(NULL==(fp=fopen("book.dat","rb")))//�ļ�������
	{
		cout<<"�ļ�������"<<endl;
		//exit(0);
	}

	//���ϴβ�ѯ���������
	if(NULL==(fo=fopen("search_single.dat","w")))//�ļ�������
	{
		cout<<"�ļ�������"<<endl;
		exit(0);
	}
	fclose(fo);
	if(strcmp(flag,"id") == 0)  //��ID��ѯ,��ȷ��ѯ
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(content,book.getBookId()) == 0)  //�������ID���о�ȷ����
			{
				fo=fopen("search_single.dat","ab");//��׷�ӵķ�ʽ�򿪣�׷�ӵ��ļ�ĩβ
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
				break;//IDΨһ���ҵ��󼴿��˳�
			}
		}
	}
	//����������ѯ�����content��name���Ӽ������ѯ�ɹ�
	else if(strcmp(flag,"name") == 0)//����֧��ģ����ѯ
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
	else if(strcmp(flag,"kind") == 0)//�����Ͳ�ѯ������ģ����ѯ
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
	else if(strcmp(flag,"author") == 0)//��������ߣ���ȷ��ѯ
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

	//���ϲ�ѯ�鼮
	//flag:��־��ѯ������ id��name��kind ��author��other
	// content����ѯ����
   //����ѯ�����ݷŵ�search_union.dat��
void System::search_union_book(char* content,char* flag)
{
	FILE *fp;
	FILE *fo;
	StateBook book;
	StateBook book2;
	if(NULL==(fp=fopen("search_single.dat","rb")))//�ļ�������
	{
		cout<<"�ļ�������"<<endl;
		exit(0);
	}

	//���ϴβ�ѯ���������
	if(NULL==(fo=fopen("search_union.dat","w")))//�ļ�������
	{
		cout<<"�ļ�������"<<endl;
		exit(0);
	}
	fclose(fo);

	if(strcmp(flag,"id") == 0)  //��ID��ѯ,��ȷ��ѯ
	{
		while(!feof(fp))
		{
			fread(&book, sizeof(StateBook), 1, fp);
			if(strcmp(book.getBookId(),"-1")==0) {
				continue;
			}
			if(strcmp(content,book.getBookId()) == 0)  //�������ID���о�ȷ����
			{
				fo=fopen("search_union.dat","ab");//��׷�ӵķ�ʽ�򿪣�׷�ӵ��ļ�ĩβ
				fwrite(&book,sizeof(StateBook),1,fo);
				fclose(fo);
				break;//idΨһ�����꼴���˳�
			}
		}
	}
	else if(strcmp(flag,"name") == 0)//����֧��ģ����ѯ
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
	else if(strcmp(flag,"kind") == 0)//�����Ͳ�ѯ����ȷ��ѯ
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
	else if(strcmp(flag,"author") == 0)//��������ߣ���ȷ��ѯ
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
