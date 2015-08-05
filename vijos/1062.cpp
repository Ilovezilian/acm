/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/30 11:03:12
File Name     :1062.cpp
 ************************************************ */

#include <bits/stdc++.h>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define ll long long
#define INF 0x0x7fffffff
using namespace std;
const int N = 0, mod = 1e9+7;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	stack<unsigned int> s;
	unsigned int a, mx;
	int n;
	while(~scanf("%d", &n))
	{
		while(!s.empty()) s.pop();
		mx = 1;
		s.push(1);
		fi(i,n)
		{
			scanf("%u", &a);
			if(a < mx) 
			{
				printf("%u%c", a - s.top() + 1, i - n + 1 ? ' ' : '\n');
				s.pop();
			}
			else if(a >= mx)
			{ 
				printf("1%c", i - n + 1 ? ' ' : '\n');
				for(unsigned int j = mx; j < a; j ++) s.push(j);
				mx = a  + 1;
			}
		}
	}	
	return 0;
}
