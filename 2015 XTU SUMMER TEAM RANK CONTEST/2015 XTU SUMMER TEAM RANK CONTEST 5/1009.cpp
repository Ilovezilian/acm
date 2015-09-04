/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/2 23:53:09
File Name     :1009.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 55, mod = 1e9+7;
int n;
struct nod
{
	int x, y, r;
} po[11];

bool vis[N][N];
vector<int> v;

bool judge()
{
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++)
	{
		if(vis[i][j]) continue;
		
		bool ok = 0;
		int sz = v.size();
		for(int k = 0; k < sz; k ++)
		{
			int x = po[v[k]].x, y = po[v[k]].y, r = po[v[k]].r;
			int d = abs(i - x) + abs(j - y);

			if(d <= r) {ok = 1; break;}
		}
		if(!ok)  return 0;
	}
	return 1;
}

void solve()
{
	while(~scanf("%d", &n) && n)
	{
		memset(vis, 0, sizeof(vis));

		int k;
		scanf("%d", &k);
		for(int i = 0; i < k; i ++)
		{
			scanf("%d%d", &po[i].x, &po[i].y);
			vis[po[i].x][po[i].y] = 1;
		}
		for(int i = 0; i < k; i ++)
			scanf("%d", &po[i].r);

		int sta = (1 << k), cnt, ans = 15;
		for(int i = 0; i < sta; i ++)
		{
			cnt = 0;
			v.clear();
			for(int j = 1, j1 = 0; j <= i; j <<= 1, j1 ++) if(i&j) v.push_back(j1), cnt ++;

			if(judge()) ans = min(ans, cnt);
		}
		if(ans == 15) ans = -1;
		printf("%d\n", ans);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
