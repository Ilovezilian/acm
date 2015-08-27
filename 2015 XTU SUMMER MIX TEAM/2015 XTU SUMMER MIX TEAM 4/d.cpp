/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/24 10:30:49
File Name     :d.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
int a[10][10];
bool vis[10];
char s[11][11];

void StoI()
{
	for(int i = 0; i < 9; i ++) for(int j = 0; j < 9; j ++)
		a[i][j] = s[i][j] - '0';
}

void solve()
{
	for(int i = 0; i < 9; i ++)
		scanf("%s", s[i]);

	bool ok = 1;
	StoI();
	for(int i = 0; i < 9; i ++)
	{
		if(!ok) break;
		memset(vis, 0, sizeof(vis));
		for(int j = 0; j < 9; j ++) vis[a[i][j]] = 1;
		for(int j = 1; j <= 9; j ++) if(!vis[j])
		{
			ok = 0;
			break;
		}

		memset(vis, 0, sizeof(vis));
		for(int j = 0; j < 9; j ++) vis[a[j][i]] = 1;
		for(int j = 1; j <= 9; j ++) if(!vis[j])
		{
			ok = 0;
			break;
		}
	}

	if(ok)
	{
		for(int i = 0; i < 7; i += 3)
		{
			if(!ok) break;

			for(int j = 0; j < 7; j += 3)
			{
				if(!ok) break;

				memset(vis, 0, sizeof(vis));
				for(int k = i; k < i + 3; k ++) for(int l = j; l < j + 3; l ++) 
				{
					//printf("(%d,%d,%d)", k + 1, l + 1, a[k][l]);
					vis[a[k][l]] = 1;
				}
				//printf("\n");
				for(int k = 1; k <= 9; k ++) if(!vis[k])
				{
					ok = 0; 
					break;
				}
			}
		}
	}

	printf("%s\n", ok ? "Valid" : "Invalid");
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    
	int cas;
	scanf("%d", &cas);
	while(cas --) solve();
    return 0;
}
