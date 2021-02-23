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

//������д���ļ���
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

//���ļ���ɾ�����ݣ�����һ����ʱ���ļ����Ѳ�ɾ���Ĳ��ַ�����ʱ�ļ�
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

//��ȡ�ļ��е�����
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





// ͼ��ݹ���ϵͳ.cpp : �������̨Ӧ�ó������ڵ㡣
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

//������Ļ�Ĵ�С
void SetScreenGrid()
{
    char sysSetBuf[80];
    sprintf(sysSetBuf, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
    system(sysSetBuf);

}
//����
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
//���û�ӭ��Ϣe
void ShowWelcome()
{
    for (int i = 0; i < 7; i++)
    {
        cout << endl;
    }
    cout << setw(40);
    cout << "*******************" << endl;
    cout << setw(40);
    cout << "*   ͼ�����ϵͳ  *" << endl;
    cout << setw(40);
    cout << "*******************" << endl;

}

void ShowRootMenu()
{
    cout << setw(37);
    cout << "��ѡ���ܣ�" << endl;
    cout << endl;
    cout << setw(36);
    cout << "1.���ͼ��" << endl;
    cout << endl;
    cout << setw(36);
    cout << "2.����ͼ��" << endl;
    cout << endl;
    cout << setw(36);
    cout << "3.ɾ��ͼ��" << endl;
    cout << endl;
}
//������ݵ�ʱ��ȴ��û�����
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
//�ȴ��û�����
void WaitUser()
{
    int iInputPage = 0;
    cout << "enter �������˵� q�˳�" << endl;
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

//���ͼ����Ϣ
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
    cout << "������������";
    getchar();
    //gets_s(inName);
    fgets(inName, sizeof(inName), stdin);
    if(inName[strlen(inName) - 1] == '\n') inName[strlen(inName) - 1] = '\0';   // ȥ�����з�
    cout << setw(36);
    cout << "������ISBN��";
    cin >> inIsbn;
    cout << setw(36);
    cout << "������۸�";
    cin >> inPrice;
    cout << setw(36);
    cout << "���������ߣ�";
    cin >> inAuthor;
    c_Book inBook(inName, inIsbn, inPrice, inAuthor);
    inBook.WriteData();
    cout << "�鼮�Ѿ���ӣ�" << endl;
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

//���ͼ����Ϣ
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
    cout << "���м�¼��" << iDataCount << " ";
    cout << "����ҳ����" << iPage << " ";
    cout << "��ǰҳ����" << iCurPage << " ";
    cout << "n ��ʾ��һҳ m ����" << endl;
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

//ɾ��ͼ����Ϣ
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
    cout << "�Ѿ�ɾ��ͼ��!" << endl;
    WaitUser;
}

//��ѭ��
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
    SetSysCaption("ͼ�����ϵͳ");
    MainLoop();

    return 0;
}
