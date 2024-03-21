#include"string.h"


// 初始化串
void InitString(String* S) {
    S->length = 0;
}

// 判断串是否为空
bool StrEmpty(String S) {
    return S.length == 0;
}

// 求串的长度
int StrLength(String S) {
    return S.length;
}

// 清空串
void ClearString(String* S) {
    S->length = 0;
}

// 串赋值
void StrAssign(String* S, String T) {
    for (int i = 0; i < T.length; i++) {
        S->data[i] = T.data[i];
    }
    S->length = T.length;
}

// 串比较
int StrCompare(String S, String T) {
    for (int i = 0; i < S.length && i < T.length; i++) {
        if (S.data[i] != T.data[i]) {
            return S.data[i] - T.data[i];
        }
    }
    return S.length - T.length;
}

// 串连接
void StrConcat(String* T, String S1, String S2) {
    for (int i = 0; i < S1.length; i++) {
        T->data[i] = S1.data[i];
    }
    for (int i = 0; i < S2.length; i++) {
        T->data[S1.length + i] = S2.data[i];
    }
    T->length = S1.length + S2.length;
}

// 串的子串
void SubString(String* Sub, String S, int pos, int len) {
    for (int i = pos - 1; i < pos - 1 + len; i++) {
        Sub->data[i - pos + 1] = S.data[i];
    }
    Sub->length = len;
}

// 串的插入
void StrInsert(String* S, int pos, String T) {
    for (int i = S->length - 1; i >= pos - 1; i--) {
        S->data[i + T.length] = S->data[i];
    }
    for (int i = pos - 1; i < pos - 1 + T.length; i++) {
        S->data[i] = T.data[i - pos + 1];
    }
    S->length = S->length + T.length;
}

// 串的删除
void StrDelete(String* S, int pos, int len) {
    for (int i = pos - 1 + len; i < S->length; i++) {
        S->data[i - len] = S->data[i];
    }
    S->length = S->length - len;
}

// 串的替换
void StrReplace(String* S, String T, String V) {
    int pos = 0;
    while ((pos = Index(*S, T, pos + 1)) != -1) {
        StrDelete(S, pos + 1, T.length);
        StrInsert(S, pos, V);
    }
}

// 串的查找，在串S中从第pos个字符开始查找串T第一次出现的位置，并返回其位置值。
int Index(String S, String T, int pos) {
    int i = pos - 1;
    int j = 0;
    while (i < S.length && j < T.length) {
        if (S.data[i] == T.data[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.length) {
        return i - T.length + 1;
    }
    else {
        return 0;
    }
}
//BF算法，暴力匹配
int BFMatch(String S, String T) {
    int i = 0; // 主串S的当前位置
    int j = 0; // 模式串T的当前位置

    while (i < S.length && j < T.length) {
        if (S.data[i] == T.data[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1; // 主串回退到上一次匹配位置的下一个位置
            j = 0; // 模式串从头开始匹配
        }
    }

    if (j == T.length) {
        return i - T.length; // 返回匹配的位置
    }
    else {
        return -1; // 未找到匹配位置
    }
}
//KMP算法
void GetNextval(const String& T, int nextval[]) {
    int i = 0;  // 模式串中当前位置
    int j = -1; // 最长可匹配前缀子串的结束位置
    nextval[0] = -1; // 第一个位置的next值为-1

    while (i < T.length - 1) {
        if (j == -1 || T.data[i] == T.data[j]) {
            i++;
            j++;
            // 修改的地方：在判断字符相等时，若T[i+1]与T[j+1]也相等，直接回退到nextval[j]的位置
            if (T.data[i] != T.data[j]) {
                nextval[i] = j;
            }
            else {
                nextval[i] = nextval[j];
            }
        }
        else {
            j = nextval[j];
        }
    }
}

void GetNext(String T, int next[]) {
    int i = 0;      
    int j = -1;      
    next[0] = -1;

    while (i < T.length - 1) {
        if (j == -1 || T.data[i] == T.data[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int KMPMatch(String S, String T) {
    int* next = new int[T.length];
    GetNextval(T, next);

    int i = 0; // 主串S的当前位置
    int j = 0; // 模式串T的当前位置

    while (i < S.length && j < T.length) {
        if (j == -1 || S.data[i] == T.data[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];//跳过next[j]个字符继续比较
        }
    }

    delete[] next;

    if (j == T.length) {
        return i - T.length; // 返回匹配的位置
    }
    else {
        return -1; // 未找到匹配位置
    }
}


// 输出串
void StrPrint(String S) {
    for (int i = 0; i < S.length; i++) {
        printf("%c", S.data[i]);
    }
    printf("\n");
}
