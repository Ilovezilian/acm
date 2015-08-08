/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/7 19:52:48
File Name     :1008_1.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff	
#define ll long long
using namespace std;
const int N = 100100, mod = 1e9+7;

int n, ans;
struct nod {
	int l, r, o;
}p[N];

bool cmp(nod a, nod b) {return a.l < b.l;}
struct cmp1 { bool operator () (nod a, nod b){return a.r > b.r;}};

priority_queue<nod, vector<nod>, cmp1> q;

void judge()
{
	int i = 0, m = 0;
	ans = 0;
	for(; i < n; i ++)
	{
		while(m < n && p[m].l <= i) q.push(p[m]), m ++;
		while(!q.empty() && q.top().r < i) q.pop();
		if(q.empty())
		{
			while(!q.empty()) q.pop();
		   	return;
		}
 		if(!q.empty()) ans ++, q.pop();
	}
	while(!q.empty()) q.pop();
	return;
}

void solve()
{
	scanf("%d", &n);
	fi(i,0,n-1) p[i].o = i + 1;
	fi(i,0,n-1) scanf("%d", &p[i].l);
	fi(i,0,n-1) scanf("%d", &p[i].r);
	sort(p, p + n, cmp);
	judge();
	printf("%d\n", ans);
	
	if(ans == 0)
	{
		fi(i,0, n - 1) printf("%d%c", p[i].o, i != n - 1 ? ' ' : '\n');
		return;
	}

	int i = 0, m = 0, cnt = 1;
	for(; i < n; i ++)
	{
		while(m < n && p[m].l <= i) q.push(p[m]), m ++;
		while(!q.empty() && q.top().r < i) printf("%d%c" ,q.top().o, cnt ++ != n ? ' ' : '\n'), q.pop();
 		if(!q.empty())
		{
			printf("%d%c" ,q.top().o, cnt ++ != n ? ' ' : '\n');
			q.pop();
		}
	}
	while(!q.empty())
	{
		 printf("%d%c" ,q.top().o, cnt ++ != n ? ' ' : '\n');
		 q.pop();
	}
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int  cas;
	scanf("%d", &cas);
	while(cas --) solve();	
	return 0;
}
