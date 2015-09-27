/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/8 22:05:26
File Name     :j.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e5+10, mod = 1e9+7;
int a[N], kcas = 1;


void solve()
{
	int n, m, ans, tmp;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%d", a + i);

	ans = 0;
	int i, j;
	for( i = 0; i < n; i ++)
	{
		tmp = a[i];
		for(j = i; j < n;)
		{
			if(tmp >= m) break;
			tmp |= a[++j];
		}
		ans += j - i;
	}
	printf("Case #%d: %d\n", kcas ++, ans);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int T;
	scanf("%d", &T);
	while(T--) solve();
    return 0;
}
