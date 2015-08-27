/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/20 12:36:26
File Name     :1005.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 2020, mod = 1e9+7;

int cnt, dp[N], n, m, a[N], b[N], w[N];

struct buy
{
	int pay, earn;
	buy(){}
};
buy val[100020];

void solve()
{
	memset(dp, 0, sizeof(dp));

	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i ++)
		scanf("%d%d%d", w + i, a + i, b + i);

	cnt = 0;
	for(int i = 0; i < n; i ++)
	{
		if(w[i] > m) continue;

		int c = m / w[i];

		if(!a[i] && !b[i]) continue;

		val[cnt].earn = a[i] + b[i];
	   	val[cnt++].pay = w[i];
		c --;

		if(!a[i]) continue;

		for(int j = 1; j <= c; j *= 2)
		{
			val[cnt].earn = a[i] * j;
		   	val[cnt++].pay = j * w[i];
			c -= j;
			//printf("j = %d\n", j);
		}

		if(c) 
		{
			val[cnt].earn = c * a[i]; 
			val[cnt++].pay = w[i] * c;
		}
	}
	//printf("cnt = %d\n", cnt);

	for(int i = 0; i < cnt; i ++) for(int j = m; j >= val[i].pay; j --) 
		dp[j] = max(dp[j], dp[j-val[i].pay] + val[i].earn);

	printf("%d\n", dp[m]);
}


int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int cas;
	scanf("%d", &cas);
	while(cas--) solve();
    return 0;
}
