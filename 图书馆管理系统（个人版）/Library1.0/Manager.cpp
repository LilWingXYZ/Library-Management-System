#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "class.h"
#include "manager.h"
#include "user.h"
#include "system.h"
#include <time.h>
using namespace std;
//����Ա�µĺ���ʵ��

//ɾ���鼮��1����
bool Manager::delete_single_book(StateBook statebook) {
	//ɾ��book.dat�е���Ϣ
	if(statebook.getBorrowState() != 0) {
		cout<<"�����������ģ��޷�ɾ��"<<endl;
		return false;
	}
	FILE *fp;
	if (NULL == (fp = fopen("book.dat", "rb+"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}
	StateBook book;
	int i=0;
	bool isHaveUser = false;
	//����Ƿ����Ȿ��
	while(!feof(fp)) {
		fread(&book, sizeof(StateBook), 1, fp);
		if(strcmp(book.getBookId(), statebook.getBookId())==0){
			isHaveUser = true;
			break;
		}
		i++;
	}
	fclose(fp);
	//���Ȿ�飬�����������Ϊ-1��û���򷵻�false
	if(isHaveUser) {
		statebook.setBookId("-1");
		if (NULL == (fp = fopen("book.dat", "rb+"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(StateBook), SEEK_SET);
		fwrite(&statebook, sizeof(StateBook), 1, fp);
		fclose(fp);
		return true;
	} else {
		return false;
	}

};
//����鼮��1����
void Manager::add_single_book(StateBook statebook){
	FILE *fp;
	if (NULL == (fp = fopen("book.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		//exit(0);
	}
	StateBook StateBookTemp;
	int i=0;
	bool isHaveOldPotion = false;
	while(!feof(fp)) {
		fread(&StateBookTemp, sizeof(StateBook), 1, fp);
		if(strcmp(StateBookTemp.getBookId(), "-1")==0) {
			isHaveOldPotion = true;
			break;
		}
		i++;
	}
	fclose(fp);

	if(isHaveOldPotion) {//�п�λ�ò�����λ����û�������������һ��
		if (NULL == (fp = fopen("book.dat", "wb"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(StateBook), SEEK_SET);
		fwrite(&statebook, sizeof(StateBook), 1, fp);
	} else {
		if (NULL == (fp = fopen("book.dat", "ab"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fwrite(&statebook, sizeof(StateBook), 1, fp);
	}
	fclose(fp);
}
//����û�
bool Manager::add_user(User user){
	//����û���Ϣ������user.dat�ļ���
	FILE *fp;
	if (NULL == (fp = fopen("user.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}
	User userTest;
	int i=0;
	bool isHaveOldPotion = false;
	while(!feof(fp)) {
		fread(&userTest, sizeof(User), 1, fp);
		if(strcmp(userTest.getUserId(), user.getUserId())==0||strcmp(user.getUserId(),"admin")==0){
			return false;
		}
		if(strcmp(userTest.getUserId(), "-1")==0) {
			isHaveOldPotion = true;
			break;
		}
		i++;
	}
	fclose(fp);
	if(isHaveOldPotion) {//�п�λ�ò�����λ����û�������������һ��
		if (NULL == (fp = fopen("user.dat", "wb"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(User), SEEK_SET);
		fwrite(&user, sizeof(User), 1, fp);
	} else {
		if (NULL == (fp = fopen("user.dat", "ab"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fwrite(&user, sizeof(User), 1, fp);
	}
	fclose(fp);

	//�����û�������Ϣ������borrow.dat��

	if (NULL == (fp = fopen("borrow.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}
	UserState userState,userDemo;
	StateBook books[10];
	userState.setUserId(user.getUserId());
	userState.setAccount(0);
	for(int j=0;j<10;j++)
		userState.setStateBooks(books[j],j);
	i=0;
	isHaveOldPotion = false;
	while(!feof(fp)) {
		fread(&userDemo, sizeof(UserState), 1, fp);
		if(strcmp(userDemo.getUserId(), "-1")==0) {
			isHaveOldPotion = true;
			break;
		}
		i++;
	}
	fclose(fp);
	if(isHaveOldPotion) {//�п�λ�ò�����λ����û�������������һ��
		if (NULL == (fp = fopen("borrow.dat", "wb"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(UserState), SEEK_SET);
		fwrite(&userState, sizeof(UserState), 1, fp);
	} else {
		if (NULL == (fp = fopen("borrow.dat", "ab"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fwrite(&userState, sizeof(UserState), 1, fp);
	}
	fclose(fp);

	return true;
}
//ɾ���û�
bool Manager::delete_user(char id[20]) {
	FILE *fp;
	//ɾ��borrow.dat�е���Ϣ
	if (NULL == (fp = fopen("borrow.dat", "rb+"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}
	UserState userState;
	int i=0;
	bool isHaveUser = false;
	//����Ƿ��и��û�
	while(!feof(fp)) {
		fread(&userState, sizeof(UserState), 1, fp);
		if(strcmp(userState.getUserId(), id)==0){
			isHaveUser = true;
			break;
		}
		i++;
	}
	fclose(fp);
	//�и��û���������ѧ����Ϊ-1��û���򷵻�false
	if(isHaveUser) {
		if(userState.getAccount() > 0) {
			cout<<"��ǰ�û����н����¼���޷�ɾ����"<<endl;
			return false;
		}
		userState.setUserId("-1");
		if (NULL == (fp = fopen("borrow.dat", "rb+"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(UserState), SEEK_SET);
		fwrite(&userState, sizeof(UserState), 1, fp);
		fclose(fp);
	} else {
		cout<<"δ�鵽idΪ"<<id<<"�û�"<<endl;
		return false;
	}

	//ɾ��user�е���Ϣ

	if (NULL == (fp = fopen("user.dat", "rb+"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}
	User userTest;
	i=0;
	isHaveUser = false;
	//����Ƿ��и��û�
	while(!feof(fp)) {
		fread(&userTest, sizeof(User), 1, fp);
		if(strcmp(userTest.getUserId(), id)==0){
			isHaveUser = true;
			break;
		}
		i++;
	}
	fclose(fp);
	//�и��û���������ѧ����Ϊ-1��û���򷵻�false
	if(isHaveUser) {

		userTest.setStudentId("-1");
		if (NULL == (fp = fopen("user.dat", "rb+"))){
			cout << "��ȡ�ļ�����" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(User), SEEK_SET);
		fwrite(&userTest, sizeof(User), 1, fp);
		fclose(fp);
	} else {
		return false;
	}
	return true;
}

//ϵͳ��Ϣ����
void Manager::initSystem() {
	FILE *fp1,*fp2,*fp3,*fp4;
	fp1=fopen("book.dat","w");
	fp2=fopen("user.dat","w");
	fp3=fopen("borrow.dat","w");
	fp4=fopen("record.dat","w");
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	initBook("book_original.txt");
	initUser("user.txt");
}
//��ʼ���鼮
void Manager::initBook(const char *fileName) {
		StateBook book;
		FILE * fp;
		char bookName[40];
		char bookKind[40];
		char bookAuthor[40];
		char bookPrice[20];
		double price;
		char str[20] ;
		fp=fopen(fileName, "rb");
		if(NULL ==fp) {
			printf("open file error\n");
			return;
			//exit(0);
		}
		while(!feof(fp)) {
			//���ļ���ȡ������
			fscanf(fp,"%[^;]%*c",bookName);
			fscanf(fp,"%[^;]%*c",bookKind);
			fscanf(fp,"%[^;]%*c",bookAuthor);
			fscanf(fp,"%[^\n]%*f",bookPrice);


			 price = atof(bookPrice);//��ü۸�

			 Date date;//�õ���ǰ����

			 getId(str);//�õ�Id
			 //ʵ��������
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

			 //�����鼮��ӵ��ļ�
			Manager::add_single_book(book);
		}
		fclose(fp);
		cout<<"�����鼮�ɹ�"<<endl;

}
//��ʼ���û�
void Manager::initUser(const char *fileName) {
	User user;
	FILE * fp;
	char userId[20];
	char name[40];
	char password[40];
	fp=fopen(fileName, "r");
	if(NULL == fp ) {
		printf("open file error");
		return;
		//exit(0);
	}

	while(!feof(fp)) {
		//���ļ���ȡ������
		fscanf(fp,"%[^;]%*c",userId);
		fscanf(fp,"%[^;]%*c",name);
		fscanf(fp,"%[^\n]%*c",password);
		//ʵ��������
		user.setStudentId(userId);
		user.setName(name);
		user.setPassword(password);

		//�����û���ӵ��ļ�
		Manager::add_user(user);
	}
	fclose(fp);
	cout<<"�����û��ɹ�"<<endl;
}
//��ȡ�鼮ID
void Manager::getId(char string[20]) {
	int BOOKIDNUM = 0;//�õ�Id��ţ���������
	FILE * fp;
	char msg[20];//�����ļ��ַ���
	if(NULL == (fp=fopen("Id.txt", "r"))) {
			printf("open file error");
			exit(0);
	}
	if(fgets((char*)msg,20,fp)) {
		BOOKIDNUM =  atoi(msg);//ת��int��
	}

	itoa(BOOKIDNUM++,(char *)string,10);//����һ��Id
	//printf("string_id %s \n", string);
	fclose(fp);
	if(NULL == (fp=fopen("Id.txt", "w"))) {
			printf("open file error");
			exit(0);
	}
    //printf("BOOKIDNUM:%d\n", BOOKIDNUM);
	fprintf(fp,"%d\n",BOOKIDNUM);//����Id
	fclose(fp);
}

void Manager::manager_single_show(int flag)//����Ա��flag=1
{
    cout << "��ʼչʾ" << endl;
	FILE *fp;
	StateBook statebook;
	StateBook statebook2;

	statebook.setBookId("not exist");
	statebook.setBookName("-1");
	statebook.setKind("-1");
	statebook.setAuthor("-1");
	statebook.setPrice(-1);
	statebook.setBorrowState(-1);
	statebook.setBorrowUserID("-1");
	statebook.setAppointmentState(-1);
	statebook.setAppointmentUserId("-1");

	if(NULL==(fp=fopen("search_single.dat","rb")))//�ļ�������
	{
		cout<<"�ļ�������...."<<endl;
		return;
	}
    while(!feof(fp))
    {
        fread(&statebook, sizeof(StateBook), 1, fp);
        if(strcmp(statebook.getBookId(),statebook2.getBookId()) == 0) {
            break;
        }
        cout << endl;
        cout<<"ID:" << statebook.getBookId()<<"  ";
        if(strcmp(statebook.getBookId(),"not exist") == 0) {
            cout<<endl;
            break;
        }
        cout<< "����:" << statebook.getBookName()<<" "<<endl;
        cout<<"����:" << statebook.getKind()<<"  ";
        cout<<"����:" << statebook.getAuthor()<<"  ";
        cout<<"�۸�:" << statebook.getPrice()<<"  "<<endl;
        cout<<"����״̬:";
        if(statebook.getBorrowState()==0)
            cout << "��" << ";"<<endl;
        else
            cout << "�ѱ�����"<<";" << endl;
        if(flag==1){
            cout<<"������ID:" ;
            if(strcmp(statebook.getBorrowUserID(), "-1") == 0)//statebook.getBorrowUserID()=="-1"
                cout << "��" << ";"<<endl;
            else
                cout << statebook.getBorrowUserID()<<";"<<endl;
        }
        cout<<"ԤԼ��״̬:" ;
        if(statebook.getAppointmentState()==0)
            cout << "��" << ";"<<endl;
        else
            cout << statebook.getAppointmentState()<<";";
        if(flag==1)
        {
            cout<<"ԤԼ��ID:" ;
            if(strcmp(statebook.getAppointmentUserId(), "-1") == 0)//statebook.getAppointmentUserId()=="-1"
                cout << "��" << ";"<<endl;
            else
                cout << statebook.getAppointmentUserId()<<";"<<endl;
        }
        if(flag==1)
        {cout << "��ֹ����:";
            cout<<(statebook.getDeadlineTime()).getYear()<<"-";
            cout<<(statebook.getDeadlineTime()).getMonth()<<"-";
            cout<<(statebook.getDeadlineTime()).getDay()<< ";";
        }
        cout<<endl;
        statebook2 = statebook;
    }
	fclose(fp);
}

void Manager::manager_union_show(int flag)
{
	FILE *fp;
	StateBook statebook;
	StateBook statebook2;
	if(NULL==(fp=fopen("search_union.dat","rb")))//�ļ�������
	{
		cout<<"�ļ�������...."<<endl;
		return;
	}
	while(!feof(fp))
		{
			fread(&statebook, sizeof(StateBook), 1, fp);
			if(strcmp(statebook.getBookId(),statebook2.getBookId()) == 0)
			{
				break;
			}
			cout<<statebook.getBookId()<<"  ";
			if(strcmp(statebook.getBookId(),"not exist") == 0) {
				cout<<endl;
				break;
			}
			cout<<statebook.getBookName()<<"  ";
			cout<<statebook.getKind()<<"  ";
			cout<<statebook.getAuthor()<<"  ";
			cout<<statebook.getPrice()<<"  ";
			cout<<statebook.getBorrowState()<<"  ";
			if(flag==1)
				cout<<statebook.getBorrowUserID()<<"  ";
			cout<<statebook.getAppointmentState()<<"  ";
			if(flag==1)
				cout<<statebook.getAppointmentUserId()<<"  ";
			if(flag==1)
			{
				cout<<(statebook.getDeadlineTime()).getYear()<<"-";
				cout<<(statebook.getDeadlineTime()).getMonth()<<"-";
				cout<<(statebook.getDeadlineTime()).getDay();
			}
			cout<<endl;
			statebook2 = statebook;
		}
	fclose(fp);
}

//��ʾ�û��Ĳ�����¼
void showOldRecord(Record userRecord) {

	cout<<"�û�Id: "<<userRecord.getUserId()<<"   �鼮Id: "<<userRecord.getBookId()<<"   ��������: ";
	if(userRecord.getBorrowState() == 0) {
		cout<<"�黹";
	} else if(userRecord.getBorrowState() == 1) {
		cout<<"����";
	} else if(userRecord.getBorrowState() == 2) {
		cout<<"����";
	}
	cout<<"   ��������ʱ��: "<<userRecord.getStartTime().getYear()<<"-"<<userRecord.getStartTime().getMonth()<<"-"<<userRecord.getStartTime().getDay()<<endl;

}

//չʾ�û���ǰ������Ϣ
void Manager::showNowRecord(UserState user) {
	cout<<"�û�id:"<<user.getUserId()<<endl;
	cout<<"��ǰ����������"<<user.getAccount()<<endl;
	cout<<"�鼮��Ϣ��"<<endl;
	for(int i=0;i<user.getAccount(); i++) {
		cout<<"�鼮ID��"<<user.getStateBooks()[i].getBookId()<<"  ����:"<<user.getStateBooks()[i].getBookName()<<"  ����״̬:";
		if (user.getStateBooks()[i].getBorrowState()==1)
            cout << "�ѽ���";
            cout << "  ��ֹʱ��:"<<user.getStateBooks()[i].getDeadlineTime().getYear()<<"-"<<user.getStateBooks()[i].getDeadlineTime().getMonth()<<"-"<<user.getStateBooks()[i].getDeadlineTime().getDay()<<endl;
	}
}

//��ȡ�û���ǰ������Ϣ
void Manager::getUserRecord(char id[20]) {
	FILE *fp;
	bool isHaveUser=true;
	if (NULL == (fp = fopen("borrow.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		return;
	}
	UserState userState;
	while(!feof(fp)) {
		fread(&userState, sizeof(UserState), 1, fp);
		if(strcmp(userState.getUserId(), id)==0){
			showNowRecord(userState);
			isHaveUser = false;
			break;
		}
	}
	fclose(fp);
	if(!isHaveUser) {
		return;
	} else {
		cout<<"δ�鵽���û�"<<endl;
		return;
	}
}

//�õ��û��Ĳ�����־
void Manager::getUserLog(char id[20]) {
	FILE *fp;
	char tempstr[20]={""};
	int temp=-1;
	bool isHaveUser=true;
	if (NULL == (fp = fopen("record.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		return;
	}
	Record userRecord;
	while(!feof(fp)) {
		fread(&userRecord, sizeof(Record), 1, fp);
		if(strcmp(userRecord.getUserId(), id)==0){
			if(strcmp(userRecord.getBookId(),tempstr)!=0||userRecord.getBorrowState()!=temp)
				showOldRecord(userRecord);
			isHaveUser = false;
			strcpy(tempstr,userRecord.getBookId());
			temp=userRecord.getBorrowState();
		}
	}
	fclose(fp);
	if(!isHaveUser) {
		return;
	} else {
		cout<<"δ�鵽���û���һ������¼"<<endl;
		return;
	}
}

//���Ϊ20���û���5~7����
/*
void Manager::random() {
	FILE * fp;
	User userManager;
	UserState user2;
	//bool isJump = false;
	if(NULL == (fp=fopen("borrow.dat","rb+"))) {
		cout<<"open file error!";
		return;
	}
	UserState user;
	StateBook book;
	int i=0;
	int num ;
	while(!feof(fp)) {
		num=0;
		fread(&user,sizeof(UserState),1,fp);
		if(strcmp(user.getUserId(),"-1") == 0) {
			continue;
		}

		if(user.getAccount() >= 10) {
			continue;
		} else if(user.getAccount() >= 3) {
			num = 10 - user.getAccount();
		}  else {
			num = rand()%3+5;   //����5~7֮�������
		}
		i++;
		if(i > 20) {  //����ʮ���û�����
			break;
		}
		if(strcmp(user.getUserId(),user2.getUserId()) == 0) {
			break;
		}
		//cout<<num<<endl;
		for(int j=0; j<num; j++) {
			//����
			book = Manager::randomGetBook(0);
			userManager.borrow_book(user.getUserId(), book,0);
		}
		user2 = user;
	}
	if(i == 21) {
		cout<<"һ������������������ɹ�"<<endl;
	}
	else if(i<21) {
		cout<<"�Ѹ�"<<i-1<<"λ�û�����ɹ�"<<endl;
	} else {
		cout<<"�����û������������ﵽ����"<<endl;
	}
}

*/

StateBook Manager::randomGetBook(int flag) { //flag����1��ͷѰ��
	FILE *fp;
	StateBook book;
	int num;
	if(flag != 1) {
		num = rand()%1000;   //����0~1000�������
	} else {
		num = 0;
	}
	book.setBookId("-1");

	if (NULL == (fp = fopen("book.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}

	while(!feof(fp)) {
		fseek(fp, num*sizeof(StateBook), SEEK_SET);
		fread(&book, sizeof(StateBook), 1, fp);
		if(strcmp(book.getBookId(),"-1") == 0 ) {
			num++;
			continue;
		}
		if(book.getBorrowState() == 0) {
			fclose(fp);
			return book;
		}
		num++;
	}

	if(flag == 1) {
		return book;
	} else {
		return randomGetBook(1);
	}

}

void Manager::updatebook(StateBook book)
{
	FILE *fp;
	int i;
	StateBook statebook;
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
		fwrite(&book,sizeof(StateBook),1,fp);
		cout<<"�޸��鼮��Ϣ�ɹ�����ǰ���鼮��ϢΪ:"<<book.getBookId()<<"  "<<book.getBookName()<<"  "<<book.getKind()<<"  "<<book.getAuthor()<<"  "<<book.getPrice()<<endl;
	}
	fclose(fp);


}
void Manager::updateuser(char user_id[20])
{
	char user_name[40],user_password[40];
	string str;
	User user;
	int i;
	int temp=0;
	FILE *fp;
	if((fp=fopen("user.dat","rb+")))
	{
		i=0;
		while(!feof(fp))
		{
			fread(&user,sizeof(User),1,fp);
			if(strcmp(user.getUserId(),user_id)==0)
			{
				temp=1;
				break;
			}
			i++;
		}
	}
	fclose(fp);
	if(temp==1)
	{
		cout<<"���û�ԭ��ϢΪ: ѧ��:"<<user.getUserId()<<"  ����:"<<user.getName()<<"  ����:"<<user.getPassword()<<endl;
		cout<<"������Ҫ�޸ĵ���Ϣ:"<<endl;
		while(1)
		{
			cout<<"����:";
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
				user.setName(user_name);
				break;
			}
		}
		while(1)
		{
			cout<<"����:";
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
				user.setPassword(user_password);
				break;
			}
		}
		if((fp=fopen("user.dat","rb+")))
		{
			fseek(fp, i*sizeof(User), SEEK_SET);
			fwrite(&user,sizeof(User),1,fp);
			cout<<"success,�޸ĳɹ�"<<endl;
			cout<<"���û���ǰ��ϢΪ: ѧ��:"<<user.getUserId()<<"  ����:"<<user.getName()<<"  ����:"<<user.getPassword()<<endl;
		}
		fclose(fp);
	}
	else
	{
		cout<<"fail,��id������"<<endl;
	}

}



//12�û���13�鼮��14�����ʾ��15��ʾ���е���ˮ��Ϣ

//��ʾ�����鼮��Ϣ
void Manager::showAllBookMsg() {
	FILE *fp;
	StateBook book;
	StateBook book2;
	int num = 0;

	if (NULL == (fp = fopen("book.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}

	while(!feof(fp)) {
		fread(&book, sizeof(StateBook), 1, fp);
		if(strcmp(book.getBookId(),"-1") == 0 ) {
			num++;
			continue;
		}
		if(strcmp(book.getBookId(), book2.getBookId()) == 0) {
			cout<<"�ݲ�"<<num<<"����"<<endl;
			break;
		}
		cout<<book.getBookId()<<"  ";
		cout<<book.getBookName()<<"  ";
		cout<<book.getKind()<<"  ";
		cout<<book.getAuthor()<<"  ";
		cout<<book.getPrice()<<"  ";
		if(book.getBorrowState() == 0){
            //cout<<book.getBorrowState()<<"  ";
            cout << "û�б�����" << "  ";
		}
		else if(book.getBorrowState() == 1)
        {
            cout << "�ѱ�����" << "  ";
        }
		if(strcmp(book.getBorrowUserID(), "-1") == 0)
		{
		    //cout<<book.getBorrowUserID()<<"  ";
		    cout << "��" << "  ";
		}
		if(book.getAppointmentState() == 0)
        {
            //cout<<book.getAppointmentState()<<"  ";
            cout << "û�б�ԤԼ" << "  ";
        }
        else if(book.getAppointmentState() == 1)
        {
            cout << "�ѱ�ԤԼ" << "  ";
        }

		if(strcmp(book.getAppointmentUserId(), "-1"))
        {
            //cout<<book.getAppointmentUserId()<<"  ";
            cout << "��" << "  ";
        }

		cout<<(book.getDeadlineTime()).getYear()<<"-";
		cout<<(book.getDeadlineTime()).getMonth()<<"-";
		cout<<(book.getDeadlineTime()).getDay();
		cout<<endl;
		num++;
		book2 = book;
	}
	fclose(fp);
}

//��ʾ�����û���Ϣ
void Manager::showAllUserMsg() {
	FILE *fp;
	User user;
	User user2;
	int num = 0;
	if(NULL == (fp = fopen("user.dat", "rb+"))){
		cout << "��ȡ�ļ�����" << endl;
		exit(0);
	}
	while(!feof(fp)) {
		fread(&user, sizeof(User), 1, fp);
		if(strcmp(user.getUserId(), "-1")==0){
			continue;
		}
		if(strcmp(user.getUserId(), user2.getUserId()) == 0) {
			cout<<"����"<<num<<"λ�û�"<<endl;
			break;
		}
		cout<<user.getUserId()<<"   "<<user.getName()<<endl;
		user2 = user;
		num++;
	}
	fclose(fp);
}

//�����ʾʮ���鼮��Ϣ
void Manager::showTenBookMsg() {
	//FILE *fp;
	StateBook book;
	for(int i=0;i<10;i++) {
		book = randomGetBook(0);
		cout<<book.getBookId()<<"  ";
		cout<<book.getBookName()<<"  ";
		cout<<book.getKind()<<"  ";
		cout<<book.getAuthor()<<"  ";
		cout<<book.getPrice()<<"  ";
		if(book.getBorrowState() == 0) {
			cout<<"δ���  ";
		} else if(book.getBorrowState() == 1) {
			cout<<"������  ";
			cout<<book.getBorrowUserID()<<"  ";
		} else if(book.getBorrowState() == 2) {
			cout<<"������  ";
			cout<<book.getBorrowUserID()<<"  ";
		}
		if(book.getAppointmentState() == 0) {
			cout<<"δԤԼ  ";
		} else if(book.getAppointmentState() == 1) {
			cout<<"ԤԼ��  ";
			cout<<book.getAppointmentUserId()<<"  ";
		}
		cout<<(book.getDeadlineTime()).getYear()<<"-";
		cout<<(book.getDeadlineTime()).getMonth()<<"-";
		cout<<(book.getDeadlineTime()).getDay();
		cout<<endl;
	}
}

//��ʾ���е���־��Ϣ
void Manager::showLogMsg() {
	FILE *fp;
	char tempstr[20]={""};
	int temp=-1;
	//bool isHaveUser=true;
	if (NULL == (fp = fopen("record.dat", "rb"))){
		cout << "��ȡ�ļ�����" << endl;
		return;
	}
	Record userRecord;
	while(!feof(fp)) {
		fread(&userRecord, sizeof(Record), 1, fp);
		if(strcmp(userRecord.getBookId(),tempstr)!=0||userRecord.getBorrowState()!=temp)
			showOldRecord(userRecord);
		//isHaveUser = false;
		strcpy(tempstr,userRecord.getBookId());
		temp=userRecord.getBorrowState();
	}
	fclose(fp);
}
