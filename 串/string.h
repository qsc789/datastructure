#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAXSIZE 1000    //�ַ������С
//����
typedef struct {
    char data[MAXSIZE];    //ÿ���ַ��洢
    int length;        //����ʵ�ʳ���
}String;
//�䳤
typedef struct {
    char* ch;    //ָ��̬����洢���׵�ַ���ַ�ָ��
    int length;    //����
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