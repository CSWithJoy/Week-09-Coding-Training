#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int a[20][20];
int dp[50][50];//代表第一个串的前i个和第二个串的前j个的 最长公共子序列
LL num[50][50];//代表第一个串的前i个和第二个串的前j个 能组成多少种不同的串

int main()
{
    int T;

    scanf("%d", &T);

    for(int z=1;z<=T;z++)
    {
        char s1[50], s2[50];
        int i, j, len1, len2;

        memset(dp,0,sizeof(dp));
        memset(num,0,sizeof(num));

        scanf("%s%s", s1, s2);
        len1 = strlen(s1);
        len2 = strlen(s2);


        for(i=0; i<=len1; i++)
            num[i][0] = 1;

        for(i=0; i<=len2; i++)
            num[0][i] = 1;

		//字符串从0开始计数
		//dp和num数组确实从一开始计数
		//dp中的i,j对应string中的i-1，j-1
        for(i=1; i<=len1; i++)
		{
			for(j=1; j<=len2; j++)
			{
				//表示[i-1][j]和[i][j-1]中不再产生公共子序列
				if(s1[i-1]==s2[j-1])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
					num[i][j] = num[i-1][j-1];//只能有一种方案
				}

				else if(s1[i-1]!=s2[j-1])
				{
					//s2中的j位在s1中找到相同字符
					if(dp[i-1][j] > dp[i][j-1])
					{
						dp[i][j] = dp[i-1][j];
						num[i][j] = num[i-1][j];//选择的是[i-1][j]这种方案，所以就跟这种方案一样
					}
					//s1中的i位在s2中找到相同字符
					else if(dp[i-1][j] < dp[i][j-1])
					{
						dp[i][j] = dp[i][j-1];
						num[i][j] = num[i][j-1];//选择的是[i][j-1]这种方案，所以就跟这种方案一样
					}
					//s1中的i位和s2中的j位的增加，都没有增加子串长度
					else if(dp[i-1][j] == dp[i][j-1])
					{
						dp[i][j] = dp[i-1][j];
						num[i][j] = num[i-1][j] + num[i][j-1];//去选择先放s2的j还是先放进去s1的i
					}
				}
			}
		}
        printf("Case %d: %d %lld\n",z, len1+len2-dp[len1][len2], num[len1][len2]);
    }
    return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 35;

char s1[N], s2[N];
int len1, len2, cas = 1;
int dp[N][N];
long long ans[N * 2][N][N];

void init()
{
    scanf("%s%s", s1 + 1, s2 + 1);
    len1 = strlen(s1 + 1);
    len2 = strlen(s2 + 1);
}

//LCS思路：不断增长s1的连续子串，去和s2找相同子序列
int LCS()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len1; i++)
	{
        for (int j = 1; j <= len2; j++)
		{
            if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
            else
				[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
	}
    return dp[len1][len2];
}

void solve()
{
    int len = len1 + len2 - LCS();

    memset(ans, 0, sizeof(ans));
    ans[0][0][0] = 1;

    for (int i = 0; i <= len; i++)
	{
        for (int j = 0; j <= len1; j++)
		{
            for (int k = 0; k <= len2; k++)
			{
                if (ans[i][j][k])
				{
                    if (s1[j + 1] == s2[k + 1])
						ans[i + 1][j + 1][k + 1] += ans[i][j][k];
                    else //s1[j + 1] != s2[k + 1]
                    {
                        ans[i + 1][j][k + 1] += ans[i][j][k];
                        ans[i + 1][j + 1][k] += ans[i][j][k];
                    }
                }
			}
		}
	}
    printf("Case %d: %d %lld\n", cas++, len, ans[len][len1][len2]);
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
	{
        init();
        solve();
    }
    return 0;
}
*/
