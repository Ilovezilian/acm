#include<bits/stdc++.h>
using namespace std;
#define fi(i,n1,n2) for(int i = n1; i <= n2; i ++)
#define fd(i,n1,n2) for(int i = n1; i >= n2; i --)

const int N = 2020;

struct TwoSat{
	int n;
	vector<int> G[N*2];
	bool mark[N*2];
	int s[N*2], c;

	bool dfs(int x)
	{
		if(mark[x^1]) return 0;
		if(mark[x]) return 1;
		//printf("x = %d\n", x);
		mark[x] = 1;
		s[c++] = x;
		fi(i,0, (int) G[x].size() - 1) if(!dfs(G[x][i])) return 0;
		return 1;
	}

	void init(int n)
	{
		this->n = n;
		memset(mark, 0, sizeof(mark));
		fi(i,0,N*2-1) G[i].clear();
	//	printf("init()\n");
	}

	void add_clause(int x, int xval, int y, int yval)
	{
		x = x * 2 + xval;
		y = y * 2 + yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	//	printf("add_clause()\n");
	}

	bool solve()
	{
		for(int i = 0; i < n * 2; i += 2)
		if(!mark[i] && !mark[i+1])
		{
			c = 0;
			if(!dfs(i))
			{
				//fi(j,0,c-1) printf("c[%d] = %d \t", j, s[j]);
				//puts("");
				while(c > 0) mark[s[--c]] = 0;
				if(!dfs(i+1)) return 0;
			}
		}
		return 1;
	}
};
TwoSat solver;

int T[N][2], n;

bool test(int diff)
{
/*
 printf("fuck\n");
*/
	solver.init(n);
	fi(i,0,n-1) fi(a,0,1) fi(j,i+1,n-1) fi(b,0,1)
		if(abs(T[i][a] - T[j][b]) < diff)
			solver.add_clause(i, a^1, j, b^1);

	return solver.solve();
}

void solve()
{
	while(~scanf("%d", &n))
	{
		int l = 0, r = 0, mid;
		fi(i,0,n-1) fi(a,0,1)
		{
			scanf("%d", &T[i][a]);
			if(r < T[i][a]) r = T[i][a];
		}

		while(l < r)
		{
			//printf("(%d,%d)\n", l, r);
			mid = l + (r - l + 1) / 2;
			if(test(mid)) l = mid;
			else r = mid - 1;
		}

		printf("%d\n", l);
	}
}

int main()
{
	solve();
	return 0;
}
