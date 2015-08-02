/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/30 19:56:09
File Name     :1009.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x7fffffff
using namespace std;
const int N = 1010, mod = 1e9+7;
int n, m, ans, mm;
char s[N][N], str[2*N];
bool vis[N][N];
typedef struct { int x, y;} nod;
queue<nod> q;

void dfs1(int x, int y)
{
	vis[x][y] = 1;
	int k = n - x + m - y - 2;
	//printf("x = %d y = %d mm = %d\n", x, y, mm);
	if(k <= mm)
	{	
		if(k < mm)
		{
			while(!q.empty()) q.pop();
			mm = k;
		}
		if(s[x][y] == '1') q.push((nod){x,y});
	}
	if(!m) return;
	if(s[x][y] == '1') return;

	if(x + 1 < n && !vis[x+1][y]) dfs1(x + 1, y);
	if(y + 1 < m && !vis[x][y+1]) dfs1(x, y + 1);
	if(x - 1 >= 0 && !vis[x-1][y]) dfs1(x - 1, y);
	if(y - 1 >= 0 && !vis[x][y-1]) dfs1(x, y - 1);
}

void dfs2(int x, int y)
{
	if(vis[x][y]) return;
	vis[x][y] = 1;
	int k = x + y;
	if(str[k] == '0' && s[x][y] == '1') return ;
	if(str[k] == '1' && s[x][y] == '0') 
	{
		memset(vis, 0, sizeof(vis));
		fill(str + k + 1, str + n + m, '1');
		str[k] = '0';
	}
	if(x + 1 < n) dfs2(x + 1, y);
	if(y + 1 < m) dfs2(x, y + 1);
}

void bfs()
{
	int x, y;
	memset(vis, 0, sizeof(vis));
	while(!q.empty())
	{
		x = q.front().x, y = q.front().y;
		q.pop();
		if(str[x+y] == '0' && s[x][y] == '1') continue;
		if(str[x+y] == '1' && s[x][y] == '0') 
		{
			fill(str + x + y + 1, str + n + m, '1');
			str[x+y] = '0';
		}
		vis[x][y] = 1;
		if(x + 1 < n && !vis[x+1][y]) q.push((nod){x+1,y});
		if(y + 1 < m && !vis[x][y+1]) q.push((nod){x,y+1});
	}
}

void solve1()
{

}

void solve()
{
	memset(vis, 0, sizeof(vis));
	scanf("%d%d", &n, &m);
	mm = n + m;
	fi(i,n) scanf("%s", s[i]);
	fill(str, str+n+m, '1');
	while(!q.empty()) q.pop();

	dfs1(0, 0);
	if(q.empty()) {printf("0\n"); return;}
	int st = (int)q.front().x + q.front().y;
	//printf("%d %d\n", n, m);
	//printf("st = %d ed = %d\n", (int)q.front().x,(int) q.front().y);
	bfs();
	/**
	  memset(vis, 0, sizeof(vis));
	  while(!q.empty())
	  {
	  int x = q.front().x, y = q.front().y;
	  dfs2(x, y);
	  q.pop();
	  }
	  */
	for(int i = st; i < n + m - 1; i ++) printf("%c",str[i]);
	printf("\n");
}

int main()
{
	freopen("1009.in","r",stdin);
	freopen("my.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();	
	return 0;
}
