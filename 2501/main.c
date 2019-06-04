#include <stdio.h>
#include <stdlib.h>

int main()
{
    __int64 i,a[55],n,s;
    scanf("%I64d",&s);
    while(s--)
    {
        scanf("%I64d",&n);
        a[0]=0;
        a[1]=1;
        a[2]=3;
        for(i=3;i<=50;i++)
            a[i]=a[i-1]+2*a[i-2];
        printf("%I64d\n",a[n]);
    }
    return 0;
}
