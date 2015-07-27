/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/27 11:26:52
File Name     :1005.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define INF 0x0x7fffffff
#define ll long long
using namespace std;
const int N = 8, mod = 1e9+7;

char s[22];
int val[8][6] = 
{
	{0,0,1,-1},
	{0,0,-1,1},
	{-1,1,0,0,-1,1},
	{1,-1,0,0,1,-1},
	{0,0,1,-1},
	{0,0,-1,1},
	{0},
	{0}
};
int main()
{
   //freopen("1005.in","r",stdin);
   //freopen("my.out","w",stdout);
/*	for(int i = 0; i < 8; i ++)
		for(int j = 0; j < 6; j ++)
			printf("%d%c", val[i][j], (j == 5) ? '\n' : ' ');
    
*/
	int cas; 
	scanf("%d", &cas);
	fi(cas_i, cas)
	{
		getchar();
		int sum_1 = 0, sum_2 = 0, sum_3 = 0;
		fi(i,8)
		{
			gets(s);
			int len = strlen(s);
			fi(j,len) 
				if(s[j] == 'y' || s[j] == 'w') sum_1 += val[i][j/2];
			else if(s[j] == 'g' || s[j] == 'b') sum_2 += val[i][j/2];
			else sum_3 += val[i][j/2];
		}

		printf("Case #%d: %s\n", cas_i + 1, (sum_1 % 3 == 0 && sum_2 % 3 == 0 && sum_3 % 3 == 0) ?"YES":"NO");
	}
    return 0;
}
