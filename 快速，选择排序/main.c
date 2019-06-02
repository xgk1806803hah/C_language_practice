#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
	int key[MAX+1];
	int length;
}Sqlist;
typedef struct Sqlist
{
    int low;
    int high;
};

int Partition(Sqlist *L,int low,int high)
{
	int p;
	L->key[0]=L->key[low];
	p=L->key[low];
	while(low<high)
	{
		while(low<high&&L->key[high]>=p) high--;
		L->key[low]=L->key[high];
		while(low<high&&L->key[low]<=p) low++;
		L->key[high]=L->key[low];
	}
	L->key[low]=L->key[0];
	return low;
}

void QSort(Sqlist *L,int low,int high)
{
	int p;
	if(low<high)
	{
		p=Partition(L,low,high);
		QSort(L,low,p-1);
		QSort(L,p+1,high);
	}
}

void QuickSort(Sqlist *L)//��������
{
	QSort(L,1,6);
}

void push(Sqlist *L)//���
{
    int i;
    for(i=0;i<7;i++)
    {
        printf("%d\n",L->key[i]);
    }
}

void SelectSort(Sqlist *L)//ѡ������
{
    int i,k,j,t;
    for(i=0;i<6;i++)
    {
        k=i;
        for(j=i+1;j<=6;j++)
            if(L->key[j]<L->key[k])
                k=j;
            if(k!=i)
            {
                t=L->key[i];L->key[i]=L->key[k];L->key[k]=t;
            }
    }
}

int main()
{
    struct Sqlist L[7]={49,38,65,97,76,13,27};
    int Partition(Sqlist *L,int low,int high);
    void QSort(Sqlist *L,int low,int high);
    void QuickSort(Sqlist *L);
    void SelectSort(Sqlist *L);
    void push(Sqlist *L);
    //QuickSort(L);
    SelectSort(L);
    push(L);
    return 0;
}
