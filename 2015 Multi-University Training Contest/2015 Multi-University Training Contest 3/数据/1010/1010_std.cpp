#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <time.h>

const int N = 500000 + 5;
std::vector<int> edges[N];
int n,W[N];
int deg[N];
int dp[N];

int work() {
    std::queue<int> que;
    for (int u = 0; u < n; ++ u) {
        if (deg[u] == 0) {
            que.push(u);
        }
    }
    int ret = 0;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        ret = std::max(ret,dp[u]);
        for (int i = 0; i < edges[u].size(); ++ i) {
            int v = edges[u][i];
            dp[v] += dp[u];
            if (--deg[v] == 0) {
                que.push(v);
            }
        }
    }
    return ret;
}

int main() {
    freopen("1010.in","r",stdin);
    freopen("std.out","w",stdout);
    while (scanf("%d",&n) == 1) {
        std::fill(edges,edges + n,std::vector<int>());
        std::fill(deg,deg + n,0);
        std::fill(dp,dp + n,1);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",W + i);
        }
        for (int i = 0; i < n - 1; ++ i) {
            int a,b;
            scanf("%d%d",&a,&b);
            a --; b --;
            if (W[a] < W[b]) {
                std::swap(a,b);
            }
            edges[a].push_back(b);
            deg[b] ++;
        }
        printf("%d\n",work());
    }
    printf("Time = %.2f\n",(double)clock() / CLOCKS_PER_SEC);
}
