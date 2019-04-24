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

//创建二叉树
int CreateBiTree(BiTree T)
{
    printf("请输入树的节点：");
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

//判断二叉树是否为空
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
//求树的深度
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

//打印节点
void Visit(TElemType e)
{
    printf("%c", e);
}

//以递归形式先序遍历二叉树
void PreOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
    if (T)
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
}
//以递归形式中序遍历二叉树
void InOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
    if (T)
    {
        InOrderTraverse(T->lchild, Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild, Visit);
    }
}

//以递归形式后序遍历二叉树
void PostOrderTraverse(BiTree T, void(*Visit)(TElemType))
{
    if (T)
    {
        PostOrderTraverse(T->lchild, Visit);
        PostOrderTraverse(T->rchild, Visit);
        Visit(T->data);
    }
}

//计算叶子节点数
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
    return count;    //返回叶子节点数
}
int max(int a, int b)
{
    return a > b ? a : b;
}

//求父节点的值 注意返回值为char类型
char Parent(BiTree T,TElemType e) //二叉树存在，e是T中某个节点，若e为非根结点，则返回它的双亲，否则返回空
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

 //寻找某个节点
 BiTree FindNode(BiTree T, char e)  //返回指向这个节点的指针
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

 //输出某个节点的左兄弟
 void LeftSibling(BiTree *T, char e)
 {
     char ch = Parent(T, e);
     BiTree tmp = FindNode(T, ch);
     if (tmp->lchild != NULL)
     {
         if (tmp->lchild->data != e)
         {
             printf("此节点的左兄弟为:%c ", tmp->lchild->data);
         }
         else
        {
            printf("此节点没有左兄弟 ");
        }
        //return tmp->lchild->data;
    }
    else
    {
        printf("此节点没有左兄弟 ");

    }
}

//输出某个节点的右兄弟
void RightSibling(BiTree *T, char e)
{
     char ch = Parent(T, e);
     BiTree tmp = FindNode(T, ch);
     if (tmp->rchild != NULL)
     {
        if (tmp->rchild->data != e)
             printf("此节点的右兄弟为:%c \n", tmp->rchild->data);
         //return tmp->rchild->data;
         else
         {
             printf("此节点没有右兄弟 ");
         }
     }
     else
    {
        printf("此节点没有右兄弟 ");

    }
}
int main()
{
    int CreateBiTree(BiTree T);
    //判断二叉树是否为空
int BiTreeEmpty(BiTree *T);
//求树的深度
int BiTreeDepth(BiTree T);
//打印节点
void Visit(TElemType e);
//以递归形式先序遍历二叉树
void PreOrderTraverse(BiTree T, void(*Visit)(TElemType));
//以递归形式中序遍历二叉树
void InOrderTraverse(BiTree T, void(*Visit)(TElemType));
//以递归形式后序遍历二叉树
void PostOrderTraverse(BiTree T, void(*Visit)(TElemType));
//计算叶子节点数
int CountLeaf(BiTree T, int *count);
//求父节点的值 注意返回值为char类型
char Parent(BiTree T,TElemType e);
 //寻找某个节点
 BiTree FindNode(BiTree T, char e);
  //输出某个节点的左兄弟
 void LeftSibling(BiTree *T, char e);
 //输出某个节点的右兄弟
void RightSibling(BiTree *T, char e);

}
