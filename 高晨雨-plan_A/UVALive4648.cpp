//DFS
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 105
char maze[MAX][MAX];
int visit[MAX][MAX];
int cnt;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void DFS(int x,int y)
{
	int xx,yy;
	visit[x][y]=1;
	for(int i=0;i<4;i++)
	{
		xx=x+dir[i][0];
		yy=y+dir[i][1];
		if(xx>=0&&yy>=0&&xx<=101&&yy<=101)
		{
			if(maze[xx][yy]=='.')
			{
				cnt++;
			}
			else
			{
				if(visit[xx][yy]==0)
				{
					DFS(xx,yy);
				}
			}
		}

	}
}
int main()
{
	int N;
	int ma;
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0) break;
		int x,y;
		cnt=0;
		ma=0;
		memset(maze,'.',sizeof(maze));
		memset(visit,0,sizeof(visit));
		while(N--)
		{
			cin>>x>>y;
			maze[x][y]='*';
			if(x>ma) ma=x;
			if(y>ma) ma=y;
		}
		for(int i=1;i<=ma;i++)
			for(int j=1;j<=ma;j++)
			{
				if(maze[i][j]=='*'&&visit[i][j]==0)
					DFS(i,j);
			}
		cout<<cnt<<endl;
	}
	return 0;
}
