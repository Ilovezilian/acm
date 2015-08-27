/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/20 15:55:00
File Name     :1011.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 100010, mod = 1e9+7;
typedef long long LL;
LL a[N], n;

void solve()
{
	LL ans = 1;
	scanf("%d", &n);
	for(LL i = 0; i < n / 2; i ++)
	{
		ans = ans * (n - i) / (i + 1) % mod;
	}
	ans = ans * ans % mod;
	if(!(n & 1)) ans = ans * 
	printf("I64d\n", ans);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    
	int cas;
	scanf("%d" , &cas);
	while( cas --) solve();

    return 0;
}
