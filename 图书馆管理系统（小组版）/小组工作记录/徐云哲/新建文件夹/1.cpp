#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <conio.h>
using namespace std;
struct student
{
    int id;//���߱��
    string name;//��������
    int borrowsum;//���ѽ��Ķ��ٱ���,Ĭ��Ϊ0
    int number;//���ڻ��ж��ٱ���δ����Ĭ��Ϊ0
    string borrowday;//�ϴν���ʱ�䣬Ĭ��Ϊ0000.00.00
    int b[10];//��������ĵı�ţ����10��
};
struct book
{
    int idnum;//ͼ�������
    int BorrowCount;//ͼ�������,��ʼ��Ϊ0
    string name;//����
    string kind;//ͼ������
    double price;//ͼ��۸�
    int sum;//ͼ���ܿ�����
    int nowsum;//ͼ���ֿ����
    string author;//ͼ������
    int appointment;//ͼ��ԤԼ��,��ʼ��Ϊ0
    bool ok;//�Ƿ�ɽ�,��ʼΪ����
    string borrowdate;//ͼ�����һ�ν��ʱ�䣬Ĭ��Ϊ0000-00-00��
    string returndate;//ͼ�����һ�ι黹ʱ�䣬Ĭ��Ϊ0000-00-00��
    string room;//�ݲص�
};
bool cmpByidnum(book a,book b)
{
    return a.idnum<b.idnum;
}
bool cmpByCount(book a,book b)
{
    return a.BorrowCount>b.BorrowCount;
}
bool cmpByBorrowsum(student a,student b)
{
    return a.borrowsum>b.borrowsum;
}
bool cmpByid(student a,student b)
{
    return a.id<b.id;
}
class Library
{
private:
    int borrownum;//ÿ�½��������
    int returnnum;//ÿ�»�������
    vector<book> data;
    vector<student> data1;
    vector<int> betoli;//ԤԼ�鵽�ݣ���������
public:
    Library();
    void AddBook(book NewBook);  //����ͼ��
    void DeleteBook(string bookname,string author);//ɾ��ͼ��                        /////////////////////////////////////////////////
    void BorrowBook(string name,string author);//����ͼ��
    void BackBook(string name,string author,int k);//�黹ͼ��
    void ShowAllBook(); //���ϵͳ����ͼ��
    void  SearchBookPosWithname(string thebook); //��������ѯ
    void  SearchBookPosWithAuthor(string theauthor);//�����߲�ѯ
    void  SearchBookPosWithKind(string kind);//�������ѯ
    int  SearchBookPosWithAB(string theauthor,string thebook);//�����ߺ�������ѯ
    int  SearchBookPosWithid(int id); //����������Ѱ
    void SortBook(int ca);  //����
    void SortStudent(int ca);//�����߽���������
    void Save();  //����ͼ����ļ�
    void Save1();//����ѧ���ļ�
    void Appointment(string bookname,string author);//ԤԼͼ��
    void printbook(book a);//���ĳ�����������Ϣ
    void revisebook(string name,string author);//�޸�ĳ�������Ϣ
    int SerchStudent(int id);//��ѯĳ������
    //int SerchStudent1(int id);//��ѯĳ������
    void AddStudent(student a);//����һ������                           ///////////////////////////////////////////////////////////
    void PrintStudent(int kid);//���������Ϣ
    int GetStudent();//���ض�������
    int readsum(int id);//��ȡĳ�����ߵĽ�����
    int getborrownum();//��ȡ���������
    int getreturnnum();//��ȡ���»�����
    void PrintToLi();//�������ԤԼ��
};
Library::Library()
{
    borrownum=0;
    returnnum=0;
    int AllBook,AllStudent;
    ifstream fin("book.txt");
    if(fin)
    {
        fin>>AllBook;
        for(int i=0; i<AllBook; i++)
        {
            book tem;
            fin>>tem.idnum>>tem.name>>tem.author>>tem.price>>tem.kind>>tem.room>>tem.sum>>tem.nowsum>>tem.BorrowCount>>tem.ok>>tem.appointment>>tem.borrowdate>>tem.returndate;
            data.push_back(tem);
        }
        fin.close();
    }
    //cin.clear();
    //cin.sync();
    ifstream tfin("student.txt");
    if(tfin)
    {
        tfin>>AllStudent;
        for(int i=0; i<AllStudent; i++)
        {
            student tem;
            tfin>>tem.id>>tem.name>>tem.borrowsum>>tem.number>>tem.borrowday;
            for(int j=0;j<10;j++)
            {
                tfin>>tem.b[j];
            }
            data1.push_back(tem);
        }
        tfin.close();
    }
}
int Library::readsum(int a)
{
    //SortStudent(1);
    return data1[a-1].borrowsum;
}
int Library::getborrownum()//��ȡ���������
{
    return borrownum;
}
int Library::getreturnnum()//��ȡ���»�����
{
    return returnnum;
}
int Library::GetStudent()
{
    int k=(int)data1.size();
    return k+1;
}
void Library::AddBook(book NewBook)
{
    data.push_back(NewBook);
}
void Library::AddStudent(student newstudent)
{
    data1.push_back(newstudent);
}
void Library::DeleteBook(string bookname,string author)
{
    int pos = SearchBookPosWithAB(author,bookname);
    if (pos!=-1)
    {
        data.erase(data.begin()+pos);
        cout<<"ɾ��ͼ��ɹ�!"<<endl;
        return ;
    }
    else
        cout<<"���޴��飡\n";
}
void Library::BorrowBook(string name,string author)
{
    string BorrowDate;
    string BackDate;
    char c;
    int flag=0;
    SortStudent(1);
    int sid=-1;
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].name==name&&data[i].author==author)
        {
            if(data[i].nowsum)
            {
                cout<<"������ߵĶ��ߺ��ǣ�";
                cin>>sid;
                if(data1[sid-1].number>10)
                {
                    cout<<"����ͬʱ����10���飡�����ٽ裡"<<endl;
                    break;
                }
                flag=1;
                data[i].nowsum=data[i].nowsum-1;
                data[i].BorrowCount=data[i].BorrowCount+1;
                cout<<"�������������"<<endl;
                cin>>BorrowDate;
                data[i].borrowdate=BorrowDate;
                cout<<"������Ԥ�ƹ黹����(���ɽ�һ��)"<<endl;
                cin>>BackDate;
                data[i].returndate=BackDate;
                data[i].ok=bool(data[i].nowsum);
                borrownum++;
                data1[sid-1].number++;
                for(int j=0;j<10;j++)
                {
                    if(data1[sid-1].b[j]==0)
                    data1[sid-1].b[j]=data[i].idnum;
                    Save();
                    Save1();
                }
            }
            else
            {
                cout<<"~~~~(>_<)~~~~ !���鱻�����ˣ��Ƿ�ԤԼ��Y/N"<<endl;
                cin>>c;
                c=toupper(c);
                if(c=='Y')
                    data[i].appointment++;
            }
        }
    }
    if(!flag)
        cout<<"��Ǹ��δ�ҵ���Ҫ�ҵ��顣"<<endl;
}
void Library::BackBook(string name,string author,int k)//k��ʾ����;��
{
    int c=-1;
    SortStudent(1);
    if(k!=-1)//������������
    {
        c=k-1;
    }
    else//����ͨ���軹��̨����
    {
        cout<<"��������Ķ��ߺţ�";
        cin>>c;
        c=c-1;
    }
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].name==name&&data[i].author==author)
        {
            data[i].nowsum=data[i].nowsum+1;
            data[i].ok=bool(data[i].nowsum);
            returnnum++;
            if(data[i].appointment!=0)
            {
                data[i].appointment--;
                betoli.push_back(data[i].idnum);
            }
            for(int j=0;j<10;j++)
                {
                    if(data1[c].b[j]==data[i].idnum)
                        data1[c].b[j]=0;
                }
                data1[c].number--;
            break;
        }
    }
    Save();
    Save1();
}
void Library::printbook(book a)
{
    cout<<setw(8)<<a.idnum;
    cout<<setw(14)<<a.name;
    cout<<setw(14)<<a.author;
    cout<<setw(14)<<fixed<<setprecision(2)<<a.price;
    cout<<setw(14)<<a.kind;
    cout<<setw(14)<<a.room;
    cout<<setw(14)<<a.sum;
    cout<<setw(14)<<a.nowsum;
    cout<<setw(14)<<a.BorrowCount;
    cout<<setw(10)<<(a.ok==0?"���ɽ�":"�ɽ�");
    cout<<setw(14)<<a.appointment;
    cout<<setw(14)<<a.borrowdate;
    cout<<setw(14)<<a.returndate<<endl;
    // cout<<endl;
}
void Library::PrintToLi()
{
    SortBook(1);
    int k=(int)betoli.size();
    if(!k) cout<<"     ��ʱ��ԤԼ�鵽�ݣ�"<<endl;
    else
    {
        cout<<"        ���ݵ�ԤԼ���У�\n";
        for(int i=0;i<k;i++)
        {
            printbook(data[betoli[i]-1]);
        }
    }
}
void Library::PrintStudent(int kid)
{
   int id=kid-1;
    //id=SerchStudent(id);
    SortStudent(1);
    SortBook(1);
    //SortStudent(1);
    cout<<setw(8)<<data1[id].id;
    cout<<setw(8)<<data1[id].name;
    cout<<setw(14)<<data1[id].borrowsum;
    cout<<setw(18)<<data1[id].number;
    cout<<setw(14)<<data1[id].borrowday<<endl;
    if(data1[id].number)
    {
        cout<<"�㵱ǰ������Щ�飺\n";
        cout<<setw(16)<<"������"<<setw(16)<<"����"<<setw(16)<<"����"<<endl;
        for(int i=0;i<10;i++)
        {
            if(data1[id].b[i]!=0)
            cout<<setw(16)<<data[data1[id].b[i]-1].idnum<<setw(16)<<data[data1[id].b[i]-1].name<<setw(16)<<data[data1[id].b[i]-1].author<<endl;
        }
    }
    else
        cout<<"�㵱ǰ��δ���κ���,��ȥ�豾�鿴���ɣ�\n";
}
void Library::ShowAllBook()
{
    //system("cls");
    cout<<setw(8)<<"������"<<setw(14)<<"����"<<setw(14)<<"����"<<setw(14)<<"�۸�"<<setw(14)<<"����"<<setw(14)<<"�ݲص�"<<setw(14)<<"�ܿ����"<<setw(14)<<"�ڹ���"<<setw(14)<<"������"<<setw(10)<<"�Ƿ�ɽ�"<<setw(14)<<"ԤԼ��";
    cout<<setw(14)<<"���ʱ��"<<setw(14)<<"�黹ʱ��"<<endl;
    for (int i = 0; i <(int)data.size(); i++)
    {
        //cout<<endl;
        printbook(data[i]);
        //cout<<endl;
        /*cout<<setw(6)<<data[i].idnum;
        cout<<setw(16)<<data[i].name;
        cout<<setw(8)<<data[i].author;
        cout<<setw(6)<<fixed<<setprecision(2)<<data[i].price;
        cout<<setw(6)<<data[i].kind;
        cout<<setw(16)<<date[i].room;
        cout<<setw(6)<<data[i].sum;
        cout<<setw(6)<<data[i].nowsum;
        cout<<setw(6)<<data[i].BorrowCount;
        cout<<setw(6)<<(data[i].borrow==0?"���ɽ�":"�ɽ�");
        cout<<setw(6)<<date[i].appointment;
        cout<<setw(14)<<date[i].borrowdate;
        cout<<setw(14)<<date[i].returndate<<endl;*/
    }
}
int Library::SerchStudent(int id)
{
    int m=-1;
     for (int i = 0; i <(int)data1.size(); i++)
     {
        if (data1[i].id==id)
        {
            return i;
        }
     }
     return m;
 }
void Library::SearchBookPosWithname(string thebook)//��������ѯ
{
    int flag=0;
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].name==thebook)
        {
            printbook(data[i]);
            flag=1;
        }
    }
    if(!flag) cout<<"���޴��飡\n";
}
void Library::SearchBookPosWithAuthor(string theauthor)//�����߲�ѯ
{
    bool flag=false;
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].author==theauthor)
        {
            flag=true;
            printbook(data[i]);
        }
    }
    if(!flag) cout<<"���޴����ߵ��飡";
}
void Library::SearchBookPosWithKind(string kind)//�������ѯ
{
    bool flag=false;
    for (int i = 0; i <(int)data.size(); ++i)
    {
        if (data[i].kind==kind)
        {
            flag=true;
            printbook(data[i]);
        }
    }
    if(!flag) cout<<"���޴����飡";
}
int Library::SearchBookPosWithAB(string theauthor,string thebook)//�����ߺ�������ѯ
{
    for (int i = 0; i <(int)data.size(); ++i)
    {
        if (data[i].author==theauthor&&data[i].name==thebook)
        {
            printbook(data[i]);
            return i;
        }
    }
    cout<<"���޴��飡";
    return -1;
}
int Library::SearchBookPosWithid(int id)
{
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].idnum==id)
        {
            return i;
        }
    }
    return -1;
}
void Library::SortBook(int ca)  //����
{
    if (ca==0)   //������������
    {
        sort(data.begin(),data.end(),cmpByCount);
    }
    else    //������������
    {
        sort(data.begin(),data.end(),cmpByidnum);
    }
}
void Library::SortStudent(int ca)
{
    if(ca==0)//������������
        sort(data1.begin(),data1.end(),cmpByBorrowsum);
    else
        sort(data1.begin(),data1.end(),cmpByid);//�����ߺ�����
}
void Library::Save() //�����鼮�ļ�
{
    ofstream fout("book.txt");
    if (fout)
    {
        fout<<data.size()<<endl;
        //book p;
        for (int i = 0; i <(int)data.size(); i++)
        {
            fout<<data[i].idnum<<" "<<data[i].name<<" "<<data[i].author<<" "<<data[i].price<<" "<<data[i].kind<<" "<<data[i].room<<" "<<data[i].sum<<" "<<data[i].nowsum<<" "<<data[i].BorrowCount<<" "<<data[i].ok<<" "<<data[i].appointment<<" "<<data[i].borrowdate<<" "<<data[i].returndate<<" "<<endl;
        }
        fout.close();
    }
}
void Library::Save1() //����ѧ���ļ�
{
    ofstream fout("student.txt");
    if (fout)
    {
        fout<<data1.size()<<endl;
        //student p;
        for (int i = 0; i <(int)data1.size(); i++)
        {
            fout<<data1[i].id<<" "<<data1[i].name<<" "<<data1[i].borrowsum<<" "<<data1[i].number<<" "<<data1[i].borrowday;
            for(int j=0;j<10;j++)
            {
                fout<<" "<<data1[i].b[j];
            }
            fout<<endl;
        }
        fout.close();
    }
}
void Library::revisebook(string name,string author)//�޸�ͼ��
{
    string Room,Kind;
    int num,k=0;
    printf("��Ҫ�޸ĵ������ǣ�\n");
    printf("                 1.�ݲص��޸�\n");
    printf("                 2.ͼ���ܿ�����޸�\n");
    printf("                 3.ͼ�����������޸�\n");
    printf("                 4.�˳�\n");
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].author==author&&data[i].name==name)
        {
            k=i;
            break;
        }
    }
    int cho;
    do
    {
        cin>>cho;
        switch(cho)
        {
        case 1:
        {
            cout<<"�������µĹݲصأ�\n";
            cin>>Room;
            data[k].room=Room;
            break;
        }
        case 2:
        {
            cout<<"�������µ��ܿ������\n";
            cin>>num;
            data[k].sum=num;
            break;
        }
        case 3:
        {
            cout<<"������ͼ�����������ࣺ\n";
            cin>>Kind;
            data[k].kind=Kind;
            break;
        }
        }
    }
    while(cho<4);
}
void Library::Appointment(string bookname,string author)//ԤԼͼ��
{
    for (int i = 0; i <(int)data.size(); i++)
    {
        if (data[i].author==author&&data[i].name==bookname)
        {
            if(data[i].nowsum>0) printf("�������飬������ԤԼ��\n");
            else
            {
                data[i].appointment++;
                printf("ԤԼ�ɹ���");
            }
        }
    }
}
int main()
{
    cout.setf(ios::left);//�����
    Library mybook;
    char mm[6];//��������
   // mybook.PrintStudent(0);
    cout<<"                                                   ��ӭʹ��ͼ�����ϵͳ"<<endl;
    cout<<"��ѡ����ĵ�¼ѡ�\n";
    cout<<"                  1.����Ա��¼"<<endl;
    cout<<"                  2.���ߵ�¼"<<endl;
    int cho,start,kk=1;
    cin>>start;
    switch(start)
    {
        case 1:
       {
        char password[]="192021";
       // string passwdInput;
        cout<<"���������Ա����:";
        do{
            kk=1;
           for(int i=0;i<6;i++)
           {
            mm[i]=getch();
            cout<<"*";
           }
           cout<<endl;
           for(int i=0;i<6;i++)
           {
           if (mm[i]!=password[i])
           {
            cout<<"��������ȷ���룡"<<endl;
            kk=0;
            break;
           }
           }
        }while(!kk);
        do
        {
           // cout<<"                                  ��ӭʹ��ͼ�����ϵͳ"<<endl;
            cin.clear();
            cin.sync();
            //system("cls");
            cout<<"              1.����ͼ��Ŀ¼ "<<endl;
            cout<<"              2.��ѯͼ�� "<<endl;
            cout<<"              3.����ͼ�� "<<endl;
            cout<<"              4.ɾ��ͼ�� "<<endl;
            cout<<"              5.����ͼ�� "<<endl;
            cout<<"              6.�黹ͼ�� "<<endl;
            cout<<"              7.�޸�ͼ����Ϣ "<<endl;
            cout<<"              8.���½軹ͳ�� "<<endl;
            cout<<"              9.ԤԼ�鵽����� "<<endl;
            cout<<"              10.�˳� "<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"              ��ѡ����,����ָ�� "<<endl;
            cin>>cho;
            switch(cho)
            {
            case 1:
            {
                int cho2;
                do
                {
                    mybook.ShowAllBook();
                    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"0:������������ , 1:������������ ,3:�˳�"<<endl;
                    cin>>cho2;
                    switch(cho2)
                    {
                    case 0:
                        mybook.SortBook(0);
                        break;
                    case 1:
                        mybook.SortBook(1);
                        break;
                    }
                }
                while (cho2<2);
                break;
            }
            case 2:
            {
                cout<<"              1.��������ѯ "<<endl;
                cout<<"              2.�����߲�ѯ "<<endl;
                cout<<"              3.�������ѯ "<<endl;
                cout<<"              4.�����������߲�ѯ "<<endl;
                cout<<"              5.�˳� "<<endl;
                cout<<"              ��ѡ����,����ָ�� "<<endl;
                int cho3;
                do
                {
                    string Name,AutHor,Kind;
                    cin>>cho3;
                    switch(cho3)
                    {
                    case 1:
                        cout<<"������������"<<endl;
                        cin>>Name;
                        mybook.SearchBookPosWithname(Name); //��������ѯ
                        break;
                    case 2:
                        cout<<"���������ߣ�"<<endl;
                        cin>>AutHor;
                        mybook.SearchBookPosWithAuthor(AutHor);//�����߲�ѯ
                        break;
                    case 3:
                        cout<<"���������࣡"<<endl;
                        cin>>Kind;
                        mybook.SearchBookPosWithKind(Kind);//�������ѯ
                        break;
                    case 4:
                        cout<<"���������ߺ�������"<<endl;
                        cin>>AutHor>>Name;
                        mybook.SearchBookPosWithAB(AutHor,Name);//�����ߺ�������ѯ
                        break;
                    }
                }
                while(cho3<=4&&cho3>=1);
                break;
            }
            case 3:         //����ͼ��
            {
                book temp;
                cout<<"�����������:";
                cin>>temp.idnum;
                while (mybook.SearchBookPosWithid(temp.idnum)>-1)
                {
                    cout<<"�������ظ�����~~~~(>_<)~~~~ !"<<endl;
                    cin>>temp.idnum;
                }
                cin.clear();
                cin.sync();
                cout<<"����:";
                cin>>temp.name;
                cout<<"���ߣ�";
                cin>>temp.author;
                cout<<"�۸�:";
                cin>>temp.price;
                cout<<"����:";
                cin>>temp.kind;
                cout<<"�ݲص�ַ:";
                cin>>temp.room;
                cout<<"����:";
                cin>>temp.sum;
                temp.nowsum=temp.sum;
                temp.BorrowCount=0;
                temp.ok=true;
                temp.appointment=0;
                temp.borrowdate="0000.00.00";
                temp.returndate="0000.00.00";
                mybook.AddBook(temp);
                mybook.Save();
                cout<<"��Ϣ����ɹ�"<<endl;
                break;
            }
            case 4:         //ɾ��ͼ��
            {
                string bookname,bookauthor;
                cout<<"����������������:"<<endl;
                cin>>bookname>>bookauthor;
                mybook.DeleteBook(bookname,bookauthor);
                break;
            }
            case 5:         //����
            {
                string bookname,bookauthor;
                cout<<"������Ҫ������������ߣ�"<<endl;
                cin>>bookname>>bookauthor;
                mybook.BorrowBook(bookname,bookauthor);
                mybook.Save();
                break;
            }
            case 6:         //����
            {
                string bookname,bookauthor;
                cout<<"������Ҫ�������������ߣ�"<<endl;
                cin>>bookname>>bookauthor;
                mybook.BackBook(bookname,bookauthor,-1);
                mybook.Save();
                break;
            }
            case 7:
            {
                string name,author;
                cout<<"������Ҫ�޸ĵ����������ߣ�"<<endl;
                cin>>name>>author;
                mybook.revisebook(name,author);
                break;
            }
            case 8:
            {
                  printf("                     ���½���%d��\n",mybook.getborrownum());
                  printf("                     ���»���%d��\n",mybook.getreturnnum());
                  break;
            }
            case 9:
            {
                 mybook.PrintToLi();
                 cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
                 break;
            }
            }
        }
        while (cho<10);
        break;
       // mybook.Save();
    }
    case 2:
    {
        int bh,cho,k;
        cout<<"��������Ķ��߱�ţ�\n";
        cin>>bh;
        if(mybook.SerchStudent(bh)==-1)
        {
            int n;
            cout<<"�㲻�Ǵ�ϵͳ���ߣ��Ƿ�ע�᣿\n";
            cout<<"                    1.ע��\n";
            cout<<"                    2.��������\n";
            cin>>n;
            student temp;
            if(n==1)
            {
                cout<<"�������������:";
                cin>>temp.name;
                cin.clear();
                cin.sync();
                temp.id=mybook.GetStudent();
                temp.borrowsum=0;
                temp.number=0;
                temp.borrowday="0000.00.00";
                for(int i=0;i<10;i++)
                {
                    temp.b[i]=0;
                }
                mybook.AddStudent(temp);
                mybook.Save1();
                //cout<<"��Ϣ����ɹ�"<<endl;
                cout<<"                ע��ɹ������ס��Ķ��ߺţ�����������ϵ����Ա!\n";
                cout<<"                ����:"<<temp.name<<endl;
                cout<<"                ���ߺţ�"<<temp.id<<endl;
                k=temp.id;
            }
            else
                break;
        }
        else
        {
            k=bh;
        }
        do
        {
            //cout<<"                                  ��ӭʹ��ͼ�����ϵͳ"<<endl;
            cin.clear();
            cin.sync();
            //system("cls");
            cout<<"              1.����ͼ��Ŀ¼ "<<endl;
            cout<<"              2.��ѯͼ�� "<<endl;
            cout<<"              3.�黹ͼ�� "<<endl;
            cout<<"              4.ԤԼͼ��"<<endl;
            cout<<"              5.�鿴�ҵĽ�����Ϣ "<<endl;
          //  cout<<"
            cout<<"              6.�˳� "<<endl;
            cout<<"              ��ѡ����,����ָ�� "<<endl;
            cin>>cho;
            switch(cho)
            {
            case 1:
            {
                int cho2;
                do
                {
                    mybook.ShowAllBook();
                    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"0:������������ , 1:������������ ,3:�˳�"<<endl;
                    cin>>cho2;
                    switch(cho2)
                    {
                    case 0:
                        mybook.SortBook(0);
                        break;
                    case 1:
                        mybook.SortBook(1);
                        break;
                    }
                }
                while (cho2<2);
                break;
            }
            case 2:
            {
                cout<<"              1.��������ѯ "<<endl;
                cout<<"              2.�����߲�ѯ "<<endl;
                cout<<"              3.�������ѯ "<<endl;
                cout<<"              4.�����������߲�ѯ "<<endl;
                cout<<"              5.�˳� "<<endl;
                cout<<"              ��ѡ����,����ָ�� "<<endl;
                int cho3;
                do
                {
                    string Name,AutHor,Kind;
                    cin>>cho3;
                    switch(cho3)
                    {
                    case 1:
                        cout<<"������������"<<endl;
                        cin>>Name;
                        mybook.SearchBookPosWithname(Name); //��������ѯ
                        break;
                    case 2:
                        cout<<"���������ߣ�"<<endl;
                        cin>>AutHor;
                        mybook.SearchBookPosWithAuthor(AutHor);//�����߲�ѯ
                        break;
                    case 3:
                        cout<<"���������࣡"<<endl;
                        cin>>Kind;
                        mybook.SearchBookPosWithKind(Kind);//�������ѯ
                        break;
                    case 4:
                        cout<<"���������ߺ�������"<<endl;
                        cin>>AutHor>>Name;
                        mybook.SearchBookPosWithAB(AutHor,Name);//�����ߺ�������ѯ
                        break;
                    }
                }
                while(cho3<=4&&cho3>=1);
                break;
            }
            case 3:         //����
            {
                string bookname,bookauthor;
                cout<<"������Ҫ�������������ߣ�"<<endl;
                cin>>bookname>>bookauthor;
                mybook.BackBook(bookname,bookauthor,k);
                break;
            }
            case 4://ԤԼͼ��
            {
                  string bookname,author;
                  cout<<"��������ҪԤԼ�������������:"<<endl;
                  cin>>bookname>>author;
                  mybook.Appointment(bookname,author);//ԤԼͼ��
                  break;
            }
            case 5://���ĸ�����Ϣ
            {
                //mybook.SortStudent(1);
                cout<<setw(8)<<"���ߺ�"<<setw(8)<<"����"<<setw(14)<<"��ʷ���Ĵ���"<<setw(18)<<"���ڽ��������"<<setw(14)<<"�ϴλ���ʱ��"<<endl;
                mybook.PrintStudent(k);
                mybook.SortStudent(0);
                printf("�������ж����н����������� %d λ\n",mybook.SerchStudent(k)+1);
                printf("���ж����е���߽������ǣ�%d��\n",mybook.readsum(1));
                mybook.SortStudent(1);
                cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            }
        }
        while (cho<6);
        break;
    }
   }
   mybook.Save();
   mybook.Save1();
   return 0;
}
