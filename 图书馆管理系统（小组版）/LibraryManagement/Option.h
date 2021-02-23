#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED
#include "AddOption.h"
#pragma once
#include "DeleteOption.h"
#include "UpdateOption.h"
#include "SearchOption.h"
#include <string>
using namespace std;
class Option///操作类，主要根据用户等级来进行基础增删改查询进行限制
{

private:
    string fileBookName;//书本文件名
    string filePeopleName;//用户文件名
    people *p;//用户结构体指针,操作者

public:

    Option(string fileBookName_in,string filePeopleName_in,people *p_in);//构造函数
    Option();
    ~Option();//析构函数

    ///设置和获取文件名
    void setFileBookName(string newBookName);
    void setFilePeopleName(string newPeopleName);
    string getFileBookName();
    string getFilePeopleName();


    void regist();                     //注册
    /*--------------------------------------------------图书增删改查以level判断等级授予相应权限-------------------------------------------------------------------*/
    ///书本添加
    void AddBook(); //增加单本图书
    void AddManyBooks(int Size);//增加多本图书,size 代表本数

    ///书本删除
    void falseDeleteBook(book *Book);//根据book指针伪删除图书
    void trueDeleteBook(book *Book);//根据book指针真删除图书

    ///书本更新
    void updateBookAll(book *Book); //整体修改书本信息
    void updateBookById(book *Book, int BookId);//修改书籍编号
    void updateBookPeopleById(book *Book, int PeopleId);//修改借书人编号
    void updateBookByClass(book *Book, int BookClass);//修改书籍分类
    void updateBookByPrice(book *Book, float Price);//修改书籍价格
    void updateBookByName(book *Book, char *Name);//修改书籍名称
    void updateBookByPublisher(book *Book, char *Publisher);//修改书籍出版社
    void updateBookByAuthor(book *Book, char *Author);//修改书籍作者
    void updateBookByPublishDate(book *Book, char *PublishDate);//修改书籍出版年份
    void updateBookByBorrowTime(book *Book, char *BorrowTime);//修改书籍借出时间
    void updateBookByBorrowFlag(book *Book, char BorrowFlag);//修改借出标志位
    void updateBookByReservedFlag(book *Book, char ReservedFlag);//修改预定标志位
    void updateBookByPreservedFlag(book *Book, char PreservedFlag);//修改保存本标志位
    void updateBookByLatedFlag(book *Book, char LatedFlag); //修改逾期标志位
    void updateBookByDeletedFlag(book *Book, char DeletedFlag);//修改伪删除标志位
    void updateBookByRealDeletedFlag(book *Book, char RealDeletedFlag); //修改真删除标志位

    ///书本查询
    void searchAllBook();//无条件展示所有书籍
    void searchBookId(unsigned int bookId);//按书号查询书籍信息
    void searchBookPeopleId(unsigned int peopleId);//按借书人序号查询书籍信息
    void searchBookClass(int bookClass);//按书籍类别查询书籍信息
    void searchBookPrice(float price1, float price2); //按价格 区间查询书籍信息
    void searchBookName(char name[20]);//按名字查询书籍信息
    void searchBookPublisher(char publisher[20]);//按出版社查询书籍信息
    void searchBookAuthor(char author[8]);//按作者查询书籍信息
    void searchBookPublishDate(char publishDate[8]);//按出版日期查询书籍信息
    void searchBookBorrowTime(char borrowTime[10]);//按借出日期查询书籍信息


    /*---------------------------------------------------用户增删改查-------------------------------------------------------------------*/
    ///添加用户
    void AddPeople();//单个借书卡的办理
    void AddManyPeople(int Size);//复数借书人/借书卡的办理

    ///删除用户
    void falseDeletePeople(people *People);//根据book指针伪删除用户
    void trueDeletePeople(people *People);//根据book指针真删除用户

    ///更新用户
    void updatePeopleAll(people *People);//整体修改用户信息
    void updatePeopleById(people *People,int PeopleId);//修改借书人编号
    void updatePeopleByRecentBorrowId(people *People,int *RecentBorrowId,int numArray);//修改最近借阅书籍编号
    void updatePeopleByPeoplesBorrowed(people *People,int *PeoplesBorrowed,int numArray);//修改已经借阅的书籍编号
    void updatePeopleByPassword(people *People,char *Password);           //修改用户密码
    void updatePeopleByLevel(people *People,int Level);//修改借书人级别
    void updatePeopleByCredit(people *People,int Credit);//修改借书人信用点
    void updatePeopleByName(people *People,char *PeopleName);//修改借书人姓名
    void updatePeopleByDeleted(people *People,char IsDeleted);//修改用户伪删除标志位

    ///查询用户信息
    void searchAllPersons();//无条件展示所有用户信息
    void searchPeopleId(unsigned int peopleId);//通过用户号查询用户信息
    void searchPeopleRecentBorrowId(unsigned int recentBorrowId[10]);//暂时不考虑
    void searchPeopleRank(int Rank);//通过用户等级查询用户信息
    void searchPeopleCredit(int credit);//通过信用等级查询用户信息


};

#endif // OPTION

