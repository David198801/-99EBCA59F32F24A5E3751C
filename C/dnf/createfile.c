#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void CreateMyFile(char * szFileName,long long fileSize)
{
    FILE* fp = fopen(szFileName, "wb+"); // �����ļ�
    if(fp==NULL)
        printf("ʧ��");
    else
    {

        char c[100]="sssssss";
        const fpos_t fileSizeT = fileSize-1;
        //fseek(fp, fileSizeT-1, SEEK_SET); // ���ļ���ָ�� ���� ָ����С��λ����
        fsetpos(fp, &fileSizeT);
        fwrite(&c,1,7,fp);
        fclose(fp);
    }
}


int main(void)
{
    int fileQuantity=1;
    int i;
    char fileName[256] = "test";
    char ext[10] = "txt";
    long long size=0;

    printf("�����ļ�����:");
    scanf("%d",&fileQuantity);
    printf("�����ļ���С(MB):");
    scanf("%lld",&size);



    size = size*1024*1024;
    for (i=0; i<fileQuantity; i++)
    {

        char code[10];
        char currentFileName[256];
        sprintf(code, "%d", i+1);
        strcpy(currentFileName,fileName);
        strcat(currentFileName,code);
        strcat(currentFileName,".");
        strcat(currentFileName,ext);
        CreateMyFile(currentFileName,size);
    }
    return 0;

}
