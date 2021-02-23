#include<iostream>
#include<cstring>
#define bookNameLength 45
#define publisherLength 25
#define authorLength 25
#define publishDateLength 5
#define borrowTimeLength 11

//cstring主要是为了配合使用memcpy函数来进行char类型数组的数据传入
//关于命名：比如publisher相关函数传入的变量命名为publishert(=publishertemp,暂时变量，用于接收)

using namespace std;
typedef enum bookClassification{MaoDeng,PhilosophyReligion,Social,PoliticalLaw,Military,Economic,Literature_PE,Language,
Literature,Art,HistoryGeography,Nature,MathChemistry,Astronomy,Biology,Medicine,Agriculture,Industry,Transportation,
Aerospace,Environmental,Safety,Comprehensive}BookType;

class Book//图书行为操作类
{
        public:


            //构造函数
            Book(unsigned int bookIdt,unsigned int peopleIdt,int bookClasst,float pricet,char bookNamet[45],
                 char publishert[25],char authort[25],char publishDatet[5],char borrowTimet[11],char borrowFlagt,
                 char isReservedFlagt,char isPreservedFlagt,char isLatedt,char isDeletedt,char isRealDeletedt);

            //复制函数
            Book(Book &t);

            //展示函数
            void displayBook();

//            unsigned int bookId;//identify number for books
            int setbookId(unsigned int bookId);
            unsigned int getbookId();
//            unsigned int peopleId;//indentify number for readers
            int setpeopleId(unsigned int peopleId);
            int getpeopleId();
//            int bookClass; //书籍分类,bookClass为1-22，分别对应22个分类,对应枚举变量bookClass-1
            int setbookClass(int bookClass);
            int getbookClass();
//            float price;//价格
            int setprice(float price);
            float getprice();
//            char bookName[45];//书名,最大44个字节，22个汉字
            int setbookName(char bookName[45]);
            string getbookName();

//            char publisher[25];//出版社,24个字节，12个汉字
            int setpublisher(char publisher[25]);
            string getpublisher();
//            char author[25];//作者，24个字节，12个汉字
            int setauthor(char author[25]);
            string getauthor();
//            char publishDate[5];//出版年份，4个字节，只有年份，例如2009
            int setpublishDate(char publishDate[5]);
            string getpublishDate();
//            char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
            int setborrowTime(char borrowTime[11]);
            string getborrowTime();
//            char borrowFlag;//借出标志位
            int setborrowFlag(char borrowFlag);
            char getborrowFlag();
//            char isReservedFlag;//预定标志位
            int setisReservedFlag(char isReservedFlag);
            char getisReservedFlag();
//            char isPreservedFlag;//保存本标志位
            int setisPreservedFlag(char isPreservedFlag);
            char getisPreservedFlag();
//            char isLated;//是否逾期
            int setisLated(char isLated);
            char getisLated();
//            char isDeleted;//whether the record is delated(false as default)
            int setisDeleted(char isDeleted);
            char getisDeleted();
//            char isRealDeleted;//是否真正删除
            int setisRealDeleted(char isRealDeleted);
            char getisRealDeleted();
//            string getBookValue(BookType num){
//                switch(num){
//                    case MaoDeng:
//                        return "马列主义、毛泽东思想、邓小平理论";
//                    case PhilosophyReligion:
//                        return "哲学宗教";
//                    case Social:
//                        return "社会科学总论";
//                    case PoliticalLaw:
//                        return "政治法律";
//                    case Military:
//                        return "军事";
//                     case Economic:
//                        return "经济";
//                    case Literature_PE:
//                        return "文化、科学、教育、体育";
//                    case Language:
//                        return "语言、文字";
//                    case Literature:
//                        return "文学";
//                    case Art:
//                        return "艺术";
//                    case HistoryGeography:
//                        return "历史、地理";
//                    case Nature:
//                        return "自然科学总论";
//                    case MathChemistry:
//                        return "数理科学与化学";
//                    case Astronomy:
//                        return "天文学、地球科学";
//                    case Biology:
//                        return "生物科学";
//                    case Medicine:
//                        return "医药、卫生";
//                    case Agriculture:
//                        return "农业科学";
//                    case Industry:
//                        return "工业技术";
//                    case Transportation:
//                        return "交通运输";
//                    case Aerospace:
//                        return  "航空、航天";
//                    case EnvironmentSafety:
//                        return "环境安全科学";
//                    case Comprehensive:
//                        return "综合性图书";
//                    default:
//                        return "获取信息出错";
//                        break;
//            }
//
//        }
        private:
            unsigned int bookId;
            unsigned int peopleId;
            int bookClass;
            float price;
            char bookName[45];
            char publisher[25];
            char author[25];
            char publishDate[5];
            char borrowTime[11];
            char borrowFlag;
            char isReservedFlag;
            char isPreservedFlag;
            char isLated;
            char isDeleted;
            char isRealDeleted;
};
//构造函数-------------------------
Book::Book(unsigned int bookIdt,unsigned int peopleIdt,int bookClasst,float pricet,char bookNamet[45],
     char publishert[25],char authort[25],char publishDatet[5],char borrowTimet[11],char borrowFlagt,
     char isReservedFlagt,char isPreservedFlagt,char isLatedt,char isDeletedt,char isRealDeletedt){
            bookId = bookIdt;
            peopleId = peopleIdt;
            bookClass = bookClasst;
            price = pricet;
            memcpy(bookName,bookNamet,bookNameLength);
            memcpy(publisher,publishert,publisherLength);
            memcpy(author,authort,authorLength);
            memcpy(publishDate,publishDatet,publishDateLength);
            memcpy(borrowTime,borrowTimet,borrowTimeLength);
            borrowFlag = borrowFlagt;
            isReservedFlag = isReservedFlagt;
            isPreservedFlag = isPreservedFlagt;
            isLated = isLatedt;
            isDeleted = isDeletedt;
            isRealDeleted = isRealDeletedt;
            cout << "This is a constructor !" << endl;

}
//复制函数-------------------------
Book::Book(Book & t){
            bookId = t.bookId;
            peopleId = t.peopleId;
            bookClass = t.bookClass;
            price = t.price;
//            memcpy(bookName,t.bookName,sizeof(t.bookName));
            strcpy(bookName,t.bookName);
            memcpy(publisher,t.publisher,sizeof(t.publisher));
            memcpy(author,t.author,sizeof(t.author));
            memcpy(publishDate,t.publishDate,sizeof(t.publishDate));
            memcpy(borrowTime,t.borrowTime,sizeof(t.borrowTime));
            borrowFlag = t.borrowFlag;
            isReservedFlag = t.isReservedFlag;
            isPreservedFlag = t.isPreservedFlag;
            isLated = t.isLated;
            isDeleted = t.isDeleted;
            isRealDeleted = t.isRealDeleted;
            cout << "This is a copy constructor !" << endl;

}
//展示函数
void Book::displayBook(){
            cout <<"bookId:         " << bookId  << endl;
            cout <<"peopleId:       " << peopleId  << endl;
            cout <<"bookClass:      " << bookClass  << endl;
            cout <<"price:          " << price  << endl;
            cout <<"bookName:       " << bookName  << endl;
            cout <<"publisher:      " << publisher  << endl;
            cout <<"author:         " << author  << endl;
            cout <<"publishDate:    " << publishDate  << endl;
            cout <<"borrowTime:     " << borrowTime  << endl;
            cout <<"borrowFlag:     " << borrowFlag  << endl;
            cout <<"isReservedFlag: " << isReservedFlag  << endl;
            cout <<"isPreservedFlag:" << isPreservedFlag  << endl;
            cout <<"isLated:        " << isLated  << endl;
            cout <<"isDeleted:      " << isDeleted  << endl;
            cout <<"isRealDeleted:  " << isRealDeleted  << endl << endl;

}
//            unsigned int bookId;//identify number for books
            int Book::setbookId(unsigned int bookIdt){
                int state = 1;//用state作为状态判断，具体的格式判断、bug数据，之后再补充完整加入
                if(state == 0){
                    return -1;
                }
                bookId = bookIdt;
                return 0;
            }
            unsigned int Book::getbookId(){
                return bookId;
            }
//            unsigned int peopleId;//indentify number for readers
            int Book::setpeopleId(unsigned int peopleIdt){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                peopleId = peopleIdt;
                return 0;
            }
            int Book::getpeopleId(){
                return peopleId;
            }
//            int bookClass; //书籍分类,bookClass为1-22，分别对应22个分类,对应枚举变量bookClass-1
            int Book::setbookClass(int bookClasst){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                bookClass = bookClasst;
                return 0;
            }
            int Book::getbookClass(){
                return bookClass;
            }
//            float price;//价格
            int Book::setprice(float pricet){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                price = pricet;
                return 0;
            }
            float Book::getprice(){
                return price;
            }
//            char bookName[45];//书名,最大44个字节，22个汉字
            int Book::setbookName(char bookNamet[45]){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                memcpy(bookName,bookNamet,bookNameLength);
                return 0;
            }
            string Book::getbookName(){
                return bookName;
            }
//            char publisher[25];//出版社,24个字节，12个汉字
            int Book::setpublisher(char publishert[25]){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                memcpy(publisher,publishert,publisherLength);
                return 0;
            }
            string Book::getpublisher(){
                return publisher;
            }
//            char author[25];//作者，24个字节，12个汉字
            int Book::setauthor(char authort[25]){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                memcpy(author,authort,authorLength);
                return 0;
            }
            string Book::getauthor(){
                return author;
            }
//            char publishDate[5];//出版年份，4个字节，只有年份，例如2009
            int Book::setpublishDate(char publishDatet[5]){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                memcpy(publishDate,publishDatet,publishDateLength);
                return 0;
            }
            string Book::getpublishDate(){
                return publishDate;
            }
//            char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
            int Book::setborrowTime(char borrowTimet[11]){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                memcpy(borrowTime,borrowTimet,borrowTimeLength);
                return 0;
            }
            string Book::getborrowTime(){
                return borrowTime;
            }
//            char borrowFlag;//借出标志位
            int Book::setborrowFlag(char borrowFlagt){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                borrowFlag = borrowFlagt;
                return 0;
            }
            char Book::getborrowFlag(){
                return borrowFlag;
            }
//            char isReservedFlag;//预定标志位
            int Book::setisReservedFlag(char isReservedFlagt){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                isReservedFlag = isReservedFlagt;
                return 0;
            }
            char Book::getisReservedFlag(){
                return isReservedFlag;
            }
//            char isPreservedFlag;//保存本标志位
            int Book::setisPreservedFlag(char isPreservedFlagt){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                isPreservedFlag = isPreservedFlagt;
                return 0;
            }
            char Book::getisPreservedFlag(){
                return isPreservedFlag;
            }
//            char isLated;//是否逾期
            int Book::setisLated(char isLatedt){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                isLated = isLatedt;
                return 0;
            }
            char Book::getisLated(){
                return isLated;
            }
//            char isDeleted;//whether the record is delated(false as default)
            int Book::setisDeleted(char isDeletedt){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                isDeleted = isDeletedt;
                return 0;
            }
            char Book::getisDeleted(){
                return isDeleted;
            }
//            char isRealDeleted;//是否真正删除
            int Book::setisRealDeleted(char isRealDeletedt){
                int state = 1;
                if(state == 0){
                    return -1;
                }
                isRealDeleted = isRealDeletedt;
                return 0;
            }
            char Book::getisRealDeleted(){
                return isRealDeleted;
            }
int main(){
            Book test(110021020,1502003110,3,98.8,"Ares's life","ChangJiang","Kim Ares","1997","19970426",'1','0','0','0','0','0');
            test.displayBook();
            Book test2(test);
            test2.displayBook();
            test.setbookName("Amanda koko");
            test.displayBook();
            cout << "getbookName: " << test.getbookName();


            return 0;
}
