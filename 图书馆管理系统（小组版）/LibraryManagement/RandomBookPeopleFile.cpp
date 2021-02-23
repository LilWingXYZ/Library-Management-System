#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "User.h"
#include <windows.h>
#define numBookRecord 100//随机模拟书本记录条数
#define numPeopleRecord 100//随机模拟用户记录条数
using namespace std;


//根据枚举值获取对应分类名称
string getBookValue(BookType num)
{

    switch(num)
    {
    case MaoDeng:
        return "马列主义、毛泽东思想、邓小平理论";
    case PhilosophyReligion:
        return "哲学宗教";
    case Social:
        return "社会科学总论";
    case PoliticalLaw:
        return "政治法律";
    case Military:
        return "军事";
    case Economic:
        return "经济";
    case Literature_PE:
        return "文化、科学、教育、体育";
    case Language:
        return "语言、文字";
    case Literature:
        return "文学";
    case Art:
        return "艺术";
    case HistoryGeography:
        return "历史、地理";
    case Nature:
        return "自然科学总论";
    case MathChemistry:
        return "数理科学与化学";
    case Astronomy:
        return "天文学、地球科学";
    case Biology:
        return "生物科学";
    case Medicine:
        return "医药、卫生";
    case Agriculture:
        return "农业科学";
    case Industry:
        return "工业技术";
    case Transportation:
        return "交通运输";
    case Aerospace:
        return  "航空、航天";
    case EnvironmentSafety:
        return "环境安全科学";
    case Comprehensive:
        return "综合性图书";
    default:
        return "获取信息出错";
        break;
    }

}
//通过学校图书干a-z分类获取对应的int型
int getBookClass(char Number)
{
    switch (Number)
    {
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'C':
        return 3;
    case 'D':
        return 4;
    case 'E':
        return 5;
    case 'F':
        return 6;
    case 'G':
        return 7;
    case 'H':
        return 8;
    case 'I':
        return 9;
    case 'J':
        return 10;
    case 'K':
        return 11;
    case 'N':
        return 12;
    case 'O':
        return 13;
    case 'P':
        return 14;
    case 'Q':
        return 15;
    case 'R':
        return 16;
    case 'S':
        return 17;
    case 'T':
        return 18;
    case 'U':
        return 19;
    case 'V':
        return 20;
    case 'X':
        return 21;
    case 'Z':
        return 22;
    default:
        break;
    }
    return -1;//出错
}



void showBookInfo(book data)
{
    if(data.bookId != 0)
    {
        cout<<"编号NO."<<data.bookId<<endl;
        cout<<"借书人编号:"<<data.peopleId<<endl;
        cout<<"分类："<<getBookValue(BookType(data.bookClass))<<endl;
        cout<<"价格："<<data.price<<endl;
        cout<<"书名："<<data.bookName<<endl;
        cout<<"出版社："<<data.publisher<<endl;
        cout<<"作者："<<data.author<<endl;
        cout<<"出版日期："<<data.publishDate<<endl;
        cout<<"借出时间："<<data.borrowTime<<endl;
        cout<<"借出："<<data.borrowFlag<<endl;
        cout<<"预定："<<data.isReservedFlag<<endl;
        cout<<"保存本："<<data.isPreservedFlag<<endl;
        cout<<"逾期："<<data.isDeleted<<endl;
        cout<<"删除："<<data.isDeleted<<endl;
    }
}

int main()
{


    string fileBookName = "fileBookInfo.dat";
    string filePeopleName = "filePeopleInfo.dat";
    BookClassIO bio;
    ReaderClassIO rio;
    if(!findFileExisting(fileBookName)) bio.createFile(fileBookName);
    if(!findFileExisting(filePeopleName)) rio.createFile(filePeopleName);
    int numBook =0;
    int numPeople =0;

///书籍数量模拟
    ifstream fin("oucBook.csv"); //打开文件流操作
    string line;

    while (getline(fin, line) && numBook < numBookRecord)   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        cout <<"primary string："<< line << endl; //整行输出
        istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
        vector<string> fields; //声明一个字符串向量
        string field;
        while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }

        ///信息录入
        book Book;
        Book.peopleId = 0;
        strcpy(Book.bookName,fields[0].c_str());
        strcpy(Book.author,fields[1].c_str());
        strcpy(Book.publisher,fields[2].c_str());
        strcpy(Book.publishDate,fields[3].c_str());
        Book.price = atoi(fields[4].c_str());
        Book.bookClass = getBookClass(fields[5][0]);
        strcpy(Book.borrowTime, "0000000000"); //time of lending the book,year xxxx month xx date xx hour xx
        Book.borrowFlag = '0';//借出标志位
        Book.isReservedFlag= '0';//预定标志位
        Book.isPreservedFlag= '0';//保存本标志位
        Book.isLated= '0';//是否逾期
        Book.isDeleted= '0';
        Book.isRealDeleted = '0';
        Book.bookId = BookIdGenerater(Book.bookName,Book.publisher,Book.author,Book.publishDate,Book.bookClass,fileBookName);

        ///展示信息
        cout <<"after dealed："<<Book.bookId<< "\t" <<Book.peopleId<< "\t" <<Book.bookName << "\t" << Book.author << "\t" <<Book.publisher << "\t" << Book.publishDate<< "\t" << Book.price<<"\t"
             <<getBookValue(BookType(Book.bookClass-1))<< endl;

        cout<<"---------bookinfo------------"<<endl;
        showBookInfo(Book);
        ofstream fileout(fileBookName,ios::out|ios::binary|ios::app);//start to write file at the end of the file
        if(!fileout) //if the file doesn't exist, return this status
        {
            cout<<"文件出错!"<<endl;
            fileout.close();
        }
        numBook++;

        ///写入文件
        fileout.write((char *)&Book,sizeof(book));// write the messaged;
        if(numBook % 10 == 0)
        {

            int num = 1 + rand() % 5 ;//随机生成该书为num本
            numBook +=num;
            for(int i = 1 ; i < num ; i++)
            {
                Book.bookId +=1;
                ofstream fileout(fileBookName,ios::out|ios::binary|ios::app);//start to write file at the end of the file
                if(!fileout) //if the file doesn't exist, return this status
                {
                    cout<<"文件出错!"<<endl;
                    fileout.close();
                }
                fileout.write((char *)&Book,sizeof(book));// write the messaged;


            }


        }

        fileout.close();
    }
    cout<<"共计书本数量："<<numBook<<" 本 !"<<endl;
    fin.close();

///用户人数模拟


    while(numPeople < numPeopleRecord)
    {

        //信息录入
        people temp;

        temp.peopleId = PeopleIdGenerater(filePeopleName);

        srand((unsigned)time(NULL));
        int num = 3+rand()%7;//限定英文名字在5-20个字母之间
        char str[num];
        int i=0;
        while(i<num-1)
        {
            int s=0;
            s=char(97+rand()%26);
            str[i] = char(s);
            i++;
        }
        str[i] = '\0';
        strcpy(temp.peopleName,str);
        sprintf(temp.password,"%d",temp.peopleId);
        temp.level = 1+rand()%3;
        temp.credit = 100;
        temp.isDeleted = '0';
        temp.isRealDeleted = '0';
        for(int i = 0; i<MAX_BORROW; i++)
        {
            temp.booksBorrowed[i] = 0;
        }
        for(int i =0; i<MAX_RECENT_BORROW; i++)
        {
            temp.recentBorrowId[i] = 0;
        }

        //展示信息
        User user  = User(temp,fileBookName,filePeopleName);
        user.showUserInfo();

        //写入文件
        ofstream fileout1(filePeopleName,ios::out|ios::binary|ios::app);
         if(!fileout1) //if the file doesn't exist, return this status
        {
            cout<<"文件出错!"<<endl;
            fileout1.close();
        }
        fileout1.write((char *)&temp,sizeof(people));// write the messaged;
        numPeople++;
        fileout1.close();
    }
    cout<<"共计用户数量："<<numPeople<<" 人 !"<<endl;
    return 0;
}

