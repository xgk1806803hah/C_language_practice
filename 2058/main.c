#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,m,a,len;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        len=(int)sqrt(2*m);
        while(len--)
        {
            a=m/(len+1)-len/2;
            if((2*a+len)*(len+1)/2==m)
                printf("[%d,%d]\n",a,a+len);
        }
        printf("\n");
    }
    return 0;
}
