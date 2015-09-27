/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/19 21:56:50
File Name     :1003_1.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 505, mod = 1e9+7;
int num[N][N];



void solve()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n ; i ++)
		for(int j = 1; j <= m; j ++)
			scanf("%d", num[i] + j);
	int op, x, y, xx, yy, val;
	while(q--)
	{
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d%d%d%d", &x, &y, &xx, &yy);
		}
		else 
		{
			scanf("%d%d%d", &x, &y, &val);
		}
	}
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
