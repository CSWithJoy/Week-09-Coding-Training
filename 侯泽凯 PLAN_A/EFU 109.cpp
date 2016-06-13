//欧拉筛法
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

int prime[50005];

bool isprime[50005];

int cnt;

void doprime()
{
	cnt=1;
	memset(isprime,true,sizeof(isprime));
	isprime[1]=0;

	for(long long i=2;i<=50000;i++)
	{
		if(isprime[i])
		{
			prime[cnt++]=i;
			for(long long j=i*i;j<=50000;j+=i)
			{
				isprime[j]=false;
			}
		}
	}
}

int isp(int n)
{
	for(int i=1;prime[i]<=sqrt(n);i++)
	{
		if(n%prime[i]==0)
			return 0;
	}
	return 1;
}

int main()
{
	doprime();

	int n;
	while(cin>>n)
	{
		if(isp(n)==0||n==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
