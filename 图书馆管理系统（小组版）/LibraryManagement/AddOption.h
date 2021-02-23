#pragma once
#ifndef ADDOPTION_H_INCLUDED
#define ADDOPTION_H_INCLUDED
#include <iostream>
#include <fstream>
#include "BookManagementIO.h"
#include <malloc.h>
#include "IdGenerator.h"
#include <vector>
#include "windows.h"
#include "Display.h"
#include "StdIO.h"
#include <iomanip>
using namespace std;
inline void fillBlank (unsigned int arr[],int length){
    for(int i = 0;i < length; i++) arr[i] = 0;
}
inline int addSingleBook(string fname)//单本书的添加
{
    StdIO io;
    int message;
    book pbook;
    BookClassIO bm;
    strcpy(pbook.borrowTime,"1970");
    pbook.peopleId = 0;
    pbook.borrowFlag = '0';
    pbook.isReservedFlag = '0';
    pbook.isPreservedFlag = '0';
    pbook.isLated = '0';
    pbook.isDeleted = '0';//char 类型的数据的初始化，基于常理
    pbook.isRealDeleted = '0';
    cout <<endl<<setw(62)<<"Please input the BASIC info of the ONLY Book "<<endl;
            cout <<endl<<setw(35)<<"BookName: ";
            io.get_CharArr(45,pbook.bookName);
            cout <<endl<<setw(36)<<"BookClass: ";
            pbook.bookClass = io.get_Int();
            if(pbook.bookClass < 1 || pbook.bookClass > 25 ){
                cout << "No such a class" << endl;
                return 0;
            }
            cout <<endl<<setw(33)<<"Author: ";
            io.get_CharArr(25,pbook.author);
            cout <<endl<<setw(36)<<"Publisher: ";
            io.get_CharArr(25,pbook.publisher);
            cout <<endl<<setw(38)<<"Publishdate: ";
            io.get_CharArr(5,pbook.publishDate);
            cout <<endl<<setw(32)<<"Price: ";
            pbook.price = io.get_Float();

   // cout << "Please input the BASIC info of the ONLY book in an order of name, class, author, publisher ,publish date(yyyy) and price;" << endl;
   // cin >>  pbook.bookName  >> pbook.bookClass >> pbook.author >> pbook.publisher >> pbook.publishDate >> pbook.price; // 对基本信息的输入，不可或缺；
    pbook.bookId = BookIdGenerater(pbook.bookName, pbook.publisher, pbook.author, pbook.publishDate, pbook.bookClass,fname);
    message = bm.writeFile(pbook, fname, 0, 5);
    cout<<endl<<setw(37)<<"Added successfully!";
    Sleep(2000);
    return message;
}
inline int addSinglePeople(string fname)//单个借书卡的办理
{
    int message;
    StdIO io;
    people ppl;
    ReaderClassIO rm;
    cout <<endl<<setw(60)<<"Please input the info of the ONLY Person "<<endl;
    cout <<endl<<setw(37)<<"PeopleName: ";
    io.get_CharArr(20,ppl.peopleName);
    cout <<endl<<setw(35)<<"Password: ";
    io.get_pwd(ppl.password);
    ppl.peopleId = PeopleIdGenerater(fname);
    ppl.level = 1;
    ppl.credit = 100;
    ppl.isDeleted = '0';
    ppl.isRealDeleted = '0';
    fillBlank(ppl.booksBorrowed,10);
    fillBlank(ppl.recentBorrowId,20);
    message = rm.writeFile(ppl,fname, 0, 5);
    cout<<endl<<setw(38)<<"Added successfully!";
    Sleep(2000);
    return message;
}
inline void addBooks(int size,string fname)//复数书本的添加,size 代表本数
{
    book pbook[size];
    BookClassIO bm;
    StdIO io;
	int count = 0;//count 作为添加个数的计数，下同
	while(1)
		{
		    cout <<endl<<setw(57)<<"Please input the BASIC info of Book " << count+1 <<endl;
            cout <<endl<<setw(35)<<"BookName: ";
            io.get_CharArr(45,pbook[count].bookName);
            cout <<endl<<setw(36)<<"BookClass: ";
            pbook[count].bookClass = io.get_Int();
            if(pbook[count].bookClass < 1 || pbook[count].bookClass > 25 ){
                cout << "No such a class" << endl;
                continue;
            }
            cout <<endl<<setw(33)<<"Author: ";
            io.get_CharArr(25,pbook[count].author);
            cout <<endl<<setw(36)<<"Publisher: ";
            io.get_CharArr(25,pbook[count].publisher);
            cout <<endl<<setw(38)<<"Publishdate: ";
            io.get_CharArr(5,pbook[count].publishDate);
            cout <<endl<<setw(32)<<"Price: ";
            pbook[count].price = io.get_Float();
			//cout << "Please input the BASIC info of book " << count+1 << " in an order of name, class, author, publisher ,publishdate and price;" << endl;
			//cin >> pbook[count].bookName >> pbook[count].bookClass >> pbook[count].author >> pbook[count].publisher >> pbook[count].publishDate >> pbook[count].price; // 对基本信息的输入，不可或缺；
            strcpy(pbook[count].borrowTime,"1970010100");
			pbook[count].peopleId = 0;
			pbook[count].borrowFlag = '0';
			pbook[count].isReservedFlag = '0';
			pbook[count].isPreservedFlag = '0';
			pbook[count].isLated = '0';
			pbook[count].isDeleted = '0';//char 类型的数据的初始化，基于常理
			pbook[count].isRealDeleted = '0';
			pbook[count].bookId = BookIdGenerater(pbook[count].bookName, pbook[count].publisher, pbook[count].author, pbook[count].publishDate, pbook[count].bookClass,fname);
			bm.writeFile(pbook[count],fname, 0, 5);
            cout<<endl<<setw(40)<<"Added Successfully!";              //
            Sleep(2000);
            count ++;//添加终了计数
			if(count < size)
				{
				    system("cls");
				    showWelcome("  Adding Multiple Data   ");
					continue;
				}
			else
				{
                    break;
				}
		}
}
inline void addPeople(int size,string fname)//复数借书人/借书卡的办理
{
    people ppl[size];
    ReaderClassIO rm;
	StdIO io;
	int count = 0;
	while(1)
		{
            cout <<endl<<setw(57)<<"Please input the BASIC info of Person " << count+1 <<endl;
            cout <<endl<<setw(37)<<"PeopleName: ";
            io.get_CharArr(20,ppl[count] .peopleName);
            cout <<endl<<setw(35)<<"Password: ";
            io.get_pwd(ppl[count]. password);
			//cout << "Please input the info of the" << count+1 << " person, in an order of name, password"<<endl;
			//cin >> ppl[count] .peopleName >> ppl[count]. password;
			ppl[count].level = 1;
			ppl[count].credit = 100;
			ppl[count].isDeleted = '0';
			ppl[count].isRealDeleted = '0';
			ppl[count].peopleId = PeopleIdGenerater(fname);
			fillBlank(ppl[count].booksBorrowed,10);
            fillBlank(ppl[count].recentBorrowId,20);
            rm.writeFile(ppl[count], fname, 0, 5);//借书卡文件暂定名
            cout<<endl<<setw(38)<<"Added Successfully!";              //
            Sleep(2000);
            count ++;
			if(count < size)
				{
                    system("cls");
				    showWelcome("  Adding Multiple Data   ");
					continue;
				}
			else
				{
                    break;
				}

		}
}

inline int fillBookBlank(string fname)//补充 BookData 中的空缺位置
{
    ifstream fin("deletedDistance.txt");
    vector<int> deletedDistance;
    int allDeletedDistance;
    int curDistance;
    if(fin)
            {
                fin>>allDeletedDistance;
                for(int i=0; i<allDeletedDistance; i++)
                {
                    int temp;
                    fin>>temp;
                    deletedDistance.push_back(temp);
                }
                fin.close();
            }
    curDistance = deletedDistance[0];
    deletedDistance.erase(deletedDistance.begin());
    int message;
    book pbook;
    BookClassIO bm;
    cout << "Please input the BASIC info of the ONLY book in an order of name, class,author, publisher ,publish date and price;" << endl;
    cin >>  pbook.bookName  >> pbook.bookClass >> pbook.author >> pbook.publisher >> pbook.publishDate >> pbook.price; // 对基本信息的输入，不可或缺；
    pbook.borrowFlag = '0';
    pbook.isReservedFlag = '0';
    pbook.isPreservedFlag = '0';
    pbook.isLated = '0';
    pbook.isDeleted = '0';//char 类型的数据的初始化，基于常理
    pbook.isRealDeleted = '0';
    pbook.bookId = BookIdGenerater(pbook.bookName, pbook.publisher, pbook.author, pbook.publishDate, pbook.bookClass,fname);
    message = bm.writeFile(pbook, fname, curDistance, 2);
    ofstream fout("deletedDistance.txt");
    allDeletedDistance--;
    if (fout)
            {
                fout << allDeletedDistance <<endl;
                for (int i = 0; i <(int)deletedDistance.size(); i++)
                {
                    fout<<deletedDistance[i]<<endl;
                }
                fout.close();
            }
    return message;
}
#endif
