/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/31 19:57:23
File Name     :cc.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
int l[101], w[101];

void solve()
{
	int n, ans_min, ans_max;

	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", l + i);
	for(int i = 0; i < n; i ++)
		scanf("%d", w + i);

	ans_min = ans_max = 0;

	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			ans_max += min(l[i], w[j]);


	sort(l, l + n);
	sort(w, w + n);

	for(int i = n - 1, j = n - 1; i + 1 || j + 1;)
	{
		if(i == -1)
		{
			while(j) ans_min += w[j], j --;
			ans_min += w[0];
			break;
		}

		if(j == -1)
		{
			while(i) ans_min += l[i], i --;
			ans_min += l[0];
			break;
		}

		if(l[i] == w[j])
		{
			ans_min += l[i];
			i --, j --;
		}
		else if(l[i] > w[j])
		{
			ans_min += l[i];
			i --;
		}
		else
		{
			ans_min += w[j];
			j --;
		}
	}
	printf("Minimalni budova obsahuje %d kostek, maximalni %d kostek.\n", ans_min, ans_max);

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
