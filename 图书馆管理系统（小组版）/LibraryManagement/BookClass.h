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
//cstring��Ҫ��Ϊ�����ʹ��memcpy����������char������������ݴ���
//��������������publisher��غ�������ı�������Ϊpublishert(=publishertemp,��ʱ���������ڽ���)
typedef enum bookClassification {MaoDeng,PhilosophyReligion,Social,PoliticalLaw,Military,Economic,Literature_PE,Language,
                                 Literature,Art,HistoryGeography,Nature,MathChemistry,Astronomy,Biology,Medicine,Agriculture,Industry,Transportation,
                                 Aerospace,EnvironmentSafety,Comprehensive
                                } BookType;

class LBook//Ϊ�˺�֮ǰ�����book�ṹ�����LBook�����𣬶����LibraryLBook,��дLBook
{
public:

    //���캯��
    LBook(book Book);
    //���ƺ���
    //LBook(unsigned int bookIdt,string fname);
    //LBook(LBook const& t);

    //չʾ����
    void displayBook();

//            unsigned int bookId;//identify number for books
    int setbookId(unsigned int bookId);
    unsigned int getbookId();
//            unsigned int peopleId;//indentify number for readers
    int setpeopleId(unsigned int peopleId);
    int getpeopleId();
//            int bookClass; //�鼮����,bookClassΪ1-22���ֱ��Ӧ22������,��Ӧö�ٱ���bookClass-1
    int setbookClass(int bookClass);
    int getbookClass();
    string getBookClassName();//�õ��鱾����������
//            float price;//�۸�
    int setprice(float price);
    float getprice();
//            char bookName[45];//����,���44���ֽڣ�22������
    int setbookName(char bookName[45]);
    string getbookName();

//            char publisher[25];//������,24���ֽڣ�12������
    int setpublisher(char publisher[25]);
    string getpublisher();
//            char author[25];//���ߣ�24���ֽڣ�12������
    int setauthor(char author[25]);
    string getauthor();
//            char publishDate[5];//������ݣ�4���ֽڣ�ֻ����ݣ�����2009
    int setpublishDate(char publishDate[5]);
    string getpublishDate();
//            char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
    int setborrowTime(char borrowTime[11]);
    string getborrowTime();
//            char borrowFlag;//�����־λ
    int setborrowFlag(char borrowFlag);
    char getborrowFlag();
//            char isReservedFlag;//Ԥ����־λ
    int setisReservedFlag(char isReservedFlag);
    char getisReservedFlag();
//            char isPreservedFlag;//���汾��־λ
    int setisPreservedFlag(char isPreservedFlag);
    char getisPreservedFlag();
//            char isLated;//�Ƿ�����
    int setisLated(char isLated);
    char getisLated();
//            char isDeleted;//whether the record is delated(false as default)
    int setisDeleted(char isDeleted);
    char getisDeleted();
//            char isRealDeleted;//�Ƿ�����ɾ��
    int setisRealDeleted(char isRealDeleted);
    char getisRealDeleted();
    int GetBorrowTime();//���ؽ�ֹĿǰ�����ĵ�����
    book getBookStruct();//����book�ṹ��

private:
   book Book;
};
#endif // BookClass
