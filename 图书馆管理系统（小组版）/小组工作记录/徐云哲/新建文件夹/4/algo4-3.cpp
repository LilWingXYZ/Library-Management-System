#include "c1.h"
typedef int ElemType;
#include "c2-5.h"
#include "c4-2.h"
#include "algo4-3.h"
#include "first.h"

//�������ṹ��������algo4-3.h��

//ȫ�ֱ���
BK  bookinfo;//BK * bookinfo=NULL;
char buf[MaxLineLen+1];
WordLisType wdlist,noidx;

//��ʼ����������������idxlistΪ�ձ�����idxlist.item[0]��һ�մ�
void InitIdxList(IdxListType &idxlist)
{
    idxlist.last=0;
    InitString(idxlist.item[0].key);   //��ʼ��[0]��Ԫ��������bo2-4.cpp��
    InitList(idxlist.item[0].bnolist);  //��ʼ��[0]��Ԫ��������bo2-6.cpp��
}

void ExtractKeyWord(int &BookNo)
{
    int i,l,f=1;   //f���ַ���buf������־0:����  1��δ����
    char *s1=NULL,*s2=NULL;
    for(i = 1; i <= wdlist.last; i++)
    {
        free(wdlist.item[i]);   //�ͷ���һ����Ŀ�ڴʱ�wdlist�Ĵ洢�ռ�
        wdlist.item[i]=NULL;
    }
    wdlist.last=0;  // ��ʼ���ʱ�wdlist�Ĵ�����
     BookNo=atoi(bookinfo.book_num);

    s1=buf;//s1=&buf[4];
    while(f)  //��ȡ�����ؼ��ʵ��ʱ�wdlist
    {
        s2=strchr(s1, ' ');   //s2ָ��s1��ĵ�һ���ո���û�У�����NULL
        if(!s2)   //����β��û�ո�
        {
            s2=strchr(s1,'\0');//s2=strchr(s1,'\12');
            //s2ָ��buf�����һ���ַ����س���10�� MYӦ�ø�Ϊ'\0'(��������־)��gets������س���
            f=0;
        }
        l=s2-s1;   //���ʳ���
        if(s1[0] >= 'A' && s1[0] <= 'Z')   //������д��ĸΪ��д
        {  //д��ʱ�
            wdlist.item[wdlist.last]=(char *)malloc((l+1)*sizeof(char));
            //���ɴ��ռ䣨������\0����
            for(i = 0; i < l; i++)
                wdlist.item[wdlist.last][i]=s1[i];   //д��ʱ�
            wdlist.item[wdlist.last][l]=0;   // ����������\0��== 0
            for(i =0; i < noidx.last &&(l=strcmp(wdlist.item[wdlist.last],noidx.item[i])) >0 ;i++)
                   ;   //�����Ƿ�Ϊ��������
            if(!l)   //�Ƿ�������
            {
                free(wdlist.item[wdlist.last]);   //�Ӵʱ���ɾ���ô�
                wdlist.item[wdlist.last]=NULL;
            }
            else
                wdlist.last++;   //�ʱ��ȼ�1
        }
        s1=s2+1;   //s1�ƶ�����һ�����ʵ����ַ���
    };
    s1=NULL;s2=NULL;
}

//��wd���شʱ�wdlist�еĵ�i���ؼ���
void GetWord(int i, HString &wd)
{
    StrAssign(wd,wdlist.item[i]);   //���ɹؼ����ַ��� bo2-4.cpp
}

//��������idxlist�в�ѯ�Ƿ������wd��ȵĹؼ��ʡ������ڣ��򷵻������������е�λ�ã���bȡֵTRUE�����򷵻ز����λ�ã���bȡֵFALSE
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


//������idxlist�ĵ�i���ϲ���ؼ���wd,����ʼ���������������Ϊ�ձ�
void InsertNewKey(IdxListType &idxlist,int i,HString wd)
{
    int j=0;
    for (j = idxlist.last; j >= i; --j)  //����������
    {
        idxlist.item[j+1] = idxlist.item[j];
    }
    InitString(idxlist.item[i].key);   //bo4-2.cpp
    StrCopy( idxlist.item[i].key , wd);   //�����������µ�������bo2-4.cpp
    InitList(idxlist.item[i].bnolist);    //��ʼ�����������Ϊ�ձ� bo2-6.cpp
    idxlist.last++;
}

//��������idxlist�ĵ�i���в������Ϊbno������
void InsertBook(IdxListType &idxlist, int i, int bno)
{
    Link p;
    MakeNode(p , bno);   //������ bo2-6.cpp
    p->next=NULL;
    Append(idxlist.item[i].bnolist , p);  //�����µ�������� bo2-6.cpp
}

//�������Ϊbno�Ĺؼ��ʲ���������
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

//�����ɵ�������idxlist������ļ�f
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
    FILE *f; // �κ�ʱ������һ���ļ�
    IdxListType idxlist; // ������
    int BookNo; // ��ű���
    int k;

    if(!(f=fopen("NoIdx.txt","r"))) // �򿪷��������ļ�
    {
        printf("Can't open the NoIdx.txt file");
        exit(OVERFLOW);
    }
    fscanf(f,"%d",&noidx.last); // ��ȡ�������ʸ���
    for(k=0;k
    {
        fscanf(f,"%s",buf);
        if( (noidx.item[k]=(char*)malloc((strlen(buf)+1)*sizeof(char)))==NULL )
        {
            printf("����ʧ�ܣ�");
            exit(1);
        }
        strcpy(noidx.item[k],buf);    //Bug  buf��ֵ������noidx.item[k]��
    }
    fclose(f); // �رշ��������ļ�


    if(!(f=fopen("Book.txt","r"))) // ����Ŀ�ļ�
    {
        printf("Can't open the Book.txt file");
        exit(FALSE);
    }
    InitIdxList(idxlist); // ��������idxlistΪ�գ�����ʼ��[0]��Ԫ
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


    if(!(f=fopen("BookIdx.txt","w"))) // �������ؼ��������ļ�
    {
        printf("Can't open the BookIdx.txt file");
        exit(INFEASIBLE);
    }
    PutText(f,idxlist); // �����ɵ�������idxlist����������ؼ��������ļ�
    fclose(f); // �ر������ؼ��������ļ�
}

