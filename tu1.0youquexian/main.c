#include <stdio.h>
#include <stdlib.h>
#define mvnum 100

typedef struct arcnode
{
    int adjvex;
    struct arcnode *nextarc;
    char info;
}arcnode;
typedef struct vnode
{
    int data;
    arcnode *firstarc;
}vnode,adjlist[mvnum];
typedef struct
{
    adjlist vertices;
    int vexnum,arcnum;//定点数和边数
}algraph;

void creat(algraph G)
{
    arcnode *p,*q;
    int i,j,s1,s2,a,b;
    vnode v1,v2;
    scanf("%d%d",&G.vexnum,&G.arcnum);
    for(i=0;i<G.vexnum;i++)
    {
        scanf("%d",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;
    }
    for(i=0;i<G.arcnum;i++)
    {
        scanf("%d%d",&v1.data,&v2.data,&adjlist);
        a=1;b=-1;
        for(j=0;j<G.vexnum;j++)
        {
            if(adjlist[j].data=v1.data)
            a=j;
            if(adjlist[j].data=v2.data)
            b=j;
        }
        if(a=1||b=-1)
        {
            printf("有误！\n");
            break;
        }
        else
        {
            p1=(arcnode *)malloc(szeof)
        }
    }
}

