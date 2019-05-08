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
SequenStack *Init()//��ʼ��ջ
{
    SequenStack *S;
    S = (SequenStack*)malloc(sizeof(SequenStack));
    S->top = -1;
    return S;
}
int Empty(SequenStack *S)//ջ�п�
{
    if (S->top == -1)
        return 1;//�շ���1
    else
        return 0;// �ǿշ���0
}
int Push(SequenStack *S, elemtype x)//��ջ
{
    if (S->top >= MAX -1)
    {
        printf("ջ��\n");//ջ��������ջ����1��
        return 1;
    }
    S->top++;
    S->data[S->top] = x;
    return 0;//��ջ�ɹ�����0��
}
int Pop(SequenStack *S, elemtype *x)//��ջ
{
    if (S->top == -1)
    {
        printf("ջ��\n");//ջ�շ���1
        return 1;
    }
    else
    {
        S->top--;
        *x = S->data[S->top + 1];
        return 0;//��ջ�ɹ�����0��
    }
}
int GetTop(SequenStack *S,elemtype *x)//ȡջ��Ԫ��
{
    if (S->top == -1)
    {
        printf("ջ��\n");//ջ�շ���1
        return 1;
    }
    else
    {
        *x = S->data[S->top];//�ɹ��շ���0��
        return 0;
    }
}
void main()
{
    int i;
    char *infix;
//  char ca[100];//��׺���ʽָ��
//  infix=ca;
    char *postfix;//��׺���ʽָ��
    int result = 0;//���ؽ��
    infix = (char*)malloc(sizeof(char)*100);
    printf("��������ʽ:");
    gets(infix);
    postfix = trans(infix);//ת��Ϊ��׺���ʽ
    printf("��׺���ʽΪ��");
    puts(postfix);//�����׺���ʽ
    result = evaluate(postfix);//��ý��
    printf("���ʽ������:%d\n", result);
}
char *trans(char *express)//��׺ת��Ϊ��׺
{
    char oprand;// ����������������
    char Operator;
    //char cb[100];
    SequenStack *S;//ջ�������
    S = Init(); //ջ��ʼ��Ϊ��
    char *postfix;//��׺���ʽָ��
//  postfix=cb;
    int offset = 0;
    int i;
    postfix = (char*)malloc(sizeof(char)*100);//����ռ�
    for(i=0;express[i]!='\0';i++)//������׺���ʽ
    {
        oprand = express[i];
        switch (oprand)
        {
            case'+':
            case'-'://���Ϊ+-
                while (!Empty(S))//��ջ�ǿ�
                {
                    GetTop(S, &Operator);//ȡջ��
                    if (Operator!='(')//�����Ϊ��
                    {
                        Pop(S, &Operator);//һֱ��ջ
                        postfix[offset++] = Operator;
                    }
                    else
                    {
                        break;
                    }
                }
                Push(S, oprand); break;//���գ�ֱ����ջ
            case'*':
            case'/'://���Ϊ*/
                while (!Empty(S))
                {
                    GetTop(S, &Operator);//ȡջ��
                    if (Operator=='*' || Operator=='/')//��Ϊ*/��һֱ��ջ
                    {
                        Pop(S, &Operator);
                        postfix[offset++] =Operator;
                    }
                    else
                    {
                        break;
                    }
                }
                Push(S, oprand);//����ֱ����ջ
                break;
            case'(':
                Push(S, oprand);//�����ȼ���ߣ�ֱ����ջ
                break;
            case')'://�����ȼ����/��ʼ��ս
                while (!Empty(S))
                {
                    GetTop(S, &Operator);
                    if (Operator!='(')//��սֱ��������
                    {
                        Pop(S, &Operator);
                        postfix[offset++] = Operator;
                    }
                    else
                    {
                        Pop(S, &Operator); //����ջ
                        break;
                    }
                }
                break;
            default:
                postfix[offset++] = oprand;//���ֽ����׺���ʽ
        }
    }
    while (!Empty(S))//ջ���� Ԫ�س�ս
    {
        Pop(S, &Operator);
        postfix[offset++] = Operator;
    }
    postfix[offset++] = '\0';
    return postfix;
}
int change1(char c)//�ַ�ת��Ϊ����
{

    return (c - '0');
}
char change2(int x)//����ת��Ϊ�ַ�
{
    return (x + 48);
}
int evaluate(char *express)//���ݺ�׺���ʽ������
{
    char oprand;
    SequenStack *G;//����������
    char result;
    int i;
    G= Init();//��ʱջΪ��
    for (i = 0; express[i] != '\0';i++)//������׺���ʽ
    {
        oprand = express[i];
        if (oprand >= '0'&&oprand <= '9')//���Ϊ������ֱ����ջ
        {
            Push(G,oprand);
        }
        else//���Ϊ��������������
        {
            calculate(G,oprand);
        }
    }
    Pop(G, &result); //�������ջ
    return change1(result);
}
void calculate(SequenStack *H, char Operator)//�����������ֵ
{
    char operand1, operand2;
    int result;
    Pop(H, &operand2);
    Pop(H, &operand1);
    result = Operate(change1(operand1),change1(operand2),Operator);
    Push(H,change2(result));//��������ջ
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
