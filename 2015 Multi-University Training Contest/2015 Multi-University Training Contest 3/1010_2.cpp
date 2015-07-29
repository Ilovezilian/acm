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

pair<int, int> pr[N];
vector<int> e[N];
bool vis[N];
int n, ans, cnt[N];

void bfs()
{
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	ans = 0;
	queue<int > q;
	for(int i = n - 1; i + 1; i --) if(!vis[pr[i].second])
	{
		while(!q.empty()) q.pop();
		int u = pr[i].second;
	   	int	la = u, step = 0;
		cnt[u] = 1;
		q.push(u);
		vis[u] = 1;
		//printf("%d\n", q.empty());
		//printf("u = %d\n", u);
		while(!q.empty())
		{
			la = u;
			for(int j = 0; j < e[u].size(); j ++)
			{
				int v = e[u][j];
				q.push(v);
				vis[v] = 1;
				if(cnt[v])
				{
					cnt[v] += cnt[u];
				}
				cnt[v] = cnt[u] + 1;
			}
		//	printf("u1 = %d\n", u);
			q.pop();
			u = q.front();
		}
		ans = max(ans, cnt[la]);
	}
	return ;
}

int main()
{
    //freopen("1010.in","r",stdin);
    //freopen("my.out","w",stdout);
	//printf("Time = %.2f\n", (double) clock() / CLOCKS_PER_SEC);
	time_t st, ed, t;
 	while(~scanf("%d", &n))
	{
		fi(i, n + 1) e[i].clear();
		int w;
		fi(i,n) 
		{
			scanf("%d", &w);
			pr[i] = make_pair(w, i+1);
		}

		int x, y;
		fi(i,n-1) 
		{
			scanf("%d%d", &x, &y);
			if(pr[x-1].first > pr[y-1].first) e[x].push_back(y);
			else e[y].push_back(x);
		}
/*
		fin(i,1,n+1)
		{
			printf("e[%d] = ", i);
			fi(j,e[i].size()) printf(" %d ", e[i][j]); 
			puts("");
		}
*/
		
		sort(pr, pr + n);
		//fi(i,n) printf("pair[%d].first = %d pair[%d].second = %d\n", i, pr[i].first, i, pr[i].second);
		
		bfs();

		printf("%d\n", ans);
	}
	
	//printf("Time used = %.2f\n", (double) clock() / CLOCKS_PER_SEC);
    return 0;
}

