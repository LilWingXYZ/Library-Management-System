#ifndef __C_BOOK_H__
#define __C_BOOK_H__

#include<string>
#include<iostream>
using namespace std;
#define NUM1 128
#define    NUM2 50
class c_Book
{
public:
    c_Book();
    c_Book(string cName,string cIsbn, string cPrice, string cAuthor);
    ~c_Book();
public:
    string GetName();
    void SetName(string cName);
    string GetIsbn();
    void SetIsbn(string cIsbn);
    string GetPrice();
    void SetPrice(string cPrice);
    string GetAuthor();
    void SetAuthor();
    void WriteData();
    void DeleteData(int iCount);
    void GetBookFromFile(int iCount);
private:
    string m_cName;
    string m_cIsbn;
    string m_cPrice;
    string m_cAuthor;
};


#endif // !__C_BOOK_H__

