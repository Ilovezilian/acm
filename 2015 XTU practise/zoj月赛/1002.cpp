/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/14 14:09:39
File Name     :1002.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e4+10, mod = 1e9+7;
typedef long long LL;

int val[N], cnt;
bool vis[N];
vector<int> V[N];

LL dfs(int x)
{
	vis[x] = 1;
	int sz = V[x].size();
	if(sz == 0 || sz == 1) return 0;
	cnt ++;

	LL ret = 0;
	for(int i = 0; i < sz; i ++) if(!vis[V[x][i]])
	{
		ret += dfs(V[x][i]);
	}
	return ret + val[x];
}

void solve()
{
	int n, m, x, y;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i ++)
		scanf("%d", val + i);

	for(int i = 1; i <= n; i ++)
		V[i].clear();
	
	for(int i = 0; i < m; i ++)
	{
		scanf("%d%d", &x, &y);
		V[x].push_back(y);
		V[y].push_back(x);
	}

	LL ans = 0, tmp;

	memset(vis + 1, 0, sizeof(vis[0]) * n);

	for(int i = 1; i <= n; i ++) if(!vis[i])
	{
		cnt = 0;
		tmp = dfs(i);
		//printf("cnt = %d\n", cnt);
		if(cnt&1 && cnt!=1) ans += tmp;
	}

	printf("%I64d\n", ans);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    
	int T;
	scanf("%d", &T);
	while(T --) solve();
    return 0;
}
