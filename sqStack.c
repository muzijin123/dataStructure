#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
typedef char Status;
typedef char SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InStack(SqStack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S->base)
		exit(ERROR);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S,SElemType *e)
{
	if(S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
			exit(ERROR);
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status POP(SqStack *S, SElemType *e)
{
	if(S->top == S->base)
		return ERROR;
	*e = *--S->top;
	return OK;
}

int IsEmpty(SqStack *S)
{
	if(S->top == S->base)
        return 1;
    else
        return 0;
}

void Output(SqStack *S)
{
	SElemType *p;
	p = S->top;
	while(p != S->base)
	{
		printf("%c ",*(p-1));
		p--;
	}
	printf("\n");
}
void Sort(SqStack *S)
{
	SqStack Stmp;
	InStack(&Stmp);
	SElemType se,te;
	while(!IsEmpty(S))
	{
		POP(S,&se);
		while(!IsEmpty(&Stmp))
        {
            GetTop(Stmp,&te);
            if(te > se)
            {
                POP(&Stmp,&te);
                Push(S,te);
            }
            else
                break;
        }
        Push(&Stmp,se);
	}
    while(!IsEmpty(&Stmp))
    {
        POP(&Stmp,&te);
        Push(S,te);
    }
}
int main(int argc, char *argv[]) {
	SqStack ss;
	InStack(&ss);
	Push(&ss,'c');
	Push(&ss,'b');
	Push(&ss,'a');
	Push(&ss,'f');
	Push(&ss,'e');
	Output(&ss);
    Sort(&ss);
    Output(&ss);
}
