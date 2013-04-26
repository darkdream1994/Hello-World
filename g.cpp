// File Name: g.cpp
// Author: darkdream
// Created Time: 2013年04月25日 星期四 01时11分49秒

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
int p[1000];
int c[1000];
int w[1000005];
int v[1000005];
int u[1000005];
int r[1000005];
int d[1005][1005];
using namespace std;

int find(int x)
{
  return p[x] == x? x:p[x] = find(p[x]);
}
int cmp(const int i , const int j)
{
  return w[i] < w[j];
}
int main(){
    int t;
	scanf("%d",&t);
	while(t--)
	{
		int n ;
	     scanf("%d",&n);
		 for(int i =1;i <= n;i ++)
			 scanf("%d",&c[i]);
		 for(int i =1 ;i <= n;i ++)
			 for(int j =1;j <= n; j ++)
			 {
			   scanf("%d",&d[i][j]);
			 }
		 int m = 0;
		 for(int i = 2;i <= n; i ++)
			 for(int j =1 ; j< i;j ++)
			 {
			      v[++m] =i ;
				  u[m] = j;
				  w[m] = c[i] +c[j] + d[i][j];
			 }
		 for(int i = 1;i <= n;i ++)
			 p[i] = i;
		for(int i = 1 ;i <= m; i ++)
             r[i] = i;
		sort(r+1,r+m+1,cmp);
		int ans = 0;
		for(int i =1;i <= m; i ++)
		{
		  int e = r[i];
		  int x = find(v[e]);
		  int y = find(u[e]);
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
