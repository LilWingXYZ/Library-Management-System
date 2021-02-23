#pragma once
#ifndef FUZZYQUERY_H_INCLUDED
#define FUZZYQUERY_H_INCLUDED
#include "BookManagementIO.h"
#include "BookManagementIOHeader.h"
#include "SearchOption.h"
#include <string>
#include <regex>
#include <map>
void deleteAllMark(string &s, const string &mark);//用于辅助模糊查询，把输入内容的空格去掉再拿来匹配
void fuzzyQueryBook(string match, string fname);//模糊查询（用搜索的内容“match”去匹配由“书名+出版社名+作者名”形成的串）

void deleteAllMark(string &s, const string &mark)  //用于除去输入的某个符号mark，此处为除去空格
{
    unsigned int nSize = mark.size();
    //删除连续空格(空格不能连续)
    if(s[0]==' ')s[0] = 'K';//防止第一个输入就是空格，如果是空格，则换为‘K’;
    int Length = s.length();
    for(int i = 0; i < Length; i++){
            if(s[i] == ' '&&s[i+1] == ' '){
                        s.erase(i+1, nSize);
                        i = 0;
                        Length--;
            }
    }
    if(s[s.length()-1]==' '){s[s.length()-1]= 'K';}//防止最后一个输入是空格，如果是空格，则换为‘K’;
    //统计空格数
        int countb = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                countb++;
            }
        }

    while(countb--)//添加正则表达式辅助符号
    {
        unsigned int pos = s.find(mark);
        cout <<"pos : " <<pos << endl;
        cout << "&s : "<<s << endl;

        if(pos == string::npos)//直到string结束
        {
            return;
        }

        s.erase(pos, nSize);
        s.insert(pos, ")(.)*|(.)*(");
        cout << "&s2 : "<<s << endl;
    }
}

void fuzzyQueryBook(string match, string fname){//模糊查询（用搜索的内容“match”去匹配由“书名+出版社名+作者名”形成的串）
        deleteAllMark(match," ");
        string matchTemp = "(.)*("+match+")(.)*";
        regex e(matchTemp);//设计好的正则表达式匹配格式
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。
        while (distance < (bm.currentFileSize(fname) / (sizeof(book)))) //当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
        {
                int state = bm.readFile(ret, fname, distance, mode); //int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
                if (state == 0|| state == -4) //state记录返回的文件打开情况，0为成功打开
                {
                        for (int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                        {
                                string bookNameTemp = ret[i].bookName;
                                string publisherTemp = ret[i].publisher;
                                string authorTemp = ret[i].author;//模拟一定级别的乱序
                                string str = bookNameTemp + publisherTemp + authorTemp
//                                            +bookNameTemp + authorTemp + publisherTemp
//                                            +publisherTemp + bookNameTemp + authorTemp
//                                            +publisherTemp + authorTemp + bookNameTemp
//                                            +authorTemp + bookNameTemp + publisherTemp
//                                            +authorTemp + publisherTemp+bookNameTemp
                                            ;
                                if(regex_match(str, e)){
                                    displayBooks(ret[i]);
                                    result++;//记录找到的个数
                                }
                                distance++;//找不到则找下一个

                        }
                        //前面十个找不到的话，再重新循环读十个

                }
                else  //如果没成功打开文件
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
