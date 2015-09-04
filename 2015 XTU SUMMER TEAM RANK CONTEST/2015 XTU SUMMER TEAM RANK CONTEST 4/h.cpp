/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/1 20:23:30
File Name     :h.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e6+10, mod = 1e9+7;
int d[N], cnt, x[9], y[9], n;
bool ok;


void fi(int cur, int de)
{
	if(ok) return;
	if(cur >= n) return ;
	//printf("curi = %d cnti = %d\n", cur, cnt);

	for(int i = 0; i < 8; i ++) x[i] = x[i+1], y[i] = y[i+1];
	if(de == 0)
	{
		x[8] += d[cur];
		if(x[8] >= x[5]) 
		{
			ok = 1;
			return;
		}
	}
	else if(de == 1)
	{
		y[8] -= d[cur];
		if(y[8] <= y[5])
		{
			ok = 1;
			return;
		}
	}
	else if(de == 2)
	{
		x[8] -= d[cur];
		if(x[8] <= x[5])
		{
			ok = 1;
			return;
		}
	}
	else if(de == 3)
	{
		y[8] += d[cur];
		if(y[8] >= y[5])
		{
			ok = 1;
			return;
		}
	}

		//printf("(%d,%d)\n", x[8], y[8]);
		//for(int i = 8; i > 1; i ++) printf("(%d,%d)%c",x[i], y[i], i != 2 ? ' ' : '\n');

	cnt ++;
	fi(cur + 1, (de + 1) % 4);
}

void fo(int cur, int de)
{
	if(ok) return;
	if(cur >= n) return ;
	//printf("curo = %d cnto = %d\n", cur, cnt);

	for(int i = 0; i < 8; i ++)
		x[i] = x[i+1], y[i] = y[i+1];

	//for(int i = 8; i > 1; i --) printf("(%d,%d)%c", x[i], y[i], i != 2 ? ' ' : '\n');

	if(de == 0)
	{
		x[8] += d[cur];

		//printf("(%d,%d)\n", x[8], y[8]);
		//for(int i = 8; i > 1; i ++) printf("(%d,%d)%c", x[i], y[i], i != 2 ? ' ' : '\n');

		if(cur == 4)
		{
			if(y[8] == 0 && x[8] >= 0)
			{
				ok = 1;
				return;
			}
			if(y[8] > 0)
			{
				//printf("debug\n");
				cnt++, fo(cur + 1, (de + 1) % 4);
			}
			else 
			{
				if(x[8] >= x[5])
				{
					ok = 1;
					return;
				}
				else cnt++, fi(cur + 1, (de + 1) % 4);
			}
		}
		else
		{
			if(y[8] > y[4]) cnt++, fo(cur + 1, (de + 1) % 4);
			else 
			{
				if(y[8] >= y[2])
				{
					if(x[8] >= x[3])
					{
						ok = 1;
						return;
					}
					else cnt++, fi(cur + 1, (de + 1) % 4);
				}
				else 
				{
					if(x[8] >= x[5])
					{
						ok = 1;
						return;
					}
					else cnt++, fi(cur + 1, (de + 1) % 4);
				}
			}
		}
	}
	else if(de == 1)
	{
		y[8] -= d[cur];

		//printf("(%d,%d)\n", x[8], y[8]);
		//for(int i = 8; i > 1; i ++) printf("(%d,%d)%c",x[i], y[i], i != 2 ? ' ' : '\n');

		if(x[8] > x[4]) cnt++, fo(cur + 1, (de + 1) % 4);
		else
		{
			if(x[8] >= x[2] && y[8] <= y[3])
			{
				ok = 1;
				return;
			}
			else
			{
				if(y[8] <= y[5])
				{
					ok = 1;
					return;
				}
				else cnt++, fi(cur + 1, (de + 1) % 4);
			}
		}
	}
	else if(de == 2)
	{
		x[8] -= d[cur];

		//printf("(%d,%d)\n", x[8], y[8]);
		//for(int i = 8; i > 1; i ++) printf("(%d,%d)%c",x[i], y[i], i != 2 ? ' ' : '\n');

		if(y[8] < y[4]) cnt++, fo(cur + 1, (de + 1) % 4);
		else 
		{
			if(y[8] <= y[2] && x[8] <= x[3])
			{
				ok = 1;
				return;
			}
			else
			{
				if(x[8] <= x[5])
				{
					ok = 1;
					return;
				}
				else cnt++, fi(cur + 1, (de + 1) % 4);
			}
		}
	}
	else if(de == 3)
	{
		y[8] += d[cur];

		//printf("(%d,%d)\n", x[8], y[8]);
		//for(int i = 8; i > 1; i ++) printf("(%d,%d)%c",x[i], y[i], i != 2 ? ' ' : '\n');

		if(x[8] < x[4]) cnt++, fo(cur + 1, (de + 1) % 4);
		else
		{
			if(x[8] <= x[2] && y[8] >= y[3])
			{
				ok = 1;
				return;
			}
			else
			{
				if(y[8] >= y[5])
				{
					ok = 1;
					return;
				}
				else cnt++, fi(cur + 1, (de + 1) % 4);
			}
		}
	}
}

void solve()
{
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < 9; i ++) x[i] = y[i] = 0;

		for(int i = 0; i < n; i ++)
			scanf("%d", d + i);
		if(n < 4)
		{
			printf("OK\n");
			continue;
		}
		else
		{
			x[6] = x[7] = d[0], y[7] = y[8] = -d[1];
			x[8] = d[0] - d[2];
			//printf("(%d,%d)\n(%d,%d)\n(%d,%d)\n", x[6], y[6], x[7], y[7], x[8], y[8]);
		}
		ok = 0;
		cnt = 3;
		if(x[8] < 0)
			fo(3, 3);
		else
			fi(3, 3);
		if(cnt == n)
			printf("OK\n");
		else printf("%d\n", cnt);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
