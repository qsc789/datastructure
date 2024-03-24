#include <stdio.h>
#include <stdlib.h>
#include<iostream>

typedef struct {
    int row;
    int col;
    int value;
} Triplet;
void Transpose(Triplet* A, Triplet* B)
{
    int m = A[0].row;//��
    int n = A[0].col;//��
    int num = A[0].value;
    //���жԻ�
    B[0].row = n;
    B[0].col = m;
    B[0].value = num;
    if (num > 0)
    {
        int q = 1;
        
        for (int c = 0; c <= n; c++)
        {
            int p = 1;
            while(A[p].value>0)
            {
                if (A[p].col == c)//B�������У����Կ�A����
                {
                    //q��������A����Ԫ�طŵ�B��
                    B[q].row = A[p].col;
                    B[q].col = A[p].row;
                    B[q].value = A[p].value;
                    q++;
                }
                p++;
            }
        }
    }
}
void FastTranspose(Triplet* A, Triplet* B) //ת��
{
    int m = A[0].row;//��
    int n = A[0].col;//��
    int num = A[0].value;
    //���жԻ�
    B[0].row = n;
    B[0].col = m;
    B[0].value = num;

    if (num > 0) {
        int* row_count = (int*)malloc(n * sizeof(int));
        int* row_start = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            row_count[i] = 0;
        }
        for (int i = 1; A[i].value>0; i++) {
            row_count[A[i].col]++;//��M��ÿһ�к�����Ԫ����
        }
        row_start[0] = 1;
        //���col���е�һ������Ԫ������Ԫ���е����
        for (int i = 1; i < n; i++) {
            row_start[i] = row_start[i - 1] + row_count[i - 1];
        }

        for (int i = 1; A[i].value > 0; i++) {
            int j = row_start[A[i].col]++;
            B[j].row = A[i].col;
            B[j].col = A[i].row;
            B[j].value = A[i].value;
        }

        free(row_count);
        free(row_start);
    }
}

int main() {
    // ԭ�������Ԫ���ʾ
    //{i,j,val}��ʾ��i,jλ�õ�Ԫ��ֵΪval
    Triplet A[] = {
        {3, 3, 4},
        {0, 0, 1},
        {0, 2, 3},
        {1, 1, 2},
        {2, 0, 4},
        {2, 1, 5},
        {2, 2, 6}
    };

    // ת�ú����Ԫ���ʾ
    Triplet B[15];

    FastTranspose(A, B);
    //Transpose(A, B);
    printf("ԭ�������Ԫ���ʾ��\n");
    for (int i = 0; A[i].value>0; i++) {
        printf("(%d, %d, %d)\n", A[i].row, A[i].col, A[i].value);
    }

    printf("\nת�ú����Ԫ���ʾ��\n");
    for (int i = 0;B[i].value>0; i++) {
        printf("(%d, %d, %d)\n", B[i].row, B[i].col, B[i].value);
    }

    return 0;
}
