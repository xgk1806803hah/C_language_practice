#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define EOVERFLOW 10
typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
void InitBiTree(BiTree *T)
{
    T = NULL;
}

//����������
int CreateBiTree(BiTree T)
{
    printf("���������Ľڵ㣺");
    TElemType ch;
    getchar();
    scanf("%c", &ch);
    if (ch == ' ')
    {
        T = NULL;
    }
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        if (!T)
        {
            exit(EOVERFLOW);
        }
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return true;
}

//�ж϶������Ƿ�Ϊ��
int BiTreeEmpty(BiTree *T)
{
    if (T)
    {
        return false;
    }
    else
    {
        return true;
    }
}
//���������
int BiTreeDepth(BiTree T)
{
    int i, j;
    if (!T)
    {
        return 0;
    }
    if (T->lchild)
    {
        i = BiTreeDepth(T->lchild);
    }
    else
    {
        i = 0;
    }
    if (T->rchild)
    {
        j = BiTreeDepth(T->rchild);
    }
    else
    {
        j = 0;
    }
    return i > j ? i + 1 : j + 1;
}

//��ӡ�ڵ�
void Visit(TElemType e)
{
    printf("%c", e);
}

//�Եݹ���ʽ�������������
void PreOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
    if (T)
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
}
//�Եݹ���ʽ�������������
void InOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
    if (T)
    {
        InOrderTraverse(T->lchild, Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild, Visit);
    }
}

//�Եݹ���ʽ�������������
void PostOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
    if (T)
    {
        PostOrderTraverse(T->lchild, Visit);
        PostOrderTraverse(T->rchild, Visit);
        Visit(T->data);
    }
}

//����Ҷ�ӽڵ���
int CountLeaf(BiTree T, int *count)
 {
    if (T)
    {

        if ((T->lchild == NULL) && (T->rchild == NULL))
        {

             count++;
         }
         CountLeaf(T->lchild, count);
         CountLeaf(T->rchild, count);
     }
    return count;    //����Ҷ�ӽڵ���
}
int max(int a, int b)
{
    return a > b ? a : b;
}

//�󸸽ڵ��ֵ ע�ⷵ��ֵΪchar����
char Parent(BiTree T,TElemType e) //���������ڣ�e��T��ĳ���ڵ㣬��eΪ�Ǹ���㣬�򷵻�����˫�ף����򷵻ؿ�
{

     if (T != NULL)
     {
        if ((T->lchild && (T->lchild->data == e)) || (T->rchild && (T->rchild->data == e)))
             return(T->data);
         else
         {
            Parent(T->lchild, e);
             Parent(T->rchild, e);
         }
     }
     return ' ';

 }

 //Ѱ��ĳ���ڵ�
 BiTree FindNode(BiTree T, char e)  //����ָ������ڵ��ָ��
 {
     if (T == NULL)
     {
         return NULL;
     }
     if (T->data == e)
     {
         return T;
     }
    BiTree node;
     if ((node = FindNode(T->lchild, e)) != NULL)
         return node;
     else
         return FindNode(T->rchild, e);
 }

 //���ĳ���ڵ�����ֵ�
 void LeftSibling(BiTree *T, char e)
 {
     char ch = Parent(T, e);
     BiTree tmp = FindNode(T, ch);
     if (tmp->lchild != NULL)
     {
         if (tmp->lchild->data != e)
         {
             printf("�˽ڵ�����ֵ�Ϊ:%c ", tmp->lchild->data);
         }
         else
        {
            printf("�˽ڵ�û�����ֵ� ");
        }
        //return tmp->lchild->data;
    }
    else
    {
        printf("�˽ڵ�û�����ֵ� ");

    }
}

//���ĳ���ڵ�����ֵ�
void RightSibling(BiTree *T, char e)
{
     char ch = Parent(T, e);
     BiTree tmp = FindNode(T, ch);
     if (tmp->rchild != NULL)
     {
        if (tmp->rchild->data != e)
             printf("�˽ڵ�����ֵ�Ϊ:%c \n", tmp->rchild->data);
         //return tmp->rchild->data;
         else
         {
             printf("�˽ڵ�û�����ֵ� ");
         }
     }
     else
    {
        printf("�˽ڵ�û�����ֵ� ");

    }
}
int main()
{
    int CreateBiTree(BiTree T);
    //�ж϶������Ƿ�Ϊ��
int BiTreeEmpty(BiTree *T);
//���������
int BiTreeDepth(BiTree T);
//��ӡ�ڵ�
void Visit(TElemType e);
//�Եݹ���ʽ�������������
void PreOrderTraverse(BiTree T, void(*Visit)(TElemType));
//�Եݹ���ʽ�������������
void InOrderTraverse(BiTree T, void(*Visit)(TElemType));
//�Եݹ���ʽ�������������
void PostOrderTraverse(BiTree T, void(*Visit)(TElemType));
//����Ҷ�ӽڵ���
int CountLeaf(BiTree T, int *count);
//�󸸽ڵ��ֵ ע�ⷵ��ֵΪchar����
char Parent(BiTree T,TElemType e);
 //Ѱ��ĳ���ڵ�
 BiTree FindNode(BiTree T, char e);
  //���ĳ���ڵ�����ֵ�
 void LeftSibling(BiTree *T, char e);
 //���ĳ���ڵ�����ֵ�
void RightSibling(BiTree *T, char e);

}
