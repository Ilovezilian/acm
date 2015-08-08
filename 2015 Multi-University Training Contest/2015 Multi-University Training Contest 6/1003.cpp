/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/6 12:53:10
File Name     :1006.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100010, mod = 1e9+7;
bool vis[N];
int ans[N],cnt, n;

void dfs(int z)
{
	if(z == 0)
	{
		printf("%d ", cnt);
		fi(i,1,cnt) printf("%d%c",ans[i], i!=cnt ? ' ' : '\n');
		return;
	}
	int k = min(n, z);
	fd(i,k,1) if(!vis[i])
	{
		vis[i] = 1;
		ans[++cnt] = i;
		dfs(z - i);
		break;
	}
}

void solve()
{
	int m;
	scanf("%d%d", &n,&m);
	ll sum = n * (n+1) / 2;
	if(sum % m || n < m) 
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	int pp = sum / m;
	memset(vis, 0, sizeof(vis));
	fi(i,1,m) cnt = 0, dfs(pp);
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
