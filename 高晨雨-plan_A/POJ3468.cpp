//线段树lazy 标记使用
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 100005
long long lazy[MAX<<2];
long long sum[MAX<<2];

void PushUP(int p)//更新父亲节点数值，本题维护内容是区间和
{
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
void build(int p,int l,int r)
{
	lazy[p]=0;
	if(l==r) {scanf("%I64d",&sum[p]);return;}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	PushUP(p);
}

void PushDown(int p,int m)//把lazy标记下放到儿子节点
{
	if(lazy[p])
	{
		lazy[p<<1]+=lazy[p];
		lazy[p<<1|1]+=lazy[p];
		sum[p<<1]+=(m-(m>>1))*lazy[p];
		sum[p<<1|1]+=(m>>1)*lazy[p];
		lazy[p]=0;
	}
}
void Update(int L,int R,int c,int l,int r,int p)
{
	if(L<=l&&R>=r)
	{
		lazy[p]+=c;
		sum[p]+=(long long)c*(r-l+1);
		return;
	}
	PushDown(p,r-l+1);
	int mid=(l+r)>>1;
	if(L<=mid) Update(L,R,c,l,mid,p<<1);
	if(R>mid) Update(L,R,c,mid+1,r,p<<1|1);
	PushUP(p);
}
long long Query(int L,int R,int l,int r,int p)
{
	if(L<=l&&R>=r) return sum[p];
	PushDown(p,r-l+1);
	int mid=(l+r)>>1;
	long long ret=0;
	if(L<=mid) ret+=Query(L,R,l,mid,p<<1);
	if(R>mid) ret+=Query(L,R,mid+1,r,p<<1|1);
	return ret;
}

int main()
{
	int m,n;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while(m--)
	{
		char s[5];
		int a,b,c;
		scanf("%s",s);
		if(s[0]=='Q')
		{
			scanf("%d%d",&a,&b);
			printf("%I64d\n",Query(a,b,1,n,1));
		}
		else
		{
			scanf("%d%d%d",&a,&b,&c);
			Update(a,b,c,1,n,1);
		}
	}
	return 0;
}

