/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/16 23:15:30
File Name     :a.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

void solve()
{
	int x;
	while(~scanf("%d", &x))
	{
		int ans = 0;
		while(x)
		{
			if(x&1) ans ++;
			x >>= 1;
		}
		printf("%d\n", ans);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
