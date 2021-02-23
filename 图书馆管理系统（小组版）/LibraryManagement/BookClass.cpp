#include<iostream>
#include "BookClass.h"

using namespace std;

///构造函数

LBook::LBook(book Book)
{
    this->Book.bookId = Book.bookId;
    this->Book.peopleId = Book.peopleId;
    this->Book.bookClass = Book.bookClass;
    this->Book.price = Book.price;
    memcpy(this->Book.bookName,Book.bookName,bookNameLength);
    memcpy(this->Book.publisher,Book.publisher,publisherLength);
    memcpy(this->Book.author,Book.author,authorLength);
    memcpy(this->Book.publishDate,Book.publishDate,publishDateLength);
    memcpy(this->Book.borrowTime,Book.borrowTime,borrowTimeLength);
    this->Book.borrowFlag = Book.borrowFlag;
    this->Book.isReservedFlag = Book.isReservedFlag;
    this->Book.isPreservedFlag = Book.isPreservedFlag;
    this->Book.isLated = Book.isLated;
    this->Book.isDeleted = Book.isDeleted;
    this->Book.isRealDeleted = Book.isRealDeleted;

}
/*
///构造函数（仅有ID版）

LBook::LBook(unsigned int bookIdt,string fname)
{
    if((searchInstanceOfBook(bookIdt,fname))< 0)
    {
        Book.bookId = bookIdt;
        BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
        book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
        int distance = 0;//初始化开始查找的位置为0.
        int flag = 0;//标志是否找到
        while(distance < (bm.currentFileSize(fname)-1)) //当数据没找完时,bm.currentFileSize(fname)为当前文件里实体个数
        {

            int state = bm.readFile(ret,fname,distance,2);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
            if(state == 0) //state记录返回的文件打开情况，0为成功打开
            {
                for(int i = 0; i < 10; i++) //十个十个地拿与检测是否匹配
                {
                    if(bookIdt == ret[i].bookId)
                    {
                        Book.bookClass = ret[i].bookClass;
                        Book.price = ret[i].price;
                        memcpy(Book.bookName,ret[i].bookName,bookNameLength);
                        memcpy(Book.publisher,ret[i].publisher,publisherLength);
                        memcpy(Book.author,ret[i].author,authorLength);
                        memcpy(Book.publishDate,ret[i].publishDate,publishDateLength);
                        memcpy(Book.borrowTime,ret[i].borrowTime,borrowTimeLength);
                        Book.borrowFlag = ret[i].borrowFlag;
                        Book.isReservedFlag = ret[i].isReservedFlag;
                        Book.isPreservedFlag = ret[i].isPreservedFlag;
                        Book.isLated = ret[i].isLated;
                        Book.isDeleted = ret[i].isDeleted;
                        Book.isRealDeleted = ret[i].isRealDeleted;
                        cout << "This is a constructor(bookId) !" << endl;
                        flag = 1;
                        break;
                    }
                    distance++;//找不到则找下一个
                }
                //前面十个找不到的话，再重新循环读十个

            }
            else  //如果没成功打开文件
            {
                cout << "Read file error!QAQ!" << endl;
            }
            if(flag == 1) //找到了，就退出
            {
                break;
            }
        }

    }
    else  //这个书ID不存在文件里
    {
        cout << "Can't find such a bookId" << endl;
    }

}
*/
///复制函数-------------------------
/*LBook::LBook(LBook const& t)
{

    Book.bookId = t.getbookId();
    Book.peopleId = t.getpeopleId();
    Book.bookClass = t.getbookClass();
    Book.price = t.getprice();
    strcpy(Book.bookName,t.getbookName());
    memcpy(Book.publisher,t.getpublisher(),sizeof(t.publisher));
    memcpy(Book.author,t,getauthor(),sizeof(t.author));
    memcpy(Book.publishDate,t.getpublishDate(),sizeof(t.publishDate));
    memcpy(Book.borrowTime,t.getborrowTime(),sizeof(t.borrowTime));
    Book.borrowFlag = t.getborrowFlag();
    Book.isReservedFlag = t.getisReservedFlag();
    Book.isPreservedFlag = t.getisPreservedFlag();
    Book.isLated = t.getisLated();
    Book.isDeleted = t.getisDeleted();
    Book.isRealDeleted = t.getisRealDeleted();

    cout << "This is a copy constructor !" << endl;
}*/
///展示函数
//##ModelId=5A156E0B020D
void LBook::displayBook()
{
    cout <<"bookId:         " << Book.bookId  << endl;
    cout <<"peopleId:       " << Book.peopleId  << endl;
    cout <<"bookClass:      " << getBookClassName() << endl;
    cout <<"price:          " << Book.price  << endl;
    cout <<"bookName:       " << Book.bookName  << endl;
    cout <<"publisher:      " << Book.publisher  << endl;
    cout <<"author:         " << Book.author  << endl;
    cout <<"publishDate:    " << Book.publishDate  << endl;
    cout <<"borrowTime:     " << Book.borrowTime  << endl;
    cout <<"borrowFlag:     " << Book.borrowFlag  << endl;
    cout <<"isReservedFlag: " << Book.isReservedFlag  << endl;
    cout <<"isPreservedFlag:" << Book.isPreservedFlag  << endl;
    cout <<"isLated:        " << Book.isLated  << endl;
    cout <<"isDeleted:      " << Book.isDeleted  << endl;
    cout <<"isRealDeleted:  " << Book.isRealDeleted  << endl << endl;

}

///设置和获取书本的各个属性
int LBook::setbookId(unsigned int bookIdt)
{
    int state = 1;//用state作为状态判断，具体的格式判断、bug数据，之后再补充完整加入
    if(state == 0)
    {
        return -1;
    }
    Book.bookId = bookIdt;
    return 0;
}
unsigned int LBook::getbookId()
{
    return Book.bookId;
}
int LBook::setpeopleId(unsigned int peopleIdt)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.peopleId = peopleIdt;
    return 0;
}
int LBook::getpeopleId()
{
    return Book.peopleId;
}
int LBook::setbookClass(int bookClasst)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.bookClass = bookClasst;
    return 0;
}

string LBook::getBookClassName(){

    BookType num = BookType(Book.bookClass-1);
    switch(num){
        case MaoDeng:
            return "马列主义、毛泽东思想、邓小平理论";
        case PhilosophyReligion:
            return "哲学宗教";
        case Social:
            return "社会科学总论";
        case PoliticalLaw:
            return "政治法律";
        case Military:
            return "军事";
         case Economic:
            return "经济";
        case Literature_PE:
            return "文化、科学、教育、体育";
        case Language:
            return "语言、文字";
        case Literature:
            return "文学";
        case Art:
            return "艺术";
        case HistoryGeography:
            return "历史、地理";
        case Nature:
            return "自然科学总论";
        case MathChemistry:
            return "数理科学与化学";
        case Astronomy:
            return "天文学、地球科学";
        case Biology:
            return "生物科学";
        case Medicine:
            return "医药、卫生";
        case Agriculture:
            return "农业科学";
        case Industry:
            return "工业技术";
        case Transportation:
            return "交通运输";
        case Aerospace:
            return  "航空、航天";
        case EnvironmentSafety:
            return "环境安全科学";
        case Comprehensive:
            return "综合性图书";
        default:
            return "获取信息出错";
            break;
    }

}
//            float price;//价格
int LBook::setprice(float pricet)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.price = pricet;
    return 0;
}
float LBook::getprice()
{
    return Book.price;
}
//            char bookName[45];//书名,最大44个字节，22个汉字
int LBook::setbookName(char bookNamet[45])
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    memcpy(Book.bookName,bookNamet,bookNameLength);
    return 0;
}
string LBook::getbookName()
{
    return Book.bookName;
}
//            char publisher[25];//出版社,24个字节，12个汉字
int LBook::setpublisher(char publishert[25])
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    memcpy(Book.publisher,publishert,publisherLength);
    return 0;
}
string LBook::getpublisher()
{
    return Book.publisher;
}
//            char author[25];//作者，24个字节，12个汉字
int LBook::setauthor(char authort[25])
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    memcpy(Book.author,authort,authorLength);
    return 0;
}
string LBook::getauthor()
{
    return Book.author;
}
//            char publishDate[5];//出版年份，4个字节，只有年份，例如2009
int LBook::setpublishDate(char publishDatet[5])
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    memcpy(Book.publishDate,publishDatet,publishDateLength);
    return 0;
}
string LBook::getpublishDate()
{
    return Book.publishDate;
}
//            char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
int LBook::setborrowTime(char borrowTimet[11])
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    memcpy(Book.borrowTime,borrowTimet,borrowTimeLength);
    return 0;
}
string LBook::getborrowTime()
{
    return Book.borrowTime;
}
//            char borrowFlag;//借出标志位
int LBook::setborrowFlag(char borrowFlagt)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.borrowFlag = borrowFlagt;
    return 0;
}
char LBook::getborrowFlag()
{
    return Book.borrowFlag;
}
//            char isReservedFlag;//预定标志位
int LBook::setisReservedFlag(char isReservedFlagt)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.isReservedFlag = isReservedFlagt;
    return 0;
}
char LBook::getisReservedFlag()
{
    return Book.isReservedFlag;
}
//            char isPreservedFlag;//保存本标志位
int LBook::setisPreservedFlag(char isPreservedFlagt)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.isPreservedFlag = isPreservedFlagt;
    return 0;
}
char LBook::getisPreservedFlag()
{
    return Book.isPreservedFlag;
}
//            char isLated;//是否逾期
int LBook::setisLated(char isLatedt)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.isLated = isLatedt;
    return 0;
}
char LBook::getisLated()
{
    return Book.isLated;
}
//            char isDeleted;//whether the record is delated(false as default)
int LBook::setisDeleted(char isDeletedt)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.isDeleted = isDeletedt;
    return 0;
}
char LBook::getisDeleted()
{
    return Book.isDeleted;
}
//            char isRealDeleted;//是否真正删除
int LBook::setisRealDeleted(char isRealDeletedt)
{
    int state = 1;
    if(state == 0)
    {
        return -1;
    }
    Book.isRealDeleted = isRealDeletedt;
    return 0;
}
char LBook::getisRealDeleted()
{
    return Book.isRealDeleted;
}
///判断该书从借阅时间距离当前系统时间的天数
int LBook::GetBorrowTime()
{
    string str(Book.borrowTime);
    Ltime time = Ltime();
    return time.DaysBetween2Date(time.getDate(),str);

}
///返回book结构体数组

book LBook::getBookStruct()
{

    return Book;

}



