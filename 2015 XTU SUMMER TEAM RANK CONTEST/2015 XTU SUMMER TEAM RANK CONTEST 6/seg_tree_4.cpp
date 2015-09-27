/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/4 22:55:04
File Name     :seg_tree_4.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e5+10, mod = 1e9+7;

int po[N<<2], kcas = 1;

void pushdown(int rt)
{
	po[rt<<1] = po[rt<<1|1] = po[rt], po[rt] = -1;
}

void build(int val, int l, int r, int rt)
{
	po[rt] = val;
}

void update(int val, int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		po[rt] = val;
		return;
	}

	if(po[rt] != -1) pushdown(rt);
	int m = (l + r) >> 1;
	if(L <= m) update(val, L, R, lson);
	if(R > m) update(val, L, R, rson);
}

int query(int L, int R, int l, int r, int rt)
{
	if(po[rt] != -1)
	{
		return (r - l + 1) * po[rt];
	}

	int m = (l + r) >> 1, ret = 0;
	if(L <= m) ret += query(L, R, lson);
	if(R > m) ret += query(L, R, rson);
	return ret;
}

void solve()
{
	int n, q, x, y, op;
	scanf("%d%d", &n, &q);
	build(1, 1, n, 1);

	for(int i = 0; i < q; i ++)
	{
		scanf("%d%d%d", &x, &y, &op);
		update(op, x, y, 1, n, 1);
	}

	printf("Case %d: The total value of the hook is %d.\n", kcas ++, query(1, n, 1, n, 1));
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
    return 0;
}

/**
#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 111111;
int h, w, n;
int col[maxn<<2];
int sum[maxn<<2];
void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushdown(int rt, int m)
{
	if(col[rt]) 
	{
		col[rt<<1] = col[rt<<1|1] = col[rt];
		sum[rt<<1] = (m - (m >> 1)) * col[rt];
		sum[rt<<1|1] = (m>>1) * col[rt];
		col[rt] = 0;
	}
}

void build(int l, int r, int rt)
{
	col[rt] = 0;
	sum[rt] = 1;
	if(l == r) return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int L, int R, int c, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		col[rt] = c;
		sum[rt] = c * (r - l + 1);
		return;
	}
	pushdown(rt, r-l + 1);
	int m = (l + r) >> 1;
	if(L <= m) update(L, R, c, lson);
	if(R > m) update(L, R, c, rson);
	pushup(rt);
}

int main()
{
	int T, n, m;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		scanf("%d%d", &n, &m);
		build(1, n, 1);
		while(m --)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
		printf("Case %d: The total value of the hook is %d.\n", cas, sum[1]);
	}
	return 0;
}
*/
