/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/24 18:51:22
File Name     :h_1.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 50050, mod = 1e9+7;
int ans[N];
vector<int> G[N];

void solve()
{

	int n, m, q, x, y;
	while(~scanf("%d%d%d", &n, &m, &q))
	{
		for(int i = 0; i < N; i ++) G[i].clear();

		for(int i = 0; i < m; i ++)
		{
			scanf("%d%d", &x, &y);
			if(x > y) G[x].push_back(y);
		}

		int m1 = N, m2 = N;
		for(int i = N-50; i; i --) 
		{
			if(G[i].size())
			{
				for(int j = 0; j < G[i].size(); j ++)
					if(G[i][j] < m1) m2 = m1, m1 = G[i][j];
					else if(G[i][j] < m2) m2 = G[i][j];
			}
			ans[i] = i - m2;
		}

		int qa;
		for(int i = 0; i < q; i ++)
		{
			scanf("%d", &qa);
			printf("%d\n", ans[qa] > 0 ? ans[qa] : 0);
		}
	}
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	solve();
	//solve_sort();
	return 0;
}

