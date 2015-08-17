/* ***********************************************
 * #include<cstring>
Author        :Ilovezilian
Created Time  :2015/8/12 14:18:15
File Name     :1011.cpp
************************************************ */


#include<vector> 
#include<cstdio>
#include<algorithm>
#include<cstring>
//#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#pragma comment(linker, "/STACK:102400000,102400000")  
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100010, mod = 1e9+7;

int n, p, t;
ll fp[N];
bool vis[N],ok;
vector<int> v[N];

void init()
{
	fp[0] = fp[1] = 1;
	fi(i, 2, N) fp[i] = (fp[i-1] * i) % mod;
	t = 1;
}

void init_1()
{
	fi(i,1,n) if(!v[i].empty()) v[i].clear();

	memset(vis, 0, sizeof(vis));
	p = 0;
}

ll dfs(int u)
{
	if(ok) return 0;
	int cnt = 0, s = 0;
	ll ans_1 = 1, ans;
	fi(i,0,v[u].size()-1) if(!vis[v[u][i]])
	{
		cnt ++;
		int p = v[u][i];
		vis[p] = 1; 
		//printf("u = %d\n", u);
		if(v[p].size() == 1) 
		{
			vis[p] = 1;
			s ++;
		}
		else ans_1 = ans_1 * dfs(p) % mod;
	}

	if(cnt - s > 2) { ok = 1;return 0;}

	ans = (ans_1 * fp[s]) % mod;
	if(cnt - s != 2) ans = ans * 2 % mod;
	//printf("u = %d ans = %I64d\n", u, ans);
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
		v[x].push_back(y), v[y].push_back(x);
	}
	//printf("xiaofengzi\n");
	vis[1] = 1;
	ok = 0;
	printf("Case #%d: %I64d\n", t ++, n == 1 ? 1 : dfs(1) );
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

