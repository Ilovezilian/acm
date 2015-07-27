/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/26 13:16:40
File Name     :d.cpp
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
    
	int n, cas, m, x, y;
	scanf("%d", &cas);
	while(cas --)
	{
		scanf("%d%d", &n, &m);
		fi(i,m) scanf("%d%d", &x, &y);
		int ans = (1 + n) / 2 * (n / 2) - m;
		if(ans < 0) ans = 0;
		printf("%d\n", ans);
	}
    return 0;
}
