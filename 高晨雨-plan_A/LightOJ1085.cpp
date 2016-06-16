//单调递增序列个数，思路同star(线段树做法)
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 100005
int Tree[MAX*4];
int num[MAX];
int input[MAX];
int ans;

void build(int p,int l,int r,int flag,int value)
{
	if(l==flag&&flag==r) {Tree[p]=value;return;}
	int mid=(l+r)>>1;
	if(mid>=flag) build(p<<1,l,mid,flag,value);
	if(mid<flag) build(p<<1|1,mid+1,r,flag,value);
	Tree[p]=(Tree[p<<1]+Tree[p<<1|1])%1000000007;
}

void Query(int p,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) {ans=(ans+Tree[p])%1000000007;return;}
	int mid=(l+r)>>1;
	if(mid>=x)  Query(p<<1,l,mid,x,y);
	if(mid<y)  Query(p<<1|1,mid+1,r,x,y);
	return;
}

int cmp(int x,int y)
{
	if(input[x]!=input[y]) return input[x]<input[y];
	else return x>y;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&input[i]);
			num[i]=i;
		}
		sort(num+1,num+n+1,cmp);
		memset(Tree,0,sizeof(Tree));
		for(int i=1;i<=n;i++)
		{
			ans=0;
			Query(1,1,n,1,num[i]);
			build(1,1,n,num[i],ans+1);
		}
		printf("Case %d: %d\n",cas,Tree[1]);


	}
	return 0;
}
