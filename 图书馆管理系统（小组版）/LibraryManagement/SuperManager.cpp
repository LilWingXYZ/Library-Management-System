#include <iostream>
#include "SuperManager.h"
#include "AddOption.h"
#include "DeleteOption.h"
#include "StdIO.h"
#include "BookManagementIO.h"
#include "BookManagementIOHeader.h"
#define filePeople "filePeopleInfo.dat"
#define fileBook "fileBookInfo.dat"
void SuperManager::addUser(){
    StdIO io;
    int choice = 0;
    do{
        cout << "1.增加多个用户 2.增加一个用户" << endl
        << "your choice :";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        do{
            cout << "大人想添加多少个用户呢(ΦωΦ)? " << endl;
            choice = io.get_Int();
        }while(choice <= 0);
        addPeople(choice,filePeople);
    }
    else{
        addSinglePeople(filePeople);
    }
}
void SuperManager::updateUserInfo(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    people temp[10];
    ReaderClassIO rio;
    do{
        cout << "请选择你需要更新的信息 :"<< endl
        << "1. 等级 2.姓名" << endl << "请高贵典雅地作出您的选择(/ω＼):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "请您输入更改者的用户编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(choice<0){
            cout << "没有这样一个记录哦！(/ω＼)" << endl;
            return;
        }
        rio.readFile(temp,filePeople,choice,2);
        do{
            cout << "请设定一个新的权限等级:";
            choice = io.get_Int();
        }while(choice<=0 || choice >3);

        updatePeopleLevel(filePeople,&temp[0],choice);
    }
    else{
        cout << "请您输入被更改者的用户编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(choice<0){
            cout << "没有这样一个记录哦！(/ω＼)" << endl;
            return;
        }
        rio.readFile(temp,filePeople,choice,2);
        cout << "请设定一个新的用户名称:";
        char pname[20];
        io.get_CharArr(20,pname);
        updatePeopleName(filePeople,&temp[0],pname);
    }
}
void SuperManager::deleteUser(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    people temp[10];
    ReaderClassIO rio;
    do{
        cout << "1.毁灭 2.删除 " << endl << "请高贵典雅地作出您的选择(/ω＼):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "请您输入被更改者的用户编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(id = this->getPeopleId()){
            cout << "不能删除目前的管理者哦(/ω＼)" << endl;
            return;
        }
        rio.readFile(temp,filePeople,choice,2);
        int bookNum = 0;
        for(int i = 0;i < 10;i++){
            if(temp[0].booksBorrowed[i] != 0){
                    bookNum ++;
                    break;
            }
        }
        if(bookNum == 0)
            trueDeletePeoplebyId(filePeople,&temp[0]);
        else{
            cout << "不能删除当前用户,该用户仍有书未还" << endl;
        }
    }
    else{
        cout << "请您输入被更改者的用户编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(id == this->getPeopleId()){
            cout << "不能删除目前的管理者哦(/ω＼)" << endl;
            return;
        }
        rio.readFile(temp,filePeople,choice,2);
        int bookNum = 0;
        for(int i = 0;i < 10;i++){
            if(temp[0].booksBorrowed[i] != 0){
                    bookNum ++;
                    break;
            }
        }
        if(bookNum == 0)
            falseDeletePeoplebyId(filePeople, &temp[0]);
        else{
            cout << "不能删除当前用户,该用户仍有书未还" << endl;
        }
    }
}
void SuperManager::searchUser(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    do{
        cout << "1.查询某个编号的用户信息 2.查询所有的用户信息 " << endl << "请高贵典雅地作出您的选择(/ω＼):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "请您输入要查询的用户编号 :" << endl;
        id = io.get_Int();
        searchPeopleById(id,filePeople);
    }
    else{
         searchAllPeople(filePeople);
    }
}
void SuperManager::recoverCredit(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    people temp[10];
    ReaderClassIO rio;
    cout << "please enter his/her id :";
    id = (unsigned)io.get_Int();
    choice = searchInstanceOfPeople(id,filePeople);
    if(choice<0){
        cout << "no such a record" << endl;
        return;
    }
    rio.readFile(temp,filePeople,choice,2);
    do{
        cout << "recover credit :" << "1.yes 2.no " << endl << "your choice :";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    updatePeopleCredit(filePeople,&temp[0],100);
}
float SuperManager::sumMoney(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    people temp[10];
    book ret[10];
    ReaderClassIO rio;
    BookClassIO bio;
    float sum = 0.0f;
    cout << "请输入用户编号哟(/ω＼) :";
    id = (unsigned)io.get_Int();
    choice = searchInstanceOfPeople(id,filePeople);
    if(choice<0){
        cout << "没有这样的记录" << endl;
        return 0.0;
    }
    rio.readFile(temp,filePeople,choice,2);
    if(temp[0].credit < 100){
        float sum = (100-temp[0].credit)*0.1;
        for(int i = 0;i < 10;i++){
            choice = searchInstanceOfBook(temp[0].booksBorrowed[i],fileBook);
            if(choice < 0){
                cout << "数据错误了QAQ！";
                return 0.0;
            }
            bio.readFile(ret,fileBook,choice,2);
            if(ret[0].isDeleted == '1'&&ret[0].isLated == '1'){
                sum += ret[0].price;
            }
        }
        cout << "这位大人需要被罚款 : "<< sum << " RMB 哦(/ω＼)";
    }
    return sum;
}
void SuperManager::addBook(){
    StdIO io;
    int choice = 0;
    do{
        cout << "1.添加多本书籍 2.添加一本书籍" << endl
        << "请高贵典雅地作出您的选择(/ω＼):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        do{
            cout << "大人您想添加多少本书籍呢(/ω＼)：" << endl;
            choice = io.get_Int();
        }while(choice <= 0);
        addBooks(choice,fileBook);
    }
    else{
        addSingleBook(fileBook);
    }
}
void SuperManager::updateBookInfo(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    book temp[10];
    BookClassIO rio;
    do{
        cout << "请选择你需要更新的信息(ΦωΦ) :"<< endl
        << "1.出版日期 2.书名 3.作者 " << endl << "请高贵典雅地作出您的选择(/ω＼): ";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2&&choice!=3);
    if(choice == 1){
        cout << "请输入需要更新信息的书籍编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        if(choice<0){
            cout << "我找不到这个书籍编号啊啊啊啊~ QAQ!" << endl;
            return;
        }
        rio.readFile(temp,fileBook,choice,2);
        cout << "请输入一个新的出版日期 : ";
        char date[5];
        io.get_CharArr(5,date);
        updateBookPublishDate(fileBook,&temp[0],date);
    }
    else if(choice == 2){
        cout << "请输入需要更新信息的书籍编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        if(choice<0){
            cout << "我找不到这个书籍编号啊啊啊啊~ QAQ!" << endl;
            return;
        }
        cout << "test" << choice << endl;
        rio.readFile(temp,fileBook,choice,2);
        cout << "请输入新的书名 :";
        char pname[45];
        io.get_CharArr(45,pname);
        updateBookName(fileBook,&temp[0],pname);
    }
    else {
        cout << "请输入需要更新信息的书籍编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        if(choice<0){
            cout << "我找不到这个书籍编号啊啊啊啊~ QAQ!" << endl;
            return;
        }
        rio.readFile(temp,fileBook,choice,2);
        cout << "请输入新的作者名称 :";
        char pname[25];
        io.get_CharArr(25,pname);
        updateBookName(fileBook,&temp[0],pname);
    }
}
void SuperManager::deleteBook(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    book temp[10];
    BookClassIO rio;
    do{
        cout << "1.毁灭 2.删除 " << endl << "请高贵典雅地作出您的选择(/ω＼):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "请输入需要更新信息的书籍编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        rio.readFile(temp,fileBook,choice,2);
        if(temp[0].borrowFlag == '1'||temp[0].isPreservedFlag == '1'){
            cout << "此书禁止删除, 因为已被借阅或为馆藏本" << endl;
            return;
        }
        trueDeleteBookbyId(fileBook,&temp[0],choice);
    }
    else{
        cout << "请输入需要更新信息的书籍编号 :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        rio.readFile(temp,fileBook,choice,2);
        if(temp[0].borrowFlag == '1'||temp[0].isPreservedFlag == '1'){
            cout << "此书禁止删除, 因为已被借阅或为馆藏本" << endl;
            return;
        }
        falseDeleteBookbyId(fileBook, &temp[0],choice);
    }
}
void SuperManager::searchBook(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    do{
        cout << "1.查询某个编号的书籍信息 2.展示所有书籍的信息 " << endl << "请高贵典雅地作出您的选择(/ω＼):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "请输入需要更新信息的书籍编号 :" << endl;
        id = io.get_Int();
        searchBookById(id,fileBook);
    }
    else{
         searchAllBooks(fileBook);
    }
}
void SuperManager::recoverDeletedBook(){
    book temp[10];
    BookClassIO bio;
    unsigned int rec = 0;
    int distance = -1;
    StdIO io;
    cout << "please input book id of the one you want to recover : " << endl;
    rec = io.get_Int();
    distance = searchInstanceOfBook(rec,fileBook);
    if(distance < 0){
        cout << "there is no such a book " << endl;
        return;
    }
    bio.readFile(temp,fileBook,distance,2);
    if(temp[0].isDeleted == '1'){
        if(temp[0].isLated == '1'){
            cout << "the book is lost, can't recover" << endl;
            return;
        }
        temp[0].isDeleted = '0';
        updateBook(fileBook,&temp[0]);
        cout << "complete" << endl;
    }
    else{
        cout << "this book do not need to recover or its record is dropped";
    }
}
void SuperManager::recoverLost(){
    book temp[10];
    BookClassIO bio;
    unsigned int rec = 0;
    int distance = -1;
    StdIO io;
    cout << "please input book id of the one you want to recover : " << endl;
    rec = io.get_Int();
    distance = searchInstanceOfBook(rec,fileBook);
    if(distance < 0){
        cout << "there is no such a book " << endl;
        return;
    }
    bio.readFile(temp,fileBook,distance,2);
    if(temp[0].isDeleted == '1' && temp[0].isLated == '1'){
        temp[0].isDeleted = '0';
        temp[0].isLated = '0';
        updateBook(fileBook,&temp[0]);
        cout << "complete" << endl;
    }
    else{
        cout << "this book is not lost or its record is dropped";
    }
}
void SuperManager::recoverDeletedUser(){
    people temp[10];
    ReaderClassIO bio;
    unsigned int rec = 0;
    int distance = -1;
    StdIO io;
    cout << "please input id of the person who you want to recover : " << endl;
    rec = io.get_Int();
    distance = searchInstanceOfPeople(rec,filePeople);
    if(distance < 0){
        cout << "there is no such a record " << endl;
        return;
    }
    bio.readFile(temp,fileBook,distance,2);
    if(temp[0].isDeleted != '0'){
        updatePeopleDeleted(filePeople,&temp[0],'0');
        cout << "complete" << endl;
    }
    else{
        cout << "this person do not need to recover or its record is dropped" << endl;
    }
}

