#pragma once
#ifndef UPDATEOPTION_H_INCLUDED
#define UPDATEOPTION_H_INCLUDED
#include<iostream>
#include<fstream>
#include<cstring>
#define maxBytes_1 45//书名最大字节数
#define maxBytes_2 5//出版年份最大字节数
#define maxBytes_3 11//borrowTime最大字节数
#define maxBytes_4 20//最近借阅书籍编号最大字节数
#define maxBytes_5 20//peopleName最大字节数
#define maxBytes_6 10//password最大字节数
#define maxBytes_7 25//作者,出版社最大字节数
#define maxBytes_8 10//已经借阅的书籍最大字节数
#include "IdGenerator.h"
#include "SearchOption.h"
#include <iomanip>
#include "windows.h"
using namespace std;


inline bool updateBook(string filename, book *Book){//除bookId号进行整体修改
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值

}


//修改书籍编号(bookId)

inline bool updateBookId(string filename, book *Book, int BookId)
{
    if(!idTest(BookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->bookId = BookId;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值
}
//修改借书人编号(peopleId)
inline bool updateBookPeopleId(string filename, book *Book, int PeopleId)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->peopleId = PeopleId;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值



}

//修改书籍分类(bookClass)

inline bool updateBookClass(string filename, book *Book, int BookClass)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->bookClass = BookClass;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值


}

//修改书籍价格(price)


inline bool updateBookPrice(string filename, book *Book, float Price)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->price = Price;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值

}

//修改书籍名称(name)

inline bool updateBookName(string filename, book *Book, char *Name)
{
    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(Name) <= maxBytes_1)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        strcpy(Book->bookName, Name);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
        cout << "编号" << Book->bookId << "的信息修改成功" << endl;
        return true;//返回修改值

    }

    return false;//否则修改失败

}



//修改书籍出版社(publisher)

inline bool updateBookPublisher(string filename, book *Book, char *Publisher)
{
    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(Publisher) <= maxBytes_7)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        strcpy(Book->publisher, Publisher);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
        cout << "编号" << Book->bookId << "的信息修改成功" << endl;
        return true;//返回修改值

    }

    return false;//否则修改失败

}

//修改书籍作者(author)

inline bool updateBookAuthor(string filename, book *Book, char *Author)
{

    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(Author) <= maxBytes_7)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        strcpy(Book->author, Author);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
        cout <<endl<<setw(29)<< "编号" << Book->bookId << "的信息修改成功" << endl;
        Sleep(2000);
        return true;//返回修改值

    }
    return false;//否则修改失败
}

//修改书籍出版年份(publishDate)

inline bool updateBookPublishDate(string filename, book *Book, char *PublishDate)
{

    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(PublishDate) <= maxBytes_2)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        strcpy(Book->publishDate, PublishDate);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
        cout <<endl<<setw(29)<< "编号" << Book->bookId << "的信息修改成功" << endl;
        Sleep(2000);
        return true;//返回修改值

    }

    return false;//否则修改失败


}

//修改书籍借出时间(borrowTime)

inline bool updateBookBorrowTime(string filename, book *Book, char *BorrowTime)
{

    if(!idTest(Book->bookId,filename)) return false;
    if (sizeof(BorrowTime) <= maxBytes_3)
    {

        int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        strcpy(Book->borrowTime, BorrowTime);
        BookClassIO bm;
        bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
        cout << "编号" << Book->bookId << "的信息修改成功" << endl;
        return true;//返回修改值

    }

    return false;//否则修改失败


}

//修改借出标志位(borrowFlag)

inline bool updateBookBorrowFlag(string filename, book *Book, char BorrowFlag)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->borrowFlag = BorrowFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值

}

//修改预定标志位（isReservedFlag）

inline bool updateBookReservedFlag(string filename, book *Book, char ReservedFlag)
{

    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->isReservedFlag = ReservedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值

}


//修改保存本标志位(isPreservedFlag)

inline bool updateBookPreservedFlag(string filename, book *Book, char PreservedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->isPreservedFlag = PreservedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值
}

//修改逾期标志位(isLated)

inline bool updateBookLatedFlag(string filename, book *Book, char LatedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->isLated = LatedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值
}

//修改删除标志位(isDeleted)

inline bool updateBookDeletedFlag(string filename, book *Book, char DeletedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->isDeleted = DeletedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值
}
//修改真删除标志位（isRealDeleted）
inline bool updateBookRealDeletedFlag(string filename, book *Book, char RealDeletedFlag)
{
    if(!idTest(Book->bookId,filename)) return false;
    //distance查找失败信息
    int distance = searchInstanceOfBook(Book->bookId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    Book->isRealDeleted = RealDeletedFlag;
    BookClassIO bm;
    bm.writeFile(*Book, filename, distance, 2); //调用BookClassIO类的writeFile函数，更新信息
    cout << "编号" << Book->bookId << "的信息修改成功" << endl;
    return true;//返回修改值
}



//以上为book修改
//-----------------------------------------------------------------------------------
//以下为people修改

inline bool updatePeople(string filename,people *People)//除peopleId外进行整体修改
{


    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    //distance查找失败信息
    int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
    cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
    return true;//返回修改值

}


//修改借书人编号(peopleId)
inline bool updatePeopleId(string filename,people *People,int PeopleId)
{


    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    //distance查找失败信息
    int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    People->peopleId = PeopleId;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
    cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
    return true;//返回修改值

}

//修改最近借阅书籍编号(recentBorrowId)

inline bool updatePeopleRecentBorrowId(string filename,people *People,int RecentBorrowId[20],int numArray)//numArray为传入数组大小，由于在子函数内无法求出其大小
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    //distance查找失败信息
    if(numArray <= maxBytes_4)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        //People->recentBorrowId = RecentBorrowId;
        memcpy(People->recentBorrowId,RecentBorrowId,20);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
        cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
        return true;//返回修改值

    }

    return false;//否则修改失败

}

//修改已经借阅的书籍编号(peoplesBorrowed)

inline bool updatePeoplePeoplesBorrowed(string filename,people *People,int *PeoplesBorrowed,int numArray)//numArray为传入数组大小，由于在子函数内无法求出其大小
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    if(numArray <= maxBytes_8)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        //Book->booksBorrowed = PeoplesBorrowed;
        memcpy(People->recentBorrowId,PeoplesBorrowed,10);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
        cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
        return true;//返回修改值

    }

    return false;//否则修改失败

}

//修改用户密码(password)

inline bool updatePeoplePassword(string filename,people *People,char *Password)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    if(sizeof(Password)<= maxBytes_6)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        strcpy(People->password,Password);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
        cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
        return true;//返回修改值

    }

    return false;//否则修改失败

}

//修改借书人级别(level)

inline bool updatePeopleLevel(string filename,people *People,int Level)
{
    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    People->level = Level;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
    cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
    return true;//返回修改值

}

//修改借书人信用点(credit)

inline bool updatePeopleCredit(string filename,people *People,int Credit)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    People->credit = Credit;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
    cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
    return true;//返回修改值

}

//修改借书人姓名(peopleName)

inline bool updatePeopleName(string filename,people *People,char *PeopleName)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    if(sizeof(PeopleName)<= maxBytes_5)
    {

        int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
        if (distance < 0)
        {
            cout << "修改失败!" << endl;
            return false;
        }
        strcpy(People->peopleName,PeopleName);
        ReaderClassIO pm;
        pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
        cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
        return true;//返回修改值

    }

    return false;//否则修改失败

}

//修改该用户删除标志位(isDeleted)

inline bool updatePeopleDeleted(string filename,people *People,char IsDeleted)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    People->isDeleted = IsDeleted;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
    cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
    return true;//返回修改值

}


//修改该用户真删除标志位(isRealDeleted)

inline bool updatePeopleRealDeleted(string filename,people *People,char IsRealDeleted)
{

    if(People->isDeleted == '1'||People->isRealDeleted == '1')
    {
        cout << "数据不存在" << endl;
        return false;
    }
    int distance = searchInstanceOfPeople(People->peopleId,filename);//根据查询函数定位Book在文件中的位置
    if (distance < 0)
    {
        cout << "修改失败!" << endl;
        return false;
    }
    People->isRealDeleted = IsRealDeleted;
    ReaderClassIO pm;
    pm.writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
    cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
    return true;//返回修改值

}

/*


int main()
{
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book bookArray[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int state = bm.readFile(bookArray, fname, 0, 2); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    cout << "STATE:" << state << endl;
    for (int i = 0; i < 10; i++)
    {

        cout << "编号NO." << bookArray[i].bookId << endl;
        cout << "借书人编号:" << bookArray[i].peopleId << endl;
        cout << "分类：" << bookArray[i].bookClass << endl;
        cout << "价格：" << bookArray[i].price << endl;
        cout << "书名：" << bookArray[i].bookName << endl;
        cout << "出版社：" << bookArray[i].publisher << endl;
        cout << "作者：" << bookArray[i].author << endl;
        cout << "出版日期：" << bookArray[i].publishDate << endl;
        cout << "借出时间：" << bookArray[i].borrowTime << endl;
        cout << "借出：" << bookArray[i].borrowFlag << endl;
        cout << "预定：" << bookArray[i].isReservedFlag << endl;
        cout << "保存本：" << bookArray[i].isPreservedFlag << endl;
        cout << "逾期：" << bookArray[i].isDeleted << endl;
        cout << "删除：" << bookArray[i].isDeleted << endl;
        cout << "----------------------------------------" << endl;
    }

    //以下为修改测试内容

    cout << "修改第一本书的分类，书名，借出标志位" << endl;
    cout << "输入修改书的分类：" << endl;
    int BookClass;
    cin >> BookClass;
    updateBookClass(fname, &bookArray[1], BookClass);

    cout << "输入修改的书名：" << endl;
    char BookName[20];
    cin >> BookName;
    updateBookName(fname, &bookArray[1], BookName);

    cout << "输入修改的借出标志位：" << endl;
    int BorrowFlag;
    cin >> BorrowFlag;
    updateBookClass(fname, &bookArray[1], BorrowFlag);

    cout << endl;
    cout << "第一本书修改后的信息:" << endl;
    cout << endl;


    cout << "编号NO." << bookArray[1].bookId << endl;
    cout << "借书人编号:" << bookArray[1].peopleId << endl;
    cout << "分类：" << bookArray[1].bookClass << endl;
    cout << "价格：" << bookArray[1].price << endl;
    cout << "书名：" << bookArray[1].bookName << endl;
    cout << "出版社：" << bookArray[1].publisher << endl;
    cout << "作者：" << bookArray[1].author << endl;
    cout << "出版日期：" << bookArray[1].publishDate << endl;
    cout << "借出时间：" << bookArray[1].borrowTime << endl;
    cout << "借出：" << bookArray[1].borrowFlag << endl;
    cout << "预定：" << bookArray[1].isReservedFlag << endl;
    cout << "保存本：" << bookArray[1].isPreservedFlag << endl;
    cout << "逾期：" << bookArray[1].isDeleted << endl;
    cout << "删除：" << bookArray[1].isDeleted << endl;
    return 0;
}
*/
#endif // UPDATEOPTION_H_INCLUDED

