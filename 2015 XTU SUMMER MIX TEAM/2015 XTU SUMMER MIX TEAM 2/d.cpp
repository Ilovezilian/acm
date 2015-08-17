/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/8 16:55:01
File Name     :d.cpp
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
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 200100, M = 1000100, mod = 1e9+7;
#pragma comment(linker, "/STACK:102400000,102400000") 
int n, m, fa[N],cur, sum, m1, m2;
bool vis[N];
vector<int> v[N], u[N];

void init()
{
	m1 = m2 = 0;
	memset(vis, 0, sizeof(vis));
	fi(i,0,n) fa[i] = i;
	fi(i,0,n) if(!v[i].empty()) v[i].clear();
	fi(i,0,n) if(!u[i].empty()) u[i].clear();
}

void dfs(int x)
{
	if(vis[x] && x != cur) {fa[x] = cur; return;}
	vis[x] = 1;

	fi(i,0,v[x].size() - 1)
	{
		int t = v[x][i];
		if(vis[t]){ cur = t; return;}
		else dfs(t);
	}
}

void build()
{
	fi(i,0,n)
	{
		if(v[i].size() > 0)
		fi(j,0,v[i].size()-1)
		{
			int t = v[i][j];
			//printf("%d %d", i, t);
			if(fa[i] != fa[t]) u[i].push_back(t), u[t].push_back(i), sum ++;
		}
	}
}

void dfs1(int x, int cnt)
{
	vis[x] = 1;
	if(u[x].size() == 1)
	{
		if(cnt > m1) m2 = m1, m1 = cnt;
		else if(cnt > m2) m2 = cnt;
		return;
	}
	fi(i,0,u[x].size()-1) if(!vis[u[x][i]]) dfs1(u[x][i], cnt + 1);
}

void solve()
{
	int x, y;
	while(~scanf("%d%d", &n,&m), n + m)
	{
		init();
		fi(i,0,m-1)
		{
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}

		dfs(x);
		
		build();

		memset(vis,0,sizeof(vis));
		sum = 0;
		dfs1(cur, 0);
		printf("%d\n", sum - m1 - m2);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
 	solve(); 
    return 0;
}
