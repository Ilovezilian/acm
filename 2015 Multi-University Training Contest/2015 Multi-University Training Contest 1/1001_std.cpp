#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9+7;
#define ll long long
#define N 111111

ll l[N],r[N];//�洢������ӡ��ұ����ӵ�λ��
int n,m;
int pre[N],last[N];
int a[N];
int main(){
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        l[i]=1;
        r[i]=n;//��ʼ������ߵ����Ӻ����ұߵ����Ӷ��Ǳ���
        }
        memset(pre,0,sizeof(pre));
        memset(last,0,sizeof(last));
        for(int i=1;i<=n;i++){
            for(int j=a[i];j<=10000;j+=a[i])
                if(pre[j]!=0&&r[pre[j]]==n)//����Ѿ����ֲ������ұ���������ӻ�û���ҵ�
                r[pre[j]]=i-1;
            pre[a[i]]=i;
        }

        for(int i=n;i>0;i--){
            for(int j=a[i];j<=10000;j+=a[i])
                if(last[j]!=0&&l[last[j]]==1)//����Ѿ����ֲ����������������ӻ�û���ҵ�
                l[last[j]]=i+1;
            last[a[i]]=i;
        }
        /*
        for(int i=1;i<=n;i++){
            printf("%d %d %d\n",i,l[i],r[i]);
        }
        */
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans = (ans%mod+(ll)(i-l[i]+1)*(r[i]-i+1)%mod)%mod;
        }
        printf("%I64d\n",ans);
    }

}

