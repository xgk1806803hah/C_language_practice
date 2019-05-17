#include <stdio.h>
#include <stdlib.h>

int main()
{
    __int64 a,s;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%I64d",&a);
        s=1+2*a*a-a;
        printf("%I64d\n",s);
    }
    return 0;
}
