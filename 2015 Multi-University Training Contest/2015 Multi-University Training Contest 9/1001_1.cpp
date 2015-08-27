/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/19 22:37:28
File Name     :1001_1.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 111, mod = 1e9+7;
char s[N];
typedef long long LL;
LL f[N], c[N][N], dp[N][N];

void  init()
{
	f[0] = f[1] = 1;
	for(int i = 2; i < N; i ++)
		f[i] = f[i-1] * i % mod;

	for(int i = 0; i < N; i ++) c[i][0] = c[i][1] = c[i][i] = 1;
	for(int i = 2; i < N; i ++) for(int j = 1; j < i; j ++)
		c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;

}

void solve()
{
	int n;
	init();
	while(~scanf("%d", &n))
	{
		memset(dp, 0, sizeof(dp));

		for(int i = 0; i < n; i ++)
			scanf("%I64d", dp[i] + i);
		scanf("%s", s);

		for(int p = 1; p < n; p ++) for(int l = 0; l < n - p; l ++)
		{
			int r = l + p;
			for(int j = l; j < r; j ++)
			{
				LL tmp;
				if(s[j] == '*') tmp = dp[l][j] * dp[j+1][r] % mod;
				else if(s[j] == '+') tmp = (dp[l][j] * f[r-j-1] + dp[j+1][r] * f[j-l]) % mod;
				else tmp = (dp[l][j] * f[r-j-1] - dp[j+1][r] * f[j-l]) % mod;

				dp[l][r] = (dp[l][r] + tmp * c[p-1][j-l]) % mod;
			}
		}
		printf("%I64d\n", (dp[0][n-1] + mod) % mod);
	}
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	solve();   
	return 0;
}
