#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define lch p<<1
#define rch p<<1|1
using namespace std;
const int maxn=10010;
const double pi=acos(-(double)1);
const double eps=1e-6;
inline int sgn(double x) { return (x+eps>0)-(x-eps<0); }
inline double d2r(int deg) { return deg*pi/180.0; }
struct V {
    double x, y;
    int r;
    V () {}
    V (double x, double y):x(x), y(y), r(0.0) {}
    void rotate(int deg) {
        double rad=d2r(deg);
        double nx=cos(rad)*x-sin(rad)*y;
        double ny=cos(rad)*y+sin(rad)*x;
        x=nx, y=ny;
        r+=deg;
        r%=360;
    }
    V operator+(const V &rhs) const {
        V ret=V(x+rhs.x, y+rhs.y);
        return ret;
    }
}st[maxn<<2];
int rot[maxn<<2];

void build(int p, int l, int r) {
    if (l==r) {
        int tmp;
        scanf("%d", &tmp);
        st[p]=V(0, (double)tmp);
        return;
    }
    int mid=(l+r)>>1;
    build(lch, l, mid);
    build(rch, mid+1, r);
    st[p]=st[lch]+st[rch];
}

void change(int p, int l, int r, int x, int y, int rad) {
    if (x<=l&&r<=y) {
        rot[p]+=rad;
        st[p].rotate(rad);
        return;
    }
    int mid=(l+r)>>1;
    if (rot[p]) {
        rot[lch]+=rot[p];
        rot[rch]+=rot[p];
        st[lch].rotate(rot[p]);
        st[rch].rotate(rot[p]);
        rot[p]=0;
    }
    if (x<=mid) change(lch, l, mid, x, y, rad);
    if (mid<y) change(rch, mid+1, r, x, y, rad);
    st[p]=st[lch]+st[rch];
}

int query(int p, int l, int r, int x) {
    if (l==r) {
        return st[p].r;
    }
    int mid=(l+r)>>1;
    if (rot[p]) {
        rot[lch]+=rot[p];
        rot[rch]+=rot[p];
        st[lch].rotate(rot[p]);
        st[rch].rotate(rot[p]);
        rot[p]=0;
    }
    if (x<=mid) return query(lch, l, mid, x);
    if (mid<x) return query(rch, mid+1, r, x);
    st[p]=st[lch]+st[rch];
}

int main() {
    int n, q;
    while (scanf("%d%d", &n, &q)!=EOF) {
        build(1, 1, n);
        //printf("%.2f %.2f\n", st[1].x, st[1].y);
        memset(rot, 0, sizeof(rot));
        while (q--) {
            int x, ang;
            scanf("%d%d", &x, &ang);
            change(1, 1, n, x+1, n, ang+query(1, 1, n, x)+180-query(1, 1, n, x+1));
            printf("%.2f %.2f\n", sgn(st[1].x)?st[1].x:0.00, sgn(st[1].y)?st[1].y:0.00);
        }
        printf("\n");
    }
    return 0;
}
