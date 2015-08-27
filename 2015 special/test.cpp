#include<bits/stdc++.h>
using namespace std;

struct my_char
{
	char s;
	my_char(char a)
	{
		s = a;
	}

	my_char() {};
	bool operator < (const my_char &a) const
	{
		return a.s < s;
	}
};

int main()
{
	set<my_char> g;
	g.insert(my_char('+'));
	g.insert(my_char('-'));
	char s[1001];

	while(~scanf("%s", s))
	{
		int len = strlen(s);
		for(int i = 0; i < len; i ++) if(g.find(s[i]))
			printf("%d",i);
		printf("\n");
	}
	return 0;
}
/*
#include<iostream>
#include<deque>
#include<iterator>
using namespace std;

void viewByArrey(deque<int> zm);
void viewByIterator(deque<int> zm);
void insertFrontAndCenter(deque<int> zm);

int main()
{
	deque<int zm;
	insertFrontAndCenter(zm);
	system("pause");
}

void viewByArrey(deque<int> zm)
{
	zm.push_back(26);
	zm.push_back(11);
	zm.push_back(12);
	for(int i = 0; i < zm.size(); i ++)
		cout<<z[i]<<endl;
}

void viewByIterator(deque<int> zm)
{
	zm.push_back(111);
	zm.push_back(222);
	zm.push_back(333);
	deque<int>::iterator aa;
	int i = 0;
	for(aa = zm.begin(), i = 0; aa !- zem.end(); a++, i ++)
		cout<<aa[0]<<"\t"<<*aa<<endl;
}

void insertFrontAndCenter(deque<int> zm)
{
	zm.push_back(111);
	zm.push_back(222);
	zm.push_back(333);
	zm.insert(zm.begin()+2, 444);
	for(int i = 0; i < zm.size(); i ++)
		cout<<zm[i]<<",";
	cout<<endl;
	}
*/
/*

#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>

using namespace std;

int a,b,k;
//数字和最多为1+9*9=82，如果MOD大于此值，一定无解
//这是重要隐含条件，否则数据范围过大，内存无法承受。
int dp[15][110][110];
int pw[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int dfs(int d,int m1,int m2)
{
    if(d==0) return (m1==0&&m2==0)?1:0;
    if(dp[d][m1][m2]>=0) return dp[d][m1][m2];
    dp[d][m1][m2]=0;
    //加法原理，同余原理
    for(int i=0;i<10;i++)
        dp[d][m1][m2]+=dfs(d-1,((m1-i)%k+k)%k,((m2-i*pw[d-1])%k+k)%k);
    return dp[d][m1][m2];
}

//计算小于n的满足条件的数
int func(int n)
{
    int d=0,m1=0,m2=0,a[15];
    if(n==0) a[d++]=0;
    while(n!=0)
    {
        a[d]=n%10;
        n/=10;
        d++;
    }
    int ans=0;
    for(int i=d-1;i>=0;i--)
    {
        if(i!=0)
        for(int j=0;j<a[i];j++)
        {
            ans+=dfs(i,(k-(m1+j)%k)%k,(k-(m2+pw[i]*j)%k)%k);
          //cout<<i<<" "<<(k-(m1+j)%k)%k<<" "<<(k-(m2+pw[i]*j)%k)%k<<endl;
        }
        else
        for(int j=0;j<=a[i];j++)//如果个位不特判，则算出的结果为<n的数量，n本身会被遗漏，但只要把输出换乘func(b+1)-func(a)效果相同
        {
            ans+=dfs(i,(k-(m1+j)%k)%k,(k-(m2+pw[i]*j)%k)%k);
          //cout<<i<<" "<<(k-(m1+j)%k)%k<<" "<<(k-(m2+pw[i]*j)%k)%k<<endl;
        }
        m1+=a[i];
        m2+=pw[i]*a[i];

    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        if(k>85)
            printf("0\n");
        else{
            memset(dp,-1,sizeof(dp));
            printf("%d\n",func(b)-func(a-1));
        }
    }
    return 0;
}
*/
/*
#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<cmath>
#include<memory.h>
#include<set>

#define ll long long
#define LL __int64
#define eps 1e-8

#define inf 0xfffffff

using namespace std;

//vector<pair<int,int> > G;
//typedef pair<int,int> P;
//vector<pair<int,int>> ::iterator iter;
//
//map<ll,int>mp;
//map<ll,int>::iterator p;
//

#define IN freopen("c:\\Users\\linzuojun\\desktop\\input.txt", "r", stdin)
#define OUT freopen("c:\\Users\\linzuojun\\desktop\\output.txt", "w", stdout)

int a,b,k;
int dp[12][112][112];
int c[12];

void clear()
{
	memset(dp,0,sizeof(dp));
}

ll detal(int x)
{
	clear();
	int tempx=x;
	for(int i=10;i>=0;i--)
	{
		c[i]=tempx%10;
		tempx/=10;
	}
	int ans1,ans2;
	ans1=ans2=0;
	for(int i=0;i<10;i++)
	{
		ans1=(ans1+c[i])%k;
		ans2=(ans2*10+c[i])%k;
		for(int j=0;j<k;j++)
			for(int l=0;l<k;l++)
				for(int p=0;p<10;p++)
					dp[i+1][(j+p)%k][(l*10+p)%k]+=dp[i][j][l];
		for(int j=0;j<c[i+1];j++)
			dp[i+1][(ans1+j)%k][(ans2*10+j)%k]++;
	}
	ll ans=dp[10][0][0];
	if((ans1+c[10])%k==0 && (ans2*10+c[10])%k==0)
		ans++;
	return ans;
}

int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>k;
		if(k>=83)
			puts("0");
		else
			cout<<detal(b)-detal(a-1)<<endl;
	}
}
*/
