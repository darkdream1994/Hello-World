// File Name: f.c
// Author: darkdream
// Created Time: 2013年04月19日 星期五 12时12分20秒
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int w[105][105];
int visit[105];
long long d[105];
int main()
{
	int n ;
    freopen("/home/plac/problem/input.txt","r",stdin);

	while(scanf("%d",&n) != EOF)
	{
		
		memset(w,0,sizeof(w));
		memset(visit,0,sizeof(visit));
		for(int i = 1; i <= n; i ++)
			for(int j =  1; j <= n; j ++)
				scanf("%d",&w[i][j]);//输入矩阵	
		for(int i = 1;i <= n; i ++)
			d[i] = INT_MAX;		


		int k;
		scanf("%d",&k);
		if(k == 0)
			d[1] = 0;
		else
			for(int i = 1;i <= k ; i++)
			{
				int a ,b ;
				scanf("%d %d",&a,&b);
				if(a == b)
					continue;
				visit[a] = 1;	
				for(int i= 1;i <= n ;i ++)
				{
					if(d[i] > w[a][i])
						d[i] = w[a][i];
				}
				a = b;
				visit[a] = 1;	
				for(int i= 1;i <= n ;i ++)
				{
					if(d[i] > w[a][i])
						d[i] = w[a][i];
				}

			}//update the first

		int sum =0;
		for(int i = 1;i <= n; i ++)
	    	printf("%d ",visit[i]);

		for(int i =1;i <= n ;i ++)
		{
			int ok = 1;
			for(int j = 1;j <= n; j++)
				if(visit[j] == 0)
					ok = 0;
			if(ok == 1)
				break;
			int m = INT_MAX;
			int x;
			for(int j = 1; j <= n; j ++)
				if(d[j] <= m && visit[j] == 0)
					m = d[x = j];
			sum += m;
			visit[x] = 1;
			for(int j = 1;j <= n; j ++)
			{
				if(d[j] > w[x][j])
					d[j] = w[x][j];
			}


		}
		printf("%d\n",sum);
	}
	return 0 ;
}


