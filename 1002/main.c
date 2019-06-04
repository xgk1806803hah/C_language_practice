#include<stdio.h>
#include<string.h>
#define N 1010
#define max(x,y) (x>y?x:y)
int main()
{
  char a1[N]={0};
  char b1[N]={0};
  int a2[N]={0},b2[N]={0};
  int num;
  scanf("%d",&num);
  for(int i=1; i<=num; i++)
    {
    scanf("%s %s",a1,b1);
    int n1 = strlen(a1);
    int m1;
    for(int j=0; j<n1;j++)
    {
        if(a1[j]!='0'&&a1[j]!=NULL)
        {
            m1=j;
            break;
        }else if(a1[j]=='0'&& j==n1-1)
        {
           m1=0;
           n1=1;
           break;
        }
    }
    int n2 = strlen(b1);
    int m2;
    for(int j=0; j<n2;j++)
    {
        if(b1[j]!='0'&&b1[j]!=NULL)
        {
            m2=j;
            break;
        }
        else if(b1[j]=='0'&& j==n2-1)
        {
           m2=0;
           n2=1;
           break;
        }
    }
    int k;
    for(int j=n1-1,k=0; j>=m1; j--,k++)
    {
       a2[k] = a1[j]-'0';
    }
    for(int j=n2-1,k=0; j>=m2; j--,k++)
    {
       b2[k] = b1[j]-'0';
    }
    int digit = max(n1-m1,n2-m2);
    int c2[N]={0};
    int t=0;
    for(int j=0; j<digit; j++)
    {
        c2[j] = a2[j] + b2[j] + t;
        t = c2[j]/10;
        c2[j]= c2[j]%10;
    }
    if(t>0)
    {
        c2[digit]=t;
        digit++;
    }
    printf("Case %d:\n", i );
    for(int j=m1;j<n1;j++)
    {
       printf("%c",a1[j]);
    }
    printf(" + ");
    for(int j=m2;j<n2;j++)
    {
       printf("%c",b1[j]);
    }
    printf(" = ");
    for(int j=digit-1;j>=0;j--)
    {
       printf("%d",c2[j]);
    }
    if(i!=num)
    {
        printf("\n\n");
    }
    else
    {
        printf("\n");
    }
    for(int j=0;j<=digit;j++)
    {
        a2[j]=b2[j]=0;
    }
  }
}
