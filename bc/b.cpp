/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/25 19:12:14
File Name     :b.cpp
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
const int N = 111, mod = 1e9+7;
char s[N], t[] = "anniversary";
int vis[N], mark;
int len, h;

bool dfs(int a, int b)
{
	h ++;
	int j, k;
	for(int i = a; i < len; i ++)
	{
		k = b;
		if(s[i] == t[k])
		{
			k ++;
			for(j = i+1; j < len; j ++, k ++) if(s[j] != t[k]) break;
			if(t[k] == '\0' && h <= 3) return 1;
			if(dfs(j, k)) return 1;
		}
	}
	h --;
	return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --)
	{
		scanf("%s", s);
		len = strlen(s);
		h = 0;
		printf("%s\n", dfs(0, 0) ? "YES" : "NO");
	}
    return 0;
}
