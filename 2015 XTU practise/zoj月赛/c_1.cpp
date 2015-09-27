
#include<bits/stdc++.h>
using namespace std;
const int N = 220;

char s[N];

struct lst{
    char c;
    int pre, next;
} l[N];

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%s", &n, s);
        int  ans = 0;

        for(int i = 0; i < n; i ++)
        {
            l[i].c = s[i];
            l[i].pre = i - 1;
            l[i].next = i + 1;
            if(i == 0) l[0].pre = -1;
            if(i == n - 1) l[i].next = -1;
        }
/**
        for(int i = 0; i < n ; i ++)
            printf("(%d,%d,%d,%c)\n", l[i].pre, i, l[i].next, l[i].c);
*/
        for(int i = 1;;)
        {
            int lp = l[i].pre, ln = l[i].next;
            if(ln == -1) break;
            bool ok = 1;
            //printf("%d%d%d\n%c%c%c\n",lp, i, ln, l[lp].c, l[i].c, l[ln].c);
            if(l[ln].c == l[lp].c)
            {
               // printf("(%d,%d,%d,%c)\n", l[i].pre, i, l[i].next, l[i].c);

                int lpp = l[lp].pre, lnn = l[ln].next;

                l[i].pre = lpp;
                if(lpp != -1) l[lpp].next = i;
                l[i].next = lnn;
                if(lnn != -1) l[lnn].pre = i;

                ans += 2;
                ok = 0;
            }

            if(ok || l[lp].pre == -1) i = l[i].next;
            if(i == -1) break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
