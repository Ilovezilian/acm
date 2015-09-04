/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/3 21:36:26
File Name     :t.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 5, mod = 1e9+7;

	int a[5][5];

void solve()
{
	for(int i = 0; i < N; i ++) for(int j = 0; j < N; j ++)
		printf("%d%c", a[i][j], j != 4 ? ' ' : '\n');
	printf("\n");

	memset(a, 0, sizeof(a));
	for(int i = 0; i < N; i ++) for(int j = 0; j < N; j ++)
		printf("%d%c", a[i][j], j != 4 ? ' ' : '\n');
	printf("\n");

	memset(a, -1, sizeof(a));
	for(int i = 0; i < N; i ++) for(int j = 0; j < N; j ++)
		printf("%d%c", a[i][j], j != 4 ? ' ' : '\n');
	printf("\n");

	fill(a[0], a[5], 1);
	for(int i = 0; i < N; i ++) for(int j = 0; j < N; j ++)
		printf("%d%c", a[i][j], j != 4 ? ' ' : '\n');
	printf("\n");

	memset(a, 0, sizeof(a[0][0]) * 2);
	for(int i = 0; i < N; i ++) for(int j = 0; j < N; j ++)
		printf("%d%c", a[i][j], j != 4 ? ' ' : '\n');
	printf("\n");
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    
	solve();
    return 0;
}
