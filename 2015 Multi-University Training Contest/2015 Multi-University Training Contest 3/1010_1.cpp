#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define prt(k) cout<<#k" = "<<k<<endl;
const int N = 501000;
int dp[N], g[N], w[N];
struct edge
{
        int v, next;
}e[N<<1];
int head[N], mm;
void add(int u, int v)
{
        e[mm].v= v;
        e[mm].next = head[u];
        head[u] = mm++;
}
int pa[N];

int up(int u)
{
        if (~g[u]) return g[u];
        g[u] = 1;
        int v = pa[u];
        if (w[u] > w[v]) g[u] = up(v) + 1;
        return g[u];
}
int n;
pair<int, int> p[N];
int main()
{
        while (scanf("%d", &n)==1) {
                for (int i=1;i<=n;i++) scanf("%d", w+i), p[i]=make_pair(w[i], i);
                sort(p+1, p+n+1);
				for(int i = 1; i < n+ 1; i ++) printf("[pair[%d].first = %d pair[%d].second = %d\n", i, p[i].first, i, p[i].second);
                mm = 0; memset(head, -1, sizeof head);
                for (int i=0;i<n-1;i++) {
                        int u, v;
                        scanf("%d%d", &u, &v);
                        add(u, v);
                        add(v, u);
                }
                memset(dp, -1, sizeof dp);
                memset(g, -1, sizeof g);
                pa[1] = 1;  g[1] = 1;
                int ans = 1;
                for (int i=n;i>=1;i--) {
                        int u = p[i].second;
                        dp[u] = 1;
                        for (int j=head[u];~j;j=e[j].next) {
                                int v = e[j].v;
                                if (w[u] < w[v]) dp[u] += dp[v];
                        }
                        ans = max(ans, dp[u]);
                }
                printf("%d\n", ans);
        }
        return 0;
}

