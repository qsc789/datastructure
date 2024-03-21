#include"string.h"


// ��ʼ����
void InitString(String* S) {
    S->length = 0;
}

// �жϴ��Ƿ�Ϊ��
bool StrEmpty(String S) {
    return S.length == 0;
}

// �󴮵ĳ���
int StrLength(String S) {
    return S.length;
}

// ��մ�
void ClearString(String* S) {
    S->length = 0;
}

// ����ֵ
void StrAssign(String* S, String T) {
    for (int i = 0; i < T.length; i++) {
        S->data[i] = T.data[i];
    }
    S->length = T.length;
}

// ���Ƚ�
int StrCompare(String S, String T) {
    for (int i = 0; i < S.length && i < T.length; i++) {
        if (S.data[i] != T.data[i]) {
            return S.data[i] - T.data[i];
        }
    }
    return S.length - T.length;
}

// ������
void StrConcat(String* T, String S1, String S2) {
    for (int i = 0; i < S1.length; i++) {
        T->data[i] = S1.data[i];
    }
    for (int i = 0; i < S2.length; i++) {
        T->data[S1.length + i] = S2.data[i];
    }
    T->length = S1.length + S2.length;
}

// �����Ӵ�
void SubString(String* Sub, String S, int pos, int len) {
    for (int i = pos - 1; i < pos - 1 + len; i++) {
        Sub->data[i - pos + 1] = S.data[i];
    }
    Sub->length = len;
}

// ���Ĳ���
void StrInsert(String* S, int pos, String T) {
    for (int i = S->length - 1; i >= pos - 1; i--) {
        S->data[i + T.length] = S->data[i];
    }
    for (int i = pos - 1; i < pos - 1 + T.length; i++) {
        S->data[i] = T.data[i - pos + 1];
    }
    S->length = S->length + T.length;
}

// ����ɾ��
void StrDelete(String* S, int pos, int len) {
    for (int i = pos - 1 + len; i < S->length; i++) {
        S->data[i - len] = S->data[i];
    }
    S->length = S->length - len;
}

// �����滻
void StrReplace(String* S, String T, String V) {
    int pos = 0;
    while ((pos = Index(*S, T, pos + 1)) != -1) {
        StrDelete(S, pos + 1, T.length);
        StrInsert(S, pos, V);
    }
}

// ���Ĳ��ң��ڴ�S�дӵ�pos���ַ���ʼ���Ҵ�T��һ�γ��ֵ�λ�ã���������λ��ֵ��
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
//BF�㷨������ƥ��
int BFMatch(String S, String T) {
    int i = 0; // ����S�ĵ�ǰλ��
    int j = 0; // ģʽ��T�ĵ�ǰλ��

    while (i < S.length && j < T.length) {
        if (S.data[i] == T.data[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1; // �������˵���һ��ƥ��λ�õ���һ��λ��
            j = 0; // ģʽ����ͷ��ʼƥ��
        }
    }

    if (j == T.length) {
        return i - T.length; // ����ƥ���λ��
    }
    else {
        return -1; // δ�ҵ�ƥ��λ��
    }
}
//KMP�㷨
void GetNextval(const String& T, int nextval[]) {
    int i = 0;  // ģʽ���е�ǰλ��
    int j = -1; // ���ƥ��ǰ׺�Ӵ��Ľ���λ��
    nextval[0] = -1; // ��һ��λ�õ�nextֵΪ-1

    while (i < T.length - 1) {
        if (j == -1 || T.data[i] == T.data[j]) {
            i++;
            j++;
            // �޸ĵĵط������ж��ַ����ʱ����T[i+1]��T[j+1]Ҳ��ȣ�ֱ�ӻ��˵�nextval[j]��λ��
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

    int i = 0; // ����S�ĵ�ǰλ��
    int j = 0; // ģʽ��T�ĵ�ǰλ��

    while (i < S.length && j < T.length) {
        if (j == -1 || S.data[i] == T.data[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];//����next[j]���ַ������Ƚ�
        }
    }

    delete[] next;

    if (j == T.length) {
        return i - T.length; // ����ƥ���λ��
    }
    else {
        return -1; // δ�ҵ�ƥ��λ��
    }
}


// �����
void StrPrint(String S) {
    for (int i = 0; i < S.length; i++) {
        printf("%c", S.data[i]);
    }
    printf("\n");
}
