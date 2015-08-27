/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/19 16:14:36
File Name     :h.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 100010, M = 202, mod = 1e9+7;

struct TwoSat{
	int n;
	bool mark[M<<1];
	vector<int> G[M<<1];
	int s[M<<1], c;

	bool dfs(int x)
	{
		if(mark[x^1]) return 0;
		if(mark[x]) return 1;
		mark[x] = 1;
		s[c++] = x;

		for(int i = 0; i < G[x].size(); i ++)
			if(!dfs(G[x][i])) return 0;

		return 1;
	}

	void init(int n)
	{
		this->n = n;
		memset(mark, 0, sizeof(mark));
		for(int i = 0; i < 2 * n; i ++)
			G[i].clear();
	}

	void add_clause(int x, int xval, int y, int yval)
	{
		x = 2 * x + xval;
		y = 2 * x + yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}

	bool solve()
	{
		for(int i = 0; i < 2 * n; i += 2) if(!mark[i] && !mark[i+1])
		{
			c = 0;
			if(!dfs(i))
			{
				while(c) mark[s[--c]] = 0;
				if(!dfs(i+1)) return 0;
			}
		}
		return 1;
	}
};

TwoSat solver;
int a[N], b[N], c[N], n, m;

bool test(int cur)
{
	solver.init(n);
	for(int i = 0; i < cur; i ++)
	{
		if(c[i] == 2)
			solver.add_clause(a[i], 0, b[i], 0);
		else if(c[i] == 1) 
			solver.add_clause(a[i], 1, b[i], 0), solver.add_clause(a[i], 0, b[i], 1);
		else
			solver.add_clause(a[i], 1, b[i], 1);
	}
	
	return solver.solve();
}

void solve()
{
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i ++)
		scanf("%d%d%d", a + i, b + i, c + i);

	int right = m, left = 0;
	while(right > left)
	{
		int mid = left + (right - left + 1) / 2;
/*
		printf("(%d, %d, %d)\n", left, mid, right);
*/
		if(test(mid)) left = mid;
		else right = mid - 1;
	}

	printf("%d\n", left);
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int cas;
	for(scanf("%d", &cas);cas ;cas --) solve();

	return 0;
}
