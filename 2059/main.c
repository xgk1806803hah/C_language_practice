#include <stdio.h>
#include <stdlib.h>

int main()
{
	int L, N, C, T, VR, VT1, VT2, p[105];
	double tr, time;
	double dp[1005];
	while (~scanf("%d",&L))
	{
		memset(p, 0, sizeof(p));
		scanf("%d%d%d",&N,&C,&T);
		scanf("%d%d%d",&VR,&VT1,&VT2);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d",&p[i]);
		}
		p[N + 1] = L;
		dp[0] = 0;
		tr = L*1.0 / VR;
		for (int i = 1; i <= N+1; i++)
		{
			double Min = 99999999;
			for (int j = 0; j < i; j++)
			{
				int x = p[i] - p[j];
				if (C >= x)
				{
					time = x*1.0 / VT1;
				}
				else
				{
					time = C*1.0 / VT1 + (x - C)*1.0 / VT2;
				}
				if (j )time += T;
				if (Min> dp[j] + time)
				{
					Min = dp[j] + time;
				}
			}
			dp[i] = Min;
		}
		if (dp[N+1]>tr)
			printf("Good job,rabbit!\n");
		else
			printf("What a pity rabbit!\n");
	}
	return 0;
}
