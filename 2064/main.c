#include <stdio.h>
#include <stdlib.h>

int main()
{
    __int64 a[40]={0,2};
    int i,n;
    while(~scanf("%d",&n))
    {
        for(i=2;i<=n;i++)
            a[i]=3*a[i-1]+2;
        printf("%I64d\n",a[n]);
    }
    return 0;
}
