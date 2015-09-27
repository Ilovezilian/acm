/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/5 0:11:25
File Name     :seg_tree_5.cpp
************************************************ */

//#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x7fffffff
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 1e5 + 10, mod = 1e9+7;
typedef long long LL;
LL po[N<<2], add[N<<2];

void pushup(int l, int r, int rt)
{
	po[rt] = po[rt<<1] + po[rt<<1|1] + add[rt] * (r - l + 1);
}

void build(int l, int r, int rt)
{
	add[rt] = 0;
	if(l == r)
	{
		scanf("%I64d", po + rt);
		return;
	}
	
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(l, r, rt);
}

void update(int val, int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		add[rt] += val;
		po[rt] += (r - l + 1) * val;
		return;
	}

	int m = (l + r) >> 1;
	if(L <= m) update(val, L, R, lson);
	if(R > m) update(val, L, R, rson);
	pushup(l, r, rt);
}

LL query(int L, int R, int l, int r, int rt)
{
	if(L <= l && r <= R)
	{
		//printf("po(%d,%d) = %I64d\n", l, r, po[rt]);
		return po[rt];
	}
	
	int m = (l + r) >> 1;
	LL ret = 0;
	if(L <= m) ret += query(L, R, lson) + add[rt] * (min(m - max(l, L) + 1, R - max(l, L) + 1));
	if(R > m) ret += query(L, R, rson) + add[rt] * (min(min(R, r) - m, min(R, r) - L + 1));
	//printf("po(%d,%d) = %I64d ret = %I64d\n", l, r, po[rt], ret);
	return ret;
}

void solve()
{
	int n, q;
	while(~scanf("%d%d", &n, &q))
	{
		build(1, n, 1);

		char s[3];
		int a, b, c;
		for(int i = 0; i < q; i ++)
		{
			scanf("%s", s);
			if(s[0] == 'C')
			{
				scanf("%d%d%d", &a, &b, &c);
				update(c, a, b, 1, n, 1);
			}
			else
			{
				scanf("%d%d", &a, &b);
				printf("%I64d\n", query(a, b, 1, n, 1)); 
			}
		}
	}
}

int main()
{
    //freopen("test.out","r",stdin);
    //freopen("ac.out","w",stdout);
    solve();
    return 0;
}
