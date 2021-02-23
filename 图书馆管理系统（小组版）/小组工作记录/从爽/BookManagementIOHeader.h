#ifndef BOOKMANAGEMENTIOHEADER_H_INCLUDED
#define BOOKMANAGEMENTIOHEADER_H_INCLUDED
#include<cstring>
#include<iostream>
#include<io.h>
#include<sstream>
typedef struct{
	unsigned int bookId;//identify number for books
	unsigned int peopleId;//indentify number for readers
	int bookClass;//书籍分类
	float price;//价格
	char bookName[20];//书名
	char publisher[20];//出版社
	char author[20];//作者
	char publishDate[9];//出版年份
	char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
	bool borrowFlag;//借出标志位
	bool isReservedFlag;//预定标志位
	bool isPreservedFlag;//保存本标志位
	bool isLated;//是否逾期
	bool isDeleted;//whether the record is delated(false as default)
	bool isRealDeleted;//is the record real
}book;
typedef struct{
	unsigned int peopleId;//借书人编号
	unsigned int recentBorrowId[10];//最近借阅书籍编号
	unsigned int booksBorrowed[5];//已经借阅的书籍
	char password[10];//password for the user
	int level;//借书人级别
	int credit;//信用点
	char peopleName[20];//people's name
	bool isDeleted;//whether the record is delated(false as default)
	bool isRealDeleted;//is the record real
}people;
void fillCharArr(char arr[],int length){//fill the char arrays by '#'
        for(int index = 0;index < length; index++) arr[index] = '#';
}
void fillEmpty(book &temp){
        /*this function is used to fill in all blanks in the array
          when there is no datas in the data base
        */
        temp.bookId = 0;//identify number for books
	temp.peopleId = 0;//indentify number for readers
	temp.bookClass = 0;//书籍分类
	temp.price = 0.0;//价格
	fillCharArr(temp.bookName,20);
	fillCharArr(temp.publisher,20);
	fillCharArr(temp.author,8);
        fillCharArr(temp.publishDate,8);
	temp.borrowFlag = false;
	temp.isReservedFlag = false;//预定标志位
	temp.isPreservedFlag = false;//保存本标志位
	temp.isLated = false;//是否逾期
	temp.isDeleted = false;//whether the record is delated(false as default)
}
void fillEmpty(people &temp){
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
	temp.isDeleted = false;//whether the record is delated(false as default)
}
bool findFileExisting(std::string fname){// find out whether a file exist
        /*warning, this function does not test whether the string is legal or not
          must be used after findDotDat
        */
        bool existing = true;//assume the file exist
        if(access(fname.data(),0) == -1) existing = false;
        return existing;
}
int findOccupy(std::string fname){// find out whether a file is occupied
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
int findPath(std::string str){
        /* this function is used to find out whether there is a path inside the string
        */
        return 0;
}
int pathSaving(std::string path){
        /* this function is used to restore the path of a file
        */
        std::ofstream outfile;
        return 0;
}
std::string findDotDat(std::string fname){
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
void showInfo(book data){
        if(data.bookId != 0){
                std::cout << data.bookId << " " << data.peopleId << " " << data.bookClass << std::endl
                        << data.price << " " << data.bookName << " " << data.publisher << " " << data.author << std::endl
                        << " " << data.publishDate << " " << data.borrowTime << " " << data.borrowFlag << std::endl
                        << " " << data.isReservedFlag << " " << data.isPreservedFlag << std::endl
                        << data.isLated << " " << data.isDeleted << std::endl;
        }
}
#endif // BOOKMANAGEMENTIOHEADER_H_INCLUDED
