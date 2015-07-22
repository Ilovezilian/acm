/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/22 13:41:10
File Name     :1002.cpp
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
#define ll long long 
using namespace std;
const int N = 100100, mod = 0;

typedef struct {
	int x, cur;
} P;
P a[N], b[N], p;


int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, k, cas;
	scanf("%d", &cas);
	while(cas --)
	{
		ll ans = 1;
		scanf("%d%d", &n, &k);
		scanf("%d", &a[0].x);
		b[0].x = a[0].x;
		int f1, f2, c1, c2, cur;
		f1 = f2 = c1 = c2 = cur = a[0].cur = b[0].cur = 0;
		fin(i,1,n)
		{
			scanf("%d", &p.x);
			p.cur = i;

			for(int j = c1; j >= f1; j --)
			{
				if(a[j].x > p.x)
				{
					a[j+1].x = p.x, a[j+1].cur = p.cur;
					c1 = j + 1;
					break;
				}	
				if(j == f1)
				{
					a[f1].x = p.x, a[f1].cur = p.cur;
					c1 = f1;
					break;
				}
			}

			for(int j = c2; j >= f2; j --)
			{
				if(b[j].x < p.x)
				{
					b[j+1].x = p.x, b[j+1].cur = p.cur;
					c2 = j + 1;
					break;
				}	
				if(j == f2)
				{
					b[f2].x = p.x, b[f2].cur = p.cur;
					c2 = f2;
					break;
				}
			}

			while(a[f1].x - b[f2].x >= k)
			{
				if(a[f1].cur < b[f2].cur)
				{
					cur = a[f1].cur + 1;
					f1 ++;
				}
				else
				{
					cur = b[f2].cur + 1;
					f2 ++;
				}
			}
			ans += (i - cur + 1);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}




/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define mx 100010
int Min[mx][20],Max[mx][20],n,m,a[mx];

void makermq()
{
for (int i = 1; i <= n; i ++) Min[i][0] = Max[i][0] = i;

for (int i = 1; (1 << i) <= n; i ++)
{
for(int j = 1; j + (1 << i) - 1 <= n; j ++)
{
int p = Min[j][i - 1],q = Min[j + (1 << i - 1)][i - 1];
if (a[p] < a[q] || (a[p] == a[q] && p < q)) Min[j][i] = p;
else Min[j][i] = q;
p = Max[j][i - 1],q = Max[j + (1 << i - 1)][i - 1];
if (a[p] > a[q] || (a[p] == a[q] && p < q)) Max[j][i] = p;
else Max[j][i] = q;
}
}
}

int ask(int l,int r,int q)
{
int tmp = int(log(r - l + 1) / log(2));
int k1,k2;

if (q == 0)
{
k1 = Min[l][tmp],k2 = Min[r - (1 << tmp) + 1][tmp];
if (a[k1] < a[k2] || (a[k1] == a[k2] && k1 < k2)) return k1;
else return k2;
}
else
{
k1 = Max[l][tmp],k2 = Max[r - (1 << tmp) + 1][tmp];
if (a[k1] > a[k2] || (a[k1] == a[k2] && k1 < k2)) return k1;
else return k2;
}
}
int main()
{
cin >> n >> m;
for (int i = 1; i <= n; i ++) cin >> a[i];

makermq();

int l,r,q;
for (int i = 1; i <= m; i ++)
{
cin >> l >> r >> q;
cout << ask(l,r,q) << endl;
}
}



*/
