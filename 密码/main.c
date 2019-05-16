#include<stdio.h>
#include<string.h>

int main()
{
 int M,i,t,a,b,c,d,sum;
 char s[60];
 while(scanf("%d",&M)!=EOF)
 {
  while(M--)
  {
   scanf("%s",s);
   t=strlen(s);
   if(t<8||t>16)
   {
    printf("NO\n");
    continue;
   }
   a=b=c=d=sum=0;
   for(i=0;s[i]!='\0';i++)
   {
    if(s[i]>='A'&&s[i]<='Z')a=1;
    else if(s[i]>='a'&&s[i]<='z')b=1;
    else if(s[i]>='0'&&s[i]<='9')c=1;
    else if(s[i]=='~'||s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='^')d=1;
   }
   sum=a+b+c+d;
   if(sum>=3)
    printf("YES\n");
   else
    printf("NO\n");
  }
 }
 return 0;
}
