#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    system("cls");
        cout<<endl<<"��������Ҫɾ�������ĳ��ƺ�:";
         char Num[20];
          for(int i=0;i<20;i++)
            Num[i]=0;              //��ʼ����ֵ
         cin>>Num;               //����һ���ַ��������ļ��е�ÿһ�εĵ�һ���ַ������бȽ�

        ifstream reFile("��������ϵͳ.txt");
        if(!reFile)
        {
            cerr<<"Error!Can not open the File!"<<endl;
            exit(1);
        }

        bool Delet=false;

        ofstream temFile2("TempFile2.txt");
        temFile2.close();


        while(reFile>>CarNum>>Pinpai>>Price>>Buytime>>Driver>>yidong>>Baofei)
        {
            if(strcmp(CarNum,Num)==0)
            {
                  cout<<"����ɾ���ĳ���������Ϣ���£�"<<endl<<endl;
                  cout<<"���ƺţ�  "<<CarNum<<endl<<"����Ʒ�ƣ�"<<Pinpai<<endl<<"�����۸�"<<Price<<endl<<"����ʱ�䣺"
                   <<Buytime<<endl<<"��ʻԱ��  "<<Driver<<endl<<"�Ƿ��춯��"<<yidong<<endl<<"�Ƿ񱨷ϣ�"<<Baofei<<endl;

              ofstream temFile1("TempFile1.txt");
              if(!temFile1)
              {
                  cerr<<"Error!Can not open the File!"<<endl;
                  exit(1);
              }

              temFile1<<CarNum<<"\n"<<Pinpai<<"\n"<<Price<<"\n"<<Buytime<<"\n"<<Driver<<"\n"<<Baofei<<"\n"<<yidong<<endl;
              temFile1.close();

              Delet=true;

            }

          else
          {
                temFile2.open("TempFile2.txt",ios::app);
                if(!temFile2)
                {
                    cerr<<"Error!Can not open the File!"<<endl;
                    exit(1);
                }
                temFile2<<CarNum<<"\n"<<Pinpai<<"\n"<<Price<<"\n"<<Buytime<<"\n"<<Driver<<"\n"<<Baofei<<"\n"<<yidong<<endl;
                temFile2.close();
          }
        }
        if(false==Delet) cout<<"Sorry!û������Ҫɾ���ĳ����ĵ�����Ϣ������ϸ�˶�!O(��_��)Oлл!"<<endl;


        reFile.close();

        system( "del   ��������ϵͳ.txt ");       //ɾ��ԭʼ�ļ�
        system( "rename   TempFile2.txt,   ��������ϵͳ.txt ");     //�޸��ļ���

        cout<<"�ó���������Ϣ�Ѿ�ɾ��!"<<endl;
        system("pause");
}
