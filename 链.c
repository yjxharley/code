
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
    printf("1----����������\n");
    printf("2----�ݻٵ�����\n");
    printf("3----����������\n");
    printf("4----���Ƿ�Ϊ��\n");
    printf("5----��ĳ���\n");
    printf("6----���������ֻʣ��ͷ��㣩\n");
    printf("7----���ĳ��λ�õ�����\n");
    char str;
    int num;
    int pos;
    int val;
    PL phead=NULL;
    do
    {
        printf("���������ѡ��");
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
                printf("������Ϊ:%d\n",getlength(phead));
                break;
            case 6:
                clearLinkedList(phead);
                break;
            case 7:
                printf("����������ҪѰ�ҵ�λ��");
                scanf("%d",&pos);
                getElem(phead,pos);
                break;

        }

        printf("�Ƿ񽫼�������Y����,���������˳�\n");
        scanf(" %c",&str);
    }while(str=='Y');
    return 0;
}
PL initLinkedList()
{
    int option;
    printf("1�Զ����ʼ����2���Զ����ʼ��\n");
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
        printf("����������Զ�������Ŀ\n");
        scanf("%d",&num);
        for(int i = 0;i< num;i++)
        {
            printf("�������%d���ڵ��ֵ\n",i+1);
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
        printf("����������\n");
        return NULL;

    }
}
PL destroyLinkedList(PL phead)//������������NULL��
{
    char str;
    if(NULL == phead)
    {
        printf("ͷ���Ϊ��\n");
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
        printf("�Ƿ񽫼�������Y����,���������˳�\n");
        scanf(" %c",&str);
    }
    while(str=='Y');
    return 0;
}
void traverse(PL phead)
{
    if(NULL ==phead)
    {
        printf("ͷ���Ϊ��\n");
    }
    else{
        if(isEmpty(phead))
        {
            printf("����Ϊ��\n");
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
        printf("ͷ���Ϊ��\n");
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

int getlength(PL phead)//�õ�����ĳ��ȣ����س���ֵ
{
    if(NULL==phead)
    {
        printf("ͷ���Ϊ��\n");
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
void clearLinkedList(PL phead)//����������ֻ����ͷ���
{
    if(NULL == phead)
    {
        printf("ͷ���Ϊ��\n");
    }
    else
    {
        phead->Next =destroyLinkedList(phead->Next);
    }


}
void getElem(PL phead, int i)//�õ�ĳ��λ�õ�Ԫ��
{
    traverse(phead);
    if(NULL == phead)
    {
        printf("ͷ���ΪNULL\n");

    }
    else if(isEmpty(phead))
    {
        return;
    }
    else if(i<1 || i>getlength(phead))
    {
        printf("�������\n");
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
        printf("��%d��λ�õ�ֵΪ:%d\n",i,p->data);
    }

}
