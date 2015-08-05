/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/3 15:55:58
File Name     :1132.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

void build(int n, char *s1, char *s2, char *s3)
{
	if( n <= 0) return;
	int p = strchr(s2, s1[n-1]) - s2;
	s3[0] = s1[n-1];
	build(p, s1-1, s2, s3);
	build(n - p - 1, s1 + p - 1, s2 + p - 1, s3 + p);
}

void solve()
{
	char s1[10], s2[10], s3[10];
	scanf("%s%s", s2, s1);
	int len = strlen(s1);
	build(len, s1, s2, s3);
	s3[len] = '\0';
	printf("%s\n", s3);
	
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
 	solve();   
    return 0;
}
