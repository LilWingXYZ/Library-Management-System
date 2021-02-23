#pragma once
#ifndef UPDATEOPTION_H_INCLUDED
#define UPDATEOPTION_H_INCLUDED
#include<iostream>
#include<fstream>
#include<cstring>
#define maxBytes_1 45//��������ֽ���
#define maxBytes_2 5//�����������ֽ���
#define maxBytes_3 11//borrowTime����ֽ���
#define maxBytes_4 20//��������鼮�������ֽ���
#define maxBytes_5 20//peopleName����ֽ���
#define maxBytes_6 10//password����ֽ���
#define maxBytes_7 25//����,����������ֽ���
#define maxBytes_8 10//�Ѿ����ĵ��鼮����ֽ���
#include "IdGenerator.h"
#include "SearchOption.h"
#include <iomanip>
#include "windows.h"
using namespace std;


inline bool updateBook(string filename, book *Book){//��bookId�Ž��������޸�
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ

}


//�޸��鼮���(bookId)

inline bool updateBookId(string filename, book *Book, int BookId)
{
    if(!idTest(BookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->bookId = BookId;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ
}
//�޸Ľ����˱��(peopleId)
inline bool updateBookPeopleId(string filename, book *Book, int PeopleId)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->peopleId = PeopleId;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ



}

//�޸��鼮����(bookClass)

inline bool updateBookClass(string filename, book *Book, int BookClass)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->bookClass = BookClass;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ


}

//�޸��鼮�۸�(price)


inline bool updateBookPrice(string filename, book *Book, float Price)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->price = Price;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ

}

//�޸��鼮����(name)

inline bool updateBookName(string filename, book *Book, char *Name)
{
    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(Name) <= maxBytes_1)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        strcpy(Book->bookName, Name);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
        cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��

}



//�޸��鼮������(publisher)

inline bool updateBookPublisher(string filename, book *Book, char *Publisher)
{
    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(Publisher) <= maxBytes_7)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        strcpy(Book->publisher, Publisher);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
        cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��

}

//�޸��鼮����(author)

inline bool updateBookAuthor(string filename, book *Book, char *Author)
{

    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(Author) <= maxBytes_7)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        strcpy(Book->author, Author);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
        cout <<endl<<setw(29)<< "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
        Sleep(2000);
        return true;//�����޸�ֵ

    }
    return false;//�����޸�ʧ��
}

//�޸��鼮�������(publishDate)

inline bool updateBookPublishDate(string filename, book *Book, char *PublishDate)
{

    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(PublishDate) <= maxBytes_2)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        strcpy(Book->publishDate, PublishDate);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
        cout <<endl<<setw(29)<< "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
        Sleep(2000);
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��


}

//�޸��鼮���ʱ��(borrowTime)

inline bool updateBookBorrowTime(string filename, book *Book, char *BorrowTime)
{

    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(BorrowTime) <= maxBytes_3)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        strcpy(Book->borrowTime, BorrowTime);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
        cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��


}

//�޸Ľ����־λ(borrowFlag)

inline bool updateBookBorrowFlag(string filename, book *Book, char BorrowFlag)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->borrowFlag = BorrowFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ

}

//�޸�Ԥ����־λ��isReservedFlag��

inline bool updateBookReservedFlag(string filename, book *Book, char ReservedFlag)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->isReservedFlag = ReservedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ

}


//�޸ı��汾��־λ(isPreservedFlag)

inline bool updateBookPreservedFlag(string filename, book *Book, char PreservedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->isPreservedFlag = PreservedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ
}

//�޸����ڱ�־λ(isLated)

inline bool updateBookLatedFlag(string filename, book *Book, char LatedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->isLated = LatedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ
}

//�޸�ɾ����־λ(isDeleted)

inline bool updateBookDeletedFlag(string filename, book *Book, char DeletedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->isDeleted = DeletedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ
}
//�޸���ɾ����־λ��isRealDeleted��
inline bool updateBookRealDeletedFlag(string filename, book *Book, char RealDeletedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfBook(Book->bookId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    Book->isRealDeleted = RealDeletedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //����BookClassIO���writeFile������������Ϣ
    cout << "���" << Book->bookId << "����Ϣ�޸ĳɹ�" << endl;
    return true;//�����޸�ֵ
}



//����Ϊbook�޸�
//-----------------------------------------------------------------------------------
//����Ϊpeople�޸�

inline bool updatePeople(string filename,people *People)//��peopleId����������޸�
{


    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
    cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
    return true;//�����޸�ֵ

}


//�޸Ľ����˱��(peopleId)
inline bool updatePeopleId(string filename,people *People,int PeopleId)
{


    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    //distance����ʧ����Ϣ
    int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    People->peopleId = PeopleId;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
    cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
    return true;//�����޸�ֵ

}

//�޸���������鼮���(recentBorrowId)

inline bool updatePeopleRecentBorrowId(string filename,people *People,int RecentBorrowId[20],int numArray)//numArrayΪ���������С���������Ӻ������޷�������С
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    //distance����ʧ����Ϣ
    if(numArray <= maxBytes_4)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        //People->recentBorrowId = RecentBorrowId;
        memcpy(People->recentBorrowId,RecentBorrowId,20);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
        cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��

}

//�޸��Ѿ����ĵ��鼮���(peoplesBorrowed)

inline bool updatePeoplePeoplesBorrowed(string filename,people *People,int *PeoplesBorrowed,int numArray)//numArrayΪ���������С���������Ӻ������޷�������С
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    if(numArray <= maxBytes_8)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        //Book->booksBorrowed = PeoplesBorrowed;
        memcpy(People->recentBorrowId,PeoplesBorrowed,10);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
        cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��

}

//�޸��û�����(password)

inline bool updatePeoplePassword(string filename,people *People,char *Password)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    if(sizeof(Password)<= maxBytes_6)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        strcpy(People->password,Password);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
        cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��

}

//�޸Ľ����˼���(level)

inline bool updatePeopleLevel(string filename,people *People,int Level)
{
    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    People->level = Level;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
    cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
    return true;//�����޸�ֵ

}

//�޸Ľ��������õ�(credit)

inline bool updatePeopleCredit(string filename,people *People,int Credit)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    People->credit = Credit;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
    cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
    return true;//�����޸�ֵ

}

//�޸Ľ���������(peopleName)

inline bool updatePeopleName(string filename,people *People,char *PeopleName)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    if(sizeof(PeopleName)<= maxBytes_5)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
        if (distance < 0)
        {
            cout << "�޸�ʧ��!" << endl;
            return false;
        }
        strcpy(People->peopleName,PeopleName);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
        cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
        return true;//�����޸�ֵ

    }

    return false;//�����޸�ʧ��

}

//�޸ĸ��û�ɾ����־λ(isDeleted)

inline bool updatePeopleDeleted(string filename,people *People,char IsDeleted)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    People->isDeleted = IsDeleted;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
    cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
    return true;//�����޸�ֵ

}


//�޸ĸ��û���ɾ����־λ(isRealDeleted)

inline bool updatePeopleRealDeleted(string filename,people *People,char IsRealDeleted)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "���ݲ�����" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//���ݲ�ѯ������λBook���ļ��е�λ��
    if (distance < 0)
    {
        cout << "�޸�ʧ��!" << endl;
        return false;
    }
    People->isRealDeleted = IsRealDeleted;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
    cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
    return true;//�����޸�ֵ

}

/*


int main()
{
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book bookArray[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int state = bm.readFile(bookArray, fname, 0, 2); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    cout << "STATE:" << state << endl;
    for (int i = 0; i < 10; i++)
    {

        cout << "���NO." << bookArray[i].bookId << endl;
        cout << "�����˱��:" << bookArray[i].peopleId << endl;
        cout << "���ࣺ" << bookArray[i].bookClass << endl;
        cout << "�۸�" << bookArray[i].price << endl;
        cout << "������" << bookArray[i].bookName << endl;
        cout << "�����磺" << bookArray[i].publisher << endl;
        cout << "���ߣ�" << bookArray[i].author << endl;
        cout << "�������ڣ�" << bookArray[i].publishDate << endl;
        cout << "���ʱ�䣺" << bookArray[i].borrowTime << endl;
        cout << "�����" << bookArray[i].borrowFlag << endl;
        cout << "Ԥ����" << bookArray[i].isReservedFlag << endl;
        cout << "���汾��" << bookArray[i].isPreservedFlag << endl;
        cout << "���ڣ�" << bookArray[i].isDeleted << endl;
        cout << "ɾ����" << bookArray[i].isDeleted << endl;
        cout << "----------------------------------------" << endl;
    }

    //����Ϊ�޸Ĳ�������

    cout << "�޸ĵ�һ����ķ��࣬�����������־λ" << endl;
    cout << "�����޸���ķ��ࣺ" << endl;
    int BookClass;
    cin >> BookClass;
    updateBookClass(fname, &bookArray[1], BookClass);

    cout << "�����޸ĵ�������" << endl;
    char BookName[20];
    cin >> BookName;
    updateBookName(fname, &bookArray[1], BookName);

    cout << "�����޸ĵĽ����־λ��" << endl;
    int BorrowFlag;
    cin >> BorrowFlag;
    updateBookClass(fname, &bookArray[1], BorrowFlag);

    cout << endl;
    cout << "��һ�����޸ĺ����Ϣ:" << endl;
    cout << endl;


    cout << "���NO." << bookArray[1].bookId << endl;
    cout << "�����˱��:" << bookArray[1].peopleId << endl;
    cout << "���ࣺ" << bookArray[1].bookClass << endl;
    cout << "�۸�" << bookArray[1].price << endl;
    cout << "������" << bookArray[1].bookName << endl;
    cout << "�����磺" << bookArray[1].publisher << endl;
    cout << "���ߣ�" << bookArray[1].author << endl;
    cout << "�������ڣ�" << bookArray[1].publishDate << endl;
    cout << "���ʱ�䣺" << bookArray[1].borrowTime << endl;
    cout << "�����" << bookArray[1].borrowFlag << endl;
    cout << "Ԥ����" << bookArray[1].isReservedFlag << endl;
    cout << "���汾��" << bookArray[1].isPreservedFlag << endl;
    cout << "���ڣ�" << bookArray[1].isDeleted << endl;
    cout << "ɾ����" << bookArray[1].isDeleted << endl;
    return 0;
}
*/
#endif // UPDATEOPTION_H_INCLUDED

