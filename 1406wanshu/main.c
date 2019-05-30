#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,j;
    int t,s,n,m;
    scanf("%d",&t);
    while(t--)
    {
        n=0;
        scanf("%d %d",&a,&b);
        if(a>b)
        {
            m=a;a=b;b=m;
        }
        for(i=a;i<=b;i++)
        {
            s=0;
            for(j=1;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    s+=j;
                }
                if(s==i&&j==i/2)
                {
                    n=1;
                    break;
                }
            }
        }
        printf("%d\n",n);
    }
    return 0;
}

