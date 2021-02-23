//---------------��������------------------------------

void searchAllBooks();//������չʾ�����鼮
void searchBookById(unsigned int bookId);//����Ų�ѯ�鼮��Ϣ
void searchBookByPeopleId(unsigned int peopleId);//����������Ų�ѯ�鼮��Ϣ
void searchBookByClass(int bookClass);//���鼮����ѯ�鼮��Ϣ
void searchBookByPrice(float price1,float price2);//���۸� �����ѯ�鼮��Ϣ
void searchBookByName(char name[20]);//�����ֲ�ѯ�鼮��Ϣ
void searchBookByPublisher(char publisher[20]);//���������ѯ�鼮��Ϣ
void searchBookByAuthor(char author[8]);//�����߲�ѯ�鼮��Ϣ
void searchBookByPublishDate(char publishDate[8]);//���������ڲ�ѯ�鼮��Ϣ
void searchBookByBorrowTime(char borrowTime[10]);//��������ڲ�ѯ�鼮��Ϣ
int  searchInstanceOfBook(unsigned int bookId);//��ѯ���������ĳ�������ļ����distance

void searchAllPeople();//������չʾ�����û���Ϣ
void searchPeopleById(unsigned int peopleId);//ͨ���û��Ų�ѯ�û���Ϣ
void searchPeopleByRecentBorrowId(unsigned int recentBorrowId[10]);//��ʱ������
void searchPeopleByRank(int rank);//ͨ���û��ȼ���ѯ�û���Ϣ
void searchPeopleByCredit(int credit);//ͨ�����õȼ���ѯ�û���Ϣ
int  searchInstanceOfPeople(unsigned int peopleId);//��ѯ�û���������ĳ�û����ļ����distance


//-----------------book�Ĳ�ѯ����----------------------------
void searchAllBooks(){//������չʾ�����鼮
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){
                showInfo(ret[i]);//չʾ��ǰ�鼮����
                distance++;//��¼����������Ŀ
            }

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ! from searchAllBooks." << endl;
    }
    }
}
void searchBookById(unsigned int bookId){//����Ų�ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(bookId == ret[i].bookId){
                    cout << "We got it the imformation of ID :" << bookId << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    return;
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    cout << "Can't find this ID~" << endl;
}

void searchBookByPeopleId(unsigned int peopleId){//����������Ų�ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(peopleId == ret[i].peopleId){
                    cout << "We got it the imformation of peopleId :" << peopleId << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of this peopleId ��" << peopleId << endl;
}
void searchBookByClass(int bookClass){//���鼮����ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������
    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(bookClass == ret[i].bookClass){
                    cout << "We got it the imformation of bookClass :" << bookClass << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of this bookClass ��" <<bookClass << endl;
}
void searchBookByPrice(float price1,float price2){//���۸������ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(ret[i].price <= price2 && ret[i].price >= price1){
                    cout << "We got it the imformation of price :" <<  price1 << " ~ " << price2 << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the price :" <<  price1<<" ~ " << price2 << endl;
}
void searchBookByName(char name[20]){//�����ֲ�ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(strcmp(name,ret[i].bookName)==0){
                    cout << "We got it the imformation of bookName :" <<  name << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the bookName :" <<  name << endl;
}
void searchBookByPublisher(char publisher[20]){//���������ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(strcmp(publisher,ret[i].publisher)==0){
                    cout << "We got it the imformation of publisher :" <<  publisher << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the publisher :" <<  publisher << endl;
}

void searchBookByAuthor(char author[8]){//�����߲�ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(strcmp(author,ret[i].author)==0){
                    cout << "We got it the imformation of author :" <<  author << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
        cout << "Can't find the record of the author :" <<  author << endl;
}
void searchBookByPublishDate(char publishDate[8]){//���������ڲ�ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
        int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(strcmp(publishDate,ret[i].publishDate)==0){
                    cout << "We got it the imformation of publishDate :" <<  publishDate << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
    cout << "Can't find the record of the publishDate :" <<  publishDate << endl;
}
void searchBookByBorrowTime(char borrowTime[10]){//��������ڲ�ѯ�鼮��Ϣ
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    int result = 0;//���ڼ�¼�Ƿ��ҵ�����һ�������

    while(distance < ((bm.currentFileSize(fname)/(sizeof(book)))-1)){//������û����ʱ;(bm.currentFileSize(fname)/(sizeof(book)))Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(strcmp(borrowTime,ret[i].borrowTime)==0){
                    cout << "We got it the imformation of borrowTime :" <<  borrowTime << endl;
                    showInfo(ret[i]);//�������ݣ������ҳ��Ǳ�������ݲ�
                    result++;//��¼�ҵ��ĸ���
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
    }
    }
    if(result == 0)
        cout << "Can't find the record of the borrowTime :" <<  borrowTime << endl;
}

int searchInstanceOfBook(unsigned int bookId){
    BookClassIO bm ;//����һ���鼮������Ķ���bm = bookmanage����˼;
    book ret[10];//ret��return�����ڽ��շ�������ʮ��book���͵��鼮����
    string fname = "TestBookData.dat";//�����ļ���
    int distance = 0;//��ʼ����ʼ���ҵ�λ��Ϊ0.
    int mode = 2;//mode = 2,�ļ�ָ��ָ���ͷ��ʼ֮��ĵ�distance*sizeof(book)�ֽڵ�λ��
    while(distance < (bm.currentFileSize(fname)-1)){//������û����ʱ,bm.currentFileSize(fname)Ϊ��ǰ�ļ���ʵ�����
    int state = bm.readFile(ret,fname,distance,mode);//int readFile(book returnInfo[10],string fname,int distance,int mode)//���ļ�
    if(state == 0){//state��¼���ص��ļ��������0Ϊ�ɹ���
            for(int i = 0; i < 10; i++){//ʮ��ʮ�����������Ƿ�ƥ��
                if(bookId == ret[i].bookId){
                    cout << "We got the distance of " << bookId <<endl <<"Its distance is : " <<distance<< endl;
                    return distance;//�ҵ����̷�������distance
                }
                distance++;//�Ҳ���������һ��
            }
            //ǰ��ʮ���Ҳ����Ļ���������ѭ����ʮ��

    }else{//���û�ɹ����ļ�
        cout << "Read file error!QAQ!" << endl;
        return -1;//-1����û�ѵ�����ļ�
    }
    }
    return -1;//-1����û�ѵ�����ļ�
}
//-----------------book�Ĳ�ѯ����----------------------------



//-----------------people�Ĳ�ѯ����----------------------------
//�Ѿ�д�ã���û�ж�Ӧ����������ݣ�û���Թ�����ʱ���ų���

//-----------------people�Ĳ�ѯ����----------------------------
