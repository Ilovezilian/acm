#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 2 * 1e5, INF = 0x7fffffff;

int ans[maxn<<2];

void pushup(int rt)
{
	ans[rt] = max(ans[rt<<1], ans[rt<<1|1]);
}

void build(int l, int r, int rt)
{
	if(l == r)
	{
		scanf("%d", ans + rt);
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p, int val, int l, int r, int rt)
{
	if(l == r)
	{
		ans[rt] = val;
		return;
	}

	int m = (l + r) >> 1;
	if(p <= m) update(p, val, lson);
	else update(p, val, rson);
	pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		return ans[rt];
	}

	int m = (l + r) >> 1, ret = 0;
	if(L <= m) ret = max(ret, query(L, R, lson));
	if(R > m) ret = max(ret, query(L, R, rson));
	return  ret;
}

void solve()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		build(1, n, 1);
		char s[5];
		int a, b;
		for(int i = 0; i < m; i ++)
		{
			scanf("%s%d%d", s, &a, &b);
			if(s[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
			else update(a, b, 1, n, 1);
		}
	}
}

int main()
{
	solve();
	return 0;
}
