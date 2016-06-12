#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1010;
struct EG {
    int u, v, d, w;
    EG() {}
    EG(int u, int v, int d, int w):u(u), v(v), d(d), w(w) {}
    bool operator<(const EG &rhs) const {
        return w>rhs.w;
    }
}edge[maxn*maxn];
int m, n, uf[maxn];
bool vis[maxn];

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
    int ans;
    while (scanf("%d%d", &n, &m)!=EOF) {
        for (int i=0;i<m;++i) 
            scanf("%d%d%d%d", &edge[i].u, &edge[i].v, &edge[i].d, &edge[i].w);
        memset(vis, false, sizeof(vis));
        for (int i=1;i<=n;++i) uf[i]=i;
        sort(edge, edge+m);

        ans=0;
        for (int i=0;i<m;++i) {
            int u=fa(edge[i].u), v=fa(edge[i].v);
            if (vis[u]&&vis[v]) continue;
            if (edge[i].d==1&&vis[u]) continue;
            ans+=edge[i].w;
            if (edge[i].d) {
                vis[u]=true;
            }else {
                if (u==v) vis[v]=true;
                if (!vis[u]&&!vis[v]) merge(u, v);
                else if (vis[u]) vis[v]=true;
                else if (vis[v]) vis[u]=true;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}