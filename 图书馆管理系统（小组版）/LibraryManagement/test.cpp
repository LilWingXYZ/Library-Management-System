#include <iostream>
#include "BookManagementIO.h"
//#include "IndexBuilder.h"
#include "IdGenerator.h"
using namespace std;
int main(){

    string fileName = "PeopleTest.dat";
    ReaderClassIO rio;
    people temp,ret[10];
    int get = 0;
    if(!findFileExisting(fileName)) rio.createFile(fileName);
    while(1){
        cout << "____________________" << endl;
        cout << "please input data:" << endl;
        cout << "id :" <<endl;
        cin >> temp.peopleId;
        cout << "name :" << endl;
        cin >> temp.peopleName;
        cout << "credit :" <<endl;
        cin >> temp.credit;
        temp.level = 0;
        temp.isDeleted = '0';
        temp.isRealDeleted = '0';
        for(int i = 0;i<5;i++) temp.booksBorrowed[i] = i+1;
        for(int i =0;i<10;i++){
            temp.recentBorrowId[i] = i+1;
            temp.password[i] = '1';
        }
        rio.writeFile(temp,fileName,0,5);
        cout << "end?0.exit" << endl;
        cin >> get;
        if(get == 0) break;
    }
    rio.readFile(ret,fileName,0,1);
    for(int i = 0;i<10;i++){
        cout << ret[i].peopleId << " " << ret[i].peopleName << endl;
        cout << ret[i].password << " " << ret[i].isDeleted << endl;
        cout << ret[i].isRealDeleted << " " << ret[i].level<<endl;
        cout << ret[i].booksBorrowed[2] << " " << ret[i].recentBorrowId[4] << endl;
    }

    /**
    string fileName = "oucBookInfo.dat";
    SetIndexMapTable(fileName);
    showIndexTable();
    return 0;
    */
}
