#include <stdio.h>
#include <stdlib.h>
#define n 6
#define MaxNum 10000  /*����һ���������*/

/*�����ڽӾ�������*/
typedef int adjmatrix[n+1][n+1];   /*0�ŵ�Ԫû��*/

typedef struct
{
	int fromvex,tovex;
	int weight;
}Edge;
typedef Edge *EdgeNode;

int arcnum;     /*�ߵĸ���*/

/*����ͼ���ڽӾ���*/
void CreatMatrix(adjmatrix GA)
{
	int i,j,k,e;
	printf("ͼ����%d������\n",n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				GA[i][j]=0;         /*�Խ��ߵ�ֵ��Ϊ0*/
			}
			else{
				GA[i][j]=MaxNum;    /*����λ�õ�ֵ�ó�ʼ��Ϊһ���������*/
			}
		}
	}
	printf("������ߵĸ�����");
	scanf("%d",&arcnum);
	printf("������ߵ���Ϣ��������㣬�յ㣬Ȩֵ����ʽ���룺\n");
	for(k=1;k<=arcnum;k++){
		scanf("%d,%d,%d",&i,&j,&e);  /*����ߵ���Ϣ*/
		GA[i][j]=e;
		GA[j][i]=e;
	}
}

/*��ʼ��ͼ�ı߼�����*/
void InitEdge(EdgeNode GE,int m)
{
	int i;
	for(i=1;i<=m;i++)
    {
		GE[i].weight=0;
	}
}

/*����ͼ���ڽӾ�������ͼ�ı߼�����*/
void GetEdgeSet(adjmatrix GA,EdgeNode GE)
{
	int i,j,k=1;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(GA[i][j]!=0&&GA[i][j]!=MaxNum)
            {
				GE[k].fromvex=i;
				GE[k].tovex=j;
				GE[k].weight=GA[i][j];
				k++;
			}
		}
	}
}

/*����������ͼ�ı߼�����*/
void SortEdge(EdgeNode GE,int m)
{
	int i,j,k;
	Edge temp;
	for(i=1;i<m;i++)
    {
		k=i;
		for(j=i+1;j<=m;j++)
		{
			if(GE[k].weight>GE[j].weight)
            {
				k=j;
			}
		}
		if(k!=i)
		{
			temp=GE[i];GE[i]=GE[k];GE[k]=temp;
		}
	}
}

/*��������ķ�㷨�ӳ�ʼ��v�������ڽӾ����ʾ��ͼ����С������*/
void Prim(adjmatrix GA,EdgeNode T)
{
	int i,j,k,min,u,m,w;
	Edge temp;
	/*��T����ֵ����ӦΪv1���ε����������ı�*/
	k=1;
	for(i=1;i<=n;i++)
    {
		if(i!=1)
		{
			T[k].fromvex=1;
			T[k].tovex=i;
			T[k].weight=GA[1][i];
			k++;
		}
	}
	/*����n-1��ѭ����ÿ�������С�������еĵ�k����*/
	for(k=1;k<n;k++)
	{
		min=MaxNum;
		m=k;
		for(j=k;j<n;j++)
		{
			if(T[j].weight<min)
			{
				min=T[j].weight;m=j;
			}
		}
		/*����̱߶Ե���k-1�±�λ��*/
		temp=T[k];
		T[k]=T[m];
		T[m]=temp;
		/*���¼�����С������T�еĶ�����Ÿ���j*/
		j=T[k].tovex;
		/*�޸��йرߣ�ʹT�е�T���ÿһ�����㱣��һ����ĿǰΪֹ��̵ı�*/
		for(i=k+1;i<n;i++)
		{
			u=T[i].tovex;
			w=GA[j][u];
			if(w<T[i].weight)
			{
				T[i].weight=w;T[i].fromvex=j;
			}
		}
	}
}

/*����߼������ÿ����*/
void OutEdge(EdgeNode GE,int e)
{
	int i;
	printf("������㣬�յ㣬Ȩֵ����ʽ�������С������Ϊ��\n");
	for(i=1;i<=e;i++)
    {
		printf("%d,%d,%d\n",GE[i].fromvex,GE[i].tovex,GE[i].weight);
	}
}

void main()
{
	adjmatrix GA;
	Edge GE[n*(n-1)/2],T[n];
	CreatMatrix(GA);
	InitEdge(GE,arcnum);
	GetEdgeSet(GA,GE);
	SortEdge(GE,arcnum);
	Prim(GA,T);
	printf("\n");
	OutEdge(T,n-1);
}
