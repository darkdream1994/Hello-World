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

using namespace std;
struct point{
  double x, y ;
};
struct point points[105];
double w[105][105];
double  dis(int i ,int  j )
{
   double tempx = points[i].x - points[j].x;
   double tempy = points[i].y - points[j].y;
   
   return sqrt(tempx*tempx + tempy*tempy);
}
int vis[105];
double d[105];
int main()
{
  int n,t= 1;; 
  while(scanf("%d",&n) != EOF)
  {
	 if (n == 0 )
		 break;
     for(int i = 0 ;i < n ;i ++)
		 scanf("%lf %lf",&points[i].x,&points[i].y);
     for(int i = 0 ;i < n; i ++)
		 for(int j = 0; j < n ; j ++)
			 w[i][j] = dis(i,j);
	 memset(vis,0,sizeof(vis));
	 for(int i = 0 ;i < n; i++)
		 d[i] = 100000000000;
	 d[0] = 0 ;
	 double sum = 0;
	 for(int i = 0 ;i < n; i++)
	 { 
	    int x;
		double m = 10000000000000;
        for(int y = 0 ;y < n ;y ++) if(!vis[y] && d[y] <= m) m = d[x=y];
		sum += m;
		vis[x] = 1;
		for(int y = 0 ;y < n; y ++) 
		d[y] = 	d[y] < w[x][y]?d[y]:w[x][y];
	 }
	 if(t > 1)
		 printf("\n");
		printf("Case #%d:\nThe minimal distance is: %.2lf\n",t++,sum);
        
   }
  return 0;
}


