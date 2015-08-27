/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/18 10:19:23
File Name     :UVALive_3713.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 100010, mod = 1e9+7;

struct TwoSat{
	int n;
	bool mark[N<<1];
	vector<int> G[N<<1];
	int s[N<<1], c;

	bool dfs(int x)
	{
		if(mark[x^1]) return 0;
		if(mark[x]) return 1;
		mark[x] = 1;
		s[c++] = x;
		for(int i = 0; i < (int)G[x].size(); i ++) if(!dfs(G[x][i]))
			return 0;
		return 1;
	}

	void init(int n)
	{
		this->n = n;
		memset(mark, 0, sizeof(mark));
		for(int i = 0; i < 2 * n; i ++) G[i].clear();
	}

	void add_clause(int x, int xval, int y, int yval)
	{
		x = 2 * x + xval;
		y = 2 * y + yval;
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

	void prt(int t[], int _t)
	{
		//printf("TwoSat.prtst\n");
		for(int i = 0; i < 2 * n; i += 2)
			printf("%c\n", (mark[i] ? 'C' : (t[i/2] * n < _t ? 'B' : 'A')));
		//printf("TwoSat.prt_ed\n");
	}
};

TwoSat solver;
int n, m, _t, t[N];

void solve()
{
	while(~scanf("%d%d", &n, &m) && n + m)
	{
		_t = 0;
		for(int i = 0; i < n; i ++)
		{
			scanf("%d", t + i);
			_t += t[i];
		}
		
		int x, y;
		solver.init(n);

		for(int i = 0; i < m; i ++)
		{
			scanf("%d%d", &x, &y);
			if(x == y) continue;

			x--, y --;
			solver.add_clause(x, 1, y, 1);
			if((t[x] * n >= _t && t[y] * n >= _t) || (t[x] * n < _t && t[y] * n < _t))
				solver.add_clause(x, 0, y, 0);
		}

		if(solver.solve()) solver.prt(t, _t);
		else printf("No solution.\n");
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
