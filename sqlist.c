#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef char Status;
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;

//init Sqlist
Status InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem)
        exit(ERROR);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}
//insert an element to sqList
Status ListInsert_Sq(SqList *L, int i, ElemType e)
{
     ElemType *newbase,*p, *q;
     if(i < 1 || i > L->length - 1)
        return ERROR;
     if(L->length >= L->listsize)
     {
        newbase = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)
            exit(ERROR);
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
     }
     q = &(L->elem[i - 1]);
     for(p = &(L->elem[L->length - 1]); p >= q; p--)
        *(p + 1) = *p;
     *q = e;
     ++L->length;
     return OK;

}
//delete an enlement in sqlist
Status ListDelete(SqList *L, int i, ElemType *e)
{
    ElemType *p, *q;
    if(i < 1 || i > L->length - 1)
        return ERROR;
    p = &(L->elem[i - 1]);
    *e = *p;
    q = L->elem + L->length - 1;
    for(++p; p <= q; ++p)
        *(p - 1) = *p;
    --L->length;
    return OK;
}
//get length
int listLength(SqList L)
{
    return L.length;
}

//clear list
void ClearList(SqList *L)
{
    L->length = 0;
}
//isEmpty
int IsEmpty(SqList L)
{
	return L.length == 0 ? 1 :0;
}
//input sqlist
void InputList(SqList *L)
{
    int n,i;
    printf("input n:\n");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
    	scanf("%d",&L->elem[i]);
    	L->length++;
	}
}
//output sqlist
void OutputList(SqList L)
{
    int i;
    for(i = 0; i < L.length; i++)
        printf("%d ",L.elem[i]);
    printf("\n");
}
//locate an element in sqlist
int locateElem(SqList L, ElemType e)
{
    int i;
    for(i = 0; i < L.length;i++)
    {
        if(e == L.elem[i])
            return i + 1;
    }
    return 0;
}
//getElment
Status GetElem(SqList L, int i, ElemType *e)
{
	if(i < 1 || i > L.length)
		return ERROR;
	else
	{
		*e = L.elem[i - 1];
		return OK;
	}

}
//destory SqList
void DestoryList(SqList *L)
{
	if(L->elem)
		free(L->elem);
	L->elem = NULL;
}
int main()
{
    SqList la;
    if(InitList_Sq(&la) == OK)
        printf("initlist is ok\n");
    //printf("insert a b c d e to sqlist\n");
    InputList(&la);
    printf("output sqlist:");
    OutputList(la);
    if(IsEmpty(la) == 1)
    	printf("顺序表为空");
    else
    	printf("顺序表不为空,顺序表的长度为:%d\n",listLength(la));
    ElemType e;
    GetElem(la,3,&e);
    printf("第三位元素为:%c\n",e);
    printf("在第四位插入f:\n");
    ElemType e1 = 10;
	ListInsert_Sq(&la,4,e1);
	printf("元素F插入成功，顺序表为：");
	OutputList(la);
	ElemType e2;
	 printf("删除第三位元素:\n");
	ListDelete(&la,3,&e2);
	printf("第三位元素删除成功，顺序表为：");
	OutputList(la);
	printf("销毁顺序表");
	DestoryList(&la);
    /*int e;
    ListDelete(&la,4,&e);
    OutputList(la);
    printf("删除的元素为：%d\n",e);
    ListInsert_Sq(&la,5,10);
    OutputList(la);*/
    //int z = 5;
    //printf("%d",locateElem(la,z));

}
