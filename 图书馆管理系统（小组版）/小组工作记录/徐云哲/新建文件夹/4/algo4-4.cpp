//����algo4-3.cpp�������ļ�,������ѯͼ��

#include "c1.h"
typedef int ElemType;
#include "c2-5.h"
#include "c4-2.h"
#include "algo4-3.h"
#include "first.h"


//�ṹ�嶨��ͺ�����������algo4-3.h��
 void algo44_main()
 {
   FILE *f; // �κ�ʱ������һ���ļ�
   IdxListType idxlist; // ������
   BookListType booklist; // ��Ŀ��
   char buf[MaxLineLen+5]; // ��ǰ��Ŀ��(������ź�'\0')
   HString ch; // �����ַ���
   int BookNo; // ���
   Link p; // ����ָ��
   int i,j,k,flag=1; // flag�Ǽ�����ѯ�ı�־

   InitString(ch); // ��ʼ��HString���͵ı���
   if(!(f=fopen("BookIdx.txt","r"))) // �������ؼ����������ļ�
   {
       printf("BookIdx.txt can not open!\n");
       exit(OVERFLOW);
   }
   fscanf(f,"%d",&idxlist.last); // �����ؼ��ʸ���
   for(k=0;k
   {
      fscanf(f,"%s",buf);
      i=0;
      while(buf[i])
           buf[i++]=tolower(buf[i]); // ��ĸתΪСд
      InitString(idxlist.item[k].key);
      StrAssign(idxlist.item[k].key,buf);
      InitList(idxlist.item[k].bnolist); // ��ʼ���������bo2-6.cpp

      fscanf(f,"%d",&i);
      for(j=0;j
      {
          fscanf(f,"%d",&BookNo);
          MakeNode(p,BookNo); // �����µ���Ž�㣬bo2-6.cpp
          p->next=NULL; // ����Ž���ָ����ֵ
          Append(idxlist.item[k].bnolist,p); // �ڱ�β�����µ���Ž�㣬bo2-6.cpp
      }
   }
   fclose(f);

   if(!(f=fopen("Book.txt","r"))) // ����Ŀ�ļ�
   {
       printf("Can not open Book.txt\n");
       exit(FALSE);
   }
   i=0;
   while(fgets(buf,MaxLineLen,f))
   { // ����Ŀ�ļ������ݿ���booklist��
       booklist.item[i].bookno=atoi(buf); // ǰ��λ����Ϊ���
       strcpy(booklist.item[i++].bookname,&buf[4]); // ��buf��������ʼ���ַ���������booklist��
   }
   booklist.last=i;

   while(flag)
   {
       printf("��������Ŀ�Ĺؼ���(һ��)��");
       scanf("%s",buf);
       i=0;
       while(buf[i])
            buf[i++]=tolower(buf[i]); // ��ĸתΪСд
       StrAssign(ch,buf);
       i=0;
       do
       {
           k=StrCompare(ch,idxlist.item[i++].key); // bo4-2.cpp
       }while(k&&i<=idxlist.last);
       if(!k) // ���������д˹ؼ���
       {
           p=idxlist.item[--i].bnolist.head->next; // pָ���������д˹ؼ�����Ӧ�������Ԫ���
           while(p)
           {
               j=0;
               while(jdata!=booklist.item[j].bookno) // ��booklist������Ӧ�����
               j++;
               if(j
                  printf("= %s",booklist.item[j].bookno,booklist.item[j].bookname);
               p=p->next; // ���������
           }
     }
     else
         printf("û�ҵ�\n");
         printf("��������������1���˳�����������0��");
         scanf("%d",&flag);
         //getchar();
   }
   fclose(f);
   f=NULL;
   getchar(); system("cls");
 }


//����algo44_main()������һЩ�ط�����Ӧbook.txt�ļ����ݵĴ��ģʽ

