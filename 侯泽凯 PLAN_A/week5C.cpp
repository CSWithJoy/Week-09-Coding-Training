//在距离上加一维的spfa
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF = 0x3fffffff;
const int MAXN = 30005;

int t,n,m,k,d,u,v,w;
int inde = 0;//给点标号

int head[10005]; //记录边从哪来
int distant[10005][15]; //各个结点,第二维是用多少新路

//路线
struct edge{
    int v,w,x,next;
}edges[30005];

struct point{
    int sum,u;
};

void add_edge(int u1,int v1,int w1,int x1)
{
    edges[inde].v = v1;//v是该路进入的点
    edges[inde].w = w1;//w是所需时间
    edges[inde].x = x1;//x记录的是：为新边还是旧边
    edges[inde].next = head[u1];//记录从哪里过来标记是
    head[u1] = inde++;
}

//算出各结点的路径和使用得新路
void spfa()
{
	//初始化
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= d; j++)
            distant[i][j] = INF;
    distant[0][0] = 0;

    queue<point> Q;

    //把s点放进队列
    point p;
    p.u = 0;
    p.sum = 0;
    Q.push(p);

    while(!Q.empty())
	{
        p = Q.front();
		Q.pop();

        for(int i = head[p.u] ; i!=-1 ; i=edges[i].next)
		{
            int costRode = edges[i].w;
            int sumNewRode = p.sum+edges[i].x;
            int nextStartU = edges[i].v;

            point pp;

            pp.sum = sumNewRode;
            pp.u = nextStartU;

            //松弛操作
            if(costRode+distant[p.u][p.sum] < distant[nextStartU][sumNewRode] && sumNewRode<=d)
            {
                distant[nextStartU][sumNewRode] = costRode + distant[p.u][p.sum];
                Q.push(pp);
            }
        }
    }
}

int main()
{
    cin>>t;
    for(int i = 1; i <= t;i++)
	{
        cin>>n>>m>>k>>d;
        inde = 0;
		memset(head,-1,sizeof(head));

        while(m--)
			cin>>u>>v>>w,add_edge(u,v,w,0);

        while(k--)
			cin>>u>>v>>w,add_edge(u,v,w,1);

        spfa();

        int minn = INF;
        printf("Case %d: ",i);
        for(int j = 0; j <= d; j++)
		{
            if(distant[n-1][j] < minn)//distant[n-1][j]表示到t需要加上j条道路
            minn = distant[n-1][j];
        }

        minn == INF?printf("Impossible\n"):printf("%d\n",minn);
    }
    return 0;
}
