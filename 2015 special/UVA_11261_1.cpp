#include<bits/stdc++.h>
#define fi(i,n1,n2) for(int i = n1; i <= n2; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
using namespace std;

int a, b, k;
int dp[12][110][110];
int pw[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int dfs(int d, int m1, int m2)
{
	if(!d) return (!m1 && !m2) ? 1: 0;
	if(dp[d][m1][m2] >= 0) return dp[d][m1][m2];
	dp[d][m1][m2] = 0;
	fi(i,0,9)
		dp[d][m1][m2] += dfs(d-1, ((m1-i)%k + k) %k, ((m2-i*pw[d-1]%k)+k)%k);
	return dp[d][m1][m2];
}

int func(int n)
{
	int d = 0, m1 = 0, m2 = 0, a[15];
	if(n == 0) a[d++] = 0;
	while(n)
	{
		a[d] = n%10;
		n /= 10;
		d++;
	}
	int ans = 0;
	fd(i,d-1,1)
	{
		for(int j = 0; j < a[i]; j ++)
		//fi(j,0,a[i]-1) 
			ans += dfs(i, (k-(m1+j)%k)%k, (k-(m2+pw[i]*j)%k)%k);
		m1 += a[i], m2 += pw[i] * a[i];
	}
	//int zz = a[i];
	fi(j,0,a[0])
	//for(int j = 0; j <= a[0]; j ++)
		ans += dfs(0, (k-(m1+j)%k)%k, (k-(m2+pw[0]*j)%k)%k);
	return ans;

}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &a, &b, &k);
		if(k>85) printf("0\n");
		else 
		{
			memset(dp, -1, sizeof(dp));
			printf("%d\n", func(b) - func(a-1));
		}
	}
	return 0;
}
