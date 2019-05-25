#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
}elemtype;
typedef struct
{
    elemtype *T;
    int lenght;
}ss;
int main()
{
    int search(ss T,int key);
    int T[11]={5,16,20,27,3,36,44,55,60,67,71};
    int key
    search(T,key)
    return 0;
}
int search(ss T,int key)
{
	int i,low,high,mid;
	low=0;
	high=T.length-1;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(T.a[mid]==key)
			return mid;
		else
			if(T.a[mid]>key)
				high=mid-1;
			else
				low=mid+1;
	}
	return 0;
}
