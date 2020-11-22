#include <stdio.h>
#include <stdlib.h>
#define OK 1;
#define ERROR 0;
typedef int ElemType;
typedef char Status;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


Status GetElem_L(LinkList L, int i, ElemType *e)
{
    int j;
    j = 1;
    LinkList p;
    p = L->next;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}
Status InsertListLink(LinkList L, int i, ElemType e)
{
    int j;
    j = 1;
    LinkList p ,s;
    p = L;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof (LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status DeleteLinkList(LinkList L, int i, ElemType *e)
{
    int j;
    j = 1;
    LinkList p,q;
    p = L;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return ERROR;
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}
void headCreateList(LinkList *L,int n)
{
    int i;
    LinkList p;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for(i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        //p->data = i;
        p->next = (*L)->next;
        (*L)->next = p;
    }

}
void tailCreateList(LinkList *L, int n)
{
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    LinkList p,q;
    p = L;
    for(i = 0; i < n; i++)
    {
        q = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&q->data);
        //q->data = i;
        p->next = q;
        p = q;
    }
    p->next = NULL;
}

void OutputLinkList(LinkList L)
{
    LinkList p = L->next;
    while(p)
    {
        printf("%d",p->data);
        p = p->next;
    }
    printf("\n");
}
int isEmpty(LinkList L)
{
    LinkList p = L;
    return p->next == NULL ? 1:0;
}

int LengthList(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    if(!p)
        return 0;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}
void destoryList(LinkList L)
{
    LinkList p = L;
    while(p)
    {
        p = p->next;
        free(p);
    }
    L->next = NULL;
}
int locationElem(LinkList L,ElemType e)
{
    LinkList p;
    p = L;
    int i = 0;
    while(p)
    {
        p = p->next;
        i++;
        if(p->data == e)
            return i;
    }
    return 0;
}
LinkList partition(LinkList L, int x)
{
    LinkList smallhead = NULL;
    LinkList smalltail = NULL;
    LinkList bighead = NULL;
    LinkList bigtail = NULL;
    LinkList cur;
    for(cur = L; cur != NULL; cur = cur->next)
    {
        if(cur->data < x)
        {
            if(smalltail == NULL)
                smallhead = smalltail = cur;
            else
            {
                smalltail->next = cur;
                smalltail = cur;
            }
        }
        else
        {
            if(bigtail == NULL)
                bighead = bigtail = cur;
            else
            {
                bigtail->next = cur;
                bigtail = cur;
            }
        }
    }
    if(smalltail)
        smalltail->next = bighead;
    if(smallhead)
        return smallhead;
    else
        return bighead;
}

int main()
{
    LNode *list;
    printf("insert five element to list by tailCreateList:\n");
    tailCreateList(&list,5);  //��β�巨��������
    OutputLinkList(list);
    /*printf("����ĳ���Ϊ:%d\n",LengthList(list));//�������ĳ���
    if(isEmpty(list) == 1)//�ж������Ƿ�Ϊ��
        printf("����Ϊ��\n");
    else
        printf("����Ϊ��\n");
    ElemType e;
    GetElem_L(list,3,&e);
    printf("������Ԫ��Ϊ��%c\n",e);//���ҵ�����Ԫ��
    printf("a��λ��Ϊ:%d\n",locationElem(list,'a'));//����aԪ�ص�λ��
    InsertListLink(list,4,'f');//�ڵ��ĸ�λ�ò���f
    printf("�ڵ��ĸ�λ�ò���f��\n");
    OutputLinkList(list);
    ElemType e1;
    DeleteLinkList(list,3,&e);//ɾ��������Ԫ��
    printf("ɾ��������Ԫ�غ�\n");
    OutputLinkList(list);
    destoryList(list);//��������
    printf("%d",LengthList(list));*/

    LNode *list2;
    list2 = partition(list,2);
    OutputLinkList(list2);

}
