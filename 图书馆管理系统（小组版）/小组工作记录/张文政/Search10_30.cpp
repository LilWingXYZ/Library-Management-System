//---------------函数声明------------------------------

void searchAllBooks();//无条件展示所有书籍
void searchBookById(unsigned int bookId);//按书号查询书籍信息
void searchBookByPeopleId(unsigned int peopleId);//按借书人序号查询书籍信息
void searchBookByClass(int bookClass);//按书籍类别查询书籍信息
void searchBookByPrice(float price1,float price2);//按价格 区间查询书籍信息
void searchBookByName(char name[20]);//按名字查询书籍信息
void searchBookByPublisher(char publisher[20]);//按出版社查询书籍信息
void searchBookByAuthor(char author[8]);//按作者查询书籍信息
void searchBookByPublishDate(char publishDate[8]);//按出版日期查询书籍信息
void searchBookByBorrowTime(char borrowTime[10]);//按借出日期查询书籍信息
int  searchInstanceOfBook(unsigned int bookId);//查询书号来返回某本书在文件里的distance

void searchAllPeople();//无条件展示所有用户信息
void searchPeopleById(unsigned int peopleId);//通过用户号查询用户信息
void searchPeopleByRecentBorrowId(unsigned int recentBorrowId[10]);//暂时不考虑
void searchPeopleByRank(int rank);//通过用户等级查询用户信息
void searchPeopleByCredit(int credit);//通过信用等级查询用户信息
int  searchInstanceOfPeople(unsigned int peopleId);//查询用户号来返回某用户在文件里的distance


//-----------------book的查询函数----------------------------
void searchAllBooks(){//无条件展示所有书籍
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){
                showInfo(ret[i]);//展示当前书籍数据
                distance++;//记录查过的书的数目
            }

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ! from searchAllBooks." << endl;
    }
    }
}
void searchBookById(unsigned int bookId){//按书号查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(bookId == ret[i].bookId){
                    cout << "We got it the imformation of ID :" << bookId << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    return;
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    cout << "Can't find this ID~" << endl;
}

void searchBookByPeopleId(unsigned int peopleId){//按借书人序号查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int result = 0;//用于记录是否找到至少一个结果。
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(peopleId == ret[i].peopleId){
                    cout << "We got it the imformation of peopleId :" << peopleId << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of this peopleId ：" << peopleId << endl;
}
void searchBookByClass(int bookClass){//按书籍类别查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int result = 0;//用于记录是否找到至少一个结果。
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(bookClass == ret[i].bookClass){
                    cout << "We got it the imformation of bookClass :" << bookClass << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of this bookClass ：" <<bookClass << endl;
}
void searchBookByPrice(float price1,float price2){//按价格区间查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int result = 0;//用于记录是否找到至少一个结果。

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(ret[i].price <= price2 && ret[i].price >= price1){
                    cout << "We got it the imformation of price :" <<  price1 << " ~ " << price2 << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the price :" <<  price1<<" ~ " << price2 << endl;
}
void searchBookByName(char name[20]){//按名字查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int result = 0;//用于记录是否找到至少一个结果。

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(strcmp(name,ret[i].bookName)==0){
                    cout << "We got it the imformation of bookName :" <<  name << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the bookName :" <<  name << endl;
}
void searchBookByPublisher(char publisher[20]){//按出版社查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(strcmp(publisher,ret[i].publisher)==0){
                    cout << "We got it the imformation of publisher :" <<  publisher << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the publisher :" <<  publisher << endl;
}

void searchBookByAuthor(char author[8]){//按作者查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(strcmp(author,ret[i].author)==0){
                    cout << "We got it the imformation of author :" <<  author << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
        cout << "Can't find the record of the author :" <<  author << endl;
}
void searchBookByPublishDate(char publishDate[8]){//按出版日期查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
        int result = 0;//用于记录是否找到至少一个结果。

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(strcmp(publishDate,ret[i].publishDate)==0){
                    cout << "We got it the imformation of publishDate :" <<  publishDate << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the publishDate :" <<  publishDate << endl;
}
void searchBookByBorrowTime(char borrowTime[10]){//按借出日期查询书籍信息
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    int result = 0;//用于记录是否找到至少一个结果。

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//当数据没找完时;(bm.currentFileSize(fname)/(sizeof(book)))为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(strcmp(borrowTime,ret[i].borrowTime)==0){
                    cout << "We got it the imformation of borrowTime :" <<  borrowTime << endl;
                    showInfo(ret[i]);//测试数据，看能找出那本书的数据不
                    result++;//记录找到的个数
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
        cout << "Can't find the record of the borrowTime :" <<  borrowTime << endl;
}

int searchInstanceOfBook(unsigned int bookId){
    BookClassIO bm ;//定义一个书籍管理类的对象bm = bookmanage的意思;
    book ret[10];//ret是return，用于接收返回来的十个book类型的书籍数据
    string fname = "TestBookData.dat";//数据文件名
    int distance = 0;//初始化开始查找的位置为0.
    int mode = 2;//mode = 2,文件指针指向从头开始之后的第distance*sizeof(book)字节的位置
    while(distance < (bm.currentFileSize(fname)-1)){//当数据没找完时,bm.currentFileSize(fname)为当前文件里实体个数
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//读文件
    if(state == 0){//state记录返回的文件打开情况，0为成功打开
            for(int i = 0; i < 10; i++){//十个十个地拿与检测是否匹配
                if(bookId == ret[i].bookId){
                    cout << "We got the distance of " << bookId <<endl <<"Its distance is : " <<distance<< endl;
                    return distance;//找到立刻返回他的distance
                }
                distance++;//找不到则找下一个
            }
            //前面十个找不到的话，再重新循环读十个

    }else{//如果没成功打开文件
        cout << "Read file error!QAQ!" << endl;
        return -1;//-1代表没搜到这个文件
    }
    }
    return -1;//-1代表没搜到这个文件
}
//-----------------book的查询函数----------------------------



//-----------------people的查询函数----------------------------
//已经写好，但没有对应管理类和数据，没测试过，暂时不放出来

//-----------------people的查询函数----------------------------
