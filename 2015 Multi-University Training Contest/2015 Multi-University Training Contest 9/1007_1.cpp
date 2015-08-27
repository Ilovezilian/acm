/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/18 17:16:13
File Name     :1007_1.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;


void solve()
{
	int n, m;
	while(~scanf("%d%d", &n, &m))
	{
		int mx, my, mv = INF, sum = 0, x;
		for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++)
		{
			scanf("%d", &x);
			sum += x;
			if((i + j) & 1 && x < mv) mv = x, mx = i, my = j;
		}

		//printf("mx = %d my = %d mv = %d\n", mx, my, mv);

		if(n&1)
		{
			printf("%d\n", sum);

			for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++) if(i != n - 1 || j != m - 1)
				printf("%c", j != m - 1 ? ( i&1 ? 'L' : 'R') : 'D');
		}
		else if(m&1)
		{
			printf("%d\n", sum);

			for(int i = 0; i < m; i ++) for(int j = 0; j < n; j ++) if(i != m - 1 || j != n - 1)
				printf("%c", j != n - 1 ? ( i&1 ? 'U' : 'D') : 'R');
		}
		else
		{
			printf("%d\n", sum - mv);

			bool di = 0; //这个变量很重要x3。
			for(int i = 0; i < m; i ++)
			{
				if(my / 2 * 2 == i)
				{
					for(int j = 0; j < n; j ++)
					{

						if(j == mx)
						{
							if(j != n - 1) printf("D");
							if(j == n - 1 && i + 1 != m - 1) printf("R");
							di = 1;
						}
						else if(j != n - 1)
							printf("%s", (j + di) & 1 ? "LD" : "RD");
						else if(j == n - 1 && i + 1 != m - 1)
							printf("RR");
						else 
							printf("R");
					}
					i ++;
				}
				else for(int j = 0; j < n ; j ++)if(i != m - 1 || j != n - 1)
					printf("%c", j != n - 1 ? (((i+di) & 1) ? 'U' : 'D') : 'R');
			}
		}
		printf("\n");
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
 	solve();   
    return 0;
}
