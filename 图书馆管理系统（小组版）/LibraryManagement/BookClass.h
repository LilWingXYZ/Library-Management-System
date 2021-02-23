#pragma once
#ifndef BOOKCLASS_H_INCLUDED
#define BOOKCLASS_H_INCLUDED
#include "SearchOption.h"
#include "Ltime.h"
#include <string>
#define bookNameLength 45
#define publisherLength 25
#define authorLength 25
#define publishDateLength 5
#define borrowTimeLength 11
using namespace std;
//cstring主要是为了配合使用memcpy函数来进行char类型数组的数据传入
//关于命名：比如publisher相关函数传入的变量命名为publishert(=publishertemp,暂时变量，用于接收)
typedef enum bookClassification {MaoDeng,PhilosophyReligion,Social,PoliticalLaw,Military,Economic,Literature_PE,Language,
                                 Literature,Art,HistoryGeography,Nature,MathChemistry,Astronomy,Biology,Medicine,Agriculture,Industry,Transportation,
                                 Aerospace,EnvironmentSafety,Comprehensive
                                } BookType;

class LBook//为了和之前定义的book结构体变量LBook相区别，定义成LibraryLBook,简写LBook
{
public:

    //构造函数
    LBook(book Book);
    //复制函数
    //LBook(unsigned int bookIdt,string fname);
    //LBook(LBook const& t);

    //展示函数
    void displayBook();

//            unsigned int bookId;//identify number for books
    int setbookId(unsigned int bookId);
    unsigned int getbookId();
//            unsigned int peopleId;//indentify number for readers
    int setpeopleId(unsigned int peopleId);
    int getpeopleId();
//            int bookClass; //书籍分类,bookClass为1-22，分别对应22个分类,对应枚举变量bookClass-1
    int setbookClass(int bookClass);
    int getbookClass();
    string getBookClassName();//得到书本类别的中文名
//            float price;//价格
    int setprice(float price);
    float getprice();
//            char bookName[45];//书名,最大44个字节，22个汉字
    int setbookName(char bookName[45]);
    string getbookName();

//            char publisher[25];//出版社,24个字节，12个汉字
    int setpublisher(char publisher[25]);
    string getpublisher();
//            char author[25];//作者，24个字节，12个汉字
    int setauthor(char author[25]);
    string getauthor();
//            char publishDate[5];//出版年份，4个字节，只有年份，例如2009
    int setpublishDate(char publishDate[5]);
    string getpublishDate();
//            char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
    int setborrowTime(char borrowTime[11]);
    string getborrowTime();
//            char borrowFlag;//借出标志位
    int setborrowFlag(char borrowFlag);
    char getborrowFlag();
//            char isReservedFlag;//预定标志位
    int setisReservedFlag(char isReservedFlag);
    char getisReservedFlag();
//            char isPreservedFlag;//保存本标志位
    int setisPreservedFlag(char isPreservedFlag);
    char getisPreservedFlag();
//            char isLated;//是否逾期
    int setisLated(char isLated);
    char getisLated();
//            char isDeleted;//whether the record is delated(false as default)
    int setisDeleted(char isDeleted);
    char getisDeleted();
//            char isRealDeleted;//是否真正删除
    int setisRealDeleted(char isRealDeleted);
    char getisRealDeleted();
    int GetBorrowTime();//返回截止目前被借阅的天数
    book getBookStruct();//返回book结构体

private:
   book Book;
};
#endif // BookClass
