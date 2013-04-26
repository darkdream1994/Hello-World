// File Name: c.cpp
// Author: darkdream
// Created Time: 2013年04月24日 星期三 22时43分39秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

int p[100005];
int v[100005];
int u[100005];
int r[100005];
int w[100005];
int find(int x)
{
	return  p[x] == x? x:p[x] =find(p[x]);
}
int cmp(const int i, const int j )
{
	return w[i] < w[j];
}
char str[100];
int main(){
	int n ;
	while(scanf("%d",&n) !=  EOF)
	{
		
		memset(p,0,sizeof(p));
		memset(r,0,sizeof(r));
		memset(v,0,sizeof(v));
		memset(u,0,sizeof(u));
		memset(w,0,sizeof(w));
		if(n == 0 )
			break;
		int m = 0;
		for(int s = 1;s <n; s++)
		{  
			char c;
			int k ;
			scanf("%s",str);
			c = str[0];
			scanf("%d",&k);
			for(int i = 1;i <= k ; i ++)
			{
				char tempc;
				int temp;
				scanf("%s",str);
				tempc = str[0];
			    scanf("%d",&temp);
				v[++m] = c-'A' +1;
				u[m] = tempc -'A'+1;
                w[m] = temp;
				
			}
		
		}
		//for(int i =1;i <= m ;i ++)
		//	printf("%d %d\n",v[i],u[i]);
		for(int i = 1;i <=n ;i ++)
			p[i] = i ;
		for(int i = 1 ;i <= m  ;i ++)
			r[i] = i ;
		sort(r+1,r+m+1,cmp);
	//	for(int i =1 ;i <= m; i ++)
	//		printf("%d\n",r[i]);
		int ans = 0;
		for(int i =1 ;i <= m;i ++)
		{
		   int e = r[i];
		   int x = find(v[e]); int y = find(u[e]);
		   //int x = 0 , y = 0;
		   if(x != y)
		   {
		     ans += w[e];
			 p[x] = y;
		   }
		}
		printf("%d\n",ans);
	}

	return 0;
}
