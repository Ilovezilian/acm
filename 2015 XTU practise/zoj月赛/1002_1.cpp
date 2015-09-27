/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/14 20:12:24
File Name     :1002_1.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e4+10, mod = 1e9+7;
bool vis[N];
vector<int> V[N];

struct nod
{
	int o, d;
	bool operator < (const nod& a) const
	{
		return d < a.d;
	}
} po[N];

priority_queue<nod> pq;
int cnt[N], val[N];
long long sum[N];

int find(int x)
{
	return fa[x] = (x != fa[x] ? find(fa[x]) : x);
}

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", val + i);
		po[i].o = i, po[i].d = 0;
	}

	for(int i = 1; i <= n; i ++)
		V[i].clear();

	for(int i = 0; i < m; i ++)
	{
		scanf("%d%d", &x, &y);
		V[x].push_back(y), V[y].push_back(x);
		po[x].d ++, po[y].d ++;
	}

	sort(po + 1, po + 1 + n);
	memset(vis + 1, 0, sizeof(vis[0]) * n);
	pq.clear();
	for(int i = 1; i <= n; i ++)
		mp[po[i].o] = i;
	
	for(int i = 1; i <= n; i ++)
		pq.push(po[i]);

	while(!pq.empty())
	{
		int u = pq.top().o, d = pq.top().d;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		if(!d) continue;

		int sz = V[u].size();
		for(int i = 0; i < sz; i ++)
		{
			int v = mp[V[u][i]];
			po[v].d --;
			if(po[v].d > 0)
				pq.push(po[v]);
		}
	}

	memset(vis + 1, 0, sizeof(vis[0]) * n);
	memset(sum + 1, 0, sizeof(sum[0]) * n);

	for(int i = 1; i <= n; i ++)
	{
		if(po[i].d <= 1) continue;
		int sz = V[po[i].o].size();
		for(int j = 0; j < sz; j ++)
		{
			int u = po[mp[V[i][j]]].o;
			if(d[u] > 1)
			{
				find(u), find(v);
				if(u == fa[u]) cnt[u] = 1, sum[u] = val[u];
				else cnt[fa[u]] ++, sum[fa[u]] += val[u];
				if(v == fa[v]) cnt[v] = 1, sum[v] = val[v];
				else cnt[fa[v]] ++, sum[fa[v]] += val[v];

				fa[fa[u]] = fa[v];
				cnt[fa[v]] += cnt[fa[u]];
			}
		}
	}

	long long ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(fa[i] == i && cnt[i] & 1 && cnt[i] > 1) ans += sum[i];
	}

	pirntf("%I64d\n", ans);
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int T;
	scanf("%d", &T);
	while(T --)
		solve();
	return 0;
}
