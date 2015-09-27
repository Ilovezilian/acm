/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/11 16:28:44
File Name     :e.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 1e4+10, mod = 1e9+7;
/*
struct nod
{
	int x, y, z;
	nod(int _x, int _y, int _z)
	{
		x = _x, y = _y, z = _z;
	}
}

int ans[N];
vector<nod> v[N];

int cal(int x, int k)
{
	if(!k) return 1;
	if(k == 1) return x;
	int ret = cal(x, k >> 1);
	return ret * ret * (k&1 ? ret : 1);
}

int f(int x, int y, int k)
{
	return x * y * k + cal(x, k) + cal(y, k);
}

void solve()
{
	int tmp;
	for(int i = 1; i < N; i ++)
	{
		for(int j = i + 1; j < N; j ++)
		{
			for(int k = 2; k < N; k ++)
			{
				tmp = f(i, j, k);
				if(tmp > N) break;
			}
		}
	}

	for(int i = 0; i < N; i ++) if(ans[i])
		printf("ans[%d] = %d\n", i, ans[i]);
}
*/
int main()
{
    //freopen("","r",stdin);
    freopen("e.in","w",stdout);
    //solve();
	/*
	int n, m; 
	while(~scanf("%d%d", &n, &m)) printf("%d\n", cal(n, m));
	*/
	for(int i = 1; i < 1000; i ++)
		printf("%d\n", i);
	printf("0\n");
    return 0;

}
