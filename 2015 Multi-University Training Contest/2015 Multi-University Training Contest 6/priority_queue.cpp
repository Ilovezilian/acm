/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/7 16:53:59
File Name     :priority_queue.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 0, mod = 1e9+7;

struct pp{
	int x, y;
	friend bool operator < (pp a, pp b) const
	{
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    
	const int len = 5;
	int i; 
	int a[len] = {3, 4, 7, 3, 7};
	priority_queue<int> qi;
	for(int i = 0;i < lne; i ++)
		qi.push(a[i]);
	for(i = 0; i< len ; i ++)
	{
		printf("%d\n", qi.top());
		qi.pop();
	}
    return 0;
}
