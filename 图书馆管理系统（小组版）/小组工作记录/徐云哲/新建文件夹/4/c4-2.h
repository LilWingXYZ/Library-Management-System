#ifndef C4H
#define C4H

 // c4-2.h 串的堆分配存储
 struct HString
 {
   char *ch; // 若是非空串，则按串长分配存储区，否则ch为NULL
   int length; // 串长度
 };

 //bo4-2.cpp function
 void StrAssign(HString &T,char *chars);
 void StrCopy(HString &T,HString S);
 Status StrEmpty(HString S);
 int StrCompare(HString S,HString T);
 int StrLength(HString S);
 void ClearString(HString &S);
 void Concat(HString &T,HString S1,HString S2);
 Status SubString(HString &Sub, HString S,int pos,int len);
 void InitString(HString &T);
 int Index(HString S,HString T,int pos);
 Status StrInsert(HString &S,int pos,HString T);
 Status StrDelete(HString &S,int pos,int len);
 Status Replace(HString &S,HString T,HString V);// 此函数与串的存储结构无关
void StrPrint(HString T);

#endif
