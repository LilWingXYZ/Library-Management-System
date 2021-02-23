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

	if(NULL==(fp=fopen("book.dat","rb")))//文件不存在
	{
		cout<<"文件不存在"<<endl;
		//exit(0);
	}
	while(!feof(fp))
	{
		fread(&book2, sizeof(StateBook), 1, fp);
		if(strcmp(book_id,book2.getBookId()) == 0)  //输入书的ID进行精确查找
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
	int choose;//选项
	string str;
	int flag=1;
	int s_flag;//用来标志查询的属性
	char s_context[40]="";//用来记录查询内容
	int s_flag2;
	string str3;
	int s_flag3;
	string str4;
	while(flag)
	{
		cout<<"------------------书籍查询界面----------------------"<<endl;
		cout<<"------------------1.书籍查询------------------"<<endl;
		//cout<<"------------------2.多属性联合查询------------------"<<endl;
		cout<<"------------------0.退出----------------------------"<<endl;
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
					cout<<"------------------书籍查询界面----------------------"<<endl;
					cout<<"---------1.书籍名称 2.书籍类型 3.书籍作者4.id精确查询 0.退出----------"<<endl;
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
						case 1://书籍名称查询
							while(1)
							{
								cout<<"请输入书籍名称:";
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
								}
								else
								{
									strcpy(s_context,str.c_str());cout <<"你输入的是：" << str << endl;
									break;
								}
							}
							System::search_single_book(s_context,"name");
							Manager::manager_single_show(flag1);
							break;
						case 2://书籍类型查询
							while(1)
							{
								cout<<"请输入书籍类型:";
								//cin>>s_context;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
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
						case 3://书籍作者查询
							while(1)
							{
								cout<<"请输入作者姓名:";
								//cin>>s_context;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
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
						case 4://书籍ID查询
							while(1)
							{
								cout<<"请输入书籍Id:";
								//cin>>s_context;
								getline(cin,str);
								if(str.length()>20)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
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
				cout<<"------------------多属性联合查询界面（第一属性选择）---------------------"<<endl;
				cout<<"---------1.书籍名称 2.书籍类型 3.书籍作者 0.退出 ---------------"<<endl;
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
							cout<<"请输入书籍名称:";
							//cin>>book_name;
							getline(cin,str);
							if(str.length()>40)
							{
								cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
							}
							else if(str.length()==0)
							{
								cout<<"输入为空，请重新输入"<<endl;
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
							cout<<"请输入书籍类型:";
							//cin>>book_name;
							getline(cin,str);
							if(str.length()>40)
							{
								cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
							}
							else if(str.length()==0)
							{
								cout<<"输入为空，请重新输入"<<endl;
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
							cout<<"请输入作者姓名:";
							//cin>>book_name;
							getline(cin,str);
							if(str.length()>40)
							{
								cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
							}
							else if(str.length()==0)
							{
								cout<<"输入为空，请重新输入"<<endl;
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
					cout<<"------------------多属性联合查询界面(第二属性选择)---------------------"<<endl;
					cout<<"---------1.书籍名称 2.书籍类型 3.书籍作者4.书籍id 0.退出---------------"<<endl;
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
								cout<<"请输入书籍名称:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
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
								cout<<"请输入书籍类型:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
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
								cout<<"请输入作者姓名:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
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
								cout<<"请输入书籍Id:";
								//cin>>book_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
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
手动输入书本信息
*/
void handInputBook(){

    Date date;//得到当前日期
    char bookName[40];
    char bookKind[40];
    char bookAuthor[40];
    char bookPrice[20];
    double price;
    char str[20] ;
    Manager::getId(str);//得到Id
    //实例化对象
    cout << "请输入书名：";
    cin.getline(bookName, 20);
    cout << "请输入类别：";
    cin.getline(bookKind, 20);
    cout << "请输入作者：";
    cin.getline(bookAuthor, 20);
    cout << "请输入价格：";
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
	//char temp1[40];//用来辅助测试输入的价格
	//用来验证非法字符
	string s = "1234567890abcdefghijklmnopqrstuvwxyz";
	int mark = 0;
	int mark2=0;
	//int usermark = 1;

	bool bl;//利用返回值判断操作的成功与否
	Date date;//得到当前日期
	int choose;//选项
	string str;
	//char fileName[40];//文件名
	int flag=1;//用来控制循环的结束
	char book_id[40],book_name[40],book_kind[40],book_author[40];
	double book_price;
	char user_id[20],user_name[40],user_password[40];
	//char admin_id[20],admin_password[40];
	string judgement;//用来判断是否进行载入信息，若载入，系统将初始化，第一次登录必须载入
	string judgement1;
	StateBook book;
	User user;
	UserState userstate;
	System system;

	cout<<"是否清除原始数据进行初始化信息?(Y/N)";
	while(1)
	{
		getline(cin,judgement);
		if(judgement=="Y"||judgement=="y")
		{
				while(1)
				{
					cout<<"请输入管理员ID:";
					getline(cin,str);
					if(str.length()>20)
					{
						cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
					}
					else if(str.length()==0)
					{
						cout<<"输入为空，请重新输入"<<endl;
					}
					else
					{
						strcpy(user_id,str.c_str());
						break;
					}
				}
				while(1)
				{
					cout<<"请输入管理员密码:";
					getline(cin,str);
					if(str.length()>40)
					{
						cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
					}
					else if(str.length()==0)
					{
						cout<<"输入为空，请重新输入"<<endl;
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
					cout<<"管理员ID或密码错误,不进行重新载入"<<endl;
					break;
				}

		}
		else if(judgement=="N"||judgement=="n"){
		    cout << "是否进行手动输入？<Y/N>";
            getline(cin,judgement1);
            if(judgement1=="N"||judgement1=="n")
            {
                //cout << "建立图书管理系统失败！" << endl;
                break;
            }
            else if(judgement1=="Y"||judgement1=="y"){
                cout << "手动输入书本信息" << endl;
                string choice;
                while(true){
                    handInputBook();
                    cout << "是否继续手动添加书籍？(Y or N):";
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
		//图书管理系统主界面
		cout<<"-----------------欢迎进入图书管理系统-----------------"<<endl;
		cout<<"-------------------1.用户登录-------------------------"<<endl;
		cout<<"-------------------2.游客登录-------------------------"<<endl;
		cout<<"-------------------0.退出-----------------------------"<<endl;
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
			case 1://用户
				while(flag)
				{
					cout<<"-------------------用户登录界面-------------------"<<endl;
					cout<<"-------------------1.已有帐号登录-----------------"<<endl;
					cout<<"-------------------2.新用户注册登录---------------"<<endl;
					cout<<"-------------------0.退出-------------------------"<<endl;
					cout<<"please choose:";
					//cin>>choose;
					//choose=0;

					int choose2;
					string str2;
					choose2=88;
					getline(cin,str2);
					str2int(choose2,str2);//讲不同进制的字符串转化为整型,能转换的传回结果，不能转换的提示出现错误
					//cout<<choose2<<endl;
					switch(choose2)
					{
						case 88:
							cout<<"input error!"<<endl;
							break;
						case 1:
							while(1)
							{
								cout<<"请输入用户ID:";
								//cin>>user_id;
								getline(cin,str);
								if(str.length()>20)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
								}
								else
								{
									strcpy(user_id,str.c_str());
									break;
								}
							}
							while(1)
							{
								cout<<"请输入用户密码:";
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
								}
								else
								{
									strcpy(user_password,str.c_str());
									break;
								}
							}
							if(strcmp(user_id,"admin")==0&&strcmp(user_password,"admin")==0)//管理员
							{
								while(flag)
								{
									//管理员界面
									cout<<"------------------管理员界面---------------------"<<endl;
									cout<<"------------------1.书籍查询---------------------"<<endl;
									cout<<"------------------2.添加书籍---------------------"<<endl;
									cout<<"------------------3.删除书籍---------------------"<<endl;
									cout<<"------------------4.添加用户---------------------"<<endl;
									cout<<"------------------5.删除用户---------------------"<<endl;
									cout<<"------------------6.查看用户的历史借阅记录-------------"<<endl;
									cout<<"------------------7.查看用户的当前借阅信息-----------"<<endl;
									cout<<"------------------8.批量载入书籍------------------"<<endl;
									cout<<"------------------9.修改书籍信息-----------------"<<endl;
									cout<<"------------------10.修改用户信息-----------------"<<endl;
									cout<<"------------------11.显示所有的用户---------------"<<endl;
									cout<<"------------------12.显示所有的书籍--------------"<<endl;
									cout<<"------------------13.查看所有用户的历史借阅记录-----------"<<endl;
									cout<<"------------------14. 批量载入用户------------------------"<<endl;
									cout<<"------------------0.退出-------------------------"<<endl;
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
										case 1://书籍查询
											search_book(1);
											break;
										case 2://添加书籍
											while(1)//名称
											{
												cout<<"请输入书籍名称:";
												//cin>>book_name;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(book_name,str.c_str());
													break;
												}
											}
											while(1)//类型
											{
												cout<<"请输入书籍类型:";
												//cin>>book_kind;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(book_kind,str.c_str());
													break;
												}
											}
											while(1)//作者
											{
												cout<<"请输入书籍作者:";
												//cin>>book_author;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(book_author,str.c_str());
													break;
												}
											}
											while(1)//价格
											{
												cout<<"请输入书籍价格:";
												//cin>>book_price;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													book_price=atof(str.c_str());
													if(book_price>0)
														break;
													else
														cout<<"输入错误，请重新输入"<<endl;
												}
											}
											//实例化对象
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
											//添加一本书
											Manager::add_single_book(book);
											cout<<"success"<<endl;
											break;

										case 3://删除书籍
											while(1)
											{
												cout<<"请输入书籍的ID:";
												//cin>>book_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
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
												cout<<"该ID对应的书籍不存在！"<<endl;
											}
											else
											{
												if((bl=Manager::delete_single_book(book))==true)
													cout<<"success"<<endl;
												else
													cout<<"fail"<<endl;
											}
											break;
										case 4://添加用户
											while(1)
											{
												cout<<"请输入用户ID(仅限数字与字母组合，不区分大小写):";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											while(1)
											{
												cout<<"请输入用户姓名:";
												//cin>>user_name;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(user_name,str.c_str());
													break;
												}
											}
											while(1)
											{
												cout<<"请输入用户密码(仅限数字与字母组合，不区分大小写):";
												//cin>>user_password;
												getline(cin,str);
												if(str.length()>40)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(user_password,str.c_str());
													break;
												}
											}
											strcpy(user_id, strlwr(user_id));
											strcpy(user_password, strlwr(user_password)); //将用户名和密码全部改为小写
											//验证输入的合法性
											for (int i = 0; user_id[i] != '\0'; i++)
												{
													mark = 0;
													for (std::size_t j = 0; j < s.length(); j++)
													{
														if (s[j] == user_id[i])mark = 1;
													}
													if (mark == 0)
													{
														//cout << "输入id非法   " << endl;
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
													//cout << "输入密码非法" << endl;
													break;
												}
											}

											if (mark != 0&&mark2!=0)
											{
												//实例化对象
												user.setStudentId(user_id);
												user.setName(user_name);
												user.setPassword(user_password);
												if((bl=Manager:: add_user(user))==true)
													cout<<"success,添加用户成功"<<endl;
												else
													cout<<"fail，该id已存在，添加失败"<<endl;
											}
											else
												cout<<"fail,输入的用户id或密码非法"<<endl;
											break;

										case 5://删除用户
											while(1)
											{
												cout<<"请输入用户ID:";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
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
										case 6://查看用户历史借阅记录
											while(1)
											{
												cout<<"请输入用户ID:";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											Manager::getUserLog(user_id);
											break;
										case 7://查看用户的当前借阅信息
											while(1)
											{
												cout<<"请输入用户ID:";
												//cin>>user_id;
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											Manager::getUserRecord(user_id);
											break;
										case 8://批量载入书籍
											cout<<"请确认是否批量载入add_batch.txt中书籍（Y/N）:";
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
										case 9://修改书籍信息
											while(1)
											{
												cout<<"请输入书籍ID:";
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
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
												cout<<"该ID对应的书籍不存在！"<<endl;
											}
											else
											{
												if(book.getBorrowState()!=0)
												{
													cout<<"该书正在被借阅，无法修改书籍信息"<<endl;
												}
												else
												{
													while(1)
													{
														temp=0;
														cout<<"原书籍信息:"<<book.getBookId()<<"  "<<book.getBookName()<<"  "<<book.getKind()<<"  "<<book.getAuthor()<<"  "<<book.getPrice()<<endl;
														cout<<"请输入要修改的内容:"<<endl;
														cout<<"书籍名称:";
														getline(cin,str);
														if(str.length()>40)
														{
															cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
															continue;
														}
														strcpy(book_name,str.c_str());
														if(strcmp(book_name,"")!=0)
														{
															book.setBookName(book_name);
															temp=1;
														}
														cout<<"书籍类型:";
														getline(cin,str);
														if(str.length()>40)
														{
															cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
															continue;
														}
														strcpy(book_kind,str.c_str());
														if(strcmp(book_kind,"")!=0)
														{
															book.setKind(book_kind);
															temp=1;
														}
														cout<<"书籍作者:";
														getline(cin,str);
														if(str.length()>40)
														{
															cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
															continue;
														}
														strcpy(book_author,str.c_str());
														if(strcmp(book_author,"")!=0)
														{
															book.setAuthor(book_author);
															temp=1;
										cout << "开始查询" << endl;				}

														if(temp==0)
														{
															cout<<"输入均为空，未作修改"<<endl;
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
										case 10://修改用户信息
											while(1)
											{
												cout<<"请输入用户id:";
												getline(cin,str);
												if(str.length()>20)
												{
													cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
												}
												else if(str.length()==0)
												{
													cout<<"输入为空，请重新输入"<<endl;
												}
												else
												{
													strcpy(user_id,str.c_str());
													break;
												}
											}
											Manager::updateuser(user_id);
											break;
										case 11://显示所有用户
											Manager::showAllUserMsg();
											break;
										case 12://显示所有书籍
											Manager::showAllBookMsg();
											break;
										case 13://查看所有用户的历史借阅记录
											Manager::showLogMsg();
											break;
										case 14://批量载入用户
											cout<<"请确认是否批量载入add_user.txt中用户（Y/N）:";
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
							else                                                            //一般用户
							{
								userstate=system.user_login(user_id,user_password);
								if(strcmp(userstate.getUserId(),"-1")==0)
									cout<<"用户名或密码错误"<<endl;
								else
								{
									cout<<"success"<<endl;
									Manager::showNowRecord(userstate);
									while(flag)
									{
										//用户界面
										cout<<"------------------用户界面--------------------"<<endl;
										cout<<"------------------1.书籍查询------------------"<<endl;
										cout<<"------------------2.借书----------------------"<<endl;
										cout<<"------------------3.还书----------------------"<<endl;
										cout<<"------------------5.预约----------------------"<<endl;
										cout<<"------------------6.查询当前借阅信息----------"<<endl;
										cout<<"------------------0.退出----------------------"<<endl;
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
											case 1://查询书籍
												search_book(0);
												break;
											case 3://还书
												while(1)
												{
													cout<<"请输入借书的书籍ID:";
													//cin>>book_id;
													getline(cin,str);
													if(str.length()>20)
													{
														cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
													}
													else if(str.length()==0)
													{
														cout<<"输入为空，请重新输入"<<endl;
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
													cout<<"fail.未找到该书籍"<<endl;
												}
												else
													user.return_book(user_id,book);
												break;
											case 2://借书
												while(1)
												{
													cout<<"请输入借入书籍ID:";
													//cin>>book_id;
													getline(cin,str);
													if(str.length()>20)
													{
														cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
													}
													else if(str.length()==0)
													{
														cout<<"输入为空，请重新输入"<<endl;
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
													cout<<"fail.未找到该书籍"<<endl;
												}
												else
													user.renew_book(user_id,book);
												break;
											case 5://预约
												while(1)
												{
													cout<<"请输入预约的书籍ID:";
													//cin>>book_id;
													getline(cin,str);
													if(str.length()>20)
													{
														cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
													}
													else if(str.length()==0)
													{
														cout<<"输入为空，请重新输入"<<endl;
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
													cout<<"fail.未找到该书籍"<<endl;
												}
												else
													user.appoint_book(user_id,book);
												break;
											case 6://显示自己当前的借阅信息
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
						case 2://新注册
							while(1)
							{
								cout<<"请输入用户ID(仅限数字与字母组合，不区分大小写):";
								//cin>>user_id;
								getline(cin,str);
								if(str.length()>20)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
								}
								else
								{
									strcpy(user_id,str.c_str());
									break;
								}
							}
							while(1)
							{
								cout<<"请输入用户姓名:";
								//cin>>user_name;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
								}
								else
								{
									strcpy(user_name,str.c_str());
									break;
								}
							}
							while(1)
							{
								cout<<"请输入用户密码(仅限数字与字母组合，不区分大小写):";
								//cin>>user_password;
								getline(cin,str);
								if(str.length()>40)
								{
									cout<<"输入过长，请勿恶意操作，请重新输入"<<endl;
								}
								else if(str.length()==0)
								{
									cout<<"输入为空，请重新输入"<<endl;
								}
								else
								{
									strcpy(user_password,str.c_str());
									break;
								}
							}
							strcpy(user_id, strlwr(user_id));
							strcpy(user_password, strlwr(user_password)); //将用户名和密码全部改为小写
							//验证输入的合法性
							for (int i = 0; user_id[i] != '\0'; i++)
								{
									mark = 0;
									for (std::size_t j = 0; j < s.length(); j++)
									{
										if (s[j] == user_id[i])mark = 1;
									}
									if (mark == 0)
									{
										//cout << "输入id非法   " << endl;
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
									//cout << "输入密码非法" << endl;
									break;
								}
							}

							if (mark != 0&&mark2!=0)
							{
								//实例化对象
								user.setStudentId(user_id);
								user.setName(user_name);
								user.setPassword(user_password);
								if((bl=Manager:: add_user(user))==true)
									cout<<"success,添加用户成功"<<endl;
								else
									cout<<"fail，该id已存在，添加失败"<<endl;
							}
							else
								cout<<"fail,输入的用户id或密码非法"<<endl;
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
			case 2://游客登录
				while(flag)
				{
					//游客界面
					cout<<"------------------游客界面---------------------"<<endl;
					cout<<"------------------1.书籍查询-------------------"<<endl;
					cout<<"------------------0.退出-----------------------"<<endl;
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
						case 1://书籍查询
							search_book(0);
							break;
						case 0://退出
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

