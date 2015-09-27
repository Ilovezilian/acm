/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/19 19:11:40
File Name     :1001.cpp
************************************************ */

//#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
const int N = 502, mod = 1e9+7;

int kind[N];

void solve()
{
	memset(kind, 0, sizeof(kind));
	int x, y, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d%d", &x, &y);
		kind[x] += y;
	}
	int ans = 0;
	for(int i = 0; i < N; i ++) if(kind[i])
	{
		ans += kind[i] / 64 + (kind[i] % 64 ? 1 : 0);
	}
	printf("%d\n", ans / 36 + (ans % 36 ? 1 : 0));
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int T;
	scanf("%d", &T);
	while(T --) solve();
    return 0;
}
