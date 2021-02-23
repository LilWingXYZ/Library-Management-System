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
//管理员下的函数实现

//删除书籍（1本）
bool Manager::delete_single_book(StateBook statebook) {
	//删除book.dat中的信息
	if(statebook.getBorrowState() != 0) {
		cout<<"该书正被借阅，无法删除"<<endl;
		return false;
	}
	FILE *fp;
	if (NULL == (fp = fopen("book.dat", "rb+"))){
		cout << "读取文件出错！" << endl;
		exit(0);
	}
	StateBook book;
	int i=0;
	bool isHaveUser = false;
	//检查是否有这本书
	while(!feof(fp)) {
		fread(&book, sizeof(StateBook), 1, fp);
		if(strcmp(book.getBookId(), statebook.getBookId())==0){
			isHaveUser = true;
			break;
		}
		i++;
	}
	fclose(fp);
	//有这本书，则将他的书号置为-1，没有则返回false
	if(isHaveUser) {
		statebook.setBookId("-1");
		if (NULL == (fp = fopen("book.dat", "rb+"))){
			cout << "读取文件出错！" << endl;
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
//添加书籍（1本）
void Manager::add_single_book(StateBook statebook){
	FILE *fp;
	if (NULL == (fp = fopen("book.dat", "rb"))){
		cout << "读取文件出错！" << endl;
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

	if(isHaveOldPotion) {//有空位置补到空位置上没有则在最后增加一条
		if (NULL == (fp = fopen("book.dat", "wb"))){
			cout << "读取文件出错！" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(StateBook), SEEK_SET);
		fwrite(&statebook, sizeof(StateBook), 1, fp);
	} else {
		if (NULL == (fp = fopen("book.dat", "ab"))){
			cout << "读取文件出错！" << endl;
			exit(0);
		}
		fwrite(&statebook, sizeof(StateBook), 1, fp);
	}
	fclose(fp);
}
//添加用户
bool Manager::add_user(User user){
	//添加用户信息，存于user.dat文件中
	FILE *fp;
	if (NULL == (fp = fopen("user.dat", "rb"))){
		cout << "读取文件出错！" << endl;
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
	if(isHaveOldPotion) {//有空位置补到空位置上没有则在最后增加一条
		if (NULL == (fp = fopen("user.dat", "wb"))){
			cout << "读取文件出错！" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(User), SEEK_SET);
		fwrite(&user, sizeof(User), 1, fp);
	} else {
		if (NULL == (fp = fopen("user.dat", "ab"))){
			cout << "读取文件出错！" << endl;
			exit(0);
		}
		fwrite(&user, sizeof(User), 1, fp);
	}
	fclose(fp);

	//增加用户借阅信息，存于borrow.dat中

	if (NULL == (fp = fopen("borrow.dat", "rb"))){
		cout << "读取文件出错！" << endl;
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
	if(isHaveOldPotion) {//有空位置补到空位置上没有则在最后增加一条
		if (NULL == (fp = fopen("borrow.dat", "wb"))){
			cout << "读取文件出错！" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(UserState), SEEK_SET);
		fwrite(&userState, sizeof(UserState), 1, fp);
	} else {
		if (NULL == (fp = fopen("borrow.dat", "ab"))){
			cout << "读取文件出错！" << endl;
			exit(0);
		}
		fwrite(&userState, sizeof(UserState), 1, fp);
	}
	fclose(fp);

	return true;
}
//删除用户
bool Manager::delete_user(char id[20]) {
	FILE *fp;
	//删除borrow.dat中的信息
	if (NULL == (fp = fopen("borrow.dat", "rb+"))){
		cout << "读取文件出错！" << endl;
		exit(0);
	}
	UserState userState;
	int i=0;
	bool isHaveUser = false;
	//检查是否有该用户
	while(!feof(fp)) {
		fread(&userState, sizeof(UserState), 1, fp);
		if(strcmp(userState.getUserId(), id)==0){
			isHaveUser = true;
			break;
		}
		i++;
	}
	fclose(fp);
	//有该用户，则将他的学号置为-1，没有则返回false
	if(isHaveUser) {
		if(userState.getAccount() > 0) {
			cout<<"当前用户仍有借书记录，无法删除。"<<endl;
			return false;
		}
		userState.setUserId("-1");
		if (NULL == (fp = fopen("borrow.dat", "rb+"))){
			cout << "读取文件出错！" << endl;
			exit(0);
		}
		fseek(fp, i*sizeof(UserState), SEEK_SET);
		fwrite(&userState, sizeof(UserState), 1, fp);
		fclose(fp);
	} else {
		cout<<"未查到id为"<<id<<"用户"<<endl;
		return false;
	}

	//删除user中的信息

	if (NULL == (fp = fopen("user.dat", "rb+"))){
		cout << "读取文件出错！" << endl;
		exit(0);
	}
	User userTest;
	i=0;
	isHaveUser = false;
	//检查是否有该用户
	while(!feof(fp)) {
		fread(&userTest, sizeof(User), 1, fp);
		if(strcmp(userTest.getUserId(), id)==0){
			isHaveUser = true;
			break;
		}
		i++;
	}
	fclose(fp);
	//有该用户，则将他的学号置为-1，没有则返回false
	if(isHaveUser) {

		userTest.setStudentId("-1");
		if (NULL == (fp = fopen("user.dat", "rb+"))){
			cout << "读取文件出错！" << endl;
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

//系统信息载入
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
//初始化书籍
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
			//从文件中取出内容
			fscanf(fp,"%[^;]%*c",bookName);
			fscanf(fp,"%[^;]%*c",bookKind);
			fscanf(fp,"%[^;]%*c",bookAuthor);
			fscanf(fp,"%[^\n]%*f",bookPrice);


			 price = atof(bookPrice);//获得价格

			 Date date;//得到当前日期

			 getId(str);//得到Id
			 //实例化对象
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

			 //将该书籍添加到文件
			Manager::add_single_book(book);
		}
		fclose(fp);
		cout<<"载入书籍成功"<<endl;

}
//初始化用户
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
		//从文件中取出内容
		fscanf(fp,"%[^;]%*c",userId);
		fscanf(fp,"%[^;]%*c",name);
		fscanf(fp,"%[^\n]%*c",password);
		//实例化对象
		user.setStudentId(userId);
		user.setName(name);
		user.setPassword(password);

		//将该用户添加到文件
		Manager::add_user(user);
	}
	fclose(fp);
	cout<<"载入用户成功"<<endl;
}
//获取书籍ID
void Manager::getId(char string[20]) {
	int BOOKIDNUM = 0;//得到Id编号，用于自增
	FILE * fp;
	char msg[20];//接受文件字符串
	if(NULL == (fp=fopen("Id.txt", "r"))) {
			printf("open file error");
			exit(0);
	}
	if(fgets((char*)msg,20,fp)) {
		BOOKIDNUM =  atoi(msg);//转成int型
	}

	itoa(BOOKIDNUM++,(char *)string,10);//传回一个Id
	//printf("string_id %s \n", string);
	fclose(fp);
	if(NULL == (fp=fopen("Id.txt", "w"))) {
			printf("open file error");
			exit(0);
	}
    //printf("BOOKIDNUM:%d\n", BOOKIDNUM);
	fprintf(fp,"%d\n",BOOKIDNUM);//保存Id
	fclose(fp);
}

void Manager::manager_single_show(int flag)//管理员：flag=1
{
    cout << "开始展示" << endl;
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

	if(NULL==(fp=fopen("search_single.dat","rb")))//文件不存在
	{
		cout<<"文件不存在...."<<endl;
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
        cout<< "书名:" << statebook.getBookName()<<" "<<endl;
        cout<<"类型:" << statebook.getKind()<<"  ";
        cout<<"作者:" << statebook.getAuthor()<<"  ";
        cout<<"价格:" << statebook.getPrice()<<"  "<<endl;
        cout<<"借阅状态:";
        if(statebook.getBorrowState()==0)
            cout << "无" << ";"<<endl;
        else
            cout << "已被借阅"<<";" << endl;
        if(flag==1){
            cout<<"借阅人ID:" ;
            if(strcmp(statebook.getBorrowUserID(), "-1") == 0)//statebook.getBorrowUserID()=="-1"
                cout << "无" << ";"<<endl;
            else
                cout << statebook.getBorrowUserID()<<";"<<endl;
        }
        cout<<"预约人状态:" ;
        if(statebook.getAppointmentState()==0)
            cout << "无" << ";"<<endl;
        else
            cout << statebook.getAppointmentState()<<";";
        if(flag==1)
        {
            cout<<"预约人ID:" ;
            if(strcmp(statebook.getAppointmentUserId(), "-1") == 0)//statebook.getAppointmentUserId()=="-1"
                cout << "无" << ";"<<endl;
            else
                cout << statebook.getAppointmentUserId()<<";"<<endl;
        }
        if(flag==1)
        {cout << "截止日期:";
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
	if(NULL==(fp=fopen("search_union.dat","rb")))//文件不存在
	{
		cout<<"文件不存在...."<<endl;
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

//显示用户的操作记录
void showOldRecord(Record userRecord) {

	cout<<"用户Id: "<<userRecord.getUserId()<<"   书籍Id: "<<userRecord.getBookId()<<"   操作类型: ";
	if(userRecord.getBorrowState() == 0) {
		cout<<"归还";
	} else if(userRecord.getBorrowState() == 1) {
		cout<<"借阅";
	} else if(userRecord.getBorrowState() == 2) {
		cout<<"续借";
	}
	cout<<"   操作生成时间: "<<userRecord.getStartTime().getYear()<<"-"<<userRecord.getStartTime().getMonth()<<"-"<<userRecord.getStartTime().getDay()<<endl;

}

//展示用户当前借阅信息
void Manager::showNowRecord(UserState user) {
	cout<<"用户id:"<<user.getUserId()<<endl;
	cout<<"当前借阅数量："<<user.getAccount()<<endl;
	cout<<"书籍信息："<<endl;
	for(int i=0;i<user.getAccount(); i++) {
		cout<<"书籍ID："<<user.getStateBooks()[i].getBookId()<<"  书名:"<<user.getStateBooks()[i].getBookName()<<"  借阅状态:";
		if (user.getStateBooks()[i].getBorrowState()==1)
            cout << "已借阅";
            cout << "  截止时间:"<<user.getStateBooks()[i].getDeadlineTime().getYear()<<"-"<<user.getStateBooks()[i].getDeadlineTime().getMonth()<<"-"<<user.getStateBooks()[i].getDeadlineTime().getDay()<<endl;
	}
}

//获取用户当前借阅信息
void Manager::getUserRecord(char id[20]) {
	FILE *fp;
	bool isHaveUser=true;
	if (NULL == (fp = fopen("borrow.dat", "rb"))){
		cout << "读取文件出错！" << endl;
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
		cout<<"未查到该用户"<<endl;
		return;
	}
}

//得到用户的操作日志
void Manager::getUserLog(char id[20]) {
	FILE *fp;
	char tempstr[20]={""};
	int temp=-1;
	bool isHaveUser=true;
	if (NULL == (fp = fopen("record.dat", "rb"))){
		cout << "读取文件出错！" << endl;
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
		cout<<"未查到该用户任一操作记录"<<endl;
		return;
	}
}

//随机为20个用户借5~7本书
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
			num = rand()%3+5;   //产生5~7之间的数量
		}
		i++;
		if(i > 20) {  //给二十个用户借书
			break;
		}
		if(strcmp(user.getUserId(),user2.getUserId()) == 0) {
			break;
		}
		//cout<<num<<endl;
		for(int j=0; j<num; j++) {
			//借书
			book = Manager::randomGetBook(0);
			userManager.borrow_book(user.getUserId(), book,0);
		}
		user2 = user;
	}
	if(i == 21) {
		cout<<"一键生成随机测试样例成功"<<endl;
	}
	else if(i<21) {
		cout<<"已给"<<i-1<<"位用户借书成功"<<endl;
	} else {
		cout<<"测试用户借书数量均达到上限"<<endl;
	}
}

*/

StateBook Manager::randomGetBook(int flag) { //flag等于1从头寻找
	FILE *fp;
	StateBook book;
	int num;
	if(flag != 1) {
		num = rand()%1000;   //产生0~1000的随机数
	} else {
		num = 0;
	}
	book.setBookId("-1");

	if (NULL == (fp = fopen("book.dat", "rb"))){
		cout << "读取文件出错！" << endl;
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
		cout<<"修改书籍信息成功，当前该书籍信息为:"<<book.getBookId()<<"  "<<book.getBookName()<<"  "<<book.getKind()<<"  "<<book.getAuthor()<<"  "<<book.getPrice()<<endl;
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
		cout<<"该用户原信息为: 学号:"<<user.getUserId()<<"  姓名:"<<user.getName()<<"  密码:"<<user.getPassword()<<endl;
		cout<<"请输入要修改的信息:"<<endl;
		while(1)
		{
			cout<<"姓名:";
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
				user.setName(user_name);
				break;
			}
		}
		while(1)
		{
			cout<<"密码:";
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
				user.setPassword(user_password);
				break;
			}
		}
		if((fp=fopen("user.dat","rb+")))
		{
			fseek(fp, i*sizeof(User), SEEK_SET);
			fwrite(&user,sizeof(User),1,fp);
			cout<<"success,修改成功"<<endl;
			cout<<"该用户当前信息为: 学号:"<<user.getUserId()<<"  姓名:"<<user.getName()<<"  密码:"<<user.getPassword()<<endl;
		}
		fclose(fp);
	}
	else
	{
		cout<<"fail,该id不存在"<<endl;
	}

}



//12用户，13书籍，14随机显示，15显示所有的流水信息

//显示所有书籍信息
void Manager::showAllBookMsg() {
	FILE *fp;
	StateBook book;
	StateBook book2;
	int num = 0;

	if (NULL == (fp = fopen("book.dat", "rb"))){
		cout << "读取文件出错！" << endl;
		exit(0);
	}

	while(!feof(fp)) {
		fread(&book, sizeof(StateBook), 1, fp);
		if(strcmp(book.getBookId(),"-1") == 0 ) {
			num++;
			continue;
		}
		if(strcmp(book.getBookId(), book2.getBookId()) == 0) {
			cout<<"馆藏"<<num<<"本书"<<endl;
			break;
		}
		cout<<book.getBookId()<<"  ";
		cout<<book.getBookName()<<"  ";
		cout<<book.getKind()<<"  ";
		cout<<book.getAuthor()<<"  ";
		cout<<book.getPrice()<<"  ";
		if(book.getBorrowState() == 0){
            //cout<<book.getBorrowState()<<"  ";
            cout << "没有被借阅" << "  ";
		}
		else if(book.getBorrowState() == 1)
        {
            cout << "已被借阅" << "  ";
        }
		if(strcmp(book.getBorrowUserID(), "-1") == 0)
		{
		    //cout<<book.getBorrowUserID()<<"  ";
		    cout << "无" << "  ";
		}
		if(book.getAppointmentState() == 0)
        {
            //cout<<book.getAppointmentState()<<"  ";
            cout << "没有被预约" << "  ";
        }
        else if(book.getAppointmentState() == 1)
        {
            cout << "已被预约" << "  ";
        }

		if(strcmp(book.getAppointmentUserId(), "-1"))
        {
            //cout<<book.getAppointmentUserId()<<"  ";
            cout << "无" << "  ";
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

//显示所有用户信息
void Manager::showAllUserMsg() {
	FILE *fp;
	User user;
	User user2;
	int num = 0;
	if(NULL == (fp = fopen("user.dat", "rb+"))){
		cout << "读取文件出错！" << endl;
		exit(0);
	}
	while(!feof(fp)) {
		fread(&user, sizeof(User), 1, fp);
		if(strcmp(user.getUserId(), "-1")==0){
			continue;
		}
		if(strcmp(user.getUserId(), user2.getUserId()) == 0) {
			cout<<"共有"<<num<<"位用户"<<endl;
			break;
		}
		cout<<user.getUserId()<<"   "<<user.getName()<<endl;
		user2 = user;
		num++;
	}
	fclose(fp);
}

//随机显示十本书籍信息
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
			cout<<"未借出  ";
		} else if(book.getBorrowState() == 1) {
			cout<<"借阅中  ";
			cout<<book.getBorrowUserID()<<"  ";
		} else if(book.getBorrowState() == 2) {
			cout<<"续借中  ";
			cout<<book.getBorrowUserID()<<"  ";
		}
		if(book.getAppointmentState() == 0) {
			cout<<"未预约  ";
		} else if(book.getAppointmentState() == 1) {
			cout<<"预约中  ";
			cout<<book.getAppointmentUserId()<<"  ";
		}
		cout<<(book.getDeadlineTime()).getYear()<<"-";
		cout<<(book.getDeadlineTime()).getMonth()<<"-";
		cout<<(book.getDeadlineTime()).getDay();
		cout<<endl;
	}
}

//显示所有的日志信息
void Manager::showLogMsg() {
	FILE *fp;
	char tempstr[20]={""};
	int temp=-1;
	//bool isHaveUser=true;
	if (NULL == (fp = fopen("record.dat", "rb"))){
		cout << "读取文件出错！" << endl;
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
