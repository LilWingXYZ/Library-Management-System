#include "Option.h"
#include <iostream>

using namespace std;

Option::Option(string fileBookName_in,string filePeopleName_in,people *p_in)  //���캯��
{
    fileBookName = fileBookName_in;
    filePeopleName = filePeopleName_in;
    p = p_in;

}
Option::Option(){}
Option::~Option()  //��������
{

    delete p;

}


//---------------------------------------------������������֮�������---------------------------------------------



///���úͻ�ȡ�ļ���
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


/*----------------------------------------�û����鱾������Ϣ---------------------------------*/

///ע��,��½���˳���User��
void Option::regist()
{

    if(p->level < ManagerLevel)//��ͨ�û�ע��
    {
        addSinglePeople(filePeopleName);//���û���Ϣ����filePeopleName�û��ļ�
        cout<<"regist successfully!"<<endl;
    }
    else
    {
        int Size;
        cout<<"Please input the amount you want to regist."<<endl;
        cin>>Size;
        addPeople(Size,filePeopleName);//���ڹ���Ա�ͳ����û��������û��ļ����Ӷ���û���Ϣ
        cout<<"add registers successfully!"<<endl;
    }
}

///�鱾���

void Option::AddBook()//����Ա�ͳ�������Ա���Խ��е��鱾���
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

void Option::AddManyBooks(int Size)//����Ա�ͳ�������Ա���Խ��ж��鱾���
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

//�鱾ɾ��

void Option::falseDeleteBook(book *Book)//�鱾αɾ��
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

void Option::trueDeleteBook(book *Book)//�鱾��ɾ��
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function��";
    }
    else
    {
        trueDeleteBookbyId(fileBookName,Book,searchInstanceOfBook(Book->bookId,fileBookName));
    }
}

///�鱾����
void Option::updateBookAll(book *Book)  //�����޸��鱾��Ϣ
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookAll)��";
    }
    else
    {
        updateBook(fileBookName,Book);
    }

}

void Option::updateBookById(book *Book, int BookId)//�������IDֵ
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookById)��";
    }
    else
    {
        updateBookId(fileBookName,Book, BookId);
    }
}

void Option::updateBookPeopleById(book *Book, int PeopleId)//�����鼮������IDֵ
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookPeopleById)��";
    }
    else
    {
        updateBookPeopleId(fileBookName, Book, PeopleId);
    }
}

void Option::updateBookByClass(book *Book, int BookClass)//����������
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByClass)��";
    }
    else
    {
        updateBookClass(fileBookName, Book, BookClass);
    }
}

void Option::updateBookByPrice(book *Book, float Price)//������ļ۸�
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByPrice)��";
    }
    else
    {
        updateBookPrice(fileBookName, Book, Price);
    }
}

void Option::updateBookByName( book *Book, char *Name)//��������
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByName)��";
    }
    else
    {
        updateBookName(fileBookName, Book, Name);
    }
}

void Option::updateBookByPublisher(book *Book, char *Publisher)//������ĳ�����
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByPublisher)��";
    }
    else
    {
        updateBookPublisher(fileBookName, Book, Publisher);
    }
}

void Option::updateBookByAuthor(book *Book, char *Author)//�����������
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByAuthor)��";
    }
    else
    {
        updateBookAuthor(fileBookName, Book, Author);
    }
}

void Option::updateBookByPublishDate(book *Book, char *PublishDate)//������ĳ�������
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByPublishDate)��";
    }
    else
    {
        updateBookPublishDate(fileBookName, Book, PublishDate);
    }
}

void Option::updateBookByBorrowTime(book *Book, char *BorrowTime)//���Ľ���ʱ��
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByBorrowTime)��";
    }
    else
    {
        updateBookBorrowTime(fileBookName, Book, BorrowTime);
    }
}
//�������״̬��Ϣ
void Option::updateBookByBorrowFlag(book *Book,char BorrowFlag)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function(updateBookByBorrowFlag)��";
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
        cout<<"You have no right to access this function(updateBookByReservedFlag)��";
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
        cout<<"You have no right to access this function(updateBookByPreservedFlag)��";
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
        cout<<"You have no right to access this function(updateBookByLatedFlag)��";
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
        cout<<"You have no right to access this function(updateBookByDeletedFlag)��";
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
        cout<<"You have no right to access this function(updateBookByRealDeletedFlag)��";
    }
    else
    {
        updateBookRealDeletedFlag(fileBookName, Book, RealDeletedFlag);
    }
}



///�鼮��ѯ

//������չʾ�����鼮
void Option::searchAllBook()
{
    searchAllBooks(fileBookName);
}
//����Ų�ѯ�鼮��Ϣ
void Option::searchBookId(unsigned int bookId)
{
    searchBookById(bookId,fileBookName);
}
//����������Ų�ѯ�鼮��Ϣ
void Option::searchBookPeopleId(unsigned int peopleId)
{
    searchBookByPeopleId(peopleId,fileBookName);
}
//���鼮����ѯ�鼮��Ϣ
void Option::searchBookClass(int bookClass)
{
    searchBookByClass(bookClass,fileBookName);
}
//���۸� �����ѯ�鼮��Ϣ
void Option::searchBookPrice(float price1, float price2)
{
    searchBookByPrice(price1, price2,fileBookName);
}
//�����ֲ�ѯ�鼮��Ϣ
void Option::searchBookName(char name[20])
{
    searchBookByName(name,fileBookName);
}
//���������ѯ�鼮��Ϣ
void Option::searchBookPublisher(char publisher[20])
{
    searchBookByPublisher(publisher,fileBookName);
}
//�����߲�ѯ�鼮��Ϣ
void Option::searchBookAuthor(char author[8])
{
    searchBookByAuthor(author,fileBookName);
}
//���������ڲ�ѯ�鼮��Ϣ
void Option::searchBookPublishDate(char publishDate[8])
{
    searchBookByPublishDate(publishDate,fileBookName);
}
//��������ڲ�ѯ�鼮��Ϣ
void Option::searchBookBorrowTime(char borrowTime[10])
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function��";
    }
    else
    {
        searchBookByBorrowTime(borrowTime,fileBookName);
    }
}



///-------------------�û�����------------------------------

///����û�
void Option::AddPeople()
{
     if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
    }
    else
    {
        addPeople(Size,filePeopleName);

    }

}

///αɾ������ɾ���û�
void Option::falseDeletePeople(people *People)
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
    }
    else
    {
        trueDeletePeoplebyId(filePeopleName,People);
    }

}

///�û���Ϣ�޸�

void Option::updatePeopleAll(people *People)//�����޸��û���Ϣ
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
    }
    else
    {
        updatePeopleDeleted(filePeopleName.c_str(),People,IsDeleted);
    }
}



///�û���Ϣ��ѯ
void Option::searchAllPersons()
{
    if(p->level<ManagerLevel)
    {
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
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
        cout<<"You have no right to access this function��";
    }
    else
    {
        searchPeopleByCredit(credit,filePeopleName);
    }
}




