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

int spfa()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	
	queue<int>q;
	q.push(1);
	st[1] = true;
	
	while(q.size())
	{
		int t  = q.front();
		q.pop();
		st[t] = false;
		
		for(int i=h[t];i!=-1;i=ne[i]){
			int j  = ne[i];
			if (dist[j]>dist[t]+w)
			{
				dist[j] = dist[j]+w;
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	if (dist[n] == 0x3f3f3f) return -1;
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
	int t = spfa();
	if (t==-1) puts("");
	else cout<<t;
	
	return 0;
}

//判断负环，将所有点加到队列，维护cnt队列，如果某点的cnt大于等于n，存在
