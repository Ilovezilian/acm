#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 200002;
//��ʾһ·�����������͵�����£��Զ��ټ۸������˶�����
struct DAT{
	int cnt;
	int val;
}Q[N];
int n, C, buy[N], sell[N], a[N], total, l, r;
ll ans;

//������С�ڵ���v�۸�������ͻ�����v�۸�����
//��Ϊ���������Ҫ�˵��ģ�ֻ����������˵�ʱ����ԭ����ԭ�������v�ļ۸���������
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

//�����д��ڵ���v�۸�������ͻ�����v�۸�����
//Q����Ͷ��Ƕ�����ͣ���ǰ����Ҳû��
void Min(int v){
	while(l <= r && Q[r].val > v){
		ans -= 1ll * Q[r].val * Q[r].cnt;
		total += Q[r].cnt;
		r --;
	}
}

//�ƶ����ģ��ѵ�ǰ������˵ļ۸��������ɾ��
//��Ϊ�Ѿ����͵�����£��˹���͸�����
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
			//��������ж�������������ȿ�����
			Max(sell[i]);
			//ÿ������Ҫ������ͣ�ʹ���䲹��
			total = (i == 0 ? C : (a[i] - a[i-1]));
			//֮ǰ����˵��ͣ�����������
			Min(buy[i]);
			//����total����
			r ++;
			Q[r].val = buy[i];
			Q[r].cnt = total;
			ans += 1ll * buy[i] * total;
			//��ȥ·���ж�������
			Del(a[i+1] - a[i]);
		}
		Max(sell[n]);
		//��󻹶�������ͣ�������Ļ�������������������ԭ��
		for(i = l; i <= r; i ++)
			ans -= 1ll * Q[i].val * Q[i].cnt;
		printf("%I64d\n",ans);
	}
	return 0;
}
