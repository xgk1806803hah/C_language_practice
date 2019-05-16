#include <stdio.h>
#include <stdlib.h>

int main()
{
     int m,A,B,s1,s2;
    int a[1000],b[1000],i,j,x,y;
    s1=0;s2=0;x=0;y=0;
    scanf("%d\n",&m);
    while(m--)
    {
        scanf("%d %d",&A,&B);
        for(i=1;i<A;i++)
            if(A%i==0)
        {
            a[x]=i;x++;
        }
        for(j=1;j<B;j++)
            if(B%j==0)
        {
            b[y]=j;y++;
        }
        for(i=0;i<=x;i++)
            s1=s1+a[i];
        for(j=0;j<=y;j++)
            s2=s2+b[j];
        if(s1==B||s2==A)
            printf("YES\n");
            else
            printf("NO\n");
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int n;
    int x,y,t,sum,i;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        scanf("%d%d",&x,&y);
        if(x>y)
        {
            t=x;
            x=y;
            y=t;
        }
        for(i=1;i<=y/2;i++)
            if(y%i==0)
                sum+=i;
        if(sum==x)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
