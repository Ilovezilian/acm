/* ***********************************************
Author        :Ilovezilian
Created Time  :2015/7/23 19:56:20
File Name     :1009.cpp
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
const int N = 0, mod = 1e9+7;

int n, a, b;
void cal(char c)
{
	if(a == 1) {printf("1 %c 2\n", c); a = 2, b = n;}
	else printf("%d %c %d\n", b, c, a);
	a ++ , b ++;
}

void cals(int x, int y, char c)
{
	printf("%d %c %d\n", x, c, y);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(~scanf("%d", &n))
	{
		a = 1;
		if(n <= 3) puts("-1");
		else if(n == 4) cal('*'), cal('+'), cal('+');
		else if(n == 5) cal('*'), cal('*'), cal('-'), cal('/');
		else if(n == 6) cal('-'), cal('+'), cal('+'), cal('+'), cal('+');
		else if(n == 7) cal('+'), cal('+'), cal('/'), cal('+'), cal('+'), cal('+');
		else if(n == 8) cal('-'), cal('*'), cal('*'), cal('*'), cal('+'), cal('+'), cal('+');
		else if(n == 9) cal('-'), cal('-'), cal('-'), cal('-'), cal('/'), cal('+'), cal('+'), cal('+');
		else if(n == 10) cal('-'), cal('*'), cal('+'), cal('+'), cal('+'), cal('+'), cal('/'), cal('+'), cal('+');
		else if(n == 11) cal('-'), cal('*'), cal('*'), cal('*'), cal('*'), cal('+'), cal('+'), cal('/'), cal('+'), cal('+');
		else if(n == 12) cal('-'), cal('*'), cal('*'), cal('*'), cal('*'), cal('*'), cal('*'), cal('*'), cal('*'), cal('+'), cal('+');
		else if(n == 13) cal('-'), cal('*'), cal('*'), cal('*'), cal('*'), cal('*'), cal('*'), cal('-'), cal('-'), cal('/'), cal('+'), cal('+');
		else if(n == 14) cal('-'), cal('*'), cal('*'), cal('*'), cal('*'), cal('*'), cal('-'), cal('-'), cal('-'), cal('-'), cal('/'), cal('+'), cal('+');
		else
		{
			cals(1,2,'+');
            cals(n+1,3,'/');
            cals(4,5,'+');
            cals(n+3,6,'/');
            cals(7,8,'+');
            cals(n+5,9,'/');
            cals(10,11,'+');
            cals(n+7,12,'+');
            cals(n+8,13,'/');
            cals(n+2,n+4,'*');
            cals(n+6,n+9,'*');
            cals(n+10,n+11,'*');
            cals(14,15,'-');
            a = 16;
            b = n + 13;
			fi(i,n-15) cal('*');
			cals(n + 12, b, '+');
		}
	}
    return 0;
}
