#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int t,n,m,now = 0;
bool mp[N][N];
bool vis[N][N];
bool ans[N<<1];
bool tag[N<<1];
struct node
{
    int x,y,step;
    node(int a,int b):x(a),y(b),step(0) {}
    node(int a,int b,int c):x(a),y(b),step(c) {}
} ;
queue <node> s,q;

void pre()
{
    q.push(node(1,1));
    while(!q.empty())
    {
        node x = q.front();q.pop();
        if(x.x>n||x.y>m||x.x<1||x.y<1) continue ;

        if(n-x.x + m-x.y + 2<now)
        {
            now = n-x.x + m-x.y + 2;
            while(!s.empty()) s.pop();
            if(mp[x.x][x.y]) s.push(x);
        }
        else if(n-x.x + m-x.y + 2 == now && mp[x.x][x.y]) s.push(x);

        if(mp[x.x][x.y]) continue ;
        if(!vis[x.x+1][x.y])
        {
            vis[x.x+1][x.y] = 1;
            q.push(node(x.x+1,x.y));
        }
        if(!vis[x.x-1][x.y])
        {
            vis[x.x-1][x.y] = 1;
            q.push(node(x.x-1,x.y));
        }
        if(!vis[x.x][x.y+1])
        {
            vis[x.x][x.y+1] = 1;
            q.push(node(x.x,x.y+1));
        }
        if(!vis[x.x][x.y-1])
        {
            vis[x.x][x.y-1] = 1;
            q.push(node(x.x,x.y-1));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("1010.in", "r", stdin);
	freopen("1010.out", "w", stdout);
    string tmp;
    cin>>t;
    while(t--)
    {
        now = 1e9 +10;
        int ansb = 0;
        //string ans = "A";
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        memset(ans,1,sizeof(ans));
        memset(tag,0,sizeof(0));
        vis[1][1] = 1;
        cin>>n>>m;
        for(int i =1;i<=n;++i) 
        {
            cin>>tmp;
            for(int j = 0;j<m;++j) mp[i][j+1] = tmp[j] - 48;
        }
        pre();
        while(!s.empty())
        {
            node x = s.front();s.pop();
            ansb = x.step + 1;
            if(tag[x.step] && mp[x.x][x.y]) continue;
            if(ans[x.step]<mp[x.x][x.y]) continue;

            if(ans[x.step]>mp[x.x][x.y])
                ans[x.step] = mp[x.x][x.y];


            if(mp[x.x+1][x.y]==mp[x.x][x.y+1])
            {
                if(x.x+1>n&&x.y+1>m) continue;
                if(x.x+1>n) 
                {
                    if(!mp[x.x][x.y+1]) tag[x.step+1] = 1;
                    s.push(node(x.x,x.y+1,x.step+1));
                }
                else 
                {
                    if(!mp[x.x+1][x.y]) tag[x.step+1] = 1;
                    s.push(node(x.x+1,x.y,x.step+1));
                    if(x.y+1<=m)
                    {
                        if(!mp[x.x][x.y+1]) tag[x.step+1] = 1;
                        s.push(node(x.x,x.y+1,x.step+1));
                    }
                }
            }

            if(mp[x.x+1][x.y]<mp[x.x][x.y+1])
                if(x.x+1<=n) 
                {
                    if(!mp[x.x+1][x.y]) tag[x.step+1] = 1;
                    s.push(node(x.x+1,x.y,x.step+1));
                }
                else 
                {
                    if(!mp[x.x][x.y+1]) tag[x.step+1] = 1;
                    s.push(node(x.x,x.y+1,x.step+1));
                }
            if(mp[x.x+1][x.y]>mp[x.x][x.y+1])
                if(x.y+1<=m) 
                {
                    if(!mp[x.x][x.y+1]) tag[x.step+1] = 1;
                    s.push(node(x.x,x.y+1,x.step+1));
                }
                else 
                {
                    if(!mp[x.x+1][x.y]) tag[x.step+1] = 1;
                    s.push(node(x.x+1,x.y,x.step+1));
                }
        }
        
        if(ansb>=1)
         for(int i=0;i<ansb;i++) cout<<ans[i];
        else cout<<0;
        cout<<'\n';
    }
    return 0;
}
