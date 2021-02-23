#include "DeleteOption.h"
#include "SearchOption.h"
#include "UpdateOption.h"
#include "AddOption.h"
#include "IdGenerator.h"
#include "Display.h"
#include "User.h"
#include <iomanip>
#include <iostream>
using namespace std;
int buildTestData(string fname,int mode){//adding data
    if(mode == 2) addBooks(5,fname);// mode 2: adding multiple books
    else if(mode == 1) addSingleBook(fname);//mode 1: adding single data
    else if (mode == 3) addSinglePeople(fname);
    else if (mode == 4) addPeople(5,fname);
    else
    {
        cout << "illegal value" << endl;
    }

    return 0;
}
int deleteTestData(string fname,unsigned int bookId,int mode){
    if(!idTest(bookId,fname)) return 0;
    BookClassIO io;
    book temp[10],delaver;
    int distance = searchInstanceOfBook(bookId,fname);
    io.readFile(temp,fname,distance,2);// read records
    delaver = temp[0];
    if(mode == 1) falseDeleteBookbyId(fname,&delaver);// mode 1: deleting multiple books
    else if(mode == 2) trueDeleteBookbyId(fname,&delaver);//mode 2: deleting single data
    else{
        cout << "illegal value" << endl;
    }
    return 0;
}
int searchBook(unsigned int id,string fname){
    int record = -1;
    if(!isRecNotDel(id,fname)) return 0;
    else record = searchInstanceOfBook(id,fname);
    return record;
}
int updateRecord(unsigned int id,string fname){
    int rec = 0;
    cout << endl<<setw(54)<<"please chose a data to update" << endl <<endl<<setw(48)<< "1.author 2.publish date" << endl
        <<endl<<setw(38)<< "your choice :" ;
    cin >> rec;
    BookClassIO io;
    book temp[10],transfer;
    int distance = searchInstanceOfBook(id,fname);
    io.readFile(temp,fname,distance,2);// read records
    transfer = temp[0];
    if(rec == 1){
        char aname[20];
        cout <<endl<<setw(46) <<"the original data is:" << temp[0].author << endl <<endl<<setw(52)<< "please input a new author :";
        cin >> aname;
        if(!updateBookAuthor(fname,&transfer,aname)) cout << "failed" << endl;
    }
    else if(rec == 2){
        char date[9];
        cout <<endl<<setw(46) << "the original data is:" << temp[0].publishDate << endl <<endl<<setw(50)<< "please input a new date :";
        cin >> date;
        if(!updateBookPublishDate(fname,&transfer,date)) cout << "failed" << endl;
    }
    return 0;
}
int main()
{
    string fileName = "BookTestDataV1.dat";
    string peopleName = "PeopleTest.dat";
    BookClassIO bio;
    ReaderClassIO rio;
    if(!findFileExisting(fileName)) bio.createFile(fileName);
    if(!findFileExisting(peopleName)) rio.createFile(peopleName);

    people ret[10];
    int get = 0;

    //随机模拟用户信息
    int peopleNUm = 0;
    while(peopleNUm < 10){

        people temp;

        temp.peopleId = 10000+peopleNUm;
        cout<<temp.peopleId<<endl;

        srand((unsigned)time(NULL));
        /*
        int num = 5+rand()%16;//限定英文名字在5-20个字母之间
        char str[num];
        int i=0;
        while(i<num){
            int s=0;
            s=rand()%2?65:97;
            s+=rand()%26;
            str[i] = char(s);
            i++;
        }
        strcpy(temp.peopleName,str);*/
        strcpy(temp.peopleName,"yan");
        cout<<temp.peopleName<<endl;
        temp.level = 1+rand()%3;
        cout<<temp.level<<endl;;
        temp.credit = 100;
        temp.isDeleted = '0';
        temp.isRealDeleted = '0';
        for(int i = 0;i<MAX_BORROW;i++) {
                temp.booksBorrowed[i] = 0;
                temp.password[i]='1';
        }
        for(int i =0;i<MAX_RECENT_BORROW;i++){
            temp.recentBorrowId[i] = 0;
        }
        get = rio.writeFile(temp,fileName,0,5);
        cout<<"writeFileGetValue:"<<get<<endl;
        peopleNUm++;
    }
    get = rio.readFile(ret,peopleName,0,1);
    cout<<"readFileGetValue:"<<get<<endl;
    for(int i = 0;i<10;i++){
        cout << ret[i].peopleId << " " << ret[i].peopleName << endl;
        cout << ret[i].password << " " << ret[i].isDeleted << endl;
        cout << ret[i].isRealDeleted << " " << ret[i].level<<endl;
        cout << ret[i].booksBorrowed[2] << " " << ret[i].recentBorrowId[4] << endl;
    }
    /*
    for(int i = 0;i<1;i++){
        User user  = User(ret[i],fileName,peopleName);
        user.showUserInfo();
    }
    */

    /*
    int choice = 1;//set the beginning function
    bool haveData = false;// you have to have data first
    unsigned int bid = 0;
    int get = 0,i=0;
    int way = 0;
    while (1)
    {
        system("cls");
        showWelcome("Library Management System");
        cout << endl;                                                       //showRootMenu
        cout << setw(51);
        cout << "1.adding multiple books" << endl;
        cout << endl;
        cout << setw(48);
        cout << "2.adding single book" << endl;
        cout << endl;
        cout << setw(49);
        cout << "3.deleting book(fake)" << endl;
        cout << endl;
        cout << setw(49);
        cout << "4.deleting book(real)" << endl;
        cout << endl;
        cout << setw(49);
        cout << "5.searching book info" << endl;
        cout << endl;
        cout << setw(48);
        cout << "6.updating book info" << endl;
        cout << endl;
        cout << setw(48);
        cout << "7.adding single card" << endl;
        cout << endl;
        cout << setw(50);
        cout << "8.adding multiple card" << endl;
        cout << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            showWelcome("  Adding Multiple Data   ");
            buildTestData(fileName,2);
            break;
        case 2:
            system("cls");
            showWelcome("   Adding Single Data    ");
            buildTestData(fileName,1);
            break;
        case 3:
            system("cls");
            showWelcome("   Deleting(fake) Data   ");
            cout <<endl<<setw(45)<< "please input an id: ";
            while(bid < 0)
            {
                cout << "Error" << endl;
                cin >> bid;
            }
            cin >> bid;
            deleteTestData(fileName,bid,1);
            break;
        case 4:
            system("cls");
            showWelcome("   Deleting(real) Data   ");
            cout <<endl<<setw(45)<< "please input an id: ";
            cin >> bid;
            while(bid < 0)
            {
                cout << "Error" << endl;
                cin >> bid;
            }
            deleteTestData(fileName,bid,2);
            break;
        case 5:
            system("cls");
            showWelcome("     Searching Data      ");
//            cout << "please input an id" << endl;
//            cin >> bid;
//            cout << searchBook(bid,fileName);
            cout <<endl<<setw(40)<< "1:  AllBooks";
            cout <<endl<<setw(40)<< "2:  ByBookId";
            cout <<endl<<setw(42)<< "3:  ByPeopleId";
            cout <<endl<<setw(39)<< "4:  ByClass";
            cout <<endl<<setw(39)<< "5:  ByPrice";
            cout <<endl<<setw(38)<< "6:  ByName";
            cout <<endl<<setw(43)<< "7:  ByPublisher";
            cout <<endl<<setw(40)<< "8:  ByAuthor";
            cout <<endl<<setw(45)<< "9:  ByPublishDate";
            cout <<endl<<setw(44)<< "10: ByBorrowTime";
            cout <<endl<<setw(52)<< "11: searchInstanceOfBook";
            cout <<endl<<setw(38)<< "0:  return";
            cout <<endl<<setw(41)<< "Your choice: ";
           // cout << "1: AllBooks  2: ByBookId  3: ByPeopleId  4: ByClass  5: ByPrice  6: ByName  7: ByPublisher "
           // <<endl <<endl<<"8: ByAuthor  9: ByPublishDate  10: ByBorrowTime 11: searchInstanceOfBook(unsigned int bookId)"<<endl;
           // cout << "Your choice: (0:break)" << endl;
            cin >> way ;
            system("cls");
            showWelcome("     Searching Data      ");
            while(way < 0 || way >11)
            {
                cout << "Error, Please re-input"<<endl;
                cin >> way;

            }
            while(way){
            switch(way){//没做限制数据判断
            case 1:
                searchAllBooks(fileName);
                break;
            case 2:
                cout <<endl<<setw(32)<< "ID: ";
                int BID;
                cin >> BID;
                searchBookById(BID,fileName);
                break;
            case 3:
                cout <<endl<<setw(32)<< "ID: ";
                int PID;
                cin >> PID;
                searchBookByPeopleId(PID,fileName);
                break;
            case 4:
                cout <<endl<<setw(35)<< "Class: ";
                int CLASS;
                cin >> CLASS;
                searchBookByClass(CLASS,fileName);
                break;
            case 5:
                cout <<endl<<setw(45)<< "Price1 ~ Price2: ";
                float price1,price2;
                cin >> price1 >> price2;
                searchBookByPrice(price1,price2,fileName);
                break;
            case 6:
                cout <<endl<<setw(34)<< "Name: ";
                char name[45];
                cin >> name;
                searchBookByName(name,fileName);
                break;
            case 7:
                cout <<endl<<setw(39)<< "Publisher: ";
                char Publisher[25];
                cin >> Publisher;
                searchBookByPublisher(Publisher,fileName);
                break;
            case 8:
                cout <<endl<<setw(36)<< "Author: ";
                char Author[25];
                cin >> Author;
                searchBookByAuthor(Author,fileName);
                break;
            case 9:
                cout <<endl<<setw(41)<< "publishDate: ";
                char publishDate[5];
                cin >> publishDate;
                searchBookByPublishDate(publishDate,fileName);
                break;
            case 10:
                cout <<endl<<setw(40)<< "BorrowTime: ";
                char BorrowTime[11];
                cin >> BorrowTime;
                searchBookByBorrowTime(BorrowTime,fileName);
                break;
            case 11:
                cout <<endl<<setw(36)<< "BookID: ";
                unsigned int bookId;
                cin >> bookId;
                int  dist ;
                dist= searchInstanceOfBook(bookId,fileName);
                cout <<endl<<setw(42)<< "Its distance: " << dist << endl;
                break;
            default :
                cout << "illegal choose!";
                break;
            }
            cout<<endl<<setw(52)<<"Press any key to return.";
            system("pause>nul");
            system("cls");
            showWelcome("     Searching Data      ");
//            cout << "please input an id" << endl;
//            cin >> bid;
//            cout << searchBook(bid,fileName);
            cout <<endl<<setw(40)<< "1:  AllBooks";
            cout <<endl<<setw(40)<< "2:  ByBookId";
            cout <<endl<<setw(42)<< "3:  ByPeopleId";
            cout <<endl<<setw(39)<< "4:  ByClass";
            cout <<endl<<setw(39)<< "5:  ByPrice";
            cout <<endl<<setw(38)<< "6:  ByName";
            cout <<endl<<setw(43)<< "7:  ByPublisher";
            cout <<endl<<setw(40)<< "8:  ByAuthor";
            cout <<endl<<setw(45)<< "9:  ByPublishDate";
            cout <<endl<<setw(44)<< "10: ByBorrowTime";
            cout <<endl<<setw(52)<< "11: searchInstanceOfBook";
            cout <<endl<<setw(38)<< "0:  return";
            cout <<endl<<setw(41)<< "Your choice: ";
           // cout << "1: AllBooks  2: ByBookId  3: ByPeopleId  4: ByClass  5: ByPrice  6: ByName  7: ByPublisher "
           // <<endl <<endl<<"8: ByAuthor  9: ByPublishDate  10: ByBorrowTime 11: searchInstanceOfBook(unsigned int bookId)"<<endl;
           // cout << "Your choice: (0:break)" << endl;
            cin >> way ;
            system("cls");
            showWelcome("     Searching Data      ");
            }
            break;
        case 6:
            system("cls");
            showWelcome("      Updating Data      ");
            cout <<endl<<setw(45)<< "please input an id: ";
            cin >> bid;
            while(bid < 0)
            {
                cout << "Error" << endl;
                cin >> bid;
            }
            updateRecord(bid,fileName);
            break;
        case 7:
            system("cls");
            showWelcome("    Adding Single Card   ");
            buildTestData(peopleName,3);
            break;
        case 8:
            system("cls");
            showWelcome("  Adding Multiple Cards  ");
            buildTestData(peopleName,4);
            break;
        case 0 :
            cout << "Exiting program" << endl;
            exit(0);
        default:
            cout << endl << "unknown command" << endl;
            break;
        }
    }
    */
    return 0;
}
