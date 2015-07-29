/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/26 9:52:27
File Name     :test.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 10000, mod = 1e9+7;
int a[N];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//int n1, n2; 

	int n, p, cas;
	scanf("%d", &cas);
	while(cas --)
	{
		scanf("%d%d", &n, &p)
		printf("%s\n", n & 1 && n != 1 ? "YES":"NO");
	}
	return 0;
}
