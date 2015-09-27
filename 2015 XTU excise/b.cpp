/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/7 15:54:37
File Name     :b.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e5+10, mod = 1e9+7;
int n, cas;
struct nod
{
	int h, w;
} retOfBob[N], retOfAlice[N];

bool cmp1(nod a, nod b)
{
	if(a.w <= b.w && a.h <= b.h) return 1;
	return 0;
	/*
	if(a.h == b.h) return a.w < b.w;
	return a.h < b.h;
	*/
}

bool cmp2(nod a, nod b)
{
	if(a.w <= b.w && a.h <= b.h) return 1;
	return 0;
	/*
	if(a.h == b.h) return a.w > b.w;
	return a.h < b.h;
	*/
}

void prt_sort()
{
	printf("Alice-------------------\n");
	for(int i = 0; i < n; i ++)
		printf("(%d,%d,%d)\n", i, retOfAlice[i].h, retOfAlice[i].w);

	printf("Bob-------------------\n");
	for(int i = 0; i < n; i++)
		printf("(%d,%d,%d)\n", i, retOfBob[i].h, retOfBob[i].w);
	printf("-------------------\n");
}

void solve()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d%d", &retOfAlice[i].h, &retOfAlice[i].w);
	for(int i = 0; i < n; i ++)
		scanf("%d%d", &retOfBob[i].h, &retOfBob[i].w);
	
	sort(retOfBob, retOfBob + n, cmp1);
	sort(retOfAlice, retOfAlice + n, cmp2);

	prt_sort();

	int ans = 0;
	for(int i = 0, j = n - 1; i < n; i ++, j --)
		if(retOfBob[i].h <= retOfAlice[j].h && retOfBob[i].w <= retOfAlice[j].w) ans ++;

	printf("%d\n", ans);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int T;
	scanf("%d", &T);
	while(T --) solve();
    return 0;
}
