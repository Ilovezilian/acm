#include<bits/stdc++.h>
using namespace std;

int n, m, p, ed_x, ed_y, ans[15][15];
char maz[15][15];
struct nod
{
	int x, y, de, clo;
	nod(int _x, int _y, int _de, int  _clo)
	{
		x = _x, y = _y, de = _de, clo = _clo;
	}
	nod(){}
};
queue<nod> q;

void bfs(int st_x, int st_y)
{
	memset(ans, -1, sizeof(ans));
	int x, y, t;
	while(!q.empty()) q.pop();
	ans[st_x][st_y] = 0;

	q.push(nod(st_x, st_y, 0, 1));
	int cnt = 0;
	while(!q.empty())
	{
		int x = q.front().x, y = q.front().y, de = q.front().de, clo = q.front().clo;
		q.pop();

		//printf("%d (%d, %d) = %d\n", cnt ++, x, y, ans[x][y]);

		if(clo == p + 1) clo = 1, de = (de + 3) % 4;

		int tmp = min(de, 4 - de) + 1;
		if(tmp + clo <= p)
		{
			if(maz[x][y-1] != '*' && (ans[x][y-1] > ans[x][y] + min(de, 4 - de) + 1 || ans[x][y-1] == -1))
				ans[x][y-1] = ans[x][y] + min(de, 4 - de) + 1, q.push(nod(x, y - 1, 0, clo + 1));
		}
		else q.push(nod(x,y,0,clo+1));

		tmp = abs(de - 1) + 1;
		if(tmp + clo <= p)
		{
			if(maz[x][y+1] != '*' && (ans[x][y+1] > ans[x][y] + abs(de - 1) + 1 || ans[x][y+1] == -1))
				ans[x][y+1] = ans[x][y] + abs(de - 1) + 1, q.push(nod(x, y + 1, 1, clo + 1));
		}
		else q.push(nod(x,y,1,clo+1));

		tmp = abs(de - 2) + 1;
		if(tmp + clo <= p)
		{
			if(maz[x-1][y] != '*' && (ans[x-1][y] > ans[x][y] + abs(de - 2) + 1 || ans[x-1][y] == -1))
				ans[x-1][y] = ans[x][y] + abs(de - 2) + 1, q.push(nod(x - 1, y, 2, clo + 1));
		}
		else q.push(nod(x,y,2,clo+1));

		tmp = min(3 - de, 1 + de) + 1;
		if(tmp + clo <= p)
		{
			if(maz[x+1][y] != '*' && (ans[x+1][y] > ans[x][y] + min(3 - de, 1 + de) + 1 || ans[x+1][y] == -1))
				ans[x+1][y] = ans[x][y] + min(3 - de, 1 + de) + 1, q.push(nod(x + 1, y, 3, clo + 1));
		}
		else q.push(nod(x,y,3,clo+1));
	}
}

void solve()
{
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; i ++)
		scanf("%s", maz[i]+1);

	for(int i = 0; i <= n + 1; i ++)
		maz[i][0] = maz[i][m+1] = '*', maz[i][m+2] = '\0';

	for(int i = 0; i <= m+1; i ++)
		maz[0][i] = maz[n+1][i] = '*';
	maz[n+1][m+2] = maz[0][m+2] = '\0';

	int st_x, st_y;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++)
	{
		if(maz[i][j] == '@') st_x = i, st_y = j;
		else if(maz[i][j] == '$') ed_x = i, ed_y = j;
	}

	for(int i = 0; i <= n + 1; i ++) printf("%s\n", maz[i]);
	printf("(%d,%d)(%d,%d)\n", st_x, st_y, ed_x, ed_y);
	/*
	*/

	bfs(st_x, st_y);
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) printf("%d%c", ans[i][j], j != m ? ' ' : '\n');

	if(ans[ed_x][ed_y] != -1)
		printf("%d\n", ans[ed_x][ed_y]);
	else
		printf("YouBadbad\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while( T --) solve();
	return 0;
}
