/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/28 20:44:21
File Name     :1004.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

char s[55][55];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int cas, n;
	scanf("%d", &cas);
	while(cas --)
	{
		scanf("%d", &n);
		fi(i,n) scanf("%s", s[i]);
		int len = strlen(s[0]);
		int sum = 0;
		for(int row = 1; row < n; row ++)
		{
			for(int i = row, j = 0; i < n && j < len; i ++, j ++) 
				if((s[i][j] == 'R' || s[i][j] == 'G' ) && (s[i-1][j-1] != 'R' && s[i-1][j-1] != 'G'  ||  j == 0))
					sum ++;
			for(int i = row, j = len - 1; i < n && j >= 0; i ++, j --) 
				if((s[i][j] == 'B' || s[i][j] == 'G' ) && (s[i-1][j+1] != 'B' && s[i-1][j+1] != 'G'  ||  j == len - 1)) 
					sum ++;
		}
		for(int colm = 0; colm < len; colm ++)
		{
			for(int i = 0, j = colm; i < n && j < len; i ++, j ++)
				if((s[i][j] == 'R' || s[i][j] == 'G' ) && (s[i-1][j-1] != 'R' && s[i-1][j-1] != 'G'  ||  j == 0))
					sum ++;
			for(int i = 0, j = colm; i < n && j >= 0; i ++, j --)
				if((s[i][j] == 'B' || s[i][j] == 'G' ) && (s[i-1][j+1] != 'B' && s[i-1][j+1] != 'G'  ||  j == len - 1)) 
					sum ++;
		}
		printf("%d\n", sum);
	}
    return 0;
}
