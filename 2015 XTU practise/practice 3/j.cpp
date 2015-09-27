/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/11 14:01:01
File Name     :j.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e6 + 10, mod = 1e9+7;
int ans[N], cnt[5005];

void solve()
{
	int n, m, len, num;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%d", cnt+i);

	char s[9];
	memset(ans, 0, sizeof(ans));
	for(int i = 0; i < m; i ++)
	{
		scanf("%s", s);
		len = strlen(s);
		num = 0;
		int t;
		for(int j = 0; j < len; j ++)
		{
			t = (int) (s[j] - 'a') / 3 + 2;
			if(s[j] == 's') t = 7;
			else if(s[j] == 'v') t = 8;
			else if(s[j] == 'y' || s[j] == 'z') t = 9;
			num = num * 10 + t;
		}
		ans[num] ++;
		//printf("num = %d\n", num);
	}
	for(int i = 0; i < n; i ++)
		printf("%d\n", ans[cnt[i]]);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
    return 0;
}

/*

1
1 9
222
abc
def
ghi
jkl
mno
pqrs
tuv
wxyz
asdf

*/
