#ifndef LOGUTIL_H_INCLUDED
#define LOGUTIL_H_INCLUDED
#include<iostream>
#include<cstring>
#include<cmath>
#include"BookManagementIOHeader.h"
int stLog(std::string info){
    std::ofstream outFile;
    std::string statusLog = "log.txt";
    outFile.open(statusLog,ios::app);
    if(!outFile) return -1;
    outFile.write(info);
    return 0;
}
#endif // LOGUTIL_H_INCLUDED
