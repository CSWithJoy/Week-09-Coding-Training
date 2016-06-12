#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

#define MP(x,y) make_pair(x,y)
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;
const int maxn=205;
bool riot[maxn][maxn], dp[maxn][maxn];
int a[maxn<<1], b[maxn<<1];
int n, r, uf[maxn<<1], sz;
pii g[maxn<<1];

void inituf() {
    for (int i=0;i<(maxn<<1);++i) uf[i]=i;
}
int fa(int x) {
    int a=x;
    while (a!=uf[a]) a=uf[a];
    uf[x]=a;
    return a;
}
void merge(int x, int y) {
    x=fa(x), y=fa(y);
    if (x==y) return;
    if (x<y) uf[y]=x;
    if (x>y) uf[x]=y;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &r);
        inituf();
        memset(riot, false, sizeof(riot));
        for (int i=0;i<r;++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            riot[x][y]=true;
            merge(x, y+n);
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i=0;i<n;++i) {
            a[fa(i)]++;
            b[fa(i+n)]++;
        }
        sz=0;
        for (int i=0;i<(n<<1);++i) {
            if (a[i]||b[i]) {
                g[sz++]=MP(a[i],b[i]);
            }
        }
        memset(dp, false, sizeof(dp));
        dp[0][0]=true;
        for (int k=0;k<sz;++k) {
            for (int i=(n>>1);i>=0;--i) {
                for (int j=(n>>1);j>=0;--j) {
                    if (dp[i][j] && i+g[k].ff<=(n>>1) && j+g[k].ss<=(n>>1) ) {
                        dp[i+g[k].ff][j+g[k].ss]=true;
                    }
                }
            }
        }
        for (int i=(n>>1);i>=0;--i) {
            if (dp[i][i]) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
