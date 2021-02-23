#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED
#include "AddOption.h"
#pragma once
#include "DeleteOption.h"
#include "UpdateOption.h"
#include "SearchOption.h"
#include <string>
using namespace std;
class Option///�����࣬��Ҫ�����û��ȼ������л�����ɾ�Ĳ�ѯ��������
{

private:
    string fileBookName;//�鱾�ļ���
    string filePeopleName;//�û��ļ���
    people *p;//�û��ṹ��ָ��,������

public:

    Option(string fileBookName_in,string filePeopleName_in,people *p_in);//���캯��
    Option();
    ~Option();//��������

    ///���úͻ�ȡ�ļ���
    void setFileBookName(string newBookName);
    void setFilePeopleName(string newPeopleName);
    string getFileBookName();
    string getFilePeopleName();


    void regist();                     //ע��
    /*--------------------------------------------------ͼ����ɾ�Ĳ���level�жϵȼ�������ӦȨ��-------------------------------------------------------------------*/
    ///�鱾���
    void AddBook(); //���ӵ���ͼ��
    void AddManyBooks(int Size);//���Ӷ౾ͼ��,size ������

    ///�鱾ɾ��
    void falseDeleteBook(book *Book);//����bookָ��αɾ��ͼ��
    void trueDeleteBook(book *Book);//����bookָ����ɾ��ͼ��

    ///�鱾����
    void updateBookAll(book *Book); //�����޸��鱾��Ϣ
    void updateBookById(book *Book, int BookId);//�޸��鼮���
    void updateBookPeopleById(book *Book, int PeopleId);//�޸Ľ����˱��
    void updateBookByClass(book *Book, int BookClass);//�޸��鼮����
    void updateBookByPrice(book *Book, float Price);//�޸��鼮�۸�
    void updateBookByName(book *Book, char *Name);//�޸��鼮����
    void updateBookByPublisher(book *Book, char *Publisher);//�޸��鼮������
    void updateBookByAuthor(book *Book, char *Author);//�޸��鼮����
    void updateBookByPublishDate(book *Book, char *PublishDate);//�޸��鼮�������
    void updateBookByBorrowTime(book *Book, char *BorrowTime);//�޸��鼮���ʱ��
    void updateBookByBorrowFlag(book *Book, char BorrowFlag);//�޸Ľ����־λ
    void updateBookByReservedFlag(book *Book, char ReservedFlag);//�޸�Ԥ����־λ
    void updateBookByPreservedFlag(book *Book, char PreservedFlag);//�޸ı��汾��־λ
    void updateBookByLatedFlag(book *Book, char LatedFlag); //�޸����ڱ�־λ
    void updateBookByDeletedFlag(book *Book, char DeletedFlag);//�޸�αɾ����־λ
    void updateBookByRealDeletedFlag(book *Book, char RealDeletedFlag); //�޸���ɾ����־λ

    ///�鱾��ѯ
    void searchAllBook();//������չʾ�����鼮
    void searchBookId(unsigned int bookId);//����Ų�ѯ�鼮��Ϣ
    void searchBookPeopleId(unsigned int peopleId);//����������Ų�ѯ�鼮��Ϣ
    void searchBookClass(int bookClass);//���鼮����ѯ�鼮��Ϣ
    void searchBookPrice(float price1, float price2); //���۸� �����ѯ�鼮��Ϣ
    void searchBookName(char name[20]);//�����ֲ�ѯ�鼮��Ϣ
    void searchBookPublisher(char publisher[20]);//���������ѯ�鼮��Ϣ
    void searchBookAuthor(char author[8]);//�����߲�ѯ�鼮��Ϣ
    void searchBookPublishDate(char publishDate[8]);//���������ڲ�ѯ�鼮��Ϣ
    void searchBookBorrowTime(char borrowTime[10]);//��������ڲ�ѯ�鼮��Ϣ


    /*---------------------------------------------------�û���ɾ�Ĳ�-------------------------------------------------------------------*/
    ///����û�
    void AddPeople();//�������鿨�İ���
    void AddManyPeople(int Size);//����������/���鿨�İ���

    ///ɾ���û�
    void falseDeletePeople(people *People);//����bookָ��αɾ���û�
    void trueDeletePeople(people *People);//����bookָ����ɾ���û�

    ///�����û�
    void updatePeopleAll(people *People);//�����޸��û���Ϣ
    void updatePeopleById(people *People,int PeopleId);//�޸Ľ����˱��
    void updatePeopleByRecentBorrowId(people *People,int *RecentBorrowId,int numArray);//�޸���������鼮���
    void updatePeopleByPeoplesBorrowed(people *People,int *PeoplesBorrowed,int numArray);//�޸��Ѿ����ĵ��鼮���
    void updatePeopleByPassword(people *People,char *Password);           //�޸��û�����
    void updatePeopleByLevel(people *People,int Level);//�޸Ľ����˼���
    void updatePeopleByCredit(people *People,int Credit);//�޸Ľ��������õ�
    void updatePeopleByName(people *People,char *PeopleName);//�޸Ľ���������
    void updatePeopleByDeleted(people *People,char IsDeleted);//�޸��û�αɾ����־λ

    ///��ѯ�û���Ϣ
    void searchAllPersons();//������չʾ�����û���Ϣ
    void searchPeopleId(unsigned int peopleId);//ͨ���û��Ų�ѯ�û���Ϣ
    void searchPeopleRecentBorrowId(unsigned int recentBorrowId[10]);//��ʱ������
    void searchPeopleRank(int Rank);//ͨ���û��ȼ���ѯ�û���Ϣ
    void searchPeopleCredit(int credit);//ͨ�����õȼ���ѯ�û���Ϣ


};

#endif // OPTION

