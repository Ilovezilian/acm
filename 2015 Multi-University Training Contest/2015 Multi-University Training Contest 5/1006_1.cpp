#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 200100, M = 300010, mod = 1e9+7;

struct edge{
	int u, v;
} e[M<<1];

int n, m, cnt, h[N], pre[M<<1], ne[M<<1], d[N], ans[N];

void init()
{
	memset(ne, -1, sizeof(pre));
	memset(d, 0, sizeof(d));
	memset(h, -1, sizeof(h));
	cnt = 0;
}

void add(int u, int v)
{
	e[cnt].u = u, e[cnt].v = v;
	pre[u] = h[u], h[u] = cnt++;

	e[cnt].u = v, e[cnt].v = u;
	pre[u] = h[v], h[v] = cnt++;
}

void dfs(int u)
{
	while(h[u] + 1)
	{
		d[u] --;
		int i = h[u];
		int v = e[i].v;
		if(i&1) ans[(i>>1)+1] = 0;
		else ans[(i>>1)+1] = 1;

		int pp,nn;
		if(h[i] + 1) h[i] = pre[i];
		pp = pre[i], nn = ne[i];
		if(pp+1)ne[pp] = nn;
		if(nn+1)pre[nn] = pp;

		i^=1;
		if(h[i] + 1) h[i] = pre[i];
		pp = pre[i], nn = ne[i];
		if(pp + 1) pre[nn] = pp;
		if(nn + 1) ne[pp] = nn;

		if(d[u=v]) d[v] --;
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	int x, y;
	fi(i,0,m-1)
	{
		scanf("%d%", &x, &y);
		add(x,y);
		d[x] ++, d[y] ++;
	}

	fi(i,0,cnt-1) if(pre[i] + 1) ne[pre[i]] = i;

	fi(i,1,n) ne[i] = -1;

	fi(i,1, n) if(d[i]&1) dfs(i);

	fi(i,1,n) if(d[i]) dfs(i);

	fi(i,1,m) printf("%d\n", ans[i]);

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
    return 0;
}
