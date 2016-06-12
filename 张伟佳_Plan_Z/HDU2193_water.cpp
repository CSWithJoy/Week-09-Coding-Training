#include <cstdio>
using namespace std;
int a[100];

int main() {
    int n;
    a[0]=1;a[1]=2;
    for (int i=2;i<=43;++i) a[i]=a[i-1]+a[i-2]+1;
    while (scanf("%d", &n)&&n) {
        int ans=0;
        while (a[ans]<=n) ++ans;
        printf("%d\n", ans-1);
    }
    return 0;
}
