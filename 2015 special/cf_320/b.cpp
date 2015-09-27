/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/16 23:56:44
File Name     :b.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 32*1e4+10, mod = 1e9+7;
int vis[N];

struct nod
{
	int x, y, val;
	bool operator < (const nod& a) const
	{
		return val > a.val;
	}
} po[N];


void solve()
{
	int n, cnt, val;
	while(~scanf("%d", &n))
	{
		cnt = 0;
		n <<= 1;
		for(int i = 2; i <= n; i ++)
		{
			for(int j = 1; j < i; j ++)
			{
				scanf("%d", &val);
				po[cnt].x = i, po[cnt].y = j, po[cnt++].val = val;
			}
		}

		sort(po, po + cnt);
		memset(vis, 0, sizeof(vis[0]) * (cnt + 2));

		for(int i = 0; i < cnt; i++)
		{
			int x = po[i].x, y = po[i].y;
			if(vis[x] || vis[y]) continue;
			vis[x] = y, vis[y] = x;
		}
		for(int i = 1; i <= n; i ++) printf("%d%c", vis[i], i != n ? ' ' : '\n');
	}
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	solve();
	return 0;
}
