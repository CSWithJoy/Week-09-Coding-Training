#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

using namespace std;

typedef long long ll;

const int MAX = 100100;
const ll INF = ~0ULL>>1;//inf的一种记法

int t;
int n,m;
ll s[MAX];//页数价位
ll p[MAX];//所需价格
ll sum[MAX];//区间最小值
ll ans[MAX];//记录最小前缀的值
ll q;

int main()
{
    scanf("%d", &t);
    while(t--)
	{
        scanf("%d%d",&n,&m);

        for(int i = 0; i < n; ++i)
            scanf("%lld %lld",&s[i],&p[i]);

        for(int i = 0; i < n; ++i)
            sum[i] = s[i] * p[i];

        ll minn = INF;

        for(int i = n -1; i >= 0; -- i)
		{
            ans[i] = minn;
            minn = min(minn,sum[i]);
        }

        for(int i = 0; i < m; ++i)
        {
            scanf("%lld",&q);

            //二分求处页数所在区间
            int l = 0, r = n;
            while(l + 1 < r)
			{
                int mid = (l + r)>>1;
                if(s[mid] > q)
					r = mid;
                else
					l = mid;
            }
            ll res1 = q * p[l];
            printf("%lld\n",res1 < ans[l]?res1:ans[l]);
        }
    }
    return 0;
}
