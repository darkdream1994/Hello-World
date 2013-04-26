// File Name: 表达式树.c
// Author: darkdream
// Created Time: 2013年04月18日 星期四 19时37分36秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
const int maxn = 1000;
int lch[maxn] , rch[maxn];
char op[maxn];
int nc = 0;
int build_tree(char *s,int x,int y)
{   
	//printf("%d****%d\n",x,y);
    int i , c1 =-1, c2 = -1, p =0;
	int u ;
	if(y - x == 1)
	{
	  u = ++nc;
	  lch[u] = rch[u] = 0 ;
	  op[u] = s[x];
	  return u ;
	}
	for(int i = x; i < y ; i++)
	{ 
	   switch(s[i])
	   {
	     case '(' :p++;break;
		 case ')' :p--;break;
		 case '+':case '-':if(!p) c1 = i ; break;
		 case '*':case '/':if(!p) c2 = i ;break;
	   }
	}
	if(c1 < 0) c1 = c2;
	if(c1 < 0) return build_tree(s,x+1,y-1);
	u = ++nc;
	lch[u] = build_tree(s,x,c1);
	rch[u] = build_tree(s,c1+1,y);
	op[u] = s[c1];
	return u ;
}
int find(int i)
{  
	if(lch[i] == 0)
	{
	   printf("%c = ",op[i]);
	   int a ;
	   scanf("%d",&a);
	   return a; 
	}
   if (op[i] == '+')
	   return find(lch[i])+find(rch[i]);
   if (op[i] == '-')
	   return find(lch[i])-find(rch[i]);
   if (op[i] == '*')
	   return find(lch[i])*find(rch[i]);
   if (op[i] == '/')
	   return find(lch[i])/find(rch[i]);
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   char s[1000];
   gets(s);
    build_tree(s,0,strlen(s));
  printf("%d",find(1));
return 0 ;
}
