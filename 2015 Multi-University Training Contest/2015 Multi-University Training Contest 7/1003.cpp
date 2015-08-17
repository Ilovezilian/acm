/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/11 14:04:38
File Name     :1003.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100100, mod = 1e9+7;

int a[N], n;

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int cas, slen = 800000;
	scanf("%d", &cas);
	fi(ca,1,cas)
	{
		scanf("%d", &n);
		fi(i,1,n) scanf("%d", a + i);
		int ans = 0;
		for(int len = 1; len*3 <= n && len * 3 <= slen; len ++)
		{
			bool ok = 1;
			//fi(i,1,len) printf("len = %d %d %d %d\n", len, a[i], a[len*2-i+1],a[len*2+i]);
			
			fi(i,1,len) if(a[i] != a[len*2+i] || a[i] != a[len*2-i+1]) 
			{
				ok = 0; 
				break;
			}
			if(ok) ans = len;
		}
		slen -= ans * 3;
		printf("Case #%d: %d\n", ca, ans * 3);
	}
    return 0;
}
