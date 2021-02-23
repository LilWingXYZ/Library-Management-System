#include "c1.h"
#include "algo4-3.h"
#include "first.h"

//�������ṹ��������first.h��

BK *h_book;
RD *h_reader;

int Menu()
{
//int sn;
    int sn=-1;
 printf("\n\t\tͼ�����ϵͳ���˵�\n");
 printf("==========================================================\n");
 printf("*\t0----�˳�ϵͳ          6----����ϵͳ    \t*\n");
 printf("*\t1----�������          7----�������    \t*\n");
 printf("*\t2----���¶���          8----ע������    \t*\n");
 printf("*\t3----��ѯͼ��/����     9----���ȫ����Ϣ\t*\n");
 printf("*\t4----����Ǽ�         10----��治��ͼ��\t*\n");
 printf("*\t5----�������         11----���浱ǰ��Ϣ\t*\n");
 printf("==========================================================\n");
 printf("��ѡ����Ӧ����:");
 for(;;)
 {
     fflush(stdin);
   scanf("%d",&sn);
   getchar();
   if(sn<0||sn>11)
      printf("\n����!����������:");
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
            printf("�Ƿ񱣴浱ǰ���� y/n��");
            scanf("%c",&i);
            getchar();

            if( i=='y')
            {
                system("cls");
                Save();
                printf("\n\n\t�ļ�����ɹ�!\n");
                printf("\n\n\tGoodBye!\n");
                getchar();
            }
            else
                printf("\n\n\t�����ļ�����!\n");

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
          printf("\n�ļ�����ɹ�!������������²�����....");
          getchar(); system("cls");break;
   default:printf("\n�����������������!"); break ;
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
     printf("\n���߳�ʼ����ʼ,�����������Ϣ..\n�������.����..\n");
     p0=(RD *)malloc(sizeof(RD));
     h_reader=p0;

     printf("\n��������ߵ���Ϣ:\n");
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
     printf("\n������Ϣ��ʼ�����!�������������һ������..\n");

     getchar();
     system("cls");
}//"Init_reader()" end

void Init_book()
{
    BK *p0=NULL;
    printf("\nͼ���ʼ����ʼ,������ͼ����Ϣ..\n�������.����.����..\n");
    p0=(BK *)malloc(sizeof(BK));
    h_book=p0;

    printf("\n������ͼ����Ϣ:\n");
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
    printf("\nͼ����Ϣ��ʼ�����!�������������һ������..\n");

    getchar();
    system("cls");
}//"Init_book()" end


void Insert_New_Reader()
{
    RD *p=NULL,*p0=NULL,*p1=NULL,*p2=NULL;
    int i;
    p=p1=p2=h_reader;
    printf("\n�����¶���ģ��...\n");
    printf("\n�������¶�����Ϣ..\n�������.����..\n");
    p0=(RD *)malloc(sizeof(RD));
  re_input_reader:
      printf("ReaderNo.:");
       scanf("%s",p0->reader_num);

       while(strcmp(p0->reader_num,p2->reader_num)!=0&&p2->next!=NULL)
           p2=p2->next;

       if(strcmp(p0->reader_num,p2->reader_num)==0)
       {
           printf("\n�˱�Ŷ����Ѵ���!����������\n");
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
      printf("\n�¶����������!�������������һ������..\n");
      getchar();
      system("cls");

}//"Insert_New_Book()" end

void Insert_New_Book()
{
    BK *p=NULL,*p0=NULL,*p1=NULL,*p2=NULL;
    p=p1=p2=h_book;
    printf("\n�������ģ��...\n");
    printf("\n������������Ϣ..\n�������.����.����..\n");

    p0=(BK *)malloc(sizeof(BK));

       printf("BookNo.:");
       scanf("%s",p0->book_num);
       getchar();

       while(strcmp(p0->book_num,p2->book_num)!=0&&p2->next!=NULL)
           p2=p2->next;
       if(strcmp(p0->book_num,p2->book_num)==0)
       {
           printf("\n�˱��ͼ���Ѵ���!!ֱ�����!\n");
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
      algo43_main();  //���ɹؼ�����������algo4-3.cpp�ж���
      p=NULL;p0=NULL;p1=NULL;p2=NULL;
      printf("\n����������!�������������һ������..\n");
      getchar();
      system("cls");
}//"Insert_New_Book()" end

int Find()
{
    int sn;
    printf("\n\t\t��ӡȫ����Ϣ�˵�\n");
    printf("===============================================\n");
    printf("*\t0----�����ϼ�     1----����ϵͳ  \t*\n");
    printf("*\t                                 \t*\n");
    printf("*\t2----����ͼ��     3----���Ҷ���  \t*\n");
    printf("===============================================\n");
    printf("��ѡ����Ӧ����:");
  for(;;)
  {
      fflush(stdin);
      scanf("%d",&sn);
      getchar();
      if(sn<0||sn>3)
          printf("\n����!����������:");
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
   default:printf("\n����!");exit(0);
   }
  }
}//"Find_Select()"end

int Find_Book_select()
{
    int sn;
    printf("\n\t\t��ӡȫ����Ϣ�˵�\n");
    printf("=================================================\n");
    printf("*\t 0----�����ϼ�         \n");    //MY  1 ����Ӧ�øĳ� ���ڲ�ѯϵͳ ���� ��ѯ����
    printf("*\t                                 \t*\n");
    printf("*\t 1----��Ų�ѯ         2----�ؼ��ֲ�ѯ\t*\n");
    printf("=================================================\n");
    printf("��ѡ����Ӧ����:");
    for(;;)
    {
        fflush(stdin);
        scanf("%d",&sn);
        getchar();
        if(sn<0||sn>3)
            printf("\n����!����������:");
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
        case 2:algo44_main();break;  //algo44_main()algo4-4.cpp�ж���
        default:printf("\n����!");exit(0);
        }
    }
}//"Find_Book_contral()"end

void Find_Book()
{
    BK *p=NULL;
    char find_book[10];
    p=h_book;
    printf("\nͼ���ѯģ��\n");
    printf("\n��������Ҫ��ѯͼ����:");
    scanf("%s",find_book);
    getchar();

     while(strcmp(p->book_num,find_book)!=0&&p->next)
         p=p->next;

     if(strcmp(p->book_num,find_book)==0)
     {
        printf("\nͼ����:%s����ϢΪ:\n",find_book);
        printf("\nBookNo.\t\tBookName\t\t\tXianCun \tKuCun\n");
        printf("%s\t\t%s\t\t=\t\t=\n",p->book_num,p->book_name,p->book_xc,p->book_kc);
     }
      else
         printf("\n��ͼ���Ų�����,��˶�!�����������...");

    p=NULL;
    getchar(); system("cls");
}//"Find_Book()"end

void Find_Reader()
{
    RD *p=NULL;
    int i;
    char find_reader[10];
    p=h_reader;
    printf("\n��ѯģ��\n");
    printf("\n��������Ҫ��ѯ���߱��:");
    scanf("%s",find_reader);
    getchar();

     while(strcmp(p->reader_num,find_reader)!=0&&p->next)
         p=p->next;
     if(strcmp(p->reader_num,find_reader)==0)
     {
       printf("\n���߱��:%s����ϢΪ:\n",find_reader);

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
         printf("\n��ͼ���Ų�����,��˶�!�����������...");
    p=NULL;
    getchar(); system("cls");
}//"Find_Reader()"end

void Borrow_Book()
{
    BK *p=NULL;  RD *q=NULL;
    char bo_num[10],rea_num[10];
    int i=0,j=0;
    p=h_book; q=h_reader;
    printf("\n����ģ��...\n");
    printf("\n���������Ķ��߱��:");
    scanf("%s",rea_num);
    getchar();

    while(q->next!=NULL&&strcmp(rea_num,q->reader_num)!=0)
         q=q->next;

     if(q->next==NULL&&strcmp(rea_num,q->reader_num)!=0)
     {
         printf("\n����!�˶��߱�Ų�����!�����������..\n");
         goto END;
     }

    printf("\n��������Ҫ�����ı��:");
    scanf("%s",bo_num);
    getchar();

    while(strcmp(bo_num,p->book_num)!=0&&p->next!=NULL)
        p=p->next;

    if(p->next==NULL&&strcmp(bo_num,p->book_num)!=0)
    {
         printf("\n����!��ͼ���Ų�����!�����������..\n");
         goto END;
    }

    if(p->book_xc<=0)
    {
        printf("\n��Ǹ,�����ѽ���!��ȴ�����ĵ���!!\n�����������....");
        goto END;
    }
    printf("�ܹ��ܽ�%d�����ѽ�%d��\n",Max, q->right+1 );
    if(q->right>=Max)
    {
        printf("\n������˼,������Ŀ����!���ܽ���!\n�����������....");
        goto END;
    }

    else if(0 != q->right ) //else if(strcmp(q->borrow[0].borrow_book_num,"0")!=0)
    {
        for(i=0;i
        {
            if(strcmp(q->borrow[i].borrow_book_num,bo_num)==0)
            {
                printf("\n��Ǹ!ͬһ�����߲���ͬ��������ͬ����!\n");
                goto END;
            }
           for(j=0; j
            if(strcmp(q->borrow[j].borrow_book_num,"0")==0)
            {
                time_t timep;
                char *wday[]={"������","����һ","���ڶ�","������","������","������","������"};
                struct tm *pt=NULL;
                time(&timep);
                pt=localtime(&timep);
                printf("����ʱ�䣺\n");
                printf("\t%d��d��d��",(1900+pt->tm_year),(1+pt->tm_mon),pt->tm_mday);
                printf(" %s\n\td:d:d\n",wday[pt->tm_wday],pt->tm_hour,pt->tm_min,pt->tm_sec);

                q->borrow[j].lend_t.st_year=(1900+pt->tm_year);   //year
                q->borrow[j].lend_t.st_mon=(1+pt->tm_mon);     //month
                q->borrow[j].lend_t.st_mday=pt->tm_mday;   //day
                //q->borrow[q->right].lend_t->st_wday   ����ʡ��
                q->borrow[j].lend_t.st_hour=pt->tm_hour;   //hour
                q->borrow[j].lend_t.st_min=pt->tm_min;     //minute
                q->borrow[j].lend_t.st_sec=pt->tm_sec;     //second

                strcpy(q->borrow[j].borrow_book_num,bo_num);
                q->right++;
                p->book_xc--;
                printf("\n���߱��%s�������!������������²�����..",q->reader_num);
                goto END;
            }//"if(strcmp(q->borrow[i].borrow_book_num,"0")==0)"end
        }//"for(i=0;i
    }//"else if(strcmp(q->borrow[0].borrow_book_num,"0")!=0)"end

   else
   {
       time_t timep;
       char *wday[]={"������","����һ","���ڶ�","������","������","������","������"};
       struct tm *pt=NULL;
       time(&timep);
       pt=localtime(&timep);
       printf("����ʱ�䣺\n");
       printf("%d��d��d��",(1900+pt->tm_year),(1+pt->tm_mon),pt->tm_mday);
       printf(" %s\nd:d:d\n",wday[pt->tm_wday],pt->tm_hour,pt->tm_min,pt->tm_sec);

       q->borrow[q->right].lend_t.st_year=(1900+pt->tm_year);   //year
       q->borrow[q->right].lend_t.st_mon=(1+pt->tm_mon);     //month
       q->borrow[q->right].lend_t.st_mday=pt->tm_mday;   //day
       //q->borrow[q->right].lend_t->st_wday   ����ʡ��
       q->borrow[q->right].lend_t.st_hour=pt->tm_hour;   //hour
       q->borrow[q->right].lend_t.st_min=pt->tm_min;     //minute
       q->borrow[q->right].lend_t.st_sec=pt->tm_sec;     //second

        strcpy(q->borrow[q->right++].borrow_book_num,bo_num);
        p->book_xc--;
        printf("\n���߱��%s�������!������������²�����..",q->reader_num);

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
    printf("\n����ģ��...\n");
    printf("\n������Ҫ����Ķ��߱��:");
    scanf("%s",return_reader_num);
    getchar();
    while(q->next!=NULL&&strcmp(return_reader_num,q->reader_num)!=0)
         q=q->next;
     if(q->next==NULL&&strcmp(return_reader_num,q->reader_num)!=0)
     {
         printf("\n����!�˶��߱�Ų�����!�����������..\n");
         goto End_return_book;
     }

    printf("\n�����뻹��ı��:");
    scanf("%s",return_book_num);
    getchar();

    while(p->next!=NULL&&strcmp(return_book_num,p->book_num)!=0)
        p=p->next;

    if(p->next==NULL&&strcmp(return_book_num,p->book_num)!=0)
    {
        printf("\n����!��ͼ���Ų�����!�����������..\n");
        goto End_return_book;
    }

        for(i=0;i
        if(strcmp(return_book_num,q->borrow[i].borrow_book_num)==0)
        {
            find++;

            printf("����ʱ�䣺\n");
            printf("\t%d��d��d��",q->borrow[i].lend_t.st_year,q->borrow[i].lend_t.st_mon,q->borrow[i].lend_t.st_mday);
            printf("\n\td:d:d\n",q->borrow[i].lend_t.st_hour,q->borrow[i].lend_t.st_min,q->borrow[i].lend_t.st_sec);

            time_t timep;
            //char *wday[]={"������","����һ","���ڶ�","������","������","������","������"};
            struct tm *pt=NULL;
            time(&timep);
            pt=localtime(&timep);
            printf("����ʱ�䣺\n");
            printf("\t%d��d��d��",(1900+pt->tm_year),(1+pt->tm_mon),pt->tm_mday);
            printf("\n\td:d:d\n",pt->tm_hour,pt->tm_min,pt->tm_sec);

            day=( (1900+pt->tm_year) - q->borrow[i].lend_t.st_year)*365;   //year
            day+=( (1+pt->tm_mon) - q->borrow[i].lend_t.st_mon )*30;     //month
            day+=( pt->tm_mday - q->borrow[i].lend_t.st_mday );         //day
            day=( pt->tm_hour - q->borrow[i].lend_t.st_hour ) + day*24;   //hour
            day=( pt->tm_min - q->borrow[i].lend_t.st_min ) + day*60;     //minute
            day=( pt->tm_sec - q->borrow[i].lend_t.st_sec ) + day*60;     //second
            printf("������:%d��\n",day);

            strcpy(q->borrow[i].borrow_book_num,"0");
            p->book_xc++;
            q->right--;

            printf("\n���%s�Ķ��߻������!������������²�����..",return_reader_num);
        }

   if(strcmp(return_book_num,q->borrow[Max-1].borrow_book_num)!=0&&find==0)
      printf("\n����!�˶���δ�����!�����������..\n");

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
    printf("\n�������ģ��\n");
    printf("\n������Ҫ�����ͼ����:");
    scanf("%s",del_num);
    getchar();

    while(strcmp(p->book_num,del_num)!=0&&p->next!=NULL)
    { q=p; p=p->next; }

    if(strcmp(p->book_num,del_num)==0)
    {
       if(p->book_kc!=p->book_xc)
            printf("\n��Ǹ,��ͼ��δ�黹�����ݳ���,���ܳ���!�����������...");
       else
       {
            if(p==h_book)
                h_book=p->next;
            else
                q->next=p->next;

        free(p);
        printf("\n���Ϊ%s��ͼ��ɾ�����!�����������...",del_num);
       }
    }
    else
         printf("\n�������ͼ���Ų�����!�����������...");
   p=NULL;
   q=NULL;
   getchar(); system("cls");
}//"del_old_book()"end

void del_old_reader()
{
    RD *p=NULL,*q=NULL;
    char del_num[10];
    p=h_reader;
    printf("\nɾ���ɶ���ģ��\n");
    printf("\n������Ҫɾ���Ķ��߱��:");
    scanf("%s",del_num);
    getchar();

    while(strcmp(p->reader_num,del_num)!=0&&p->next!=NULL)
    { q=p; p=p->next; }

    if(strcmp(p->reader_num,del_num)==0)
    {
       if(strcmp(p->borrow[0].borrow_book_num,"0")!=0)
           printf("\n��Ǹ,�˶��߻���ͼ��û�й黹,����ɾ������Ϣ!\n�����������...");

        else
        {
            if(p==h_reader)
                h_reader=p->next;
            else
                q->next=p->next;
            free(p);

            printf("\n���Ϊ%s�Ķ���ɾ�����!�����������...",del_num);
        }
    }
    else
         printf("\n������Ķ��߱�Ų�����!�����������...");
   p=NULL;
   q=NULL;
   getchar(); system("cls");

}//"del_old_reader()"end

int Print()
{
    int sn;
    printf("\n\t\t��ӡȫ����Ϣ�˵�\n");
    printf("=================================================\n");
    printf("*\t0----�����ϼ�     1----����ϵͳ  \t*\n");
    printf("*\t                                 \t*\n");
    printf("*\t2----��ӡͼ��     3----��ӡ����  \t*\n");
    printf("=================================================\n");
    printf("��ѡ����Ӧ����:");
  for(;;)
  {
      fflush(stdin);
      scanf("%d",&sn);
      getchar();
      //fflush(stdin);
      if(sn<0||sn>3)
          printf("\n����!����������:");
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
       default:printf("\n����!");exit(0);
   }
  }
}//"Print_Select()"end

void Print_book()
{
    BK *p=NULL;
    p=h_book;

    printf("\n���ͼ����Ϣ����:\n\n");
    printf("BookNo.\t\tBookName\t\t\tXianCun \tKuCun\n");

    while(p!=NULL)
    {
        printf("%s\t\t%s\t\t=\t\t=\n",p->book_num,p->book_name,p->book_xc,p->book_kc);
        p=p->next;
    }

    p=NULL;
    printf("\nͼ����Ϣ��ӡ���!�������������һ������..");
    getchar();
    system("cls");
}//"Print_book()"end

void Print_reader()
{
    RD *p=NULL;
    int i;
    p=h_reader;

    printf("\n��������Ϣ����:\n\n");
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
    printf("\n������Ϣ��ӡ���!�������������һ������..");
    getchar();
    system("cls");
}//"Print_reader()"end

void about()
{
    system("cls");
    printf("\n\n\n\t\t\t�� �� �� ϵ ͳ �� ˵ ��\n");
    printf("\n\t\t1.��ϵͳΪģ��С��ͼ��ݶ����,�����������ѡ�����.\n");
    printf("\n\t\t2.ϵͳ��ʼ��ʱ��ʾ�û�����������Ϣ.\n");
    printf("\n\t\t3.��ʼ����Ϻ�ÿ�����ߵĽ���Ȩ��Ϊ3��.\n\n\t\t4.���߽�����������Ϣ�м�¼�������,δ������ž�Ϊ 0.\n");
    printf("\n\t\t5.����ʱ���ԭ��,ϵͳ���������ܻ�����ȫ,����Ҽ���!");
    printf("\n\n\t\t6.����:˫����ִ���ļ���,���������ǵ��Ҽ�-->����-->��ɫ\n\n\t\t  ������Ļ����Ϊ:����ɫ(��10��) ��Ļ����Ϊ:����ɫ(��12��)");
    printf("\n\n\t\t  ���巽����ο��ļ�����Word�ĵ�.\n\n\t\t7.ϵͳ������������,����ϵ����!");
    printf("\n\n\t\t  E-mail:99688385@qq.com");
    printf("\n\n\n\t\t�� �� �� ��, �� �� �� �� �� �� ...");

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
            printf("\n��治���ͼ����:\n");
            printf("\nBookNumber\t\tBookName\n");
            printf("%s\t\t\t%s\n",p->book_num,p->book_name);
        }
        p=p->next;
    }

    if(p==NULL&&i==0)
        printf("\n��ʱû�п�治���ͼ��!");
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
        printf("\n�ļ�����ʧ��!\n������������ϵͳ...\n");
        exit(0);
    }
    while(p!=NULL)
    {
        if(fwrite(p,sizeof(RD),1,fp_reader)!=1)
            printf("\nд���ļ�ʧ��!\n������������ϵͳ!\n");
        p0=p;
        p=p->next;
        free(p0);
            // Bug ��book.txt ��reader.txt�����ڵ���Ϊ��ʱ��������ϢΪ�ջ����bug,����ԭ�򲻽�
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
    p=h_book;   //��ȫ��ָ�룩
    if((fp_book=fopen("Book.txt","wb"))==NULL) // �˴�������wb���ļ�ȫ������
    {
        printf("\n�ļ�����ʧ��!\n������������ϵͳ...\n");
        exit(0);
    }
    while(p!=NULL)
    {
        if(fwrite(p,sizeof(BK),1,fp_book)!=1)
            printf("\nд���ļ�ʧ��!\n������������ϵͳ!\n");
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
