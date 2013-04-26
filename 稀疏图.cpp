// File Name: 稀疏图.cpp
// Author: darkdream
// Created Time: 2013年04月18日 星期四 19时14分00秒

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
#define MAXN  1005
using namespace std;

int main(){
int n , m ;
int first[MAXN];
int u[MAXN],v[MAXN],w[MAXN],next[MAXN];
  scanf("%d %d",&n,&m);
  memset(first,-1,sizeof(first));
    for(int e = 1 ;e <= m ;e ++)
	{
	  scanf("%d %d %d",&u[e],&v[e],&w[e]);
	  next[e] = first[u[e]];
	  first[u[e]] = e;
	}
	for(int i = 1 ;i <= m; i ++)
		printf("%d %d\n",next[i],first[i]);
  return 0;
}
