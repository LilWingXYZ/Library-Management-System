#include<iostream>
#include<cstring>
#define bookNameLength 45
#define publisherLength 25
#define authorLength 25
#define publishDateLength 5
#define borrowTimeLength 11

//cstring��Ҫ��Ϊ�����ʹ��memcpy����������char������������ݴ���
//��������������publisher��غ�������ı�������Ϊpublishert(=publishertemp,��ʱ���������ڽ���)

using namespace std;
typedef enum bookClassification{MaoDeng,PhilosophyReligion,Social,PoliticalLaw,Military,Economic,Literature_PE,Language,
Literature,Art,HistoryGeography,Nature,MathChemistry,Astronomy,Biology,Medicine,Agriculture,Industry,Transportation,
Aerospace,Environmental,Safety,Comprehensive}BookType;

class Book//ͼ����Ϊ������
{
        public:


            //���캯��
            Book(unsigned int bookIdt,unsigned int peopleIdt,int bookClasst,float pricet,char bookNamet[45],
                 char publishert[25],char authort[25],char publishDatet[5],char borrowTimet[11],char borrowFlagt,
                 char isReservedFlagt,char isPreservedFlagt,char isLatedt,char isDeletedt,char isRealDeletedt);

            //���ƺ���
            Book(Book &t);

            //չʾ����
            void displayBook();

//            unsigned int bookId;//identify number for books
            int setbookId(unsigned int bookId);
            unsigned int getbookId();
//            unsigned int peopleId;//indentify number for readers
            int setpeopleId(unsigned int peopleId);
            int getpeopleId();
//            int bookClass; //�鼮����,bookClassΪ1-22���ֱ��Ӧ22������,��Ӧö�ٱ���bookClass-1
            int setbookClass(int bookClass);
            int getbookClass();
//            float price;//�۸�
            int setprice(float price);
            float getprice();
//            char bookName[45];//����,���44���ֽڣ�22������
            int setbookName(char bookName[45]);
            string getbookName();

//            char publisher[25];//������,24���ֽڣ�12������
            int setpublisher(char publisher[25]);
            string getpublisher();
//            char author[25];//���ߣ�24���ֽڣ�12������
            int setauthor(char author[25]);
            string getauthor();
//            char publishDate[5];//������ݣ�4���ֽڣ�ֻ����ݣ�����2009
            int setpublishDate(char publishDate[5]);
            string getpublishDate();
//            char borrowTime[11];//time of lending the book,year xxxx month xx date xx hour xx
            int setborrowTime(char borrowTime[11]);
            string getborrowTime();
//            char borrowFlag;//�����־λ
            int setborrowFlag(char borrowFlag);
            char getborrowFlag();
//            char isReservedFlag;//Ԥ����־λ
            int setisReservedFlag(char isReservedFlag);
            char getisReservedFlag();
//            char isPreservedFlag;//���汾��־λ
            int setisPreservedFlag(char isPreservedFlag);
            char getisPreservedFlag();
//            char isLated;//�Ƿ�����
            int setisLated(char isLated);
            char getisLated();
//            char isDeleted;//whether the record is delated(false as default)
            int setisDeleted(char isDeleted);
            char getisDeleted();
//            char isRealDeleted;//�Ƿ�����ɾ��
            int setisRealDeleted(char isRealDeleted);
            char getisRealDeleted();
//            string getBookValue(BookType num){
//                switch(num){
//                    case MaoDeng:
//                        return "�������塢ë��˼�롢��Сƽ����";
//                    case PhilosophyReligion:
//                        return "��ѧ�ڽ�";
//                    case Social:
//                        return "����ѧ����";
//                    case PoliticalLaw:
//                        return "���η���";
//                    case Military:
//                        return "����";
//                     case Economic:
//                        return "����";
//                    case Literature_PE:
//                        return "�Ļ�����ѧ������������";
//                    case Language:
//                        return "���ԡ�����";
//                    case Literature:
//                        return "��ѧ";
//                    case Art:
//                        return "����";
//                    case HistoryGeography:
//                        return "��ʷ������";
//                    case Nature:
//                        return "��Ȼ��ѧ����";
//                    case MathChemistry:
//                        return "�����ѧ�뻯ѧ";
//                    case Astronomy:
//                        return "����ѧ�������ѧ";
//                    case Biology:
//                        return "�����ѧ";
//                    case Medicine:
//                        return "ҽҩ������";
//                    case Agriculture:
//                        return "ũҵ��ѧ";
//                    case Industry:
//                        return "��ҵ����";
//                    case Transportation:
//                        return "��ͨ����";
//                    case Aerospace:
//                        return  "���ա�����";
//                    case EnvironmentSafety:
//                        return "������ȫ��ѧ";
//                    case Comprehensive:
//                        return "�ۺ���ͼ��";
//                    default:
//                        return "��ȡ��Ϣ����";
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
//���캯��-------------------------
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
//���ƺ���-------------------------
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
//չʾ����
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
                int state = 1;//��state��Ϊ״̬�жϣ�����ĸ�ʽ�жϡ�bug���ݣ�֮���ٲ�����������
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
//            int bookClass; //�鼮����,bookClassΪ1-22���ֱ��Ӧ22������,��Ӧö�ٱ���bookClass-1
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
//            float price;//�۸�
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
//            char bookName[45];//����,���44���ֽڣ�22������
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
//            char publisher[25];//������,24���ֽڣ�12������
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
//            char author[25];//���ߣ�24���ֽڣ�12������
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
//            char publishDate[5];//������ݣ�4���ֽڣ�ֻ����ݣ�����2009
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
//            char borrowFlag;//�����־λ
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
//            char isReservedFlag;//Ԥ����־λ
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
//            char isPreservedFlag;//���汾��־λ
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
//            char isLated;//�Ƿ�����
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
//            char isRealDeleted;//�Ƿ�����ɾ��
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
