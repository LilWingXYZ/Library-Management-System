#pragma once
#ifndef SEARCHOPTION_H_INCLUDED
#define SEARCHOPTION_H_INCLUDED
#include "BookManagementIO.h"
#include "StdIO.h"
#include <iomanip>
using namespace std;
//---------------书本函数声明------------------------------
void displayBooks(book ret);//展示
int countSameBooks(unsigned int hashNum,string fname);//计算机“同一本书”有多少本，用以设计序号
void searchAllBooks(string fname);//无条件展示所有书籍
void searchBookById(unsigned int bookId,string fname);//按书号查询书籍信息
void searchBookByPeopleId(unsigned int peopleId,string fname);//按借书人序号查询书籍信息
void searchBookByClass(int bookClass,string fname);//按书籍类别查询书籍信息
void searchBookByPrice(float price1, float price2,string fname); //按价格 区间查询书籍信息
void searchBookByName(char name[45],string fname);//按名字查询书籍信息
void searchBookByPublisher(char publisher[25],string fname);//按出版社查询书籍信息
void searchBookByAuthor(char author[25],string fname);//按作者查询书籍信息
void searchBookByPublishDate(char publishDate[5],string fname);//按出版日期查询书籍信息
void searchBookByBorrowTime(char borrowTime[11],string fname);//按借出日期查询书籍信息
int  searchInstanceOfBook(unsigned int bookId,string fname);//查询书号来返回某本书在文件里的distance


//-----------------用户函数声明------------------------------
void displayPeople(people ret);
void searchAllPeople(string fname);
void searchPeopleById(unsigned int peopleId,string fname);
void searchPeopleByLevel(int level,string fname);
void searchPeopleByCredit(int credit,string fname);
int  searchInstanceOfPeople(unsigned int peopleId,string fname);

//*********************************辅助函数*************************************
inline void displayBooks(book ret)
{
        StdIO io;
        if(ret.bookId != 0){
                if(ret.isLated == '1') io.setColor(io.enmCFC_Red,io.enmCBC_Black);
                else if(ret.borrowFlag == '1' || ret.isPreservedFlag == '1' || ret.isReservedFlag == '1') io.setColor(io.enmCFC_Yellow,io.enmCBC_Black);
                else io.setColor(io.enmCFC_Green,io.enmCBC_Black);
                cout <<endl;
                cout <<"书籍编号:                " << ret.bookId  << endl;
                cout <<"最近租借本书用户编号:    " << ret.peopleId  << endl;
                cout <<"书籍类别:                " << ret.bookClass  << endl;
                cout <<"价格:                    " << ret.price  << endl;
                cout <<"书名:                    " << ret.bookName  << endl;
                cout <<"出版社:                  " << ret.publisher  << endl;
                cout <<"作者:                    " << ret.author  << endl;
                cout <<"出版日期:                " << ret.publishDate  << endl;
                cout <<"借出日期:                " << ret.borrowTime  << endl;
                cout <<"是否被借出:              " << ret.borrowFlag  << endl;
                cout <<"是否被预约:              " << ret.isReservedFlag  << endl;
                cout <<"是否保存本:              " << ret.isPreservedFlag  << endl;
                cout <<"是否逾期未还:            " << ret.isLated  << endl;
                cout <<"是否在馆藏序列中:        " << ret.isDeleted  << endl;
                io.setColor();
        }
}
inline int countSameBooks(unsigned int hashNum,string fname)//hashNum = class+hashnumber
{

        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int countB = 0;
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if( (hashNum == (ret[i].bookId/100) )&&( ret[i].isRealDeleted == '0'))
                                {
                                        countB++;
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        return countB;
}

//*********************************辅助函数*************************************

//------------------------------book的查询函数------------------------------------
inline void searchAllBooks(string fname) //无条件展示所有书籍
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4 || state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++)
                        {
                                displayBooks(ret[i]);//展示当前书籍数据
                                distance++;//记录查过的书的数目
                        }

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ! ." << endl;
                }
        }
}
inline int getBook(unsigned int bookId,string fname,book* Book){
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (bookId == ret[i].bookId)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : " << bookId << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        *Book = ret[i];
                                        return 0;
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                        return -1;
                }
        }
        cout <<endl<<setw(47)<< "我找不到这个书籍编号啊啊啊啊~ QAQ!" << endl;
        return -1;


}
inline void searchBookById(unsigned int bookId,string fname) //按书号查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (bookId == ret[i].bookId)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 书籍编号————" << bookId << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        return;
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        cout <<endl<<setw(47)<< "我找不到这个书籍编号啊啊啊啊~ QAQ!" << endl;
}

inline void searchBookByPeopleId(unsigned int peopleId,string fname) //按借书人序号查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (peopleId == ret[i].peopleId)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 借书者编号————" << peopleId << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
                cout <<endl<<setw(47)<< "我找不到这个用户编号啊啊啊啊~ QAQ!" << endl;
        }
}
inline void searchBookByClass(int bookClass,string fname) //按书籍类别查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (bookClass == ret[i].bookClass)
                                {
                                       cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 类别————" << bookClass << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(55)<< "我找不到这个类别的书籍啊啊啊啊~ QAQ!  " << endl;
        }
}
inline void searchBookByPrice(float price1, float price2,string fname) //按价格区间查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (ret[i].price <= price2 && ret[i].price >= price1)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 价格————" <<  price1 << " ~ " << price2 << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
                cout <<endl<<setw(56)<< "我找不到这个价格内的书籍啊啊啊啊~ QAQ!" <<  price1 << " ~ " << price2 << endl;
        }
}
inline void searchBookByName(char name[45],string fname) //按名字查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (strcmp(name, ret[i].bookName) == 0)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 书名————" <<  name << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个
                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(54)<< "我找不到一本叫这个名字的书籍啊啊啊啊~ QAQ!" << endl;
        }
}
inline void searchBookByPublisher(char publisher[25],string fname) //按出版社查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (strcmp(publisher, ret[i].publisher) == 0)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 出版社————" <<  publisher << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(55)<< "我找不到一个叫这个名字的出版社出版的书籍啊啊啊啊~ QAQ!  " << endl;
        }
}

inline void searchBookByAuthor(char author[25],string fname) //按作者查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (strcmp(author, ret[i].author) == 0)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 作者————" <<  author << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(52)<< "我找不到这个这个作者写的书籍啊啊啊啊~ QAQ!  " << endl;
        }
}
inline void searchBookByPublishDate(char publishDate[5],string fname) //按出版日期查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (strcmp(publishDate, ret[i].publishDate) == 0)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 :出版日期———— " <<  publishDate << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(57)<< "我找不到这个日期出版的书籍啊啊啊啊~ QAQ!  " << endl;
                }
}
inline void searchBookByBorrowTime(char borrowTime[11],string fname) //按借出日期查询书籍信息
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (strcmp(borrowTime, ret[i].borrowTime) == 0)
                                {
                                        cout <<endl<< "于瀚海书屋内，终觅此颜如玉 : 借出时间————" <<  borrowTime << endl;
                                        displayBooks(ret[i]);//测试数据，看能找出那本书的数据不
                                        result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十
                }
                else  //如果没成功打开文件
                {
                        cout << "文件竟然打开失败了QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(56)<< "我找不到这个时间被借出去的书籍啊啊啊啊~ QAQ!  " << endl;
        }
}

inline int searchInstanceOfBook(unsigned int bookId,string fname)
{
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        while (distance < (bm.currentFileSize(fname)/sizeof(book))) //当数据没找完时,bm.currentFileSize(fname)为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                if (bookId == ret[i].bookId && ret[i].isRealDeleted!='1')return distance;//找到立刻返回他的distance
                                distance++;//找不到则找下一个
                        }
                        //前面十个找不到的话，再重新循环读十个
                }
                else return -2;//-2 means failed to open this file
        }
        return -1;//-1 means failed to find the record
}
//----------searchBookById-------book的查询函数----------------------------


//-----------------people的查询函数----------------------------//没数据没测试过

inline void displayPeople(people ret){
    StdIO io;
    if(ret.peopleId < 10000) return;
    if(ret.credit<50) io.setColor(io.enmCFC_Yellow,io.enmCBC_Black);
    else if(ret.credit < 20) io.setColor(io.enmCFC_Red,io.enmCBC_Black);
    else if(ret.credit <10) io.setColor(io.enmCFC_Red,io.enmCBC_White);
    cout <<endl;
    cout << "用户编号:                   " <<ret.peopleId<< endl;
    cout << "最近借阅书籍的编号:         " <<ret.recentBorrowId << endl;
    cout << "正在借阅的书籍:             " <<ret.booksBorrowed << endl;
    cout << "密码:                       " <<"**secret**"<< endl;
    cout << "权限级别:                   " <<ret.level << endl;
    cout << "信用点:                     " <<ret.credit << endl;
    cout << "用户名称:                   " <<ret.peopleName << endl;
    cout << "是否不在于用户序列之中:     " <<ret.isDeleted << endl;
    io.setColor();
}

inline void searchAllPeople(string fname){//无条件展示所有用户信息
    ReaderClassIO pm ;
    people ret[10];//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(people)字节的位置
    while(distance < ((pm.currentFileSize(fname)/(sizeof(people))))){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(people)))为当前文件里实体个数
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0 || state == -4){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                    cout << "找到了这位大人的信息(/ω＼) :" << ret[i].peopleId << endl;
                    displayPeople(ret[i]);
                    distance++;//找不到则找下一个
            }

    }else{//如果没成功打开文件
        cout << "文件竟然打开失败了QAQ!" << endl;
    }
    }
}
inline void searchPeopleById(unsigned int peopleId,string fname){
    ReaderClassIO pm ;//定义一个书籍管理类的对象pm = peoplemanage的意思;
    people ret[10];
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int flag = 0;
    while(distance < ((pm.currentFileSize(fname)/(sizeof(book))))){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0 || state == -4){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(peopleId<10000){cout << "这是个非法的输入值呢(/ω＼)" << endl;return;}
                if(peopleId == ret[i].peopleId){
                    cout << "找到了这位大人的信息(/ω＼) :编号————" << peopleId << endl;
                    displayPeople(ret[i]);//测试数据，看能找出那个用户的数据不
                    return;
                }
                distance++;//找不到则找下一个
            }

    }else{//如果没成功打开文件
        cout << "文件竟然打开失败了QAQ!" << endl;
    }
    }
    cout << "我找不到这个编号的用户信息啊啊啊啊~ QAQ!: " << peopleId << endl;
}
// void searchPeopleByRecentBorrowId(unsigned int recentBorrowId[10],string fname);//暂时不考虑
inline void searchPeopleByLevel(int level,string fname){//通过用户等级查询用户信息
    ReaderClassIO pm ;//定义一个书籍管理类的对象pm = peoplemanage的意思;
    people ret[10];
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(people)字节的位置
    while(distance < ((pm.currentFileSize(fname)/(sizeof(people))))){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(people)))为当前文件里实体个数
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0 || state == -4){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(level == ret[i].level){
                    cout << "找到了这位大人的信息(/ω＼) :权限等级————" << level << endl;
                    displayPeople(ret[i]);//测试数据，看能找出那个用户的数据不
                    return;
                }
                distance++;//找不到则找下一个
            }

    }else{//如果没成功打开文件
        cout << "文件竟然打开失败了QAQ!" << endl;
    }
    }
    cout << "我找不到这个级别的用户信息啊啊啊啊~ QAQ!: " << level << endl;
}
inline void searchPeopleByCredit(int credit,string fname){//通过信用等级查询用户信息
    ReaderClassIO pm ;//定义一个书籍管理类的对象pm = peoplemanage的意思;
    people ret[10];
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(people)字节的位置
    while(distance < ((pm.currentFileSize(fname)/(sizeof(people))))){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(people)))为当前文件里实体个数
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0 || state == -4){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(credit == ret[i].credit){
                    cout << "找到了这位大人的信息(/ω＼)  :信用点————" << credit << endl;
                    displayPeople(ret[i]);//测试数据，看能找出那个用户的数据不
                    return;
                }
                distance++;//找不到则找下一个
            }

    }else{//如果没成功打开文件
        cout << "文件竟然打开失败了QAQ!" << endl;
    }
    }
    cout << "我找不到有这个信用点值的用户信息啊啊啊啊~ QAQ! " << credit << endl;
}
 inline int  searchInstanceOfPeople(unsigned int peopleId,string fname){//查询用户号来返回某用户在文件里的distance
    ReaderClassIO pm ;//定义一个书籍管理类的对象pm = peoplemanage的意思;
    people ret[10];
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(people)字节的位置
    while(distance < (pm.currentFileSize(fname)/sizeof(people))){//当数据没找完时,bm.currentFileSize(fname)为当前文件里实体个数
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0 || state == -4){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(peopleId == ret[i].peopleId&&ret[i].isRealDeleted!='1'){
                    cout << "欢迎大人： " <<ret[i].peopleName  <<" ( " << peopleId <<" ) " <<" 大驾光临，您于文件中的序列为 : " <<distance<< endl;
                    return distance;//找到立刻返回他的distance
                }
                distance++;//找不到则找下一个
            }

    }else{//如果没成功打开文件
        cout << "文件竟然打开失败了QAQ!" << endl;
        return -1;//-1代表没搜到这个文件
    }
    }
    return -1;//-1代表没搜到这个文件
}
//-----------------people的查询函数----------------------------

#endif
