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
    cout << setw(65) <<"��һ����ͨ��������˼ȡ���ֵ���ɬ(/�أ�)ͼ�����ϵͳ��" ;
    showWelcome("    ��ʼ�˺ŵ�¼����    ");
    cout<< setw(56)<<"����������������������������������"<<endl;
    cout<< setw(56)<<"��                              ��"<<endl;
    cout<< setw(56)<<" ����ӭ���ٱ�ͼ�����ϵͳ(���ئ�)��"<<endl;
    cout<< setw(56)<<"��                              ��"<<endl;
    cout<< setw(56)<<"����������������������������������"<<endl<<endl;
}

void InitialInterface()
{
    showWelcome("     ͼ��ݹ���ϵͳ     ");
    cout<< setw(56)<<"����������������������������������"<<endl;
    cout<< setw(56)<<"��2,��½                        ��"<<endl;
    cout<< setw(56)<<"��4,��ѯ                        ��"<<endl;
    cout<< setw(56)<<"��1,�˳�                        ��"<<endl;
    cout<< setw(56)<<"����������������������������������"<<endl;
}
void showUserLevelMenu()
{
    showWelcome("     ͼ��ݹ���ϵͳ     ");
    cout<< setw(56)<<"����������������������������������"<<endl;
    cout<< setw(56)<<"��1,�˳���½����                ��"<<endl;
    cout<< setw(56)<<"��2,��½��������Ա              ��"<<endl;//5,7,8
    cout<< setw(56)<<"��3,�û���Ϣά��                ��"<<endl;
    cout<< setw(56)<<"��4,��ѯ                        ��"<<endl;
    cout<< setw(56)<<"��5,����                        ��"<<endl;//
    cout<< setw(56)<<"��6,����                        ��"<<endl;
    cout<< setw(56)<<"��7,ԤԼ                        ��"<<endl;//
    cout<< setw(56)<<"��8,����                        ��"<<endl;//
    cout<< setw(56)<<"��9,��ʧ                        ��"<<endl;
    cout<< setw(56)<<"����������������������������������"<<endl;
}

void showManagePeopleMenu()
{
    showWelcome("ͼ�����Ա---�û��������");
    cout<< setw(56)<<"����������������������������������"<<endl;
    cout<< setw(56)<<"��1,�����û�                    ��"<<endl;
    cout<< setw(56)<<"��2,ɾ���û�                    ��"<<endl;
    cout<< setw(56)<<"��3,�����û���Ϣ                ��"<<endl;
    cout<< setw(56)<<"��4,��ѯ�û���Ϣ                ��"<<endl;
    cout<< setw(56)<<"��5,�ָ���ɾ���û�              ��"<<endl;
    cout<< setw(56)<<"��6,�˳�                        ��"<<endl;
    cout<< setw(56)<<"����������������������������������"<<endl;
}

void showManageBookMenu()
{
    showWelcome("ͼ�����Ա---�鼮�������");
    cout<< setw(56)<<"����������������������������������"<<endl;
    cout<< setw(56)<<"��1,�����鼮                    ��"<<endl;
    cout<< setw(56)<<"��2,ɾ���鼮                    ��"<<endl;
    cout<< setw(56)<<"��3,�����鼮��Ϣ                ��"<<endl;
    cout<< setw(56)<<"��4,��ѯ�鼮��Ϣ                ��"<<endl;
    cout<< setw(56)<<"��5,�ָ���ɾ���鼮              ��"<<endl;
    cout<< setw(56)<<"��6,��ʧ�鼮��Ѱ��              ��"<<endl;
    cout<< setw(56)<<"��7,�˳�                        ��"<<endl;
    cout<< setw(56)<<"����������������������������������"<<endl;
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
    //��ͨ�û�
    people ret[10];
    int distance = 0;
    int mode = 2;


    //ret[0]�û�����
    //����User����


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
            cout << "�����߹���ŵ����������˺�(/�أ�) : " << endl;
            testId = (unsigned int)io.get_Int();
            distance = searchInstanceOfPeople(testId,filePeopleName);
            if(distance < 0){
                cout << "���û�������Ŷ(/�أ�) \a\a\a\a\a\a" << endl;
                continue;
            }
            int state =  rio.readFile(ret,filePeopleName,distance,mode);
            if(state == 0 || state == -4)
            {
                User th = User(ret[0],fileBookName,filePeopleName);
                th.showUserInfo();
                user = th;
            }
            else  //���û�ɹ����ļ�
            {
                cout << "�ļ���Ȼ��ʧ���ˣ�(/�أ�)" << endl;
                continue;
            }
        }
        if(user.getIsDeleted() == '1'){
            cout << "����û���������Ŷ(/�أ�)  " << endl;
            continue;
        }
        if(!user.getOnlineState())
        {
            managerFlag = 0;
            loginFlag = 0;
            do
            {
                cout << "Ϊ�˷�����Զ��ڴ˴���ʾ��Ӧ����(���ئ�)��" << user.getPassword()<<endl;
                InitialInterface();
                cout<<"��߹���ŵ���������ѡ��(/�أ�):";
                choice = io.get_Int();
            }
            while(choice!=2&&choice!=4&&choice!=1);
        }
        if(user.getOnlineState())
        {
                do{
                    showUserLevelMenu();
                    cout<<"��߹���ŵ���������ѡ��(/�أ�):";
                    choice = io.get_Int();
                }while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7&&choice!=8&&choice!=9);
                if(user.getPeopleStatue()&&choice == 5 && choice == 7 && choice == 8){
                    cout << "���ѽ���鴦������δ��״̬�����Լ����޷�������ŶTnT" << endl;
                }
                if(choice == 2) managerFlag = 1;
        }
        switch(choice)
        {
        case 1:
            if(managerFlag!=0) managerFlag = 0;// reset flag
            else{
                loginFlag = 0;
                cout<<"˳���˳���~�ڴ��ټ���(/�أ�)!"<<endl;
                user.logout();
            }
            break;
        case 2:
            cout<<"�������˺��ǵ�һ�ε�¼����ô�������˺���ͬӴ���״ε�½֮�󷽿ɸ������롣(/�أ�)"<<endl;
            if(user.login(&Book,managerFlag)){
                cout<<"�ɹ���¼��(���ئ�)!"<<endl;
                loginFlag = 1;
            }
            else{
                cout<<"��½ʧ������QAQ!!"<<endl;
                loginFlag = 0;
            }
            if(managerFlag!=1||user.getLevel()!=2) break;
        case 3:
            {

            if(managerFlag!=1)// just ordinary function
            {
                cout<<"���������Ϣ���� : "<<endl;
                user.showUserInfo();
                cout<< setw(56)<<"����������������������������������"<<endl;
                cout<< setw(56)<<"��1.��������                    ��"<<endl;
                cout<< setw(56)<<"��2.��������                    ��"<<endl;
                cout<< setw(56)<<"��0.�˳�                        ��"<<endl;
                cout<< setw(56)<<"����������������������������������"<<endl;
                cout<<"��߹���ŵ���������ѡ��(/�أ�): ";
                way = io.get_Int();
                while(way < 0 || way >3)
                {
                    cout << "�Ƿ�����ѽ(/�أ�), ���������룺"<<endl;
                    way = io.get_Int();

                }
                while(way)
                {

                    switch(way)
                    {

                    case 1:
                        cout <<endl<< "�û���: ";
                        char Name[20];
                        io.get_CharArr(20,Name);
                        user.setPeopleName(Name);
                        People  = user.getPeopleClass();
                        user.updatePeopleWhole(&People);
                        break;
                    case 2:{
                        int pwdcFlag = 0;
                        cout <<endl<< "����: ";
                        char password[10],conform[10];
                        io.get_pwd(password);
                        cout << endl << "��ȷ������:" << endl;
                        io.get_pwd(conform);
                        if(strcmp(password,conform)!=0) pwdcFlag = 1;
                        if(pwdcFlag == 1) cout << endl << "������������벻һ�£��˳������޸� " << endl;
                        if(pwdcFlag == 0){
                            user.setPassword(password);
                            People  = user.getPeopleClass();
                            user.updatePeopleWhole(&People);

                        }
                    }
                        break;
                    default:
                        cout<<"�Ƿ�ѡ������! (/�أ�) "<<endl;
                    }
                    cout<<endl<<"\n�߹���ŵذ���������Լ���Ŷ(/�أ�)...";
                    system("pause>nul");
                    cout<< setw(56)<<"����������������������������������"<<endl;
                    cout<< setw(56)<<"��1.��������                    ��"<<endl;
                    cout<< setw(56)<<"��2.��������                    ��"<<endl;
                    cout<< setw(56)<<"��0.�˳�                        ��"<<endl;
                    cout<< setw(56)<<"����������������������������������"<<endl;
                    cout<< setw(49)<<"��߹���ŵ���������ѡ��(/�أ�): ";
                    way = io.get_Int();

                }
            }
            else if(user.getLevel() == 2 && user.getOnlineState()){
                SuperManager sm(user.getPeopleClass(),fileBookName,filePeopleName);
                cout<< setw(56)<< "����������������������������������"<<endl;
                cout <<setw(56)<< "��1.�û���Ϣ����                ��" << endl;
                cout <<setw(56)<< "��2.�鼮��Ϣ����                ��" << endl;
                cout <<setw(56)<< "��3.�˳�                        ��" << endl;
                cout<< setw(56)<< "����������������������������������"<<endl;
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
                else cout << "��Ǹ, ѡ�����, �˳�" << endl;
            }
            }
            break;
        case 4:
            way = -1;
            showWelcome("      �鼮��ѯ����       ");
                    cout << setw(56);
            cout<<"����������������������������������"<<endl;
                    cout << setw(56);
            cout<<"��1:  ������ȫչʾ�鼮��Ϣ      ��"<<endl;
                    cout << setw(56);
            cout<<"��2:  ͨ���鼮���              ��"<<endl;
                    cout << setw(56);
            cout<<"��3:  ͨ���������鼮���û���ũ�"<<endl;
                    cout << setw(56);
            cout<<"��4:  ͨ�����                  ��"<<endl;
                    cout << setw(56);
            cout<<"��5:  ͨ���۸�����              ��"<<endl;
                    cout << setw(56);
            cout<<"��6:  ͨ������                  ��"<<endl;
                    cout << setw(56);
            cout<<"��7:  ͨ��������                ��"<<endl;
                    cout << setw(56);
            cout<<"��8:  ͨ������                  ��"<<endl;
                    cout << setw(56);
            cout<<"��9:  ͨ����������              ��"<<endl;
                    cout << setw(56);
            cout<<"��10: ͨ�������ʱ��            ��"<<endl;
                    cout << setw(56);
            cout<<"��12: ģ����ѯ                  ��"<<endl;
                    cout << setw(56);
            cout<<"��0:  ����                      ��"<<endl;
                    cout << setw(56);
            cout<<"����������������������������������"<<endl;
            cout <<endl<<endl<< "��߹���ŵ���������ѡ��(/�أ�):";
            way = io.get_Int();
            system("cls");
            showWelcome("      �鼮��ѯ����       ");
            while(way < 0 || way >12)
            {
                cout << "������Ŷ�������³����(/�أ�)��"<<endl;
                way = io.get_Int();

            }
            while(way)
            {
                switch(way) //û�����������ж�
                {
                case 1:
                    user.getOptionClass().searchAllBook();
                    break;
                case 2:
                    cout <<endl<< "�鼮���: ";
                    int BID;
                    BID = io.get_Int();
                    user.getOptionClass().searchBookId(BID);
                    break;
                case 3:
                    cout <<endl<< "������������˱��: ";
                    int PID;
                    PID = io.get_Int();
                    user.getOptionClass().searchBookPeopleId(PID);
                    break;
                case 4:
                    cout <<endl<< "���: ";
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
                    cout <<endl<< "����: ";
                    char name[45];
                    io.get_CharArr(45,name);
                    user.getOptionClass().searchBookName(name);
                    break;
                case 7:
                    cout <<endl<< "������: ";
                    char Publisher[25];
                    io.get_CharArr(25,Publisher);
                    user.getOptionClass().searchBookPublisher(Publisher);
                    break;
                case 8:
                    cout <<endl<< "����: ";
                    char Author[25];
                    io.get_CharArr(25,Author);
                    user.getOptionClass().searchBookAuthor(Author);
                    break;
                case 9:
                    cout <<endl<< "��������: ";
                    char publishDate[5];
                    io.get_CharArr(5,publishDate);
                    user.getOptionClass().searchBookPublishDate(publishDate);//�ĵ������ˣ���������
                    break;
                case 10:
                    cout <<endl<< "���ʱ��: ";
                    char BorrowTime[11];
                    io.get_CharArr(11,BorrowTime);
                    user.getOptionClass().searchBookBorrowTime(BorrowTime);
                    break;
                case 11:
                    cout << "�������ع���ֻ�ܿ�������ʹ���ر�ǸӴ(/�أ�)"<<endl;
//                    cout <<endl<< "BookID: ";
//                    unsigned int bookId;
//                    cin >> bookId;
//                    int  dist ;
//                    dist = searchInstanceOfBook(bookId,fileBookName);
//                    cout <<endl<< "Its distance: " << dist << endl;
                    break;
                case 12:
                {
                    cout << endl<<"�������� (���ئ�): " ;
                    string match ;
                    getchar();
                    getline(cin,match);
                    fuzzyQueryBook(match, fileBookName);
                }
                break;
                default :
                    cout << "�Ƿ�ѡ������! (/�أ�)";
                    break;
                }
                cout<<endl<<"\n�߹���ŵذ���������Լ���Ŷ(/�أ�)...";
                system("pause>nul");
                showWelcome("      �鼮��ѯ����       ");
                    cout << setw(56);
            cout<<"����������������������������������"<<endl;
                    cout << setw(56);
            cout<<"��1:  ������ȫչʾ�鼮��Ϣ      ��"<<endl;
                    cout << setw(56);
            cout<<"��2:  ͨ���鼮���              ��"<<endl;
                    cout << setw(56);
            cout<<"��3:  ͨ���������鼮���û���ũ�"<<endl;
                    cout << setw(56);
            cout<<"��4:  ͨ�����                  ��"<<endl;
                    cout << setw(56);
            cout<<"��5:  ͨ���۸�����              ��"<<endl;
                    cout << setw(56);
            cout<<"��6:  ͨ������                  ��"<<endl;
                    cout << setw(56);
            cout<<"��7:  ͨ��������                ��"<<endl;
                    cout << setw(56);
            cout<<"��8:  ͨ������                  ��"<<endl;
                    cout << setw(56);
            cout<<"��9:  ͨ����������              ��"<<endl;
                    cout << setw(56);
            cout<<"��10: ͨ�������ʱ��            ��"<<endl;
                    cout << setw(56);
            cout<<"��12: ģ����ѯ                  ��"<<endl;
                    cout << setw(56);
            cout<<"��0:  ����                      ��"<<endl;
                    cout << setw(56);
            cout<<"����������������������������������"<<endl;
            cout <<endl<<endl<< "��߹���ŵ���������ѡ��(/�أ�):";
                way = io.get_Int();
                showWelcome("      �鼮��ѯ����       ");
            }
            break;
        case 5:
            cout<<"�뻪����������Ҫ���ҵ��Ǳ���ı��(/�أ�):";
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
            cout<<"�뻪����������Ҫ�黹���Ǳ���ı��(/�أ�):";
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
            cout<<"�뻪����������ҪԤԼ���Ǳ���ı��(/�أ�):";
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
            cout<<"�뻪����������Ҫ������Ǳ���ı��(/�أ�):";
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
            cout<<"���������˶��ٱ�����(/�أ�):";//�����ܹ���ʧ���鱾����
            way = io.get_Int();
            cout<<endl;
            while(way>user.getNumBooksBorrowed())
            {
                cout<<"ƭ���ţ�QAQ�������費����ô�౾���!��ȷ��һ�°ɣ�"<<endl;
               way = io.get_Int();
            }
            for(int i=0; i<way; i++)
            {
                cout<<"�����˵���������ʧ���Ǳ���ı��TnT:";
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
            cout<<"�Ƿ�ѡ������! (/�أ�),�����������~ :";

        }

            //system("cls");

    }


}

