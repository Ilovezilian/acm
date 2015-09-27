/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/16 23:26:10
File Name     :d.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 2*1e5+10, mod = 1e9+7;

long long a[N], mi[9][11], dp[2][N];

void init()
{
	for(int j = 2; j < 9; j ++) mi[j][0] = 1;
	for(int j = 2; j < 9; j ++) for(int i = 1; i < 11; i ++)
		mi[j][i] = mi[j][i-1] * j;
}

void solve()
{
	int n, k, x;
	init();
	while(~scanf("%d%d%d", &n, &k, &x))
	{
		for(int i = 0; i < n; i ++)
			scanf("%I64d", a + i);

		dp[0][0] = a[0], dp[1][n-1] = a[n-1];
		for(int i = 1; i < n; i++)
		{
			dp[0][i] = dp[0][i-1] | a[i];
			dp[1][n-1-i] = dp[1][n-i] | a[n-1-i];
		}

		long long ans = 0, tmp;
		for(int i = 0; i < n; i++)
		{
			tmp = a[i] * mi[x][k];
			if(i) tmp |= dp[0][i-1];
			if(i != n - 1) tmp |= dp[1][i+1];
			ans = max(ans, tmp);
		}
		/**
		printf("%I64d\n", mi[x][k]);
		for(int i = 0; i < n; i ++)
			printf("%I64d %I64d\n", dp[0][i], dp[1][i]);
		*/

		printf("%I64d\n", ans);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
