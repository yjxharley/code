
 #include<stdio.h>
 #include<stdlib.h>
 #include<malloc.h>
 #include<stdbool.h>
  typedef struct Lnode{
    int data;
    struct Lnode *Next;
  }L,*PL;
PL initLinkedList();
PL destroyLinkedList(PL phead);
void traverse();
bool isEmpty(PL phead);
void clearLinkedList(PL phead);
int getlength();
void getElem(PL phead,int i);

int main()
{
    printf("Hello world!\n");
    printf("1----创建单链表\n");
    printf("2----摧毁单链表\n");
    printf("3----遍历单链表\n");
    printf("4----表是否为空\n");
    printf("5----表的长度\n");
    printf("6----清除单链表（只剩下头结点）\n");
    printf("7----获得某个位置的数据\n");
    char str;
    int num;
    int pos;
    int val;
    PL phead=NULL;
    do
    {
        printf("请输入你的选择：");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
                phead=initLinkedList();
                break;
            case 2:
                    phead = destroyLinkedList(phead);
                break;
            case 3:
                traverse(phead);
                break;
            case 4:
                if(isEmpty(phead))
                {
                    printf("Empty.\n");
                }
                else{
                    printf("Not Empty.\n");
                }
                break;
            case 5:
                printf("链表长度为:%d\n",getlength(phead));
                break;
            case 6:
                clearLinkedList(phead);
                break;
            case 7:
                printf("请输入你想要寻找的位置");
                scanf("%d",&pos);
                getElem(phead,pos);
                break;

        }

        printf("是否将继续输入Y继续,或者其他退出\n");
        scanf(" %c",&str);
    }while(str=='Y');
    return 0;
}
PL initLinkedList()
{
    int option;
    printf("1自定义初始化，2非自定义初始化\n");
    scanf("%d",&option);
    if(1 == option)
    {
        PL phead=(PL)malloc(sizeof(L));
        if(NULL ==phead)
        {
            printf("Dynamic Malloc failed");
            exit(-1);
        }
        else
        {
            phead->Next =NULL;
            phead->data = 0;

        }
        PL ptail=phead;
        int num=0,val =0;
        printf("请输入你的自定义点的数目\n");
        scanf("%d",&num);
        for(int i = 0;i< num;i++)
        {
            printf("请输入第%d个节点的值\n",i+1);
            scanf("%d",&val);
            PL phew=(PL)malloc(sizeof(L));
            if(phew==NULL)
            {
               printf("Dynamic Malloc failed\n");
               exit(-1);
            }
            else
                {
                    phew->Next =NULL;
                    phew->data =val;
                }
            ptail->Next =phew;
            ptail = phew;
        }
        return phead;
    }
    else if(2 == option)
    {
        PL phead =(PL)malloc(sizeof(L));
        if(NULL == phead)
        {
            printf("Dynamic Malloc failed\n");
            exit(-1);
        }
        else{
          phead->Next =NULL;
          phead->data =0;

        }
        return phead;
    }
    else
    {
        printf("操作数错误\n");
        return NULL;

    }
}
PL destroyLinkedList(PL phead)//撤销链表，返回NULL；
{
    char str;
    if(NULL == phead)
    {
        printf("头结点为空\n");
        return NULL;

    }
    else
    {
        PL p=phead;
        PL q=NULL;
        while(p)
        {
            q=p->Next;
            free(p);
            p=q;
        }
        return NULL;

    }
    do{
        printf("是否将继续输入Y继续,或者其他退出\n");
        scanf(" %c",&str);
    }
    while(str=='Y');
    return 0;
}
void traverse(PL phead)
{
    if(NULL ==phead)
    {
        printf("头结点为空\n");
    }
    else{
        if(isEmpty(phead))
        {
            printf("链表为空\n");
        }
        else{
            PL p=phead->Next;
            while(p)
            {
                printf("%d\n",p->data);
                p=p->Next;
            }
            printf("\n");
        }
    }

}
bool isEmpty(PL phead)
{
    if(NULL==phead)
    {
        printf("头结点为空\n");
        return true;
    }
    else
    {
        if(NULL == phead->Next)
        {

                return true;
        }
        else{
            return false;
        }
    }
}

int getlength(PL phead)//得到链表的长度，返回长度值
{
    if(NULL==phead)
    {
        printf("头结点为空\n");
        return 0;
    }
    else
    {
        int i=0;
        PL p=phead->Next;
        while(p)
        {
            i++;
            p=p->Next;
        }
        return i;
    }
}
void clearLinkedList(PL phead)//清空链表，结果只包含头结点
{
    if(NULL == phead)
    {
        printf("头结点为空\n");
    }
    else
    {
        phead->Next =destroyLinkedList(phead->Next);
    }


}
void getElem(PL phead, int i)//得到某个位置的元素
{
    traverse(phead);
    if(NULL == phead)
    {
        printf("头结点为NULL\n");

    }
    else if(isEmpty(phead))
    {
        return;
    }
    else if(i<1 || i>getlength(phead))
    {
        printf("输入错误\n");
    }
    else
    {
        int j = 0;
        PL p =phead;
        while(p&& j<i)
        {
            j++;
            p=p->Next;
        }
        printf("第%d个位置的值为:%d\n",i,p->data);
    }

}
