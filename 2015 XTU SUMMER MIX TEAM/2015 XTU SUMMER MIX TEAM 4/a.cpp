/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/24 9:40:20
File Name     :a.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

void solve()
{
	int a, b, ok;
	char s[3];
	scanf("%d%s%d", &a, s, &b);
	int len = strlen(s);
	if(len == 1)
	{
		if(s[0] == '<') ok = (a < b);
		else if(s[0] == '>') ok = (a > b);
	}
	else 
	{
		if(s[0] == '=') ok = (a == b);
		else if(s[0] == '!') ok = (a != b);
		else if(s[0] == '<') ok = (a <= b);
		else if(s[0] == '>') ok = (a >= b);
	}
	printf("%s\n", ok ? "true" : "false");
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
