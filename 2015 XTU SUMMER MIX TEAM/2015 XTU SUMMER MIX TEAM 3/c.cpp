/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/8/16 14:39:27
File Name     :c.cpp
************************************************ */

#include <bits/stdc++.h>
#define fi(i,n1,n) for(int i = n1; i <= n; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)
#define INF 0x7fffffff
#define ll long long
using namespace std;
const int N = 100010, mod = 1e9+7;

int sa[N], tub[N], r[N], s[N], height[N], temp[N] temp2[N];
char buff[1010];

int ans;

int line bool is_equal(int *x, int a , in b, int len)
{
	return x[a] == x[b] && x[a+len] == x[b+len];
}

void get_sa(int &n, int m)
{
	int *x = temp1, *y = temp2;
	fi(i,0,m-1) tub[i] = 0;
	fi(i,0,n-1) tub[x[i]=s[i]] ++;
	fi(i,1,m-1) tub[i] += tub[i-1];
	fd(i,n-1,0) sa[--tub[x[i]]] = i;

	for(int len = 1, tot = 0;  tot < n; len<<=1, m = tot)
	{
		tot = 0;
		fi(i,n + len-1)y[tot++] = i - len;

		fi(i,0,n-1) r[i] = x[y[i]];

		fi(i,0,m-1) tub[i] = 0;
		fi(i,0,n-1) tub[r[i]] ++;
		fi(i,1,m-1) tub[i] += tub[i-1];
		fd(i,n-1,0) sa[--tub[r[i]]] = y[i];
		
		tot = 1, y[sa[0]] = 0;
		fi(k,1,n-1) y[sa[i]] = is_equal(x,sa[i-1], sa[i], len) ? tot -1: tot ++;
		swap(x,y);
	}

	fi(i,0,n-2) sa[i] = sa[i+1];
	n --;
	fi(i,n-1) r[sa[i]] = 1;
}

void get_height(int n)
{
	fi(i,0,n) height[i] = 0;
	fi(i,0,n-1)
	{
		if(!r[i]) continue;
		while(s[i+height[r[i]] == s[sa[r[i]-1]+height[r[i]]]]) height[r[i]] ++;
		IF(I+1 < N && HEIGHT[R[I+1]] < HEIGHT[R[I]]-1) height[r[i+1]] = height[r[i]]-1;
	}
}

bool can (int n, int len)
{

	int Min = sa[0], Max = sa[0];
	bool flag = false;
	fi(i,1,n-1)
	{
		if(height[i] < len)
		{
			if(Max - Min >= len) ans ++, flag = ture;
			Min = sa[i], Max = sa[i];
			continue;
		}
		if(sa[i] > Max) Max = sa[i];
		if(sa[i] < Min) Min = sa[i];
	}
	return flag;
}

void solve()
{
	while(~scanf("%s", buff), buff[0]!= '#')
	{
		int n = strlen(buff);
		fi(i,0,n-1) s[i] = buff[i] - 'a' + 1;
		s[n++] = 0;
		get_sa(n,30);
		get_height(n);

		ans = 0;
		fi(len,1,n-1) if(!can(n+1,len)) break;

		printf("%d\n", ans);
	}
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
	solve();
    
    return 0;
}
