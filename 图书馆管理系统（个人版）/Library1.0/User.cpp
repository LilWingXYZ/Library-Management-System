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
//����
�ж�����������״̬==0;�ѽ��鼮�����Ƿ�С��10��book.dat�н���״̬�������ˡ�borrow.dat�н����������鼮��record.dat�м�һ����¼��
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
	if(book.getBorrowState()==0)//������״̬Ϊ0
	{
		if(fp1)
		{
			i=0;
			while(!feof(fp1)) //����ѭ���ҵ�userstate���ļ�borrow.dat�е�λ��
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
		if(userstate.getAccount()<10)//���ѽ��鼮����С��10������ɹ�
		{
			if(flag == 1) {
				cout<<"success,����ɹ�"<<endl;
			}
			book.setBorrowState(1);//������״̬��Ϊ1
			book.setBorrowUserID(userId);//������ID��Ϊ���û�ID
			book.setDeadlineTime(date);
			date=add_date(book.getDeadlineTime());//����ʱ��+1��
			book.setDeadlineTime(date);
			//borrow.dat
			userstate.setStateBooks(book,userstate.getAccount());//�鼮��һ��
			userstate.setAccount(userstate.getAccount()+1);//�ѽ��鼮����+1
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//���޸ĺ��userstateд��borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate, sizeof(UserState), 1, fp1);
			}
			fclose(fp1);

			//book.dat

			fp2=fopen("book.dat","rb+");
			if(fp2)
			{
				i=0;

				while(!feof(fp2))	//����ѭ���ҵ�book���ļ�book.dat�е�λ��
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
				//���޸ĺ��bookд��book.dat
				fseek(fp2, i*sizeof(StateBook), SEEK_SET);
				fwrite(&book,sizeof(book),1,fp2);
			}
			fclose(fp2);

			//record.dat,����һ����¼��Ķ���׷�Ӵ��record.dat
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
			cout<<"fail,�Ѵﵽ10���Ľ�����������"<<userId<<endl;


	}
	else if(book.getBorrowState()==1)//������״̬Ϊ1
	{
		if(strcmp(userId,book.getBorrowUserID())==0)//����Ϊ����
		{
			Date date1;
			if(book.getAppointmentState()==0&&datecmp(date1,book.getDeadlineTime())==true)
			{
				cout<<"success,����ɹ�"<<endl;
				//borrow.dat   ,book.dat  ,record.dat
				//borrow.dat
				book.setBorrowState(2);//������״̬��Ϊ2
				date=add_date(book.getDeadlineTime());//����ʱ��+1��
				book.setDeadlineTime(date);
				fp1=fopen("borrow.dat","rb+");
				if(fp1)
				{
					i=0;
					while(!feof(fp1)) //����ѭ���ҵ�userstate���ļ�borrow.dat�е�λ��
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
				for(j=0;j<userstate.getAccount();)//����ѭ���ҵ��������StateBooks�����е��ı���
				{
					if(strcmp(userstate.getStateBooks()[j].getBookId(),book.getBookId())==0)
						break;
					j++;
				}
				userstate.setStateBooks(book,j);//���޸ĺ��book����������
				fp1=fopen("borrow.dat","rb+");
				if(fp1)
				{
					//���޸ĺ��userstateд��borrow.dat
					fseek(fp1, i*sizeof(UserState), SEEK_SET);
					fwrite(&userstate, sizeof(UserState), 1, fp1);
				}
				fclose(fp1);

				//book.dat
				fp2=fopen("book.dat","rb+");
				if(fp2)
				{
					i=0;

					while(!feof(fp2))	//����ѭ���ҵ�book���ļ�book.dat�е�λ��
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
					//���޸ĺ��bookд��book.dat
					fseek(fp2, i*sizeof(StateBook), SEEK_SET);
					fwrite(&book,sizeof(book),1,fp2);
				}
				fclose(fp2);

				//record.dat
				//record.dat,����һ����¼��Ķ���׷�Ӵ��record.dat
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
				cout<<"fail,����ʧ�ܣ�����������ԤԼ"<<endl;
			}
			if(book.getAppointmentState()==0&&datecmp(date1,book.getDeadlineTime())==false)
			{
				cout<<"fail,����ʧ�ܣ��ѳ����黹���ޣ��뼰ʱ�黹����������"<<endl;
			}
		}
		else
		{
			cout<<"fail,�����ѱ�����"<<endl;
			if(book.getAppointmentState()==0)
			{
				string judgement;
				cout<<"�Ƿ����ԤԼ(Y/N):";
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
	else if(book.getBorrowState()==2)//������״̬Ϊ2
	{

		if(strcmp(userId,book.getBorrowUserID())==0)
		{
			cout<<"fail,��������������ٴ�����"<<endl;
		}
		else
			cout<<"fail,����ʧ��"<<endl;
			if(book.getAppointmentState()==0)
				{
					string judgement;
					cout<<"�Ƿ����ԤԼ(Y/N):";
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
		cout<<"success,����δ�����ģ�����ԤԼ�����ɽ���"<<endl;
		User:: borrow_book(userId, book,1);
	}
	else
	{
		if(book.getAppointmentState()==0)//��ԤԼ״̬Ϊ0��ԤԼ�ɹ�
		{
			cout<<"success,ԤԼ�ɹ�"<<endl;
			book.setAppointmentState(1);//��ԤԼ״̬��Ϊ1
			book.setAppointmentUserId(userId);//��ԤԼ����Ϊ���û�
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
			cout<<"false,�����ѱ�ԤԼ��ԤԼʧ��"<<endl;
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
			cout<<"success,��ʱ����ɹ�"<<endl;
		}
		else
		{
			money=beyond(date1,book.getDeadlineTime());
			cout<<"success,����ɹ�,����������ڷ���"<<money<<"Ԫ�����ڷ���0.1/����㣩"<<endl;
		}
		if(book.getAppointmentState()==0)//��ԤԼ״̬Ϊ0������ɹ�
		{
			//�޸�borrow.dat��һ����Ϣ,book.dat����record.dat������һ���黹��¼

			//borrow.dat
			book.setBorrowState(0);//������״̬��Ϊ0
			book.setBorrowUserID("-1");//��������id��Ϊ-1
			book.setDeadlineTime(date1);//��deadlinetime��Ϊ��ǰʱ��
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				i=0;
				while(!feof(fp1))//����ѭ���ҵ�userstate��borrow.dat��
				{
					fread(&userstate,sizeof(UserState),1,fp1);
					if(strcmp(userstate.getUserId(),userId)==0)
						break;
					i++;
				}
			}
			fclose(fp1);
			userstate.setAccount(userstate.getAccount()-1);//�����û������鼮����-1
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
			userstate.setStateBooks(statebook,j);//�޸�StateBooks,�����һ����ŵ��黹�鼮��λ��
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//���޸ĺõ�userstate�Ż�borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate,sizeof(UserState),1,fp1);
			}
			fclose(fp1);

			//book.dat
			fp2=fopen("book.dat","rb+");
				if(fp2)
				{
					i=0;

					while(!feof(fp2))	//����ѭ���ҵ�book���ļ�book.dat�е�λ��
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
				//���޸ĺ��bookд��book.dat
				fseek(fp2, i*sizeof(StateBook), SEEK_SET);
				fwrite(&book,sizeof(book),1,fp2);
			}
			fclose(fp2);

			//record
			//record.dat,����һ����¼��Ķ���׷�Ӵ��record.dat
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
		else//ԤԼ״̬��Ϊ0������ɹ������ҽ������ԤԼ��
		{
			//�޸�borrow.dat��������Ϣ,book.dat����record.dat������һ���黹��¼��һ�����ļ�¼
			char appid[20];
			cout<<"ԭԤԼ��"<<book.getAppointmentUserId()<<"����ɹ�"<<endl;
			strcpy(appid,book.getAppointmentUserId());//��¼ԭԤԼ��id
			book.setBorrowUserID(book.getAppointmentUserId());//��������id��ΪԭԤԼ��id
			book.setAppointmentState(0);//��ԤԼ״̬��Ϊ0
			book.setAppointmentUserId("-1");//��ԤԼ��id��Ϊ-1
			book.setDeadlineTime(date1);

			//borrow.dat
			//�޸�ԭ��������borrow.dat�е���Ϣ
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				i=0;
				while(!feof(fp1))//����ѭ���ҵ�userstate��borrow.dat��
				{
					fread(&userstate,sizeof(UserState),1,fp1);
					if(strcmp(userstate.getUserId(),userId)==0)
						break;
					i++;
				}
			}
			fclose(fp1);
			userstate.setAccount(userstate.getAccount()-1);//�����û������鼮����-1
			for(j=0;j<=userstate.getAccount();)
			{
				if(strcmp(userstate.getStateBooks()[j].getBookId(),book.getBookId())==0)
				{
					break;
				}
				j++;
			}
			statebook=userstate.getStateBooks()[userstate.getAccount()];
			userstate.setStateBooks(statebook,j);//�޸�StateBooks,�����һ����ŵ��黹�鼮��λ��
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//���޸ĺõ�userstate�Ż�borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate,sizeof(UserState),1,fp1);
			}
			fclose(fp1);
			//�޸�ԭԤԼ����borrow.dat�е���Ϣ
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				i=0;
				while(!feof(fp1))//����ѭ���ҵ�userstate��borrow.dat��
				{
					fread(&userstate,sizeof(UserState),1,fp1);
					if(strcmp(userstate.getUserId(),appid)==0)
						break;
					i++;
				}
			}
			fclose(fp1);
			userstate.setAccount(userstate.getAccount()+1);//�����û������鼮����+1
			userstate.setStateBooks(book,userstate.getAccount()-1);//���鼮����Statebooks���еĺ���
			fp1=fopen("borrow.dat","rb+");
			if(fp1)
			{
				//���޸ĺõ�userstate�Ż�borrow.dat
				fseek(fp1, i*sizeof(UserState), SEEK_SET);
				fwrite(&userstate,sizeof(UserState),1,fp1);
			}
			fclose(fp1);

			//book.dat
			fp2=fopen("book.dat","rb+");
				if(fp2)
				{
					i=0;

					while(!feof(fp2))	//����ѭ���ҵ�book���ļ�book.dat�е�λ��
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
				//���޸ĺ��bookд��book.dat
				fseek(fp2, i*sizeof(StateBook), SEEK_SET);
				fwrite(&book,sizeof(book),1,fp2);
			}
			fclose(fp2);

			//record.dat,����һ����¼��Ķ���׷�Ӵ��record.dat
			//ԭ�����˵Ļ����¼
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
			//ԭԤԼ�˵Ľ����¼
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
		cout<<"fail,δ���ĸ��鼮������ʧ��"<<endl;
	}
}

