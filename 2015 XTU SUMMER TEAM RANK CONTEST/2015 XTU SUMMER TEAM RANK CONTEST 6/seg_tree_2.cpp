/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/4 0:57:03
File Name     :seg_tree_2.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int N = 0,maxn = 5555, mod = 1e9+7;
int sum[maxn<<2];

void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt)
{
	sum[rt] = 0;
	if(l == r) return ;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}

void update(int p, int l, int r, int rt)
{
	if(l == r)
	{
		sum[rt] ++;
		return;
	}

	int m = (l + r) >> 1;
	if(p <= m) update(p, lson);
	else update(p, rson);
	pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		return sum[rt];
	}

	int m = (l + r) >> 1, ret = 0;
	if(L <= m) ret += query(L, R, lson);
	if(R > m) ret += query(L, R, rson);
	return ret;
}

int x[maxn];

void solve()
{
	int n;
	while(~scanf("%d", &n))
	{
		build(0, n - 1, 1);

		int sum = 0;
		for(int i = 0; i < n; i ++)
		{
			scanf("%d", x + i);
			sum += query(x[i], n - 1, 0, n - 1, 1);
			update(x[i], 0, n - 1, 1);
		}
		int ret = sum;
		for(int i = 0; i < n; i ++)
		{
			sum += n - x[i] - x[i] - 1;
			ret = min(ret, sum);
		}
		printf("%d\n", ret);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
