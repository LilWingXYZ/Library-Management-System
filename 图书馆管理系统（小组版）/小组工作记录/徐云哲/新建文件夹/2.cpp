#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>//����/����ļ�����
using namespace std;
const int Maxr=100;//���Ķ���
const int Maxb=100;//����ͼ��
const int Maxbor=5;//ÿλ���������屾��
//������,ʵ�ֶԶ��ߵ���Ϣ������
class Reader
{
    private:
	int tag;  //ɾ����� 1:��ɾ 0:δɾ                       /////////////////////////////////////////////////
	int no;   //���߱��
	char name[10];  //��������
	int borbook[Maxbor];//����ͼ��
    public:
		Reader() {}
    	char *getname() {return name;}      //��ȡ����
		int gettag() {return tag;}         //��ȡɾ�����                              ///////////////////////////////////
	    int getno() {return no;}           //��ȡ���߱��
    	void setname(char na[])            //��������
		{
		   strcpy(name,na);
		}
	void delbook(){  tag=1;  }//����ɾ����� 1:��ɾ 0:δɾ                             ///////////////////////////////
	void addreader(int n,char *na)//���Ӷ���
	{
		tag=0;
		no=n;
		strcpy(name,na);
		for(int i=0;i<Maxbor;i++)
			borbook[i]=0;
	}
	void borrowbook(int bookid)//�������
	{
		for(int i=0;i<Maxbor;i++)
		{
			if (borbook[i]==0)
			{
				borbook[i]=bookid;
				return;
			}
		}
	}
	int retbook(int bookid)//�������
	{
		for(int i=0;i<Maxbor;i++)
		{
			if(borbook[i]==bookid)
			{
			borbook[i]=0;
			return 1;
			}
		}
		return 0;
	}
	void disp()//����������Ϣ
	{
		cout << setw(5) << no <<setw(10) << name<<"�����ţ�[";
		for(int i=0;i<Maxbor;i++)
			if(borbook[i]!=0)
				cout << borbook[i] << "|";
		cout << "]"<<endl;
	}
};
//������⣬ʵ�ֽ������ߵĸ�������
 class RDatabase
{
private:
   int top;       //���߼�¼ָ��
   Reader read[Maxr];//���߼�¼
public:
	RDatabase()   //���캯������reader.txt����read[]��
	{
		Reader s;
		top=-1;
		fstream file("reader.txt",ios::in);//��һ�������ļ�
		while (1)
		{
			file.read((char *)&s,sizeof(s));
			if (!file)break;
			top++;
			read[top]=s;
		}
		file.close();     //�ر� reader.txt
	}
    void clear()//ɾ�����ж�����Ϣ                                      ////////////////////////////////////
	{
		top=-1;
	}
	int addreader(int n,char *na)//��Ӷ���ʱ�Ȳ����Ƿ����
	{
		Reader *p=query(n);
		if (p==NULL)
		{
		  top++;
		  read[top].addreader(n,na);
		  return 1;
		}
		return 0;
    }
	Reader *query(int readerid)//����Ų���
	{
		for (int i=0;i<=top;i++)
			if (read[i].getno()==readerid &&
			read[i].gettag()==0)
			{
				return &read[i];
			}
			return NULL;
	}
	void disp()  //������ж�����Ϣ
	{
           for (int i=0;i<=top;i++)
			   read[i].disp();
	}
	void readerdata();//���߿�ά��
	~RDatabase()  //������������read[]д��reader.txt�ļ���
	{
		fstream file("reader.txt",ios::out);
        for (int i=0;i<=top;i++)
			if (read[i].gettag()==0)
				file.write((char *)&read[i],sizeof(read[i]));
			file.close();
     }
};
void RDatabase::readerdata()
{

    char choice;
	char rname[20];
	int readerid;
	Reader *r;
	while (choice!='0')
	{
        cout <<"\n\n\t\t\t��   ��   ά   ��\n\n\n\t\t 1   ��      ��\n\n\t\t 2   ��      ��\n\n\t\t 3   ɾ      ��\n\n\t\t 4   ��      ��\n\n\t\t 5   ��      ʾ\n\n\t\t 6   ȫ      ɾ\n\n\t\t 0   ��      ��"<<endl;
		cin >> choice;
		switch (choice)
		{
            case '1':
				cout << "������߱��:";
				cin >> readerid;
				cout << "�����������:";
				cin >> rname;
				addreader (readerid,rname);
				break;
            case '2':
				cout << "������߱��:";
				cin >> readerid;
				r=query(readerid);
				if (r==NULL)
				{
					cout << " �ö��߲�����  "<<endl;
				    break;
				}
				cout << "�����µ�����:";
				cin >> rname;
				r->setname(rname);
			 	break;
            case '3':                                                          /////////////////////////////////
				   	cout << " ������߱��:";
                    cin >> readerid;
					r=query(readerid);
					if (r==NULL)
					{
					    cout <<" �ö��߲�����" << endl;
					    break;
					}
					r->delbook();
					break;
			case '4':
				cout << "������߱��:";
				cin >> readerid;
				r=query(readerid);
				if (r==NULL)
				{
					cout <<"�ö��߲�����"<< endl;
					break;
				}
				r->disp();
				break;
			case '5':
				disp();
				break;
			case '6':                                                                ///////////////////////////////
				clear();
				break;
			default:cout<<"���������������룺";break;
		}
	}
}
//ͼ���࣬ʵ�ֶ�ͼ���������ͼ��ı�ţ�����������������
class Book
{
private:
    int tag;//ɾ����� 1:��ɾ 0:δɾ                                  /////////////////////////////////////////
	int no;//ͼ����
	char name[20];//����
	int onshelf;//�Ƿ��ټ� 1:�ټ� 2:�ѽ�
public:
	Book(){}
	char *getname() { return name; }//��ȡ����
	int getno(){ return no; }//��ȡͼ����
	int gettag(){ return tag; }//��ȡɾ�����                     ////////////////////////////////////////
	void setname(char na[])//��������
	{
		strcpy(name,na);
	}
	void delbook(){ tag=1;}//ɾ��ͼ��                             /////////////////////////////////////
	void addbook(int n,char *na)//����ͼ��
	{
		tag=0;
		no=n;
		strcpy(name,na);
		onshelf=1;
	}
	int borrowbook()//�������
	{
		if (onshelf==1)
		{
			onshelf=0;
			return 1;
		}
		return 0;
	}
	void retbook()//�������
	{
		onshelf=1;
	}
	void disp()//���ͼ��
	{
		cout << setw(6) << no << setw(18) << name << setw(10)
			<<(onshelf==1? "�ڼ�":"�ѽ�") <<endl;
	}
};






//ͼ����࣬ʵ�ֶ�ͼ���ά�������ң�ɾ����
class BDatabase
{
private:
    int top;         //ͼ���¼ָ��
	Book book[Maxb]; //ͼ���¼
public:
	BDatabase()//���캯������book.txt����book[]��
	{
			Book b;
			top=-1;
			fstream file("book.txt",ios::in);
			while (1)
			{
				file.read((char *)&b,sizeof(b));
				if (!file) break;
				top++;
				book[top]=b;
			}
			file.close();
	}
    void clear()//ȫɾ                    /////////////////////////////////////////
	{
		top=-1;
	}
    int addbook(int n,char *na)//����ͼ��
	{
		Book *p=query(n);
		if (NULL==p)
		{
			top++;
			book[top].addbook(n,na);
			return 1;
		}
		return 0;
	}
	Book *query(int bookid)//����ͼ��
	{
		for (int i=0;i<=top;i++)
			if (book[i].getno()==bookid &&book[i].gettag()==0)
			{
				return &book[i];
			}
			return NULL;
	}
	void bookdata();//ͼ���ά��
	void disp()
	{
	  for (int i=0;i<=top;i++)
		  if (book[i].gettag()==0)
			  book[i].disp();
	}
	~BDatabase()//������������book[]д��book.txt�ļ���
	{
		fstream file("book.txt",ios::out);
        for (int i=0;i<=top;i++)
			if (book[i].gettag()==0)
				file.write((char *)&book[i],sizeof(book[i]));
			file.close();
	}
};
void BDatabase::bookdata()
{
    char choice;
	char bname[40];
	int bookid;
	Book *b;
	while (choice!='0')
	{
		cout <<"\n\n\n\t\t\tͼ  ��  ά  �� "<<endl<<endl;
		cout<<"\t\t1   ��     ��\n \t\t2   ��     ��\n\t\t3   ɾ     ��\n\t\t4   ��     ��\n\t\t5   ��     ʾ\n\t\t6   ȫ     ɾ\n\t\t0   ��     ��"<<endl;
		cin >> choice;
		switch (choice)
		{
            case '1':
				cout << "����ͼ����:"<<endl;
				cin >> bookid;
                cout << "����ͼ������:"<<endl;
				cin >> bname;
				addbook(bookid,bname);
				break;
            case '2':
				cout << "����ͼ����:"<<endl;
				cin >> bookid;
				b=query(bookid);
				if (b==NULL)
				{
					cout << " ��ͼ�鲻����  "<<endl;
				    break;
				}
				cout << "�����µ�����:"<<endl;
				cin >> bname;
				b->setname(bname);
			 	break;
            case '3':
				   	cout <<" ����ͼ����:"<<endl;
                    cin >> bookid;
					b=query(bookid);
					if (b==NULL)
					{
					    cout <<" ��ͼ�鲻����" << endl;
					    break;
					}
					b->delbook();
					break;
			case '4':
				cout << "  ����ͼ����:"<<endl;
				cin >> bookid;
				b=query(bookid);
				if (b==NULL)
				{
					cout <<"  ��ͼ�鲻����"<< endl;
					break;
				}
				b->disp();
				break;
			case '5':
				disp();
				break;
			case '6':
				clear();
				break;
			default:cout<<"����������������:";
		}
	}
}
//main() ������ʵ�֣�����������������
int main()
{
	char choice;
	int bookid,readerid;
	RDatabase ReaderDB;
	Reader *r;
	BDatabase BookDB;
	Book *b;
	while(choice!='0')
	{
			cout <<endl<<endl<<"\t\t\t     ͼ  ��  ��  ��  ϵ  ͳ\n\n\n";


			cout <<"\t\t\t1    ��       ��\n\n\t\t\t2    ��       �� \n\n\t\t\t3    ͼ �� ά ��\n\n\t\t\t4    �� �� ά ��\n\n\t\t\t0    ��       ��"<<endl;
			cin >> choice;
			switch (choice)
			{
			case '1':
				cout <<"  ���� ���߱��:";
				cin >>readerid;
				cout <<"  ͼ���ţ� ";
				cin >>bookid;
				r=ReaderDB.query(readerid);//����Ų���
				if (NULL==r)
				{
					cout <<"  �����ڸö��ߣ����ܽ���"<< endl;
					break;
				}
				b=BookDB.query(bookid);
				if (b==NULL)
				{
					cout <<"  �����ڸ�ͼ�飬���ܽ���"<< endl;
					break;
				}
				if (b->borrowbook()==0)
				{
					cout << "  ��ͼ���ѽ�������ܽ���"<< endl;
					break;
				}
				r->borrowbook(b->getno());
				break;
			case '2':
				cout<<"����\n ���߱��:";
				cin >>readerid;
				cout << "   ͼ����:";
				cin >>bookid;
				r=ReaderDB.query(readerid);
				if (r==NULL)
				{
					cout <<" �����ڸö��ߣ����ܻ���" << endl;
					break;
				}
				b=BookDB.query(bookid);
				if (b==NULL)
				{
					cout <<"  �����ڸ�ͼ�飬���ܻ���" <<endl;
					break;
				}
				b->retbook();
				r->retbook(b->getno());
				break;
			case '3':
					BookDB.bookdata();
					break;
			case '4':
				    ReaderDB.readerdata();
				    break;
			default:cout<<"���������������룺";
               }
	}
}
