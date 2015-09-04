/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/31 10:19:44
File Name     :test.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

int pow_mod(int a, int n, int m)
{
	if(!n) return 1;
	int x = pow_mod(a, n / 2, m);
	long long ans = (long long) x * x % m;
	if(n&1) ans = ans * a % m;
	return (int) ans;
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	int n, a, m;
	while(~scanf("%d%d%d", &a, &n, &m))
	{
		printf("%d\n", pow_mod(a, n, m));
	}
    
    return 0;
}
