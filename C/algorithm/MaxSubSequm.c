#include <stdio.h>
int MaxSubSequm1(int A[], int N)
{
    int ThisSum, MaxSum = -100;
    int i, j, k;
    for (i = 0; i < N; i++)  {  // i ��������˵�λ��
        for (j = i; j <= N; j++){ //j �������Ҷ˵�λ��
            ThisSum = 0;               //*
            for (k = i; k <= j; k++)   //*
                ThisSum += A[k];       //*
            if (ThisSum>MaxSum)  // ����յõ������к͸���
                MaxSum = ThisSum; // ���½��

        }

    }// ѭ������
    return MaxSum;
}

int MaxSubseqSum4(int A[], int N)
{
    int ThisSum, MaxSum;
    int i;
    ThisSum = 0;
    MaxSum = -100;
    for (i = 0; i < N; i++){
        ThisSum += A[i];//�����ۼ�
        if (ThisSum>MaxSum)
            MaxSum = ThisSum; // ���ָ��������µ�ǰ���
        else if (ThisSum < 0)  // �����ǰ���к�Ϊ����
            ThisSum = 0; // �򲻿���ʹ���沿�ֺ���������֮
    }
    return MaxSum;

}
int main(void)
{
    int seq[5] = {-1,-1,-1,-1,-2};
    int max1,max2;
    max1 = MaxSubseqSum4(seq,5);
    max2 = MaxSubSequm1(seq,5);
    printf("%d\n",max1);
    printf("%d",max2);
    return 0;
}
