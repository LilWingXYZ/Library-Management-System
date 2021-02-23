//algo4-3.cpp 中使用的相关宏定义，bo2-6.cpp中的函数申明
#ifndef ALGO43H
#define ALGO43H

#include "c2-5.h"
#include "c4-2.h"
typedef int ElemType;
//bo2-6.cpp function
void MakeNode(Link &p,ElemType e);
void FreeNode(Link &p);
void InitList(LinkList &L);
void ClearList(LinkList &L);
void DestroyList(LinkList &L);
void InsFirst(LinkList &L,Link h,Link s); // 形参增加L,因为需修改L
Status DelFirst(LinkList &L,Link h,Link &q); // 形参增加L,因为需修改L
void Append(LinkList &L,Link s);
Position PriorPos(LinkList L,Link p);
Status Remove(LinkList &L,Link &q);
void InsBefore(LinkList &L,Link &p,Link s);
void InsAfter(LinkList &L,Link &p,Link s);
void SetCurElem(Link p,ElemType e);
ElemType GetCurElem(Link p);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Position GetLast(LinkList L);
Position GetHead(LinkList L);
Position NextPos(Link p);
Status LocatePos(LinkList L,int i,Link &p);
Position LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType));
void ListTraverse(LinkList L,void(*visit)(ElemType));
void OrderInsert(LinkList &L,ElemType e,int (*comp)(ElemType,ElemType));
Status LocateElem(LinkList L,ElemType e,Position &q,int(*compare)(ElemType,ElemType));


//algo4-3.cpp
#define MaxKeyNum 25 //索引表的最大容量（关键词的最大数目）
#define MaxLineLen 52  //数目串（也是一个书目中的关键词）的最大数目
#define MaxNoIdx 10

struct WordLisType//一个书目的词表（顺序表）和非索引词表（有序表）共用类型
{
    char *item[MaxNoIdx];   //词表（字符串）指针数组
    int last;   //词的数量
};

struct IdxTermType  //索引项类型
{
    HString key;   //关键词（堆分配类型，c4-2.h）
    LinkList bnolist;   //存放书号索引的链表（c2-5.h）
};

struct IdxListType    //索引表类型（有序表）
{
    IdxTermType item[MaxKeyNum+1];   //索引项数组类型
    int last;  //关键词的个数
};

void InitIdxList(IdxListType &idxlist);
void ExtractKeyWord(int &BookNo);
void GetWord(int i, HString &wd);
int Locate(IdxListType &idxlist, HString wd, Status &b);
void InsertNewKey(IdxListType &idxlist,int i,HString wd);
void InsertBook(IdxListType &idxlist, int i, int bno);
void InsIdxList(IdxListType &idxlist , int bno);
void PutText(FILE *f , IdxListType idxlist);
void algo43_main(void);

//algo4-4.cpp
#define MaxBookNum 10 // 假设只对10个书名建索引表
#define MaxKeyNum 25 // 索引表的最大容量(关键词的最大数目)

struct BookTermType // 书目项类型
{
    char bookname[MaxLineLen+1]; // 书名串(包括'\0')
    int bookno; // 书号
};

struct BookListType // 书目表类型(有序表)
{
    BookTermType item[MaxBookNum]; // 书目项数组类型
    int last; // 书目的数量
 };

void algo44_main();

#endif
