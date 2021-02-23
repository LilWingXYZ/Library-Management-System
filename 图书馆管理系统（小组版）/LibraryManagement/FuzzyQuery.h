#pragma once
#ifndef FUZZYQUERY_H_INCLUDED
#define FUZZYQUERY_H_INCLUDED
#include "BookManagementIO.h"
#include "BookManagementIOHeader.h"
#include "SearchOption.h"
#include <string>
#include <regex>
#include <map>
void deleteAllMark(string &s, const string &mark);//���ڸ���ģ����ѯ�����������ݵĿո�ȥ��������ƥ��
void fuzzyQueryBook(string match, string fname);//ģ����ѯ�������������ݡ�match��ȥƥ���ɡ�����+��������+���������γɵĴ���

void deleteAllMark(string &s, const string &mark)  //���ڳ�ȥ�����ĳ������mark���˴�Ϊ��ȥ�ո�
{
    unsigned int nSize = mark.size();
    //ɾ�������ո�(�ո�������)
    if(s[0]==' ')s[0] = 'K';//��ֹ��һ��������ǿո�����ǿո���Ϊ��K��;
    int Length = s.length();
    for(int i = 0; i < Length; i++){
            if(s[i] == ' '&&s[i+1] == ' '){
                        s.erase(i+1, nSize);
                        i = 0;
                        Length--;
            }
    }
    if(s[s.length()-1]==' '){s[s.length()-1]= 'K';}//��ֹ���һ�������ǿո�����ǿո���Ϊ��K��;
    //ͳ�ƿո���
        int countb = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                countb++;
            }
        }

    while(countb--)//���������ʽ��������
    {
        unsigned int pos = s.find(mark);
        cout <<"pos : " <<pos << endl;
        cout << "&s : "<<s << endl;

        if(pos == string::npos)//ֱ��string����
        {
            return;
        }

        s.erase(pos, nSize);
        s.insert(pos, ")(.)*|(.)*(");
        cout << "&s2 : "<<s << endl;
    }
}

void fuzzyQueryBook(string match, string fname){//ģ����ѯ�������������ݡ�match��ȥƥ���ɡ�����+��������+���������γɵĴ���
        deleteAllMark(match," ");
        string matchTemp = "(.)*("+match+")(.)*";
        regex e(matchTemp);//��ƺõ�������ʽƥ���ʽ
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
                                string bookNameTemp = ret[i].bookName;
                                string publisherTemp = ret[i].publisher;
                                string authorTemp = ret[i].author;//ģ��һ�����������
                                string str = bookNameTemp + publisherTemp + authorTemp
//                                            +bookNameTemp + authorTemp + publisherTemp
//                                            +publisherTemp + bookNameTemp + authorTemp
//                                            +publisherTemp + authorTemp + bookNameTemp
//                                            +authorTemp + bookNameTemp + publisherTemp
//                                            +authorTemp + publisherTemp+bookNameTemp
                                            ;
                                if(regex_match(str, e)){
                                    displayBooks(ret[i]);
                                    result++;//��¼�ҵ��ĸ���
                                }
                                distance++;//�Ҳ���������һ��

                        }
                        //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

                }
                else  //���û�ɹ����ļ�
                {
                        cout <<endl<<setw(57)<< "Read file error!QAQ!" << endl;
                }
        }
        if (result == 0)
        {
            cout <<endl<<setw(57)<< "Can't find books about such imformation.  " << endl;
                }

}
#endif // FUZZYQUERY_H_INCLUDED
