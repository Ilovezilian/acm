#include<cstdio>
using namespace std;
int  d[210000],n,a,b;
inline void cal(char c)
{
    if(a == 1)a = 3,printf("1 %c 2\n",c);
    else printf("%d %c %d\n",b++,c,a++);
}
inline void cals(int x,int y,int z,char c)
{
    printf("%d %c %d\n",x,c,y);
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1; i <= n; ++i)d[i] = n;
        a = 1;
        b = n + 1;
        if(n < 4)puts("-1");
        else if(n == 4)cal('*'),cal('+'),cal('+');
        else if(n == 5)cal('*'),cal('*'),cal('-'),cal('/');
        else if(n == 6)cal('*'),cal('*'),cal('/'),cal('-'),cal('-');
        else if(n == 7)cal('+'),cal('+'),cal('/'),cal('+'),cal('+'),cal('+');
        else if(n == 8)cal('-'),cal('*'),cal('*'),cal('*'),cal('+'),cal('+'),cal('+');
        else if(n == 9)cal('+'),cal('+'),cal('+'),cal('+'),cal('+'),cal('/'),cal('+'),cal('+');
        else if(n <= 12)
        {
            cal('-');
            for(int i = 0; i < n - 5 - (24 - 2 * n); ++i)cal('*');
            for(int i = 0; i < 24 - 2 * n; ++i)cal('+');
            cal('/');cal('+');cal('+');
        }
        else if(n <= 14)
        {
            cal('-');
            for(int i = 0; i < n - 5 - (2 * n - 24); ++i)cal('*');
            for(int i = 0; i < 2 * n - 24; ++i)cal('-');
            cal('/');cal('+');cal('+');
        }
        else
        {
            cals(1,2,n+1,'+');
            cals(n+1,3,n+2,'/');
            cals(4,5,n+3,'+');
            cals(n+3,6,n+4,'/');
            cals(7,8,n+5,'+');
            cals(n+5,9,n+6,'/');
            cals(10,11,n+7,'+');
            cals(n+7,12,n+8,'+');
            cals(n+8,13,n+9,'/');
            cals(n+2,n+4,n+10,'*');
            cals(n+6,n+9,n+11,'*');
            cals(n+10,n+11,n+12,'*');
            cals(14,15,n+13,'-');
            a = 16;
            b = n + 13;
            for(int i = 0; i < n - 15; ++i)cal('*');
            cals(n+12,b,2*n - 1,'+');
        }
    }
    return 0;
}
