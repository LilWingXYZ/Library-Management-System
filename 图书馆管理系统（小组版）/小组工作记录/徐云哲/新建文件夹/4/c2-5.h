//���������ض���

#ifndef C2H
#define C2H

typedef int ElemType;
 // c2-5.h ��ͷ����������������
 typedef struct LNode // �������
 {
   ElemType data;
   LNode *next;
 }*Link,*Position;

 struct LinkList // ��������
 {
   Link head,tail; // �ֱ�ָ�����������е�ͷ�������һ�����
   int len; // ָʾ��������������Ԫ�صĸ���
 };

#endif
