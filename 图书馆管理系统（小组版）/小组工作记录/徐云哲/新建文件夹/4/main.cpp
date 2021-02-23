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
        printf("\t读者及图书信息加载完毕。\n");

        //algo43_main();
        printf("\t关键词检索表更新完毕。\n");
    }

    Menu_select();
}//end"first_main()"


int main(void)
{
    first_main();

    return 0;
}
