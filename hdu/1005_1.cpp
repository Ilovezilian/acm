/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/29 19:54:57
File Name     :1005.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 8, mod = 7;
vector<int> v[N][N];
int a, b, c, f1, f2, n;
void init()
{

	for(int i = 1; i < 7; i ++)
		for(int j = 0; j < 7; j ++)
		{
			if(i == 1 && (!j)) continue;
			v[i][j].push_back(1), v[i][j].push_back(1);
			f1 = f2 = 1;
			while(1)
			{
				f1 = (i * f2 + j * f1) % mod;
				if(f1 == 1 && f2 == 1) break;
				v[i][j].push_back(f1);
				f1 ^= f2,  f2 ^= f1,  f1 ^= f2;
			}
			v[i][j].pop_back();
		}
	v[0][2].push_back(4);v[0][2].push_back(1);v[0][2].push_back(2);
	v[0][3].push_back(5);v[0][3].push_back(1);v[0][3].push_back(3);v[0][3].push_back(2);v[0][3].push_back(6);v[0][3].push_back(4);
	v[0][4].push_back(2);v[0][4].push_back(1);v[0][4].push_back(4);
	v[0][5].push_back(3);v[0][5].push_back(1);v[0][5].push_back(5);v[0][5].push_back(4);v[0][5].push_back(6);v[0][5].push_back(2);
	v[0][6].push_back(6);v[0][6].push_back(1);
//#define local
#ifdef local
	for(int i = 0; i < 7; i ++) for(int j = 0; j < 7; j ++)
	{
		printf("v[%d][%d] = %d \n", i, j, v[i][j].size());
		//		for(int k = 0; k < v[i][j].size(); k ++)
		//			printf("%d%c",v[i][j][k], k != v[i][j].size() - 1 ? ' ' : '\n'); 
	}
#endif

}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	init();
	while(scanf("%d%d%d", &a, &b, &n), n + a + b)
	{
		a %= mod, b %= mod;
		if(n == 1 || n == 2) puts("1");
		else if(!a && !b) puts("0");
		else if((a == 1 && !b) || (!a && b == 1)) puts("1");
		else
		{
			n = (n - 1) % v[a][b].size();
			printf("%d\n", v[a][b][n]);
		}

	}	
	return 0;
}

