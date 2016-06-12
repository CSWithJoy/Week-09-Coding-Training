//二维树状数组
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define MAX 10000
using namespace std;
int tree[MAX][MAX];
bool mark[MAX][MAX];
int lowbit(int t)
{
	return t&(-t);
}
int update(int x,int y,int num)
{
	for(int i=x;i<=MAX;i+=lowbit(i))
	{
		for(int j=y;j<=MAX;j+=lowbit(j))
		{
			tree[i][j]+=num;
		}
	}
}
int Query(int x,int y)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		for(int j=y;j>0;j-=lowbit(j))
		{
			sum+=tree[i][j];
		}

	}
	return sum;
}
int main()
{
	char str[3];
	int n,x,y;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		scanf("%s",str);
		if(str[0]=='B')
		{
			scanf("%d%d",&x,&y);
			x++;
			y++;
			if(mark[x][y]==false)
			{
				mark[x][y]=true;
				update(x,y,1);
			}
		}
		else if(str[0]=='D')
		{
			scanf("%d%d",&x,&y);
			x++;
			y++;
			if(mark[x][y]==true)
			{
				mark[x][y]=false;
				update(x,y,-1);
			}
		}
		else if(str[0]=='Q')
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
			x1++,x2++,y1++,y2++;
			if(x1<x2) swap(x1,x2);
			if(y1<y2) swap(y1,y2);
			int res=Query(x1,y1)-Query(x1,y2-1)-Query(x2-1,y1)+Query(x2-1,y2-1);
			printf("%d\n",res);
		}
	}
	return 0;
}
