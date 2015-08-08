/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/6 14:03:55
File Name     :1008.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100050, mod = 1e9+7;
int mark[N], ans[N];

struct nod{
	int x, y, o;
	/*
	bool oprerator < (const nod &a) const{
		if(y == a.y) return x < a.x;
		return y > a.y;
	}
	*/
} p[N];

bool cmp(nod a, nod b)
{
	if(a.y == b.y) return a.x > b.x;
	return a.y < b.y;
}

void solve()
{
	int n;
	scanf("%d", &n);
	fi(i,0,n-1)	p[i].o = i + 1;
	fi(i,0,n-1) scanf("%d", &p[i].x);
	fi(i,0,n-1) scanf("%d", &p[i].y);

	sort(p, p + n, cmp);
	int cnt = 0;
	memset(mark, 0, sizeof(mark));
	for(; cnt < n; cnt ++)
	{
		bool ok = 0;
		for(int i = 0; i < n; i ++) if(!mark[i] && p[i].x <= cnt && p[i].y >= cnt) 
		{
			ans[cnt] = i;
			mark[i] = 1;
			ok = 1;
			break;
		}
		if(!ok) { break;}
	}

	int sum = cnt;
	if(cnt != n) fi(i,0,n-1) if(!mark[i]) ans[cnt++] = i;
	printf("%d\n", sum);
	fi(i,0,n-1) printf("%d%c", p[ans[i]].o, i != n - 1 ? ' ' : '\n');
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
