#pragma once
#ifndef MANAGER
#define MANAGER

#include "User.h"


class Manager:public User
{
private:
    int totalNumBooks;//���������
    int totalNumPeople;//����������
    int totalBorrowedBooks;//����鼮����
public:
    Manager(people PEOPLE_IN,string fileBookName_in,string filePeopleName_in):User(PEOPLE_IN,fileBookName_in,filePeopleName_in)
    {
        setLevel(ManagerLevel);//�û��ȼ�Ϊ����Ա

    }
    void setTotalNumBooks(int numBooks);
    void setTotalNumPeople(int numPeople);
    void setTotalBorrowedBooks(int numBorrowedBook);
    void getTotalNumBooks();
    void getTotalNumPeople();
    void getTotalBorrowedBooks();
    void showCurrentLibraryInfo();
};
#endif // MANAGER
