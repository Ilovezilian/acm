#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
#define M 1000010
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

bool iscut[2*M];
int pre[N],dp[N][2],head[N],nxt[2*M][2];
int n,m,dfs_clock,p;

void init()
{
    for(int i=0; i<n; ++i) pre[i]=dp[i][0]=dp[i][1]=0,head[i]=-1;
    dfs_clock=p=0;
}
void add(int u,int v)
{
    nxt[p][1]=v;
    nxt[p][0]=head[u];
    head[u]=p++;
}
int dfs(int u)
{
    int lowu=pre[u]=++dfs_clock;
    for(int i=head[u]; i!=-1; i=nxt[i][0])
        if(!iscut[i>>1])
        {
            iscut[i>>1]=1;
            int v=nxt[i][1];
            if(!pre[v])
            {
                int lowv=dfs(v);
                lowu=min(lowu,lowv);
                int c=dp[v][1];
                if(pre[u]<lowv) ++c,++m;
                if(dp[u][1]<c)
                {
                    dp[u][0]=dp[u][1];
                    dp[u][1]=c;
                }
                else if(dp[u][0]<c) dp[u][0]=c;
                p=max(p,dp[u][0]+dp[u][1]);
            }
            else lowu=min(lowu,pre[v]);
        }
    return lowu;
}

int main()
{
 //   freopen("in.txt","r",stdin);
    int x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m) break;
        init();
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&x,&y);
            add(x-1,y-1);
            add(y-1,x-1);
            iscut[2*i]=iscut[2*i+1]=false;
        }
        p=m=0;
        dfs(0);
        printf("%d\n",m-p);
    }
    return 0;
}
