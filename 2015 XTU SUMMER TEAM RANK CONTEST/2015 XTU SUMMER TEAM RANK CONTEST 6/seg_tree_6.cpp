/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/6 22:37:13
File Name     :seg_tree_6.cpp
************************************************ */

//#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x7fffffff
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long LL;
const int N = 1e5+20, mod = 1e9+7;
LL sum[N<<2], add[N<<2];

void pushup(int l, int r, int rt)
{
	int w = r - l + 1;
	sum[rt] = sum[rt<<1] + add[rt<<1] * (w - (w>>1)) + sum[rt<<1|1] + add[rt<<1|1] * (w>>1);
}

void pushdown(int rt)
{
	add[rt<<1] += add[rt];
	add[rt<<1|1] += add[rt];
	add[rt] = 0;
}

void build(int l, int r, int rt)
{
	add[rt] = 0;
	if(l == r)
	{
		scanf("%I64d", sum + rt);
		return;
	}

	int m = (r + l) >> 1;
	build(lson);
	build(rson);
	pushup(l, r, rt);
}

void update(int L, int R, int val, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		add[rt] += val;
		return;
	}

	int m = (l + r) >> 1;
	if(L <= m) update(L, R, val, lson);
	if(m < R) update(L, R, val, rson);

	pushup(l, r, rt);
}

LL query(int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		//printf("sum(%d,%d) ret = %I64d\n",l, r, sum[rt] + add[rt] * (r - l + 1));
		return sum[rt] + add[rt] * (r - l + 1);
	}

	int m = (l + r) >> 1;
	pushdown(rt);

	LL ret = 0;
	if(L <= m) ret += query(L, R, lson);
	if(R > m) ret += query(L, R, rson);

	pushup(l, r, rt);
	//printf("sum(%d,%d) = %I64d ret = %I64d\n", l, r, sum[rt], ret);

	return ret;
}

void solve()
{
	int n, q;
	while(~scanf("%d%d", &n, &q))
	{
		build(1, n, 1);

		char s[4];
		int a, b, c;
		for(int i = 0; i < q; i ++)
		{
			scanf("%s", s);
			if(s[0] == 'Q')
			{
				scanf("%d%d", &a, &b);
				printf("%I64d\n", query(a, b, 1, n, 1));
			}
			else
			{
				scanf("%d%d%d", &a, &b, &c);
				update(a, b, c, 1, n, 1);
			}
		}
	}
}

int main()
{
    //freopen("test.out","r",stdin);
    //freopen("wa.out","w",stdout);
    solve();
    return 0;
}

