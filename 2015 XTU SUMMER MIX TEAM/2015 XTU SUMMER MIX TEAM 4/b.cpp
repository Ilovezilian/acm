/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/24 10:04:48
File Name     :b.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

void solve()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%s\n", (a + b + c == 180 && a && b && c) ? "YES" : "NO");
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int cas;
	scanf("%d", &cas);
	while(cas --) solve();
    return 0;
}
