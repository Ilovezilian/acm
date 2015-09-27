/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/7 15:54:37
File Name     :b.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e5+10, mod = 1e9+7;
int n, cas;
struct nod
{
	int h, w, mk;
	bool operator < (const nod& a) const
	{

		return h <= a.h || w <= a.w;
	}
} ret[N<<1];

queue<int> q;
void prt_sort()
{
	for(int i = 0; i < n; i ++)
		printf("(%d,%d,%d,%s)\n", i, ret[i].h, ret[i].w, ret[i].mk ? "Alice" : "Bob");
}

void solve()
{
	scanf("%d", &n);
	n <<= 1;
	for(int i = 0; i < n; i ++)
	{
		scanf("%d%d", &ret[i].h, &ret[i].w);
		ret[i].mk = (i < n / 2);
	}

	sort(ret, ret + n);
	prt_sort();

	while(!q.empty()) q.pop();

	int ans = 0;
	for(int i = n - 1; i + 1; i --)
	{
		if(ret[i].mk)
		{
			q.push(i);
		}
		else
		{
			int cur;
			while(!q.empty())
			{
				cur = q.front();
				if(ret[i].h <= ret[cur].h && ret[i].w <= ret[cur].w)
				{
					q.pop();
					ans ++;
					break;
				}
				q.pop();
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int T;
	scanf("%d", &T);
	while(T --) solve();
    return 0;
}

