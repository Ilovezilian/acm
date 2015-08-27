/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/18 12:47:53
File Name     :1007.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 101, mod = 1e9+7;

int n, m, maz[N][N];

void solve()
{
	while(~scanf("%d%d", &n, &m))
	{
		int sum = 0, mx, my, mv = 0;
		for(int i =  0; i < n; i ++) for(int j = 0; j < m; j ++)
		{
			scanf("%d", maz[i] + j);
			sum += maz[i][j];
			if((!i && !j || i != n - 1 && j m - 1) && maz[i][j] < mv) mx = i, my = j;
		}
		
		if(m&1)
		{
			printf("%d\n", sum);
			for(int i = 0; i < m; i ++) for(int j = 0; j < n; j ++)
			{
				if(i == n - 1 && j == m - 1) {printf("\n"); break;}
				if(j == n -1) printf("R");
				else printf("%c", i&1 ? 'U' : 'D');
			}
		}
		else if(n&1)
		{
			printf("%d\n", sum);
			for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++)
			{
				if(i == n - 1 && j == m - 1) {printf("\n"); break;}
				if(j == m -1) printf("D");
				else printf("%c", i&1 ? 'L' : 'R');
			}
		}
		else
		{
			printf("%d\n", sum - mi);

			for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++)
			{
				if(i == mx / 2 * 2)
				{
					i += 2;
					for(int i = 0; i < m - 2; i ++)
					{
						printf("%cR", i&1?'U':'D');
					}
				}

				if(j == m - 1 ) printf("D");
				else printf("%c", i&1?'L':'R');
			}
		}
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	solve();   
    return 0;
}
