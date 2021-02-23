#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "User.h"
#include <windows.h>
#define numBookRecord 100//���ģ���鱾��¼����
#define numPeopleRecord 100//���ģ���û���¼����
using namespace std;


//����ö��ֵ��ȡ��Ӧ��������
string getBookValue(BookType num)
{

    switch(num)
    {
    case MaoDeng:
        return "�������塢ë��˼�롢��Сƽ����";
    case PhilosophyReligion:
        return "��ѧ�ڽ�";
    case Social:
        return "����ѧ����";
    case PoliticalLaw:
        return "���η���";
    case Military:
        return "����";
    case Economic:
        return "����";
    case Literature_PE:
        return "�Ļ�����ѧ������������";
    case Language:
        return "���ԡ�����";
    case Literature:
        return "��ѧ";
    case Art:
        return "����";
    case HistoryGeography:
        return "��ʷ������";
    case Nature:
        return "��Ȼ��ѧ����";
    case MathChemistry:
        return "�����ѧ�뻯ѧ";
    case Astronomy:
        return "����ѧ�������ѧ";
    case Biology:
        return "�����ѧ";
    case Medicine:
        return "ҽҩ������";
    case Agriculture:
        return "ũҵ��ѧ";
    case Industry:
        return "��ҵ����";
    case Transportation:
        return "��ͨ����";
    case Aerospace:
        return  "���ա�����";
    case EnvironmentSafety:
        return "������ȫ��ѧ";
    case Comprehensive:
        return "�ۺ���ͼ��";
    default:
        return "��ȡ��Ϣ����";
        break;
    }

}
//ͨ��ѧУͼ���a-z�����ȡ��Ӧ��int��
int getBookClass(char Number)
{
    switch (Number)
    {
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'C':
        return 3;
    case 'D':
        return 4;
    case 'E':
        return 5;
    case 'F':
        return 6;
    case 'G':
        return 7;
    case 'H':
        return 8;
    case 'I':
        return 9;
    case 'J':
        return 10;
    case 'K':
        return 11;
    case 'N':
        return 12;
    case 'O':
        return 13;
    case 'P':
        return 14;
    case 'Q':
        return 15;
    case 'R':
        return 16;
    case 'S':
        return 17;
    case 'T':
        return 18;
    case 'U':
        return 19;
    case 'V':
        return 20;
    case 'X':
        return 21;
    case 'Z':
        return 22;
    default:
        break;
    }
    return -1;//����
}



void showBookInfo(book data)
{
    if(data.bookId != 0)
    {
        cout<<"���NO."<<data.bookId<<endl;
        cout<<"�����˱��:"<<data.peopleId<<endl;
        cout<<"���ࣺ"<<getBookValue(BookType(data.bookClass))<<endl;
        cout<<"�۸�"<<data.price<<endl;
        cout<<"������"<<data.bookName<<endl;
        cout<<"�����磺"<<data.publisher<<endl;
        cout<<"���ߣ�"<<data.author<<endl;
        cout<<"�������ڣ�"<<data.publishDate<<endl;
        cout<<"���ʱ�䣺"<<data.borrowTime<<endl;
        cout<<"�����"<<data.borrowFlag<<endl;
        cout<<"Ԥ����"<<data.isReservedFlag<<endl;
        cout<<"���汾��"<<data.isPreservedFlag<<endl;
        cout<<"���ڣ�"<<data.isDeleted<<endl;
        cout<<"ɾ����"<<data.isDeleted<<endl;
    }
}

int main()
{


    string fileBookName = "fileBookInfo.dat";
    string filePeopleName = "filePeopleInfo.dat";
    BookClassIO bio;
    ReaderClassIO rio;
    if(!findFileExisting(fileBookName)) bio.createFile(fileBookName);
    if(!findFileExisting(filePeopleName)) rio.createFile(filePeopleName);
    int numBook =0;
    int numPeople =0;

///�鼮����ģ��
    ifstream fin("oucBook.csv"); //���ļ�������
    string line;

    while (getline(fin, line) && numBook < numBookRecord)   //���ж�ȡ�����з���\n�����֣������ļ�β��־eof��ֹ��ȡ
    {
        cout <<"primary string��"<< line << endl; //�������
        istringstream sin(line); //�������ַ���line���뵽�ַ�����istringstream��
        vector<string> fields; //����һ���ַ�������
        string field;
        while (getline(sin, field, ',')) //���ַ�����sin�е��ַ����뵽field�ַ����У��Զ���Ϊ�ָ���
        {
            fields.push_back(field); //���ոն�ȡ���ַ�����ӵ�����fields��
        }

        ///��Ϣ¼��
        book Book;
        Book.peopleId = 0;
        strcpy(Book.bookName,fields[0].c_str());
        strcpy(Book.author,fields[1].c_str());
        strcpy(Book.publisher,fields[2].c_str());
        strcpy(Book.publishDate,fields[3].c_str());
        Book.price = atoi(fields[4].c_str());
        Book.bookClass = getBookClass(fields[5][0]);
        strcpy(Book.borrowTime, "0000000000"); //time of lending the book,year xxxx month xx date xx hour xx
        Book.borrowFlag = '0';//�����־λ
        Book.isReservedFlag= '0';//Ԥ����־λ
        Book.isPreservedFlag= '0';//���汾��־λ
        Book.isLated= '0';//�Ƿ�����
        Book.isDeleted= '0';
        Book.isRealDeleted = '0';
        Book.bookId = BookIdGenerater(Book.bookName,Book.publisher,Book.author,Book.publishDate,Book.bookClass,fileBookName);

        ///չʾ��Ϣ
        cout <<"after dealed��"<<Book.bookId<< "\t" <<Book.peopleId<< "\t" <<Book.bookName << "\t" << Book.author << "\t" <<Book.publisher << "\t" << Book.publishDate<< "\t" << Book.price<<"\t"
             <<getBookValue(BookType(Book.bookClass-1))<< endl;

        cout<<"---------bookinfo------------"<<endl;
        showBookInfo(Book);
        ofstream fileout(fileBookName,ios::out|ios::binary|ios::app);//start to write file at the end of the file
        if(!fileout) //if the file doesn't exist, return this status
        {
            cout<<"�ļ�����!"<<endl;
            fileout.close();
        }
        numBook++;

        ///д���ļ�
        fileout.write((char *)&Book,sizeof(book));// write the messaged;
        if(numBook % 10 == 0)
        {

            int num = 1 + rand() % 5 ;//������ɸ���Ϊnum��
            numBook +=num;
            for(int i = 1 ; i < num ; i++)
            {
                Book.bookId +=1;
                ofstream fileout(fileBookName,ios::out|ios::binary|ios::app);//start to write file at the end of the file
                if(!fileout) //if the file doesn't exist, return this status
                {
                    cout<<"�ļ�����!"<<endl;
                    fileout.close();
                }
                fileout.write((char *)&Book,sizeof(book));// write the messaged;


            }


        }

        fileout.close();
    }
    cout<<"�����鱾������"<<numBook<<" �� !"<<endl;
    fin.close();

///�û�����ģ��


    while(numPeople < numPeopleRecord)
    {

        //��Ϣ¼��
        people temp;

        temp.peopleId = PeopleIdGenerater(filePeopleName);

        srand((unsigned)time(NULL));
        int num = 3+rand()%7;//�޶�Ӣ��������5-20����ĸ֮��
        char str[num];
        int i=0;
        while(i<num-1)
        {
            int s=0;
            s=char(97+rand()%26);
            str[i] = char(s);
            i++;
        }
        str[i] = '\0';
        strcpy(temp.peopleName,str);
        sprintf(temp.password,"%d",temp.peopleId);
        temp.level = 1+rand()%3;
        temp.credit = 100;
        temp.isDeleted = '0';
        temp.isRealDeleted = '0';
        for(int i = 0; i<MAX_BORROW; i++)
        {
            temp.booksBorrowed[i] = 0;
        }
        for(int i =0; i<MAX_RECENT_BORROW; i++)
        {
            temp.recentBorrowId[i] = 0;
        }

        //չʾ��Ϣ
        User user  = User(temp,fileBookName,filePeopleName);
        user.showUserInfo();

        //д���ļ�
        ofstream fileout1(filePeopleName,ios::out|ios::binary|ios::app);
         if(!fileout1) //if the file doesn't exist, return this status
        {
            cout<<"�ļ�����!"<<endl;
            fileout1.close();
        }
        fileout1.write((char *)&temp,sizeof(people));// write the messaged;
        numPeople++;
        fileout1.close();
    }
    cout<<"�����û�������"<<numPeople<<" �� !"<<endl;
    return 0;
}

