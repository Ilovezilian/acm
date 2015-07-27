/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/27 20:08:45
File Name     :d1.cpp
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
const int N = 10100, mod = 1e9+7;
int vis[N];

int main()
{
    int t, n, m, u, v;
	scanf("%d", &t);
	while(t --)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		fi(i,m)
		{
			scanf("%d%d", &u, &v);
			if(!vis[u] && !vis[v]) vis[u] = -1, vis[v] = 1;
			else if(!vis[u]) vis[u] = -vis[v];
			else if(!vis[v]) vis[v] = - vis[u];
		}

		int s1 = 0, s2 = 0;
		fi(i,n+1) 
			if(vis[i] == -1) s1 ++;
			else if(vis[i] == 1) s2 ++;
		if(s1 + s2 == n) {puts("0"); continue;}
		if(s1 < s2) s1 = s2;
		else s2 = s1;
		int k = n -  2 * s1;
		s1 += k / 2; s2 += k - k / 2;
		printf("%d\n", s1 * s2 - m);
	}
    return 0;
}
