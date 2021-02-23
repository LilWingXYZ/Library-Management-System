#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "Class.h"
#include "Manager.h"
#include "System.h"
#include "User.h"
using namespace std;
void str2int(int &int_temp,const string &string_temp)
{
    stringstream stream(string_temp);
    stream>>int_temp;
}
StateBook searchbyid(char book_id[20])
{
	Date date;
	StateBook book,book2;
	FILE *fp;
	book.setBookId("-1");
	book.setBookName("-1");
	book.setKind("-1");
	book.setAuthor("-1");
	book.setPrice(-1);
	book.setBorrowState(0);
	book.setAppointmentState(0);
	book.setAppointmentUserId("-1");
	book.setBorrowUserID("-1");
	book.setDeadlineTime(date);

	if(NULL==(fp=fopen("book.dat","rb")))//�ļ�������
	{
		cout<<"�ļ�������"<<endl;
		//exit(0);
	}
	while(!feof(fp))
	{
		fread(&book2, sizeof(StateBook), 1, fp);
		if(strcmp(book_id,book2.getBookId()) == 0)  //�������ID���о�ȷ����
		{
			book=book2;
			break;
		}
	}
	fclose(fp);
	return (book);
}
void search_book(int  flag1)
{
	int choose;//ѡ��
	string str;
	int flag=1;
	int s_flag;//������־��ѯ������
	char s_context[40]="";//������¼��ѯ����
	int s_flag2;
	string str3;
	int s_flag3;
	string str4;
	while(flag)
	{
		cout<<"------------------�鼮��ѯ����----------------------"<<endl;
		cout<<"------------------1.�鼮��ѯ------------------"<<endl;
		//cout<<"------------------2.���������ϲ�ѯ------------------"<<endl;
		cout<<"------------------0.�˳�----------------------------"<<endl;
		cout<<"please choose:";
		//cin>>choose;
		choose=88;
		getline(cin,str);
		str2int(choose,str);
		switch(choose)
		{
			case 88:
				cout<<"input error!"<<endl;
							break;
			case 1:
				while(flag)
				{
					cout<<"------------------�鼮��ѯ����----------------------"<<endl;
					cout<<"---------1.�鼮���� 2.�鼮���� 3.�鼮����4.id��ȷ��ѯ 0.�˳�----------"<<endl;
					cout<<"please choose:";
					//cin>>s_flag;
					string str2;
					s_flag=88;
					getline(cin,str2);
					str2int(s_flag,str2);

					switch(s_flag)
					{
						case 88:
							cout<<"input error!"<<endl;
							break;
						case 1://�鼮���Ʋ�ѯ
							while(1)
							{
								cout<<"�������鼮����:";
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());cout <<"��������ǣ�" << str << endl;
									break;
								}
							}
							System::search_single_book(s_context,"name");
							Manager::manager_single_show(flag1);
							break;
						case 2://�鼮���Ͳ�ѯ
							while(1)
							{
								cout<<"�������鼮����:";
								//cin>>s_context;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());
									break;
								}
							}
							System::search_single_book(s_context,"kind");
							Manager::manager_single_show(flag1);
							break;
						case 3://�鼮���߲�ѯ
							while(1)
							{
								cout<<"��������������:";
								//cin>>s_context;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());
									break;
								}
							}
							System::search_single_book(s_context,"author");
							Manager::manager_single_show(flag1);
							break;
						case 4://�鼮ID��ѯ
							while(1)
							{
								cout<<"�������鼮Id:";
								//cin>>s_context;
								getline(cin,str);
								if(str.length()>20)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());
									break;
								}
							}
							System::search_single_book(s_context,"id");
							Manager::manager_single_show(flag1);
						case 0:
							flag=0;
							break;
						default:
							cout<<"input error"<<endl;
							break;
					}
				}
				flag=1;
				break;
			/*case 2:
				cout<<"------------------���������ϲ�ѯ���棨��һ����ѡ��---------------------"<<endl;
				cout<<"---------1.�鼮���� 2.�鼮���� 3.�鼮���� 0.�˳� ---------------"<<endl;
				cout<<"please choose:";
				//cin>>s_flag;
				s_flag=88;
				getline(cin,str3);
				str2int(s_flag2,str3);
				switch(s_flag2)
				{
					case 88:
						cout<<"input error!"<<endl;
							break;
					case 1:
						while(1)
						{
							cout<<"�������鼮����:";
							//cin>>book_name;
							getline(cin,str);
							if(str.length()>40)
							{
								cout<<"�������������������������������"<<endl;
							}
							else if(str.length()==0)
							{
								cout<<"����Ϊ�գ�����������"<<endl;
							}
							else
							{
								strcpy(s_context,str.c_str());
								break;
							}
						}
						System::search_single_book(s_context,"name");
						break;
					case 2:
						while(1)
						{
							cout<<"�������鼮����:";
							//cin>>book_name;
							getline(cin,str);
							if(str.length()>40)
							{
								cout<<"�������������������������������"<<endl;
							}
							else if(str.length()==0)
							{
								cout<<"����Ϊ�գ�����������"<<endl;
							}
							else
							{
								strcpy(s_context,str.c_str());
								break;
							}
						}
						System::search_single_book(s_context,"kind");
						break;
					case 3:
						while(1)
						{
							cout<<"��������������:";
							//cin>>book_name;
							getline(cin,str);
							if(str.length()>40)
							{
								cout<<"�������������������������������"<<endl;
							}
							else if(str.length()==0)
							{
								cout<<"����Ϊ�գ�����������"<<endl;
							}
							else
							{

								strcpy(s_context,str.c_str());
								break;
							}
						}
						System::search_single_book(s_context,"author");
						break;
					case 0:
						break;
					default:
						cout<<"input error"<<endl;
						break;
				}
				if(flag)
				{
					cout<<"------------------���������ϲ�ѯ����(�ڶ�����ѡ��)---------------------"<<endl;
					cout<<"---------1.�鼮���� 2.�鼮���� 3.�鼮����4.�鼮id 0.�˳�---------------"<<endl;
					cout<<"please choose:";
					//cin>>s_flag;
					s_flag=88;
					getline(cin,str4);
					str2int(s_flag3,str4);
					switch(s_flag3)
					{
						case 88:
							cout<<"input error!"<<endl;
							break;
						case 1:
							while(1)
							{
								cout<<"�������鼮����:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());
									break;
								}
							}
							System::search_union_book(s_context,"name");
							Manager::manager_union_show(flag1);
							break;
						case 2:
							while(1)
							{
								cout<<"�������鼮����:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());
									break;
								}
							}
							System::search_union_book(s_context,"kind");
							Manager::manager_union_show(flag1);
							break;
						case 3:
							while(1)
							{
								cout<<"��������������:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());
									break;
								}
							}
							System::search_union_book(s_context,"author");
							Manager::manager_union_show(flag1);
							break;
						case 4:
							while(1)
							{
								cout<<"�������鼮Id:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());
									break;
								}
							}
							System::search_union_book(s_context,"id");
							Manager::manager_union_show(flag1);
						case 0:
							flag=0;
							break;
						default:
							cout<<"input error"<<endl;
							continue;
					}
				}*/
			case 0:
				flag=0;
				break;
			default:
				cout<<"input error"<<endl;
				break;
		}
	}
}


/**
�ֶ������鱾��Ϣ
*/
void handInputBook(){

    Date date;//�õ���ǰ����
    char bookName[40];
    char bookKind[40];
    char bookAuthor[40];
    char bookPrice[20];
    double price;
    char str[20] ;
    Manager::getId(str);//�õ�Id
    //ʵ��������
    cout << "������������";
    cin.getline(bookName, 20);
    cout << "���������";
    cin.getline(bookKind, 20);
    cout << "���������ߣ�";
    cin.getline(bookAuthor, 20);
    cout << "������۸�";
    cin >> price;
    StateBook book;
    book.setBookId(str);
    book.setBookName(bookName);
    book.setKind(bookKind);
    book.setAuthor(bookAuthor);
    book.setPrice(price);
    book.setBorrowState(0);
    book.setAppointmentState(0);
    book.setAppointmentUserId("-1");
    book.setBorrowUserID("-1");
    book.setDeadlineTime(date);
    Manager::add_single_book(book);
}



int main()
{
    //cout << "main" << endl;
	int temp;
	//char temp1[40];//����������������ļ۸�
	//������֤�Ƿ��ַ�
	string s = "1234567890abcdefghijklmnopqrstuvwxyz";
	int mark = 0;
	int mark2=0;
	//int usermark = 1;

	bool bl;//���÷���ֵ�жϲ����ĳɹ����
	Date date;//�õ���ǰ����
	int choose;//ѡ��
	string str;
	//char fileName[40];//�ļ���
	int flag=1;//��������ѭ���Ľ���
	char book_id[40],book_name[40],book_kind[40],book_author[40];
	double book_price;
	char user_id[20],user_name[40],user_password[40];
	//char admin_id[20],admin_password[40];
	string judgement;//�����ж��Ƿ����������Ϣ�������룬ϵͳ����ʼ������һ�ε�¼��������
	string judgement1;
	StateBook book;
	User user;
	UserState userstate;
	System system;

	cout<<"�Ƿ����ԭʼ���ݽ��г�ʼ����Ϣ?(Y/N)";
	while(1)
	{
		getline(cin,judgement);
		if(judgement=="Y"||judgement=="y")
		{
				while(1)
				{
					cout<<"���������ԱID:";
					getline(cin,str);
					if(str.length()>20)
					{
						cout<<"�������������������������������"<<endl;
					}
					else if(str.length()==0)
					{
						cout<<"����Ϊ�գ�����������"<<endl;
					}
					else
					{
						strcpy(user_id,str.c_str());
						break;
					}
				}
				while(1)
				{
					cout<<"���������Ա����:";
					getline(cin,str);
					if(str.length()>40)
					{
						cout<<"�������������������������������"<<endl;
					}
					else if(str.length()==0)
					{
						cout<<"����Ϊ�գ�����������"<<endl;
					}
					else
					{
						strcpy(user_password,str.c_str());
						break;
					}
				}
				if(strcmp(user_id,"admin")==0&&strcmp(user_password,"admin")==0)
				{
					Manager::initSystem();
					break;
				}
				else
				{
					cout<<"����ԱID���������,��������������"<<endl;
					break;
				}

		}
		else if(judgement=="N"||judgement=="n"){
		    cout << "�Ƿ�����ֶ����룿<Y/N>";
            getline(cin,judgement1);
            if(judgement1=="N"||judgement1=="n")
            {
                //cout << "����ͼ�����ϵͳʧ�ܣ�" << endl;
                break;
            }
            else if(judgement1=="Y"||judgement1=="y"){
                cout << "�ֶ������鱾��Ϣ" << endl;
                string choice;
                while(true){
                    handInputBook();
                    cout << "�Ƿ�����ֶ�����鼮��(Y or N):";
                    cin >> choice;
                    string str_getline;
                    getline(cin, str_getline);
                    if(choice == "N" || choice == "n"){
                        break;
                    }
                }
                break;
            }
		}
		else
			cout<<"input error,please input again:";
	}

	while(flag)
	{
		//ͼ�����ϵͳ������
		cout<<"-----------------��ӭ����ͼ�����ϵͳ-----------------"<<endl;
		cout<<"-------------------1.�û���¼-------------------------"<<endl;
		cout<<"-------------------2.�ο͵�¼-------------------------"<<endl;
		cout<<"-------------------0.�˳�-----------------------------"<<endl;
		cout<<"please choose:";
		//cin>>choose;
		choose=88;
		getline(cin,str);
		str2int(choose,str);
		switch(choose)
		{
			case 88:
				cout<<"input error!"<<endl;
							break;
			case 1://�û�
				while(flag)
				{
					cout<<"-------------------�û���¼����-------------------"<<endl;
					cout<<"-------------------1.�����ʺŵ�¼-----------------"<<endl;
					cout<<"-------------------2.���û�ע���¼---------------"<<endl;
					cout<<"-------------------0.�˳�-------------------------"<<endl;
					cout<<"please choose:";
					//cin>>choose;
					//choose=0;

					int choose2;
					string str2;
					choose2=88;
					getline(cin,str2);
					str2int(choose2,str2);//����ͬ���Ƶ��ַ���ת��Ϊ����,��ת���Ĵ��ؽ��������ת������ʾ���ִ���
					//cout<<choose2<<endl;
					switch(choose2)
					{
						case 88:
							cout<<"input error!"<<endl;
							break;
						case 1:
							while(1)
							{
								cout<<"�������û�ID:";
								//cin>>user_id;
								getline(cin,str);
								if(str.length()>20)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(user_id,str.c_str());
									break;
								}
							}
							while(1)
							{
								cout<<"�������û�����:";
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(user_password,str.c_str());
									break;
								}
							}
							if(strcmp(user_id,"admin")==0&&strcmp(user_password,"admin")==0)//����Ա
							{
								while(flag)
								{
									//����Ա����
									cout<<"------------------����Ա����---------------------"<<endl;
									cout<<"------------------1.�鼮��ѯ---------------------"<<endl;
									cout<<"------------------2.����鼮---------------------"<<endl;
									cout<<"------------------3.ɾ���鼮---------------------"<<endl;
									cout<<"------------------4.����û�---------------------"<<endl;
									cout<<"------------------5.ɾ���û�---------------------"<<endl;
									cout<<"------------------6.�鿴�û�����ʷ���ļ�¼-------------"<<endl;
									cout<<"------------------7.�鿴�û��ĵ�ǰ������Ϣ-----------"<<endl;
									cout<<"------------------8.���������鼮------------------"<<endl;
									cout<<"------------------9.�޸��鼮��Ϣ-----------------"<<endl;
									cout<<"------------------10.�޸��û���Ϣ-----------------"<<endl;
									cout<<"------------------11.��ʾ���е��û�---------------"<<endl;
									cout<<"------------------12.��ʾ���е��鼮--------------"<<endl;
									cout<<"------------------13.�鿴�����û�����ʷ���ļ�¼-----------"<<endl;
									cout<<"------------------14. ���������û�------------------------"<<endl;
									cout<<"------------------0.�˳�-------------------------"<<endl;
									cout<<"please choose:";
									//cin>>choose;
									int choose3;
									string str3;
									choose3=88;
									getline(cin,str3);
									str2int(choose3,str3);
									switch(choose3)
									{
										case 88:
											cout<<"input error!"<<endl;
														break;
										case 1://�鼮��ѯ
											search_book(1);
											break;
										case 2://����鼮
											while(1)//����
											{
												cout<<"�������鼮����:";
												//cin>>book_name;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(book_name,str.c_str());
													break;
												}
											}
											while(1)//����
											{
												cout<<"�������鼮����:";
												//cin>>book_kind;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(book_kind,str.c_str());
													break;
												}
											}
											while(1)//����
											{
												cout<<"�������鼮����:";
												//cin>>book_author;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(book_author,str.c_str());
													break;
												}
											}
											while(1)//�۸�
											{
												cout<<"�������鼮�۸�:";
												//cin>>book_price;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													book_price=atof(str.c_str());
													if(book_price>0)
														break;
													else
														cout<<"�����������������"<<endl;
												}
											}
											//ʵ��������
											Manager::getId(book_id);
											book.setBookId(book_id);
											book.setBookName(book_name);
											book.setKind(book_kind);
											book.setAuthor(book_author);
											book.setPrice(book_price);
											book.setBorrowState(0);
											book.setAppointmentState(0);
											book.setAppointmentUserId("-1");
											book.setBorrowUserID("-1");
											book.setDeadlineTime(date);
											//���һ����
											Manager::add_single_book(book);
											cout<<"success"<<endl;
											break;

										case 3://ɾ���鼮
											while(1)
											{
												cout<<"�������鼮��ID:";
												//cin>>book_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(book_id,str.c_str());
													break;
												}
											}
											book=searchbyid(book_id);
											if(strcmp(book.getBookId(),"-1")==0)
											{
												cout<<"��ID��Ӧ���鼮�����ڣ�"<<endl;
											}
											else
											{
												if((bl=Manager::delete_single_book(book))==true)
													cout<<"success"<<endl;
												else
													cout<<"fail"<<endl;
											}
											break;
										case 4://����û�
											while(1)
											{
												cout<<"�������û�ID(������������ĸ��ϣ������ִ�Сд):";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											while(1)
											{
												cout<<"�������û�����:";
												//cin>>user_name;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(user_name,str.c_str());
													break;
												}
											}
											while(1)
											{
												cout<<"�������û�����(������������ĸ��ϣ������ִ�Сд):";
												//cin>>user_password;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(user_password,str.c_str());
													break;
												}
											}
											strcpy(user_id, strlwr(user_id));
											strcpy(user_password, strlwr(user_password)); //���û���������ȫ����ΪСд
											//��֤����ĺϷ���
											for (int i = 0; user_id[i] != '\0'; i++)
												{
													mark = 0;
													for (std::size_t j = 0; j < s.length(); j++)
													{
														if (s[j] == user_id[i])mark = 1;
													}
													if (mark == 0)
													{
														//cout << "����id�Ƿ�   " << endl;
														break;
													}

												}
											for (int i = 0; user_password[i] != '\0'; i++)
											{
												mark2 = 0;
												for (std::size_t j = 0; j < s.length(); j++)
												{
													if (s[j] == user_password[j])mark2 = 1;
												}
												if (mark2 == 0)
												{
													//cout << "��������Ƿ�" << endl;
													break;
												}
											}

											if (mark != 0&&mark2!=0)
											{
												//ʵ��������
												user.setStudentId(user_id);
												user.setName(user_name);
												user.setPassword(user_password);
												if((bl=Manager:: add_user(user))==true)
													cout<<"success,����û��ɹ�"<<endl;
												else
													cout<<"fail����id�Ѵ��ڣ����ʧ��"<<endl;
											}
											else
												cout<<"fail,������û�id������Ƿ�"<<endl;
											break;

										case 5://ɾ���û�
											while(1)
											{
												cout<<"�������û�ID:";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											if((bl=Manager:: delete_user(user_id))==true)
												cout<<"success"<<endl;
											else
												cout<<"fail"<<endl;
											break;
										case 6://�鿴�û���ʷ���ļ�¼
											while(1)
											{
												cout<<"�������û�ID:";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											Manager::getUserLog(user_id);
											break;
										case 7://�鿴�û��ĵ�ǰ������Ϣ
											while(1)
											{
												cout<<"�������û�ID:";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											Manager::getUserRecord(user_id);
											break;
										case 8://���������鼮
											cout<<"��ȷ���Ƿ���������add_batch.txt���鼮��Y/N��:";
											while(1)
											{
												getline(cin,judgement);
												if(judgement=="Y"||judgement=="y")
												{
													Manager::initBook("add_batch.txt");
													break;
												}
												else if(judgement=="N"||judgement=="n")
													break;
												else
													cout<<"input error,please input again:";
											}
											break;
										case 9://�޸��鼮��Ϣ
											while(1)
											{
												cout<<"�������鼮ID:";
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(book_id,str.c_str());
													break;
												}
											}
											book=searchbyid(book_id);
											if(strcmp(book.getBookId(),"-1")==0)
											{
												cout<<"��ID��Ӧ���鼮�����ڣ�"<<endl;
											}
											else
											{
												if(book.getBorrowState()!=0)
												{
													cout<<"�������ڱ����ģ��޷��޸��鼮��Ϣ"<<endl;
												}
												else
												{
													while(1)
													{
														temp=0;
														cout<<"ԭ�鼮��Ϣ:"<<book.getBookId()<<"  "<<book.getBookName()<<"  "<<book.getKind()<<"  "<<book.getAuthor()<<"  "<<book.getPrice()<<endl;
														cout<<"������Ҫ�޸ĵ�����:"<<endl;
														cout<<"�鼮����:";
														getline(cin,str);
														if(str.length()>40)
														{
															cout<<"�������������������������������"<<endl;
															continue;
														}
														strcpy(book_name,str.c_str());
														if(strcmp(book_name,"")!=0)
														{
															book.setBookName(book_name);
															temp=1;
														}
														cout<<"�鼮����:";
														getline(cin,str);
														if(str.length()>40)
														{
															cout<<"�������������������������������"<<endl;
															continue;
														}
														strcpy(book_kind,str.c_str());
														if(strcmp(book_kind,"")!=0)
														{
															book.setKind(book_kind);
															temp=1;
														}
														cout<<"�鼮����:";
														getline(cin,str);
														if(str.length()>40)
														{
															cout<<"�������������������������������"<<endl;
															continue;
														}
														strcpy(book_author,str.c_str());
														if(strcmp(book_author,"")!=0)
														{
															book.setAuthor(book_author);
															temp=1;
										cout << "��ʼ��ѯ" << endl;				}

														if(temp==0)
														{
															cout<<"�����Ϊ�գ�δ���޸�"<<endl;
															break;
														}
														if(temp!=0)
														{
															Manager::updatebook(book);
															break;
														}
													}
												}
											}
											break;
										case 10://�޸��û���Ϣ
											while(1)
											{
												cout<<"�������û�id:";
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"�������������������������������"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"����Ϊ�գ�����������"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											Manager::updateuser(user_id);
											break;
										case 11://��ʾ�����û�
											Manager::showAllUserMsg();
											break;
										case 12://��ʾ�����鼮
											Manager::showAllBookMsg();
											break;
										case 13://�鿴�����û�����ʷ���ļ�¼
											Manager::showLogMsg();
											break;
										case 14://���������û�
											cout<<"��ȷ���Ƿ���������add_user.txt���û���Y/N��:";
											while(1)
											{
												//cin>>judgement;
												getline(cin,judgement);
												if(judgement=="Y")
												{
													Manager::initUser("add_user.txt");
													break;
												}
												else if(judgement=="N")
													break;
												else
													cout<<"input error,please input again:";
											}
											break;
										case 0:
											flag=0;break;
										default:
										cout<<"input error"<<endl;break;
									}
								}
							}
							else                                                            //һ���û�
							{
								userstate=system.user_login(user_id,user_password);
								if(strcmp(userstate.getUserId(),"-1")==0)
									cout<<"�û������������"<<endl;
								else
								{
									cout<<"success"<<endl;
									Manager::showNowRecord(userstate);
									while(flag)
									{
										//�û�����
										cout<<"------------------�û�����--------------------"<<endl;
										cout<<"------------------1.�鼮��ѯ------------------"<<endl;
										cout<<"------------------2.����----------------------"<<endl;
										cout<<"------------------3.����----------------------"<<endl;
										cout<<"------------------5.ԤԼ----------------------"<<endl;
										cout<<"------------------6.��ѯ��ǰ������Ϣ----------"<<endl;
										cout<<"------------------0.�˳�----------------------"<<endl;
										cout<<"please choose:";
										//cin>>choose;
										int choose4;
										string str4;
										choose4=88;
										getline(cin,str4);
										str2int(choose4,str4);
										switch(choose4)
										{
											case 88:
												cout<<"input error!"<<endl;
															break;
											case 1://��ѯ�鼮
												search_book(0);
												break;
											case 3://����
												while(1)
												{
													cout<<"�����������鼮ID:";
													//cin>>book_id;
													getline(cin,str);
													if(str.length()>20)
													{
														cout<<"�������������������������������"<<endl;
													}
													else if(str.length()==0)
													{
														cout<<"����Ϊ�գ�����������"<<endl;
													}
													else
													{
														strcpy(book_id,str.c_str());
														break;
													}
												}
												book=searchbyid(book_id);
												if(strcmp(book.getBookId(),"-1")==0)
												{
													cout<<"fail.δ�ҵ����鼮"<<endl;
												}
												else
													user.return_book(user_id,book);
												break;
											case 2://����
												while(1)
												{
													cout<<"����������鼮ID:";
													//cin>>book_id;
													getline(cin,str);
													if(str.length()>20)
													{
														cout<<"�������������������������������"<<endl;
													}
													else if(str.length()==0)
													{
														cout<<"����Ϊ�գ�����������"<<endl;
													}
													else
													{
														strcpy(book_id,str.c_str());
														break;
													}
												}
												book=searchbyid(book_id);
												if(strcmp(book.getBookId(),"-1")==0)
												{
													cout<<"fail.δ�ҵ����鼮"<<endl;
												}
												else
													user.renew_book(user_id,book);
												break;
											case 5://ԤԼ
												while(1)
												{
													cout<<"������ԤԼ���鼮ID:";
													//cin>>book_id;
													getline(cin,str);
													if(str.length()>20)
													{
														cout<<"�������������������������������"<<endl;
													}
													else if(str.length()==0)
													{
														cout<<"����Ϊ�գ�����������"<<endl;
													}
													else
													{
														strcpy(book_id,str.c_str());
														break;
													}
												}
												book=searchbyid(book_id);
												if(strcmp(book.getBookId(),"-1")==0)
												{
													cout<<"fail.δ�ҵ����鼮"<<endl;
												}
												else
													user.appoint_book(user_id,book);
												break;
											case 6://��ʾ�Լ���ǰ�Ľ�����Ϣ
												Manager::getUserRecord(user_id);
												break;
											case 0:
												flag=0;
												break;
											default:
												cout<<"input error"<<endl;
												break;
										}
									}
								}
								flag=1;
							}
							break;
						case 2://��ע��
							while(1)
							{
								cout<<"�������û�ID(������������ĸ��ϣ������ִ�Сд):";
								//cin>>user_id;
								getline(cin,str);
								if(str.length()>20)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(user_id,str.c_str());
									break;
								}
							}
							while(1)
							{
								cout<<"�������û�����:";
								//cin>>user_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(user_name,str.c_str());
									break;
								}
							}
							while(1)
							{
								cout<<"�������û�����(������������ĸ��ϣ������ִ�Сд):";
								//cin>>user_password;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"�������������������������������"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"����Ϊ�գ�����������"<<endl;
								}
								else
								{
									strcpy(user_password,str.c_str());
									break;
								}
							}
							strcpy(user_id, strlwr(user_id));
							strcpy(user_password, strlwr(user_password)); //���û���������ȫ����ΪСд
							//��֤����ĺϷ���
							for (int i = 0; user_id[i] != '\0'; i++)
								{
									mark = 0;
									for (std::size_t j = 0; j < s.length(); j++)
									{
										if (s[j] == user_id[i])mark = 1;
									}
									if (mark == 0)
									{
										//cout << "����id�Ƿ�   " << endl;
										break;
									}

								}
							for (int i = 0; user_password[i] != '\0'; i++)
							{
								mark2 = 0;
								for (std::size_t j = 0; j < s.length(); j++)
								{
									if (s[j] == user_password[i])mark2 = 1;
								}
								if (mark2 == 0)
								{
									//cout << "��������Ƿ�" << endl;
									break;
								}
							}

							if (mark != 0&&mark2!=0)
							{
								//ʵ��������
								user.setStudentId(user_id);
								user.setName(user_name);
								user.setPassword(user_password);
								if((bl=Manager:: add_user(user))==true)
									cout<<"success,����û��ɹ�"<<endl;
								else
									cout<<"fail����id�Ѵ��ڣ����ʧ��"<<endl;
							}
							else
								cout<<"fail,������û�id������Ƿ�"<<endl;
							break;
						case 0:
							flag=0;
							break;
						default:
							cout<<"input error!"<<endl;
							break;
					}
				}
				flag=1;
				break;
			case 2://�ο͵�¼
				while(flag)
				{
					//�οͽ���
					cout<<"------------------�οͽ���---------------------"<<endl;
					cout<<"------------------1.�鼮��ѯ-------------------"<<endl;
					cout<<"------------------0.�˳�-----------------------"<<endl;
					cout<<"please choose:";
					//cin>>choose;
					int choose5;
					string str5;
					choose5=88;
					getline(cin,str5);
					str2int(choose5,str5);
					switch(choose5)
					{
						case 88:
							cout<<"input error!"<<endl;
							break;
						case 1://�鼮��ѯ
							search_book(0);
							break;
						case 0://�˳�
							flag=0;
							break;
						default:
							cout<<"input error"<<endl;
							break;
					}
				}
				flag=1;
				break;
			case 0:
				flag=0;break;
			default:
				cout<<"input error"<<endl;
				break;
		}

	}
	flag=1;
	return 0;
}

