// File Name: a.cpp
// Author: darkdream
// Created Time: 2013年04月16日 星期二 19时38分30秒

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
#include<math.h>
#include<limits.h>
#define MAX 10000000
using namespace std;
int w[1005][1005];
int vis[1005];
int d[1005];
int answer[1005];

struct heihei
{
   int x, y ;
	bool operator  < (const heihei& p) const 
	{
	      if(x == p.x)
			  return y < p.y;
		  else
			  return x < p.x;
	}
};
struct heihei hehe[1005];
int main()
{
  int n,t= 1;
  //freopen("/home/plac/problem/input.txt","r",stdin);
  while(scanf("%d",&n) != EOF)
  {
     int m ;
	 if(n==0)
		 break;
	 scanf("%d",&m);
	  for(int i = 1 ;i <= n; i ++)
		 for(int j = 1; j <= n ; j ++)
	       w[i][j] = MAX;
	  for(int i = 0 ;i < m; i ++)
	  {
		int tempi ,tempj ;
	    scanf("%d %d",&tempi,&tempj);
		int temp;
		scanf("%d",&temp);
		if(temp < w[tempi][tempj])
			w[tempi][tempj]= temp;
		
		w[tempj][tempi] = w[tempi][tempj]; 
	  }
	  /*for(int i = 1;i <= n; i ++)
	  {
		for(int j =1; j <= n;j ++)
		  {
		    printf("%d ",w[i][j]);
		  }
		printf("\n");
	  }*/
	 memset(vis,0,sizeof(vis));
	 for(int i = 1 ;i <= n; i++)
	    d[i] = MAX;
	 d[1] = 0 ;
	 
	 int sum = 0;
	 int max = 0;
	 for(int i = 1 ;i <= n; i++)
	 { 
	    int x;
		int m = MAX;
        for(int y = 1 ;y <= n ;y ++) 
			if(!vis[y] && d[y] <= m)
				m = d[x=y];
		sum += m;
		if(m > max)
			max = m;
		vis[x] = 1;
		for(int y = 1 ;y <= n; y ++) 
			if( w[x][y] < d[y] || d[y] == MAX)
			{
			  d[y] = w[x][y];
			  hehe[y].x = x;
			  hehe[y].y = y;
			}
	 }
	 //sort(hehe+1,hehe+n+1);


     printf("%d\n",max);
     printf("%d\n",sum);
	 for(int i = 2; i<= n;i ++)
		 printf("%d %d\n",hehe[i].x,hehe[i].y);
   }
  return 0;
}
