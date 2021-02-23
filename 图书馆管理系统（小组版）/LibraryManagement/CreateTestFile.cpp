#include<iostream>
#include "BookManagementIOHeader.h"
#include "BookManagementIO.h"
#include "IdGenerator.h"
using namespace std;
void fillBlank (unsigned int arr[],int length){
    for(int i = 0;i < length; i++) arr[i] = 0;
}
int main(){
    string fname = "filePeopleInfo";
    people temp;
    ReaderClassIO rio;
    int i = 0;
    for(i = 0;i < 4; i ++) temp.peopleName[i] = 'f';
    temp.peopleName[i] = '\0';
    temp.isDeleted = '0';
    temp.isRealDeleted = '0';
    temp.level = 2;
    temp.credit = 100;
    for(i = 0;i < 5; i ++) temp.password[i] = '1';
    temp.password[i] = '\0';
    temp.peopleId = PeopleIdGenerater(fname);
    fillBlank(temp.booksBorrowed, 10);
    fillBlank(temp.recentBorrowId,20);
    rio.writeFile(temp,fname,0,5);
    return 0;
}
