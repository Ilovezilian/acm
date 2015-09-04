/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/31 19:00:28
File Name     :c.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 100010, mod = 1e9+7;

int cnt[4][N];


void solve()
{
	memset(cnt, 0, sizeof(cnt));
	int n, x, mt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d", &x);
		cnt[0][x] ++;
		//cnt[2][x] ++;
	}

	for(int i = 0; i < n; i ++)
	{
		scanf("%d", &x);
		cnt[1][x] ++;
		mt = max(mt, x);
		//cnt[3][x] ++;
	}
	/*
	if(!n)
	{
		printf("Minimalni budova obsahuje 0 kostek, maximalni 0 kostek.\n");
		return;
	}
	*/

	for(int i = mt; i; i --)
	{
		cnt[0][i] += cnt[0][i+1];
		cnt[1][i] += cnt[1][i+1];
	}

	int ans_min = 0, ans_max = 0;
	for(int i = mt; i ; i --)
	{
		ans_min += max(cnt[0][i], cnt[1][i]);
		ans_max += cnt[0][i] * cnt[1][i];
	}

	printf("Minimalni budova obsahuje %d kostek, maximalni %d kostek.\n", ans_min, ans_max);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
 	int cas;
 	scanf("%d", &cas);
	while(cas --); //solve();	
    return 0;
}
