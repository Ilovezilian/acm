/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/11 17:55:32
File Name     :e_1.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;
typedef long long LL;
int pw_2[32];

void init()
{
	pw_2[0] = 1;
	for(int i = 1; i < 32; i ++)
		pw_2[i] = pw_2[i-1] * 2;
}

LL cal(int x, int k)
{
	if(!k) return 1;
	if(k == 1) return x;
	LL ret = cal(x, k >> 1);
	return ret * ret * (k&1 ? ret : 1);
}

void solve()
{
	init();
	int k, ans;
	while(~scanf("%d", &k) && k)
	{
		ans = 0;
		int b = (int) sqrt(k);
		if(b * b == k)
			ans = (b - 1) / 2;

		for(int z = 3; z < 31; z ++)
		{
			LL k_1 = 0;
			for(int i = 1; k_1 < k ; i ++)
			{
				LL tmp = cal(i, z);
				k_1 = k - tmp;
				//printf("(%I64d,%I64d)\n", tmp, k_1);
				if(k_1 <= tmp) break;

				int l = i + 1, r = 1024;
				//printf("r = %d\n", r);
				while(l < r)
				{
					int mid = l + (r - l) / 2;
					LL tmp = cal(mid, z) + mid * i * z;
					if(tmp == k_1)
					{
						ans ++;
						break;
					}
					if(tmp < k_1) l = mid + 1;
					else r = mid;
					//printf("%d,%d,%d)\n", l, mid, r);
				}
				/*
				*/
			}
		}
		printf("(%d,%d)\n", k, ans);
	}
}

int main()
{
    freopen("e.in","r",stdin);
    freopen("e_1.out","w",stdout);
    solve();
    return 0;
}
