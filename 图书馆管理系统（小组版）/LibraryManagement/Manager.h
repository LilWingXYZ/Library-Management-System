#pragma once
#ifndef MANAGER
#define MANAGER

#include "User.h"


class Manager:public User
{
private:
    int totalNumBooks;//书库总数量
    int totalNumPeople;//借阅总人数
    int totalBorrowedBooks;//借出书籍数量
public:
    Manager(people PEOPLE_IN,string fileBookName_in,string filePeopleName_in):User(PEOPLE_IN,fileBookName_in,filePeopleName_in)
    {
        setLevel(ManagerLevel);//用户等级为管理员

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
