/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/18 14:20:47
File Name     :1001.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 101, mod = 1e9+7;

long long dp[N][N];
int a[N], n;
char s[N];

long long cal(long long a, long long b, char c, int i, int j, int k)
{
	long long ans;
	if(c == '+') ans = a + b;
	else if( c == '-') ans = a - b;
	else ans = a * b;
	printf("dp[%d][%d] %I64d %c dp[%d][%d] %I64d = dp[%d][%d] %I64d\n", i, k, a, c, k+1, j, b, i, j, ans);
	//printf("%I64d %c dp[%d][%d] %I64d = dp[%d][%d] %I64d\n", i, k, i, j, a, c, k, j, b, i, j, ans);
	//printf("dp[0][%d] = %I64d\n", n - 1, dp[0][n-1]);
	return ans;
}

void solve()
{
	while(~scanf("%d", &n))
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i ++) scanf("%I64d", &dp[i][i]);

		scanf("%s", s);

		for(int p = 1; p < n; p ++)
		{
			for(int i = 0; i < n - p; i ++) 
			for(int k = i; k < i + p; k ++)
			{
				dp[i][i+p] = (dp[i][i+p] + cal(dp[i][k], dp[k+1][i+p], s[k], i, i + p, k)); //% mod) % mod;
			}
		}
		//printf("%I64d\n", dp[0][n-1]); //% mod);
		printf("dp[0][%d] = %I64d\n", n - 1, dp[0][n-1]); //% mod);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
