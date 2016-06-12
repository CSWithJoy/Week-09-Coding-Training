#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=50010;
int MAX[maxn][20], MIN[maxn][20];

int qmin(int l, int r) {
    int m=(int)(log((double)(r-l+1))/log(2.0));
    return min(MIN[l][m], MIN[r-(1<<m)+1][m]);
}

int qmax(int l, int r) {
    int m=(int)(log((double)(r-l+1))/log(2.0));
    return max(MAX[l][m], MAX[r-(1<<m)+1][m]);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i=0;i<n;++i) {
        int tmp;
        scanf("%d", &tmp);
        MAX[i][0]=MIN[i][0]=tmp;
    }
    int sz=(int)(log((double)n)/log(2.0));
    for (int k=1;k<=sz;++k) {
        for (int i=0;i<n-(1<<(k-1));++i) {
            MAX[i][k]=max(MAX[i][k-1], MAX[i+(1<<(k-1))][k-1]);
            MIN[i][k]=min(MIN[i][k-1], MIN[i+(1<<(k-1))][k-1]);
        }
    }
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        printf("%d\n", qmax(x, y)-qmin(x, y));
    }
    return 0;
}
