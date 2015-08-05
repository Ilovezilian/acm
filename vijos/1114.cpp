/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/3 15:01:33
File Name     :1114.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 11, mod = 1e9+7;
char s[1<<N];

void dfs(int l, int r)
{
	if(l == r) 
	{
		printf("%c", s[l] == '1' ? 'I' : 'B');
		return;
	}
	//printf("l = %d r = %d\n", l, r);
	int mid = l + (r - l) / 2;
	dfs(l, mid), dfs(mid+1, r);
	bool ok1 = 0, ok2 = 0;
	fin(i,l,r+1)
	{
		if(s[i] == '1') ok1 = 1;
		else ok2 = 1;
		if(ok1 && ok2) 
		{
			printf("F");
			break;
		}
	}
	if(! (ok1 && ok2)) printf("%c", ok1 ? 'I' : 'B');
}

void solve()
{
	int n;
	scanf("%d %s", &n, s);
	int len = 1<<n;
	dfs(0, len - 1);
	printf("\n");
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
