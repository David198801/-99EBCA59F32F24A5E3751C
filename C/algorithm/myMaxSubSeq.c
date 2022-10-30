#include<stdio.h>
int MaxSubSeq1(int seq[],int n){
    int thisSeq,maxSeq=0;
    int i,j;
    for (i=0;i<n;i++){
        thisSeq=0;
        for(j=i;j<n;j++){
            thisSeq += seq[j];
            if (thisSeq>maxSeq)
                maxSeq=thisSeq;
        }
    }
    return maxSeq;
}
int MaxSubseqSum4(int A[], int N)
{
    int ThisSum, MaxSum;
    int i;
    ThisSum = 0;
    MaxSum = -100;
    for (i = 0; i < N; i++){
        ThisSum += A[i];//�����ۼ�
        if (ThisSum>MaxSum){
            MaxSum = ThisSum; // ���ָ��������µ�ǰ���
            printf("%d\n",MaxSum);}
        if (ThisSum < 0)  // �����ǰ���к�Ϊ����
            ThisSum = 0; // �򲻿���ʹ���沿�ֺ���������֮
    }
    return MaxSum;

}

int Max3( int A, int B, int C ){ /* ����3�������е����ֵ */
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer( int List[], int left, int right ){ /* ���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* �ݹ����ֹ����������ֻ��1������ */
        //if( List[left] > 0 )
        return List[left];
        //else return 0;
    }

        /* ������"��"�Ĺ��� */
    center = ( left + right ) / 2; /* �ҵ��зֵ� */
        /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

        /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = -100; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
                MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */

    MaxRightBorderSum = -100; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
                MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */

        /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int List[], int N ){ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
        return DivideAndConquer( List, 0, N-1 );
    }



int main(void){
    int a[5]={-1,-5,-10,-6,-3};
    int b[3]={-3,1,3};
    int max;
    max = MaxSubseqSum3(a,5);
    printf("%d",max);
    return 0;
}
