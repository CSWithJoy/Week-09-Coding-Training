//区间DP
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace  std;
#define MAX 100005
int num[MAX];
int dp[MAX];
int n,ans;
int l,r;
void DP()
{
	 dp[0]= num[0];
        for(int  i= 1; i< n; i++)
            dp[i]= dp[i-1]> 0? dp[i-1]+ num[i] : num[i];
        r= 0;
        ans= num[0];
        for(int  i= 1; i< n; i++ )
        {
            if( ans< dp[i] )
                ans= dp[i],  r=i;
        }
        l= r;
        for(int  i= l-1; i>= 0; i-- )
        {
            if( dp[i]>= 0 )
                l= i;
            else break;
        }
}
int main()
{
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>num[i];
		memset(dp,0,sizeof(dp));
		ans=0;
		l=r=1;
		DP();
		printf("Case %d:\n",cas);
		cout<<ans<<' '<<l+1<<' '<<r+1<<endl;
		if(cas!=T) cout<<endl;
	}
}
