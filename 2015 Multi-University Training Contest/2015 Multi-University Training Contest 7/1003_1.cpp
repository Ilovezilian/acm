/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/11 16:42:25
File Name     :1003_1.cpp
 ************************************************ */
//Time Limited Exceeded!

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100010, mod = 1e9+7;

int a[N], n, ans;

int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int cas, zz = 1;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d", &n);
		fi(i,1,n) scanf("%d", a + i);
		ans = 0;
		fi(i,1,n-1)
		{
			if(i + ans * 2 > n) break;

			if(a[i] == a[i+1])
			{
				int lr = min(i*3, n);
				for(int j = i + ans*2 + 2; j <= lr; j += 2) if(a[j] == a[i])
				{ 
					int len = (j - i) / 2;
					//printf("j = %d len = %d\n", j, len);
					bool ok = 1;
					for(int k = 1; k < len; k ++) if(a[i-k] != a[i+k+1] || a[i-k] != a[j-k])
					{
					//	printf("a[%d] = %d a[%d] = %d a[%d] =  %d\n", i-k, a[i-k], i + k + 1, a[i+k+1], j - k, a[j-k]);

						ok = 0;
						break;
					}
					if(ok) ans = len;
				}
			}
		}
		printf("Case #%d: %d\n", zz ++, ans * 3);
	}
	return 0;
}
