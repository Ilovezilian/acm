/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/15 10:24:23
File Name     :UVALive_4123.cpp
 ************************************************ */

//#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 1010, mod = 1e9+7;

ll d[N][5][2];

void init()
{
	memset(d, 0, sizeof(d));
	d[1][0][0] = d[1][0][1] = 1;
	fi(i,2,N) 
	{
		d[i][0][0] = d[i-1][0][0];
		d[i][0][1] = d[i-1][0][1];
		fi(j,1,4)
		{
			d[i][j][0] = d[i-1][j][0] + d[i-1][j-1][0];
			d[i][j][1] = d[i-1][j][1] + d[i-1][j-1][1];
		}
	}
}

void solve()
{
	int l, cas = 1;
	init();
	while(~scanf("%d", &l) && l)
	{
		printf("Case %d: ", cas ++);
		if(l<3 || l&1) puts("0");
		else printf("%lld\n", d[(l+4)/2][3][0] + d[(l+4)/2][4][1] + d[(l+4)/2][4][0]);

	}
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	solve();
	return 0;
}
