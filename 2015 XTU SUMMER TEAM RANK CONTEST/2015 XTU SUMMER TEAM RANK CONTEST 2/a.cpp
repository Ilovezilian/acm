/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/27 8:57:25
File Name     :a.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 11, mod = 1e9+7;
typedef long long  LL;
LL n1, n2, r1, r2, a1[N], a2[N];

void dec(LL fz, LL fm)
{
	if(fm < 0) fm = - fm, fz = - fz;
	//printf("fz = %I64d  fm = %I64d\n", fz , fm);

	if(fz % fm == 0)
	{
		printf("%I64d\n", fz / fm);
		return;
	}

	if(fz < fm)
	{
		if(fz < 0)
		{
			printf("%I64d ", (fz - fm) / fm);
			fz = fz - (fz - fm) / fm * fm;
			//printf("%I64d/%I64d\n", fz, fm);
		}
		else
		{
			printf("0 ");
		}
	}
	else
	{
		printf("%I64d ", fz/fm);
		fz %= fm;
	}

	while(1)
	{
		LL tmp = fm;
		fm = fz, fz = tmp;
		//printf("%I64d/%I64d\n", fz, fm);
		printf("%I64d%c", fz / fm, fz % fm ? ' ' : '\n');
		if(fz % fm == 0) break;
		fz %= fm;
	}
}

void cal()
{ 
	LL fz1, fz2, fm1, fm2;
	fm1 = a1[n1-1], fz1 = 1;
    LL tmp;
	for(int i = n1 - 2; i > 0; i --)
	{
		tmp = fm1;
		fz1 += a1[i] * fm1;
		fm1 = fz1;
		fz1 = tmp;
	}
	if(n1 != 1) fz1 += a1[0] * fm1;
	else fm1 = 1, fz1 = a1[0];

	fm2 = a2[n2-1], fz2 = 1;
	for(int i = n2 - 2; i > 0; i --)
	{
		tmp = fm2;
		fz2 += a2[i] * fm2;
		fm2 = fz2;
		fz2 = tmp;
	}
	if(n2 != 1) fz2 += a2[0] * fm2;
	else fm2 = 1, fz2 = a2[0];

/*
	printf("r1 = %I64d/%I64d r2 = %I64d/%I64d\n", fz1, fm1, fz2, fm2);
*/
	dec(fz1 * fm2 + fz2 * fm1, fm1 * fm2);
	dec(fz1 * fm2 - fz2 * fm1, fm1 * fm2);
	dec(fz1 * fz2, fm1 * fm2);
	dec(fz1 * fm2, fz2 * fm1);
}

void solve()
{
	int cas = 1;
	while(~scanf("%I64d%I64d", &n1, &n2) && n1 + n2)
	{
		for(int i = 0; i < n1; i ++)
			scanf("%I64d", a1 + i);
		for(int i = 0; i < n2; i ++)
			scanf("%I64d", a2 + i);
		
		printf("Case %d:\n", cas ++);
		cal();
	}
}

int main()
{
	//dec(-1,5);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
