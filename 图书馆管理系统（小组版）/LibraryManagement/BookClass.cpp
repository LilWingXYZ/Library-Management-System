#include<iostream>
#include "BookClass.h"

using namespace std;

///���캯��

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
///���캯��������ID�棩

LBook::LBook(unsigned int bookIdt,string fname)
{
    if((searchInstanceOfBook(bookIdt,fname))< 0)
    {
        Book.bookId = bookIdt;
        BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
        book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
        int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
        int flag = 0;//��־�Ƿ��ҵ�
        while(distance < (bm.currentFileSize(fname)-1)) //������û����ʱ,bm.currentFileSize(fname)Ϊ��ǰ�ļ���ʵ�����
        {

            int state = bm.readFile(ret,fname,distance,2);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
            if(state == 0) //state��¼���ص��ļ��������0Ϊ�ɹ���
            {
                for(int i = 0; i < 10; i++) //ʮ��ʮ�����������Ƿ�ƥ��
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
                    distance++;//�Ҳ���������һ��
                }
                //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

            }
            else  //���û�ɹ����ļ�
            {
                cout << "Read file error!QAQ!" << endl;
            }
            if(flag == 1) //�ҵ��ˣ����˳�
            {
                break;
            }
        }

    }
    else  //�����ID�������ļ���
    {
        cout << "Can't find such a bookId" << endl;
    }

}
*/
///���ƺ���-------------------------
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
///չʾ����
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

///���úͻ�ȡ�鱾�ĸ�������
int LBook::setbookId(unsigned int bookIdt)
{
    int state = 1;//��state��Ϊ״̬�жϣ�����ĸ�ʽ�жϡ�bug���ݣ�֮���ٲ�����������
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
            return "�������塢ë��˼�롢��Сƽ����";
        case PhilosophyReligion:
            return "��ѧ�ڽ�";
        case Social:
            return "����ѧ����";
        case PoliticalLaw:
            return "���η���";
        case Military:
            return "����";
         case Economic:
            return "����";
        case Literature_PE:
            return "�Ļ�����ѧ������������";
        case Language:
            return "���ԡ�����";
        case Literature:
            return "��ѧ";
        case Art:
            return "����";
        case HistoryGeography:
            return "��ʷ������";
        case Nature:
            return "��Ȼ��ѧ����";
        case MathChemistry:
            return "�����ѧ�뻯ѧ";
        case Astronomy:
            return "����ѧ�������ѧ";
        case Biology:
            return "�����ѧ";
        case Medicine:
            return "ҽҩ������";
        case Agriculture:
            return "ũҵ��ѧ";
        case Industry:
            return "��ҵ����";
        case Transportation:
            return "��ͨ����";
        case Aerospace:
            return  "���ա�����";
        case EnvironmentSafety:
            return "������ȫ��ѧ";
        case Comprehensive:
            return "�ۺ���ͼ��";
        default:
            return "��ȡ��Ϣ����";
            break;
    }

}
//            float price;//�۸�
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
//            char bookName[45];//����,���44���ֽڣ�22������
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
//            char publisher[25];//������,24���ֽڣ�12������
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
//            char author[25];//���ߣ�24���ֽڣ�12������
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
//            char publishDate[5];//������ݣ�4���ֽڣ�ֻ����ݣ�����2009
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
//            char borrowFlag;//�����־λ
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
//            char isReservedFlag;//Ԥ����־λ
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
//            char isPreservedFlag;//���汾��־λ
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
//            char isLated;//�Ƿ�����
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
//            char isRealDeleted;//�Ƿ�����ɾ��
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
///�жϸ���ӽ���ʱ����뵱ǰϵͳʱ�������
int LBook::GetBorrowTime()
{
    string str(Book.borrowTime);
    Ltime time = Ltime();
    return time.DaysBetween2Date(time.getDate(),str);

}
///����book�ṹ������

book LBook::getBookStruct()
{

    return Book;

}



