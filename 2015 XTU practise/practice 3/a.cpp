/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/11 13:17:11
File Name     :a.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
int dp[10];

int dfs(int n, int di)
{
	if(!n) return 0;
	int t = n % 10;
	dp[di] = 8 * dp[di-1];
	if(t >= 8) return dp[di-1] * (t - 2) + dfs(n / 10, di + 1);
	if(t >= 3) return dp[di-1] * (t - 1) + dfs(n / 10, di + 1);
	return t * dp[di-1] + dfs(n / 10, di + 1);
}

void solve()
{
	int n;
	dp[0] = 1;
	while(scanf("%d", &n) && n) printf("%d: %d\n", n, dfs(n,1));
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
