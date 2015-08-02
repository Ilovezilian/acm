/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/31 14:35:30
File Name     :1009_1.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 1010, mod = 1e9+7;

char s[N][N], str[2*N];
int n, m, mm;
bool vis[N][N];

struct nod{
	int x, y;
};

queue<nod> q, q1;

void dfs(int x, int y)
{
	int k = n - x + m - y - 2;
	if(mm >= k)
	{
		if(mm > k)
		{
			mm = k;
			while(!q.empty()) q.pop();
		}
		if(s[x][y] == '1') q.push((nod){x,y});
	}
	if(mm == 0) return;
	if(s[x][y] == '1') return;

	if(x-1 >= 0 && !vis[x-1][y]) vis[x-1][y] = 1, dfs(x-1, y);
	if(y-1 >= 0 && !vis[x][y-1]) vis[x][y-1] = 1, dfs(x, y-1);
	if(x+1 < n && !vis[x+1][y]) vis[x+1][y] = 1, dfs(x+1, y);
	if(x+1 < m && !vis[x][y+1]) vis[x][y+1] = 1, dfs(x, y+1);
}

void bfs()
{
	int k, max_s = 0;
	while(!q1.empty()) q1.pop();
	q1.push((nod){0,0});
	vis[0][0] = 1;
	while(!q1.empty())
	{
		int x = (int)q1.front().x , y = (int)q1.front().y;
		q1.pop();
		k = n - x + m - y - 2;
		//printf("(%d,%d)\n", x, y);
		if(k <= mm)
		{
			if(k < mm)
			{
				while(!q.empty()) q.pop();
				mm = k;
			}
			if(s[x][y] == '1') q.push((nod){x, y});
		}

		if(s[x][y] == '0')
		{
			if(x-1 >= 0 && !vis[x-1][y]) q1.push((nod){x-1,y}), vis[x-1][y] = 1;
			if(y-1 >= 0 && !vis[x][y-1]) q1.push((nod){x,y-1}), vis[x][y-1] = 1;
			if(x+1 < n && !vis[x+1][y]) q1.push((nod){x+1,y}), vis[x+1][y] = 1;
			if(y+1 < m && !vis[x][y+1]) q1.push((nod){x,y+1}), vis[x][y+1] = 1;
		}
		//if(cnt > n * m) {printf("over 20000000 the stack!\n"); break;}
	}
	//printf("cnt = %d\n", cnt);
	return;
}

void dfs1(int x, int y)
{
	int k = x + y;
	if(str[k] == '0' && s[x][y] == '1') return;

	if(str[k] == '1' && s[x][y] == '0') 
	{
		for(int i = k + 1; i < n + m; i ++) str[i] = '1';
		str[k] = '0';
		memset(vis, 0, sizeof(vis));
	}
	vis[x][y] = 1;
	if(x + 1 < n && !vis[x+1][y]) dfs1(x + 1, y);
	if(y + 1 < m && !vis[x][y+1]) dfs1(x, y + 1);
}

void bfs1()
{
	int x, y;
	int cnt = 0;
	while(!q.empty())
	{
		x = q.front().x, y = q.front().y;
		q.pop();
		if(s[x][y] == '1' && str[x+y] == '0') continue;
		if(s[x][y] == '0' && str[x+y] == '1') 
		{
			//fill(str + x + y + 1, str+ n + m , '1');
			for(int i = x + y + 1; i < n + m; i ++) str[i] = '1';
			str[x+y] = '0';
			memset(vis, 0, sizeof(vis));
		}
		if(x + 1 < n && !vis[x+1][y]) vis[x+1][y] = 1, q.push((nod){x + 1, y});
		if(y + 1 < m && !vis[x][y+1]) vis[x][y+1] = 1, q.push((nod){x, y + 1});
		cnt ++;
		if(x + y < 10) printf("(%d,%d)%s\n",x,y,str);
	}
//	printf("cnt = %d\n", cnt);
	return;
}

void solve()
{
	memset(vis, 0, sizeof(vis));
	scanf("%d%d", &n, &m);
	fi(i,n) scanf("%s", s[i]);

	mm = n + m;
	//dfs(0, 0);

	bfs();
	int st = (int)q.front().x + q.front().y;
	if(q.empty())
	{
		printf("0\n");
		return;
	}

	fill(str, str + n + m, '1');
	str[n+m] = '\0';
	memset(vis, 0, sizeof(vis));
	bfs1();
/**
	while(!q.empty())
	{
		int x = q.front().x, y = q.front().y; 
		//printf("(%d,%d)\n", x, y);
		vis[x][y] = 1;
		dfs1(x, y);
		q.pop();
	}
*/
	for(int i = st; i < n + m - 1; i ++) printf("%c", str[i]);
	printf("\n");

	/**
	printf("kkkkk\n"); */
	return;
}

int main()
{
	freopen("1009.in","r",stdin);
	freopen("my_1.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	while(cas -- ) solve();	
	
	return 0;
}
