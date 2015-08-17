/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/12 14:18:15
File Name     :1011.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100010, mod = 1e9+7;

int next[N][2], fp[N], head[N], n, p, t;
bool vis[N];

void init()
{
	fp[0] = fp[1] = 1;
	fi(i, 2, N) fp[i] = (fp[i-1] * i) % mod;
	t = 1;
}
void init_1()
{
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	p = 0;
}

void add(int u, int v)
{
	next[p][1] = v, next[p][0] = head[u], head[u] = p ++;
	next[p][1] = u, next[p][0] = head[v], head[v] = p ++;
}

ll dfs(int u)
{
	int cnt = 0, s = 0;
	ll ans_1 = 1, ans;
	//printf("u = %d\n", u);
	for(int i = head[u]; i + 1; i = next[i][0]) if(!vis[i>>1])
	{
		vis[i>>1] = 1;
		cnt ++;
		int v = next[i][1];
		//printf("u = %d v = %d\n", u, v);
		if(!(head[v] + 1)) 
		{
			vis[v>>1] = 1;
			s ++;
		}
		else ans_1 = ans_1 * dfs(v) % mod;
	}
	ans = (ans_1 * fp[s]) % mod;
	if(cnt - s != 2) ans = ans * 2 % mod;
	printf("u = %d ans = %I64d\n", u, ans);
	return ans;
}

void solve()
{
	init_1();
	int x, y;
	scanf("%d", &n);
	fi(i,0, n-2)
	{
		scanf("%d%d", &x, &y);
		add(x,y);
	}
	/*
	printf("p = %d\n", p);

	printf("head[3] = %d\n", head[3]);
	
	for(int i = head[3]; i + 1; i = next[i][0])
		printf("(3, %d)\n", next[i][1]);

	printf("xiaofenzi\n");

	printf("xiaoshazi\n");
	*/

	printf("Case #%d: %I64d\n", t, dfs(1));
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int cas;
	init();
	scanf("%d", &cas);
	while(cas --) solve();
    return 0;
}
