/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/24 17:18:26
File Name     :h.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 50010, mod = 1e9+7;
int pre[N], cnt[N], n, m, qq;
queue<int> q;

void solve()
{
	memset(cnt, 0, sizeof(cnt));
	memset(pre, 0, sizeof(pre));

	scanf("%d%d%d", &n, &m, &qq);
	int a, b;
	for(int i = 0; i < m; i ++)
	{
		scanf("%d%d", &a, &b);
		if(a > b) cnt[b] ++, cnt[a] --;
	}

	while(!q.empty()) q.pop();

	bool ok = 1;
	for(int i = 1; i < N; i ++)
	{
		cnt[i] += cnt[i-1];
		if(cnt[i] == cnt[i-1]) pre[i] = pre[i-1];
		else if(cnt[i-1] < cnt[i])
		{
			if(!q.empty())	pre[i] = q.front();
			for(int j = 0; j < cnt[i] - cnt[i-1]; j ++)
			   q.push(i);
			if(ok) {q.pop(); ok = 0;}
		}
		else if(cnt[i-1] > cnt[i])
		{
			if(!q.empty())	pre[i] = q.front();
			for(int j = 0; j < cnt[i-1] - cnt[i]; j ++)
				q.pop(); ///这里的更新会出错
		}
	}

	int qa;
	for(int i = 0; i < qq; i ++)
	{
		scanf("%d", &qa);
		printf("%d\n", cnt[qa-1] > 1 ? qa - pre[qa-1] : 0);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
