#include"stdio.h"
#include"string.h"
#include"stdlib.h"



int n;
struct A
{
	int a,b;
	int len;
}eage[10011];
int Num;
int map[111][111];
int set[111];


int cmp(const void *a,const void *b)
{
	struct A *c,*d;
	c=(struct A *)a;
	d=(struct A *)b;
	return c->len-d->len;
}
void build(int num)
{
	int i;
	for(i=1;i<=num;i++)	set[i]=i;
}
int find(int k)
{
	if(set[k]==k)	return k;
	set[k]=find(set[k]);
	return set[k];
}
void Union(int f1,int f2)
{
	set[f2]=f1;
}


int Kruskal()
{
	int i;
	int f1,f2;
	int ans;


	ans=0;
	for(i=0;i<Num;i++)
	{
//		printf("%d %d\n",eage[i].a,eage[i].b);
		f1=find(eage[i].a);
		f2=find(eage[i].b);
		if(f1==f2)	continue;
		ans+=eage[i].len;
		Union(f1,f2);
//		for(int j = 1; j <=n ;j ++)
//			printf("%d ",set[j]);
//		printf("\n");
	}
	return ans;
}


int main()
{
	int m;
	int i,l;
	int a,b;
	int f1,f2;
	int ans;
	freopen("/home/plac/problem/input.txt","r",stdin);
	while(scanf("%d",&n)!=-1)
	{
		build(n);


		for(i=1;i<=n;i++)
			for(l=1;l<=n;l++)
				scanf("%d",&map[i][l]);


		Num=0;
		for(i=2;i<=n;i++)
			for(l=1;l<i;l++)
			{
				eage[Num].a=i;
				eage[Num].b=l;
				eage[Num].len=map[i][l];
				Num++;
			}


		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			f1=find(a);
			f2=find(b);
			if(f1==f2)	continue;
			Union(f1,f2);
		}
 
		qsort(eage,Num,sizeof(eage[0]),cmp);
		ans=Kruskal();
		
		printf("%d\n",ans);
	}
	return 0;
}
