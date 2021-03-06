#include<iostream>
#include<fstream>
#include<io.h>
#include<cmath>
#include "BookManagementIOHeader.h"
using namespace std;
/*
class BookClassIO{//this class is used for reading or writing datas of books.
	private:

	public:
        int writeFile(book writeMessage,std::string fname,int distance,int mode){//in current access
                std::string filename = findDotDat(fname);//find whether this name has ".dot", if it isn't, add an ".dot" at the end
                ofstream fileout;
                fileout.open(filename.data(),ios::binary|ios::out|ios::in);//start to write file at the end of the file
                if(!fileout){//if the file doesn't exist, return this status
                        fileout.close();
                        return -2;
                }//if it exists, start to write
                switch(mode){
                case 1:
                        fileout.seekp(0,ios::beg);
                        break;
                case 2:
                        fileout.seekp(abs(distance)*(off_t)sizeof(book),ios::beg);
                        break;
                case 3:
                        fileout.seekp(distance*(off_t)sizeof(book),ios::cur);//no judgement, only used in the middle
                        break;
                case 4:
                        fileout.seekp(-abs(distance)*(off_t)sizeof(book),ios::end);
                        break;
                case 5://adding mode
                        fileout.close();
                        fileout.open(filename.data(),ios::binary|ios::app);
                        break;
                default:
                        return -5;
                }
                fileout.write((char *) &writeMessage,sizeof(book));// write the message
                fileout.close();
                return 0;
        }
	int readFile(book returnInfo[10],std::string fname,int distance,int mode){//in current access
                std::string filename = findDotDat(fname);
                ifstream filein;
                int ret = 0;
                filein.open(filename.data(),ios::binary|ios::in);
                if(!filein){//if the file doesn't exist, return this status
                        filein.close();
                        return -2;
                }//if it exists, start to read
                switch(mode){
                case 1:
                        filein.seekg(0,ios::beg);//read from the begining
                        break;
                case 2:
                        filein.seekg(abs(distance)*(off_t)sizeof(book),ios::beg);
                        break;
                case 3:
                        filein.seekg(distance*(off_t)sizeof(book),ios::cur);
                        break;
                case 4:
                        filein.seekg((-abs(distance))*(off_t)sizeof(book),ios::end);
                        break;
                default:
                        return -5;
                }
                int counter = 0;
                while (counter < 10 && filein.read((char *) &returnInfo[counter], sizeof(book))) counter ++;
                if(counter<10){//if the file is finished before the array is full, fill the empty one
                        while(counter<10){
                                fillEmpty(returnInfo[counter]);
                                counter++;
                        }
                        ret = -4;// tell the file is finished
                }
                filein.close();
                return ret;
	}
	int currentFileSize(std::string fname){//get length of the file
                int length = 0;
                std::string filename = findDotDat(fname);
                ifstream lengthTest(filename.data(),ios::binary);
                lengthTest.seekg(0,ios::end);
                length = lengthTest.tellg();
                lengthTest.seekg(0,ios::beg);//reset pointer
                return length;
	}
        int createFile(std::string fname){
                if(findFileExisting(fname)) return -6;// if there is such a file, return -6
                std::string filename = findDotDat(fname);//else start to create file
                ofstream createFile;
                createFile.open(filename.data(),ios::app|ios::binary);
                if(!createFile){//failed to create file, return 5
                        createFile.close();
                        return 5;
                }
                createFile.close();
                return 0;
        }
        int turncateFile(std::string fname){
                std::string filename = findDotDat(fname);// prevent the name has no postfix
                int rec = remove(filename.data());
                if(rec == -1) return 4;
                return 0;
        }
};
class ReaderClassIO{//this class is used for tansfering data from database for readers
	private:
	public:
        int writeFile(people writeMessage,std::string fname,int distance,int mode){//in current access
                std::string filename = findDotDat(fname);//find whether this name has ".dot", if it isn't, add an ".dot" at the end
                ofstream fileout;
                fileout.open(filename.data(),ios::binary|ios::out|ios::in);//start to write file at the end of the file
                if(!fileout){//if the file doesn't exist, return this status
                        fileout.close();
                        return -2;
                }//if it exists, start to write
                switch(mode){
                case 1:
                        fileout.seekp(0,ios::beg);
                        break;
                case 2:
                        fileout.seekp(abs(distance)*(off_t)sizeof(people),ios::beg);
                        break;
                case 3:
                        fileout.seekp(distance*(off_t)sizeof(people),ios::cur);//no judgement, only used in the middle
                        break;
                case 4:
                        fileout.seekp(-abs(distance)*(off_t)sizeof(people),ios::end);
                        break;
                case 5://adding mode
                        fileout.close();
                        fileout.open(filename.data(),ios::binary|ios::app);
                        break;
                default:
                        return -5;
                }
                fileout.write((char *) &writeMessage,sizeof(people));// write the message
                fileout.close();
                return 0;
        }

	int readFile(people returnInfo[10],std::string fname,int distance,int mode){//in current access
                std::string filename = findDotDat(fname);
                ifstream filein;
                int ret = 0;
                filein.open(filename.data(),ios::binary|ios::in);
                if(!filein){//if the file doesn't exist, return this status
                        filein.close();
                        return -2;
                }//if it exists, start to read
                switch(mode){
                case 1:
                        filein.seekg(0,ios::beg);//read from the begining
                        break;
                case 2:
                        filein.seekg(abs(distance)*(off_t)sizeof(people),ios::beg);
                        break;
                case 3:
                        filein.seekg(distance*(off_t)sizeof(people),ios::cur);
                        break;
                case 4:
                        filein.seekg((-abs(distance))*(off_t)sizeof(people),ios::end);
                        break;
                default:
                        return -5;
                }
                int counter = 0;
                while (counter < 10 && filein.read((char *) &returnInfo[counter], sizeof(people))) counter ++;
                if(counter<10){//if the file is finished before the array is full, fill the empty one
                        while(counter<10){
                                fillEmpty(returnInfo[counter]);
                                counter++;
                        }
                        ret = -4;// tell the file is finished
                }
                filein.close();
                return ret;
	}
	int currentFileSize(std::string fname){//get length of the file
                int length = 0;
                std::string filename = findDotDat(fname);
                ifstream lengthTest(filename.data(),ios::binary);
                lengthTest.seekg(0,ios::end);
                length = lengthTest.tellg();
                lengthTest.seekg(0,ios::beg);//reset pointer
                return length;
	}
        int createFile(std::string fname){
                if(findFileExisting(fname)) return -6;// if there is such a file, return -6
                std::string filename = findDotDat(fname);//else start to create file
                ofstream createFile;
                createFile.open(filename.data(),ios::app|ios::binary);
                if(!createFile){//failed to create file, return 5
                        createFile.close();
                        return 5;
                }
                createFile.close();
                return 0;
        }
        int turncateFile(std::string fname){
                std::string filename = findDotDat(fname);// prevent the name has no postfix
                int rec = remove(filename.data());
                if(rec == -1) return 4;
                return 0;
        }
};

*/
