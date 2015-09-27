/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/12 9:23:15
File Name     :e_3.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
typedef long long LL;

LL pw[33][1025];

void init()
{
	for(int i = 0; i < 1025; i ++) pw[0][i] = 1;

	for(LL i = 2, j = 1;i < 1025; i ++)
	{
		for(; pw[i][j] <= INF; j ++)
			pw[i][j] = pw[i][j-1] * j;
	}
}

void b_s(int cnt, int x, int z)
{
	int l = x + 1, r 
}

void solve()
{
	init();
	int k;
	while(~scanf("%d", &k) && k)
	{
		int b = (int) sqrt(k), ans = 0;
		if(b * b == k)
			ans = (b - 1) >> 1;

		int cnt;
		for(int z = 3; z < 33; z ++)
		{
			for(int x = 1; ; x ++)
			{
				if(pw[z][x] == 0) break;
				cnt = k - pw[x][z];
				if(cnt < pw[x][z]) break;
				b_s(cnt, x, z);
			}
		}
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
