/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/1 11:08:48
File Name     :1009_2.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 1010, mod = 1e9+7;
int n, m, mm;
char s[N][N];
bool vis[N][N];
struct nod{
	int x, y;
};
queue<nod> q;

void bfs()
{
	mm = 0;
	memset(vis, 0, sizeof(vis));
	while(!q.empty()) q.pop();
	int x, y;
	vis[0][0] = 1, q.push((nod){0,0});
	while(!q.empty())
	{
		x = q.front().x, y = q.front().y;
		q.pop();

		//printf("(%d,%d)\n", x, y);
		if(s[x][y] == '1') 
		{
			mm = max(mm,x + y);
			continue;
		}

		if(x-1 >= 0 && !vis[x-1][y]) vis[x-1][y] = 1, q.push((nod){x-1,y});
		if(y-1 >= 0 && !vis[x][y-1]) vis[x][y-1] = 1, q.push((nod){x,y-1});
		if(x+1 < n  && !vis[x+1][y]) vis[x+1][y] = 1, q.push((nod){x+1,y});
		if(y+1 < m  && !vis[x][y+1]) vis[x][y+1] = 1, q.push((nod){x,y+1});
	}
	return;
}

void bfs1()
{
	//printf("[%d,%d]\n", mm, n+m-2);
	for(int i = mm; i < n + m - 1; i ++)
	{
		//printf("i = %d\n", i);
		bool ok = 1;
		int j = (i >= n ? (n - 1) : i), k = i - j;
		//printf(" j = %d, k = %d\n", j, k);
	//	for(j = (i >= n ? (n - 1) : i), k = i - j; j >= 0 && k < m; j-- , k ++) printf("s[%d][%d] = %c vis[%d][%d] = %d\n", j, k, s[j][k], j, k, vis[j][k]);
		for( j = (i >= n ? (n - 1) : i), k = i - j; j >= 0 && k < m; j-- , k ++) if(s[j][k] == '0' && vis[j][k]) 
		{
			if(j+1 < n) vis[j+1][k] = 1;
			if(k+1 < m) vis[j][k+1] = 1;
			ok = 0;
		//	printf("j = %d k = %d\n", j, k);
		}

		if(ok)
		{
			for(j = (i >= n ? n - 1 : i), k = i - j; j >= 0 && k < m; j --, k ++) if(s[j][k] == '1' && vis[j][k]) 
			{
				if(j+1 < n) vis[j+1][k] = 1;
				if(k+1 < m) vis[j][k+1] = 1;
				//printf("j = %d k = %d\n", j, k);
			}
		}
		/*
		*/
		printf("%c", ok?'1' : '0');
	}
	printf("\n");
}

void solve()
{
	scanf("%d%d", &n, &m);
	fi(i,n) scanf("%s", s[i]);
	bfs();
	if(vis[n-1][m-1] && s[n-1][m-1] == '0') printf("0\n");
	else bfs1();
}

int main()
{
	//freopen("1009.in","r",stdin);
	//freopen("my_2.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
	return 0;
}
