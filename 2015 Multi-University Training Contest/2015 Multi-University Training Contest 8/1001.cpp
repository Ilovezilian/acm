#include<bits/stdc++.h>

#define fi(i,n1,n2) for(int i = n1; i <= n2; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define ll long long 
using namespace std;
const int N = 200010, mod = 1e+9+7;
int a[N], buy[N], sell[N], total, l, r;
ll ans;

struct nod{
	int val, cnt;
} q[N];

void Max(int v)
{
	int num = 0;
	while(l <= r && q[l].val < v) num += q[l++].cnt;
	if(num) q[--l].cnt = num, q[l].val = v;
}

void Min(int v)
{
	while(l <= r && q[r].val > v) 
	{
		ans -= (ll) q[r].val * q[r].cnt;
		total += q[r--].cnt;
	}
}

void Del(int num)
{
	while(num)
	{
		int v = min(num, q[l].cnt);
		q[l].cnt -= v;
		num -= v;
		if(!q[l].cnt) l ++;
	}
}

void solve()
{
	int n, c;
	scanf("%d%d", &n, &c);
	fi(i,1,n) scanf("%d", a + i);
	fi(i,0,n) scanf("%d%d", buy + i, sell + i);
	ans = total = l = 0;
	r = -1;
	fi(i,0,n-1)
	{
		Max(sell[i]);
		total = (!i ? c : (a[i] - a[i-1]));
		Min(buy[i]);
		q[++r].cnt = total, q[r].val = buy[i];
		ans += (ll) total * buy[i];
		Del(a[i+1] - a[i]);
	}
	Max(sell[n]);

	while(l<=r) ans -= (ll)q[l].cnt * q[l++].val;
	printf("%I64d\n", ans);
}

int main()
{
	int t; 
	for(scanf("%d", &t); t --;) solve();
	return 0;
}
