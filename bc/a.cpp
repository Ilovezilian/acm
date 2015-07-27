/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/25 18:59:47
File Name     :a.cpp
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
const int N = 0, mod = 1e9+7;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m, p, q, cas;
	scanf("%d", &cas);
	while(cas --)
	{
		scanf("%d%d%d%d", &n, &m, &p, &q);
		int ans = 0;
	   if(m * p > q) 
	   {
		   ans = n / m * q, n %= m;
			if(n * p < q) ans += n * p;
			else ans += q;
	   }
	   else  ans = p * n;
		printf("%d\n", ans);

	}
    return 0;
}
