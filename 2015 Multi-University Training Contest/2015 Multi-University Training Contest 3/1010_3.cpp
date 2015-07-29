/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/29 9:59:15
File Name     :1010.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 500050, mod = 1e9+7;

int W[N];
vector<int> e[N];
int n, ans, cnt[N],vis[N];

void bfs()
{
	queue<int > q;
	fin(i,1,n+1) if(!vis[i]) q.push(i);
	ans = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		ans = max(ans, cnt[u]);
		for(int j = 0; j < e[u].size(); j ++)
		{
			int v = e[u][j];
			cnt[v] += cnt[u];
			vis[v] --;
			if(vis[v] == 0) q.push(v);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	//freopen("1010.in","r",stdin);
	//freopen("my.out","w",stdout);
	
	while(cin>>n)
	{
		fill(cnt + 0, cnt + n + 1, 1);
		memset(vis, 0, sizeof(vis));
		fi(i, n + 1) e[i].clear();
		fi(i,n) cin>>W[i+1];

		int x, y;
		fi(i,n-1) 
		{
			cin>>x>>y;
			if(W[x] > W[y]) e[x].push_back(y), vis[y] ++;
			else e[y].push_back(x), vis[x] ++;
		}

		bfs();

		//fin(i,1, n + 1) printf("cnt[%d] = %d\n", i, cnt[i]);

		cout<<ans<<'\n';
		cout<<flush;
	}

//	printf("Time used = %.2f\n", (double) clock() / CLOCKS_PER_SEC);
	return 0;
}

