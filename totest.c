// File Name: totest.c
// Author: darkdream
// Created Time: 2013年04月25日 星期四 14时52分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   FILE *p,*p1;
   p = fopen("output.txt","r");
   p1 = fopen("output.txt","r");
   char str[100],str1[100];
   int  i =1 ;
   while(fscanf(p1,"%s",str) != EOF)
   {
      fscanf(p,"%s",str1);
	  if(strcmp(str,str1) != 0)
		  printf("%d\n",i);
     i++;
   }
return 0 ;
}
