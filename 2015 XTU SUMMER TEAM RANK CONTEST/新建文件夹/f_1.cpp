/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/6 11:40:42
File Name     :f_1.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
int n, m, p, vis[15][15][4][50];
char maz[15][15];

queue<int[][][][]> q;

void bfs(int st, int ed)
{
	
}

void solve()
{
	memset(vis, 0, sizeof(vis));

	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; i ++)
		scanf("%s", maz[i] + 1);

	for(int i = 0; i <= n + 1; i ++)
		maz[i][0] = maz[i][m+1] = '*', maz[i][m+2] = '\0';
	for(int i = 0; i <= m + 1; i ++)
		maz[0][i] = maz[n+1][i] = '*';
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j ++)
			if(maz[i][j] == '@') bfs(i, j);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	while(!q.empty()) q.pop();
	while(~scanf("%d", &n))
	{
		q.push(vis
	}

	/*
    int cas;
	scanf("%d", &cas);
	while(cas --) solve();
	*/
    return 0;
}
