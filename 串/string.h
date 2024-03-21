#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAXSIZE 1000    //字符串最长大小
//定长
typedef struct {
    char data[MAXSIZE];    //每个字符存储
    int length;        //串的实际长度
}String;
//变长
typedef struct {
    char* ch;    //指向动态分配存储区首地址的字符指针
    int length;    //长度
}Str;
void InitString(String* S);
bool StrEmpty(String S);
int StrLength(String S);
void ClearString(String* S);
void StrAssign(String* S, String T);
int StrCompare(String S, String T);
void StrConcat(String* T, String S1, String S2);
void SubString(String* Sub, String S, int pos, int len);
void StrInsert(String* S, int pos, String T);
void StrDelete(String* S, int pos, int len);
void StrReplace(String* S, String T, String V);
void GetNext(String T, int next[]);
int KMPMatch(String S, String T);
int Index(String S, String T, int pos);
void StrPrint(String S);