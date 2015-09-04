/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/2 22:52:10
File Name     :1007_1.cpp
************************************************ */

#include <bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 1e9+7, INF = 1000001;
map<string, int> mp;
int n, dis[N][N];
vector<int> G[N];
bool vis[N];
queue<int> q;

void bfs(int x)
{
	memset(vis, 0, sizeof(vis[0]) * n);
	while(!q.empty()) q.pop();

	vis[x] = 1;
	dis[x][x] = 0;
	q.push(x);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		int sz = G[u].size();
		for(int j = 0; j < sz; j ++) if(!vis[G[u][j]])
		{
			int v = G[u][j];
			q.push(v);
			vis[v] = 1;

			dis[x][v] = dis[x][u] + 1;
		}
	}
}

void solve()
{
	string s1, s2;
	while(cin>>n && n)
	{
		mp.clear();
		for(int i = 0; i < n; i ++) G[i].clear();

		for(int i = 0; i < n; i ++)
		{
			cin>>s1;
			mp[s1] = i;
		}
		int m;
		cin>>m;
		for(int i = 0; i < m; i ++)
		{
			cin>>s1>>s2;
			int x = mp[s1], y = mp[s2];
			G[x].push_back(y);
			G[y].push_back(x);
		}

		for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) dis[i][j] = INF;
		dis[0][0] = 0;

		for(int i = 0; i < n; i ++) bfs(i);

		int ans = 0;
		for(int i = 0; i < n; i ++) for(int j = i + 1; j < n; j ++) ans = max(ans, dis[i][j]);

		if(ans == INF) ans = -1;
		cout<<ans<<'\n';
		//cout<<flush;

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
