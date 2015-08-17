/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/8 12:49:38
File Name     :b.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 16, mod = 1e9+7;

int maze[N][N];
int n, state[1001], cnt_s, dp[N][1<<16];

void prt(int k)
{
   if(!k) {printf("0\n"); return ;}
	while(k)
	{
		printf("%d", k & 1);
		k >>= 1;
	}
	printf("\n");
}

void init()
{
	//printf("n = %d\n", n);
	cnt_s = 0;
	fi(i,0,(1<<(n+1)) - 1)
	{
		if(i & (i << 1) || i & (i >> 1)) continue;
		state[cnt_s++] = i;//, prt(i);
	}
	/*
	   fi(i,0, cnt_s - 1)
	   {
	   int k = state[i];
	   while(k)
	   {
	   printf("%d", k & 1);
	   k >>= 1;
	   }
	   printf("\n");
	   }
	   */
}

int f(int x, int y)
{
	int sum = 0;
	fi(i,0,n+1) if(state[y] & (1<<i)) sum += maze[x][i];
	return sum;
}

void solve()
{
	//scanf("%d", &n);
	//cout<<sizeof(dp)/1024./1024;
	char c;
	while(~scanf("%d%c", &maze[0][0], &c))
	{
		memset(dp, 0, sizeof(dp));

		for(n = 1;; n ++)
		{
			scanf("%d%c", &maze[0][n], &c);
			if(c == '\n') break;
		}

		init();

		fi(i,1,n) fi(j,0,n) scanf("%d", &maze[i][j]);
		//	fi(i,0,n) fi(j,0,n) printf("%d%c", maze[i][j], (j != n ? ' ' : '\n'));

		int sum; 
		fi(i,0,cnt_s-1)
		{
			sum = 0;
			fi(j,0,n+1) if(state[i] & (1<<j)) sum += maze[n][j];		
			dp[n][i] = sum;
			//prt(state[i]);
		}

		fd(i,n-1, 0)
		{
			fi(j,0,cnt_s-1) 
			{
				int tmp = 0;
				fi(k, 0, cnt_s-1) if(!(state[k] & (state[j]<<1)) && !(state[k] & (state[j]>>1)) && !(state[k] & state[j])) 
				{
					tmp = max(tmp, dp[i+1][k] + f(i,j));
					/**
					prt(state[j]); prt(state[k]);
					printf("\n");
					*/
				}
				dp[i][j] = tmp;
				//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
			}
		}
		int ans = dp[0][0];
		fi(i,1,cnt_s-1) ans = max(ans, dp[0][i]);
		printf("%d\n", ans);
	}
}

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	solve();
	return 0;
}
