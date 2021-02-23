//algo4-3.cpp ��ʹ�õ���غ궨�壬bo2-6.cpp�еĺ�������
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
void InsFirst(LinkList &L,Link h,Link s); // �β�����L,��Ϊ���޸�L
Status DelFirst(LinkList &L,Link h,Link &q); // �β�����L,��Ϊ���޸�L
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
#define MaxKeyNum 25 //�����������������ؼ��ʵ������Ŀ��
#define MaxLineLen 52  //��Ŀ����Ҳ��һ����Ŀ�еĹؼ��ʣ��������Ŀ
#define MaxNoIdx 10

struct WordLisType//һ����Ŀ�Ĵʱ�˳����ͷ������ʱ��������������
{
    char *item[MaxNoIdx];   //�ʱ��ַ�����ָ������
    int last;   //�ʵ�����
};

struct IdxTermType  //����������
{
    HString key;   //�ؼ��ʣ��ѷ������ͣ�c4-2.h��
    LinkList bnolist;   //����������������c2-5.h��
};

struct IdxListType    //���������ͣ������
{
    IdxTermType item[MaxKeyNum+1];   //��������������
    int last;  //�ؼ��ʵĸ���
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
#define MaxBookNum 10 // ����ֻ��10��������������
#define MaxKeyNum 25 // ��������������(�ؼ��ʵ������Ŀ)

struct BookTermType // ��Ŀ������
{
    char bookname[MaxLineLen+1]; // ������(����'\0')
    int bookno; // ���
};

struct BookListType // ��Ŀ������(�����)
{
    BookTermType item[MaxBookNum]; // ��Ŀ����������
    int last; // ��Ŀ������
 };

void algo44_main();

#endif
