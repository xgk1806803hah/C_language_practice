#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int m,s1,s2;

typedef struct
{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTnode,*HFMtree;
typedef char *HFMcode;

void select(HFMtree HT,int n)
{
    int i,j;
    for(i = 1;i <= n;i++)
    if(!HT[i].parent)
    {
        s1=i;
        break;
    }
    for(j = i+1;j <= n;j++)
    if(!HT[j].parent)
    {
        s2 = j;
        break;
    }
    for(i = 1;i <= n;i++)
    if((HT[s1].weight>HT[i].weight)&&(!HT[i].parent)&&(s2!=i))
        s1=i;
    for(j = 1;j <= n;j++)
    if((HT[s2].weight>HT[j].weight)&&(!HT[j].parent)&&(s1!=j))
        s2=j;
}

void HFMcoding(HFMtree HT,HFMcode HC[],int *w,int n)
{
    int i,j,f,start;
    char *cd;
    if(n<=1)
        return;
    m=2*n-1;
    HT=(HFMtree)malloc((m+1)*sizeof(HTnode));
    for (i=1; i<=n; i++)
    {
        HT[i].weight=w[i-1];
        HT[i].parent=HT[i].lchild=HT[i].rchild=0;
    }
    for(i=n+1;i<=m;i++)
    {
        HT[i].weight=HT[i].rchild=HT[i].lchild=HT[i].parent=0;
    }
    printf(" 结点i weight parent lchild rchild\n");
    for (i=1; i<=m; i++)
    printf("\n%4d%8d%8d%8d%8d",i,HT[i].weight,HT[i].parent,HT[i].lchild, HT[i].rchild);
    for (i=n+1; i<=m; i++)
    {
        select(HT, i-1);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
        printf("select: s1=%d s2=%d\n", s1, s2);
        printf(" 结点i weight parent lchild rchild\n");
        for (j=1; j<=i; j++)
        printf("%4d%8d%7d%7d%7d\n",j,HT[j].weight,HT[j].parent,HT[j].lchild,HT[j].rchild);
    }
    cd=(char *)malloc(n*sizeof(char));
    f=m;start=0;
    for(i=1;i<=m;++i)
    HT[i].weight=0;
    while(f)
    {
        if(HT[f].weight==0)
        {
            HT[f].weight=1;
            if(HT[f].lchild!=0)
            {
                f=HT[f].lchild;
                cd[start++]='0';
            }
        else if(HT[f].rchild==0)
        {
            HC[f]=(char *)malloc((start+1)*sizeof(char));
            cd[start]='\0';
            strcpy(HC[f],cd);
        }
        }
    else if(HT[f].weight==1)
    {
        HT[f].weight=2;
        if(HT[f].rchild!=0)
        {
            f=HT[f].rchild;
            cd[start++] ='1';
        }
    }else
    {
        HT[f].weight=0;
        f=HT[f].parent;
        --start;
    }
    }
}
void main()
{
    HFMtree HT;
    HFMcode *HC;
    int *w,n,i;
    system("color 7B");
    puts("输入结点数:");
    scanf("%d",&n);
    HC=(HFMcode *)malloc(n*sizeof(HFMcode));
    w=(int *)malloc(n*sizeof(int));
    printf("输入%d个结点的权值\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    HFMcoding(HT,HC,w,n);
    puts("各结点的哈夫曼编码:\n");
    for(i=1;i<=n;i++)
        printf("%2d(%2d):%s\n",i,w[i-1],HC[i]);
    getchar();
}
