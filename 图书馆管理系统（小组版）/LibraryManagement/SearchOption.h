#pragma once
#ifndef SEARCHOPTION_H_INCLUDED
#define SEARCHOPTION_H_INCLUDED
#include "BookManagementIO.h"
#include "StdIO.h"
#include <iomanip>
using namespace std;
//---------------�鱾��������------------------------------
void displayBooks(book ret);//չʾ
int countSameBooks(unsigned int hashNum,string fname);//�������ͬһ���顱�ж��ٱ�������������
void searchAllBooks(string fname);//������չʾ�����鼮
void searchBookById(unsigned int bookId,string fname);//����Ų�ѯ�鼮��Ϣ
void searchBookByPeopleId(unsigned int peopleId,string fname);//����������Ų�ѯ�鼮��Ϣ
void searchBookByClass(int bookClass,string fname);//���鼮����ѯ�鼮��Ϣ
void searchBookByPrice(float price1, float price2,string fname); //���۸� �����ѯ�鼮��Ϣ
void searchBookByName(char name[45],string fname);//�����ֲ�ѯ�鼮��Ϣ
void searchBookByPublisher(char publisher[25],string fname);//���������ѯ�鼮��Ϣ
void searchBookByAuthor(char author[25],string fname);//�����߲�ѯ�鼮��Ϣ
void searchBookByPublishDate(char publishDate[5],string fname);//���������ڲ�ѯ�鼮��Ϣ
void searchBookByBorrowTime(char borrowTime[11],string fname);//��������ڲ�ѯ�鼮��Ϣ
int  searchInstanceOfBook(unsigned int bookId,string fname);//��ѯ���������ĳ�������ļ����distance


//-----------------�û���������------------------------------
void displayPeople(people ret);
void searchAllPeople(string fname);
void searchPeopleById(unsigned int peopleId,string fname);
void searchPeopleByLevel(int level,string fname);
void searchPeopleByCredit(int credit,string fname);
int  searchInstanceOfPeople(unsigned int peopleId,string fname);

//*********************************��������*************************************
inline void displayBooks(book ret)
{
        StdIO io;
        if(ret.bookId != 0){
                if(ret.isLated == '1') io.setColor(io.enmCFC_Red,io.enmCBC_Black);
                else if(ret.borrowFlag == '1' || ret.isPreservedFlag == '1' || ret.isReservedFlag == '1') io.setColor(io.enmCFC_Yellow,io.enmCBC_Black);
                else io.setColor(io.enmCFC_Green,io.enmCBC_Black);
                cout <<endl;
                cout <<"�鼮���:                " << ret.bookId  << endl;
                cout <<"�����豾���û����:    " << ret.peopleId  << endl;
                cout <<"�鼮���:                " << ret.bookClass  << endl;
                cout <<"�۸�:                    " << ret.price  << endl;
                cout <<"����:                    " << ret.bookName  << endl;
                cout <<"������:                  " << ret.publisher  << endl;
                cout <<"����:                    " << ret.author  << endl;
                cout <<"��������:                " << ret.publishDate  << endl;
                cout <<"�������:                " << ret.borrowTime  << endl;
                cout <<"�Ƿ񱻽��:              " << ret.borrowFlag  << endl;
                cout <<"�Ƿ�ԤԼ:              " << ret.isReservedFlag  << endl;
                cout <<"�Ƿ񱣴汾:              " << ret.isPreservedFlag  << endl;
                cout <<"�Ƿ�����δ��:            " << ret.isLated  << endl;
                cout <<"�Ƿ��ڹݲ�������:        " << ret.isDeleted  << endl;
                io.setColor();
        }
}
inline int countSameBooks(unsigned int hashNum,string fname)//hashNum = class+hashnumber
{

        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int countB = 0;
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if( (hashNum == (ret[i].bookId/100) )&&( ret[i].isRealDeleted == '0'))
                                {
                                        countB++;
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        return countB;
}

//*********************************��������*************************************

//------------------------------book�Ĳ�ѯ����------------------------------------
inline void searchAllBooks(string fname) //������չʾ�����鼮
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4 || state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++)
                        {
                                displayBooks(ret[i]);//չʾ��ǰ�鼮����
                                distance++;//��¼����������Ŀ
                        }

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ! ." << endl;
                }
        }
}
inline int getBook(unsigned int bookId,string fname,book* Book){
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (bookId == ret[i].bookId)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : " << bookId << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        *Book = ret[i];
                                        return 0;
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                        return -1;
                }
        }
        cout <<endl<<setw(47)<< "���Ҳ�������鼮��Ű�������~ QAQ!" << endl;
        return -1;


}
inline void searchBookById(unsigned int bookId,string fname) //����Ų�ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (bookId == ret[i].bookId)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : �鼮��š�������" << bookId << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        return;
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        cout <<endl<<setw(47)<< "���Ҳ�������鼮��Ű�������~ QAQ!" << endl;
}

inline void searchBookByPeopleId(unsigned int peopleId,string fname) //����������Ų�ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (peopleId == ret[i].peopleId)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : �����߱�š�������" << peopleId << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
                cout <<endl<<setw(47)<< "���Ҳ�������û���Ű�������~ QAQ!" << endl;
        }
}
inline void searchBookByClass(int bookClass,string fname) //���鼮����ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (bookClass == ret[i].bookClass)
                                {
                                       cout <<endl<< "��嫺������ڣ����ٴ������� : ��𡪡�����" << bookClass << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(55)<< "���Ҳ�����������鼮��������~ QAQ!  " << endl;
        }
}
inline void searchBookByPrice(float price1, float price2,string fname) //���۸������ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (ret[i].price <= price2 && ret[i].price >= price1)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : �۸񡪡�����" <<  price1 << " ~ " << price2 << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
                cout <<endl<<setw(56)<< "���Ҳ�������۸��ڵ��鼮��������~ QAQ!" <<  price1 << " ~ " << price2 << endl;
        }
}
inline void searchBookByName(char name[45],string fname) //�����ֲ�ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (strcmp(name, ret[i].bookName) == 0)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : ������������" <<  name << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��
                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(54)<< "���Ҳ���һ����������ֵ��鼮��������~ QAQ!" << endl;
        }
}
inline void searchBookByPublisher(char publisher[25],string fname) //���������ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (strcmp(publisher, ret[i].publisher) == 0)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : �����硪������" <<  publisher << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(55)<< "���Ҳ���һ����������ֵĳ����������鼮��������~ QAQ!  " << endl;
        }
}

inline void searchBookByAuthor(char author[25],string fname) //�����߲�ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (strcmp(author, ret[i].author) == 0)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : ���ߡ�������" <<  author << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(52)<< "���Ҳ�������������д���鼮��������~ QAQ!  " << endl;
        }
}
inline void searchBookByPublishDate(char publishDate[5],string fname) //���������ڲ�ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (strcmp(publishDate, ret[i].publishDate) == 0)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� :�������ڡ������� " <<  publishDate << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(57)<< "���Ҳ���������ڳ�����鼮��������~ QAQ!  " << endl;
                }
}
inline void searchBookByBorrowTime(char borrowTime[11],string fname) //��������ڲ�ѯ�鼮��Ϣ
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (strcmp(borrowTime, ret[i].borrowTime) == 0)
                                {
                                        cout <<endl<< "��嫺������ڣ����ٴ������� : ���ʱ�䡪������" <<  borrowTime << endl;
                                        displayBooks(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                                        result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ
                }
                else  //���û�ɹ����ļ�
                {
                        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(56)<< "���Ҳ������ʱ�䱻���ȥ���鼮��������~ QAQ!  " << endl;
        }
}

inline int searchInstanceOfBook(unsigned int bookId,string fname)
{
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        while (distance < (bm.currentFileSize(fname)/sizeof(book))) //������û����ʱ,bm.currentFileSize(fname)Ϊ��ǰ�ļ���ʵ�����
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
                if (state == 0|| state == -4) //state��¼���ص��ļ��������0Ϊ�ɹ���
                {
                        for (int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
                        {
                                if (bookId == ret[i].bookId && ret[i].isRealDeleted!='1')return distance;//�ҵ����̷�������distance
                                distance++;//�Ҳ���������һ��
                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��
                }
                else return -2;//-2 means failed to open this file
        }
        return -1;//-1 means failed to find the record
}
//----------searchBookById-------book�Ĳ�ѯ����----------------------------


//-----------------people�Ĳ�ѯ����----------------------------//û����û���Թ�

inline void displayPeople(people ret){
    StdIO io;
    if(ret.peopleId < 10000) return;
    if(ret.credit<50) io.setColor(io.enmCFC_Yellow,io.enmCBC_Black);
    else if(ret.credit < 20) io.setColor(io.enmCFC_Red,io.enmCBC_Black);
    else if(ret.credit <10) io.setColor(io.enmCFC_Red,io.enmCBC_White);
    cout <<endl;
    cout << "�û����:                   " <<ret.peopleId<< endl;
    cout << "��������鼮�ı��:         " <<ret.recentBorrowId << endl;
    cout << "���ڽ��ĵ��鼮:             " <<ret.booksBorrowed << endl;
    cout << "����:                       " <<"**secret**"<< endl;
    cout << "Ȩ�޼���:                   " <<ret.level << endl;
    cout << "���õ�:                     " <<ret.credit << endl;
    cout << "�û�����:                   " <<ret.peopleName << endl;
    cout << "�Ƿ������û�����֮��:     " <<ret.isDeleted << endl;
    io.setColor();
}

inline void searchAllPeople(string fname){//������չʾ�����û���Ϣ
    ReaderClassIO pm ;
    people ret[10];//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(people)�ֽڵ�λ��
    while(distance < ((pm.currentFileSize(fname)/(sizeof(people))))){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(people)))Ϊ��ǰ�ļ���ʵ�����
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0 || state == -4){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                    cout << "�ҵ�����λ���˵���Ϣ(/�أ�) :" << ret[i].peopleId << endl;
                    displayPeople(ret[i]);
                    distance++;//�Ҳ���������һ��
            }

    }else{//���û�ɹ����ļ�
        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
    }
    }
}
inline void searchPeopleById(unsigned int peopleId,string fname){
    ReaderClassIO pm ;//����һ���鼮������Ķ���pm = peoplemanage����˼;
    people ret[10];
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    int flag = 0;
    while(distance < ((pm.currentFileSize(fname)/(sizeof(book))))){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0 || state == -4){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(peopleId<10000){cout << "���Ǹ��Ƿ�������ֵ��(/�أ�)" << endl;return;}
                if(peopleId == ret[i].peopleId){
                    cout << "�ҵ�����λ���˵���Ϣ(/�أ�) :��š�������" << peopleId << endl;
                    displayPeople(ret[i]);//�������ݣ������ҳ��Ǹ��û������ݲ�
                    return;
                }
                distance++;//�Ҳ���������һ��
            }

    }else{//���û�ɹ����ļ�
        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
    }
    }
    cout << "���Ҳ��������ŵ��û���Ϣ��������~ QAQ!: " << peopleId << endl;
}
// void searchPeopleByRecentBorrowId(unsigned int recentBorrowId[10],string fname);//��ʱ������
inline void searchPeopleByLevel(int level,string fname){//ͨ���û��ȼ���ѯ�û���Ϣ
    ReaderClassIO pm ;//����һ���鼮������Ķ���pm = peoplemanage����˼;
    people ret[10];
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(people)�ֽڵ�λ��
    while(distance < ((pm.currentFileSize(fname)/(sizeof(people))))){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(people)))Ϊ��ǰ�ļ���ʵ�����
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0 || state == -4){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(level == ret[i].level){
                    cout << "�ҵ�����λ���˵���Ϣ(/�أ�) :Ȩ�޵ȼ���������" << level << endl;
                    displayPeople(ret[i]);//�������ݣ������ҳ��Ǹ��û������ݲ�
                    return;
                }
                distance++;//�Ҳ���������һ��
            }

    }else{//���û�ɹ����ļ�
        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
    }
    }
    cout << "���Ҳ������������û���Ϣ��������~ QAQ!: " << level << endl;
}
inline void searchPeopleByCredit(int credit,string fname){//ͨ�����õȼ���ѯ�û���Ϣ
    ReaderClassIO pm ;//����һ���鼮������Ķ���pm = peoplemanage����˼;
    people ret[10];
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(people)�ֽڵ�λ��
    while(distance < ((pm.currentFileSize(fname)/(sizeof(people))))){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(people)))Ϊ��ǰ�ļ���ʵ�����
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0 || state == -4){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(credit == ret[i].credit){
                    cout << "�ҵ�����λ���˵���Ϣ(/�أ�)  :���õ㡪������" << credit << endl;
                    displayPeople(ret[i]);//�������ݣ������ҳ��Ǹ��û������ݲ�
                    return;
                }
                distance++;//�Ҳ���������һ��
            }

    }else{//���û�ɹ����ļ�
        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
    }
    }
    cout << "���Ҳ�����������õ�ֵ���û���Ϣ��������~ QAQ! " << credit << endl;
}
 inline int  searchInstanceOfPeople(unsigned int peopleId,string fname){//��ѯ�û���������ĳ�û����ļ����distance
    ReaderClassIO pm ;//����һ���鼮������Ķ���pm = peoplemanage����˼;
    people ret[10];
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(people)�ֽڵ�λ��
    while(distance < (pm.currentFileSize(fname)/sizeof(people))){//������û����ʱ,bm.currentFileSize(fname)Ϊ��ǰ�ļ���ʵ�����
    int state = pm.readFile(ret,fname,distance,mode);//int readFile(people returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0 || state == -4){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(peopleId == ret[i].peopleId&&ret[i].isRealDeleted!='1'){
                    cout << "��ӭ���ˣ� " <<ret[i].peopleName  <<" ( " << peopleId <<" ) " <<" ��ݹ��٣������ļ��е�����Ϊ : " <<distance<< endl;
                    return distance;//�ҵ����̷�������distance
                }
                distance++;//�Ҳ���������һ��
            }

    }else{//���û�ɹ����ļ�
        cout << "�ļ���Ȼ��ʧ����QAQ!" << endl;
        return -1;//-1����û�ѵ�����ļ�
    }
    }
    return -1;//-1����û�ѵ�����ļ�
}
//-----------------people�Ĳ�ѯ����----------------------------

#endif
