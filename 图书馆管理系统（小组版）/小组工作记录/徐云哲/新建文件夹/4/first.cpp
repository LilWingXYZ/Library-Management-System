#include "c1.h"
#include "algo4-3.h"
#include "first.h"

//函数及结构体申明在first.h中

BK *h_book;
RD *h_reader;

int Menu()
{
//int sn;
    int sn=-1;
 printf("\n\t\t图书管理系统主菜单\n");
 printf("==========================================================\n");
 printf("*\t0----退出系统          6----关于系统    \t*\n");
 printf("*\t1----新书入库          7----旧书出库    \t*\n");
 printf("*\t2----增新读者          8----注销读者    \t*\n");
 printf("*\t3----查询图书/读者     9----输出全部信息\t*\n");
 printf("*\t4----借书登记         10----库存不足图书\t*\n");
 printf("*\t5----还书管理         11----保存当前信息\t*\n");
 printf("==========================================================\n");
 printf("请选择相应代码:");
 for(;;)
 {
     fflush(stdin);
   scanf("%d",&sn);
   getchar();
   if(sn<0||sn>11)
      printf("\n错误!请重新输入:");
   else break;
 }
  return sn;
}//"Menu()"end

void Menu_select()
{
    char i='n';
  for(;;)
 {
   switch(Menu())
   {
     case 0:
            //char i='n';
            printf("是否保存当前更改 y/n？");
            scanf("%c",&i);
            getchar();

            if( i=='y')
            {
                system("cls");
                Save();
                printf("\n\n\t文件保存成功!\n");
                printf("\n\n\tGoodBye!\n");
                getchar();
            }
            else
                printf("\n\n\t放弃文件保存!\n");

            getchar();
            exit(0);

   case 1:Insert_New_Book();break;
   case 2:Insert_New_Reader();break;
   case 3:Find_Select();break;
   case 4:Borrow_Book();break;
   case 5:Return_Book();break;
   case 6:about();break;
   case 7:del_old_book();break;
   case 8:del_old_reader();break;
   case 9:Print_Select();break;
   case 10:book_not_enough();break;
   case 11:Save(); Load();
          printf("\n文件保存成功!按任意键进行下步操作....");
          getchar(); system("cls");break;
   default:printf("\n输入错误，请重新输入!"); break ;
   }
  }//"switch(Menu())"
}//"Menu_select()"end


void Init()
{
    Init_reader();
    Init_book();
}//"Init()" end

void Init_reader()
{
     RD *p0=NULL;
     int i;
     printf("\n读者初始化开始,请输入读者信息..\n包括编号.姓名..\n");
     p0=(RD *)malloc(sizeof(RD));
     h_reader=p0;

     printf("\n请输入读者的信息:\n");
     printf("ReaderNo.:");
     scanf("%s",p0->reader_num);
     getchar();
     printf("ReaderName:");
     gets(p0->reader_name);
     p0->right=0;
     for(i=0;i
     strcpy(p0->borrow[i].borrow_book_num,"0");

     p0->next=NULL;
     p0=NULL;
     printf("\n读者信息初始化完毕!按任意键继续下一步操作..\n");

     getchar();
     system("cls");
}//"Init_reader()" end

void Init_book()
{
    BK *p0=NULL;
    printf("\n图书初始化开始,请输入图书信息..\n包括编号.书名.数量..\n");
    p0=(BK *)malloc(sizeof(BK));
    h_book=p0;

    printf("\n请输入图书信息:\n");
    printf("BookNo.:");
    scanf("%s",p0->book_num);
    getchar();
    printf("BookName:");
    gets(p0->book_name);
    printf("Number:");
    scanf("%d",&p0->book_kc);
    getchar();

    p0->book_xc=p0->book_kc;
    p0->next=NULL;
    p0=NULL;
    printf("\n图书信息初始化完毕!按任意键继续下一步操作..\n");

    getchar();
    system("cls");
}//"Init_book()" end


void Insert_New_Reader()
{
    RD *p=NULL,*p0=NULL,*p1=NULL,*p2=NULL;
    int i;
    p=p1=p2=h_reader;
    printf("\n增加新读者模块...\n");
    printf("\n请输入新读者信息..\n包括编号.姓名..\n");
    p0=(RD *)malloc(sizeof(RD));
  re_input_reader:
      printf("ReaderNo.:");
       scanf("%s",p0->reader_num);

       while(strcmp(p0->reader_num,p2->reader_num)!=0&&p2->next!=NULL)
           p2=p2->next;

       if(strcmp(p0->reader_num,p2->reader_num)==0)
       {
           printf("\n此编号读者已存在!请重新输入\n");
           goto re_input_reader;
       }

      printf("ReaderName:");
       scanf("%s",p0->reader_name);
       p0->right=0;

       for(i=0;i
       strcpy(p0->borrow[i].borrow_book_num,"0");

       while(strcmp(p->reader_num,p0->reader_num)!=0&&p->next!=NULL)
       {
              p1=p; p=p->next;
       }
          if(strcmp(p0->reader_num,p->reader_num)<=0)
          {
              if(p==h_reader) h_reader=p0;
              else p1->next=p0;
               p0->next=p;
          }
          else
          {
              p->next=p0;
              p0->next=NULL;
          }

      p=NULL;p0=NULL;p1=NULL;p2=NULL;
      printf("\n新读者增加完毕!按任意键继续下一步操作..\n");
      getchar();
      system("cls");

}//"Insert_New_Book()" end

void Insert_New_Book()
{
    BK *p=NULL,*p0=NULL,*p1=NULL,*p2=NULL;
    p=p1=p2=h_book;
    printf("\n新书入库模块...\n");
    printf("\n请输入新书信息..\n包括编号.书名.数量..\n");

    p0=(BK *)malloc(sizeof(BK));

       printf("BookNo.:");
       scanf("%s",p0->book_num);
       getchar();

       while(strcmp(p0->book_num,p2->book_num)!=0&&p2->next!=NULL)
           p2=p2->next;
       if(strcmp(p0->book_num,p2->book_num)==0)
       {
           printf("\n此编号图书已存在!!直接入库!\n");
           printf("Number:");
           scanf("%d",&p0->book_kc);
           getchar();
           p2->book_kc+=p0->book_kc;
            p2->book_xc+=p0->book_kc;
            goto end;
       }

      printf("BookName:");
      gets(p0->book_name);
      printf("Number:");
      scanf("%d",&p0->book_kc);
      getchar();
         p0->book_xc=p0->book_kc;

         while(strcmp(p->book_num,p0->book_num)!=0&&p->next!=NULL)
          {
              p1=p; p=p->next;
          }
          if(strcmp(p0->book_num,p->book_num)<=0)
          {
              if(p==h_book) h_book=p0;
              else p1->next=p0;
               p0->next=p;
          }
          else
          {
              p->next=p0;
              p0->next=NULL;
          }

        end:
      algo43_main();  //生成关键字索引表，在algo4-3.cpp中定义
      p=NULL;p0=NULL;p1=NULL;p2=NULL;
      printf("\n新书入库完毕!按任意键继续下一步操作..\n");
      getchar();
      system("cls");
}//"Insert_New_Book()" end

int Find()
{
    int sn;
    printf("\n\t\t打印全部信息菜单\n");
    printf("===============================================\n");
    printf("*\t0----返回上级     1----关于系统  \t*\n");
    printf("*\t                                 \t*\n");
    printf("*\t2----查找图书     3----查找读者  \t*\n");
    printf("===============================================\n");
    printf("请选择相应代码:");
  for(;;)
  {
      fflush(stdin);
      scanf("%d",&sn);
      getchar();
      if(sn<0||sn>3)
          printf("\n错误!请重新输入:");
      else break;
  }
  return sn;
}//"Find()" end

void Find_Select()
{
    system("cls");
    for(;;)
 {
  switch(Find())
  {
   case 0:system("cls"); Menu_select(); break;
   case 1:about();break;
   case 2:Find_Book_contral();break;
   case 3:Find_Reader();break;
   default:printf("\n错误!");exit(0);
   }
  }
}//"Find_Select()"end

int Find_Book_select()
{
    int sn;
    printf("\n\t\t打印全部信息菜单\n");
    printf("=================================================\n");
    printf("*\t 0----返回上级         \n");    //MY  1 这条应该改成 关于查询系统 或是 查询帮助
    printf("*\t                                 \t*\n");
    printf("*\t 1----编号查询         2----关键字查询\t*\n");
    printf("=================================================\n");
    printf("请选择相应代码:");
    for(;;)
    {
        fflush(stdin);
        scanf("%d",&sn);
        getchar();
        if(sn<0||sn>3)
            printf("\n错误!请重新输入:");
        else break;
    }
  return sn;
}//"Find_Book_select()"end

void Find_Book_contral()
{
    system("cls");
    for(;;)
    {
        switch( Find_Book_select() )
        {
        case 0:system("cls"); Find_Book_select(); break;
        case 1:Find_Book();break;
        case 2:algo44_main();break;  //algo44_main()algo4-4.cpp中定义
        default:printf("\n错误!");exit(0);
        }
    }
}//"Find_Book_contral()"end

void Find_Book()
{
    BK *p=NULL;
    char find_book[10];
    p=h_book;
    printf("\n图书查询模块\n");
    printf("\n请输入你要查询图书编号:");
    scanf("%s",find_book);
    getchar();

     while(strcmp(p->book_num,find_book)!=0&&p->next)
         p=p->next;

     if(strcmp(p->book_num,find_book)==0)
     {
        printf("\n图书编号:%s的信息为:\n",find_book);
        printf("\nBookNo.\t\tBookName\t\t\tXianCun \tKuCun\n");
        printf("%s\t\t%s\t\t=\t\t=\n",p->book_num,p->book_name,p->book_xc,p->book_kc);
     }
      else
         printf("\n此图书编号不存在,请核对!按任意键返回...");

    p=NULL;
    getchar(); system("cls");
}//"Find_Book()"end

void Find_Reader()
{
    RD *p=NULL;
    int i;
    char find_reader[10];
    p=h_reader;
    printf("\n查询模块\n");
    printf("\n请输入你要查询读者编号:");
    scanf("%s",find_reader);
    getchar();

     while(strcmp(p->reader_num,find_reader)!=0&&p->next)
         p=p->next;
     if(strcmp(p->reader_num,find_reader)==0)
     {
       printf("\n读者编号:%s的信息为:\n",find_reader);

       printf("ReaderNo.\tReaderName");

       for(i=0;i
          printf("\tBorrowBookNum%d",i+1);
       printf("\n");

       printf("%s\t\t%s",p->reader_num,p->reader_name);
       for(i=0;i
          printf("\t\t%7s",p->borrow[i].borrow_book_num);
        printf("\n");
     }

     else
         printf("\n此图书编号不存在,请核对!按任意键返回...");
    p=NULL;
    getchar(); system("cls");
}//"Find_Reader()"end

void Borrow_Book()
{
    BK *p=NULL;  RD *q=NULL;
    char bo_num[10],rea_num[10];
    int i=0,j=0;
    p=h_book; q=h_reader;
    printf("\n借书模块...\n");
    printf("\n请输入借书的读者编号:");
    scanf("%s",rea_num);
    getchar();

    while(q->next!=NULL&&strcmp(rea_num,q->reader_num)!=0)
         q=q->next;

     if(q->next==NULL&&strcmp(rea_num,q->reader_num)!=0)
     {
         printf("\n错误!此读者编号不存在!按任意键返回..\n");
         goto END;
     }

    printf("\n请输入你要借的书的编号:");
    scanf("%s",bo_num);
    getchar();

    while(strcmp(bo_num,p->book_num)!=0&&p->next!=NULL)
        p=p->next;

    if(p->next==NULL&&strcmp(bo_num,p->book_num)!=0)
    {
         printf("\n错误!此图书编号不存在!按任意键返回..\n");
         goto END;
    }

    if(p->book_xc<=0)
    {
        printf("\n抱歉,此书已借完!请等待新书的到来!!\n按任意键返回....");
        goto END;
    }
    printf("总共能借%d本，已借%d本\n",Max, q->right+1 );
    if(q->right>=Max)
    {
        printf("\n不好意思,借书数目已满!不能借书!\n按任意键返回....");
        goto END;
    }

    else if(0 != q->right ) //else if(strcmp(q->borrow[0].borrow_book_num,"0")!=0)
    {
        for(i=0;i
        {
            if(strcmp(q->borrow[i].borrow_book_num,bo_num)==0)
            {
                printf("\n抱歉!同一个读者不能同借两本相同的书!\n");
                goto END;
            }
           for(j=0; j
            if(strcmp(q->borrow[j].borrow_book_num,"0")==0)
            {
                time_t timep;
                char *wday[]={"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};
                struct tm *pt=NULL;
                time(&timep);
                pt=localtime(&timep);
                printf("借书时间：\n");
                printf("\t%d年d月d日",(1900+pt->tm_year),(1+pt->tm_mon),pt->tm_mday);
                printf(" %s\n\td:d:d\n",wday[pt->tm_wday],pt->tm_hour,pt->tm_min,pt->tm_sec);

                q->borrow[j].lend_t.st_year=(1900+pt->tm_year);   //year
                q->borrow[j].lend_t.st_mon=(1+pt->tm_mon);     //month
                q->borrow[j].lend_t.st_mday=pt->tm_mday;   //day
                //q->borrow[q->right].lend_t->st_wday   星期省略
                q->borrow[j].lend_t.st_hour=pt->tm_hour;   //hour
                q->borrow[j].lend_t.st_min=pt->tm_min;     //minute
                q->borrow[j].lend_t.st_sec=pt->tm_sec;     //second

                strcpy(q->borrow[j].borrow_book_num,bo_num);
                q->right++;
                p->book_xc--;
                printf("\n读者编号%s借书完毕!按任意键继续下步操作..",q->reader_num);
                goto END;
            }//"if(strcmp(q->borrow[i].borrow_book_num,"0")==0)"end
        }//"for(i=0;i
    }//"else if(strcmp(q->borrow[0].borrow_book_num,"0")!=0)"end

   else
   {
       time_t timep;
       char *wday[]={"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};
       struct tm *pt=NULL;
       time(&timep);
       pt=localtime(&timep);
       printf("借书时间：\n");
       printf("%d年d月d日",(1900+pt->tm_year),(1+pt->tm_mon),pt->tm_mday);
       printf(" %s\nd:d:d\n",wday[pt->tm_wday],pt->tm_hour,pt->tm_min,pt->tm_sec);

       q->borrow[q->right].lend_t.st_year=(1900+pt->tm_year);   //year
       q->borrow[q->right].lend_t.st_mon=(1+pt->tm_mon);     //month
       q->borrow[q->right].lend_t.st_mday=pt->tm_mday;   //day
       //q->borrow[q->right].lend_t->st_wday   星期省略
       q->borrow[q->right].lend_t.st_hour=pt->tm_hour;   //hour
       q->borrow[q->right].lend_t.st_min=pt->tm_min;     //minute
       q->borrow[q->right].lend_t.st_sec=pt->tm_sec;     //second

        strcpy(q->borrow[q->right++].borrow_book_num,bo_num);
        p->book_xc--;
        printf("\n读者编号%s借书完毕!按任意键继续下步操作..",q->reader_num);

   }//"else"end

      END:
        p=NULL;
        q=NULL;
        getchar(); system("cls");
}//"Borrow_Book()"end

void Return_Book()
{
    BK *p=NULL;  RD *q=NULL;
    int i,j,find=0,day=0;
    char return_book_num[10],return_reader_num[10];
    p=h_book; q=h_reader;
    printf("\n还书模块...\n");
    printf("\n请输入要还书的读者编号:");
    scanf("%s",return_reader_num);
    getchar();
    while(q->next!=NULL&&strcmp(return_reader_num,q->reader_num)!=0)
         q=q->next;
     if(q->next==NULL&&strcmp(return_reader_num,q->reader_num)!=0)
     {
         printf("\n错误!此读者编号不存在!按任意键返回..\n");
         goto End_return_book;
     }

    printf("\n请输入还书的编号:");
    scanf("%s",return_book_num);
    getchar();

    while(p->next!=NULL&&strcmp(return_book_num,p->book_num)!=0)
        p=p->next;

    if(p->next==NULL&&strcmp(return_book_num,p->book_num)!=0)
    {
        printf("\n错误!此图书编号不存在!按任意键返回..\n");
        goto End_return_book;
    }

        for(i=0;i
        if(strcmp(return_book_num,q->borrow[i].borrow_book_num)==0)
        {
            find++;

            printf("借书时间：\n");
            printf("\t%d年d月d日",q->borrow[i].lend_t.st_year,q->borrow[i].lend_t.st_mon,q->borrow[i].lend_t.st_mday);
            printf("\n\td:d:d\n",q->borrow[i].lend_t.st_hour,q->borrow[i].lend_t.st_min,q->borrow[i].lend_t.st_sec);

            time_t timep;
            //char *wday[]={"星期天","星期一","星期二","星期三","星期四","星期五","星期六"};
            struct tm *pt=NULL;
            time(&timep);
            pt=localtime(&timep);
            printf("还书时间：\n");
            printf("\t%d年d月d日",(1900+pt->tm_year),(1+pt->tm_mon),pt->tm_mday);
            printf("\n\td:d:d\n",pt->tm_hour,pt->tm_min,pt->tm_sec);

            day=( (1900+pt->tm_year) - q->borrow[i].lend_t.st_year)*365;   //year
            day+=( (1+pt->tm_mon) - q->borrow[i].lend_t.st_mon )*30;     //month
            day+=( pt->tm_mday - q->borrow[i].lend_t.st_mday );         //day
            day=( pt->tm_hour - q->borrow[i].lend_t.st_hour ) + day*24;   //hour
            day=( pt->tm_min - q->borrow[i].lend_t.st_min ) + day*60;     //minute
            day=( pt->tm_sec - q->borrow[i].lend_t.st_sec ) + day*60;     //second
            printf("共借阅:%d秒\n",day);

            strcpy(q->borrow[i].borrow_book_num,"0");
            p->book_xc++;
            q->right--;

            printf("\n编号%s的读者还书完毕!按任意键继续下步操作..",return_reader_num);
        }

   if(strcmp(return_book_num,q->borrow[Max-1].borrow_book_num)!=0&&find==0)
      printf("\n错误!此读者未借此书!按任意键返回..\n");

   End_return_book:
        p=NULL;
        q=NULL;
        getchar(); system("cls");
}//"Return_Book()"end

void del_old_book()
{
    BK *p=NULL,*q=NULL;
    char del_num[10];
    p=h_book;
    printf("\n旧书出库模块\n");
    printf("\n请输入要出库的图书编号:");
    scanf("%s",del_num);
    getchar();

    while(strcmp(p->book_num,del_num)!=0&&p->next!=NULL)
    { q=p; p=p->next; }

    if(strcmp(p->book_num,del_num)==0)
    {
       if(p->book_kc!=p->book_xc)
            printf("\n抱歉,此图书未归还或数据出错,不能出库!按任意键返回...");
       else
       {
            if(p==h_book)
                h_book=p->next;
            else
                q->next=p->next;

        free(p);
        printf("\n编号为%s的图书删除完毕!按任意键继续...",del_num);
       }
    }
    else
         printf("\n你输入的图书编号不存在!按任意键返回...");
   p=NULL;
   q=NULL;
   getchar(); system("cls");
}//"del_old_book()"end

void del_old_reader()
{
    RD *p=NULL,*q=NULL;
    char del_num[10];
    p=h_reader;
    printf("\n删除旧读者模块\n");
    printf("\n请输入要删除的读者编号:");
    scanf("%s",del_num);
    getchar();

    while(strcmp(p->reader_num,del_num)!=0&&p->next!=NULL)
    { q=p; p=p->next; }

    if(strcmp(p->reader_num,del_num)==0)
    {
       if(strcmp(p->borrow[0].borrow_book_num,"0")!=0)
           printf("\n抱歉,此读者还有图书没有归还,不能删除其信息!\n按任意键继续...");

        else
        {
            if(p==h_reader)
                h_reader=p->next;
            else
                q->next=p->next;
            free(p);

            printf("\n编号为%s的读者删除完毕!按任意键继续...",del_num);
        }
    }
    else
         printf("\n你输入的读者编号不存在!按任意键返回...");
   p=NULL;
   q=NULL;
   getchar(); system("cls");

}//"del_old_reader()"end

int Print()
{
    int sn;
    printf("\n\t\t打印全部信息菜单\n");
    printf("=================================================\n");
    printf("*\t0----返回上级     1----关于系统  \t*\n");
    printf("*\t                                 \t*\n");
    printf("*\t2----打印图书     3----打印读者  \t*\n");
    printf("=================================================\n");
    printf("请选择相应代码:");
  for(;;)
  {
      fflush(stdin);
      scanf("%d",&sn);
      getchar();
      //fflush(stdin);
      if(sn<0||sn>3)
          printf("\n错误!请重新输入:");
      else break;
  }
  return sn;
}//"Print()"end

void Print_Select()
{
    system("cls");
    for(;;)
 {
  switch(Print())
  {
   case 0:system("cls"); Menu_select(); break;
   case 1:about();break;
   case 2:Print_book();break;
   case 3:Print_reader();break;
       default:printf("\n错误!");exit(0);
   }
  }
}//"Print_Select()"end

void Print_book()
{
    BK *p=NULL;
    p=h_book;

    printf("\n库存图书信息如下:\n\n");
    printf("BookNo.\t\tBookName\t\t\tXianCun \tKuCun\n");

    while(p!=NULL)
    {
        printf("%s\t\t%s\t\t=\t\t=\n",p->book_num,p->book_name,p->book_xc,p->book_kc);
        p=p->next;
    }

    p=NULL;
    printf("\n图书信息打印完毕!按任意键继续下一步操作..");
    getchar();
    system("cls");
}//"Print_book()"end

void Print_reader()
{
    RD *p=NULL;
    int i;
    p=h_reader;

    printf("\n库存读者信息如下:\n\n");
    printf("ReaderNo.\tReaderName");
    for(i=0;i
        printf("\tBorrowBookNum%d",i+1);
    printf("\n");
    while(p!=NULL)
    {
        printf("%s\t\t%s",p->reader_num,p->reader_name);
        for(i=0;i
        printf("\t\t%7s",p->borrow[i].borrow_book_num);
        printf("\n");
        p=p->next;
    }
    p=NULL;
    printf("\n读者信息打印完毕!按任意键继续下一步操作..");
    getchar();
    system("cls");
}//"Print_reader()"end

void about()
{
    system("cls");
    printf("\n\n\n\t\t\t关 于 本 系 统 的 说 明\n");
    printf("\n\t\t1.本系统为模拟小型图书馆而设计,界面采用数字选择界面.\n");
    printf("\n\t\t2.系统初始化时提示用户输入两组信息.\n");
    printf("\n\t\t3.初始化完毕后每个读者的借书权限为3本.\n\n\t\t4.读者借书后会在其信息中记录所借书号,未借者书号均为 0.\n");
    printf("\n\t\t5.由于时间等原因,系统的其他功能还不健全,望大家见谅!");
    printf("\n\n\t\t6.建议:双击可执行文件后,在任务栏那点右键-->属性-->颜色\n\n\t\t  设置屏幕文字为:深蓝色(第10个) 屏幕背景为:淡绿色(第12个)");
    printf("\n\n\t\t  具体方法请参看文件夹内Word文档.\n\n\t\t7.系统如有其他问题,请联系作者!");
    printf("\n\n\t\t  E-mail:99688385@qq.com");
    printf("\n\n\n\t\t阅 读 完 毕, 按 任 意 键 继 续 ...");

    getchar(); system("cls");
}//"about()"end

void book_not_enough()
{
    BK *p=NULL;
    int i=0;
    p=h_book;
    while(p!=NULL)
    {
        if(p->book_xc==0)
        {
            i++;
            printf("\n库存不足的图书有:\n");
            printf("\nBookNumber\t\tBookName\n");
            printf("%s\t\t\t%s\n",p->book_num,p->book_name);
        }
        p=p->next;
    }

    if(p==NULL&&i==0)
        printf("\n暂时没有库存不足的图书!");
    p=NULL;
    getchar(); system("cls");
}//"book_not_enough()"end



void Save()
{
    Save_Reader();
    Save_Book();
}//"Save()"end

void Save_Reader()
{
    FILE *fp_reader=NULL;
    RD *p=NULL,*p0=NULL;
    p=h_reader;
    if((fp_reader=fopen("Reader.txt","wb"))==NULL)
    {
        printf("\n文件保存失败!\n请重新启动本系统...\n");
        exit(0);
    }
    while(p!=NULL)
    {
        if(fwrite(p,sizeof(RD),1,fp_reader)!=1)
            printf("\n写入文件失败!\n请重新启动本系统!\n");
        p0=p;
        p=p->next;
        free(p0);
            // Bug 当book.txt 和reader.txt都存在但都为空时，加载信息为空会出现bug,具体原因不解
    }

    h_reader=NULL;
    fclose(fp_reader);
    fp_reader=NULL;
    p=NULL;
    p0=NULL;
}//"Save_Reader()"end

void Save_Book()
{
    FILE *fp_book=NULL;
    BK *p=NULL,*p0=NULL;
    p=h_book;   //（全局指针）
    if((fp_book=fopen("Book.txt","wb"))==NULL) // 此处必须用wb将文件全部更新
    {
        printf("\n文件保存失败!\n请重新启动本系统...\n");
        exit(0);
    }
    while(p!=NULL)
    {
        if(fwrite(p,sizeof(BK),1,fp_book)!=1)
            printf("\n写入文件失败!\n请重新启动本系统!\n");
        p0=p;
        p=p->next;
        free(p0);
    }

    p=NULL;
    p0=NULL;
    h_book=NULL;
    fclose(fp_book);
    fp_book=NULL;
}//"Save_Book()"end

void Load()
{
    Load_Reader();
    Load_Book();
}//"Load()"end

void Load_Reader()
{
   RD *p1=NULL,*p2=NULL,*p3=NULL;
   FILE *fp=NULL;

   fp=fopen("Reader.txt","rb");
   p1=(RD *)malloc(sizeof(RD));
   fread(p1,sizeof(RD),1,fp);
   h_reader=p3=p2=p1;
   while(! feof(fp))
   {  p1=(RD *)malloc(sizeof(RD));
      fread(p1,sizeof(RD),1,fp);
      p2->next=p1;
      p3=p2;
      p2=p1;
   }
   p3->next=NULL;
   free(p1);
   p1=NULL;
   p2=NULL;
   p3=NULL;
   fclose(fp);
   fp=NULL;
}//"Load_Reader()"end


void Load_Book()
{
    BK *p1=NULL,*p2=NULL,*p3=NULL;
    FILE *fp=NULL;

    fp=fopen("Book.txt","rb");
    p1=(BK *)malloc(sizeof(BK));
    fread(p1,sizeof(BK),1,fp);
    h_book=p3=p2=p1;
   while(! feof(fp))
   {  p1=(BK *)malloc(sizeof(BK));
      fread(p1,sizeof(BK),1,fp);
      p2->next=p1;
      p3=p2;
      p2=p1;
   }
    p3->next=NULL;
    free(p1);
    p1=p2=p3=NULL;
    fclose(fp);
    fp=NULL;
}//"Load_Book()"end
