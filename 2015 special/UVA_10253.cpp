/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/16 11:37:36
File Name     :UVA_10253.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define lli long long
using namespace std;
const int N = 35, mod = 1e9+7;
lli f[N], d[N][N];


lli C(lli n, lli m)
{
	double ans = 1;
	fi(i,0,m-1) ans *= n - i;
	fi(i,0,m-1) ans /= i + 1;
	return (lli) (ans + 0.5);
}

void solve()
{
	f[1] = 1;
	int n = 30;
	memset(d, 0, sizeof(d));

	d[0][0] = 1;
	fi(i,1,n) d[i][0] = d[i][1] = 1;

	fi(i,1,n)
	{
		fi(j,2,n)
		{
			for(int p = 0; p * i <= j; p ++) 
				d[i][j] += C(f[i] + p - 1, p) * d[i-1][j-p*i];
		}
		f[i+1] = d[i][i+1];
	}

	while(~scanf("%d", &n) && n) printf("%lld\n", n == 1 ? 1 : (2 * f[n]));
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);

	solve();
	return 0;
}
