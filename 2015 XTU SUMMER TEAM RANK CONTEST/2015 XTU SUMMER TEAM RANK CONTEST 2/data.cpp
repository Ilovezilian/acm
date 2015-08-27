#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <set>
#include <stack>
#define LL long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 250;
struct arc{
    int to,flow,next;
    arc(int x = 0,int y = 0,int z = -1){
        to = x;
        flow = y;
        next = z;
    }
};
arc e[100000];
int head[maxn],p[maxn],d[maxn],gap[maxn],cur[maxn];
int tot,S = 1,T,q[10000],hd,tl;
void add(int u,int v,int flow){
    e[tot] = arc(v,flow,head[u]);
    head[u] = tot++;
    e[tot] = arc(u,0,head[v]);
    head[v] = tot++;
}
void bfs(){
    memset(gap,0,sizeof(gap));
    memset(d,-1,sizeof(d));
    d[T] = 0;
    q[tl++] = T;
    while(hd < tl){
        int u = q[hd++];
        ++gap[d[u]];
        for(int i = head[u]; ~i; i = e[i].next){
            if(d[e[i].to] == -1){
                d[e[i].to] = d[u] + 1;
                q[tl++] = e[i].to;
            }
        }
    }
}
int isap(){
    int maxFlow = 0,flow = INF,u = S;
    memcpy(cur,head,sizeof(head));
    bfs();
    while(d[S] < T){
        int &i = cur[u];
        for( ;~i; i = e[i].next)
            if(e[i].flow && d[u] == d[e[i].to] + 1) break;
        if(i > -1){
            flow = min(flow,e[i].flow);
            p[u = e[i].to] = i;
            if(u == T){
                do{
                    int v = p[u];
                    e[v].flow -= flow;
                    e[v^1].flow += flow;
                    u = e[v^1].to;
                }while(u != S);
                maxFlow += flow;
                flow = INF;
            }
        }else{
            if(--gap[d[u]] == 0) break;
            d[u] = T;
            cur[u] = head[u];
            for(int k = head[u]; ~k; k = e[k].next)
                if(e[k].flow && d[e[k].to] + 1 < d[u])
                    d[u] = d[e[k].to] + 1;
            ++gap[d[u]];
            if(u != S) u = e[p[u]^1].to;
        }
    }
    return maxFlow;
}
int main(){
    int x,y,z,n;
    while(~scanf("%d %d",&n,&T)){
        memset(head,-1,sizeof(head));
        tot = 0;
        while(n--){
            scanf("%d %d %d",&x,&y,&z);
            add(x,y,z);
        }
        printf("%d\n",isap());
    }
}




#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 1000;
struct arc {
    int to,flow,next;
    arc(int x = 0,int y = 0,int z = -1) {
        to = x;
        flow = y;
        next = z;
    }
};
arc e[maxn];
int head[maxn],d[maxn],cur[maxn],tot,n,m;
void add(int u,int v,int flow) {
    e[tot] = arc(v,flow,head[u]);
    head[u] = tot++;
    e[tot] = arc(u,0,head[v]);
    head[v] = tot++;
}
bool bfs() {
    queue<int>q;
    memset(d,-1,sizeof(d));
    d[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = head[u]; ~i; i = e[i].next) {
            if(e[i].flow && d[e[i].to] == -1) {
                d[e[i].to] = d[u] + 1;
                q.push(e[i].to);
            }
        }
    }
    return d[n] > 0;
}
int dfs(int u,int low) {
    if(u == n) return low;
    int tmp = 0,a = 0;
    for(int &i = cur[u]; ~i; i = e[i].next) {
        if(e[i].flow > 0 && d[e[i].to] == d[u] + 1 &&(a = dfs(e[i].to,min(low,e[i].flow)))) {
            e[i].flow -= a;
            e[i^1].flow += a;
            tmp += a;
            low -= a;
            if(!low) break;
        }
    }
    if(!tmp) d[u] = -1;
    return tmp;
}
int dinic() {
    int ans = 0;
    while(bfs()) {
        memcpy(cur,head,sizeof(head));
        ans += dfs(1,INF);
    }
    return ans;
}
int main() {
    while(~scanf("%d %d",&m,&n)) {
        memset(head,-1,sizeof(head));
        int u,v,w;
        for(int i = tot = 0; i < m; ++i) {
            scanf("%d %d %d",&u,&v,&w);
            add(u,v,w);
        }
        printf("%d\n",dinic());
    }
    return 0;
}
