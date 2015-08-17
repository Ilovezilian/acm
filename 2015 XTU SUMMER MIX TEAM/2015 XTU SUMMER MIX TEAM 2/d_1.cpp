/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/9 22:27:49
File Name     :d_1.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 200020, M = 1000100, mod = 1e9+7;

bool iscut[M*2];
int dfn[N], dp[N][2], head[N], nx[M*2][2];
int n, m, mt, p;

void init()
{
	memset(dfn, 0, sizeof(dfn));
	memset(dp, 0, sizeof(dp));
	memset(head, -1, sizeof(head));
	memset(iscut, 0, sizeof(iscut));
	mt = p = 0;
}

void add(int u, int v)
{
	nx[p][1] = v, nx[p][0] = head[u], head[u] = p++;
	nx[p][1] = u, nx[p][0] = head[v], head[v] = p++;
}


int dfs(int u)
{
	int lowu = dfn[u] = ++mt;
	for(int i = head[u]; i + 1; i = nx[i][0]) if(!iscut[i>>1])
	{
		iscut[i>>1] = 1;
		int v = nx[i][1];
		if(!dfn[v])
		{
			int lowv = dfs(v);
			lowu = min(lowu, lowv);
			int c = dp[v][1];
			if(dfn[u] < lowv) ++c, ++m;
			if(dp[u][1] < c) dp[u][0] = dp[u][1], dp[u][1] = c;
			else if(dp[u][0] < c) dp[u][0] = c;
			p = max(p, dp[u][0] + dp[u][1]);
		}
		else lowu = min(lowu, dfn[v]);
	}
	return lowu;
}

void solve()
{
	int x, y;
	while(~scanf("%d%d", &n, &m), n + m)
	{
		init();
		fi(i,0, m - 1)
		{
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		m = p = 0;
		dfs(1);
		printf("%d\n", m - p);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
 	solve();
    return 0;
}
