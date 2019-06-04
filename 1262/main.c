#include <stdio.h>
#include <math.h>
int isPrime(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {    if(a%i==0)
        {    break;
        }
    }
    if(i>sqrt(a))
        return 1;
    else
        return 0;
}

int main()
{
    int m,i;
    while(scanf("%d",&m)!=EOF)
    {
        for(i=m/2;i>=2;i--)
        {
            if( isPrime(i) && isPrime(m-i) )
            {
                printf("%d %d\n",i,m-i);
                break;
            }
        }
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
#define N 8000

int s[N];
int main()
{
  int i,j,k,t,n;
  while(scanf("%d",&n)!=EOF)
    {

     memset(s,0,sizeof(s));
     s[0]=1;
     for(i=2;i<=n;i++)
     {
       for(j=0,t=0;j<N;j++)
       {
          k=s[j]*i+t;
          t=k/100000;
          s[j]=k%100000;
       }
     }
     for(i=N-1;!s[i];i--);
     printf("%d",s[i]);
     while(i)
        printf("%05d",s[--i]);
     printf("\n");
  }
  return 0;
}
