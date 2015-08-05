/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/3 21:02:56
File Name     :d.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 10010, mod = 1e9+7;
struct point{
	double x, y, z, r;
} p[N];
int n;

double cal(double r)
{
	double m = 0;
	fi(i,n) m = max(m, p[i].z / (r - p[i].r));
	return m * r;
}

void solve()
{
	scanf("%d", &n);
    double mh, mr;
	mh = mr = 0;
	fi(i,n)
	{
		scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
		p[i].r = sqrt(p[i].y * p[i].y + p[i].x * p[i].x);
		mr = max(mr, p[i].r);
		mh = max(mh, p[i].z);
	}
	
	double r = 2 * 1e+3, l = mr, midl, midr, la, ra;
	while(r - l > 1e-4)
	{
		midl = (r + 2 * l) / 3, midr = (l + 2 * r) / 3;
		la = cal(midl) * midl * midl, ra = cal(midr) * midr * midr;
		if(la < ra) r = midr;
		else l = midl;
	}
	double ans = (r + l) / 2;
	printf("%.3f %.3f\n", cal(ans), ans);
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
