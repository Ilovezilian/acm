/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/4 8:53:59
File Name     :seg_tree_3.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N = 2 * 1e5 + 20, mod = 1e9+7;
int w[N<<2];

void pushup(int rt)
{
	w[rt] = max(w[rt<<1], w[rt<<1|1]);
}

void build(int val, int l, int r, int rt)
{
	w[rt] = val;
	if(l == r) return;

	int m = (l + r) >> 1;
	build(val, lson);
	build(val, rson);
	//pushup(rt);
}

void update(int val, int l, int r, int rt)
{
	if(l == r)
	{
		w[rt] -= val;
		return;
	}
	int m = (l + r) >> 1;
	if(val <= w[rt<<1]) update(val, lson);
	else update(val, rson);
	pushup(rt);
}

int query(int val, int l, int r, int rt)
{
	if(r == l) return r;
	int m = (l + r) >> 1;
	return (w[rt<<1] >= val) ? query(val, lson) : query(val, rson);
}

void solve()
{
	int height, width, n, wi;
	while(~scanf("%d%d%d", &height, &width, &n))
	{
		height = min(height, n);
		//build(width, 1, height, 1);
		fill(w, w + (height << 2) + 1, width);

		for(int i = 0; i < n; i ++)
		{
			scanf("%d", &wi);
			printf("%d\n", (w[1] < wi) ? -1 : query(wi, 1, height, 1));
			if(w[1] >= wi) update(wi, 1, height, 1);
		}
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
