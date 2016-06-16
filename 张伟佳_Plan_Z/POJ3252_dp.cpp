#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[32][32], dp2[32][32], start, finish;

void init()
{
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    dp2[0][0]=dp[0][0]=1;
    for (int i=1;i<=31;++i)
    {
        dp2[i][0]=1;
        for (int j=1;j<=31;++j)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-1];
        }
    }
    /*
    for (int i=1;i<=4;++i)
    {
        for (int j=0;j<=4;++j)
            printf("%5d ", dp[i][j]);
        printf("\n");
    }
    */
}

int find(int num, int bit)
{
    int ans=0;
    for (int i=0;i<=num;++i)
        ans+=dp[bit][i];
    return ans;
}

int count(int x)
{
    int cnt=0, tmp=x, cnt0;
    while (tmp)
    {
        ++cnt;
        tmp>>=1;
    }
    cnt0=cnt;
    int ans=0;
    for (int i=2;i<cnt;++i)
    {
        ans+=find(i/2, i);
    }

    tmp=1;
    cnt--;
    for (;cnt>0;--cnt)
    {
        if (x&(1<<(cnt-1)))
        {
            for (int j=0;j<=cnt0/2-tmp;++j)
            {
                ans+=dp2[cnt-1][j];
            }
            ++tmp;
        }
    }
    if (tmp<=cnt0/2) ++ans;
    return ans;
}

int main()
{
    init();
    scanf("%d%d", &start, &finish);
    printf("%d\n", count(finish)-count(start-1));
    //for (int i=1;i<=10;++i) printf("%d\n", count(i));
    return 0;
}
