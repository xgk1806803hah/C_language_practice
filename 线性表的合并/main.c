#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data[205];
    int lenth;
}La, Lb, Lc;

int main()
{
    int n, m, i, j;
    int ans = 0;
    while(scanf("%d", &m) != EOF)
    {
        for(i = 0; i < m; i++)
        {
            scanf("%d", &La.data[i]);
        }
        La.lenth = m;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &Lb.data[i]);
        }
        Lb.lenth = n;
        int k = 0;
        Lc.lenth = 0;
        i = 0; j = 0;
        while(i != La.lenth && j != Lb.lenth)
        {
            if(La.data[i] <= Lb.data[j])
            {
                Lc.data[k] = La.data[i];
                i++;
                k++;
                Lc.lenth++;
            }
            else
            {
                Lc.data[k] = Lb.data[j];
                j++;
                k++;
                Lc.lenth++;
            }
        }
        if(i != La.lenth)
        {
            for(i; i < La.lenth; i++)
            {
                Lc.data[k] = La.data[i];
                k++;
                Lc.lenth++;
            }
        }
        if(j != Lb.lenth)
        {
            for(j; j < Lb.lenth; j++)
            {
                Lc.data[k] = Lb.data[j];
                k++;
                Lc.lenth++;
            }
        }
        int l;
        for(l = 0; l < Lc.lenth; l++)
        {
            if(l != 0)
                printf(" ");
            printf("%d", Lc.data[l]);
        }
        printf("\n");
    }
    return 0;
}
