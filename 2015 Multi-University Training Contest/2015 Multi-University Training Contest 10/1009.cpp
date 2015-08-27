/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/20 14:46:12
File Name     :1009.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 100010, mod = 1e9+7;

char s[N], t[N];

void solve()
{
	scanf("%s%s", s, t);
	int len_s = strlen(s), len_t = strlen(t), i = 0, j = 0;

	for(; s[i] == t[i] && s[i] != '\0'; i ++)
		if(i && t[i] != t[i-1]) break;
	if(t[0] == t[i]) 
	{
		printf("No\n");
		return ;
	}

	for(j = i; i < len_s && j < len_t; i ++, j ++)
		while(t[j] != s[i])
		{
			j ++;
			if(j >= len_t)
			{
				printf("No\n");
				return ;
			}
		}
	printf("%s\n", i != len_s ? "No" : "Yes");
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
