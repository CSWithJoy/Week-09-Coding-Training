#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int a[110];
int sum[110];//前缀和
int dp[110][110];//用dp[i][j]表示在区间i~j上A比B多的分数值，然后枚举区间。

int main()
{
    int t;
    scanf("%d", &t);

    for(int z=1;z<=t;z++)
    {
        memset(a  , 0, sizeof(a)  );
        memset(dp , 0, sizeof(dp) );
        memset(sum, 0, sizeof(sum));

        scanf("%d", &n);

        for (int i = 1;i <= n;i++)
        {
            scanf("%d", &a[i]);

            sum[i] = sum[i - 1] + a[i];

            dp[i][i] = a[i];
        }

        for (int p=1 ; p<=n ; p++)//p用来枚举区间长度
        {
            for (int i=1 ; i+p<=n ; i++)
            {
                int j=i+p;

                dp[i][j]=sum[j]-sum[i-1];

                //取子区间i~k和k+1~j中 A比B多出数值 的最大值
                for (int k = i;k < j;k++)
                {
                	//max(sum[k]-sum[i-1] - dp[k+1][j] , sum[j]-sum[k] - dp[i][k])表示从左边和从右边取的最优方案
                    dp[i][j] = max(dp[i][j], max(sum[k]-sum[i-1] - dp[k+1][j] , sum[j]-sum[k] - dp[i][k]));
                }
            }
        }
        printf("Case %d: %d\n",z, dp[1][n]);
    }
    return 0;
}
