/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/1 9:07:53
File Name     :d.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e7 + 10, mod = 1e9+7;
int wei[20];

void init()
{
	wei[0] = 1;
	for(int i = 1; wei[i-1] < N; i ++)
	{
		wei[i] = wei[i-1] * 3;
		//val[i] = (val[i-1] + wei[i-1]) * 3 - wei[i-1];
		//printf("wei[%d] = %d val[%d] = %d\n", i, wei[i], i, val[i]);
	} //printf("cnt = %d  %d N = %d\n", cnt,cnt * cnt, N);
}

void solve()
{
	int k, ans[20];
	memset(ans, 0, sizeof(ans));

	scanf("%d", &k);

	for(int i = 15; i + 1; i --)
	{
		if(k >= wei[i])
		{
			ans[i] = k / wei[i];
			k %= wei[i];
		}
	}
	
	int i = 15;
	while(!ans[--i]);
	for(; i + 1; i --)
		printf("%d%c", ans[i], i ? ' ' : '\n');
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int cas;
	init();
	scanf("%d", &cas);
	while(cas --) solve();
    return 0;
}
