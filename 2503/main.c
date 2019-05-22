#include <stdio.h>
#include <stdlib.h>

int yue(int m,int n)
{
   int tmp;
   while(n)
   {
       tmp=m;
       m=n;
       n=tmp%n;
   }
   return m;
}

int main()
{
    int a,b,c,d;
    int t,m,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        m=a*d+b*c;
        n=b*d;
        k=yue(m,n);
        printf("%d %d\n",m/k,n/k);
    }
    return 0;
}
