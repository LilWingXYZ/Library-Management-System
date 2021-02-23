#include<iostream>
#include <fstream>
#include <iostream>
#include <string>
#include "user.h"
#include "class.h"


Date add_date(Date date)
{
	if(date.getMonth()==12)
	{
		date.setMonth(1);
		date.setYear(date.getYear()+1);
	}
	else
		date.setMonth(date.getMonth()+1);
	return date;
}
bool datecmp(Date date,Date deadlinetime)
{
	if(date.getYear()>deadlinetime.getYear())
		return false;
	if(date.getYear()<deadlinetime.getYear())
		return true;
	if(date.getMonth()>deadlinetime.getMonth())
		return false;
	if(date.getMonth()<deadlinetime.getMonth())
		return true;
	if(date.getDay()>deadlinetime.getDay())
		return false;
	if(date.getDay()<deadlinetime.getDay())
		return true;
	return true;
}
double beyond(Date date1,Date deadlinetime)
{
	double money;
	int n;
	n=date1.getYear()*365+date1.getMonth()*30+date1.getDay()-deadlinetime.getYear()*365-deadlinetime.getMonth()*30-deadlinetime.getDay();
	money=0.1*n;
	return money;
}

/*
//借书
判断条件：借阅状态==0;已借书籍数量是否小于10。book.dat中借阅状态，借阅人。borrow.dat中借阅数量，书籍。record.dat中加一个记录。
*/

void User:: borrow_book(char userId[20], StateBook book,int flag)
{
	Date starttime;
	Date date;
	FILE *fp1,*fp2,*fp3;//fp1->borrow.dat  ,fp2->book.dat  ,fp3->record.dat
	UserState userstate;
	int i=0,j;
	StateBook tempbook;
	Record record;
	fp1=fopen("borrow.dat","rb+");
	if(book.getBorrowState()==0)//若借阅状态为0
	{
		if(fp1)
		{
			i=0;
			while(!feof(fp1)) //控制循环找到userstate在文件borrow.dat中的位置
			{
				fread(&userstate,sizeof(UserState),1,fp1);
				if(strcmp(userstate.getUserId(),userId)==0)
				{
					break;
				}
				i++;
			}
		}
		fclose(fp1);
		if(userstate.getAccount()<10)//若已借书籍数量小于10，借书成功
		{
			if(flag == 1) {
				cout<<"success,借书成功"<<endl;
			}
			book.setBorrowState(1);//将借阅状态置为1
			book.setBorrowUserID(userId);//借阅人ID置为该用户ID
			book.setDeadlineTime(date);
			date=add_date(book.getDeadlineTime());//到期时间+1月
			book.setDeadlineTime(date);
			//borrow.dat
			userstate.setStateBooks(book,userstate.getAccount());//书籍加一本
			userstate.setAccount(userstate.getAccount()+1);//已借书籍数量+1
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//将修改后的userstate写回borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate, sizeof(UserState), 1, fp1);
			}
			fclose(fp1);

			//book.dat

			fp2=fopen("book.dat","rb+");
			if(fp2)
			{
				i=0;

				while(!feof(fp2))	//控制循环找到book在文件book.dat中的位置
				{
					fread(&tempbook,sizeof(StateBook),1,fp2);
					if(strcmp(tempbook.getBookId(),book.getBookId())==0)
					{
						break;
					}
					i++;
				}
			}
			fclose(fp2);
			fp2=fopen("book.dat","rb+");
			if(fp2)
			{
				//将修改后的book写回book.dat
				fseek(fp2, i*sizeof(StateBook), SEEK_SET);
				fwrite(&book,sizeof(book),1,fp2);
			}
			fclose(fp2);

			//record.dat,构造一条记录类的对象，追加存进record.dat
			record.setUserId(userId);
			record.setBookId(book.getBookId());
			record.setBorrowState(1);
			record.setStartTime(starttime);
			fp3=fopen("record.dat","ab");
			if(fp3)
			{
				fwrite(&record,sizeof(Record),1,fp3);
			}
			fclose(fp3);

		}
		else
			cout<<"fail,已达到10本的借书数量上限"<<userId<<endl;


	}
	else if(book.getBorrowState()==1)//若借阅状态为1
	{
		if(strcmp(userId,book.getBorrowUserID())==0)//可视为续借
		{
			Date date1;
			if(book.getAppointmentState()==0&&datecmp(date1,book.getDeadlineTime())==true)
			{
				cout<<"success,续借成功"<<endl;
				//borrow.dat   ,book.dat  ,record.dat
				//borrow.dat
				book.setBorrowState(2);//将借阅状态置为2
				date=add_date(book.getDeadlineTime());//到期时间+1月
				book.setDeadlineTime(date);
				fp1=fopen("borrow.dat","rb+");
				if(fp1)
				{
					i=0;
					while(!feof(fp1)) //控制循环找到userstate在文件borrow.dat中的位置
					{
						fread(&userstate,sizeof(UserState),1,fp1);
						if(strcmp(userstate.getUserId(),userId)==0)
						{
							break;
						}
						i++;
					}
				}
				fclose(fp1);
				for(j=0;j<userstate.getAccount();)//控制循环找到续借的是StateBooks序列中的哪本书
				{
					if(strcmp(userstate.getStateBooks()[j].getBookId(),book.getBookId())==0)
						break;
					j++;
				}
				userstate.setStateBooks(book,j);//将修改后的book置于序列中
				fp1=fopen("borrow.dat","rb+");
				if(fp1)
				{
					//将修改后的userstate写回borrow.dat
					fseek(fp1, i*sizeof(UserState), SEEK_SET);
					fwrite(&userstate, sizeof(UserState), 1, fp1);
				}
				fclose(fp1);

				//book.dat
				fp2=fopen("book.dat","rb+");
				if(fp2)
				{
					i=0;

					while(!feof(fp2))	//控制循环找到book在文件book.dat中的位置
					{
						fread(&tempbook,sizeof(StateBook),1,fp2);
						if(strcmp(tempbook.getBookId(),book.getBookId())==0)
						{
							break;
						}
						i++;
					}
				}
				fclose(fp2);
				fp2=fopen("book.dat","rb+");
				if(fp2)
				{
					//将修改后的book写回book.dat
					fseek(fp2, i*sizeof(StateBook), SEEK_SET);
					fwrite(&book,sizeof(book),1,fp2);
				}
				fclose(fp2);

				//record.dat
				//record.dat,构造一条记录类的对象，追加存进record.dat
				record.setUserId(userId);
				record.setBookId(book.getBookId());
				record.setBorrowState(2);
				Date date1;
				record.setStartTime(starttime);
				fp3=fopen("record.dat","ab");
				if(fp3)
				{
					fwrite(&record,sizeof(Record),1,fp3);
				}
				fclose(fp3);
			}
			if(book.getAppointmentState()!=0)
			{
				cout<<"fail,续借失败，该书已有人预约"<<endl;
			}
			if(book.getAppointmentState()==0&&datecmp(date1,book.getDeadlineTime())==false)
			{
				cout<<"fail,续借失败，已超过归还期限，请及时归还，并交罚金"<<endl;
			}
		}
		else
		{
			cout<<"fail,该书已被借阅"<<endl;
			if(book.getAppointmentState()==0)
			{
				string judgement;
				cout<<"是否进行预约(Y/N):";
				while(1)
				{
					//cin>>judgement;
					getline(cin,judgement);
					if(judgement=="Y")
					{

						User::appoint_book(userId,book);
						break;
					}
					else if(judgement=="N")
						break;
					else
						cout<<"input error,please input again:";
				}
			}

		}


	}
	else if(book.getBorrowState()==2)//若借阅状态为2
	{

		if(strcmp(userId,book.getBorrowUserID())==0)
		{
			cout<<"fail,已续借过，不能再次续借"<<endl;
		}
		else
			cout<<"fail,借阅失败"<<endl;
			if(book.getAppointmentState()==0)
				{
					string judgement;
					cout<<"是否进行预约(Y/N):";
					while(1)
					{
						//cin>>judgement;
						getline(cin,judgement);
						if(judgement=="Y")
						{

							User::appoint_book(userId,book);
							break;
						}
						else if(judgement=="N")
							break;
						else
							cout<<"input error,please input again:";
					}
				}

	}
}

void User::renew_book(char userId[20], StateBook book)
{
	User:: borrow_book(userId, book,1);
}

void User::appoint_book(char userId[20], StateBook book)
{
	//book.dat
	FILE *fp;
	int i;
	StateBook statebook;
	if(book.getBorrowState()==0)
	{
		cout<<"success,该书未被借阅，无需预约，即可借阅"<<endl;
		User:: borrow_book(userId, book,1);
	}
	else
	{
		if(book.getAppointmentState()==0)//若预约状态为0，预约成功
		{
			cout<<"success,预约成功"<<endl;
			book.setAppointmentState(1);//将预约状态置为1
			book.setAppointmentUserId(userId);//将预约人置为该用户
			fp=fopen("book.dat","rb+");
			if(fp)
			{
				i=0;
				while(!feof(fp))
				{
					fread(&statebook,sizeof(StateBook),1,fp);
					if(strcmp(statebook.getBookId(),book.getBookId())==0)
						break;
					i++;
				}
			}
			fclose(fp);
			fp=fopen("book.dat","rb+");
			if(fp)
			{
				fseek(fp, i*sizeof(StateBook), SEEK_SET);
				fwrite(&book,sizeof(book),1,fp);
			}
			fclose(fp);
		}
		else
			cout<<"false,该书已被预约，预约失败"<<endl;
	}
}

void User::return_book(char userId[20], StateBook book)
{
	Date starttime;
	Record record;
	Date date1;
	double money;
	FILE *fp1,*fp2,*fp3;
	int i,j,m;
	StateBook statebook;
	UserState userstate;
	if(strcmp(book.getBorrowUserID(),userId)==0)
	{
		if(datecmp(date1,book.getDeadlineTime())==true)
		{
			cout<<"success,按时还书成功"<<endl;
		}
		else
		{
			money=beyond(date1,book.getDeadlineTime());
			cout<<"success,还书成功,但需缴纳逾期罚金"<<money<<"元（逾期罚金按0.1/天计算）"<<endl;
		}
		if(book.getAppointmentState()==0)//若预约状态为0，还书成功
		{
			//修改borrow.dat中一条信息,book.dat，在record.dat中生成一条归还记录

			//borrow.dat
			book.setBorrowState(0);//将借阅状态置为0
			book.setBorrowUserID("-1");//将借阅人id置为-1
			book.setDeadlineTime(date1);//将deadlinetime置为当前时间
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				i=0;
				while(!feof(fp1))//控制循环找到userstate在borrow.dat中
				{
					fread(&userstate,sizeof(UserState),1,fp1);
					if(strcmp(userstate.getUserId(),userId)==0)
						break;
					i++;
				}
			}
			fclose(fp1);
			userstate.setAccount(userstate.getAccount()-1);//将该用户借阅书籍数量-1
			for(j=0;j<=userstate.getAccount();)
			{
				if(strcmp(userstate.getStateBooks()[j].getBookId(),book.getBookId())==0)
				{
					break;
				}
				j++;
			}
			m=userstate.getAccount();
			statebook.setBookId(userstate.getStateBooks()[m].getBookId());
			statebook.setBookName(userstate.getStateBooks()[m].getBookName() );
			statebook.setKind  (userstate.getStateBooks()[m].getKind() );
			statebook.setAuthor (userstate.getStateBooks()[m].getAuthor () );
			statebook.setPrice (userstate.getStateBooks()[m].getPrice () );
			statebook.setBorrowState (userstate.getStateBooks()[m].getBorrowState () );
			statebook.setBorrowUserID (userstate.getStateBooks()[m].getBorrowUserID () );
			statebook.setAppointmentState (userstate.getStateBooks()[m].getAppointmentState () );
			statebook.setAppointmentUserId (userstate.getStateBooks()[m].getAppointmentUserId () );
			statebook.setDeadlineTime (userstate.getStateBooks()[m].getDeadlineTime () );
			userstate.setStateBooks(statebook,j);//修改StateBooks,将最后一本书放到归还书籍的位置
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//将修改好的userstate放回borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate,sizeof(UserState),1,fp1);
			}
			fclose(fp1);

			//book.dat
			fp2=fopen("book.dat","rb+");
				if(fp2)
				{
					i=0;

					while(!feof(fp2))	//控制循环找到book在文件book.dat中的位置
					{
						fread(&statebook,sizeof(StateBook),1,fp2);
						if(strcmp(statebook.getBookId(),book.getBookId())==0)
						{
							break;
						}
						i++;
					}
				}
			fclose(fp2);
			fp2=fopen("book.dat","rb+");
			if(fp2)
			{
				//将修改后的book写回book.dat
				fseek(fp2, i*sizeof(StateBook), SEEK_SET);
				fwrite(&book,sizeof(book),1,fp2);
			}
			fclose(fp2);

			//record
			//record.dat,构造一条记录类的对象，追加存进record.dat
			record.setUserId(userId);
			record.setBookId(book.getBookId());
			record.setBorrowState(0);
			record.setStartTime(starttime);
			fp3=fopen("record.dat","ab+");
			if(fp3)
			{
				fwrite(&record,sizeof(Record),1,fp3);
			}
			fclose(fp3);
		}
		else//预约状态不为0，还书成功，并且将书借于预约人
		{
			//修改borrow.dat中两条信息,book.dat，在record.dat中生成一条归还记录，一条借阅记录
			char appid[20];
			cout<<"原预约人"<<book.getAppointmentUserId()<<"借书成功"<<endl;
			strcpy(appid,book.getAppointmentUserId());//记录原预约人id
			book.setBorrowUserID(book.getAppointmentUserId());//将借阅人id置为原预约人id
			book.setAppointmentState(0);//将预约状态置为0
			book.setAppointmentUserId("-1");//将预约人id置为-1
			book.setDeadlineTime(date1);

			//borrow.dat
			//修改原借阅人在borrow.dat中的信息
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				i=0;
				while(!feof(fp1))//控制循环找到userstate在borrow.dat中
				{
					fread(&userstate,sizeof(UserState),1,fp1);
					if(strcmp(userstate.getUserId(),userId)==0)
						break;
					i++;
				}
			}
			fclose(fp1);
			userstate.setAccount(userstate.getAccount()-1);//将该用户借阅书籍数量-1
			for(j=0;j<=userstate.getAccount();)
			{
				if(strcmp(userstate.getStateBooks()[j].getBookId(),book.getBookId())==0)
				{
					break;
				}
				j++;
			}
			statebook=userstate.getStateBooks()[userstate.getAccount()];
			userstate.setStateBooks(statebook,j);//修改StateBooks,将最后一本书放到归还书籍的位置
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//将修改好的userstate放回borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate,sizeof(UserState),1,fp1);
			}
			fclose(fp1);
			//修改原预约人在borrow.dat中的信息
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				i=0;
				while(!feof(fp1))//控制循环找到userstate在borrow.dat中
				{
					fread(&userstate,sizeof(UserState),1,fp1);
					if(strcmp(userstate.getUserId(),appid)==0)
						break;
					i++;
				}
			}
			fclose(fp1);
			userstate.setAccount(userstate.getAccount()+1);//将该用户借阅书籍数量+1
			userstate.setStateBooks(book,userstate.getAccount()-1);//将书籍放在Statebooks序列的后面
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//将修改好的userstate放回borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate,sizeof(UserState),1,fp1);
			}
			fclose(fp1);

			//book.dat
			fp2=fopen("book.dat","rb+");
				if(fp2)
				{
					i=0;

					while(!feof(fp2))	//控制循环找到book在文件book.dat中的位置
					{
						fread(&statebook,sizeof(StateBook),1,fp2);
						if(strcmp(statebook.getBookId(),book.getBookId())==0)
						{
							break;
						}
						i++;
					}
				}
			fclose(fp2);
			fp2=fopen("book.dat","rb+");
			if(fp2)
			{
				//将修改后的book写回book.dat
				fseek(fp2, i*sizeof(StateBook), SEEK_SET);
				fwrite(&book,sizeof(book),1,fp2);
			}
			fclose(fp2);

			//record.dat,构造一条记录类的对象，追加存进record.dat
			//原借阅人的还书记录
			record.setUserId(userId);
			record.setBookId(book.getBookId());
			record.setBorrowState(0);
			record.setStartTime(starttime);
			fp3=fopen("record.dat","ab");
			if(fp3)
			{
				fwrite(&record,sizeof(Record),1,fp3);
			}
			fclose(fp3);
			//原预约人的借书记录
			record.setUserId(appid);
			record.setBookId(book.getBookId());
			record.setBorrowState(1);
			record.setStartTime(starttime);
			fp3=fopen("record.dat","ab");
			if(fp3)
			{
				fwrite(&record,sizeof(Record),1,fp3);
			}
			fclose(fp3);

		}
	}
	else
	{
		cout<<"fail,未借阅该书籍，还书失败"<<endl;
	}
}

