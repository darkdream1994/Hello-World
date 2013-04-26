// File Name: d.cpp
// Author: darkdream
// Created Time: 2013年04月25日 星期四 00时16分20秒

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
struct point
{
  double x, y, z,r;
};
struct point points[105];
int p[105];
double w[10005];
int  v[10005];
int  u[10005];  
int  r[10005];
int cmp(const int i, const int j)
{
   return w[i] < w[j];
}
double dis(int i , int j )
{
    return sqrt(pow(points[i].x-points[j].x,2.0)+pow(points[i].z-points[j].z,2.0)+pow(points[i].y-points[j].y,2.0));
}
int find(int x)
{
  return p[x] == x? x:p[x] = find(p[x]);
}
int main(){
  int n ;
  //freopen("/home/plac/problem/input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  while(scanf("%d",&n) != EOF)
  {
	memset(p,0,sizeof(p));
	memset(v,0,sizeof(v));
	memset(u,0,sizeof(u));
	memset(r,0,sizeof(r));
	memset(w,0,sizeof(w));
	memset(points,0,sizeof(points));
	if(n == 0)
		break;
    for(int i =1 ;i <= n;i ++)
	{
	  scanf("%lf %lf %lf %lf",&points[i].x,&points[i].y,&points[i].z,&points[i].r);
	}
	for(int i =1 ;i <= n;i ++)
		p[i] = i ;
	int m = 0 ;
	for(int i =1 ;i <= n; i++)
		for(int j = i+1 ;j <= n ;j ++ )
		{
		if(dis(i,j) > (points[i].r + points[j].r))
		   {
		      v[++m] = i ;
			  u[m] = j;
			  w[m] = dis(i,j) - points[i].r - points[j].r;
		   }
		   else
		   {
		//	printf("%d %d\n",i,j);
		     /*v[++m] = i;
			 v[m] = j;
			 w[m] = 0.0;*/
			 int x = find(i);
			 int y = find(j);
			 if(x != j)
				 p[x] = y;
		   }
              
		}
	//for(int i=1 ;i <= n;i ++)
	//	printf("%d ",p[i]);
	//printf("%lf\n",dis(3,4));
	//printf("%d %d\n",v[439],u[439]);
	for(int i =1;i <= m;i ++)
		r[i] = i;
    sort(r+1,r+m+1,cmp);
	double ans = 0.000 ;
	for(int i = 1;i <= m;i ++)
	{
	  int e = r[i];
	  int x = find(v[e]);
	  int y = find(u[e]);
	  if(x != y)
	  {
	//	 printf("%d %d %d\n",e,v[e],u[e]);
	     ans += w[e];
		 p[x] = y ;
	  }
	}
	printf("%.3f\n",ans);
  }
return 0;
}
