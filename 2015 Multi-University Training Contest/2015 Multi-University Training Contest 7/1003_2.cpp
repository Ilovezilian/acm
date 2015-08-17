/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/11 22:59:46
File Name     :1003_2.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100010, mod = 1e9+7;

int a[N<<1], dp[N<<1];

int main()
{
    freopen("st.in","r",stdin);
    //freopen("","w",stdout);
	int cas, n, ans;
	scanf("%d", &cas);
	fi(ccas, 1, cas)
	{
		memset(a, -1, sizeof(a));
		memset(dp, 0, sizeof(dp));

		scanf("%d", &n);
		fi(i,1,n) scanf("%d", a + i*2);

		int len = n * 2, id = 0;
		a[0] = -2, a[len+2] = -3;
		dp[0] = dp[1] = dp[len+1] = 1;
	
		fi(i, 2, len + 1)
		{
			if(dp[id] + id > i) dp[i] = min(dp[id*2-i], dp[id] + id - i);
			else dp[i] = 1;
			
			while(a[i+dp[i]] == a[i-dp[i]]) dp[i] ++;//i + dp[i] <= len + 1 && i - dp[i] >= 1 && 
			if(dp[id] + id < i + dp[i]) id = i;
		}

		ans = -1;
		//fi(i,1,n) dp[i] = dp[i*2]/2;
		for(int i = 1; i <= len+1; i += 2) if(dp[i] + i <= len + 1)
		{
			for(int k = ans + 2; k <= dp[i]; k += 2)
			//if(dp[i] <= dp[i+k-1] || dp[i+k-1] >= dp[i])
			if(dp[i] >= k && dp[i + k - 1] >= k)
				ans = k;

			/*
			if(dp[i] + i <= len + 1 && dp[i] <= dp[dp[i] + i - 1] && dp[i] > ans)
				ans = dp[i];
			if(j - dp[j] + 1 >= 0 && dp[j] <= dp[j - dp[j] + 1] && dp[j] > ans)
				ans = dp[j];
			*/
		}

		//fi(i,1,len+1) printf("dp[%d] = %d\n", i, dp[i]);
		if(ans == 1) ans = 0;
		printf("Case #%d: %d\n",ccas, ans / 2 * 3);
	}
   //printf("%d\n", (int)clock()); 
    return 0;
}
