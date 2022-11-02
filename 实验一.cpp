#include <iostream>
#include <stdio.h>
#include  <stdlib.h>
#include <malloc.h>
using namespace std;

#define OK       1
#define ERROR   -1
#define OVERFLOW   -2
#define MAXSIZE    100


typedef int  Status;
typedef int ElemType;

typedef struct{
    ElemType *elem;
    int length;
}SqList;


//����һ���յ����Ա�

Status InitList(SqList &L){
    L.elem =(ElemType*) malloc (MAXSIZE*sizeof(ElemType));
    if(L.elem==NULL)
    {
        exit(OVERFLOW);
    }
    L.length =0;
    return OK;
}
//������Ա�
Status ClearList(SqList &L){
    if(L.elem)
    {
        L.length=0;
        printf("����ɹ�\n");
        return OK;
    }
    else
    {
        printf("���Ա����ڲ������\n");
        return OK;
    }
}
 //�ж����Ա��Ƿ�Ϊ��
 Status ListEmpty(SqList L){
    if(L.elem)
    {
        if(L.length != 0)
            printf("���Ա��ǿձ�\n");
        else
            printf ("���Ա��ǿձ�");

    }
    else
        printf("���������\n");
    return OK;
 }

Status ListLength(SqList L){
    if(L.elem)
    {
        int x;
        x=L.length;
        printf("���Ա�ĳ���Ϊ%d",x);
        return OK;
    }
}

//��ȡ���Ա�ĳһλ�õ�Ԫ��
Status GetElem(SqList L,int index){
int Num;
if(index<=0 || index >L.length)
{
    printf("���벻�Ϸ�������ʧ��\n");
    return ERROR;
}
else{
    Num =L.elem[index -1];

}
printf("��%d��Ԫ��Ϊ��%d\n",index,Num);
return OK;
}
//�����Ա�ĳһλ�ò���Ԫ��
Status ListInsert (SqList &L,int i,ElemType e)
{
    if(i<0 || i>L.length+1)
    {
        printf ("����λ�ò��Ϸ�\n");
        return ERROR;
    }
   if(L.length ==MAXSIZE)
   {
       printf ("����λ������������ʧ��\n");
       return ERROR;
   }
   for(int j =L.length-1;j>i-1;j--)
   {
       L.elem[j]=L.elem[i-1];
   }
   L.elem[i-1]=e;
   L.length++;
   printf("����ɹ�\n");
   return OK;


}
//��ӡ���Ա�
Status PrintList(SqList L)
{
    printf("���Ա�Ԫ��Ϊ;\n");
    for(int j=0;j<L.length;j++)
    {
        printf("%d",L.elem[j]);
        printf("\n");
    }
    printf("\n");
    return OK;
}
Status DeleteList(SqList &L,int i){
if(i<1 || i>L.length)
{
    printf("ɾ��λ�ò��Ϸ�\n");
    return ERROR;
}
for(int j=i+1;j<=L.length;j++)
{
        L.elem[j-1]=L.elem[j];
}
--L.length;
printf("ɾ���ɹ�\n");
return OK;
}
//��ǰ��
Status PriorElem(SqList&L,int i){
    int x;
 if(L.elem)
 {
    if(i<=1||i>L.length)
        printf("���벻�Ϸ�\n");
    else{
        x=L.elem[i-2];
        printf("��Ҫ�ҵ�λ��Ϊ%d��ǰ��Ϊ��%d\n",i,x);
    }

 }
 else
    printf("���Ա�����,����ʧ��\n");
return OK;
}
 Status NestElem(SqList &L,int i){
 int x=0;
 if(L.elem)
 {
     if(i<=0||i>=L.length)
     {
         printf("���벻�Ϸ�\n");
     }
     else {
            x=L.elem[i];
        printf("�����ҵ�λ��Ϊ%d�ĺ��Ϊ��%d\n",i,x);
     }

 }
 else{
    printf("���벻�Ϸ�\n");
    return OK;
 }
 }


int main()
{
    SqList L;
    InitList(L);
    int choose,index,e;
    while(1)
    {
        printf(":.............................................\n");
        printf(":1------������Ա�............................\n");
        printf(":2------�ж��Ƿ�Ϊ��..........................\n");
        printf(":3------�����Ա���..........................\n");
        printf(":4-------��ȡָ��λ��Ԫ��.....................\n");
        printf(":5------����Ԫ��..............................\n");
        printf(":6------��ʾ���Ա�............................\n");
        printf(":7------ɾ��ĳ��Ԫ��..........................\n");
        printf(":8-----��ǰ��..........................\n");
        printf(":9------����..........................\n");
        scanf("%d",&choose);
        if(choose<0)
        break;
        switch(choose){
        case 1:ClearList(L);break;
        case 2:ListEmpty(L);break;
        case 3:ListLength(L);break;
        case 4:{
         printf("������Ҫ��ȡԪ�ص�λ��\n");
         scanf("%d",&index);
         GetElem(L,index);
          }
        break;

        case 5:{
            printf("������Ҫ�����λ��");
            scanf("%d",&index);
            printf("������Ҫ����Ԫ��");
            scanf("%d",&e);
            ListInsert(L,index,e);
            //PrintList(L);
            }
            break;
        case 6:PrintList(L);break;
        case 7:{
            printf("������ɾ����λ��\n");
            scanf("%d",&index);
            DeleteList( L ,index);
        }
        break;
        case 8:{
        printf("���������ǰ����λ��\n");
        scanf("%d",&index);
        PriorElem(L,index);
        }
        break;
        case 9:{
        printf("������Ҫ���Һ�̵�λ��\n");
        scanf("%d",&index);
        NestElem(L,index);
        }


        }
    }

}
