/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/29 21:55:21
File Name     :1005_2.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 0, mod = 7;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int a, b, n, f1, f2;
	while(~scanf("%d%d%d", &a, &b, &n))
	{
		f1 = f2 = 1;
		for(int i = 1; i <= n; i ++)
		{
			printf("f[%d] = %d\n", i, f1);
			f1 = (a * f1 + b * f2) % mod;
			f1 ^= f2, f2 ^= f1, f1 ^= f2;
		}
	}
    
    return 0;
}
