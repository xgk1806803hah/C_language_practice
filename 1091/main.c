#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,a,s=0;
    while(scanf("%d",&N)&&N!=0)
        {
                for(i=0;i<N;i++)
                {
                    scanf("%d",&a);
                    s+=a;
                }
            printf("%d\n",s);
            s=0;
        }
    return 0;
}
