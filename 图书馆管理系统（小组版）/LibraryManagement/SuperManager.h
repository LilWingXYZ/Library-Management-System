#pragma once
#ifndef SUPERMANAGER
#define SUPERMANAGER
#include "Manager.h"
#define SuperManagerManagerLevel 2
class SuperManager:public Manager
{
private:
    int totalNumManager;//书库总数量
public:
    SuperManager(people PEOPLE_IN,string fileBookName_in,string filePeopleName_in):Manager(PEOPLE_IN,fileBookName_in,filePeopleName_in)
    {
        setLevel(SuperManagerManagerLevel);//用户等级为管理员

    }
    void setTotalManager(int numManager);
    void getTotalNumManager();
    void ForcedOffline(User *user);//使用户或者管理员强制下线,user->level<SuperManagerManagerLevel,user->logout()
    void addUser();
    void updateUserInfo();
    void searchUser();
    void deleteUser();
    void recoverCredit();
    void recoverDeletedUser();
    float sumMoney();// to see how much money used
    void addBook();
    void updateBookInfo();
    void searchBook();
    void deleteBook();
    void recoverDeletedBook();
    void recoverLost();
};
#endif // SUPERMANAGER
