#pragma once
#ifndef DELETEOPTION_H_INCLUDED
#define DELETEOPTION_H_INCLUDED
#include <iostream>
#include <iomanip>
#include<fstream>
#include <vector>
#include "windows.h"
#include "SearchOption.h"
#include "StdIO.h"
#include "BookManageMentIOHeader.h"
#include "BookManagementIO.h"
using namespace std;
inline bool isRecNotDel(int distance,string fname){
    if(distance < 0) return false;
    BookClassIO biostream;
    book temp[10];
    biostream.readFile(temp,fname,distance,2);
    if(temp[0].isDeleted=='1'||temp[0].isRealDeleted=='1') return false;
    return true;
}
/*----------------------------------------------falseDeleteBook-------------------------------------------------Top*/
//According to bookId
//void falseDeleteBookbyId(string filename,unsigned int bookId)
inline void falseDeleteBookbyId(string filename, book *b,int distance)

{
        //int distance = searchInstanceOfBook(b->bookId,filename);//Find the book's location in file
        StdIO io;
        if (distance >= 0 && b->isDeleted == '0')
        {
                int choice;
                cout <<endl<<setw(58)<< "Confirm Delete£¿ 1.delete 0.return: " ;                 //
                choice = io.get_Int();
                if (choice == 1)
                {
                        b->isDeleted = '1';
                        BookClassIO temp;
                        temp.writeFile(*b, filename, distance, 2); //Use Class BookClassIO's writeFile fuction£¬updating infomartion
                        cout<<endl<<setw(50)<< "Delete Book Successfully!" << endl;            //
                        Sleep(2000);                                                           //
                        return ;
                }
                else if (choice == 0)
                {
                        return ;
                }
        }
        else
        {
                cout <<endl<<setw(57)<< "Didn't find the book, Can't delete!" << endl;
                Sleep(2000);
        }
}

/*----------------------------------------------trueDeleteBook--------------------------------------------*/
//According to bookId
//void trueDeleteBookbyId(string filename,book *b,unsigned int bookId)
inline void trueDeleteBookbyId(string filename, book *b,int distance){
//        int distance = searchInstanceOfBook(b->bookId,filename);//Find the book's location in file
        StdIO io;
        if (distance>=0 && b->isRealDeleted == '0')
        {
                int choice;
                cout <<endl<<setw(58)<< "Confirm Delete£¿ 1.delete 0.return: " ;
                choice = io.get_Int();
                if (choice == 1)
                {
                        b->isRealDeleted = '1';
                        BookClassIO temp;
                        temp.writeFile(*b, filename, distance, 2); //Use Class BookClassIO's writeFile fuction£¬updating information
                        vector<unsigned int> deletedBookID;
                        vector<int> deletedBookDistance;
                        unsigned int allDeletedBookID;
                        int allDeletedBookDistance;
                        /*--------------------------------read file "deletedBookID" information--------------------Top*/
                        ifstream fin1("deletedBookID.txt");
                        //ifstream fin1("deletedBookID.dat",ios::in|ios::binary);
                        if (fin1)
                        {
                                fin1 >> allDeletedBookID;
                                for (int i = 0; (unsigned int)i < allDeletedBookID; i++)
                                {
                                        unsigned int temp;
                                        fin1 >> temp;
                                        deletedBookID.push_back(temp);
                                }
                                fin1.close();
                        }
                        /*--------------------------------read file "deletedBookID" information--------------------bottom*/
                        /*--------------------------------read file "deletedBookDistance" information--------------------top*/
                        ifstream fin2("deletedBookDistance.txt");
                        //ifstream fin2("deletedBookDistance.dat",ios::in|ios::binary);
                        if (fin2)
                        {
                                fin2 >> allDeletedBookDistance;
                                for (int i = 0; i < allDeletedBookDistance; i++)
                                {
                                        int temp;
                                        fin2 >> temp;
                                        deletedBookDistance.push_back(temp);
                                }
                                fin2.close();
                        }
                        /*--------------------------------read file "deletedBookDistance" information--------------------bottom*/
                        deletedBookID.push_back(b->bookId);                           //Add the new delete item's ID into bottom
                        deletedBookDistance.push_back(distance);                      //Add the new delete item's DISTANCE into bottom

                        /*--------------------------------write file "deletedBookID"--------------------top*/
                        ofstream fout1("deletedBookID.txt");
                        //ofstream fout1("deletedBookID.dat",ios::app|ios::binary);
                        if (fout1)
                        {
                                fout1<<deletedBookID.size()<<endl;
                                for (int i = 0; i < (int)deletedBookID.size(); i++)
                                {
                                        fout1 << deletedBookID[i] << endl;
                                }
                                fout1.close();
                        }
                        /*--------------------------------write file "deletedBookID"--------------------bottom*/
                        /*--------------------------------write file "deletedBookDistance"--------------------top*/
                        ofstream fout2("deletedBookDistance.txt");
                        //ofstream fout2("deletedBookDistance.dat",ios::app|ios::binary);
                        if (fout2)
                        {
                                fout2 << deletedBookDistance.size()<<endl;
                                for (int i = 0; i < (int)deletedBookDistance.size(); i++)
                                {
                                        fout2 << deletedBookDistance[i] << endl;
                                }
                                fout2.close();
                        }
                        /*--------------------------------write file "deletedBookDistance"--------------------bottom*/
                        cout<<endl<<setw(50)<< "Delete Book Successfully!" << endl;            //
                        Sleep(2000);                                                           //
                        return ;
                }
                else if (choice == 0)
                {
                        return ;
                }
        }
        else
        {
                cout <<endl<<setw(57)<< "Didn't find the book, Can't delete!" << endl;
                Sleep(2000);
        }
}


//-----------------------------------Lack searchInstanceOfPeople fuction------------------------------------------------------


/*----------------------------------------------falseDeletePeople-------------------------------------------------Top*/
//According to peopleId
//void falseDeletePeoplebyId(string filename,unsigned int peopleId)
inline void falseDeletePeoplebyId(string filename, people *p)
{
        StdIO io;
        int distance = searchInstanceOfPeople(p->peopleId,filename);//Find the people's location in file
        if (distance >= 0 && p->isDeleted == '0')
        {
                int choice;
                cout << "Confirm Delete£¿ 1.delete 0.return" << endl;
                choice = io.get_Int();
                if (choice == 1)
                {
                        p->isDeleted = '1';
                        ReaderClassIO temp;
                        temp.writeFile(*p, filename, distance, 2); //Use Class ReaderClassIO's writeFile fuction£¬updating infomartion
                        cout << "Delete User Successfully!" << endl;
                        return ;
                }
                else if (choice == 0)
                {
                        return ;
                }
        }
        else
        {
                cout << "Didn't find the user, Can't delete!" << endl;
        }
}

/*----------------------------------------------trueDeletePeople--------------------------------------------*/
//According to peopleId
//void trueDeletePeoplebyId(string filename,people *p,unsigned int peopleId)
inline void trueDeletePeoplebyId(string filename, people *p){
        int distance = searchInstanceOfPeople(p->peopleId,filename);//Find the people's location in file
        StdIO io;
        if (distance>=0 && p->isRealDeleted == '0')
        {
                int choice;
                cout << "Confirm Delete£¿ 1.delete 0.return" << endl;
                choice = io.get_Int();
                if (choice == 1)
                {
                        p->isRealDeleted = '1';
                        ReaderClassIO temp;
                        temp.writeFile(*p, filename, distance, 2); //Use Class ReaderClassIO's writeFile fuction£¬updating information
                        vector<unsigned int> deletedPeopleID;
                        vector<int> deletedPeopleDistance;
                        unsigned int allDeletedPeopleID;
                        int allDeletedPeopleDistance;
                        /*--------------------------------read file "deletedPeopleID" information--------------------Top*/
                        ifstream fin1("deletedPeopleID.txt");
                        //ifstream fin1("deletedPeopleID.dat",ios::in|ios::binary);
                        if (fin1)
                        {
                                fin1 >> allDeletedPeopleID;
                                for (int i = 0; (unsigned int)i < allDeletedPeopleID; i++)
                                {
                                        unsigned int temp;
                                        fin1 >> temp;
                                        deletedPeopleID.push_back(temp);
                                }
                                fin1.close();
                        }
                        /*--------------------------------read file "deletedPeopleID" information--------------------bottom*/
                        /*--------------------------------read file "deletedPeopleDistance" information--------------------top*/
                        ifstream fin2("deletedPeopleDistance.txt");
                        //ifstream fin2("deletedPeopleDistance.dat",ios::in|ios::binary);
                        if (fin2)
                        {
                                fin2 >> allDeletedPeopleDistance;
                                for (int i = 0; i < allDeletedPeopleDistance; i++)
                                {
                                        int temp;
                                        fin2 >> temp;
                                        deletedPeopleDistance.push_back(temp);
                                }
                                fin2.close();
                        }
                        /*--------------------------------read file "deletedPeopleDistance" information--------------------bottom*/
                        deletedPeopleID.push_back(p->peopleId);                           //Add the new delete item's ID into bottom
                        deletedPeopleDistance.push_back(distance);                      //Add the new delete item's DISTANCE into bottom

                        /*--------------------------------write file "deletedPeopleID"--------------------top*/
                        ofstream fout1("deletedPeopleID.txt");
                        //ofstream fout1("deletedPeopleID.dat",ios::app|ios::binary);
                        if (fout1)
                        {
                                fout1<<deletedPeopleID.size()<<endl;
                                for (int i = 0; i < (int)deletedPeopleID.size(); i++)
                                {
                                        fout1 << deletedPeopleID[i] << endl;
                                }
                                fout1.close();
                        }
                        /*--------------------------------write file "deletedPeopleID"--------------------bottom*/
                        /*--------------------------------write file "deletedPeopleDistance"--------------------top*/
                        ofstream fout2("deletedPeopleDistance.txt");
                        //ofstream fout2("deletedPeopleDistance.dat",ios::app|ios::binary);
                        if (fout2)
                        {
                                fout2 << deletedPeopleDistance.size()<<endl;
                                for (int i = 0; i < (int)deletedPeopleDistance.size(); i++)
                                {
                                        fout2 << deletedPeopleDistance[i] << endl;
                                }
                                fout2.close();
                        }
                        /*--------------------------------write file "deletedPeopleDistance"--------------------bottom*/
                        cout << "Delete User Successfully!" << endl;
                        return ;
                }
                else if (choice == 0)
                {
                        return ;
                }
        }
        else
        {
                cout << "Didn't find the user, Can't delete!" << endl;
        }
}
#endif
