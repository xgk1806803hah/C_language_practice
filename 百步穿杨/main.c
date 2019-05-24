#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,temp;
    int a[50],b[50];
    scanf("%d",&t);
    while(t--)
        {
            scanf("%d",&n);
            for(int i=0;i<n;i++)
                {
                    scanf("%d%d",&a[i],&b[i]);
                }
                for(int i=0;i<n-1;i++)
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(a[i]>a[j])
                        {
                            temp=a[i]; a[i]=a[j]; a[j]=temp;
                            temp=b[i]; b[i]=b[j]; b[j]=temp;
                        }
                    }
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<b[i];j++)
                    {
                        printf(">+");
                        for(int k=0;k<a[i]-2;k++)
                        {
                            printf("-");
                        }
                        printf("+>\n");
                    }
                    printf("\n");
                }
            }
        return 0;
}
