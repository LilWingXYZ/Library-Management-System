#ifndef INDEXBUILDER_H_INCLUDED
#define INDEXBUILDER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include "SearchOption.h"
#include "IdGenerator.h"
#include "BookManagementIO.h"
#include "BookManagementIOHeader.h"
std::string IntToString(unsigned int num){
    /*this function is int to string*/
    std::stringstream ssStream;
    ssStream<<num;
    return ssStream.str();
}
void showIndexTable(){
    /*show all information of the index table*/
    std::string fname = "IndexTable.dat";
    IndexFileIO fio;
    IndexTableInfo ret[10];
    int distance = 0,get = 0,maxNum = fio.currentFileSize(fname)/sizeof(IndexTableInfo);
    while(get!=-4&&distance<maxNum){
            distance ++;
            get = fio.readFile(ret,fname,distance-1,2);
            if(get == -2) return;//if the file opened wrongly,return
            std::cout << ret[0].id << std::endl;
            std::cout << ret[0].distance<< std::endl;
            std::cout << ret[0].isDeleted << std::endl;
    }
}
int searchIdIndexExisting(std::string fname,unsigned int bid,int mode){
    /*this function is used to see whether an id exists in the id-index table,if there isn't, return 0,
      else return distance of the book which has the bid(unsigned int)*/
    IndexFileIO fio;
    IndexTableInfo temp[10];
    int distance = 0, get = 0,maxNum = fio.currentFileSize(fname)/sizeof(IndexTableInfo);
    while(distance < maxNum){
        get = fio.readFile(temp,fname,distance,2);
        if(get == -2) return -2;//return file open error
        if(temp[0].id == bid){
                if(mode == 1) return temp[0].distance;// return distance distance of the book
                else if(mode == 2) return distance;//return index of the record
                else return -2;// the mode is illegal, assume the file is not open
        }
        distance ++;
    }
    return -1;//not find
}
int InsertIntoIndexMap(book bk,std::string fname_Orignal,int mode){
    /*this function is used to insert a data into the index table*/
    if(bk.bookId == 0) return -9;
    if(!idMatch(bk.bookId)) return -9;
    std::string fname = "IndexTable.dat";
    int get = searchIdIndexExisting(fname,bk.bookId,2);
    if(get == -2) return -2;//file open error
    if(get != -1) return 0;//if the record exists, just return 0
    IndexFileIO fio;//else if there is no such a record, add it
    IndexTableInfo temp;
    temp.id = bk.bookId;
    temp.distance = searchInstanceOfBook(bk.bookId,fname_Orignal);
    if(mode == 1) fio.writeFile(temp,fname,0,5);//add at the end of file
    else if(mode == 2) fio.writeFile(temp,fname,get,2);//replace
    else return -2;
    return 0;
}
int SetIndexMapTable(std::string fname_Orignal){
    /*this function is used to set a big table of id-index*/
    IndexFileIO fio;
    BookClassIO bio;// use the two stream to transform the data
    int get = 0,distance = 0,maxNum = bio.currentFileSize(fname_Orignal)/sizeof(book);
    book ret[10];//read book info
    IndexTableInfo temp;//write index info, using an array to compare whether there is such a record
    std::string fname  = "IndexTable.dat";// name of the index table

    if(findFileExisting(fname)) fio.turncateFile(fname);//if there is such a file, to prevent rebuild data there is, delete the original one?
    fio.createFile(fname);//create file by file io option

    while(distance < maxNum){
        get = bio.readFile(ret,fname_Orignal,distance,1);//open file and read book info
        if(get == -2) return -1;
        for(int i=0;i<10 && distance < maxNum;i++,distance++){//transformation from book information to id-index
            if(ret[i].bookId!=0) {//if there is data, save the record
                temp.id = ret[i].bookId;//copy information
                temp.distance = distance;
                temp.isDeleted = ret[i].isRealDeleted;
                fio.writeFile(temp,fname,0,5);// add the data to the index
            }
        }
    }
    return 0;
}
int setIndexTables(std::string OrginName){
        int temp = 1, length = 0,distance = 0,i = 0;
        IndexFileIO fio;
        IndexTableInfo rec[10],temp;
        std::string temp_fname,fname;
        std::stringstream ss;
        length = fio.currentFileSize(OrginName)/sizeof(IndexTableInfo);
        do{
                ss.str("");//clean string stream
                ss << temp;//converting into string
                temp_fname = ss.str();
                fname = findDotDat(temp_fname);//adding '.dot'
                if(!findFileExisting(fname)) fio.createFile(fname);//if there is no such a file, create one
                for(i = 0;i < length; i++){
                        fio.readFile(rec,OrginName,i,2);
                        if(((int)intCut(rec[0].id,7,getIntDigit(rec.id))) == temp)
                                fio.writeFile(rec[0],fname,0,5);//if id of the record matches currant index filename, write it, or continue
                }
                temp ++;
        }while(temp <= 25);
        return 0;
}
int findRecord(unsigned int id,int mode){
        if(mode!=1&&mode!=2&&mode!=3){
                std::cout << std::endl << "mode error" << std::endl;
                return -2;
        }
        int temp = 0,length = 0;
        unsigned int tempId = id;
        temp = (int) intCut(tempId,7,getIntDigit(tempId));//get digit, and prepare to tran
        std::string fname;
        std::stringstream ss;
        ss << temp;//tranverse it to string
        fname = ss.str();
        findDotDat(fname);
        if(!findFileExisting()){
                std::cout << std::endl << "cannot find such a record in the index, please try to update the index" << std::endl;
                return -1;
        }
        IndexTableInfo rec[10];
        IndexFileIO fio;
        length = fio.currentFileSize(fname)/sizeof(IndexTableInfo);
        for(int i = 0;i < length; i ++){
                fio.readFile(rec,fname,i,2);
                if(rec[0].id == id){// if find  this record
                        if(rec[0].isDeleted == '0'&&mode == 1) return rec[0].distance;//return its distance in the file while not deleted, mode = 1
                        else if(rec[0].isDeleted == '0'&&mode == 2) return i;//return its distance in the indextable while not deleted, mode = 2
                        else if(rec[0].isDeleted == '1'&&mode == 3) return i;//return its distance in the indextable while deleted, mode = 3
                        else{
                                std::cout << std::endl << "this object has been deleted" << std::endl;
                                return -2;
                        }
                }
        }
        std::cout << std::endl << "cannot find such a record in the index, please try to update the index" << std::endl;
        return -1;//not find the record;
}
int insertIndexTables(unsigned int id,char isDeleted,int distance){
        /*warnning, this function won't figure out whether data is illegal*/
        int get = findRecord(id);
        if(get != -1){
                std:cout << "this record exists" << std::endl;
                return 0;
        }
        IndexFileIO fio;//if the record doesn't exists, add it in
        IndexTableInfo temp;
        temp.id = id;
        temp.isDeleted = isDeleted;
        temp.distance = distance;//copy values
        int rec = (int)intCut(id,7,getIntDigit(id));
        std::string fname;
        std::stringstream ss;
        ss << temp;//tranverse it to string
        fname = ss.str();
        findDotDat(fname);//form the filename
        if(!findFileExisting()) fio.createFile(fname);
        fio.writeFile(temp,fname,0,5);
        return 0;
}
int updateStatus(unsigned int id,std::string filename){
        int get = findRecord(id);
        if(get == -1){
                std::cout << "the record doesn't exists" << std::endl;
                return -1;
        }
        else{

        }
        return 0;
}
#endif // INDEXBUILDER_H_INCLUDED
