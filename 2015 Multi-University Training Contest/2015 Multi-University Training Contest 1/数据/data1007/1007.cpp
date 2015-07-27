/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/22 16:49:53
File Name     :1007.cpp
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
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int M = 500005, N = 2005, mod = 1e9+7;

struct edge
{
	int u, v, w, next;
} e[M];

vector<pair<int, int> > ee[N];
int eid, nod[N], tnod[N], level[N], dis[N], cnt[N], n, m, max_flow, add_flow;
queue<int> q;
bool in[N];

void add_edge(int x, int y, int z) { e[eid].u = x, e[eid].v = y, e[eid].w = z, e[eid].next = nod[x], nod[x] = eid ++; }

void build_graph()
{
	eid = 0;
	memset(nod, -1, sizeof(nod));
	fin(i, 1, n + 1)
	{
		fi(j,(int) ee[i].size())
		{
			int v = ee[i][j].first;
			if(dis[i] + ee[i][j].second == dis[v])
				add_edge(i, v, 1), add_edge(v, i, 0);
		}
	}
	return;
}

void spfa(int st, int ed)
{
	memset(in, 0, sizeof(in));
	while(!q.empty()) q.pop();
	fi(i,N)
	{
		dis[i] = INF;
		cnt[i] = INF;
	}

	q.push(st);
	in[st] = 1, dis[st] = cnt[st] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		in[u] = 0;
		fi(i,(int)ee[u].size())
		{
			int v = ee[u][i].first;
			if(dis[v] == dis[u] + ee[u][i].second) cnt[v] = min(cnt[v], cnt[u] + 1);
			if(dis[v] > dis[u] + ee[u][i].second)
			{
				dis[v] = dis[u] + ee[u][i].second;
				cnt[v] = cnt[u] + 1;
				if(!in[v]) q.push(v), in[v] = 1;
			}
		}
	}
	return;
}

bool bfs(int st, int ed)
{
	int u, v, i;
	memset(level, -1, sizeof(level));
	memset(in, 0, sizeof(in));
	while(!q.empty()) q.pop();

	q.push(st);
	in[st] = 1, level[st] = 0;
	while(!q.empty())
	{
		u = q.front(), q.pop();
		in[u] = 0, i = nod[u];
		while(i != -1)
		{
			v = e[i].v;
			if(e[i].w > 0 && level[v] == -1)
			{
				level[v] = level[u] + 1;
				q.push(v);
				in[v] = 1;
				if(v == ed) return 1;
			}
			i = e[i].next;
		}
	}
	return 0;
}

void find(int st, int ed)
{
	vector<int> road;
	int tmp_flow, u, i, k;
	road.clear();
	add_flow = 0;
	u = st;
	while(tnod[st] != -1)
	{
		i = tnod[u];
		if(u != ed && i != -1 && e[i].w > 0 && level[u] + 1 == level[e[i].v]) road.push_back(i), u = e[i].v;
		else if(u == ed)
		{
			tmp_flow = INF;
			for(i = 0; i < (int)road.size(); i ++) k = road[i], tmp_flow = min(tmp_flow, e[k].w);
			for(i = (int) road.size() -1; i >= 0; -- i)
			{
				k = road[i];
				e[k].w -= tmp_flow;
				e[k^1].w += tmp_flow;
				if(!e[k].w) while((int) road.size() > i) road.pop_back();
				u= e[k].u;
			}
		 	add_flow += tmp_flow;
		}
		else
		{
			while((int) road.size() > 0 && u != st && tnod[u] == -1) road.pop_back(), u = e[road[road.size()]].u;
			tnod[u] = e[tnod[u]].next;
		}
	}
	return;
}


void dinic(int st, int ed)
{
	max_flow = 0;
	while(bfs(st, ed))
	{
		fi(i,n+1) tnod[i] = nod[i];
		find(st, ed);
		max_flow += add_flow;
	}
	return ;
}

int main()
{
	freopen("1007.in","r",stdin);
	freopen("my.out","w",stdout);
	int u, v, l;
	while(~scanf("%d%d", &n, &m))
	{
		fi(i,N) ee[i].clear();
		fi(i,m)
		{
			scanf("%d%d%d", &u, &v, &l);
			ee[u].push_back(make_pair<int, int>(v,l));
			ee[v].push_back(make_pair<int, int>(u,l));
		}
		spfa(1,n);

		build_graph();

		dinic(1, n);
		printf("%d %d\n", max_flow, m - cnt[n]);
	}

	return 0;
}
