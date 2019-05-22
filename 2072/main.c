#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    while(gets(s),s[0]!='#')
    {
        char c[100][100]={0};
        int i,j,k,flag=1;
        for(i=0,j=0,k=0;i<strlen(s);i++)
        {
            if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
            {
                if(flag==1)
                    j++;
                c[j][k]=s[i];
                k++;
                flag=0;
            }
            else
            {
                flag=1;
                k=0;
            }
        }
        int z,l,sum=0;
        for(i=1,sum=0;i<=j;i++)
        {
            z=0;
            for(k=0;k<i;k++)
            {
                if(strcmp(c[i],c[k])==0)
                z=1;
            }
            if(z==0)
                sum++;
        }
        if(s[0]=='\0')
            printf("0\n");
        else
            printf("%d\n",sum);
        memset(s,0,sizeof(char)*(strlen(s)));
    }
    return 0;
}
