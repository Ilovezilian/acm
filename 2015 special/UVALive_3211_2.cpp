#include <iostream>
#include <cstdio>
#include <cstring>
#include<vector>
#include <algorithm>

using namespace std;

const int MAXN = 2005;

struct TwoSAT{
    int n;
    vector<int> g[MAXN * 2];
    bool mark[MAXN * 2];
    int s[MAXN * 2], c;

    bool dfs(int x) {
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x] = true;
        s[c++] = x;
        for (int i = 0; i < g[x].size(); i++)
            if (!dfs(g[x][i])) return false;
        return true;
    }

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n * 2; i++) 
            g[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    void add_clause(int x, int xval, int y, int yval) {
        x = x * 2 + xval;
        y = y * 2 + yval;
        g[x^1].push_back(y);
        g[y^1].push_back(x);
    }

    bool solve() {
        for (int i = 0; i < n * 2; i += 2) 
            if (!mark[i] && !mark[i + 1]) {
                c = 0;
                if (!dfs(i)) {
                    while (c > 0) mark[s[--c]] = false; 
                    if (!dfs(i + 1)) return false;
                }
            }
        return true;
    }
};

TwoSAT solver;
int n, T[MAXN][2];

bool test(int diff) {
    solver.init(n);
    for (int i = 0; i < n; i++)
        for (int a = 0; a < 2; a++)
            for (int j = i + 1; j < n; j++)
                for (int b = 0; b < 2; b++)
                    if (abs(T[i][a] - T[j][b]) < diff)
                        solver.add_clause(i, a^1, j, b^1);
    return solver.solve();
}

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(T, 0, sizeof(T));
        int L = 0, R = 0; 
        for (int i = 0; i < n; i++)
            for (int a = 0; a < 2; a++) {
                scanf("%d", &T[i][a]); 
                R = max(R, T[i][a]);
            }
        while (L < R) {
            int mid = L + (R - L + 1) / 2;
            if (test(mid)) 
                L = mid; 
            else 
                R = mid - 1;
        }
        printf("%d\n", L); 
    }     
    return 0;
}
