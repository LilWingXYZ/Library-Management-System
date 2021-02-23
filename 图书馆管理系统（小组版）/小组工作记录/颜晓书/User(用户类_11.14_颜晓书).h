#include<string>
using namespace std;
#define MAX_BORROW 10;//一个用户最大借阅书籍数量
#define MAX_RECENT_BORROW 10;//存储最大历史借阅书籍数量
#define MAX_NAME 20;//最大用户姓名字节数
#define MAX_PASSWORD 10;//最大用户密码字节数
#define BORROW_DAY 30;//每个用户最多可借一本书30天，超过30天未归还则超期
#define MAX_DELAY_MONTH 2;//最大延期为2月


typedef struct{
	unsigned int peopleId;//借书人编号
	unsigned int recentBorrowId[10];//最近借阅书籍编号
	unsigned int booksBorrowed[10];//已经借阅的书籍
	char password[10];//password for the user
	int level;//借书人级别
	int credit;//信用点
	char peopleName[20];//people's name
	bool isDeleted;//whether the record is delated(false as default)
	bool isRealDeleted;//is the record real
}people;

class User{

    private:
        people PEOPLE;//用户信息
        用户操作类 UserOperation;
	int numBooksRecent=0;//历史借阅书籍数量
	int numBooksBorrowed=0;//已借书数量
	int maxBooksBorrowed=0;//最高可借书数量
    public:

        //构造函数
        User(people PEOPLE_IN){  

            this.PEOPLE = PEOPLE_in;
            setMaxBooksBorrowed(int credit);//根据用户限制最大借书数量,maxBooksBorrowed=int(credit/10)
		for(int i=0; i<MAX_BORROW;i++){//初始化numBooksBorrowed,numBooksRecent
			if(PEOPLE.booksBorrowed[i]!=0)
                    		numBooksBorrowed++;
                	if(PEOPLE.recentBorrowId[i]!=0)
                    		numBooksRecent++;
			}
        }



        ///以下为设置用户信息

        void setNumBooksRecent(int numBooksRecent); //功能描述：设置用户历史借阅书籍数量;参数：要设置的数量值，int型；返回值：void；调用：操作类用户修改numBooksRecent函数：

        void setNumBooksBorrowed(int numBooksBorrowed); //功能描述：设置用户已借书数量;参数：要设置的数量值，int型；返回值：void；调用：操作类用户修改numBooksBorrowed函数：

        void setMaxBooksBorrowed(int credit); //功能描述：设置用户最高可借书数量;参数：用户信用点，int型；返回值：void；调用:根据用户信用点计算设置最大可借阅书籍数量：

        void setPeopleId(int peopleId); //功能描述：设置用户id;参数：要设置的用户id值，int型；返回值：void；调用：操作类用户修改peopleId函数：

	void setLevel(int level); //功能描述：设置用户级别;参数：要设置的用户level值，int型；返回值：void；调用：操作类用户修改level函数：

	void setCredit(int credit); //功能描述：设置用户信用点;参数：要设置的用户credit值,int型；返回值：void；调用：操作类用户修改credit函数：

	void setPeopleName(string peopleName); //功能描述：设置用户姓名;参数：要设置的用户姓名值，string类型，最大不能超过20字节；返回值：void；调用：操作类用户修改peopleName函数：

	void setPassword(string password); //功能描述：设置用户密码;参数：要设置的用户密码值，string类型，最大不能超过10字节；返回值：void；调用：操作类用户修改密码函数：

	void setRecentBorrowId(int recentBorrowId[]); //功能描述：整体设置用户最近借阅书籍id;参数：要设置的用户recentBorrowId[]，int数组，数组最大值为10；返回值：void；调用：操作类用户修改最近借阅书籍函数：

	void setBooksBorrowed(int booksBorrowed[]); //功能描述：整体设置用户已经借阅书籍id;参数：要设置的用户booksBorrowed[]，int数组，数组最大值为5；返回值：void；调用：操作类用户修改已借阅书籍函数：

        void setRecentBorrowId(int recentBorrowId,int index); //功能描述：部分设置用户最近借阅书籍第index本的id值;参数：要设置的用户recentBorrowId，int型，index值为1-PEOPLE.numBooksRecent；返回值：void；调用：操作类用户修改最近借阅书籍函数：

	void setBooksBorrowed(int booksBorrowedId,int index); //功能描述：部分设置用户已经借阅书籍第index本的id值;参数：要设置的用户booksBorrowedId，int型，index值为1-PEOPLE.numBooksBorrowed；返回值：void；调用：操作类用户修改已借阅书籍函数：

        void AddRecentBorrowId(int recentBorrowId); //功能描述：增加用户最近借阅书籍;参数：要增加的用户recentBorrowId，int型，增加之后numBooksRecent不超过最大值10；返回值：void；调用：操作类用户修改最近借阅书籍函数：

	void AddBooksBorrowed(int booksBorrowedId); //功能描述：增加用户已经借阅书籍;参数：要增加的用户booksBorrowedId，int型，增加之后numBooksBorrowed不超过最大值5；返回值：void；调用：操作类用户修改已借阅书籍函数：

        void DeleteRecentBorrowId(int recentBorrowId); //功能描述：从用户最近借阅书籍删除为recentBorrowId值的记录，设置其id值为0;参数：要删除的recentBorrowId，int型；返回值：void；调用：setRecentBorrowId(recentBorrowId,0)：

	void DeleteBooksBorrowed(int booksBorrowedId); //功能描述：从用户已经借阅书籍删除为booksBorrowedId值的记录，设置其id值为0;参数：要删除的booksBorrowed，int型；返回值：void；调用：setBooksBorrowed(booksBorrowedId,0)

	void setIsDeleted(bool flag); //功能描述：伪删除该用户在文件记录;参数：删除标识flag为true代表删除,false代表恢复在文件记录；返回值：void；调用：操作类用户修改IsDeleted函数：

        void setIsRealDeleted(); //功能描述：真删除该用户在文件记录;参数：空；返回值：void；调用：操作类用户修改IsRealDeleted函数：

        int GetBorrowTime(int bookId); //功能描述：返回该本书截止目前被借阅的时间;参数：bookId，int型；返回值：int，无：

        ///以下为返回用户信息

	int getPeopleId(); //功能描述：返回用户id;参数：空；返回值：int；调用:无：

	int getLevel(); //功能描述：返回用户等级;参数：空；返回值：int；调用:无；

	int getCredit(); //功能描述：返回用户信用点;参数：空；返回值：int；调用:无；

	string getPeopleName(); //功能描述：返回用户姓名;参数：空；返回值：string；调用:无；

	int getRecentBorrowId(int index); //功能描述：返回用户历史借阅书籍第index本的书本id值;参数：int型第index本，index不超过numBooksRecent；返回值：第index本的id值；调用:无：

	int getBooksBorrowed(int index); //功能描述：返回用户目前借阅书籍第index本的书本id值;参数：int型第index本，index不超过numBooksBorrowed；返回值：第index本的id值；调用:无;

	string getPassword(); //功能描述：获得用户密码;参数：空；返回值：string；调用：无：

	int getNumBooksBorrowed(); //功能描述：返回用户已经借阅书籍数量;参数：空；返回值：借阅数量int；调用：无；

	int getMaxBooksBorrowed(); //功能描述：返回用户最大借阅书籍数量，根据用户信用点计算;参数：空；返回值：最大借阅数量int；调用：getCredit();

        bool getIsDeleted(); //功能描述：返回该用户是否被伪删除状态信息;参数：无；返回值：bool类型，true代表删除，false反之；调用：无

        bool getIsRealDeleted(); //功能描述：返回该用户是否被真删除状态信息;参数：无；返回值：bool类型，true代表真删除，false反之；调用：无

	void showUserInfo(); //功能描述:展示用户信息;参数：空；返回值：void；调用：无；
		
	
	
	///以下为根据用户等级可进行具体图书操作功能


        bool login();//功能描述：返回该用户与服务器的连接状态,当用户登陆成功，自动计算credit，若超期一天，-1，若丢失-10；参数：无；返回值：bool类型，true代表在线，false反之；调用：无

        bool logout();//功能描述：返回该用户与服务器的连接状态；参数：无；返回值：bool类型，true代表用户已退出，false反之；调用：无

	bool isBorrowMaxnum()://功能描述：返回该用户是否还有借书能力；参数：numBooksBorrowed，maxBooksBorrowed，都为int型；返回值：bool型，true代表可以借书，false反之；调用：无

	void borrowBooks(int bookId)://功能描述：用户从书库借书；参数：bookId,int型；返回值：bookId，int型；调用：borrowPower()，用户操作类查找函数，AddBooksBorrowed，书的借书标志改为true

	void returnBooks(int bookId)://功能描述：用户还回已借书；参数：booksBorrowed，int型；返回值：bookId，int型；调用：用户操作类查找函数，AddRecentBorrowId，书的借书标志改为false

	void orderBooks(int bookId)://功能描述：用户预约借书；参数：bookId，int型；返回值：bookId，int型；调用：用户操作类查找函数，AddBooksBorrowed，书的预约标志改为true

        void continueBorrow(int bookId,int month);//功能描述：续借；参数：bookId，int型，续借书籍的编号，month，int型，续借月数，最大3个月；返回值：void；调用：用户操作类查找函数，AddBooksBorrowed，书的预约标志改为true

};




