//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 210,INF = 1e9;
//
//
//int n,m,q;
//int d[N][N];
//
//void floyd()
//{
//	for(int k = 1;k<=n;k++)
//		for(int i=1;i<=n;i++)
//			for(int j = 1;j<=n;j++)
//				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
//}
//
//
//int main()
//{
//	cin >>n>>m>>q;
//	
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			if (i==j) d[i][j] = 0;
//			else d[i][j] = INF;
//	
//	while (m--)
//	{
//		int a,b,w;
//		cin >>a>>b>>w;
//		
//		d[a][b] = min(d[a][b],w);
//		
//	}
//	
//	floyd();
//	
//	while(q--)
//	{
//		int a,b;
//		cin >>a>>b;
//		
//		if (d[a][b] > INF/2) puts("impossible");
//		else cout << d[a][b];
//	}
//}

#include <iostream>

using namespace std;

int main(){
	string s;
	cin >>s;
	for(int i =0;i<s.size();i++)
		if (s[i]=='d')
			cout <<s[i];
	return 0;
}
