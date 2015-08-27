/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/25 17:39:34
File Name     :h.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
const double mv = 11.0 / 120.0;
int ini[] = {0, 330, 300, 270, 240, 210, 180, 150, 120, 90, 60, 30, 0}, kk;

void solve()
{
	double wd;
	int d, hh, h, m, s;
	char c[10];
	scanf("%d%s%d", &d, c, &hh);
	wd = ini[hh];
	int cnt;

	if(c[0] == 'a')
	{
		if(wd >= d) wd -= 360;
		cnt = (int)((d + mv / 2  - wd) / mv);
		s = cnt % 60;
		cnt /= 60;
		m = cnt % 60;
		cnt /= 60;
		h = hh + cnt;
		if(h > 12) h -= 12;
		//printf("after\n");
	}
	else
	{
		double dd = wd;
	   	wd = d;
		if(wd >= dd) wd -= 360; 
		cnt = (int) ((dd + mv / 2 - wd) / mv);
		if(cnt % 60) s = 60 - cnt % 60, cnt += 60;
		cnt /= 60;
		if(cnt % 60) m = 60 - cnt % 60, cnt += 60;
		cnt /= 60;
		h = hh - cnt;
		if(h <= 0) h += 12;
		//printf("til\n");
	}

	printf("Case %d: %d:%02d:%02d\n", kk ++, h, m, s);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	int cas;
	kk = 1;
 	scanf("%d", &cas);
	while(cas --) solve();	
    return 0;
}
