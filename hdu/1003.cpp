/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/29 17:34:58
File Name     :1003.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 100010, mod = 1e9+7;
int a[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 	int cas, n;
	scanf("%d", &cas);
	fi(kk,cas)
	{
		if(kk) printf("\n");
		scanf("%d", &n);
		fi(i,n) scanf("%d", a + i);
		int sum = 0, ans = -mod;
		int st = 0, ed = 0, a_st, a_ed;
		fi(i,n)
		{
			sum += a[i];
			if(ans < sum) ans = sum, a_st = st, a_ed = i;
			if(sum < 0) sum = 0, st = i + 1, ed = i;
		}
		printf("Case %d:\n%d %d %d\n", kk + 1, ans, a_st+1, a_ed+1);
	}
    return 0;
}
