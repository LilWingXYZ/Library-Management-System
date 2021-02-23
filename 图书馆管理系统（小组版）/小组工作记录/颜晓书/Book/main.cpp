
#include<iostream>
#include<fstream>
#include<cstring>
#define maxBytes_1 20//����,����,������,�Ѿ����ĵ��鼮����ֽ���
#define maxBytes_2 9//�����������ֽ���
#define maxBytes_3 10//borrowTime,peopleName,password����ֽ���
#define maxBytes_4 40//��������鼮�������ֽ���
#include "BookManageMentIOHeader.h"
using namespace std;




//��ѯ���ļ���book��distance
int  searchInstanceOfbook(unsigned int bookId){
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    int maxBooksNum = 9999;//����ٶ�ͳ�ƹ����ļ����������Ŀǰһ����9999������maxBooksNum����¼
    while(distance < (maxBooksNum-1)){//������û����ʱ
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(bookId == ret[i].bookId){
                    cout << "We got it!=3=" << endl;
                    bm.showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    return distance;//�ҵ����̷�������distance
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
        return 0;
    }
    }
    return 0;
}


//�޸��鼮���(bookId)

bool updateBookId(string filename,book *Book,int BookId){

        //distance����ʧ����Ϣ
		int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
		if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->bookId = BookId;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}

//�޸Ľ����˱��(peopleId)

bool updateBookPeopleId(string filename,book *Book,int PeopleId){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
		if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->peopleId = PeopleId;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ



}

//�޸��鼮����(bookClass)

bool updateBookClass(string filename,book *Book,int BookClass){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->bookClass = BookClass;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ


}

//�޸��鼮�۸�(price)


bool updateBookPrice(string filename,book *Book,float Price){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->price = Price;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}

//�޸��鼮����(name)

bool updateBookName(string filename,book *Book,char *Name){

	if(sizeof(Name)<= maxBytes_1){

		int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		strcpy(Book->bookName,Name);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��

}



//�޸��鼮������(publisher)

bool updateBookPublisher(string filename,book *Book,char *Publisher){
    if(sizeof(Publisher)<= maxBytes_1){

		int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
		if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		strcpy(Book->publisher,Publisher);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��

}

//�޸��鼮����(author)

bool updateBookAuthor(string filename,book *Book,char *Author){

    if(sizeof(Author)<= maxBytes_1){

		int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
		if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		strcpy(Book->author,Author);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��


}

//�޸��鼮�������(publishDate)

bool updateBookPublishDate(string filename,book *Book,char *PublishDate){

    if(sizeof(PublishDate)<= maxBytes_2){

		int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
		if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		strcpy(Book->publishDate,PublishDate);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��


}

//�޸��鼮���ʱ��(borrowTime)

bool updateBookBorrowTime(string filename,book *Book,char *BorrowTime){

     if(sizeof(BorrowTime)<= maxBytes_3){

		int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
		if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		strcpy(Book->borrowTime,BorrowTime);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��


}

//�޸Ľ����־λ(borrowFlag)

bool updateBookBorrowFlag(string filename,book *Book,bool BorrowFlag){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->borrowFlag = BorrowFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}

//�޸�Ԥ����־λ��isReservedFlag��

bool updateBookReservedFlag(string filename,book *Book,bool ReservedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->isReservedFlag = ReservedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}


//�޸ı��汾��־λ(isPreservedFlag)

bool updateBookPreservedFlag(string filename,book *Book,bool PreservedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->isPreservedFlag = PreservedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ
}

//�޸����ڱ�־λ(isLated)

bool updateBookLatedFlag(string filename,book *Book,bool LatedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->isLated = LatedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ
}

//�޸�ɾ����־λ(isDeleted)

bool updateBookDeletedFlag(string filename,book *Book,bool DeletedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->isDeleted = DeletedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}

//�޸���ɾ����־λ��isRealDeleted��

bool updateBookRealDeletedFlag(string filename,book *Book,bool RealDeletedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//���ݲ�ѯ������λBook���ļ��е�λ��
        if(distance == 0){
            cout<<"�޸�ʧ��!"<<endl;
            return false;
		}
		Book->isRealDeleted = RealDeletedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<Book->bookId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}


/*-----------��������޸�---------------------------------------------------------

 void updateBook(char *filename,book *Book,int index ){

       //filena�鱾��Ϣ�����ļ���BookҪ�޸ĵ��鱾��¼ָ��
       //index�޸��鱾��Ϣ�����1,bookId 2,peopleId 3,bookClass 4,price 5,name  6,publisher 7,author 8,publishDate 9,borrowTime 10,borrowFlag 11,isReservedFlag 12,isPreservedFlag 13,isLated 14,isDeleted;
       //��������Ϊ����ֵ��ture�����޸ĳɹ���false�����޸�ʧ��

       //ͨ��switch_case�Զ����޸�,�Լ�index�ɵ������������޸ĺ���

}*/

//����Ϊbook�޸�
//-----------------------------------------------------------------------------------
//����Ϊpeople�޸�

/*�޸Ľ�������Ϣ�ķ�ʽ��Ϊ���ࣺ(����������)

-----------���ε��������޸�---------------------------------------------------------
�����ܣ�
bool updatePeople_(char *filename,people *People,"Ҫ���µ���Ϣ" ){

	//filename�鱾��Ϣ�����ļ���BookҪ�޸ĵ��鱾��¼ָ��,����������Ϊ����ĸ��µ���Ϣ
	//����ֵΪbool���ͣ�trueΪ�޸ĳɹ���false�޸�ʧ��

	if(sizeof("Ҫ���µ���Ϣ")<= maxBytes){

		int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		Book->��Ӧ����֮ǰ��Ϣ = "Ҫ���µ���Ϣ";

		writeFile(*People,filename,distance,1);//����BookClassIO���writeFile������������Ϣ
		return true;//�����޸�ֵ


	}


	return false;//�����޸�ʧ��

}*/
/*
//�޸Ľ����˱��(peopleId)
bool updatePeopleId(char *filename,people *People,int PeopleId){

		int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		People->peopleId = PeopleId;
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}

//�޸���������鼮���(recentBorrowId)

bool updatePeopleRecentBorrowId(char *filename,people *People,int *RecentBorrowId){

    if(sizeof(RecentBorrowId)<= maxBytes_4){

		int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		Book->recentBorrowId = RecentBorrowId;
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��

}

//�޸��Ѿ����ĵ��鼮���(peoplesBorrowed)

bool updatePeoplePeoplesBorrowed(char *filename,people *People,int *PeoplesBorrowed){

    if(sizeof(PeoplesBorrowed)<= maxBytes_1){

		int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		Book->peoplesBorrowed = PeoplesBorrowed;
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��

}

//�޸��û�����(password)

bool updatePeoplePassword(char *filename,people *People,int *Password){

    if(sizeof(Password)<= maxBytes_3){

		int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		Book->password = Password;
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��

}

//�޸Ľ����˼���(level)

bool updatePeopleLevel(char *filename,people *People,int Level){

    	int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		People->level = Level;
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}

//�޸Ľ��������õ�(credit)

bool updatePeopleCredit(char *filename,people *People,int Credit){

        int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		People->credit = Credit;
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}

//�޸Ľ���������(peopleName)

bool updatePeopleName(char *filename,people *People,char *PeopleName){

      if(sizeof(Password)<= maxBytes_3){

		int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		strcpy(People->peopleName,PeopleName);
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

	}

	return false;//�����޸�ʧ��

}

//�޸ĸ��û�ɾ����־λ(isDeleted)

bool updatePeopleDeleted(char *filename,people *People,bool IsDeleted){

        int distance = searchInstanceOfPeople(People->peopleId);//���ݲ�ѯ������λBook���ļ��е�λ��
		People->isDeleted = IsDeleted;
		writeFile(*People,filename,distance,2);//����BookClassIO���writeFile������������Ϣ
		cout<<"���"<<People->peopleId<<"����Ϣ�޸ĳɹ�"<<endl;
		return true;//�����޸�ֵ

}
*/

/*-----------��������޸�---------------------------------------------------------

 void updatePeople(char *filename,book *People,int index ){

       //filena�鱾��Ϣ�����ļ���PeopleҪ�޸ĵĽ����˼�¼ָ��
       //index�޸��û���Ϣ�����1��peopleId  2��recentBorrowId  3��booksBorrowed  4�� password  5,level  6��credit 7��peopleName 8��isDeleted;
       //��������Ϊ����ֵ��ture�����޸ĳɹ���false�����޸�ʧ��

       //ͨ��switch_case�Զ����޸�,�Լ�index�ɵ������������޸ĺ���

}*/




int main()
{
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book bookArray[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int state = bm.readFile(bookArray,fname,0,2);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    cout<<"STATE:"<<state<<endl;
         for(int i=0;i<10;i++){

          cout<<"���NO."<<bookArray[i].bookId<<endl;
          cout<<"�����˱��:"<<bookArray[i].peopleId<<endl;
          cout<<"���ࣺ"<<bookArray[i].bookClass<<endl;
          cout<<"�۸�"<<bookArray[i].price<<endl;
          cout<<"������"<<bookArray[i].bookName<<endl;
          cout<<"�����磺"<<bookArray[i].publisher<<endl;
          cout<<"���ߣ�"<<bookArray[i].author<<endl;
          cout<<"�������ڣ�"<<bookArray[i].publishDate<<endl;
          cout<<"���ʱ�䣺"<<bookArray[i].borrowTime<<endl;
          cout<<"�����"<<bookArray[i].borrowFlag<<endl;
          cout<<"Ԥ����"<<bookArray[i].isReservedFlag<<endl;
          cout<<"���汾��"<<bookArray[i].isPreservedFlag<<endl;
          cout<<"���ڣ�"<<bookArray[i].isDeleted<<endl;
          cout<<"ɾ����"<<bookArray[i].isDeleted<<endl;
          cout<<"----------------------------------------"<<endl;
   }

   //����Ϊ�޸Ĳ�������

   cout<<"�޸ĵ�һ����ķ��࣬�����������־λ"<<endl;
   cout<<"�����޸���ķ��ࣺ"<<endl;
   int BookClass;
   cin>>BookClass;
   updateBookClass(fname,&bookArray[1],BookClass);

   cout<<"�����޸ĵ�������"<<endl;
   char BookName[20];
   cin>>BookName;
   updateBookName(fname,&bookArray[1],BookName);

   cout<<"�����޸ĵĽ����־λ��"<<endl;
   int BorrowFlag;
   cin>>BorrowFlag;
   updateBookClass(fname,&bookArray[1],BorrowFlag);

   cout<<endl;
   cout<<"��һ�����޸ĺ����Ϣ:"<<endl;
   cout<<endl;


          cout<<"���NO."<<bookArray[1].bookId<<endl;
          cout<<"�����˱��:"<<bookArray[1].peopleId<<endl;
          cout<<"���ࣺ"<<bookArray[1].bookClass<<endl;
          cout<<"�۸�"<<bookArray[1].price<<endl;
          cout<<"������"<<bookArray[1].bookName<<endl;
          cout<<"�����磺"<<bookArray[1].publisher<<endl;
          cout<<"���ߣ�"<<bookArray[1].author<<endl;
          cout<<"�������ڣ�"<<bookArray[1].publishDate<<endl;
          cout<<"���ʱ�䣺"<<bookArray[1].borrowTime<<endl;
          cout<<"�����"<<bookArray[1].borrowFlag<<endl;
          cout<<"Ԥ����"<<bookArray[1].isReservedFlag<<endl;
          cout<<"���汾��"<<bookArray[1].isPreservedFlag<<endl;
          cout<<"���ڣ�"<<bookArray[1].isDeleted<<endl;
          cout<<"ɾ����"<<bookArray[1].isDeleted<<endl;
   return 0;
}


  /* void updateBook(char *filename,book *Book,char Name[] ){
       //filena�鱾��Ϣ�����ļ���BookҪ�޸ĵ��鱾��¼ָ��
       //index�޸��鱾��Ϣ�����t,1,bookId 2,peopleId 3,bookClass 4,price 5,name  6,publisher
	   //7,author 8,publishDate 9,borrowTime 10,borrowFlag 11,isReservedFlag 12,isPreservedFlag 13,isLated 14,isDeleted;
       //��������Ϊ����ֵ��ture�����޸ĳɹ���false�����޸�ʧ��
    int distance = ��ѯ����(Book); //ͨ����ѯ������λ��bookΪ�����ļ���ͷ�ֽ���

    int index;//ѡ���޸ĵ���Ϣ
    cout<<"��Ҫ�޸ĵ���Ϣ:"<<endl;
    cout<<"1,bookId\t2,peopleId\t3,bookClass\t4,price \t5,name\t6,publisher\t"
    <<"7,author\t8,publishDate\t9,borrowTime\t10,borrowFlag\t11,isReservedFlag\t12,isPreservedFlag\t13,isLated\t14,isDeleted"<<endl;
    cin>>index;
    switch(index){
    case 1:
        int BookId;
        cin>>BookId;
        Book->bookId = BookId;
        break;
    case 2:
        int PeopleId;
        cin>>PeopleId;
        Book->peopleId = PeopleId;
    case 3:
        int Price;
        cin>>Price;
        Book->price = Price;
    case 4:
        int BookClass;
        cin>>BookClass;
        Book->bookClass = BookClass;
    case 5:
        char Name[20];
        cin>>Name;
        strcpy(Book->name,Name);

    writeFile(*Book,filename,distance,1);

     strcpy(Book->name,Name);

   strcpy(Book->name,Name);

   ofstream outfile(filename,ios::binary|ios::in|ios::out);
   if(!outfile)
   {
     cerr<<"open error!"<<endl;

   }

   outfile.seekp(sizeof(*Book),ios::beg);  //��λ�ڵڸ�ѧ�����ݵĿ�ͷ
   outfile.write((char*)Book,sizeof(*Book));
   outfile.close( );


    }*/



