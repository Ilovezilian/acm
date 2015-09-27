/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/19 20:07:48
File Name     :1003.cpp
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
#define INF 0x7fffffff
using namespace std;
const int N = 502, mod = 1e9+7;
int c[N][N];

void solve()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++)
		scanf("%d", c[i] + j);

	int op, x, y, xx, yy, val;
	for(int i = 0; i < q; i ++)
	{
		scanf("%d", &op);
		if(op == 1)
		{
			scanf("%d%d%d%d", &x, &y, &xx, &yy);
			int res = 0;
			for(int i1 = x; i1 <= xx; i1 ++)
				for(int i2 = y; i2 <= yy; i2 ++)
					res ^= c[i1][i2];
			printf("%s\n", res ? "Yes" : "No");
		}
		else
		{
			scanf("%d%d%d", &x, &y, &val);
			if(val < 0) val = 0;
			c[x][y] = val;
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
