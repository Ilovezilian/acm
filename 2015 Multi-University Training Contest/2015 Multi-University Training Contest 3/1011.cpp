/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/29 9:08:33
File Name     :1011.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 111, mod = 1e9+7;
int cnt[N];
vector<int> p[N];

int dfs(int x)
{
	fi(i, p[x].size()) cnt[x] += dfs(p[x][i]); 
	return cnt[x] + 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 	int n, k, x, y;
 	while(~scanf("%d%d", &n, &k))
	{
		memset(cnt, 0, sizeof(cnt));
		fi(i,n+1) p[i].clear();

		fi(i,n-1)
		{
			scanf("%d%d", &x, &y);
			p[x].push_back(y);
		}

		dfs(1);

		int sum = 0;
		fin(i,1,n+1) if(cnt[i] == k) sum ++;
		printf("%d\n", sum);
	}
    return 0;
}

/**
 
7 2
1 2
1 3
2 4
2 5
3 6
3 7  

7 1
1 2
1 3
2 4
2 5
3 6
3 7 

  */

