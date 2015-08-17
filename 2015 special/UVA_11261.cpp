#include<bits/stdc++.h>
using namespace std;
#define fi(i,n1,n2) for(int i = n1; i <= n2; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define ll long long
const int N = 83;
int dp[12][N+10][N+10], c[12], a, b, k;

int dfs(int x)
{
	memset(dp, 0, sizeof(dp));

	int tempx = x;
	fd(i,10,0) c[i] = tempx % 10, tempx /= 10;

	int ans1 = 0, ans2 = 0;
	/*
	*/
	fi(i,0,9)
	{
		ans1 = (ans1 + c[i]) % k;
		ans2 = (ans2 * 10 + c[i]) % k;
		fi(j,0,k-1) fi(l,0,k-1) fi(p,0,9)
			dp[i+1][(j+p)%k][(l*10+p)%k] += dp[i][j][l];

		fi(j,0,c[i+1]-1)
			dp[i+1][(ans1+j)%k][(ans2*10+j)%k] ++;
	}

	int ans = dp[10][0][0];
	if((ans1 + c[10]) % k == 0 && (ans2 * 10 + c[10]) %k == 0)
		ans ++;
	return ans;
}

void solve()
{
	scanf("%d%d%d", &a, &b, &k);
	//printf("dfs(%d) = %d dfs(%d) = %d\n", a-1, dfs(a-1), b, dfs(b));
	if(k >= N) puts("0");
	else printf("%d\n", dfs(b) - dfs(a-1));
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
	return 0;
}
