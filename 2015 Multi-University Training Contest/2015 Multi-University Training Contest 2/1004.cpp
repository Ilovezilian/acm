/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/24 16:58:27
File Name     :1004.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fi(i,n) for(int i = 0; i < n; i ++)
#define fin(i,n1,n2) for(int i = n1; i < n2; i ++)
#define INF 0x0x7fffffff
#define ll long long
using namespace std;
const int N = 1e+5 + 10, mod = 1e9+7;
int l, n, k, rl, rr, sum, c1, c2;
ll ans;
struct node
{
	int x, a;
} apple1[N], apple2[N], mid;

bool cmp(node a, node b) { return a.x < b.x;}

void solve()
{
	scanf("%d%d%d", &l, &n, &k);
	int x, a;
	ans = sum = rl = rr = c1 = c2 = 0;
	fi(i,n) 
	{
		scanf("%d %d", &x, &a);
		if(!x) continue;
		if(x < l / 2 || x == l / 2 && l & 1) apple1[c1].x = x, apple1[c1++].a = a, rl += a;
		else if( x > l / 2) apple2[c2].x = l - x, apple2[c2++].a = a, rr += a;
		else mid.x = x, mid.a = a;
		sum += a;
	}
	sort(apple1, apple1 + c1, cmp);
	sort(apple2, apple2 + c2, cmp);

	fi(i,c1) if(apple1[i].a > 0)
	{
		if(rl < k) break;
		ans += apple1[i].x;
		int kk = k;
		for(int j = i; j < c1 && kk > 0; j ++)
		{
			if(kk < apple1[j].a) 
			{
				rl -= kk, apple1[j].a -= kk, sum -= kk;
				i = j - 1;
				break;
			}
			else kk -= apple1[j].a, sum -= apple1[j].a, rl -= apple1[j].a, apple1[j].a = 0;
		}
	}

	fi(i,c2) if(apple2[i].a > 0)
	{
		if(rr < k) break;
		ans += apple2[i].x;
		int kk = k;
		for(int j = i; j < c2 && kk > 0; j ++)
		{
			if(kk < apple2[j].a) 
			{
				rr -= kk, apple2[j].a -= kk, sum -= kk;
				i = j - 1;
				break;
			}
			else kk -= apple2[j].a, sum -= apple2[j].a, rr -= apple2[j].a, apple2[j].a = 0;
		}
	}

	int in1 = 0, in2 = 0;
	//printf("%d\n", (ans + in2 + in1) * 2);
	if(l % 2 == 0) 
	{
		while(mid.a >= k) ans += mid.x, mid.a -= k, sum -= k;
		//printf("sum = %d rl = %d rr = %d\n", sum, rl, rr);
		//printf("mid.a = %d mid.x = %d \n", mid.a, mid.x);
		if(mid.a)
		{
			if(sum <= k) ans += mid.x, rl = rr = sum = 0;
			else
			{
				if(mid.a + rl <= k) ans += mid.x, mid.a = rl = sum = 0;
				else if(mid.a + rr <= k) ans += mid.x, mid.a = rr = sum = 0;
				else 
				{
					ans += mid.x, rl -= k - mid.a, sum -= k, mid.a = 0;
					for(int i = 0, ss = 0; i < c1; i ++)
					if(ss + apple1[i].a <= k - mid.a) ss += apple1[i].a, apple1[i].a = 0;
					else if(ss + apple1[i].a > k- mid.a)
					{
						apple1[i].a -= k - mid.a - ss;
						break;
					}
				}
			}
		}
	}

	if(rl > 0) for( int i = c1 - 1; ; i --) if(apple1[i].a) {in1 = apple1[i].x; break;}
	if(rr > 0) for( int i = c2 - 1; ; i --) if(apple2[i].a) {in2 = apple2[i].x; break;}
	if(sum <= k && (in1 + in2) * 2 > l) in1 = l - in2;
	//printf("rl = %d rr = %d sum = %d\n", rl, rr, sum);
	//printf("in1 = %d in2 = %d\n", in1, in2);

	printf("%I64d\n", (ans + in2 + in1) * 2);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas;
	scanf("%d", &cas);
	while(cas --) solve();
    return 0;
}
