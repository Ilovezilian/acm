/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/5 14:09:22
File Name     :1006.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 300100, mod = 1e9+7;

struct nod{
	int x, y, o, in, out, cnt;
} e[N];

vector<int> v[N/3];
int d[N/3];

void init()
{
}

void dfs(int x, int y)
{
	
}

void solve()
{
	memset(d, 0, sizeof(d));

	scanf("%d%d", &n, &m);
	int x, y;
	fi(i,0,n-1)
	{
		scanf("%d%d", &x, &y);
		e[i].o = i, e[i].x = x, e[i].y = y;
		d[x] ++ , d[y] ++;
		v[x].push_back(y), v[y].push_back(x);
	}

	dfs();
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
