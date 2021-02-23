#include "Option.h"
#include <iostream>

using namespace std;

Option::Option(string fileBookName_in,string filePeopleName_in,people *p_in)  //构造函数
{
    fileBookName = fileBookName_in;
    filePeopleName = filePeopleName_in;
    p = p_in;

}
Option::Option(){}
Option::~Option()  //析构函数
{

    delete p;

}


//---------------------------------------------计算两个日期之间的天数---------------------------------------------



///设置和获取文件名
void Option::setFileBookName(string newBookName){

    fileBookName = newBookName;


}
void Option::setFilePeopleName(string newPeopleName){

   filePeopleName = newPeopleName;

}
string Option::getFileBookName(){

    return fileBookName;

}
string Option::getFilePeopleName(){

    return filePeopleName;


}


/*----------------------------------------用户和书本操作信息---------------------------------*/

///注册,登陆和退出在User类
void Option::regist()
{

    if(p->level < ManagerLevel)//普通用户注册
    {
        addSinglePeople(filePeopleName);//将用户信息加入filePeopleName用户文件
        cout<<"regist successfully!"<<endl;
    }
    else
    {
        int Size;
        cout<<"Please input the amount you want to regist."<<endl;
        cin>>Size;
        addPeople(Size,filePeopleName);//对于管理员和超级用户可以在用户文件增加多个用户信息
        cout<<"add registers successfully!"<<endl;
    }
}

///书本添加

void Option::AddBook()//管理员和超级管理员可以进行单书本添加
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function!";
    }
    else
    {
        addSingleBook(fileBookName);
    }
}

void Option::AddManyBooks(int Size)//管理员和超级管理员可以进行多书本添加
{
    if(p->level < ManagerLevel)
    {
        cout<<"You have no right to access this function!";
    }
    else
    {
        addBooks(Size,fileBookName);
    }
}

//书本删除

void Option::falseDeleteBook(book *Book)//书本伪删除
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function!";
    }
    else
    {
        falseDeleteBookbyId(fileBookName,Book,searchInstanceOfBook(Book->bookId,fileBookName));
    }
}

void Option::trueDeleteBook(book *Book)//书本真删除
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        trueDeleteBookbyId(fileBookName,Book,searchInstanceOfBook(Book->bookId,fileBookName));
    }
}

///书本更新
void Option::updateBookAll(book *Book)  //整体修改书本信息
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookAll)！";
    }
    else
    {
        updateBook(fileBookName,Book);
    }

}

void Option::updateBookById(book *Book, int BookId)//更改书的ID值
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookById)！";
    }
    else
    {
        updateBookId(fileBookName,Book, BookId);
    }
}

void Option::updateBookPeopleById(book *Book, int PeopleId)//更改书籍借阅人ID值
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookPeopleById)！";
    }
    else
    {
        updateBookPeopleId(fileBookName, Book, PeopleId);
    }
}

void Option::updateBookByClass(book *Book, int BookClass)//更改书的类别
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByClass)！";
    }
    else
    {
        updateBookClass(fileBookName, Book, BookClass);
    }
}

void Option::updateBookByPrice(book *Book, float Price)//更改书的价格
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByPrice)！";
    }
    else
    {
        updateBookPrice(fileBookName, Book, Price);
    }
}

void Option::updateBookByName( book *Book, char *Name)//更改书名
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByName)！";
    }
    else
    {
        updateBookName(fileBookName, Book, Name);
    }
}

void Option::updateBookByPublisher(book *Book, char *Publisher)//更改书的出版社
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByPublisher)！";
    }
    else
    {
        updateBookPublisher(fileBookName, Book, Publisher);
    }
}

void Option::updateBookByAuthor(book *Book, char *Author)//更改书的作者
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByAuthor)！";
    }
    else
    {
        updateBookAuthor(fileBookName, Book, Author);
    }
}

void Option::updateBookByPublishDate(book *Book, char *PublishDate)//更改书的出版日期
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByPublishDate)！";
    }
    else
    {
        updateBookPublishDate(fileBookName, Book, PublishDate);
    }
}

void Option::updateBookByBorrowTime(book *Book, char *BorrowTime)//更改借书时间
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByBorrowTime)！";
    }
    else
    {
        updateBookBorrowTime(fileBookName, Book, BorrowTime);
    }
}
//更改书的状态信息
void Option::updateBookByBorrowFlag(book *Book,char BorrowFlag)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByBorrowFlag)！";
    }
    else
    {
        updateBookBorrowFlag(fileBookName, Book, BorrowFlag);
    }
}

void Option::updateBookByReservedFlag(book *Book, char ReservedFlag)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByReservedFlag)！";
    }
    else
    {
        updateBookReservedFlag(fileBookName, Book, ReservedFlag);
    }
}

void Option::updateBookByPreservedFlag(book *Book, char PreservedFlag)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByPreservedFlag)！";
    }
    else
    {
        updateBookPreservedFlag(fileBookName, Book, PreservedFlag);
    }
}

void Option::updateBookByLatedFlag(book *Book, char LatedFlag)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByLatedFlag)！";
    }
    else
    {
        updateBookLatedFlag(fileBookName, Book, LatedFlag);
    }
}

void Option::updateBookByDeletedFlag(book *Book, char DeletedFlag)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByDeletedFlag)！";
    }
    else
    {
        updateBookDeletedFlag(fileBookName, Book, DeletedFlag);
    }
}

void Option::updateBookByRealDeletedFlag( book *Book, char RealDeletedFlag)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByRealDeletedFlag)！";
    }
    else
    {
        updateBookRealDeletedFlag(fileBookName, Book, RealDeletedFlag);
    }
}



///书籍查询

//无条件展示所有书籍
void Option::searchAllBook()
{
    searchAllBooks(fileBookName);
}
//按书号查询书籍信息
void Option::searchBookId(unsigned int bookId)
{
    searchBookById(bookId,fileBookName);
}
//按借书人序号查询书籍信息
void Option::searchBookPeopleId(unsigned int peopleId)
{
    searchBookByPeopleId(peopleId,fileBookName);
}
//按书籍类别查询书籍信息
void Option::searchBookClass(int bookClass)
{
    searchBookByClass(bookClass,fileBookName);
}
//按价格 区间查询书籍信息
void Option::searchBookPrice(float price1, float price2)
{
    searchBookByPrice(price1, price2,fileBookName);
}
//按名字查询书籍信息
void Option::searchBookName(char name[20])
{
    searchBookByName(name,fileBookName);
}
//按出版社查询书籍信息
void Option::searchBookPublisher(char publisher[20])
{
    searchBookByPublisher(publisher,fileBookName);
}
//按作者查询书籍信息
void Option::searchBookAuthor(char author[8])
{
    searchBookByAuthor(author,fileBookName);
}
//按出版日期查询书籍信息
void Option::searchBookPublishDate(char publishDate[8])
{
    searchBookByPublishDate(publishDate,fileBookName);
}
//按借出日期查询书籍信息
void Option::searchBookBorrowTime(char borrowTime[10])
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        searchBookByBorrowTime(borrowTime,fileBookName);
    }
}



///-------------------用户操作------------------------------

///添加用户
void Option::AddPeople()
{
     if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        addSinglePeople(filePeopleName);

    }
}

void Option::AddManyPeople(int Size)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        addPeople(Size,filePeopleName);

    }

}

///伪删除和真删除用户
void Option::falseDeletePeople(people *People)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        falseDeletePeoplebyId(filePeopleName,People);
    }

}


void Option::trueDeletePeople(people *People)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        trueDeletePeoplebyId(filePeopleName,People);
    }

}

///用户信息修改

void Option::updatePeopleAll(people *People)//整体修改用户信息
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeople(filePeopleName,People);
    }
}
void Option::updatePeopleById(people *People,int PeopleId)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeopleId(filePeopleName,People,PeopleId);
    }
}

void Option::updatePeopleByRecentBorrowId(people *People,int *RecentBorrowId,int numArray)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeopleRecentBorrowId(filePeopleName,People,RecentBorrowId,numArray);
    }
}

void Option::updatePeopleByPeoplesBorrowed(people *People,int *PeoplesBorrowed,int numArray)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeoplePeoplesBorrowed(filePeopleName,People,PeoplesBorrowed,numArray);
    }
}

void Option::updatePeopleByPassword(people *People,char *Password)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeoplePassword(filePeopleName.c_str(),People,Password);
    }
}

void Option::updatePeopleByLevel(people *People,int Level)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeopleLevel(filePeopleName.c_str(),People,Level);
    }
}

void Option::updatePeopleByCredit(people *People,int Credit)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeopleCredit(filePeopleName.c_str(),People,Credit);
    }
}

void Option::updatePeopleByName(people *People,char *PeopleName)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeopleName(filePeopleName,People,PeopleName);
    }
}

void Option::updatePeopleByDeleted(people *People,char IsDeleted)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        updatePeopleDeleted(filePeopleName.c_str(),People,IsDeleted);
    }
}



///用户信息查询
void Option::searchAllPersons()
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        searchAllPeople(filePeopleName);
    }
}
void Option::searchPeopleId(unsigned int peopleId)
{
     if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        searchPeopleById(peopleId,filePeopleName);
    }

}
/*
void Option::searchPeopleRecentBorrowId(unsigned int recentBorrowId[10])
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        searchPeopleByRecentBorrowId(recentBorrowId,filePeopleName);
    }
}
*/
void Option::searchPeopleRank(int Rank)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        searchPeopleByLevel(Rank,filePeopleName);
    }
}

void Option::searchPeopleCredit(int credit)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function！";
    }
    else
    {
        searchPeopleByCredit(credit,filePeopleName);
    }
}




