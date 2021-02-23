//#include "stdafx.h"
#include "c_Book.h"
#include<fstream>

c_Book::c_Book()
{
}


c_Book::c_Book(string cName, string cIsbn, string cPrice, string cAuthor)
    :m_cName(cName),m_cIsbn(cIsbn),m_cPrice(cPrice),m_cAuthor(cAuthor)
{

}

c_Book::~c_Book()
{
}

string c_Book::GetName()
{
    return m_cName;
}

void c_Book::SetName(string cName)
{
    m_cName = cName;
}
string c_Book::GetIsbn()
{
    return m_cIsbn;
}
void c_Book::SetIsbn(string cIsbn)
{
    m_cIsbn = cIsbn;
}
string c_Book::GetPrice()
{
    return m_cPrice;
}
void c_Book::SetPrice(string cPrice)
{
    m_cPrice = cPrice;
}
string c_Book::GetAuthor()
{
    return m_cAuthor;
}


void c_Book::SetAuthor()
{
    m_cAuthor = m_cAuthor;
}

//将数据写入文件中
void c_Book::WriteData()
{
    ofstream oFile;
    oFile.open("book.txt", ios::binary|ios::app);
    try
    {
        oFile.write(m_cName.c_str(),NUM1);
        oFile.write(m_cIsbn.c_str(), NUM1);
        oFile.write(m_cPrice.c_str(), NUM2);
        oFile.write(m_cAuthor.c_str(), NUM2);
    }
    catch(...)
    {
        throw("file error occurred!");
        oFile.close();
    }
    oFile.close();
}

//从文件中删除数据，创建一个临时的文件，把不删除的部分放在临时文件
void c_Book::DeleteData(int iCount)
{
    long resPos;
    int iDataCount = 0;
    char tempBuf[NUM1*2+NUM2*2];
    fstream file("book.txt",ios::binary|ios::in|ios::out);
    fstream tempFile("temp.txt",ios::binary|ios::in|ios::out|ios::trunc);
    ofstream oFile;
    file.seekg(0,ios::end);
    resPos = file.tellg();
    iDataCount = resPos / (NUM1 * 2 + NUM2 * 2);
    if (iDataCount < 0 || iDataCount < iCount)
    {
        throw "input number error";
    }
    else
    {
        file.seekg(iCount*(NUM1 * 2 + NUM2 * 2), ios::beg);
        for (int i = 0; i < (iDataCount - iCount);i++)
        {
            memset(tempBuf,0, NUM1 * 2 + NUM2 * 2);
            file.read(tempBuf, NUM1 * 2 + NUM2 * 2);
            tempFile.write(tempBuf, NUM1 * 2 + NUM2 * 2);
        }
        file.close();
        tempFile.seekg(0,ios::beg);
        oFile.open("book.txt");
        oFile.seekp((iCount-1)*(NUM1 * 2 + NUM2 * 2),ios::beg);
        for (int i = 0; i < (iDataCount-iCount); i++)
        {
            memset(tempBuf, 0, NUM1 * 2 + NUM2 * 2);
            tempFile.read(tempBuf, NUM1 * 2 + NUM2 * 2);
            oFile.write(tempBuf, NUM1 * 2 + NUM2 * 2);
        }
    }
    tempFile.close();
    oFile.close();
    remove("temp.txt");
}

//获取文件中的数据
void c_Book::GetBookFromFile(int iCount)
{
    char cName[NUM1];
    char cIsbn[NUM1];
    char cPrice[NUM2];
    char cAuthor[NUM2];
    ifstream iFile("book.txt", ios::binary);
    try
    {
        iFile.seekg(iCount*(NUM1 + NUM1 + NUM2 + NUM2), ios::beg);
        iFile.read(cName, NUM1);
        if (iFile.tellg() > 0)
        {
            m_cName = cName;
        }
        iFile.read(cIsbn, NUM1);
        if (iFile.tellg() > 0)
        {
            m_cIsbn = cIsbn;
        }
        iFile.read(cPrice, NUM2);
        if (iFile.tellg() > 0)
        {
            m_cPrice = cPrice;
        }
        iFile.read(cAuthor, NUM2);
        if (iFile.tellg() > 0)
        {
            m_cAuthor = cAuthor;
        }
    }
    catch (...)
    {
        throw("file error occurred!");
        iFile.close();
    }
    iFile.close();
}





// 图书馆管理系统.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include"c_Book.h"
using namespace std;

#define CMD_COLS 80
#define CMD_LINES 25
#define PAGE 5
void SetScreenGrid();
void ClearScreen();
void SetSysCaption(const char* pText);
void ShowWelcome();
void ShowRootMenu();
void WaitView(int iCurPage);
void WaitUser();
void GuideInput();
int GetSelect();
long GetFileLength(ifstream &ifs);
void ViewData(int iSelPage=1);
void DeleteBookFromFile();
void MainLoop();

//设置屏幕的大小
void SetScreenGrid()
{
    char sysSetBuf[80];
    sprintf(sysSetBuf, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
    system(sysSetBuf);

}
//清屏
void ClearScreen()
{
    system("cls");
}

void SetSysCaption(const char *pText)
{
    char sysSetBuf[80];
    sprintf(sysSetBuf, "title %s", pText);
    system(sysSetBuf);
}
//设置欢迎信息e
void ShowWelcome()
{
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << setw(40);
    cout << "*******************" << endl;
    cout << setw(40);
    cout << "*   图书管理系统  *" << endl;
    cout << setw(40);
    cout << "*******************" << endl;

}

void ShowRootMenu()
{
    cout << setw(37);
    cout << "请选择功能：" << endl;
    cout << endl;
    cout << setw(36);
    cout << "1.添加图书" << endl;
    cout << endl;
    cout << setw(36);
    cout << "2.遍历图书" << endl;
    cout << endl;
    cout << setw(36);
    cout << "3.删除图书" << endl;
    cout << endl;
}
//浏览数据的时候等待用户操作
void WaitView(int iCurPage)
{
    string buf;
    cin >> buf;
    if (buf[0] == 'q')
        system("exit");
    if (buf[0] == 'm')
        MainLoop();
    if (buf[0] == 'n')
        ViewData(iCurPage);
}
//等待用户操作
void WaitUser()
{
    int iInputPage = 0;
    cout << "enter 返回主菜单 q退出" << endl;
    string strBuf;
    cin >> strBuf;
    if (strBuf[0] == 'q')
    {
        system("exit");
    }
}

int GetSelect()
{
    char strSelect[256];
    cin >> strSelect;
    return atoi(strSelect);
}

//添加图书信息
void GuideInput()
{
    char inName[NUM1];
    char inIsbn[NUM1];
    char inPrice[NUM2];
    char inAuthor[NUM2];
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << setw(36);
    cout << "请输入书名：";
    getchar();
    //gets_s(inName);
    fgets(inName, sizeof(inName), stdin);
    if(inName[strlen(inName) - 1] == '\n') inName[strlen(inName) - 1] = '\0';   // 去掉换行符
    cout << setw(36);
    cout << "请输入ISBN：";
    cin >> inIsbn;
    cout << setw(36);
    cout << "请输入价格：";
    cin >> inPrice;
    cout << setw(36);
    cout << "请输入作者：";
    cin >> inAuthor;
    c_Book inBook(inName, inIsbn, inPrice, inAuthor);
    inBook.WriteData();
    cout << "书籍已经添加！" << endl;
    WaitUser();
}

long GetFileLength(ifstream &ifs)
{
    long temPos;
    long resPos;
    temPos = ifs.tellg();
    ifs.seekg(0, ios::end);
    resPos = ifs.tellg();
    ifs.seekg(temPos, ios::beg);
    return resPos;
}

//浏览图书信息
void ViewData(int iSelPage)
{
    int iPage = 0;
    int iCurPage = 0;
    int iDataCount = 0;
    char inName[NUM1];
    char inIsbn[NUM1];
    char inPrice[NUM2];
    char inAuthor[NUM2];
    bool bIndex = false;
    iCurPage = iSelPage;
    ifstream iFile;
    iFile.open("book.txt",ios::binary);
    iDataCount = GetFileLength(iFile) / (NUM1 * 2 + NUM2 * 2);
    if (iDataCount >= 1)
    {
        bIndex = true;
    }
    iPage = iDataCount / PAGE + 1;
    ClearScreen();
    cout << "共有记录：" << iDataCount << " ";
    cout << "共有页数：" << iPage << " ";
    cout << "当前页数：" << iCurPage << " ";
    cout << "n 显示下一页 m 返回" << endl;
    cout << setw(5) << "index";
    cout << setw(20) << "Name" << setw(20) << "Isbn";
    cout << setw(15) << "price" << setw(15) << "author";
    cout << endl;
    try
    {
        iFile.seekg((iCurPage-1) * PAGE * (NUM1 * 2 + NUM2 * 2), ios::beg);
        if (!iFile.fail())
        {
            for (int i = 1; i <= PAGE; i++)
            {
//                cout << "********" << endl;
                memset(inName, 0, NUM1);
                memset(inIsbn, 0, NUM1);
                memset(inPrice, 0, NUM2);
                memset(inAuthor, 0, NUM2);
                if (bIndex)
                {
                    cout << setw(3) << (iCurPage - 1) * PAGE + i;
                    iFile.read(inName, NUM1);
                    cout << setw(20) << inName;
                    iFile.read(inIsbn, NUM1);
                    cout << setw(25) << inIsbn;
                    iFile.read(inPrice, NUM2);
                    cout << setw(10) << inPrice;
                    iFile.read(inAuthor, NUM2);
                    cout << setw(16) << inAuthor;
                    cout << endl;
                    if (iFile.tellg() < 0)
                    {
                        bIndex = false;
                    }
                    else
                    {
                        bIndex = true;
                    }
                }
            }
        }
    }
    catch (...)
    {
        cout << "throw file exception" << endl;
        throw "file error occurred";
        iFile.close();
    }
    if (iCurPage < iPage)
    {
        iCurPage = iCurPage + 1;
        WaitView(iCurPage);
    }
    else
    {
        WaitView(iCurPage);
    }
    iFile.close();

}

//删除图书信息
void DeleteBookFromFile()
{
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    int iDelCount;
    cout << "input delete index" << endl;
    cin >> iDelCount;
    c_Book cDelBook;
    cDelBook.DeleteData(iDelCount);
    cout << "已经删除图书!" << endl;
    WaitUser;
}

//主循环
void MainLoop()
{
    ShowWelcome();
    while (1)
    {
        ClearScreen();
        ShowWelcome();
        ShowRootMenu();
        switch (GetSelect())
        {
        case 1:
            ClearScreen();
            GuideInput();
            break;
        case 2:
            ClearScreen();
            ViewData();
            break;
        case 3:
            ClearScreen();
            DeleteBookFromFile();
            break;
        }
    }
}

int main()
{
    SetScreenGrid();
    SetSysCaption("图书管理系统");
    MainLoop();

    return 0;
}
