#include "DeleteOption.h"
#include "SearchOption.h"
#include "UpdateOption.h"
#include "AddOption.h"
#include "IdGenerator.h"
#include "Display.h"
#include "User.h"
#include "FuzzyQuery.h"
#include "SuperManager.h"
#include "StdIO.h"
#include <iostream>
using namespace std;
void LoginFace()
{
    {
    int a = 10;
    for(int x=0;x<30;x++){
    for(int y=0;y<60+a;y++){
        if(x==0||x==29){if(y<a)cout<<" ";else cout<<"*";}
        else if(x==1){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else cout<<" ";}
        else if(x==2){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+9||y==a+50)cout<<"*";
                            else if(y==a+22||y==a+24||y==a+26||y==a+28||y==a+30||y==a+32||y==a+34||
                            y==a+36||y==a+38)cout<<"*"; else cout<<" ";}
        else if(x==3){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==8+a||y==10+a)cout<<"*";
                            else if(y==12+a||y==18+a||y==a+42||y==a+47||y==a+49||y==a+51)cout<<"*"; else cout<<" ";}
        else if(x==4){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+8||y==a+11||y==a+15||y==a+45
                            ||y==a+48||y==a+51)cout<<"*";else cout<<" ";}
        else if(x==5){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+8||y==a+13||y==a+47||y==a+51)
                            cout<<"*";else cout<<" ";}
        else if(x==6){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+8||y==a+51)
                            cout<<"*";else cout<<" ";}
        else if(x==7){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+6
                            ||y==a+53)cout<<"*";else cout<<" ";}
        else if(x==8){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+5
                            ||y==a+54)cout<<"*";else cout<<" ";}
        else if(x==9){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+4
                            ||y==a+55)cout<<"*";else cout<<" ";}
        else if(x==10){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+3
                            ||y==a+56)cout<<"*";
                      else if(y>=a+9&&y!=a+10&&y!=a+12&&y!=a+14&&y!=a+16&&y!=a+18&&y!=a+20&&y!=a+22&&y!=a+24&&y!=a+26&&y<=a+27)cout<<"*";
                      else if(y>=a+32&&y!=a+33&&y!=a+35&&y!=a+37&&y!=a+39&&y!=a+41&&y!=a+43&&y!=a+45&&y!=a+47&&y!=a+49&&y<=a+50)cout<<"*";else cout<<" ";}
        else if(x==11){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y==a+10||y==a+49||y==a+26||y==a+33)
                            cout<<"*";else if(y>=a+14&&y<=a+17)cout<<"*";else if(y>=a+42&&
                            y<=a+45)cout<<"*";else cout<<" ";}
        else if(x==12){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y==a+12||y==a+24||y==a+35||y==a+47)
                            cout<<"*";else cout<<" ";}
        else if(x==13){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y>=a+14&&y!=a+15&&y!=a+17&&y!=a+19&&y<=a+20)cout<<"*";else if
                            (y>=a+39&&y!=a+40&&y!=a+42&&y!=a+44&&y<=a+45)cout<<"*";else cout<<" ";}
        else if(x==14){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else cout<<" ";}
        else if(x==15){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y==a+8||y==50+a) cout<<"*";else cout<<" ";}
        else if(x==16){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y==a+8||y==50+a) cout<<"*";else cout<<" ";}
        else if(x==17){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y==a+8||y==50+a) cout<<"*";else cout<<" ";}
        else if(x==18){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y==a+9||y==49+a) cout<<"*";else cout<<" ";}
        else if(x==19){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+2
                            ||y==a+57)cout<<"*";else if(y==a+10||y==48+a) cout<<"*";else cout<<" ";}
        else if(x==20){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+3
                            ||y==a+56)cout<<"*";else if(y==a+11||y==47+a) cout<<"*";else cout<<" ";}
        else if(x==21){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+4
                            ||y==a+55)cout<<"*";else if(y==a+13||y==45+a) cout<<"*";else cout<<" ";}
        else if(x==22){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+5
                            ||y==a+54)cout<<"*";else if(y==a+15||y==43+a) cout<<"*";else cout<<" ";}
        else if(x==23){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+7
                            ||y==a+52)cout<<"*";else if(y==a+17||y==41+a) cout<<"*";else cout<<" ";}
        else if(x==24){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+10
                            ||y==a+49)cout<<"*";else if(y==a+21||y==a+25||y==a+29||y==a+33||y==a+37)cout<<"*";else cout<<" ";}
        else if(x==25){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+13
                            ||y==a+46)cout<<"*";else cout<<" ";}
        else if(x==26){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if
                            (y>=a+17&&y!=a+18&&y!=a+20&&y!=a+22&&y!=a+24&&y!=a+26&&
                            y!=a+28&&y!=a+29&&y!=a+31&&y!=a+33&&y!=a+35&&y!=a+37&&
                            y!=a+39&&y!=a+41&&y<=42+a)cout<<"*";else cout<<" ";}
        else if(x==27){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+16
                            ||y==a+25||y==a+29||y==a+30||y==a+31||y==a+35||y==a+43)cout<<"*";else cout<<" ";}
        else if(x==28){if(y<a)cout<<" ";else if(y==a||y==59+a) cout<<"$";else if(y==a+15
                            ||y==a+26||y==a+27||y==a+33||y==a+34||y==a+44)cout<<"*";else cout<<" ";}

        }
        cout<<endl;
    }
    }
    cout << setw(65) <<"【一个普通到不好意思取名字的羞涩(/ω＼)图书管理系统】" ;
    showWelcome("    初始账号登录界面    ");
    cout<< setw(56)<<"┏━━━━━━━━━━━━━━━┓"<<endl;
    cout<< setw(56)<<"┃                              ┃"<<endl;
    cout<< setw(56)<<" ┃欢迎光临本图书馆里系统(ΦωΦ)┃"<<endl;
    cout<< setw(56)<<"┃                              ┃"<<endl;
    cout<< setw(56)<<"┗━━━━━━━━━━━━━━━┛"<<endl<<endl;
}

void InitialInterface()
{
    showWelcome("     图书馆管理系统     ");
    cout<< setw(56)<<"┏━━━━━━━━━━━━━━━┓"<<endl;
    cout<< setw(56)<<"┃2,登陆                        ┃"<<endl;
    cout<< setw(56)<<"┃4,查询                        ┃"<<endl;
    cout<< setw(56)<<"┃1,退出                        ┃"<<endl;
    cout<< setw(56)<<"┗━━━━━━━━━━━━━━━┛"<<endl;
}
void showUserLevelMenu()
{
    showWelcome("     图书馆管理系统     ");
    cout<< setw(56)<<"┏━━━━━━━━━━━━━━━┓"<<endl;
    cout<< setw(56)<<"┃1,退出登陆界面                ┃"<<endl;
    cout<< setw(56)<<"┃2,登陆超级管理员              ┃"<<endl;//5,7,8
    cout<< setw(56)<<"┃3,用户信息维护                ┃"<<endl;
    cout<< setw(56)<<"┃4,查询                        ┃"<<endl;
    cout<< setw(56)<<"┃5,借书                        ┃"<<endl;//
    cout<< setw(56)<<"┃6,还书                        ┃"<<endl;
    cout<< setw(56)<<"┃7,预约                        ┃"<<endl;//
    cout<< setw(56)<<"┃8,续借                        ┃"<<endl;//
    cout<< setw(56)<<"┃9,挂失                        ┃"<<endl;
    cout<< setw(56)<<"┗━━━━━━━━━━━━━━━┛"<<endl;
}

void showManagePeopleMenu()
{
    showWelcome("图书管理员---用户管理界面");
    cout<< setw(56)<<"┏━━━━━━━━━━━━━━━┓"<<endl;
    cout<< setw(56)<<"┃1,增加用户                    ┃"<<endl;
    cout<< setw(56)<<"┃2,删除用户                    ┃"<<endl;
    cout<< setw(56)<<"┃3,更改用户信息                ┃"<<endl;
    cout<< setw(56)<<"┃4,查询用户信息                ┃"<<endl;
    cout<< setw(56)<<"┃5,恢复被删除用户              ┃"<<endl;
    cout<< setw(56)<<"┃6,退出                        ┃"<<endl;
    cout<< setw(56)<<"┗━━━━━━━━━━━━━━━┛"<<endl;
}

void showManageBookMenu()
{
    showWelcome("图书管理员---书籍管理界面");
    cout<< setw(56)<<"┏━━━━━━━━━━━━━━━┓"<<endl;
    cout<< setw(56)<<"┃1,增加书籍                    ┃"<<endl;
    cout<< setw(56)<<"┃2,删除书籍                    ┃"<<endl;
    cout<< setw(56)<<"┃3,更改书籍信息                ┃"<<endl;
    cout<< setw(56)<<"┃4,查询书籍信息                ┃"<<endl;
    cout<< setw(56)<<"┃5,恢复被删除书籍              ┃"<<endl;
    cout<< setw(56)<<"┃6,丢失书籍已寻回              ┃"<<endl;
    cout<< setw(56)<<"┃7,退出                        ┃"<<endl;
    cout<< setw(56)<<"┗━━━━━━━━━━━━━━━┛"<<endl;
}
int main()
{
    string fileBookName = "fileBookInfo.dat";
    string filePeopleName = "filePeopleInfo.dat";
    BookClassIO bio;
    ReaderClassIO rio;
    StdIO io;
    if(!findFileExisting(fileBookName)) bio.createFile(fileBookName);
    if(!findFileExisting(filePeopleName)) rio.createFile(filePeopleName);
    //普通用户
    people ret[10];
    int distance = 0;
    int mode = 2;


    //ret[0]用户测试
    //构造User对象


    unsigned int bookId = 0;//7233913
    book Book;
    people People;
    User user;
    int choice = 0,way = -1,managerFlag = 0,loginFlag = 0;
    while(1)
    {
        if(loginFlag == 0)
        {
            unsigned int testId = 0;
            LoginFace();
            cout << "请您高贵典雅地输入您的账号(/ω＼) : " << endl;
            testId = (unsigned int)io.get_Int();
            distance = searchInstanceOfPeople(testId,filePeopleName);
            if(distance < 0){
                cout << "该用户不存在哦(/ω＼) \a\a\a\a\a\a" << endl;
                continue;
            }
            int state =  rio.readFile(ret,filePeopleName,distance,mode);
            if(state == 0 || state == -4)
            {
                User th = User(ret[0],fileBookName,filePeopleName);
                th.showUserInfo();
                user = th;
            }
            else  //如果没成功打开文件
            {
                cout << "文件竟然打开失败了！(/ω＼)" << endl;
                continue;
            }
        }
        if(user.getIsDeleted() == '1'){
            cout << "这个用户并不存在哦(/ω＼)  " << endl;
            continue;
        }
        if(!user.getOnlineState())
        {
            managerFlag = 0;
            loginFlag = 0;
            do
            {
                cout << "为了方便测试而在此处提示对应密码(ΦωΦ)：" << user.getPassword()<<endl;
                InitialInterface();
                cout<<"请高贵典雅地作出您的选择(/ω＼):";
                choice = io.get_Int();
            }
            while(choice!=2&&choice!=4&&choice!=1);
        }
        if(user.getOnlineState())
        {
                do{
                    showUserLevelMenu();
                    cout<<"请高贵典雅地作出您的选择(/ω＼):";
                    choice = io.get_Int();
                }while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7&&choice!=8&&choice!=9);
                if(user.getPeopleStatue()&&choice == 5 && choice == 7 && choice == 8){
                    cout << "有已借的书处于逾期未还状态，所以继续无法借阅书哦TnT" << endl;
                }
                if(choice == 2) managerFlag = 1;
        }
        switch(choice)
        {
        case 1:
            if(managerFlag!=0) managerFlag = 0;// reset flag
            else{
                loginFlag = 0;
                cout<<"顺利退出啦~期待再见呢(/ω＼)!"<<endl;
                user.logout();
            }
            break;
        case 2:
            cout<<"如果这个账号是第一次登录，那么密码与账号相同哟；首次登陆之后方可更改密码。(/ω＼)"<<endl;
            if(user.login(&Book,managerFlag)){
                cout<<"成功登录啦(ΦωΦ)!"<<endl;
                loginFlag = 1;
            }
            else{
                cout<<"登陆失败了呢QAQ!!"<<endl;
                loginFlag = 0;
            }
            if(managerFlag!=1||user.getLevel()!=2) break;
        case 3:
            {

            if(managerFlag!=1)// just ordinary function
            {
                cout<<"您最近的信息如下 : "<<endl;
                user.showUserInfo();
                cout<< setw(56)<<"┏━━━━━━━━━━━━━━━┓"<<endl;
                cout<< setw(56)<<"┃1.更新姓名                    ┃"<<endl;
                cout<< setw(56)<<"┃2.更新密码                    ┃"<<endl;
                cout<< setw(56)<<"┃0.退出                        ┃"<<endl;
                cout<< setw(56)<<"┗━━━━━━━━━━━━━━━┛"<<endl;
                cout<<"请高贵典雅地作出您的选择(/ω＼): ";
                way = io.get_Int();
                while(way < 0 || way >3)
                {
                    cout << "非法输入呀(/ω＼), 请重新输入："<<endl;
                    way = io.get_Int();

                }
                while(way)
                {

                    switch(way)
                    {

                    case 1:
                        cout <<endl<< "用户名: ";
                        char Name[20];
                        io.get_CharArr(20,Name);
                        user.setPeopleName(Name);
                        People  = user.getPeopleClass();
                        user.updatePeopleWhole(&People);
                        break;
                    case 2:{
                        int pwdcFlag = 0;
                        cout <<endl<< "密码: ";
                        char password[10],conform[10];
                        io.get_pwd(password);
                        cout << endl << "请确认密码:" << endl;
                        io.get_pwd(conform);
                        if(strcmp(password,conform)!=0) pwdcFlag = 1;
                        if(pwdcFlag == 1) cout << endl << "两次输入的密码不一致，退出密码修改 " << endl;
                        if(pwdcFlag == 0){
                            user.setPassword(password);
                            People  = user.getPeopleClass();
                            user.updatePeopleWhole(&People);

                        }
                    }
                        break;
                    default:
                        cout<<"非法选择了呢! (/ω＼) "<<endl;
                    }
                    cout<<endl<<"\n高贵典雅地按下任意键以继续哦(/ω＼)...";
                    system("pause>nul");
                    cout<< setw(56)<<"┏━━━━━━━━━━━━━━━┓"<<endl;
                    cout<< setw(56)<<"┃1.更新姓名                    ┃"<<endl;
                    cout<< setw(56)<<"┃2.更新密码                    ┃"<<endl;
                    cout<< setw(56)<<"┃0.退出                        ┃"<<endl;
                    cout<< setw(56)<<"┗━━━━━━━━━━━━━━━┛"<<endl;
                    cout<< setw(49)<<"请高贵典雅地作出您的选择(/ω＼): ";
                    way = io.get_Int();

                }
            }
            else if(user.getLevel() == 2 && user.getOnlineState()){
                SuperManager sm(user.getPeopleClass(),fileBookName,filePeopleName);
                cout<< setw(56)<< "┏━━━━━━━━━━━━━━━┓"<<endl;
                cout <<setw(56)<< "┃1.用户信息管理                ┃" << endl;
                cout <<setw(56)<< "┃2.书籍信息管理                ┃" << endl;
                cout <<setw(56)<< "┃3.退出                        ┃" << endl;
                cout<< setw(56)<< "┗━━━━━━━━━━━━━━━┛"<<endl;
                choice = io.get_Int();
                if(choice == 1)
                {
                    do
                    {
                        showManagePeopleMenu();
                        choice = io.get_Int();
                    }
                    while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6);

                    switch(choice)
                    {
                    case 1:
                        sm.addUser();
                        break;
                    case 2:
                        sm.deleteUser();
                        break;
                    case 3:
                        sm.updateUserInfo();
                        break;
                    case 4:
                        sm.searchUser();
                        break;
                    case 5:
                        sm.recoverDeletedUser();
                        break;
                    default:
                        cout << "exiting" <<endl;
                    }
                }
                else if(choice == 2){
                    do{
                        showManageBookMenu();
                        choice = io.get_Int();
                    }
                    while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7);
                    switch(choice)
                    {
                    case 1:
                        sm.addBook();
                        break;
                    case 2:
                        sm.deleteBook();
                        break;
                    case 3:
                        sm.updateBookInfo();
                        break;
                    case 4:
                        sm.searchBook();
                        break;
                    case 5:
                        sm.recoverDeletedBook();
                        break;
                    case 6:
                        sm.recoverLost();
                        break;
                    default:
                        cout << "exiting" <<endl;
                    }
                }
                else cout << "抱歉, 选择错误, 退出" << endl;
            }
            }
            break;
        case 4:
            way = -1;
            showWelcome("      书籍查询界面       ");
                    cout << setw(56);
            cout<<"┏━━━━━━━━━━━━━━━┓"<<endl;
                    cout << setw(56);
            cout<<"┃1:  无条件全展示书籍信息      ┃"<<endl;
                    cout << setw(56);
            cout<<"┃2:  通过书籍编号              ┃"<<endl;
                    cout << setw(56);
            cout<<"┃3:  通过最近借该书籍的用户编号┃"<<endl;
                    cout << setw(56);
            cout<<"┃4:  通过类别                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃5:  通过价格区间              ┃"<<endl;
                    cout << setw(56);
            cout<<"┃6:  通过书名                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃7:  通过出版社                ┃"<<endl;
                    cout << setw(56);
            cout<<"┃8:  通过作者                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃9:  通过出版日期              ┃"<<endl;
                    cout << setw(56);
            cout<<"┃10: 通过被借出时间            ┃"<<endl;
                    cout << setw(56);
            cout<<"┃12: 模糊查询                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃0:  返回                      ┃"<<endl;
                    cout << setw(56);
            cout<<"┗━━━━━━━━━━━━━━━┛"<<endl;
            cout <<endl<<endl<< "请高贵典雅地作出您的选择(/ω＼):";
            way = io.get_Int();
            system("cls");
            showWelcome("      书籍查询界面       ");
            while(way < 0 || way >12)
            {
                cout << "出错了哦，请重新出入吧(/ω＼)："<<endl;
                way = io.get_Int();

            }
            while(way)
            {
                switch(way) //没做限制数据判断
                {
                case 1:
                    user.getOptionClass().searchAllBook();
                    break;
                case 2:
                    cout <<endl<< "书籍编号: ";
                    int BID;
                    BID = io.get_Int();
                    user.getOptionClass().searchBookId(BID);
                    break;
                case 3:
                    cout <<endl<< "该书最近借书人编号: ";
                    int PID;
                    PID = io.get_Int();
                    user.getOptionClass().searchBookPeopleId(PID);
                    break;
                case 4:
                    cout <<endl<< "类别: ";
                    int CLASS;
                    CLASS = io.get_Int();
                    user.getOptionClass().searchBookClass(CLASS);
                    break;
                case 5:
                    cout <<endl<< "Price1 ~ Price2: ";
                    float price1,price2;
                    price1 = io.get_Float();
                    price2 = io.get_Float();
                    user.getOptionClass().searchBookPrice(price1,price2);
                    break;
                case 6:
                    cout <<endl<< "书名: ";
                    char name[45];
                    io.get_CharArr(45,name);
                    user.getOptionClass().searchBookName(name);
                    break;
                case 7:
                    cout <<endl<< "出版社: ";
                    char Publisher[25];
                    io.get_CharArr(25,Publisher);
                    user.getOptionClass().searchBookPublisher(Publisher);
                    break;
                case 8:
                    cout <<endl<< "作者: ";
                    char Author[25];
                    io.get_CharArr(25,Author);
                    user.getOptionClass().searchBookAuthor(Author);
                    break;
                case 9:
                    cout <<endl<< "出版日期: ";
                    char publishDate[5];
                    io.get_CharArr(5,publishDate);
                    user.getOptionClass().searchBookPublishDate(publishDate);//改到这里了！！！！！
                    break;
                case 10:
                    cout <<endl<< "借出时间: ";
                    char BorrowTime[11];
                    io.get_CharArr(11,BorrowTime);
                    user.getOptionClass().searchBookBorrowTime(BorrowTime);
                    break;
                case 11:
                    cout << "这项隐藏功能只能开发者能使用呢抱歉哟(/ω＼)"<<endl;
//                    cout <<endl<< "BookID: ";
//                    unsigned int bookId;
//                    cin >> bookId;
//                    int  dist ;
//                    dist = searchInstanceOfBook(bookId,fileBookName);
//                    cout <<endl<< "Its distance: " << dist << endl;
                    break;
                case 12:
                {
                    cout << endl<<"搜索内容 (ΦωΦ): " ;
                    string match ;
                    getchar();
                    getline(cin,match);
                    fuzzyQueryBook(match, fileBookName);
                }
                break;
                default :
                    cout << "非法选择了呢! (/ω＼)";
                    break;
                }
                cout<<endl<<"\n高贵典雅地按下任意键以继续哦(/ω＼)...";
                system("pause>nul");
                showWelcome("      书籍查询界面       ");
                    cout << setw(56);
            cout<<"┏━━━━━━━━━━━━━━━┓"<<endl;
                    cout << setw(56);
            cout<<"┃1:  无条件全展示书籍信息      ┃"<<endl;
                    cout << setw(56);
            cout<<"┃2:  通过书籍编号              ┃"<<endl;
                    cout << setw(56);
            cout<<"┃3:  通过最近借该书籍的用户编号┃"<<endl;
                    cout << setw(56);
            cout<<"┃4:  通过类别                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃5:  通过价格区间              ┃"<<endl;
                    cout << setw(56);
            cout<<"┃6:  通过书名                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃7:  通过出版社                ┃"<<endl;
                    cout << setw(56);
            cout<<"┃8:  通过作者                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃9:  通过出版日期              ┃"<<endl;
                    cout << setw(56);
            cout<<"┃10: 通过被借出时间            ┃"<<endl;
                    cout << setw(56);
            cout<<"┃12: 模糊查询                  ┃"<<endl;
                    cout << setw(56);
            cout<<"┃0:  返回                      ┃"<<endl;
                    cout << setw(56);
            cout<<"┗━━━━━━━━━━━━━━━┛"<<endl;
            cout <<endl<<endl<< "请高贵典雅地作出您的选择(/ω＼):";
                way = io.get_Int();
                showWelcome("      书籍查询界面       ");
            }
            break;
        case 5:
            cout<<"请华丽地输入您要宠幸的那本书的编号(/ω＼):";
            bookId = (unsigned int) io.get_Int();
            cout<<bookId;
            if(getBook(bookId,fileBookName,&Book)!=-1)
            {
                user.borrowBooks(&Book);
                LBook lbook = LBook(Book);
                lbook.displayBook();
                user.showUserInfo();
            }

            break;
        case 6:
            cout<<"请华丽地输入您要归还的那本书的编号(/ω＼):";
            bookId = (unsigned int) io.get_Int();
            if(getBook(bookId,fileBookName,&Book)!=-1)
            {
                user.returnBooks(&Book);
                LBook lbook = LBook(Book);
                lbook.displayBook();
                user.showUserInfo();
            }
            break;
        case 7:
            cout<<"请华丽地输入您要预约的那本书的编号(/ω＼):";
            bookId = (unsigned int) io.get_Int();
            if(getBook(bookId,fileBookName,&Book)!=-1)
            {
                user.orderBooks(&Book);
                LBook lbook = LBook(Book);
                lbook.displayBook();
                user.showUserInfo();
            }

            break;


        case 8:
            cout<<"请华丽地输入您要续借的那本书的编号(/ω＼):";
            bookId = (unsigned int) io.get_Int();
            if(getBook(bookId,fileBookName,&Book)!=-1)
            {
                user.continueBorrow(&Book);
                LBook lbook = LBook(Book);
                lbook.displayBook();
                user.showUserInfo();
            }

            break;


        case 9:
            cout<<"大人您丢了多少本书呢(/ω＼):";//输入总共丢失的书本数量
            way = io.get_Int();
            cout<<endl;
            while(way>user.getNumBooksBorrowed())
            {
                cout<<"骗人呐！QAQ您根本借不了那么多本书的!再确认一下吧："<<endl;
               way = io.get_Int();
            }
            for(int i=0; i<way; i++)
            {
                cout<<"请忧伤地输入您丢失的那本书的编号TnT:";
                bookId = (unsigned int) io.get_Int();
                if(getBook(bookId,fileBookName,&Book)!=-1)
                {
                    user.ReportLoss(&Book);
                    LBook lbook = LBook(Book);
                    lbook.displayBook();
                    user.showUserInfo();

                }
            }
            break;

        default:
            cout<<"非法选择了呢! (/ω＼),请重新输入吧~ :";

        }

            //system("cls");

    }


}

