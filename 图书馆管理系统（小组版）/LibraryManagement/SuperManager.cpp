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
        cout << "1.���Ӷ���û� 2.����һ���û�" << endl
        << "your choice :";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        do{
            cout << "��������Ӷ��ٸ��û���(���ئ�)? " << endl;
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
        cout << "��ѡ������Ҫ���µ���Ϣ :"<< endl
        << "1. �ȼ� 2.����" << endl << "��߹���ŵ���������ѡ��(/�أ�):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "������������ߵ��û���� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(choice<0){
            cout << "û������һ����¼Ŷ��(/�أ�)" << endl;
            return;
        }
        rio.readFile(temp,filePeople,choice,2);
        do{
            cout << "���趨һ���µ�Ȩ�޵ȼ�:";
            choice = io.get_Int();
        }while(choice<=0 || choice >3);

        updatePeopleLevel(filePeople,&temp[0],choice);
    }
    else{
        cout << "�������뱻�����ߵ��û���� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(choice<0){
            cout << "û������һ����¼Ŷ��(/�أ�)" << endl;
            return;
        }
        rio.readFile(temp,filePeople,choice,2);
        cout << "���趨һ���µ��û�����:";
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
        cout << "1.���� 2.ɾ�� " << endl << "��߹���ŵ���������ѡ��(/�أ�):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "�������뱻�����ߵ��û���� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(id = this->getPeopleId()){
            cout << "����ɾ��Ŀǰ�Ĺ�����Ŷ(/�أ�)" << endl;
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
            cout << "����ɾ����ǰ�û�,���û�������δ��" << endl;
        }
    }
    else{
        cout << "�������뱻�����ߵ��û���� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfPeople(id,filePeople);
        if(id == this->getPeopleId()){
            cout << "����ɾ��Ŀǰ�Ĺ�����Ŷ(/�أ�)" << endl;
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
            cout << "����ɾ����ǰ�û�,���û�������δ��" << endl;
        }
    }
}
void SuperManager::searchUser(){
    StdIO io;
    int choice = 0;
    unsigned int id = 0;
    do{
        cout << "1.��ѯĳ����ŵ��û���Ϣ 2.��ѯ���е��û���Ϣ " << endl << "��߹���ŵ���������ѡ��(/�أ�):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "��������Ҫ��ѯ���û���� :" << endl;
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
    cout << "�������û����Ӵ(/�أ�) :";
    id = (unsigned)io.get_Int();
    choice = searchInstanceOfPeople(id,filePeople);
    if(choice<0){
        cout << "û�������ļ�¼" << endl;
        return 0.0;
    }
    rio.readFile(temp,filePeople,choice,2);
    if(temp[0].credit < 100){
        float sum = (100-temp[0].credit)*0.1;
        for(int i = 0;i < 10;i++){
            choice = searchInstanceOfBook(temp[0].booksBorrowed[i],fileBook);
            if(choice < 0){
                cout << "���ݴ�����QAQ��";
                return 0.0;
            }
            bio.readFile(ret,fileBook,choice,2);
            if(ret[0].isDeleted == '1'&&ret[0].isLated == '1'){
                sum += ret[0].price;
            }
        }
        cout << "��λ������Ҫ������ : "<< sum << " RMB Ŷ(/�أ�)";
    }
    return sum;
}
void SuperManager::addBook(){
    StdIO io;
    int choice = 0;
    do{
        cout << "1.��Ӷ౾�鼮 2.���һ���鼮" << endl
        << "��߹���ŵ���������ѡ��(/�أ�):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        do{
            cout << "����������Ӷ��ٱ��鼮��(/�أ�)��" << endl;
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
        cout << "��ѡ������Ҫ���µ���Ϣ(���ئ�) :"<< endl
        << "1.�������� 2.���� 3.���� " << endl << "��߹���ŵ���������ѡ��(/�أ�): ";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2&&choice!=3);
    if(choice == 1){
        cout << "��������Ҫ������Ϣ���鼮��� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        if(choice<0){
            cout << "���Ҳ�������鼮��Ű�������~ QAQ!" << endl;
            return;
        }
        rio.readFile(temp,fileBook,choice,2);
        cout << "������һ���µĳ������� : ";
        char date[5];
        io.get_CharArr(5,date);
        updateBookPublishDate(fileBook,&temp[0],date);
    }
    else if(choice == 2){
        cout << "��������Ҫ������Ϣ���鼮��� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        if(choice<0){
            cout << "���Ҳ�������鼮��Ű�������~ QAQ!" << endl;
            return;
        }
        cout << "test" << choice << endl;
        rio.readFile(temp,fileBook,choice,2);
        cout << "�������µ����� :";
        char pname[45];
        io.get_CharArr(45,pname);
        updateBookName(fileBook,&temp[0],pname);
    }
    else {
        cout << "��������Ҫ������Ϣ���鼮��� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        if(choice<0){
            cout << "���Ҳ�������鼮��Ű�������~ QAQ!" << endl;
            return;
        }
        rio.readFile(temp,fileBook,choice,2);
        cout << "�������µ��������� :";
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
        cout << "1.���� 2.ɾ�� " << endl << "��߹���ŵ���������ѡ��(/�أ�):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "��������Ҫ������Ϣ���鼮��� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        rio.readFile(temp,fileBook,choice,2);
        if(temp[0].borrowFlag == '1'||temp[0].isPreservedFlag == '1'){
            cout << "�����ֹɾ��, ��Ϊ�ѱ����Ļ�Ϊ�ݲر�" << endl;
            return;
        }
        trueDeleteBookbyId(fileBook,&temp[0],choice);
    }
    else{
        cout << "��������Ҫ������Ϣ���鼮��� :";
        id = (unsigned)io.get_Int();
        choice = searchInstanceOfBook(id,fileBook);
        rio.readFile(temp,fileBook,choice,2);
        if(temp[0].borrowFlag == '1'||temp[0].isPreservedFlag == '1'){
            cout << "�����ֹɾ��, ��Ϊ�ѱ����Ļ�Ϊ�ݲر�" << endl;
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
        cout << "1.��ѯĳ����ŵ��鼮��Ϣ 2.չʾ�����鼮����Ϣ " << endl << "��߹���ŵ���������ѡ��(/�أ�):";
        choice = io.get_Int();
    }while(choice!=1&&choice!=2);
    if(choice == 1){
        cout << "��������Ҫ������Ϣ���鼮��� :" << endl;
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

