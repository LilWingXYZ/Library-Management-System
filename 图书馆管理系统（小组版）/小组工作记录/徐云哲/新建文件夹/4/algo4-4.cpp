//根据algo4-3.cpp产生的文件,索引查询图书

#include "c1.h"
typedef int ElemType;
#include "c2-5.h"
#include "c4-2.h"
#include "algo4-3.h"
#include "first.h"


//结构体定义和函数声明放在algo4-3.h中
 void algo44_main()
 {
   FILE *f; // 任何时间最多打开一个文件
   IdxListType idxlist; // 索引表
   BookListType booklist; // 书目表
   char buf[MaxLineLen+5]; // 当前书目串(包括书号和'\0')
   HString ch; // 索引字符串
   int BookNo; // 书号
   Link p; // 链表指针
   int i,j,k,flag=1; // flag是继续查询的标志

   InitString(ch); // 初始化HString类型的变量
   if(!(f=fopen("BookIdx.txt","r"))) // 打开书名关键词索引表文件
   {
       printf("BookIdx.txt can not open!\n");
       exit(OVERFLOW);
   }
   fscanf(f,"%d",&idxlist.last); // 书名关键词个数
   for(k=0;k
   {
      fscanf(f,"%s",buf);
      i=0;
      while(buf[i])
           buf[i++]=tolower(buf[i]); // 字母转为小写
      InitString(idxlist.item[k].key);
      StrAssign(idxlist.item[k].key,buf);
      InitList(idxlist.item[k].bnolist); // 初始化书号链表，bo2-6.cpp

      fscanf(f,"%d",&i);
      for(j=0;j
      {
          fscanf(f,"%d",&BookNo);
          MakeNode(p,BookNo); // 产生新的书号结点，bo2-6.cpp
          p->next=NULL; // 给书号结点的指针域赋值
          Append(idxlist.item[k].bnolist,p); // 在表尾插入新的书号结点，bo2-6.cpp
      }
   }
   fclose(f);

   if(!(f=fopen("Book.txt","r"))) // 打开书目文件
   {
       printf("Can not open Book.txt\n");
       exit(FALSE);
   }
   i=0;
   while(fgets(buf,MaxLineLen,f))
   { // 把书目文件的内容拷到booklist中
       booklist.item[i].bookno=atoi(buf); // 前几位数字为书号
       strcpy(booklist.item[i++].bookname,&buf[4]); // 将buf由书名开始的字符串拷贝到booklist中
   }
   booklist.last=i;

   while(flag)
   {
       printf("请输入书目的关键词(一个)：");
       scanf("%s",buf);
       i=0;
       while(buf[i])
            buf[i++]=tolower(buf[i]); // 字母转为小写
       StrAssign(ch,buf);
       i=0;
       do
       {
           k=StrCompare(ch,idxlist.item[i++].key); // bo4-2.cpp
       }while(k&&i<=idxlist.last);
       if(!k) // 索引表中有此关键词
       {
           p=idxlist.item[--i].bnolist.head->next; // p指向索引表中此关键词相应链表的首元结点
           while(p)
           {
               j=0;
               while(jdata!=booklist.item[j].bookno) // 在booklist中找相应的书号
               j++;
               if(j
                  printf("= %s",booklist.item[j].bookno,booklist.item[j].bookname);
               p=p->next; // 继续向后找
           }
     }
     else
         printf("没找到\n");
         printf("继续查找请输入1，退出查找请输入0：");
         scanf("%d",&flag);
         //getchar();
   }
   fclose(f);
   f=NULL;
   getchar(); system("cls");
 }


//调整algo44_main()函数的一些地方以适应book.txt文件数据的存放模式

