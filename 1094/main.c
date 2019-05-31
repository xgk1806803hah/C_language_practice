#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n;
    int a,sum=0;
    while(scanf("%d",&T)!=EOF)
    {
        while(scanf("%d",&n)!=EOF)
        {
            int i=0;
            for(i;i<n;i++)
            {
                scanf("%d",&a);
                sum+=a;
            }
            printf("%d\n",sum);
            sum=0;
            T--;
            if(T!=0)
            {
                printf("\n");
            }
        }
    }
    return 0;
}
