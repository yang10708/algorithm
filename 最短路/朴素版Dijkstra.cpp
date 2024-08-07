//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 510;
//
//int n,m;
//int g[N][N];
//int dist[N];
//bool st[N];
//
//
//int dijkstra()
//{
//	memset(dist,0x3f,sizeof dist);
//	dist[1]=0;
//	
//	for(int i = 0;i<n;i++)
//	{
//		int t = -1;
//		for(int j = 1;i<=n;j++)
//			if (!st[j] && (t==-1 || dist[t]>dist[j]))
//				t = j;
//
//		st[t] = true;
//		
//		for(int j = 1;j<=n;j++)
//			dist[j] = min(dist[j],dist[t]+g[t][j]);
//	}
//	if (dist[n]==0x3f3f3f) return -1;
//	return dist[n];
//}
//
//int main()
//{
//	cin >>n>>m;
//	
//	memset(g,0x3f,sizeof g);
//	
//	while(m--)
//	{
//		int a,b,c;
//		cin >>a>>b>>c;
//		g[a][b] = min(g[a][b],c);
//	}
//	return 0;
//}
//


#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 510;

int n;
int g[N][N],dist[N][N];
bool st[N][N];

struct node
{
	int x,y,st;
	bool operator < (const node& b)const{
		return st > b.st;
	}
};

priority_queue<node>q;

int step[4][2] = {1,0,-1,0,0,1,0,-1};


void dij()
{
	q.push({1,1,g[1][1]});
	memset(dist,0x3f,sizeof dist);
	dist[1][1] = g[1][1];
	while(!q.empty())
	{
		auto now = q.top();
		q.pop();
		if(st[now.x][now.y]) continue;
		st[now.x][now.y] = true;
		
		for(int i = 0;i<4;i++)
		{
			int dx = now.x + step[i][0];
			int dy = now.y + step[i][1];
			
			if(dx>0 && dx<=n && dy<=n &&dy>0 && !st[dx][dy])
			{
				dist[dx][dy] = max(g[dx][dy],dist[now.x][now.y]);
				q.push({dx,dy,dist[dx][dy]});
			}
		}
	}
}


int main()
{
	cin >>n;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			cin >>g[i][j];
	
	dij();
	
	cout <<dist[n][n];
	return 0;
}
