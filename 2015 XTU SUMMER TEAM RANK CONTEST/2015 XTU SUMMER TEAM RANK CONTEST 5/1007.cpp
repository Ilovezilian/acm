#include<bits/stdc++.h>
using namespace std;
const int N = 1001, INF = 1000000;
map<string, int> mp;
bool vis[N];
vector<int> G[N];
queue<int> q;
int dp[N][N], n;

int bfs(const int i)
{
	memset(vis, 0, sizeof(vis[0]) * n);
	while(!q.empty()) q.pop();
	for(int i = 0; i < n; i ++) for(int j = 0; j < n; j ++) dp[i][j] = INF;
	dp[i][i] = 0;

	q.push(i);
	vis[q.front()];
	int la;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		int siz = G[u].size();
		for(int j = 0; j < siz; j ++) if(!vis[G[u][j]])
		{
			q.push(G[u][j]);
			vis[G[u][j]] = 1;
			dp[i][G[u][j]] = dp[i][u] + 1;
		}
		la = u;
	}

	bool ok = 1;
	for(int j = 0; j < n; j ++) if(!vis[j]) {return -1;}
	return dp[i][la];
}


void solve()
{
	string s, s1;
	while(cin>>n && n)
	{
		for(int i = 0; i < n; i ++) G[i].clear();

		for(int i = 0; i < n; i ++)
		{
			cin>>s;
			mp[s] = i;
		}

		int m;
		cin>>m;
		for(int i = 0; i < m; i ++)
		{
			cin>>s>>s1;
			int x = mp[s], y= mp[s1];
			G[x].push_back(y), G[y].push_back(x);
		}

		bool ans_mark = 1;
	    int	ans = 0;
		for(int i = 0; i < n; i ++)
		{
			int k = bfs(i);
			if(k == -1)
			{
				ans = -1;
				break;
			}
			ans = max(ans, k);
		}

		cout<<ans<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}

