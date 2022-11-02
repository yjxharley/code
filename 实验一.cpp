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


//构造一个空的线性表

Status InitList(SqList &L){
    L.elem =(ElemType*) malloc (MAXSIZE*sizeof(ElemType));
    if(L.elem==NULL)
    {
        exit(OVERFLOW);
    }
    L.length =0;
    return OK;
}
//清除线性表
Status ClearList(SqList &L){
    if(L.elem)
    {
        L.length=0;
        printf("清除成功\n");
        return OK;
    }
    else
    {
        printf("线性表不存在不能清空\n");
        return OK;
    }
}
 //判断线性表是否为空
 Status ListEmpty(SqList L){
    if(L.elem)
    {
        if(L.length != 0)
            printf("线性表不是空表\n");
        else
            printf ("线性表是空表");

    }
    else
        printf("现象表不存在\n");
    return OK;
 }

Status ListLength(SqList L){
    if(L.elem)
    {
        int x;
        x=L.length;
        printf("线性表的长度为%d",x);
        return OK;
    }
}

//获取线性表某一位置的元素
Status GetElem(SqList L,int index){
int Num;
if(index<=0 || index >L.length)
{
    printf("输入不合法，操作失败\n");
    return ERROR;
}
else{
    Num =L.elem[index -1];

}
printf("第%d个元素为：%d\n",index,Num);
return OK;
}
//在线性表某一位置插入元素
Status ListInsert (SqList &L,int i,ElemType e)
{
    if(i<0 || i>L.length+1)
    {
        printf ("插入位置不合法\n");
        return ERROR;
    }
   if(L.length ==MAXSIZE)
   {
       printf ("插入位置已满，插入失败\n");
       return ERROR;
   }
   for(int j =L.length-1;j>i-1;j--)
   {
       L.elem[j]=L.elem[i-1];
   }
   L.elem[i-1]=e;
   L.length++;
   printf("插入成功\n");
   return OK;


}
//打印线性表
Status PrintList(SqList L)
{
    printf("线性表元素为;\n");
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
    printf("删除位置不合法\n");
    return ERROR;
}
for(int j=i+1;j<=L.length;j++)
{
        L.elem[j-1]=L.elem[j];
}
--L.length;
printf("删除成功\n");
return OK;
}
//求前驱
Status PriorElem(SqList&L,int i){
    int x;
 if(L.elem)
 {
    if(i<=1||i>L.length)
        printf("输入不合法\n");
    else{
        x=L.elem[i-2];
        printf("您要找的位置为%d的前驱为：%d\n",i,x);
    }

 }
 else
    printf("线性表不存在,操作失败\n");
return OK;
}
 Status NestElem(SqList &L,int i){
 int x=0;
 if(L.elem)
 {
     if(i<=0||i>=L.length)
     {
         printf("输入不合法\n");
     }
     else {
            x=L.elem[i];
        printf("您查找的位置为%d的后继为：%d\n",i,x);
     }

 }
 else{
    printf("输入不合法\n");
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
        printf(":1------清空线性表............................\n");
        printf(":2------判断是否为空..........................\n");
        printf(":3------求线性表长度..........................\n");
        printf(":4-------获取指定位置元素.....................\n");
        printf(":5------插入元素..............................\n");
        printf(":6------显示线性表............................\n");
        printf(":7------删除某个元素..........................\n");
        printf(":8-----求前驱..........................\n");
        printf(":9------求后继..........................\n");
        scanf("%d",&choose);
        if(choose<0)
        break;
        switch(choose){
        case 1:ClearList(L);break;
        case 2:ListEmpty(L);break;
        case 3:ListLength(L);break;
        case 4:{
         printf("请输入要获取元素的位置\n");
         scanf("%d",&index);
         GetElem(L,index);
          }
        break;

        case 5:{
            printf("请输入要插入的位置");
            scanf("%d",&index);
            printf("请输入要插入元素");
            scanf("%d",&e);
            ListInsert(L,index,e);
            //PrintList(L);
            }
            break;
        case 6:PrintList(L);break;
        case 7:{
            printf("请输入删除的位置\n");
            scanf("%d",&index);
            DeleteList( L ,index);
        }
        break;
        case 8:{
        printf("请输入查找前驱的位置\n");
        scanf("%d",&index);
        PriorElem(L,index);
        }
        break;
        case 9:{
        printf("请输入要查找后继的位置\n");
        scanf("%d",&index);
        NestElem(L,index);
        }


        }
    }

}
