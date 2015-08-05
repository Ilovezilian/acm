/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/2 15:34:50
File Name     :c.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 1010, mod = 1e9+7;

struct nod{
	int t, c, fa, mark;
	double w;
	nod(int k){t = 1, w = k, c = k, fa = 0, mark = 0;}
	nod(){t = 0, w = 0, c = 0, fa = 0, mark = 0;}
} e[N];
int n, r;

int find()
{
	int mx = 0;
	fin(i,1,n+1) if(i != r && !e[i].mark && e[i].w > e[mx].w) mx = i;
	return mx;
}

void solve()
{
	int v1, v2, x;
	while(~scanf("%d%d", &n, &r), n + r)
	{
		fin(i,1,n+1)
		{
			scanf("%d", &x);
			e[i] = nod(x);
		}
		e[r].fa = r;
		fi(i,n-1)
		{
			scanf("%d%d", &v1, &v2);
			e[v2].fa = v1;
		}
		
		int ans = 0;
		fin(i,1,n+1) ans += e[i].c;
		e[r].mark = 1;

		fi(i,n-1)
		{
			int mx = find(), fa;
			//printf("%d = %d\n", i, mx);
			fa = e[mx].fa;
			ans += e[mx].c * e[fa].t;

			e[fa].c += e[mx].c;
			fin(i,1,n+1) if(e[i].fa == mx) e[i].fa = fa;
			e[mx].mark = 1;
			e[fa].t += e[mx].t;
			e[fa].w  = (double)e[fa].c / e[fa].t;
		}
		printf("%d\n", ans);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();	   
	return 0;
}
