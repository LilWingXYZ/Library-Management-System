#ifndef FIRSTH1
#define FIRSTH1

// #include
// #include
// #include
#include
#define Max 3

typedef struct book
{
    char book_num[10];
    char book_name[20];
    int  book_kc;     //MY库存总量
    int  book_xc;    //MY现存数量
    struct book *next;
}BK;

typedef struct Start
{
    int st_sec;
    int st_hour;
    int st_mday;
    int st_min;
    int st_mon;
    int st_year;
}start;

typedef struct borrow
{
    char borrow_book_num[10];
    start lend_t;
}BO;

typedef struct reader
{
    char reader_num[10];
    char reader_name[10];
    int right;     //MY读者最多借书本数
    BO borrow[Max];
    struct reader * next;
}RD;
//BK *h_book;
//RD *h_reader;

int Menu();
void Menu_select();
void Init();
void Init_reader();
void Init_book();
void Insert_New_Book();
void Insert_New_Reader();
void del_old_book();
void del_old_reader();
void book_not_enough();
int Find();
void Find_Select();
void Find_Reader();
void Find_Book_contral();
int  Find_Book_select();
void Find_Book();
void Borrow_Book();
void Return_Book();
void about();
int Print();
void Print_Select();
void Print_book();
void Print_reader();
void Save();
void Save_Reader();
void Save_Book();
void Load();
void Load_Reader();
void Load_Book();

#endif
