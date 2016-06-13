//组合数学题
#include<iostream>
#include<stdio.h>
using namespace std;

long long c(long long n,long long r)
{
    long long sum=1;
    for(long long i=1;i<=r;i++)
        sum=sum*(n+1-i)/i;
    return sum;
}

long long a(long long n,long long r)
{
    long long sum=1;
    for(long long i=0;i<r;i++)
        sum=sum*(n-i);
    return sum;
}

long long j(long long x)
{
	long long s=1;
	for(long long i=2;i<=x;i++)
	{
		s*=i;
	}
	return s;
}

int main()
{
	long long t;
	cin>>t;
	for(long long z=1;z<=t;z++)
	{
		long long k,n;
		cin>>n>>k;
		if(k>n)
			printf("Case %d: 0\n",z);
		else
		{
			printf("Case %lld: %lld\n",z,c(n,k)*c(n,k)*j(k));
		}
	}
	return 0;
}
