/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/9/7 2:01:59
File Name     :srand.cpp
************************************************ */

#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

int main()
{
    srand(time(NULL));
    //freopen("","r",stdin);
    freopen("test.out","w",stdout);
	//printf("%d\n", RAND_MAX);
	for(int cas = 4; cas < 10; cas ++)
	{
		int n, q;
		n = q = rand() * 123 % (10 * cas);
		printf("%d %d\n", n, q);
		for(int i = 0; i < n; i ++)
			printf("1 ");
		printf("\n");
			//printf("%d%c", rand() * 7 % 12344, i != n - 1 ? ' ' : '\n');
		for(int i = 0; i < n; i ++)
		{
			bool ok = rand() > 20000;
			printf("%c", ok ? 'C' : 'Q');
			int a =  rand() % n + 1, b =  rand() % n + 1;
			if(a > b) swap(a, b);
			printf(" %d %d", a, b);
			if(ok) printf(" %d\n", rand() % 1000);
			else printf("\n");
		}
	}
    return 0;
}
