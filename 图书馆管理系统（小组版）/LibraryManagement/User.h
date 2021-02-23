#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "bookClass.h"
#include "Option.h"
#define MAX_BORROW 10//一个用户最大借阅书籍数量
#define MAX_RECENT_BORROW 20//存储最大历史借阅书籍数量
#pragma once
#define MAX_NAME 20//最大用户姓名字节数
#define MAX_PASSWORD 10//最大用户密码字节数
#define SubCredit_LOST 10//丢失-10
#define MAX_ORDER_DAY 7 //预约最大期限
#define MAX_BORROW_DAY 30//每本书最多可借30天

class User
{
private:
    people People;//用户信息
    Option option;//操作类(增删查改)
    int numBooksRecent = 0;//历史借阅书籍数量
    int numBooksBorrowed = 0;//已借书数量
    int maxBooksBorrowed = 0;//最高可借书数量
    bool onlineState;//用户登录状态
public:


///构造函数
    User(people PEOPLE_IN,string fileBookName_in,string filePeopleName_in);
    User(){
        this->onlineState = 0;
    }
    User(const User &temp){//copy creator
        this->People = temp.People;
        this->option = temp.option;
        this->numBooksBorrowed = 0;
        this->numBooksRecent = 0;
        this->maxBooksBorrowed = 0;
        this->onlineState = temp.onlineState;
    }

///以下为设置用户信息
    void updateBookWhole(book *Book);//功能描述：整体修改书籍信息
    void updatePeopleWhole(people *People);//功能描述：整体修改用户信息
    void setRecentBorrowId(int recentBorrowId,int index);//功能描述：部分设置用户最近借阅书籍第index本的id值
    void setBooksBorrowed(int booksBorrowedId,int index);//功能描述：部分设置用户已经借阅书籍第index本的id值
    void AddRecentBorrowId(int recentBorrowId);//功能描述：增加用户已经借阅书籍
    void AddBooksBorrowed(int booksBorrowedId);//功能描述：增加用户已经借阅书籍
    void DeleteRecentBorrowId(int recentBorrowId);//功能描述：从用户最近借阅书籍删除为recentBorrowId值的记录
    void DeleteBooksBorrowed(int booksBorrowedId);//功能描述：从用户已经借阅书籍删除为booksBorrowedId值的记录
    void setOnlineState(int state);
    void setPeopleId(int peopleId);
    void setLevel(int level);
    void setCredit(int credit);
    void setPeopleName(char *name);
    void setPassword(char *password);
    void setIsDeleted(char isDelete);
    void setIsRealDeleted(char isRealDelete);
    void setNumBooksRecent(int numBooksRecent);//功能描述：设置用户历史借阅书籍数量
    void setNumBooksBorrowed(int numBooksBorrowed);//功能描述：设置用户已借书数量
    void setMaxBooksBorrowed();//功能描述：设置用户最高可借书数量



///以下为返回用户信息
    bool getOnlineState();//返回用户在线状态信息
    int getPeopleId();//功能描述：返回用户id
    int getLevel(); //功能描述：返回用户等级;
    int getCredit(); //功能描述：返回用户信用点
    string getPeopleName();//功能描述：返回用户姓名
    int getRecentBorrowId(int index); //功能描述：返回用户历史借阅书籍第index本的书本id值
    int getBooksBorrowed(int index); //功能描述：返回用户目前借阅书籍第index本的书本id值;参数
    int getBooksBorrowedIndex(int bookId);//功能描述：返回用户目前借阅书籍号为bookId的书本在booksBorrowed数组的下标值
    string getPassword();//功能描述：获得用户密码;参数：空；返回值：string；调用：无：
    int getNumBooksBorrowed();//功能描述：返回用户已经借阅书籍数量
    int getMaxBooksBorrowed(); //功能描述：返回用户最大借阅书籍数量
    char getIsDeleted(); //功能描述：返回该用户是否被伪删除状态信息
    char getIsRealDeleted();//功能描述：返回该用户是否被真删除状态信息
    float getPunishmentMoney();//返回罚款金额
    Option getOptionClass();//返回操作类
    people getPeopleClass();//返回用户类
    bool getPeopleStatue();
    void showUserInfo(); ///功能描述:展示用户信息



///以下为根据用户等级可进行具体图书操作功能

//---------------------------借书,还书,预约,续借基本功能------------------------

    void borrowBooks(book *Book);///功能描述：用户从书库借书

    void returnBooks(book *Book);///功能描述:用户还书

    void orderBooks(book *Book);///功能描述:用户预约借书,预约时间不超过7天

    void continueBorrow(book *Book);///功能描述:续借

    bool login(book *Book,int mode);///功能描述:返回该用户与服务器的连接状态,当用户登陆成功，自动计算credit，若超期一天，-1

    void logout();///功能描述:返回该用户与服务器的连接状态

    void ReportLoss(book *Book);///功能描述:挂失；


};
#endif // USER
