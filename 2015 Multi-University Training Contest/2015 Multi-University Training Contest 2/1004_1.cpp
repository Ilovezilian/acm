/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/25 11:59:49
File Name     :1004_1.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define INF 0x0x7fffffff
#define ll long long
using namespace std;
const int N = 1e+5 + 10, mod = 1e9+7;
ll dp1[N], dp2[N];
int apple1[N], apple2[N], r1, r2, l, n, k;

void solve()
{
	scanf("%d%d%d", &l, &n, &k);
	int a, x;
	r1 = r2 = 0;
	fi(i,n)
	{
		scanf("%d%d", &x, &a);
		if(!x) continue;
		fi(j,a)
		{
			if(x * 2 < l) apple1[++r1] = x;
			else apple2[++r2] = l - x;
		}
	}
	
	apple1[0] =apple2[0] = dp1[0] = dp2[0] = 0;
	sort(apple1, apple1 + r1 + 1);
	sort(apple2, apple2 + r2 + 1);

	fin(i,1,r1 + 1) dp1[i] =  dp1[max(0, i-k)] + apple1[i] * 2;
	fin(i,1,r2 + 1) dp2[i] =  dp2[max(0, i-k)] + apple2[i] * 2;
	
	//fi(i,r1) printf("dp1[%d] = %I64d\n", i, dp1[i]);
	//fi(i,r2) printf("dp2[%d] = %I64d\n", i, dp2[i]);
	
	ll ans = dp1[r1] + dp2[r2], tp;
    for(int i = 0; i <= k && i <= r1; i ++) 
	{
		ll tp = dp1[r1 - i] + dp2[max(0, r2 - (k - i))] + l;
		ans = min(ans, tp);
		//printf("tp = %I64d ans = %I64d\n", tp, ans);
	}
	printf("%I64d\n", ans);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int cas;
   scanf("%d", &cas);
	while(cas --) solve();	
    return 0;
}
