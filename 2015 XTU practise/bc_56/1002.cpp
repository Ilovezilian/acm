/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/19 19:26:24
File Name     :1002.cpp
************************************************ */

#include<cstdio>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
const int N = 1010, mod = 1e9+7;
int num[N];
long long cnt[2][N];

void solve()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d", num + i);
		num[i] = (num[i] % p + p) % p;
	}

	memset(cnt[0], 0, sizeof(cnt[0][0]) * p);
	memset(cnt[1], 0, sizeof(cnt[0][0]) * p);
	
	cnt[0][0] = 1;
	bool ro = 0;
	for(int i = 0; i < n; i ++)
	{
		ro ^= 1;
		for(int j = p - 1; j + 1; j --) if(cnt[j])
		{
			int t = (j+num[i]) % p;
			cnt[ro][t] = cnt[ro^1][t] + cnt[ro^1][j];
			cnt[ro][t] %= mod;
		}
		/*
		for(int k = 0; k < p; k ++)
			printf("%d %I64d\n", ro, cnt[ro][k]);
		*/
	}
	printf("%I64d\n", cnt[0][0]);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int T;
	scanf("%d", &T);
	while(T --) solve();
    return 0;
}
