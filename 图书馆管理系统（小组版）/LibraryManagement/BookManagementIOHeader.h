#pragma once
#ifndef BOOKMANAGEMENTIOHEADER_H_INCLUDED
#define BOOKMANAGEMENTIOHEADER_H_INCLUDED
#include<cstring>
#include<iostream>
#include<io.h>
#include<sstream>

//用户等级定义
#define UserLevel 1
#define ManagerLevel 2
#define SuperManagerLevel 3



typedef struct{
    unsigned int id;
    int distance;
    char isDeleted;//is the record RealDeleted
}IndexTableInfo;
typedef struct{
    unsigned int id;
    int leftChild;//distance of left child
    int rightChild;//distance of right child
    int IndexTableDistance;//distance of the matched id inside the index table
    char isDeleted;
}ReflactTableInfo;
typedef struct{
	unsigned int bookId;//identify number for books
	unsigned int peopleId;//indentify number for readers
	int bookClass;//书籍分类,bookClass为0-25，分别对应26个分类
	float price;//价格
	char bookName[45];//书名,最大44个字节，22个汉字
	char publisher[25];//出版社,24个字节，12个汉字
	char author[25];//作者，24个字节，12个汉字
	char publishDate[5];//出版年份，4个字节，只有年份，例如2009
	char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
	char borrowFlag;//借出标志位
	char isReservedFlag;//预定标志位
	char isPreservedFlag;//保存本标志位
	char isLated;//是否逾期
	char isDeleted;//whether the record is delated(false as default)
	char isRealDeleted;//是否真正删除
}book;

typedef struct{
	unsigned int peopleId;//借书人编号
	unsigned int recentBorrowId[20];//最近借阅书籍编号
	unsigned int booksBorrowed[10];//已经借阅的书籍
	char password[10];//password for the user
	int level;//借书人级别
	int credit;//信用点
	char peopleName[20];//people's name
	char isDeleted;//whether the record is delated(false as default)
	char isRealDeleted;//是否真正删除
}people;
inline void fillCharArr(char arr[],int length){//fill the char arrays by '#'
        for(int index = 0;index < length; index++) arr[index] = '#';
}
inline void fillEmpty(book &temp){
        /*this function is used to fill in all blanks in the array
          when there is no datas in the data base
        */
    temp.bookId = 0;//identify number for books
	temp.peopleId = 0;//indentify number for readers
	temp.bookClass = 0;//书籍分类
	temp.price = 0.0;//价格
	fillCharArr(temp.bookName,45);
	fillCharArr(temp.publisher,25);
	fillCharArr(temp.author,25);
    fillCharArr(temp.publishDate,5);
	temp.borrowFlag = '0';
	temp.isReservedFlag = '0';//预定标志位
	temp.isPreservedFlag = '0';//保存本标志位
	temp.isLated = '0';//是否逾期
	temp.isDeleted = '0';//whether the record is delated(false as default)
	temp.isRealDeleted = '0';
}
inline void fillEmpty(people &temp){
        /*this function is used to fill in all blanks in the array
          when there is no datas in the data base
        */
    temp.peopleId = 0;//借书人编号
	for(int index = 0;index < 10;index ++) temp.recentBorrowId[index] = 0;//最近借阅书籍编号
	for(int index = 0;index < 5;index ++) temp.booksBorrowed[index] = 0;//已经借阅的书籍
	fillCharArr(temp.password,10);//password for the user
	temp.level = 0;//借书人级别
	temp.credit = 0;//信用点
	fillCharArr(temp.peopleName,20);//people's name
	temp.isDeleted = '0';//whether the record is delated(false as default)
	temp.isRealDeleted = '0';
}
inline bool findFileExisting(std::string fname){// find out whether a file exist
        /*warning, this function does not test whether the string is legal or not
          must be used after findDotDat
        */
        bool existing = true;//assume the file exist
        if(access(fname.data(),0) == -1) existing = false;
        return existing;
}
inline int findOccupy(std::string fname){// find out whether a file is occupied
        /*warning, this function does not test whether the string is legal or not
          must be used after findDotDat
        */
        int occupied = 6;//assume the file is occupied
        if(access(fname.data(),6) == 0) occupied = 0;//if not occupied
        return occupied;
}
//int preventCuting(std::ofstream outfile){
        /* this function is used to prevent cutting while writing into the file
        */
//        if(!outfile) return -1;
//        return 0;
//}
inline int findPath(std::string str){
        /* this function is used to find out whether there is a path inside the string
           the string should be something like 'c://Documents//c++//test//TestData.dat'
           and it will save the path if the file is not inside the floder of this program
        */
        std::string line_r("/"),line_l("\\"),dot(":");
        std::string testStr = str;
        unsigned int dotLocation = testStr.rfind(dot);//search for which disk the file is in
        if(dotLocation == std::string::npos) {//if not find, assume the file is inside the current position of this program
                if(findFileExisting(testStr)) return 0;//the file is inside the floder
                else{
                        std::cout << std::endl << "The file cannot be accessed" << std::endl;
                        return -1;//if cannot find ':', just assume it cannot find the file
                }
        }
        unsigned int replaceDecTemp = 0;//if it is not in current floder, turn the path to a formal one
        replaceDecTemp = testStr.find(line_r);
        while(replaceDecTemp!=std::string::npos){//testing whether the path is using '/'
                testStr.replace(replaceDecTemp,line_r.length(),line_l);
                replaceDecTemp = testStr.find(line_r);
        }//replace all '/' with '\\' if it uses '/'
        int lastPosition = str.rfind(line_l);//seek the final '\\', this operation means that all characters after this '\\' is file name

        return 0;
}
inline std::string findDotDat(std::string fname){
/* find whether there is ".dat" in the filename,
   if there is no such a postfix, add it on. And if
   the name is NULL(empty), auto-create a name for it
*/
        std::string temp, trans_temp;
        std::stringstream rec;
        int autoIndex = 1;
        temp = fname;
        if(temp.empty()) {//if one did not gave it a name
              trans_temp = "newfile.dat";
              while(findFileExisting(trans_temp)){//test, find a name not used before
                        trans_temp = "newfile";
                        rec.str("");//erase the string stream(.clear() only cleans the status of the stream)
                        rec << trans_temp << "_" << autoIndex;// using sstring to transform int to string, and conbine it with "newfile"
                        trans_temp = rec.str()+".dat";
                        autoIndex++;
              }// generate name like "newfile_1", "newfile_2" ...
              temp = trans_temp;
        }// if the file name does not exit, just create a new file
        if(temp.find(".dat") == std::string::npos) temp+=".dat";// if the filename doesn't have postfix ".dot", add such a postfix
        return temp;
}
inline void showInfo(book data){
        if(data.bookId != 0){
                std::cout << data.bookId << " " << data.peopleId << " " << data.bookClass << std::endl
                        << data.price << " " << data.bookName << " " << data.publisher << " " << data.author << std::endl
                        << " " << data.publishDate << " " << data.borrowTime << std::endl;
        }
}
/*
void showInfo(people data){
        if(data.peopleId != 0){
                std::cout <<
        }
}
*/
#endif // BOOKMANAGEMENTIOHEADER_H_INCLUDED
