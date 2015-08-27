/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/20 9:52:49
File Name     :UVALive_4119.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1440, mod = 1e9+7;
char s[N];
int co[102], ex[102], cnt;//coefficients exponet
set<char> symbol = {'+', '-'};

int Stoi(int i, int j)
{
	int num = 0;
	for(int k = j - 1; k >= i; k ++)
		num += 10 * num + (int) (s[k] - '0');
	return num;
}

void scf()
{
	while(scanf("%s", s))
	{
		cnt = 0;
		int len = strlen(s);
		for(int i = 0; i < len; i ++)
		{
			if(isdigit(s[i]))
			{
				int j = i;
				for(;s[i] != 'n'; i ++);
				co[cnt] = Stoi(j,i);
				i ++;

				if(s[i] == '^')
				{
					j = i;
					for(;j != 
					ex[cnt] = Stoi
				}
			}
		}
		return 1;
	}
	return 0;
}

void solve()
{
	while(scf())
	{
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    solve();
    return 0;
}
