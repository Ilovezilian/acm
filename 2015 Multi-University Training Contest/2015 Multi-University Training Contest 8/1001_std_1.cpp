#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 200002;
//表示一路保持油箱满油的情况下，以多少价格买入了多少油
struct DAT{
	int cnt;
	int val;
}Q[N];
int n, C, buy[N], sell[N], a[N], total, l, r;
ll ans;

//将所有小于等于v价格买入的油换成以v价格买入
//因为多余的油是要退掉的，只不过这里把退的时机从原价买原价卖变成v的价格卖出而已
void Max(int v){
	int num=0;
	while(l <= r && Q[l].val < v){
		num += Q[l].cnt;
		l ++;
	}
	if(num){
		l --;
		Q[l].val = v;
		Q[l].cnt = num;
	}
}

//把所有大于等于v价格买入的油换成以v价格买入
//Q里的油都是多余的油，提前买了也没用
void Min(int v){
	while(l <= r && Q[r].val > v){
		ans -= 1ll * Q[r].val * Q[r].cnt;
		total += Q[r].cnt;
		r --;
	}
}

//移动消耗：把当前以最便宜的价格买入的油删掉
//因为已经有油的情况下，退贵的油更合算
void Del(int num){
	while(num){
		int v = min(num, Q[l].cnt);
		Q[l].cnt -= v;
		num -= v;
		if(Q[l].cnt == 0)
			l ++;
	}
}

int main(){
	int T, i;
	for(scanf("%d",&T); T --; ){
		scanf("%d%d", &n, &C);
		for(i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		for(i = 0; i <= n; i ++)
			scanf("%d%d", &buy[i], &sell[i]);
		ans = 0;
		l = r = 0;
		r --;
		for(i = 0; i <= n - 1; i ++){
			//首先如果有多余的油能卖，先考虑卖
			Max(sell[i]);
			//每个点需要补充的油，使油箱补满
			total = (i == 0 ? C : (a[i] - a[i-1]));
			//之前买贵了的油，换成现在买
			Min(buy[i]);
			//买入total的油
			r ++;
			Q[r].val = buy[i];
			Q[r].cnt = total;
			ans += 1ll * buy[i] * total;
			//减去路上行动的消耗
			Del(a[i+1] - a[i]);
		}
		Max(sell[n]);
		//最后还多出来的油，哪里买的还在哪里卖掉，所以是原价
		for(i = l; i <= r; i ++)
			ans -= 1ll * Q[i].val * Q[i].cnt;
		printf("%I64d\n",ans);
	}
	return 0;
}
