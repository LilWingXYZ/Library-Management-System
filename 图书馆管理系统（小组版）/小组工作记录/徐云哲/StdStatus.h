#ifndef STDSTATUS_H_INCLUDED
#define STDSTATUS_H_INCLUDED

/*------------------AddOption.h------------*/

//addSingleBook(string fname) ����������,����ֵΪwriteFile�ķ���ֵ

#define FILE_DOESNT_EXIST -2
#define MODE_ILLEGAL -5

//addSinglePeople(string fname)//�������鿨�İ���,����ֵΪwriteFile�ķ���ֵ

#define FILE_DOESNT_EXIST -2
#define MODE_ILLEGAL -5

//fillBookBlank(string fname)//���� BookData �еĿ�ȱλ��,����ֵΪwriteFile�ķ���ֵ

#define FILE_DOESNT_EXIST -2
#define MODE_ILLEGAL -5


/*--------------SearchOption.h------------*/

//searchInstanceOfBook(unsigned int bookId,string fname)

#define FAILED_TO_OPEN_FILE -2
#define FAILED_TO_FIND_RECORD -1

//searchInstanceOfPeople(unsigned int peopleId)//��ѯ�û���������ĳ�û����ļ����distance

#define FAILED_TO_FIND_FILE -1


/*--------------BookManagementIO.h------------*/

//writeFile(book writeMessage,string fname,int distance,int mode)

#define FILE_DOESNT_EXIST -2
#define MODE_ILLEGAL -5

//readFile(book returnInfo[10],string fname,int distance,int mode)

#define FILE_DOESNT_EXIST -2
#define MODE_ILLEGAL -5
#define FILE_IS_FINISHED -4

//createFile(string fname)

#define FILE_ALREADY_EXIST -6
#define FAILED_TO_CREATE_FILE 5

//turncateFile(string fname)

#define FAILED_TO_DELETE_FILE 4


/*--------------BookManagementIOHeader.h------------*/

//findOccupy(std::string fname){// find out whether a file is occupied

#define FILE_IS_OCCUPIED 6

//findPath(std::string str)

#define FAILED_TO_FIND_FILE -1

/*--------------------------------------------------*/
#define CANNOTGETHOST -7
#define NOACCESSSERVER -8
#define TIMEOUT -9
#define
#endif // STDSTATUS_H_INCLUDED











