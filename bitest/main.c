#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,s;
    int a[500],n;
    while(scanf("%d",&n)!=EOF)
    {
        s=0;
        for(i=0;n!=0;i++)
        {
            a[i]=n%2;
            s++;
            n=n/2;
        }
        for(i=s-1;i>-1;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
