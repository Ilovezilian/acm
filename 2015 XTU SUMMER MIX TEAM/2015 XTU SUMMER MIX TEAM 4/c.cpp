/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/24 10:12:26
File Name     :c.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

void solve()
{
	int sum = 0, k, n, m, a[101];
	scanf("%d%d%d", &k, &m, &n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d", a + i);
		sum += a[i];
	}
	sum = k - sum;
	sort(a, a + n);
	int cnt = 0;
	for(int i =  n - 1; i + 1; sum += a[i], i --, cnt ++) 
	{
		//printf("i = %d cnt = %d sum = %d\n", i, cnt, sum);
		if(sum >= m) break;
	}
	printf("%d\n", cnt);
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
