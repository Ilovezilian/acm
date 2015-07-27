/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/25 20:21:46
File Name     :c.cpp
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
const int N = 18501, mod = 1e9+7;
int value[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	fin(i, 1, N) value[i] = 3 * i * (i - 1) + 1;
    
	int cas, m, k;
	scanf("%d", &cas);
	while(cas --)
	{
		scanf("%d", &m);
		if(m % 6 == 1)
		{
			if(binary_search(value + 1, value + N, m)) puts("1");
			else puts("7");
		}
		else if( m % 6 == 2)
		{
			bool mark = 0;
			int j = N - 1;
			fin(i, 1, N) 
			{
				for(; value[i] + value[j] > m; j --) ;
				if(value[i] + value[j] == m)
				{
					mark = 1;
					break;
				}
			}
			printf("%d\n", mark ? 2 : 8);
		}
		else printf("%d\n", (m - 1) % 6 + 1);
	}
    return 0;
}
