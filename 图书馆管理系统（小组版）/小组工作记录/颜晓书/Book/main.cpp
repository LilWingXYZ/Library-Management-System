
#include<iostream>
#include<fstream>
#include<cstring>
#define maxBytes_1 20//书名,作者,出版社,已经借阅的书籍最大字节数
#define maxBytes_2 9//出版年份最大字节数
#define maxBytes_3 10//borrowTime,peopleName,password最大字节数
#define maxBytes_4 40//最近借阅书籍编号最大字节数
#include "BookManageMentIOHeader.h"
using namespace std;




//查询在文件中book的distance
int  searchInstanceOfbook(unsigned int bookId){
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int maxBooksNum = 9999;//这里假定统计过后文件里的数据量目前一共有9999个，用maxBooksNum来记录
    while(distance < (maxBooksNum-1)){//当数据没找完时
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(bookId == ret[i].bookId){
                    cout << "We got it!=3=" << endl;
                    bm.showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    return distance;//找到立刻返回他的distance
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
        return 0;
    }
    }
    return 0;
}


//修改书籍编号(bookId)

bool updateBookId(string filename,book *Book,int BookId){

        //distance查找失败信息
		int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
		if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->bookId = BookId;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}

//修改借书人编号(peopleId)

bool updateBookPeopleId(string filename,book *Book,int PeopleId){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
		if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->peopleId = PeopleId;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值



}

//修改书籍分类(bookClass)

bool updateBookClass(string filename,book *Book,int BookClass){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->bookClass = BookClass;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值


}

//修改书籍价格(price)


bool updateBookPrice(string filename,book *Book,float Price){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->price = Price;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}

//修改书籍名称(name)

bool updateBookName(string filename,book *Book,char *Name){

	if(sizeof(Name)<= maxBytes_1){

		int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		strcpy(Book->bookName,Name);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败

}



//修改书籍出版社(publisher)

bool updateBookPublisher(string filename,book *Book,char *Publisher){
    if(sizeof(Publisher)<= maxBytes_1){

		int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
		if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		strcpy(Book->publisher,Publisher);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败

}

//修改书籍作者(author)

bool updateBookAuthor(string filename,book *Book,char *Author){

    if(sizeof(Author)<= maxBytes_1){

		int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
		if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		strcpy(Book->author,Author);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败


}

//修改书籍出版年份(publishDate)

bool updateBookPublishDate(string filename,book *Book,char *PublishDate){

    if(sizeof(PublishDate)<= maxBytes_2){

		int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
		if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		strcpy(Book->publishDate,PublishDate);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败


}

//修改书籍借出时间(borrowTime)

bool updateBookBorrowTime(string filename,book *Book,char *BorrowTime){

     if(sizeof(BorrowTime)<= maxBytes_3){

		int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
		if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		strcpy(Book->borrowTime,BorrowTime);
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败


}

//修改借出标志位(borrowFlag)

bool updateBookBorrowFlag(string filename,book *Book,bool BorrowFlag){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->borrowFlag = BorrowFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}

//修改预定标志位（isReservedFlag）

bool updateBookReservedFlag(string filename,book *Book,bool ReservedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->isReservedFlag = ReservedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}


//修改保存本标志位(isPreservedFlag)

bool updateBookPreservedFlag(string filename,book *Book,bool PreservedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->isPreservedFlag = PreservedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值
}

//修改逾期标志位(isLated)

bool updateBookLatedFlag(string filename,book *Book,bool LatedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->isLated = LatedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值
}

//修改删除标志位(isDeleted)

bool updateBookDeletedFlag(string filename,book *Book,bool DeletedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->isDeleted = DeletedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}

//修改真删除标志位（isRealDeleted）

bool updateBookRealDeletedFlag(string filename,book *Book,bool RealDeletedFlag){

        int distance = searchInstanceOfbook(Book->bookId);//根据查询函数定位Book在文件中的位置
        if(distance == 0){
            cout<<"修改失败!"<<endl;
            return false;
		}
		Book->isRealDeleted = RealDeletedFlag;
		BookClassIO bm;
		bm.writeFile(*Book,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<Book->bookId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}


/*-----------连续多次修改---------------------------------------------------------

 void updateBook(char *filename,book *Book,int index ){

       //filena书本信息所在文件，Book要修改的书本记录指针
       //index修改书本信息的类别：1,bookId 2,peopleId 3,bookClass 4,price 5,name  6,publisher 7,author 8,publishDate 9,borrowTime 10,borrowFlag 11,isReservedFlag 12,isPreservedFlag 13,isLated 14,isDeleted;
       //返回类型为布尔值，ture代表修改成功，false代表修改失败

       //通过switch_case自定义修改,以及index可调用上述单次修改函数

}*/

//以上为book修改
//-----------------------------------------------------------------------------------
//以下为people修改

/*修改借书人信息的方式分为两类：(与上述类似)

-----------单次单个属性修改---------------------------------------------------------
总体框架：
bool updatePeople_(char *filename,people *People,"要更新的信息" ){

	//filename书本信息所在文件，Book要修改的书本记录指针,第三个参数为传入的更新的信息
	//返回值为bool类型，true为修改成功，false修改失败

	if(sizeof("要更新的信息")<= maxBytes){

		int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		Book->对应更新之前信息 = "要更新的信息";

		writeFile(*People,filename,distance,1);//调用BookClassIO类的writeFile函数，更新信息
		return true;//返回修改值


	}


	return false;//否则修改失败

}*/
/*
//修改借书人编号(peopleId)
bool updatePeopleId(char *filename,people *People,int PeopleId){

		int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		People->peopleId = PeopleId;
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}

//修改最近借阅书籍编号(recentBorrowId)

bool updatePeopleRecentBorrowId(char *filename,people *People,int *RecentBorrowId){

    if(sizeof(RecentBorrowId)<= maxBytes_4){

		int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		Book->recentBorrowId = RecentBorrowId;
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败

}

//修改已经借阅的书籍编号(peoplesBorrowed)

bool updatePeoplePeoplesBorrowed(char *filename,people *People,int *PeoplesBorrowed){

    if(sizeof(PeoplesBorrowed)<= maxBytes_1){

		int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		Book->peoplesBorrowed = PeoplesBorrowed;
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败

}

//修改用户密码(password)

bool updatePeoplePassword(char *filename,people *People,int *Password){

    if(sizeof(Password)<= maxBytes_3){

		int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		Book->password = Password;
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败

}

//修改借书人级别(level)

bool updatePeopleLevel(char *filename,people *People,int Level){

    	int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		People->level = Level;
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}

//修改借书人信用点(credit)

bool updatePeopleCredit(char *filename,people *People,int Credit){

        int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		People->credit = Credit;
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}

//修改借书人姓名(peopleName)

bool updatePeopleName(char *filename,people *People,char *PeopleName){

      if(sizeof(Password)<= maxBytes_3){

		int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		strcpy(People->peopleName,PeopleName);
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

	}

	return false;//否则修改失败

}

//修改该用户删除标志位(isDeleted)

bool updatePeopleDeleted(char *filename,people *People,bool IsDeleted){

        int distance = searchInstanceOfPeople(People->peopleId);//根据查询函数定位Book在文件中的位置
		People->isDeleted = IsDeleted;
		writeFile(*People,filename,distance,2);//调用BookClassIO类的writeFile函数，更新信息
		cout<<"编号"<<People->peopleId<<"的信息修改成功"<<endl;
		return true;//返回修改值

}
*/

/*-----------连续多次修改---------------------------------------------------------

 void updatePeople(char *filename,book *People,int index ){

       //filena书本信息所在文件，People要修改的借书人记录指针
       //index修改用户信息的类别：1，peopleId  2，recentBorrowId  3，booksBorrowed  4， password  5,level  6，credit 7，peopleName 8，isDeleted;
       //返回类型为布尔值，ture代表修改成功，false代表修改失败

       //通过switch_case自定义修改,以及index可调用上述单次修改函数

}*/




int main()
{
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book bookArray[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int state = bm.readFile(bookArray,fname,0,2);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    cout<<"STATE:"<<state<<endl;
         for(int i=0;i<10;i++){

          cout<<"编号NO."<<bookArray[i].bookId<<endl;
          cout<<"借书人编号:"<<bookArray[i].peopleId<<endl;
          cout<<"分类："<<bookArray[i].bookClass<<endl;
          cout<<"价格："<<bookArray[i].price<<endl;
          cout<<"书名："<<bookArray[i].bookName<<endl;
          cout<<"出版社："<<bookArray[i].publisher<<endl;
          cout<<"作者："<<bookArray[i].author<<endl;
          cout<<"出版日期："<<bookArray[i].publishDate<<endl;
          cout<<"借出时间："<<bookArray[i].borrowTime<<endl;
          cout<<"借出："<<bookArray[i].borrowFlag<<endl;
          cout<<"预定："<<bookArray[i].isReservedFlag<<endl;
          cout<<"保存本："<<bookArray[i].isPreservedFlag<<endl;
          cout<<"逾期："<<bookArray[i].isDeleted<<endl;
          cout<<"删除："<<bookArray[i].isDeleted<<endl;
          cout<<"----------------------------------------"<<endl;
   }

   //以下为修改测试内容

   cout<<"修改第一本书的分类，书名，借出标志位"<<endl;
   cout<<"输入修改书的分类："<<endl;
   int BookClass;
   cin>>BookClass;
   updateBookClass(fname,&bookArray[1],BookClass);

   cout<<"输入修改的书名："<<endl;
   char BookName[20];
   cin>>BookName;
   updateBookName(fname,&bookArray[1],BookName);

   cout<<"输入修改的借出标志位："<<endl;
   int BorrowFlag;
   cin>>BorrowFlag;
   updateBookClass(fname,&bookArray[1],BorrowFlag);

   cout<<endl;
   cout<<"第一本书修改后的信息:"<<endl;
   cout<<endl;


          cout<<"编号NO."<<bookArray[1].bookId<<endl;
          cout<<"借书人编号:"<<bookArray[1].peopleId<<endl;
          cout<<"分类："<<bookArray[1].bookClass<<endl;
          cout<<"价格："<<bookArray[1].price<<endl;
          cout<<"书名："<<bookArray[1].bookName<<endl;
          cout<<"出版社："<<bookArray[1].publisher<<endl;
          cout<<"作者："<<bookArray[1].author<<endl;
          cout<<"出版日期："<<bookArray[1].publishDate<<endl;
          cout<<"借出时间："<<bookArray[1].borrowTime<<endl;
          cout<<"借出："<<bookArray[1].borrowFlag<<endl;
          cout<<"预定："<<bookArray[1].isReservedFlag<<endl;
          cout<<"保存本："<<bookArray[1].isPreservedFlag<<endl;
          cout<<"逾期："<<bookArray[1].isDeleted<<endl;
          cout<<"删除："<<bookArray[1].isDeleted<<endl;
   return 0;
}


  /* void updateBook(char *filename,book *Book,char Name[] ){
       //filena书本信息所在文件，Book要修改的书本记录指针
       //index修改书本信息的类倀,1,bookId 2,peopleId 3,bookClass 4,price 5,name  6,publisher
	   //7,author 8,publishDate 9,borrowTime 10,borrowFlag 11,isReservedFlag 12,isPreservedFlag 13,isLated 14,isDeleted;
       //返回类型为布尔值，ture代表修改成功，false代表修改失败
    int distance = 查询函数(Book); //通过查询函数定位该book为距离文件开头字节数

    int index;//选择修改的信息
    cout<<"需要修改的信息:"<<endl;
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

   outfile.seekp(sizeof(*Book),ios::beg);  //定位于第个学生数据的开头
   outfile.write((char*)Book,sizeof(*Book));
   outfile.close( );


    }*/



