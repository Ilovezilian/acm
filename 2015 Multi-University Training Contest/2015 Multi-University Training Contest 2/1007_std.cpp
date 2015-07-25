#include<bits/stdc++.h>
using namespace std;
const int N = 10;
const int M = 100;
int n,m,t,ans,d[N],r[N],s[N];
int ecnt;
struct Edge
{
    int u,v;
} e[M];

void dfs(int x)
{
    //if(ecnt>m/2||x-ecnt-1>m/2) return ;

    if(x>m)
    {
        //if(ecnt!=m/2) return ;
        //cout<<i<<" "<<r[i]<<" "<<s[i]<<endl;
        ++ans;
        return ;
    }

    ++r[e[x].u];
    ++r[e[x].v];
    if(r[e[x].u]>d[e[x].u]/2||r[e[x].v]>d[e[x].v]/2)
    {
        --r[e[x].u];
        --r[e[x].v];
    }
    else
    {
        ++ecnt;
        dfs(x+1);
        --r[e[x].u];
        --r[e[x].v];
        --ecnt;
    }

    ++s[e[x].u];
    ++s[e[x].v];
    if(s[e[x].u]>d[e[x].u]/2||s[e[x].v]>d[e[x].v]/2)
    {
        --s[e[x].u];
        --s[e[x].v];
    }
    else
    {
        dfs(x+1);
        --s[e[x].u];
        --s[e[x].v];
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>e[i].u;
            cin>>e[i].v;
            d[e[i].u]++;
            d[e[i].v]++;
        }
        /*if(m&1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            if(d[i]&1)
            {
                cout<<0<<endl;
                continue;
            }*/
        ans = 0; ecnt = 0;
        memset(r,0,sizeof(r));
        memset(s,0,sizeof(s));
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
/*
5
3 3
1 2
2 3
3 1
4 4
1 2
2 3
3 4
4 1
7 8
1 2
2 3
3 4
4 1
1 5
5 6
6 7
7 1

8 24

1 2
1 3
1 4
1 5
1 6
1 7

2 3
2 4
2 5
2 6
2 8

3 4
3 5
3 8
3 7

4 8
4 6
4 7

5 6
5 7
5 8

6 7
6 8

7 8


*/
