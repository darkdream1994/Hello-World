// File Name: f1.cpp
// Author: darkdream
// Created Time: 2013年04月23日 星期二 18时24分48秒

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
//int set[105];
int a[105][105];
int w[10005];
int p[10005];
int u[10005];
int v[10005];
int r[10005];
int find(int x)
{
   return p[x] == x? x :p[x] = find(p[x]); 
}
int cmp(const int i , const int j ) {
  return w[i] < w[j];
}
int main(){
   int n;
   freopen("/home/plac/problem/input.txt","r",stdin);
   while(scanf("%d",&n) != EOF)
   {
	  memset(a,0,sizeof(a));
	  memset(w,0,sizeof(w));
	  memset(p,0,sizeof(p));
	  memset(u,0,sizeof(u));
	  memset(v,0,sizeof(v));
	  memset(r,0,sizeof(r));

      for(int i =1 ;i <= n;i ++)
		  for(int j = 1;j <= n;j ++)
			  scanf("%d",&a[i][j]);
	  int q ;
	  scanf("%d",&q);
	  for(int i =1; i<= n;i ++)
		  p[i] = i;
  
	  for(int i = 1;i <= q; i ++)
	  {
	     int tempa,tempb;
		 scanf("%d %d",&tempa,&tempb);
		 if(tempa == tempb)
			 continue;
		 //find(tempa);
	     if(find(tempa) != find(tempb))
		    {
			   p[find(tempb)] = find(tempa);
			}
		 //find(tempa);
   	  //for(int i = 1;i <= n;i ++)
		//  printf("%d ",p[i]);
	  //printf("\n");
	  }
	  int s = 0 ;
	  for(int i =2 ;i <= n; i ++)
	    for(int j = 1;  j < i; j ++)
	    {
	      v[++s] = i;
		  u[s] = j;
		  w[s] = a[i][j];
		}
	  //printf("%d************ %d\n",v[117],u[117]);
	  for(int k = 1 ;k <= s; k++)
	  { 
		  r[k] = k ;
	  }
	  sort(r+1,r+s+1,cmp);
	  //for(int i = 1;i <= s;i ++)
	    //  printf("%d %d %d %d\n",r[i],v[r[i]],u[r[i]],w[r[i]]);
	  //printf("%d************ %d\n",v[117],u[117]);
	  int ans = 0;
	  for(int i = 1;i <= s; i ++)
	  {
	      int e = r[i];
		  
		  int x = find(u[e]) ; int y = find(v[e]);
		  if(x != y) {ans += w[e]; p[x] = y;
			 // printf("%d %d %d\n",e,v[e],u[e]);
			  //for(int j = 1;j <= n; j ++ )
		        //printf("%d ",p[j]);
			  //printf("\n");
		  }
	  }
	  printf("%d\n",ans);
   }
return 0;
}
