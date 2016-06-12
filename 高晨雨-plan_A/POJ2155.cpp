//二维树状数组
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define MAX 1010
using namespace std;
int tree[MAX][MAX];
int n;
int lowbit(int t)
{
	return t&(-t);
}
int update(int x,int y,int num)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		for(int j=y;j<=n;j+=lowbit(j))
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
	int T;
	scanf("%d",&T);
	char str[5];
	while(T--)
	{
		int q;
		scanf("%d%d",&n,&q);
		memset(tree,0,sizeof(tree));
		int x1,x2,y1,y2;
		while(q--)
		{
			scanf("%s",str);
			if(str[0]=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				update(x2+1,y2+1,1);
				update(x1,y1,1);
				update(x1,y2+1,1);
				update(x2+1,y1,1);
			}
			else if(str[0]=='Q')
			{
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",Query(x,y)%2);
			}
		}
		if(T>0) printf("\n");
	}
	return 0;
}
