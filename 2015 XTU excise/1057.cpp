/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/10 13:59:14
File Name     :1057.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
int dp[22][11], a[33], d_cnt;

int dfs(int cnt, int x, int k, int b)
{
	int tmp = x % b, ret = 0;
	ret += tmp * dp[cnt-1][0];
	dp[cnt][0] = dp[cnt-1][0] * b;

	return ret + dfs(cnt+1, x / b, k, b);
}

void solve()
{
	int x, y, k, b, ans;
	while(~scanf("%d%d%d%d", &x, &y, &k, &b))
	{
		dec(y, b);
		ans = dfs(i, a[i], k, b);

		dec(x-1, b);
		ans -= dfs(i, a[i], k, b);

		printf("%d\n", ans);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
