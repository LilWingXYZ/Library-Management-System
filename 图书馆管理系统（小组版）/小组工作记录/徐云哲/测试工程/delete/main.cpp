#include <iostream>
#include<fstream>
#include <vector>                                               //自己增加
#include "BookManageMentIOHeader.h"
using namespace std;


/*---------------------------------------------张文政查询------------------------------------------上分界线*/
void searchAllBooks();//无条件展示所有书籍
void searchBookId(unsigned int bookId);//按书号查询书籍信息
void searchPeopleId(unsigned int peopleId);//按借书人序号查询书籍信息
void searchBookClass(int bookClass);//按书籍类别查询书籍信息
void searchPrice(float price1,float price2);//按价格区间查询书籍信息
void searchName(char name[20]);//按名字查询书籍信息
void searchPublisher(char publisher[20]);//按出版社查询书籍信息
void searchAuthor(char author[8]);//按作者查询书籍信息
void searchPublishDate(char publishDate[8]);//按出版日期查询书籍信息
void searchBorrowTime(char borrowTime[10]);//按借出日期查询书籍信息
int  searchInstanceOfBook(unsigned int bookId);//查询书号来返回某本书在文件里的distance

void searchAllPeople();//无条件展示所有用户信息
void searchPeopleId(unsigned int peopleId);//通过用户号查询用户信息
void searchRecentBorrowId(unsigned int recentBorrowId[10]);//暂时不考虑
void searchRank(int rank);//通过用户等级查询用户信息
void searchCredit(int credit);//通过信用等级查询用户信息
int  searchInstanceOfPeople(unsigned int peopleId);//查询用户号来返回某用户在文件里的distance


void searchAllBooks(){//无条件展示所有书籍
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int maxBooksNum = 10;//这里假定统计过后文件里的数据量目前一共有10个，用maxBooksNum来记录

    while(distance < (maxBooksNum-1)){//当数据没找完时，不断十个十个地接受展示数据
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){
                bm.showInfo(ret[i]);//展示当前书籍数据
                distance++;//记录查过的书的数目
            }

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
}

void searchBookId(unsigned int bookId){//按书号查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int maxBooksNum = 10;//这里假定统计过后文件里的数据量目前一共有10个，用maxBooksNum来记录
    while(distance < (maxBooksNum-1)){//当数据没找完时
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(bookId == ret[i].bookId){
                    cout << "We got it!=3=" << endl;
                    bm.showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
}

//查询在文件中book的distance
int  searchInstanceOfbook(unsigned int bookId){
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int maxBooksNum = 9999;//这里假定统计过后文件里的数据量目前一共有9999个，用maxBooksNum来记录
    while(distance < (maxBooksNum-1)){//当数据没找完时
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(bookId == ret[i].bookId){
                    cout << "We got it!=3=" << endl;
                    bm.showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    return distance;//找到立刻返回他的distance
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
        return 0;
    }
    }
    return 0;
}

/*---------------------------------------------张文政查询------------------------------------------下分界线*/


/*----------------------------------------------伪删除-------------------------------------------------上分割线*/
//根据书籍编号（bookId）
//void falseDeleteBookbyId(string filename,book *b,unsigned int bookId)
void falseDeleteBookbyId(string filename,book *b)
{
    int distance = searchInstanceOfbook(b->bookId);//根据查询函数定位Book在文件中的位置
    //if (distance>=0 && b->isDeleted == 0)
    if (distance>=0 && b->isDeleted == false)
    {
        int choice;
        cout<<"确定删除？ 1.删除 0.返回"<<endl;
        cin>>choice;
        if(choice==1)
        {
            //b->isDeleted = 1;
            b->isDeleted = true;
            BookClassIO temp;
            temp.writeFile(*b,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
            cout<<"删除图书成功!"<<endl;
                return ;
        }
        else if(choice==0)
        {
            return ;
        }
    }
    else
        cout<<"没有查询到本书,无法删除!"<<endl;
}

/*
//根据书籍分类（bookClass）
void falseDeleteBookbyClass(string filename,book *b, int bookClass)
{
        searchBookClass(bookClass);
    	unsigned int deleteBookId;
	cout<<"请输入要删除书籍的编号：";
	cin>>deleteBookId;
	falseDeleteBookbyId(filename,b,deleteBookId);
	return ;
}

//根据书籍价格区间（price）
void falseDeleteBookbyPrice(string filename,book *b, float price1,float price2)
{
        searchPrice(price1,price2);
    	unsigned int deleteBookId;
	cout<<"请输入要删除书籍的编号：";
	cin>>deleteBookId;
	falseDeleteBookbyId(filename,b,deleteBookId);
	return ;
}

//根据书籍名称（bookName）
void falseDeleteBookbyName(string filename,book *b,char *name)
{
        searchName(name);
    	unsigned int deleteBookId;
	cout<<"请输入要删除书籍的编号：";
	cin>>deleteBookId;
	falseDeleteBookbyId(filename,b,deleteBookId);
	return ;
}

//根据书籍出版社（publisher）
void falseDeleteBookbyPublisher(string filename,book *b, char *publisher)
{
        searchPublisher(publisher);
    	unsigned int deleteBookId;
	cout<<"请输入要删除书籍的编号：";
	cin>>deleteBookId;
	falseDeleteBookbyId(filename,b,deleteBookId);
	return ;
}

//根据书籍作者（author）
void falseDeleteBookbyAuthor(string filename,book *b, char *author)
{
        searchAuthor(author);
    	unsigned int deleteBookId;
	cout<<"请输入要删除书籍的编号：";
	cin>>deleteBookId;
	falseDeleteBookbyId(filename,b,deleteBookId);
	return ;
}

//根据书籍出版年份（publishDate）
void falseDeleteBookbyPublishDate(string filename,book *b, char *publishDate)
{
        searchPublishDate(publishDate);
    	unsigned int deleteBookId;
	cout<<"请输入要删除书籍的编号：";
	cin>>deleteBookId;
	falseDeleteBookbyId(filename,b,deleteBookId);
	return ;
}

//根据书籍借出时间（borrowTime）
void falseDeleteBookbyBorrowTime(string filename,book *b, char *borrowTime)
{
        searchBorrowTime(borrowTime);
    	unsigned int deleteBookId;
	cout<<"请输入要删除书籍的编号：";
	cin>>deleteBookId;
	falseDeleteBookbyId(filename,b,deleteBookId);
	return ;
}
*/

/*
//各类删除调用
void falseDeleteBook(string fname,book *b)
{
	int choice;
	while(choice!=0)
	{
		cout<<"请选择删除依据："<<endl<<endl;
		cout<<"    1.书籍编号"<<endl;
		cout<<"    2.书籍分类"<<endl;
		cout<<"    3.书籍价格区间"<<endl;
		cout<<"    4.书籍名称"<<endl;
		cout<<"    5.书籍出版社"<<endl;
		cout<<"    6.书籍作者"<<endl;
		cout<<"    7.书籍出版年份"<<endl;
		cout<<"    8.书籍借出时间"<<endl;
        cout<<"    0.退出删除界面"<<endl<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1:
				unsigned int id;
				cout<<"请输入书籍编号：";
				cin>>id;
				falseDeleteBookbyId(fname,b,id);
				break;
			case 2:
				int class1;
				cout<<"请输入书籍分类：";
				cin>>class1;
				falseDeleteBookbyClass(fname,b,class1);
				break;
			case 3:
				float price1;
				float price2;
				cout<<"请输入书籍价格区间：如（0.0  1.0）";
				cin>>price1>>price2;
				falseDeleteBookbyPrice(fname,b,price1,price2);
				break;
			case 4:
				char name[20];
				cout<<"请输入书籍名称：";
				cin>>name;
				falseDeleteBookbyName(fname,b,name);
				break;
			case 5:
				char pub[20];
				cout<<"请输入书籍出版社：";
				cin>>pub;
				falseDeleteBookbyPublisher(fname,b,pub);
				break;
			case 6:
				char aut[8];
				cout<<"请输入书籍作者：";
				cin>>aut;
				falseDeleteBookbyAuthor(fname,b,aut);
				break;
			case 7:
				char year[8];
				cout<<"请输入书籍出版年份：";
				cin>>year;
				falseDeleteBookbyPublishDate(fname,b,year);
				break;
			case 8:
				char time[10];
				cout<<"请输入书籍借出时间：";
				cin>>time;
				falseDeleteBookbyBorrowTime(fname,b,time);
				break;
			case 0:
				//转向上一级界面
				break;
			default:
				cout<<"输入错误，请从新输入:";
		}
	}
}
/*----------------------------------------------伪删除-------------------------------------------------下分割线*/


/*----------------------------------------------真删除-------------------------------------------------上分割线*/
//根据书籍编号（bookId）
//void trueDeleteBookbyId(string filename,book *b,unsigned int bookId)
void trueDeleteBookbyId(string filename,book *b)
{
    int distance = searchInstanceOfbook(b->bookId);//根据查询函数定位Book在文件中的位置
    //if (distance>=0 && b->isDeleted == 0)
    if (distance>=0 && b->isDeleted == false)
    //if (distance>=0 && b->trueDelete == false)
    {
        int choice;
        cout<<"确定删除？ 1.删除 0.返回"<<endl;
        cin>>choice;
        if(choice==1)
        {
            //b->trueDelete = 1;
            b->isDeleted = true;
            BookClassIO temp;
            temp.writeFile(*b,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息

            vector<unsigned int> deletedID;
            vector<int> deletedDistance;
            unsigned int allDeletedID;
            int allDeletedDistance;

/*--------------------------------读取文件"deletedID"中已有的数据--------------------上分割线*/
            ifstream fin1("deletedID.txt");
            //ifstream fin1("deletedID.dat",ios::in|ios::binary);
            if(fin1)
            {
                fin1>>allDeletedID;
                for(int i=0; i<allDeletedID; i++)
                {
                    unsigned int temp;
                    fin1>>temp;
                    deletedID.push_back(temp);
                }
                fin1.close();
            }
/*--------------------------------读取文件"deletedID"中已有的数据--------------------下分割线*/

/*--------------------------------读取文件"deletedDistance.txt"中已有的数据--------------------上分割线*/
            ifstream fin2("deletedDistance.txt");
            //ifstream fin2("deletedDistance.dat",ios::in|ios::binary);
            if(fin2)
            {
                fin2>>allDeletedDistance;
                for(int i=0; i<allDeletedDistance; i++)
                {
                    int temp;
                    fin2>>temp;
                    deletedDistance.push_back(temp);
                }
                fin2.close();
            }
/*--------------------------------读取文件"deletedDistance.txt"中已有的数据--------------------下分割线*/
            deletedID.push_back(b->bookId);                           //将新增加的被删除项加入尾部
            deletedDistance.push_back(distance);                      //将新增加的被删除项加入尾部

/*--------------------------------写文件"deletedID"--------------------上分割线*/
            ofstream fout1("deletedID.txt");
            //ofstream fout1("deletedID.dat",ios::app|ios::binary);
            if (fout1)
            {
                fout1<<deletedID.size()<<endl;
                for (int i = 0; i <(int)deletedID.size(); i++)
                {
                    fout1<<deletedID[i]<<endl;
                }
                fout1.close();
            }
/*--------------------------------写文件"deletedID"--------------------下分割线*/
/*--------------------------------写文件"deletedDistance"--------------------上分割线*/
            ofstream fout2("deletedDistance.txt");
            //ofstream fout2("deletedDistance.dat",ios::app|ios::binary);
            if (fout2)
            {
                fout2<<deletedDistance.size()<<endl;
                for (int i = 0; i <(int)deletedDistance.size(); i++)
                {
                    fout2<<deletedDistance[i]<<endl;
                }
                fout2.close();
            }
/*--------------------------------写文件"deletedDistance"--------------------下分割线*/
            cout<<"删除图书成功!"<<endl;
            return ;
        }
        else if(choice==0)
        {
            return ;
        }
    }
    else
        cout<<"没有查询到本书,无法删除!"<<endl;
}

/*----------------------------------------------真删除-------------------------------------------------下分割线*/

//测试用恢复函数
//根据书籍编号（bookId）
//void recoverDeleteBookbyId(string filename,book *b,unsigned int bookId)
void recoverDeleteBookbyId(string filename,book *b)
{
    int distance = searchInstanceOfbook(b->bookId);//根据查询函数定位Book在文件中的位置
    //if (distance>=0 && b->isDeleted == 1)
    if (distance>=0 && b->isDeleted == true)
    {
        int choice;
        cout<<"确定恢复？ 1.恢复 0.返回"<<endl;
        cin>>choice;
        if(choice==1)
        {
            //b->isDeleted = 0;
            b->isDeleted = false;
            BookClassIO temp;
            temp.writeFile(*b,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
            cout<<"恢复图书成功!"<<endl;
                return ;
        }
        else if(choice==0)
        {
            return ;
        }
    }
    else
        cout<<"没有查询到本书,无法删除!"<<endl;
}

//测试用main函数
int main()
{
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book bookArray[10];//用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int state = bm.readFile(bookArray,fname,0,2);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    cout<<"STATE:"<<state<<endl;
         for(int i=0;i<10;i++){

          cout<<"编号NO."<<bookArray[i].bookId<<endl;
          cout<<"借书人编号:"<<bookArray[i].peopleId<<endl;
          cout<<"分类："<<bookArray[i].bookClass<<endl;
          cout<<"价格："<<bookArray[i].price<<endl;
          cout<<"书名："<<bookArray[i].bookName<<endl;
          cout<<"出版社："<<bookArray[i].publisher<<endl;
          cout<<"作者："<<bookArray[i].author<<endl;
          cout<<"出版日期："<<bookArray[i].publishDate<<endl;
          cout<<"借出时间："<<bookArray[i].borrowTime<<endl;
          cout<<"借出："<<bookArray[i].borrowFlag<<endl;
          cout<<"预定："<<bookArray[i].isReservedFlag<<endl;
          cout<<"保存本："<<bookArray[i].isPreservedFlag<<endl;
          cout<<"逾期："<<bookArray[i].isDeleted<<endl;
          cout<<"删除："<<bookArray[i].isDeleted<<endl;
          cout<<"----------------------------------------"<<endl;
   }
    falseDeleteBookbyId(fname,&bookArray[0]);              //测试伪删除  备注：修改&bookArray[0]中的0进行测试即可，范围0~9
    //trueDeleteBookbyId(fname,&bookArray[0]);              //测试真删除    备注：修改&bookArray[0]中的0进行测试即可，范围0~9
    //recoverDeleteBookbyId(fname,&bookArray[0]);          //测试用删除恢复函数  可将标志位还原  备注：修改&bookArray[0]中的0进行测试即可，范围0~9
    return 0;
}



  //          vector<unsigned int> deletedID;
    //        vector<int> deletedDistance;


      //  deletedDistance.erase(deletedDistance.begin());
