#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 55555;
int sum[maxn<<2];

void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt)
{
	if(r == l)
	{
		scanf("%d", &sum[rt]);
		return ;
	}
	int m = (r + l) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

void update(int p, int add, int l, int r, int rt)
{
	if(l == r)
	{
		sum[rt] += add;
		return;
	}

	int m = (l + r) >> 1;
	if(p <= m) update(p, add, lson);
	else update(p, add, rson);
	pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		return sum[rt];
	}
	
	int m = (r + l) >> 1, ret = 0;
	if(L <= m) ret += query(L, R, lson);
	if(R > m) ret += query(L, R, rson);

	return ret;
}

void solve()
{
	int n, T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		scanf("%d", &n);
		printf("Case %d:\n", cas);
		build(1, n, 1);
		char s[10];
		while(scanf("%s", s))
		{
			if(s[0] == 'E') break;
			int a, b;
			scanf("%d%d", &a, &b);
			if(s[0] == 'S') update(a, -b, 1, n, 1);
			else if(s[0] == 'Q') printf("%d\n", query(a, b, 1, n, 1));
			else update(a, b, 1, n, 1);
		}
	}
}

int main()
{
	solve();
	return 0;
}
