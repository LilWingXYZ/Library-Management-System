#include "User.h"
#include "StdIO.h"
#include "SuperManager.h"
#include<iostream>
#define filePeople "filePeopleInfo.dat"
#define fileBook "fileBookInfo.dat"
using namespace std;
///构造函数
User::User(people PEOPLE_IN,string fileBookName_in,string filePeopleName_in):option(fileBookName_in,filePeopleName_in,&PEOPLE_IN)
{

    this->People = PEOPLE_IN;
    setMaxBooksBorrowed();//根据用户限制最大借书数量,maxBooksBorrowed=int(credit/10)
    for(int i=0; i<MAX_BORROW; i++) //初始化numBooksBorrowed,numBooksRecent
    {
        if(People.booksBorrowed[i]!=0)
            numBooksBorrowed++;
    }
     for(int i=0; i<MAX_RECENT_BORROW; i++) //初始化numBooksBorrowed,numBooksRecent
    {
        if(People.recentBorrowId[i]!=0)
             numBooksRecent++;
    }

    onlineState = false;
}



///以下为设置用户信息
void User::updateBookWhole(book *Book)
{
    updateBook(option.getFileBookName(),Book);

}//功能描述：整体修改书籍信息




void User::updatePeopleWhole(people *People)
{
   updatePeople(option.getFilePeopleName(),People);

}//功能描述：整体修改用户信息


void User::setRecentBorrowId(int recentBorrowId,int index)
{
    if(index >=1 && index <= MAX_RECENT_BORROW)
    {
        People.recentBorrowId[index-1] = recentBorrowId;
        updatePeopleWhole(&(this->People));
    }
    else{
        cout<<"the index is out of max values(10)"<<endl;
    }



} //功能描述：部分设置用户最近借阅书籍第index本的id值


void User::setBooksBorrowed(int booksBorrowedId,int index)
{
    if(index >=1 && index <= MAX_RECENT_BORROW)
    {
        People.booksBorrowed[index-1] = booksBorrowedId;
        updatePeopleWhole(&(this->People));
    }
    else
        cout<<"the index is out of max values(10)"<<endl;

} //功能描述：部分设置用户已经借阅书籍第index本的id值


void User::AddRecentBorrowId(int recentBorrowId)
{
    if(numBooksRecent < MAX_RECENT_BORROW)
    {
        for(int i=0; i<MAX_RECENT_BORROW; i++)
            if(People.recentBorrowId[i]==0)
            {
                People.recentBorrowId[i] = recentBorrowId;
                numBooksRecent++;
                setRecentBorrowId(recentBorrowId,i+1);//对第i+1本进行更新
                break;

            }

    }else if(numBooksRecent == MAX_RECENT_BORROW){//若数组满，则将首元素移除，进入队尾

        for(int i = 0 ; i < numBooksRecent-1;i++){
            People.recentBorrowId[i] = People.recentBorrowId[i+1];

        }

        People.recentBorrowId[numBooksRecent-1] = recentBorrowId;


    }
    else{
        cout<<"recentBooks are full"<<endl;
    }


} //功能描述：增加用户最近借阅书籍：


void User::AddBooksBorrowed(int booksBorrowedId)
{

    if(numBooksBorrowed < maxBooksBorrowed)
    {
        for(int i=0; i<MAX_BORROW; i++)
            if(People.booksBorrowed[i]==0)
            {
                People.booksBorrowed[i] = booksBorrowedId;
                numBooksBorrowed++;
                setBooksBorrowed(booksBorrowedId,i+1);//对第i+1本进行更新
                break;

            }

    }
    else
        cout<<"borrowedBooks are full"<<endl;

}//功能描述：增加用户已经借阅书籍

void User::DeleteRecentBorrowId(int recentBorrowId)
{
    int i;
    for(i=0; i<MAX_RECENT_BORROW; i++)
    {
        if(People.recentBorrowId[i]==recentBorrowId)
        {
            People.recentBorrowId[i]=0;//如果有该本书，将其设置为0
            numBooksRecent--;
            setRecentBorrowId(0,i+1);
            break;
        }

    }
    if(i==MAX_RECENT_BORROW)
        cout<<recentBorrowId<<"--this book is not in recent borrow history"<<endl;
    else
        cout<<"this book is delete successfully!"<<endl;

} //功能描述：从用户最近借阅书籍删除为recentBorrowId值的记录

void User::DeleteBooksBorrowed(int booksBorrowedId)
{

    int i;
    for(i=0; i<MAX_BORROW; i++)
    {
        if(People.booksBorrowed[i]==booksBorrowedId)
        {
            People.booksBorrowed[i]=0;//如果有该本书，将其设置为0
            numBooksBorrowed--;
            setBooksBorrowed(0,i+1);
            break;
        }

    }
    if(i==MAX_BORROW)
        cout<<booksBorrowedId<<"--this book is not in borrow history"<<endl;
    else
        cout<<"this book is delete successfully!"<<endl;

}//功能描述：从用户已经借阅书籍删除为booksBorrowedId值的记录


void User::setOnlineState(int state)
{

    onlineState = state;

}


void User::setPeopleId(int peopleId)
{

    People.peopleId = peopleId;



}


void User::setLevel(int level)
{

    People.level = level;


}


void User::setCredit(int credit)
{
    if(credit < 0)
        People.credit  = 0;
    People.credit = credit;

}
void User::setPeopleName(char *name)
{

    if(sizeof(name)<MAX_NAME)
        strcpy(People.peopleName,name);
    else
        cout<<"Your input is out of the max bytes of the people name!"<<endl;

}


void User::setPassword(char *password)
{

    if(sizeof(password)<MAX_PASSWORD)
        strcpy(People.password,password);
    else
        cout<<"Your input is out of the max bytes of the password!"<<endl;


}


void User::setIsDeleted(char isDelete)
{

    People.isDeleted = isDelete;

}


void User::setIsRealDeleted(char isRealDelete)
{

    People.isRealDeleted = isRealDelete;

}



void User::setNumBooksRecent(int numBooksRecent)
{
    this->numBooksRecent = numBooksRecent;


}//功能描述：设置用户历史借阅书籍数量



void User::setNumBooksBorrowed(int numBooksBorrowed)
{

    this->numBooksBorrowed = numBooksBorrowed;

}//功能描述：设置用户已借书数量


void User::setMaxBooksBorrowed()
{

    maxBooksBorrowed = int(People.credit/10);
    if(maxBooksBorrowed > MAX_BORROW-numBooksBorrowed)
        maxBooksBorrowed = MAX_BORROW-numBooksBorrowed;
    if(maxBooksBorrowed < 0)
        maxBooksBorrowed = 0;

}//功能描述：设置用户最高可借书数量





///以下为返回用户信息
bool User::getOnlineState()
{

    return onlineState;


}//返回用户在线状态信息



int User::getPeopleId()
{

    return People.peopleId;

} //功能描述：返回用户id


int User::getLevel()
{

    return People.level;

} //功能描述：返回用户等级;


int User::getCredit()
{

    return People.credit;

} //功能描述：返回用户信用点
string User::getPeopleName()
{

    return People.peopleName;

} //功能描述

int User::getRecentBorrowId(int index)
{
    int Count = 0;//计数不为0的第几本
    if(index >=1 && index <= numBooksRecent)
        for(int i=0; i<MAX_RECENT_BORROW; i++)
            if(People.recentBorrowId[i]!=0)
            {
                Count++;
                if(Count == index)
                    return People.recentBorrowId[i];
            }

    else{

         return -1;//index超出目前历史借阅书籍数量

    }



} //功能描述：返回用户历史借阅书籍第index本的书本id值

int User::getBooksBorrowed(int index)
{

    int Count = 0;//计数不为0的第几本
    if(index >=1 && index <= numBooksBorrowed)
        for(int i=0; i<MAX_BORROW; i++)
            if(People.booksBorrowed[i]!=0)
            {
                Count++;
                if(Count == index)
                    return People.booksBorrowed[i];
            }

    else{

        return -1;//index超出目前借阅书籍数量
    }




} //功能描述：返回用户目前借阅书籍第index本的书本id值;参数

int User::getBooksBorrowedIndex(int bookId)
{

    for(int i=0; i<MAX_BORROW; i++)
        if(People.booksBorrowed[i] ==  bookId)
        {
            return i;
        }
    return -1;//bookId这本书不在借阅数组中

}//功能描述：返回用户目前借阅书籍号为bookId的书本在booksBorrowed数组的下标值

string User::getPassword()
{

    return People.password;


} //功能描述：获得用户密码;参数：空；返回值：string；调用：无：


int User::getNumBooksBorrowed()
{

    return numBooksBorrowed;

}//功能描述：返回用户已经借阅书籍数量

int User::getMaxBooksBorrowed()
{

    return maxBooksBorrowed;
} //功能描述：返回用户最大借阅书籍数量

char User::getIsDeleted()
{
    return People.isDeleted;

} //功能描述：返回该用户是否被伪删除状态信息


char User::getIsRealDeleted()
{

    return People.isRealDeleted;

}//功能描述：返回该用户是否被真删除状态信息

float User::getPunishmentMoney()
{

    return (100-People.credit)*0.1;

}//返回罚款金额


Option User::getOptionClass()
{

    return option;


}//返回操作类

people User::getPeopleClass()
{

    return People;


}//返回操作类
bool User::getPeopleStatue(){

    book Book;
    for(int i=0; i<MAX_BORROW; i++){
        if(People.booksBorrowed[i]!=0){
             if(getBook(People.booksBorrowed[i],option.getFileBookName(),&Book)!=-1){
                     if(Book.isLated = '1')
                        return true;
            }
        }

    }
    return false;

}//判断用户是否处于超期状态


void User::showUserInfo()
{
    cout<<"----------user info------------"<<endl;
    cout <<"PeopleId:       " << People.peopleId << endl;
    cout <<"PeopleName:     " << People.peopleName  << endl;
    cout <<"level:          " << People.level  << endl;
    cout <<"credit:         " << People.credit  << endl;
    cout <<"onlineState:    " << onlineState<< endl;
    cout <<"PunishmentMoney:" << getPunishmentMoney() <<endl;
    cout <<"maxBooksBorrowed:"<< maxBooksBorrowed <<endl;
    cout <<"booksRecentBorrowed:  " << endl;
    cout <<"numBooksRecent:    " << numBooksRecent<< endl;
    for(int i=0; i<MAX_RECENT_BORROW; i++){
         if(People.recentBorrowId[i]!=0)
            cout<<People.recentBorrowId[i]<<"\t";
         else
            cout<<"empty!"<<endl;

    }
    cout<<endl;

    cout <<"booksBorrowed:  " << endl;
    cout <<"numBooksBorrowed:    " << numBooksBorrowed<< endl;
    for(int i=0; i<MAX_BORROW; i++){
        if(People.booksBorrowed[i]!=0)
            cout<<People.booksBorrowed[i]<<"\t";
        else
            cout<<"empty!"<<endl;
    }
    cout<<endl;
} ///功能描述:展示用户信息



///以下为根据用户等级可进行具体图书操作功能

//---------------------------借书,还书,预约,续借基本功能------------------------



void User::borrowBooks(book *Book)
{
    if(Book->isDeleted =='1'||Book->isRealDeleted == '1'){
        cout << "no such a book" << endl;
        return;
    }
    if(Book->isReservedFlag == '1'){
        if(Book->peopleId != this->getPeopleId()){
            cout << "this Book is Reserved by others" << endl;
            return;
        }
    }
    if( (Book->borrowFlag!='1') &&(searchInstanceOfBook(Book->bookId,option.getFileBookName())>=0) && (maxBooksBorrowed>0) && (Book->isPreservedFlag!='1')) //判断所借书籍是否在书库中并且还有继续借书的能力
    {
        cout<<"The number of books you can borrow : "<<MAX_BORROW - numBooksBorrowed<<endl;
        AddBooksBorrowed(Book->bookId);//将书籍加入到借阅数组中
        //设置book的信息
        Book->peopleId = People.peopleId;
        Book->borrowFlag = '1';
        Ltime time = Ltime();
        strcpy(Book->borrowTime,((char*)time.getDate().c_str()));//修改时间为当前系统时间
        updateBookWhole(Book);

    }else{
        cout<<"This book you can not borrow!"<<endl;
    }

}///功能描述：用户从书库借书


void User::returnBooks(book *Book)
{

    int subIndex = getBooksBorrowedIndex(Book->bookId);//获取bookId在借阅数组中的下标值
    if(subIndex!=-1){
        People.booksBorrowed[subIndex]=0;//将该本书在借阅数组中移除
        numBooksBorrowed--;//借阅书籍数量-1
        AddRecentBorrowId(Book->bookId);
        //设置bookId信息
        Book->borrowFlag = '0';
        Book->peopleId = 0;
        Book->isLated = '0';
        strcpy(Book->borrowTime, "0000000000");
        updateBookWhole(Book);
    }else{
        cout<<"Your return book is not found in your borrow history!"<<endl;
    }



}///功能描述：用户还书


void User::orderBooks(book *Book)
{
    if(Book->isDeleted =='1'||Book->isRealDeleted == '1'){
        cout << "no such a book" << endl;
        return;
    }
    if((Book->borrowFlag!='1') && (Book->isReservedFlag!='1') && (searchInstanceOfBook(Book->bookId,option.getFileBookName())>=0) && (maxBooksBorrowed > 0) && (Book->isPreservedFlag!='1')) //判断所借书籍是否在书库中并且还有继续借书的能力
    {
        AddBooksBorrowed(Book->bookId);//将书籍加入到借阅数组中
        //设置book的信息
        Book->peopleId = People.peopleId;
        Book->isReservedFlag = '1';
        Ltime time = Ltime();
        strcpy(Book->borrowTime,((char*)time.getDate().c_str()));//修改时间为当前系统时间
        updateBookWhole(Book);

    }else{
        cout<<"This book you can not order!"<<endl;
    }



}///功能描述：用户预约借书；


void User::continueBorrow(book *Book)
{
    if(Book->isDeleted =='1'||Book->isRealDeleted == '1'){
        cout << "no such a book" << endl;
        return;
    }
    if((Book->isReservedFlag!='1') && getBooksBorrowedIndex(Book->bookId)>=0&&getBooksBorrowedIndex(Book->bookId) < MAX_BORROW) //续借书籍存在借阅数组中
    {
        Book->isLated = '0';//设置逾期标识为false
        Ltime time = Ltime();
        strcpy(Book->borrowTime,((char*)time.getDate().c_str()));//修改时间为当前系统时间
        updateBookWhole(Book);

    }
    else{
        cout<<"This book you can not continue to borrow!"<<endl;
    }

}///功能描述：续借；


bool User::login(book *Book,int mode)
{
     //控制用户输入ID和密码
    StdIO io;
    char *Password = new char [10];
    string temp = People.password;
    cout << "Your ID:";
    cout << People.peopleId <<endl;
    cout <<"Input your password:";
    getchar();
    io.get_pwd(Password);
    if(mode == 1 && temp.compare(Password) == 0){
        cout << "welcome" << endl;
        return true;
    }
    if(temp.compare(Password) == 0)//判断用户姓名和登录密码是否正确
    {

        for(int i=0; i<MAX_BORROW; i++)
        {

            if(People.booksBorrowed[i]!=0)
            {
                if(getBook(People.booksBorrowed[i],option.getFileBookName(),Book)!=-1){
                     LBook lbook = LBook(*Book);
                     cout<<lbook.GetBorrowTime()<<endl;
                     if(lbook.GetBorrowTime() > MAX_BORROW_DAY && lbook.getborrowFlag() == '1')
                        {//若该本书为已借状态，判断是否超过30天
                            AddRecentBorrowId(lbook.getbookId());
                            Book->isLated = '1';
                            setCredit(People.credit-(lbook.GetBorrowTime()-MAX_BORROW_DAY));//逾期进行信用点扣除
                            setMaxBooksBorrowed();//信用点改变，最大借书数量也改变
                            updateBookWhole(Book);
                            updatePeopleWhole(&(this->People));
                        }
                    if(lbook.GetBorrowTime() > MAX_ORDER_DAY && lbook.getisReservedFlag() == '1')
                        {//若该本书为预约状态，判断是否超过7天
                            AddRecentBorrowId(lbook.getbookId());
                            Book->isReservedFlag = '0';
                            Book->peopleId = 0;
                            setCredit(People.credit-(lbook.GetBorrowTime()-MAX_ORDER_DAY));//逾期进行信用点扣除
                            setMaxBooksBorrowed();//信用点改变，最大借书数量也改变
                            updateBookWhole(Book);
                            DeleteBooksBorrowed(People.booksBorrowed[i]);//将预约超过期限的书籍从借阅数组中移除
                            updatePeopleWhole(&(this->People));
                        }


                }
            }

        }
        if(maxBooksBorrowed == 0 && MAX_BORROW - numBooksBorrowed > 0){//若最大可借数量为0，并且MAX_BORROW - numBooksBorrowed大于0，代表credit值过低
            cout<<"Your current account has been frozen, the amount to be paid is"<<getPunishmentMoney()<<" yuan !"<<endl;
            cout<<"Please pay the cost :";
            float cost;
            while(true){
                cin>>cost;
                if(cost >= getPunishmentMoney()){
                    maxBooksBorrowed = MAX_BORROW - numBooksBorrowed;
                    if(cost > getPunishmentMoney()) cout << "return " << (cost - getPunishmentMoney()) << "yuan" << endl;
                    SuperManager sm(this->getPeopleClass(),fileBook,filePeople);
                    sm.recoverCredit();//讲信用点恢复到100
                    break;
                }
                cout<<"the amount is less than expected, please hand in enough money :" << endl;
            }


        }
        onlineState = true;//设置用户为在线状态为TRUE
        return true;
    }
    onlineState = false;//设置用户为在线状态为FALSE
    return false;



}///功能描述：返回该用户与服务器的连接状态,当用户登陆成功，自动计算credit，若超期一天，-1


void User::logout()
{
    onlineState = false;
    updatePeopleWhole(&(this->People));//更新用户信息
    cout<<"logout Successful!"<<endl;

}///功能描述：返回该用户与服务器的连接状态


void User::ReportLoss(book *Book)
{

            int subIndex = getBooksBorrowedIndex(Book->bookId);//获取该本书在BooksBorrowed数组中的下标值
            if(subIndex != -1){

                AddRecentBorrowId(Book->bookId);
                DeleteBooksBorrowed(Book->bookId);

                 //设置bookId信息
                Book->isDeleted = '1';
                Book->isLated = '1';
                strcpy(Book->borrowTime,"0000000000");

                setCredit(People.credit-SubCredit_LOST);//将Credit值-10
                setMaxBooksBorrowed();//信用点改变，最大借书数量也改变
                updateBookWhole(Book);
                updatePeopleWhole(&(this->People));

            }else{

                cout<<"This book is not in your booksBorrowed array!";

            }




}///功能描述：挂失；

