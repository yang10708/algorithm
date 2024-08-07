#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int,int>PII;

const int N = 510;

int n,m;
int h[N],e[N],ne[N],idx,w[N];
int dist[N];
bool st[N];

void add(int a,int b,int c)
{
	e[idx] = b,w[idx] = c,ne[idx] = h[a];h[a] = idx++;
}

int dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	heap.push({0,1});
	
	while (heap.size())
	{
		auto t = heap.top();
		heap.top();
		
		int ver = t.second,distance = t.first;
		if (st[ver]) continue;
		
		for(int i = h[ver];i != -1;i = ne[i])
		{
			int j = ne[i];
			if (dist[j]>distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({dist[j],j});
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}

int main()
{
	memset(h,-1,sizeof h);
	cin >>n>>m;
	while(m--)
	{
		int a,b,c;
		cin >>a>>b>>c;
		add(a,b,c);
	}
	int t = dijkstra();
	cout<<t;
	
	return 0;
}
