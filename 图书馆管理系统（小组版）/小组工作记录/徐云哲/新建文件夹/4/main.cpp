#include "c1.h"
typedef int ElemType;
#include "c2-5.h"
#include "c4-2.h"
#include "algo4-3.h"
#include "first.h"

void first_main()
{
    FILE *fp_book,*fp_reader;
    if((fp_book=fopen("Book.txt","r+"))==NULL && (fp_reader=fopen("Reader.txt","r+"))==NULL)
    {
        about();
        Init();
    }
    else
    {   Load();
        printf("\t���߼�ͼ����Ϣ������ϡ�\n");

        //algo43_main();
        printf("\t�ؼ��ʼ����������ϡ�\n");
    }

    Menu_select();
}//end"first_main()"


int main(void)
{
    first_main();

    return 0;
}
