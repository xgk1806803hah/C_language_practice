#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;

typedef int SElemType;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack, Status;

Status InitStack(SqStack *S);

Status DestroyStack(SqStack *S);

Status ClearStack(SqStack *S);

Status StackEmpty(SqStack *S);

int StackLength(SqStack *S);

Status GetTop(SqStack *S,SElemType *e);

Status Push(SqStack *S,SElemType *e);

Status Pop(SqStack *S,SElemType *e);

Status StackTraverse(SqStack *S,Status(*visit)());


Status InitStack(SqStack *S){
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType ));
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack *S){
　　free(S.base);

　　S.base = NULL;
　　S.top  = NULL;
　　S.stacksize = 0;
　
    return OK;
}

Status ClearStack(SqStack *S){
　　S.top = S.base;
    return OK;
}

Status StackEmpty(SqStack *S){
    if (S.top = S.base)
        return TRUE;
    else　　
        return FALSE;
}

int StackLength(SqStack *S){
    return S.top - S.base;
}

Status GetTop(SqStack *S,SElemType *e){
    if (S.top == S.base)
        return ERROR;
    e = *(S.top - 1);
        return OK;
}

Status Push(SqStack *S,SElemType *e){
    if (S.top - S.base>= S.stacksize){
        S.base= (SElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if (!S.base)
　　　　　　　exit(OVERFLOW);
　　　　　S.top = S.base + S.stacksize;
　　　　　S.stacksize += STACKINCREMENT;
　　}　　
　　*S.top++ = e;
    return OK;
}

Status Pop(SqStack *S,SElemType *e){
    if (S.top == S.base)
        return ERROR;
　　e = *--S.top;
    return OK;
}

Status StackTraverse(SqStack *S,Status(*visit)()){
　　SElemType *p = S.base;
    while(p < S.top)
　　　　Visit(*p++);
    return OK;
}
