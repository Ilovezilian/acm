/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/24 13:41:16
File Name     :1007.cpp
 ************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define INF 0x0x7fffffff
#define ll long long
using namespace std;
const int N = 9, mod = 1e9+7;
int n, m,cnt[N], c1[N], c2[N], ans;

struct kk
{
	int x, y;
} e[N * N];

void dfs(int i)
{
	if(i == m)
	{
		ans ++;
		return;
	}
	int x = e[i].x, y = e[i].y;
	cnt[x] --, cnt[y] --;
	if(c1[x] && c1[y])
		c1[x]--, c1[y] --, dfs(i + 1), c1[x] ++, c1[y] ++;
	if(c2[x] && c2[y])
		c2[x]--, c2[y] --, dfs(i + 1), c2[x] ++, c2[y] ++;
	cnt[x] ++, cnt[y] ++;
}

void solve()
{
	scanf("%d%d", &n, &m);
	int x, y;
	memset(cnt, 0, sizeof(cnt));

	fi(i,m) 
	{
		scanf("%d%d", &x, &y);
		e[i].x = x, e[i].y = y;
		cnt[x] ++, cnt[y] ++;
	}

	fi(i,n+1) if(cnt[i] & 1) 
	{
		printf("0\n");
		return;
	}

	ans = 0;
	fi(i,n+1) c1[i] = c2[i] = cnt[i]/2;

	dfs(0);
	printf("%d\n", ans);
}


int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --)
	{
		solve();
	}
	return 0;
}
