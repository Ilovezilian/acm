/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/6 17:41:29
File Name     :1001.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100100, mod = 1e9+7;
int n,a[N], b[N], av, ans;
/*
bool judge() 
{ 
	fi(i,1,n) if(a[i] > av + 2 || a[i] < av - 2) return 0;
	return 1; 
}
*/

void cal()
{
	ans = 0;
	fi(i,1,n) if(a[i] - av == 2)
	{
		int l = i - 1, r = i + 1;
		if(l < 1) l = n;
		if(r > n) r = 1;
		a[l] ++, a[r] ++;
		a[i] -= 2;
		ans += 2;
	}
	else if(a[i] - av == -2)
	{
		int l = i - 1, r = i + 1;
		if(l < 1) l = n;
		if(r > n) r = 1;
		a[l] --, a[r] --;
		a[i] += 2;
		ans += 2;
	}
	fi(i,1,n)
	{
		int r = i + 1;
		if(r > n) r = 1;
		if(a[i] > a[r] && (a[i] != av)) a[i] --, a[r] ++, ans ++;
	}
	fd(i,n,1)
	{
		int r = i - 1;
		if(r < 1) r = n;
		if(a[i] > a[r] && (a[i] != av)) a[i] --, a[r] ++, ans ++;
	}
}

void prt()
{
	fi(i,1,n) if(b[i] - av == 2)
	{
		int l = i - 1, r = i + 1;
		if(l < 1) l = n;
		if(r > n) r = 1;
		b[l] ++, b[r] ++;
		b[i] -= 2;
		printf("%d %d\n%d %d\n",i, r, i, l);
	}
	else if(b[i] - av == -2)
	{
		int l = i - 1, r = i + 1;
		if(l < 1) l = n;
		if(r > n) r = 1;
		b[l] --, b[r] --;
		b[i] += 2;
		printf("%d %d\n%d %d\n",r, i, l, i);
	}
	fi(i,1,n)
	{
		int r = i + 1;
		if(r > n) r = 1;
		if(b[i] > b[r] && (b[i] != av)) b[i] --, b[r] ++, printf("%d %d\n", i, r);
	}
	fd(i,n,1)
	{
		int r = i - 1;
		if(r < 1) r = n;
		if(b[i] > b[r] && (b[i] != av)) b[i] --, b[r] ++, printf("%d %d\n", i, r);
	}
}

void solve()
{
	ll sum = 0;
	scanf("%d", &n);
	fi(i,1,n)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
		sum += a[i];
	}
	av = sum / n;
	cal();
	bool ok = 0;
	fi(i,1,n) if(a[i] - av) {ok = 1; break;}
	if(sum % n || ok || (n == 2 && abs(b[2] - b[1]) == 4))
	{
		printf("NO\n");
		return ;
	}
	printf("YES\n");
	printf("%d\n", ans);
	prt();
}

int main()
{
	freopen("1001.in","r",stdin);
	freopen("my.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
	return 0;
}
