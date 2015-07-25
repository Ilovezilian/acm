/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/23 13:54:06
File Name     :1002.cpp
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
#define Min(a,b) ((a)< (b)?(a):(b))
#define Max(a,b) ((a)> (b)?(a):(b))
using namespace std;
const int N = 0, mod = 1000000009;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m, x, y, ans;
    while(~scanf("%d%d%d%d", &n, &m, &x, &y))
    {
		if(n>m) swap(n,m), swap(x,y);
		ans = (n + 1) / 2;
		if(n == m && n & 1 && x == y && x == ans) 
		{
			printf("%d\n", ans - 1);
			continue;
		}

		int ans1 = min(max(x - 1,  n - x), min(y, m - y + 1));
		if(ans1 > ans) printf("%d\n", ans1);
		else printf("%d\n", ans);
    }
    return 0;
}
