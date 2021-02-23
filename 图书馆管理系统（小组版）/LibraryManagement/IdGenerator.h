#pragma once
#ifndef IDGENERATOR_H_INCLUDED
#define IDGENERATOR_H_INCLUDED
#include <cmath>
#include "BookManagementIOHeader.h"
#include "SearchOption.h"
#include "DeleteOption.h"
#include <string>
using namespace std;
inline int hashOperation(char *arr,int length){
    /* this function is used to deal with the three string and change them into an id which is easy to identify
    */
    if(length <= 0 || !arr) return 0;//logic error, return 0
    char *p;
    int index = 0, hashLength = 0;
    unsigned int temp = 0,hashValue = 0;// 'temp' is an assistance hash value, try to verify the hash value
    hashLength = (int) pow(10.0,length) - 1;//set hash address table, generate Number for mod operation
    for(p = arr; *p ; p++,index ++){//produce hash value
        hashValue = 31 * hashValue + *p;//primary hash value
        if((index&1) == 0) temp ^= ((temp << 7)^(*p)^(temp >> 3));//secondary hash value
        else temp ^= (~((temp << 11)^(*p)^(temp >> 5)));
        temp = temp << index;
    }
    hashValue = ((hashValue%((int)hashLength/2))*((int)pow(10.0,hashValue/2)) + temp%((int)hashLength/2));//combine the values
    return hashValue;
}
inline bool charMatch(char *arr_O,char *arr_T,int length){
    /* compare two strings, and find out whether their length are the same value which match length(int)
    */
    int index = 0;
    char *p = arr_O,*q = arr_T;//detect whether there are still characters inside the array
    if(!p||!q) return false;//if one of them is null, no match
    for(;index < length&&p&&q;index ++,p++,q++)//compare all characters in the array
        if(arr_O[index] != arr_T[index]) return false;
    if(p||q) return false;//if there is still some characters inside one of the arrays(one of them is finished or both of them is not finished within 'length')
    else if(index < length) return false;//if arrays are shorter than expected, return false
    return true;
}
inline bool bookMatch(book obj,book test){
    /*this function is used to detect whether the books are identical
    */
    if(obj.bookClass != test.bookClass) return false;
	else if(!charMatch(test.bookName,obj.bookName,20)) return false;
	else if(!charMatch(obj.publisher,test.publisher,20)) return false;
        else if(!charMatch(obj.author,test.author,20)) return false;
        else if(!charMatch(obj.publishDate,test.publishDate,9)) return false;//if information about the book is not correct, return false
    return true;
}

inline int getIntDigit(unsigned int num){//get how many digits the number has
    int ret = 0;
    unsigned int temp = num;
    for(;temp!=0;ret ++, temp/=10);
    return ret;
}
inline unsigned int intCut(unsigned int obj,int begPosition,int endPosition){
    /*this function is used to get specific part of an int data, begPosition < endPosition,begPosition is where it begin to cut
      it's how many times that the number divide 10, example: 12345,cut '234', begPosition = 1, endPosition = 4
    */
    if(begPosition >= endPosition) return 0;//begPosition < endPosition
    else if(begPosition<0) return 0;//begPosition,endPosition>0
    else if(endPosition > getIntDigit(obj)) return 0;//endPosition should be smaller than the length of the number
    return ((obj/(int)pow(10.0,begPosition))%((int)pow(10.0,endPosition-begPosition)));
    // return the number, first cut the tail by dividing, then, cut the head by mod operation
}
inline bool idMatch(unsigned int id){
    /*this function is used to find out whether a book id matches the legal form*/
    if(id <= 0) return false;
    int temp = getIntDigit(id);
    if(temp < 8) return false;
    else if(temp > 9) return false;//if the length of the id is illegal
    int get = intCut(id,7,getIntDigit(id));
    if(get > 25 || get < 1) return false;
    return true;
}
inline bool idTest(unsigned int bookid,string fname){
    /* this function is used to test whether an id is legal
    */
    if(!idMatch(bookid)) return false;
    //if the digit number of the id get wrong
    int temp = 0;
    if((temp = searchInstanceOfBook(bookid,fname)) == -1||temp == -2) return false;// if there is no such a file or record
    if(!isRecNotDel(temp,fname)) return false;//if the data is deleted, return false
    return true;
}
inline int collideDetection(unsigned int value_O, unsigned int value_T,book testObject,book test){
    /* this function is used to detect hash collision and correct it
    */
    if(value_O == value_T&&bookMatch(testObject,test)) return -1;// if the books are of the same kind, and it got same id/
    else if(intCut(value_O,2,8) == intCut(value_T,2,8)&&!bookMatch(testObject,test)) return -2;
    return 0;
}
inline unsigned int BookIdGenerater(char *bookName,char *publisher,char *author,char *publishDate,int bookClass,string fname){
        /* use this function to generate hash value
        */
        if(!bookName||!publisher||!author||!publishDate) return 0;// if any information is lack
        if(bookClass <= 0 || bookClass > 25) return 0;// if bookClass is illegal
        unsigned int idHashValue = (hashOperation(bookName,8)+hashOperation(publisher,8)+hashOperation(author,8)+hashOperation(publishDate,8))%99999;//generate a hash value fits the blank
         int get = countSameBooks(bookClass*100000+idHashValue,fname);
        //if(curBookNum<= 0|| curBookNum > 99) return 0;//if there are too many books
        return(bookClass*10000000+idHashValue*100+get);//combine
}
inline bool idTest(people data,string fname){
    /*test whether people id matches the standard*/
    if(data.peopleId <= 10000) return false;
    return true;
}
inline unsigned int PeopleIdGenerater(string fname){
    /*build people id*/
    ReaderClassIO rio;
    people temp,ret[10];
    if(!findFileExisting(fname)){//set beginning id number, the file doesn't or its length is 0 means that it needs to be set up
        rio.createFile(fname);
        temp.level = 10000;
        rio.writeFile(temp,fname,0,3);
    }
    else if(rio.currentFileSize(fname) == 0){
        temp.level = 10000;
        rio.writeFile(temp,fname,0,3);
    }//initialization finish
    int curNum = rio.readFile(ret,fname,0,3);
    if(curNum == -2) return 0;//if open error, assume the file open error
    curNum = ++ret[0].level;
    temp.level = curNum;
    rio.writeFile(temp,fname,0,3);//refresh
    return ((unsigned int)curNum);
}

#endif // IDGENERATOR_H_INCLUDED
