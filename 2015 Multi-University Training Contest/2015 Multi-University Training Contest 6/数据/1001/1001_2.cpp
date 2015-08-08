/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/7 14:40:19
File Name     :1001_2.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100100, mod = 1e9+7;
int a[N], b[N], av, ans, n;

bool solve1()
{
	ans = 0;
	fi(i,2,n)
	{
		int r = i + 1;
		if(r > n) r = 1;
		if(a[i] > 0) a[i] --, a[r] ++, ans ++;
		else if(a[i] < 0) a[i] ++, a[r] --, ans ++;
	}

	//fi(i,1,n) printf("a[%d] = %d\n" ,i, a[i]);
	fi(i,1,n) if(a[i]) return 0;
	return 1;
}

void prt()
{
	fi(i,2,n)
	{
		int r = i + 1;
		if(r > n) r = 1;
		if(b[i] > 0) b[i] --, b[r] ++, printf("%d %d\n", i, r);
		else if(b[i] < 0) b[i] ++, b[r] --, printf("%d %d\n", r, i);
	}
}

bool judge()
{
	if(solve1())
	{
		printf("YES\n%d\n", ans);
		prt();
	//printf("3test\n");
		return 1;
	}

	memcpy(a, b, sizeof(b[0]) * (n + 1));
	if(a[1] >= 0 && a[1] <= 2)
	{
		a[1] --, a[2] ++;
		if(solve1())
		{
			b[1] --, b[2] ++;
			printf("YES\n%d\n", ans+1);
			printf("1 2\n");
			prt();
	//printf("1test\n");
		return 1;
		}
	}

	memcpy(a, b, sizeof(b[0]) * (n + 1));
	if(a[1] <= 0 && a[1] >= -2)
	{
		a[1] ++, a[2] --;
		if(solve1())
		{
			b[1] ++, b[2] --;
			printf("YES\n%d\n", ans+1);
			printf("2 1\n");
			prt();
	//printf("2test\n");
		return 1;
		}
	}

	//printf("4test\n");
	return 0;
}

void solve()
{
	ll sum = 0;
	scanf("%d", &n);
	fi(i,1,n)
	{
		scanf("%d", a + i);
		sum += a[i];
	}

/*
	bool ok = 1;
	fi(i,1,n) if(a[i] != a[i-1]) { ok = 0; break;}
	if(ok)
	{
		printf("YES\n0\n");
		return;
	}
*/

	if(sum % n || (n == 2 && abs(a[2] - a[1]) == 4)) 
	{
		printf("NO\n");
		return;
	}
	av = sum / n;
	fi(i,1,n) b[i] = a[i] = a[i] - av;

	if(!judge()) 
	{
		printf("NO\n");
		return;
	}
}

int main()
{
	freopen("1001.in","r",stdin);
	freopen("my_1.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
	return 0;
}
