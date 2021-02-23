#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    system("cls");
        cout<<endl<<"请输入您要删除车辆的车牌号:";
         char Num[20];
          for(int i=0;i<20;i++)
            Num[i]=0;              //初始化数值
         cin>>Num;               //输入一个字符串，与文件中的每一段的第一个字符串进行比较

        ifstream reFile("车辆管理系统.txt");
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
                  cout<<"您想删除的车辆档案信息如下："<<endl<<endl;
                  cout<<"车牌号：  "<<CarNum<<endl<<"车辆品牌："<<Pinpai<<endl<<"车辆价格："<<Price<<endl<<"购买时间："
                   <<Buytime<<endl<<"驾驶员：  "<<Driver<<endl<<"是否异动："<<yidong<<endl<<"是否报废："<<Baofei<<endl;

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
        if(false==Delet) cout<<"Sorry!没有您所要删除的车辆的档案信息，请仔细核对!O(∩_∩)O谢谢!"<<endl;


        reFile.close();

        system( "del   车辆管理系统.txt ");       //删除原始文件
        system( "rename   TempFile2.txt,   车辆管理系统.txt ");     //修改文件名

        cout<<"该车辆档案信息已经删除!"<<endl;
        system("pause");
}
