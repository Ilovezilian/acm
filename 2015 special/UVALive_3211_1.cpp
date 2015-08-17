#include<cstring>
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<ctime>
#include<cstdlib>
#include<functional>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
#define MAXN 2010
#define eps 1e-7
#define INF 0x3F3F3F3F      //0x7FFFFFFF
#define LLINF 0x7FFFFFFFFFFFFFFF
#define seed 1313131
#define MOD 1000000007
#define ll long long
#define ull unsigned ll
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

struct TwoSAT{
    int n;
    vector<int> G[MAXN * 2];
    bool mark[MAXN * 2];
    int S[MAXN * 2], c;
    bool dfs(int x){
        if(mark[x ^ 1]) return false;
        if(mark[x]) return true;
        mark[x] = true;
        S[c++] = x;
        for(int i = 0; i < G[x].size(); i++){
            if(!dfs(G[x][i]))   return false;
        }
        return true;
    }

    void init(int n){
        this->n = n;
        for(int i = 0; i < n * 2; i++)  G[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    //x = xval or y = yval
    void add_clause(int x, int xval, int y, int yval){
        x = x * 2 + xval;
        y = y * 2 + yval;
        G[x ^ 1].push_back(y);
        G[y ^ 1].push_back(x);
    }

    bool solve(){
        for(int i = 0; i < n * 2; i += 2){
            if(!mark[i] && !mark[i + 1]){
                c = 0;
                if(!dfs(i)){
                    while(c > 0)    mark[S[--c]] = false;
                    if(!dfs(i+1))   return false;
                }
            }
        }
        return true;
    }
};

TwoSAT fuck;
int n, T[MAXN][2];

bool gao(int diff){
    int i, j;
    fuck.init(n);
    for(i = 0; i < n; i++){
        for(int a = 0; a < 2; a++){
            for(j = i + 1; j < n; j++){
                for(int b = 0; b < 2; b++){
                    if(abs(T[i][a] - T[j][b]) < diff)
                        fuck.add_clause(i, a ^ 1, j, b ^ 1);
                }
            }
        }
    }
    return fuck.solve();
}
int main(){
    int i, j;
    while(scanf("%d", &n) != EOF){
        int l = 0, r = 0;
        for(i = 0; i < n; i++){
            scanf("%d%d", &T[i][0], &T[i][1]);
            int temp = max(T[i][0], T[i][1]);
            r = max(r, temp);
        }
        int ans;
        while(l <= r){
            int mid = (l + r) / 2;
            if(gao(mid)){
                if(!gao(mid + 1)){
                    ans = mid;
                    break;
                }
                else    l = mid + 1;
            }
            else    r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
