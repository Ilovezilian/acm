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
	fi(i,1,n)
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
	fi(i,1,n)
	{	
		int r = i + 1;
		if(r > n) r = 1;
		if(b[i] > 0) b[i] --, b[r] ++, printf("%d %d\n", i, r);
		else if(b[i] < 0) b[i] ++, b[r] --, printf("%d %d\n", r, i);
	}
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
	if(sum % n) 
	{
		printf("NO\n");
		return;
	}
	av = sum / n;
	fi(i,1,n) b[i] = a[i] = a[i] - av;
	if(!solve1()) 
	{
		printf("NO\n");
		return;
	}
	printf("YES\n%d\n", ans);
	prt();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
	return 0;
}
