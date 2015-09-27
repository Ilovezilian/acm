#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long LL;

int pr[N];
LL cnt[N], cnt1[N];
char s[N];
stack<int> sk;

void solve()
{
    int len = strlen(s);
    LL ans = 0;
    while(!sk.empty()) sk.pop();
    memset(cnt, 0, sizeof(cnt));
	memset(cnt1, 0, sizeof(cnt1));

    for(int i = 0; i < len; i ++)
    {
        if(s[i] == '(') sk.push(i);
        else if(s[i] == ')')
        {
            pr[i] = sk.top();
            sk.pop();
            cnt[i] = cnt[i-1] + 1;
			cnt1[i] = cnt[i] + cnt1[pr[i]-1];
            if(sk.empty()) continue;

            int pre = sk.top();
            if(pre + 1 != pr[i])
            {
                //printf("cnt = %I64d (%d,%d) len = %I64d\n", cnt[i], pr[i], i, cnt[i] * (i + 2 - pre));
                if(s[i+1] == ')') 
				{
					for(int j = i; j != pre; j = pr[j] - 1)
					{
						if(pr[j] - 1 == pre) break;
						ans += cnt1[pr[j]-1] * cnt[j] * (i + 2 - pre);
						//printf("cnt[%d] = %I64d %I64d\n", j, cnt[j], cnt[j] * (i + 2 - pre));
					}
				}
            }
        }
    }
    //for(int i = 0; i < len; i ++) printf("(%d,%I64d,%I64d)%c", i, cnt[i], cnt1[i], i != len - 1 ? ' ' : '\n');
    printf("%I64d\n", ans);
}

int main()
{
    while(~scanf("%s", s)) solve();
    return 0;
}
