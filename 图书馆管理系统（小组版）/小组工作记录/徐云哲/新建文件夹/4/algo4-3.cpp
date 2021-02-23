#include "c1.h"
typedef int ElemType;
#include "c2-5.h"
#include "c4-2.h"
#include "algo4-3.h"
#include "first.h"

//函数及结构体申明在algo4-3.h中

//全局变量
BK  bookinfo;//BK * bookinfo=NULL;
char buf[MaxLineLen+1];
WordLisType wdlist,noidx;

//初始化操作，置索引表idxlist为空表，且在idxlist.item[0]设一空串
void InitIdxList(IdxListType &idxlist)
{
    idxlist.last=0;
    InitString(idxlist.item[0].key);   //初始化[0]单元，函数在bo2-4.cpp中
    InitList(idxlist.item[0].bnolist);  //初始化[0]单元，函数在bo2-6.cpp中
}

void ExtractKeyWord(int &BookNo)
{
    int i,l,f=1;   //f是字符串buf结束标志0:结束  1：未结束
    char *s1=NULL,*s2=NULL;
    for(i = 1; i <= wdlist.last; i++)
    {
        free(wdlist.item[i]);   //释放上一个书目在词表wdlist的存储空间
        wdlist.item[i]=NULL;
    }
    wdlist.last=0;  // 初始化词表wdlist的词数量
     BookNo=atoi(bookinfo.book_num);

    s1=buf;//s1=&buf[4];
    while(f)  //提取书名关键词到词表wdlist
    {
        s2=strchr(s1, ' ');   //s2指向s1后的第一个空格，如没有，返回NULL
        if(!s2)   //到串尾（没空格）
        {
            s2=strchr(s1,'\0');//s2=strchr(s1,'\12');
            //s2指向buf的最后一个字符（回车符10） MY应该改为'\0'(串结束标志)，gets不保存回车符
            f=0;
        }
        l=s2-s1;   //单词长度
        if(s1[0] >= 'A' && s1[0] <= 'Z')   //单词首写字母为大写
        {  //写入词表
            wdlist.item[wdlist.last]=(char *)malloc((l+1)*sizeof(char));
            //生成串空间（包括‘\0’）
            for(i = 0; i < l; i++)
                wdlist.item[wdlist.last][i]=s1[i];   //写入词表
            wdlist.item[wdlist.last][l]=0;   // 串结束符‘\0’== 0
            for(i =0; i < noidx.last &&(l=strcmp(wdlist.item[wdlist.last],noidx.item[i])) >0 ;i++)
                   ;   //查找是否为非索引词
            if(!l)   //是非索引词
            {
                free(wdlist.item[wdlist.last]);   //从词表中删除该词
                wdlist.item[wdlist.last]=NULL;
            }
            else
                wdlist.last++;   //词表长度加1
        }
        s1=s2+1;   //s1移动到下一个单词的首字符处
    };
    s1=NULL;s2=NULL;
}

//用wd返回词表wdlist中的第i个关键词
void GetWord(int i, HString &wd)
{
    StrAssign(wd,wdlist.item[i]);   //生成关键字字符串 bo2-4.cpp
}

//在索引表idxlist中查询是否存在与wd相等的关键词。若存在，则返回其在索引表中的位置，且b取值TRUE；否则返回插入的位置，且b取值FALSE
int Locate(IdxListType &idxlist, HString wd, Status &b)
{
     int i,m;
     for(i=idxlist.last; (m = StrCompare(idxlist.item[i].key , wd)) > 0; --i)
           ;  //bo4-2.cpp
     if (m == 0)  //finded
     {
         b = TRUE;
         return i;
     }
     else
     {
         b = FALSE;
         return i+1;
     }
}


//索引表idxlist的第i项上插入关键词wd,并初始化书号索引的链表为空表
void InsertNewKey(IdxListType &idxlist,int i,HString wd)
{
    int j=0;
    for (j = idxlist.last; j >= i; --j)  //后移索引项
    {
        idxlist.item[j+1] = idxlist.item[j];
    }
    InitString(idxlist.item[i].key);   //bo4-2.cpp
    StrCopy( idxlist.item[i].key , wd);   //串拷贝插入新的索引项bo2-4.cpp
    InitList(idxlist.item[i].bnolist);    //初始化书号索引表为空表 bo2-6.cpp
    idxlist.last++;
}

//在索引表idxlist的第i项中插入书号为bno的索引
void InsertBook(IdxListType &idxlist, int i, int bno)
{
    Link p;
    MakeNode(p , bno);   //分配结点 bo2-6.cpp
    p->next=NULL;
    Append(idxlist.item[i].bnolist , p);  //插入新的书号索引 bo2-6.cpp
}

//将新书号为bno的关键词插入索引表
void InsIdxList(IdxListType &idxlist , int bno)
{
    int i=0,j=0;
    Status b;
    HString wd;
    InitString(wd);
    for(i = 0;i < wdlist.last ; i++)
    {
        GetWord(i ,wd);
        j = Locate(idxlist , wd , b);
        if(!b)
        {
            InsertNewKey(idxlist , j ,wd);
        }
        InsertBook(idxlist , j , bno);
    }
}

//将生成的索引表idxlist输出到文件f
void PutText(FILE *f , IdxListType idxlist)
{
    int i=0,j=0;
    Link p;
    fprintf(f, "%d\n" , idxlist.last);
    for (i = 1; i <= idxlist.last; i++)
    {
        for(j = 0; j < idxlist.item[i].key.length; j++)
            fprintf(f, "%c", idxlist.item[i].key.ch[j]);
        fprintf(f, "\n%d\n",idxlist.item[i].bnolist.len);

        p = idxlist.item[i].bnolist.head;
        for(j = 1; j <= idxlist.item[i].bnolist.len; j++)
        {
            p = p->next;
            fprintf( f, "%d ", p->data);
        }
        fprintf(f, "\n");
    }//end "for(i = 1; ...)"
}

void algo43_main(void)
{
    FILE *f; // 任何时间最多打开一个文件
    IdxListType idxlist; // 索引表
    int BookNo; // 书号变量
    int k;

    if(!(f=fopen("NoIdx.txt","r"))) // 打开非索引词文件
    {
        printf("Can't open the NoIdx.txt file");
        exit(OVERFLOW);
    }
    fscanf(f,"%d",&noidx.last); // 读取非索引词个数
    for(k=0;k
    {
        fscanf(f,"%s",buf);
        if( (noidx.item[k]=(char*)malloc((strlen(buf)+1)*sizeof(char)))==NULL )
        {
            printf("分配失败！");
            exit(1);
        }
        strcpy(noidx.item[k],buf);    //Bug  buf的值赋不到noidx.item[k]中
    }
    fclose(f); // 关闭非索引词文件


    if(!(f=fopen("Book.txt","r"))) // 打开书目文件
    {
        printf("Can't open the Book.txt file");
        exit(FALSE);
    }
    InitIdxList(idxlist); // 设索引表idxlist为空，并初始化[0]单元
    fread(&bookinfo,1,sizeof(struct book),f);  //fread(buf,1,sizeof(struct book),f);
    while(!feof(f))
    {
        strcpy(buf,bookinfo.book_name);
        ExtractKeyWord(BookNo);
        InsIdxList(idxlist,BookNo);
        fread(&bookinfo,1,sizeof(struct book),f);
    }
    fclose(f);
    f=NULL;


    if(!(f=fopen("BookIdx.txt","w"))) // 打开书名关键词索引文件
    {
        printf("Can't open the BookIdx.txt file");
        exit(INFEASIBLE);
    }
    PutText(f,idxlist); // 将生成的索引表idxlist输出到书名关键词索引文件
    fclose(f); // 关闭书名关键词索引文件
}

