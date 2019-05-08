#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
typedef char elemtype;
typedef struct SequenStack
{
    elemtype data[MAX];
    //int type;
    int top;
}SequenStack;
int change1(char c);
char change2(int x);
void calculate(SequenStack *S, char Operator);
int Operate(int operand1, int operand2, char Operator);
int evaluate(char *express);
char *trans(char *express);
SequenStack *Init()//初始化栈
{
    SequenStack *S;
    S = (SequenStack*)malloc(sizeof(SequenStack));
    S->top = -1;
    return S;
}
int Empty(SequenStack *S)//栈判空
{
    if (S->top == -1)
        return 1;//空返回1
    else
        return 0;// 非空返回0
}
int Push(SequenStack *S, elemtype x)//入栈
{
    if (S->top >= MAX -1)
    {
        printf("栈满\n");//栈满不能入栈返回1；
        return 1;
    }
    S->top++;
    S->data[S->top] = x;
    return 0;//入栈成功返回0；
}
int Pop(SequenStack *S, elemtype *x)//出栈
{
    if (S->top == -1)
    {
        printf("栈空\n");//栈空返回1
        return 1;
    }
    else
    {
        S->top--;
        *x = S->data[S->top + 1];
        return 0;//出栈成功返回0；
    }
}
int GetTop(SequenStack *S,elemtype *x)//取栈顶元素
{
    if (S->top == -1)
    {
        printf("栈空\n");//栈空返回1
        return 1;
    }
    else
    {
        *x = S->data[S->top];//成功刚返回0；
        return 0;
    }
}
void main()
{
    int i;
    char *infix;
//  char ca[100];//中缀表达式指针
//  infix=ca;
    char *postfix;//后缀表达式指针
    int result = 0;//返回结果
    infix = (char*)malloc(sizeof(char)*100);
    printf("请输入表达式:");
    gets(infix);
    postfix = trans(infix);//转换为后缀表达式
    printf("后缀表达式为：");
    puts(postfix);//输出后缀表达式
    result = evaluate(postfix);//获得结果
    printf("表达式计算结果:%d\n", result);
}
char *trans(char *express)//中缀转换为后缀
{
    char oprand;// 储存操作数或运算符
    char Operator;
    //char cb[100];
    SequenStack *S;//栈存运算符
    S = Init(); //栈初始化为空
    char *postfix;//后缀表达式指针
//  postfix=cb;
    int offset = 0;
    int i;
    postfix = (char*)malloc(sizeof(char)*100);//分配空间
    for(i=0;express[i]!='\0';i++)//遍历中缀表达式
    {
        oprand = express[i];
        switch (oprand)
        {
            case'+':
            case'-'://如果为+-
                while (!Empty(S))//若栈非空
                {
                    GetTop(S, &Operator);//取栈顶
                    if (Operator!='(')//如果不为（
                    {
                        Pop(S, &Operator);//一直出栈
                        postfix[offset++] = Operator;
                    }
                    else
                    {
                        break;
                    }
                }
                Push(S, oprand); break;//若空，直接入栈
            case'*':
            case'/'://如果为*/
                while (!Empty(S))
                {
                    GetTop(S, &Operator);//取栈顶
                    if (Operator=='*' || Operator=='/')//顶为*/则一直出栈
                    {
                        Pop(S, &Operator);
                        postfix[offset++] =Operator;
                    }
                    else
                    {
                        break;
                    }
                }
                Push(S, oprand);//空则直接入栈
                break;
            case'(':
                Push(S, oprand);//（优先级最高，直接入栈
                break;
            case')'://）优先级最低/开始出战
                while (!Empty(S))
                {
                    GetTop(S, &Operator);
                    if (Operator!='(')//出战直到遇到（
                    {
                        Pop(S, &Operator);
                        postfix[offset++] = Operator;
                    }
                    else
                    {
                        Pop(S, &Operator); //（出栈
                        break;
                    }
                }
                break;
            default:
                postfix[offset++] = oprand;//数字进入后缀表达式
        }
    }
    while (!Empty(S))//栈其余 元素出战
    {
        Pop(S, &Operator);
        postfix[offset++] = Operator;
    }
    postfix[offset++] = '\0';
    return postfix;
}
int change1(char c)//字符转化为数字
{

    return (c - '0');
}
char change2(int x)//数字转化为字符
{
    return (x + 48);
}
int evaluate(char *express)//根据后缀表达式计算结果
{
    char oprand;
    SequenStack *G;//储存运算结果
    char result;
    int i;
    G= Init();//此时栈为空
    for (i = 0; express[i] != '\0';i++)//遍历后缀表达式
    {
        oprand = express[i];
        if (oprand >= '0'&&oprand <= '9')//如果为数字则直接入栈
        {
            Push(G,oprand);
        }
        else//如果为运算符则进行运算
        {
            calculate(G,oprand);
        }
    }
    Pop(G, &result); //最后结果出栈
    return change1(result);
}
void calculate(SequenStack *H, char Operator)//根据运算符求值
{
    char operand1, operand2;
    int result;
    Pop(H, &operand2);
    Pop(H, &operand1);
    result = Operate(change1(operand1),change1(operand2),Operator);
    Push(H,change2(result));//运算结果入栈
}
int Operate(int operand1, int operand2, char Operator)
{
    int result;
    switch (Operator)
    {
        case'+':result = operand1 + operand2; break;
        case'-':result = operand1 - operand2; break;
        case'*':result = operand1*operand2; break;
        case'/':result = operand1 / operand2; break;
    }
    return result;
}
