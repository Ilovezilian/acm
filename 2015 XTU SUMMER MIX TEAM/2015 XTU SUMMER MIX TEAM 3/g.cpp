/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/16 21:29:47
File Name     :g.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 500050, mod = 1e9+7;

int dp[N], sum[N], n, q[N], m;

bool judge(int j,  int k, int i)
{
	 return dp[j] + sum[j] * sum[j] - (dp[k] + sum[k] * sum[k]) <= sum[i] * 2 * (sum[j] - sum[k]);
}

bool judge1(int j, int k, int i)
{
	return (dp[k] + sum[k] * sum[k] - (dp[j]  + sum[j] * sum[j])) * (sum[i] - sum[k]) >= (dp[i] + sum[i] * sum[i] - (dp[k] + sum[k] * sum[k])) * (sum[k] - sum[j]);
}

void solve()
{
	while(~scanf("%d%d", &n, &m))
	{
		fi(i,1,n) scanf("%d", sum + i);
		
		sum[0] = 0;
		fi(i,1,n) sum[i] += sum[i-1];

		int head, tail;
		head = tail = 0;
		q[tail++] = 0;
		fi(i,1,n)
		{
			while(head + 1 < tail && judge(q[head+1], q[head], i))
				head ++;

			dp[i] = dp[q[head]] + (sum[i] - sum[q[head]]) * (sum[i] - sum[q[head]]) + m;

			while(head + 1 < tail && judge1(q[tail-2], q[tail-1], i))
				tail --;
			q[tail++] = i;
		}
		printf("%d\n", dp[n]);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
 	solve();   
    return 0;
}
