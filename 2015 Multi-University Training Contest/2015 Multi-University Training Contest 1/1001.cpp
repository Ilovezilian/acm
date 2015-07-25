/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/21 21:07:38
File Name     :1001.cpp
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
#define ll long long 
using namespace std;
const int N = 111010, mod = 1e9+7, maxn = 10001;

int l[N], r[N], pr[N], la[N], a[N];
int main()
{
	int n;
	long long ans;
	while(~scanf("%d", &n))
	{
		for(int i = 1; i <= n ; i ++)
		{	
			scanf("%d", a + i);
			l[i] = 1, r[i] = n;
		}

		memset(pr, 0, sizeof(pr));
		memset(la, 0, sizeof(la));

		for(int i = 1; i <= n ; i ++)
		{
			for(int j = a[i]; j < maxn; j += a[i])
				if(pr[j] && r[pr[j]] == n) r[pr[j]] = i - 1;
			pr[a[i]] = i;
		}

		for(int i = n; i ; i --)
		{
			for(int j = a[i]; j < maxn; j += a[i]) 
				if(la[j] && l[la[j]] == 1) l[la[j]] = i + 1;
			la[a[i]] = i;
		}	
		/*
		   for(int i = 1; i <= n ; i ++)
		   printf("%d [%d, %d]\n", i, l[i], r[i]);
		   */
		ans = 0;
		for(int i = 1; i <= n; i ++)
			ans = (ans + (ll)(i - l[i] + 1) * (r[i] - i + 1) % mod) % mod;
		printf("%I64d\n", ans);
	}
	return 0;
}

