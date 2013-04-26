#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Cell
{
	double x;
	double y;
	double z;
	double r;
};

Cell c[105];

struct MAP
{
	int x;
	int y;
	double r;
};

MAP m[105*105];

int root[105];

int rank[105];

bool cmp(MAP m1,MAP m2)
{
	if(m1.r<m2.r)
	{
		return true;
	}
	else
		return false;
}

int Find(int x)
{
	if(x!=root[x])
	{
		root[x] = Find(root[x]);
	}
	return root[x];
}

double sum = 0;

void Union(int x,int y,double r)
{
	if(x==y)
		return;
	if(rank[x]<rank[y])
	{
		root[x] = y;
	}
	else
	{
		if(rank[x]==rank[y])
		{
			rank[x]++;
		}
		root[y] = x;
	}
	sum+=r;

}

int main()
{
	int n;
	freopen("/home/plac/problem/input.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>c[i].x>>c[i].y>>c[i].z>>c[i].r;
			root[i] = i;
			rank[i] =0;
		}

		int count  = 0;
		for(int i = 0;i<n;i++)
			for(int j =i+1;j<n;j++)
			{
				m[count].x = i;
				m[count].y = j;
				m[count].r =sqrt(pow((c[i].x-c[j].x),2.0)+pow((c[i].y-c[j].y),2.0)+pow((c[i].z-c[j].z),2.0)) > c[i].r+c[j].r ?sqrt(pow((c[i].x-c[j].x),2.0)+pow((c[i].y-c[j].y),2.0)+pow((c[i].z-c[j].z),2.0))-( c[i].r+c[j].r ):0 ;
				//if(m[count].r == 0)
				//	printf("%d %d\n",i+1,j+1);
				count++;
			}
		sort(m,m+count,cmp);
		sum = 0;
		for(int i = 0;i<count ;i++)
		{
			Union(Find(m[i].x),Find(m[i].y),m[i].r);
		}
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl;
	}
	return 0;
}
