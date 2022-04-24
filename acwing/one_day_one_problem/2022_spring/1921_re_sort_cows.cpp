#include <bits/stdc++.h>
using namespace std;


const int N = 110;
// size��ʾÿ�����ϵ��������ֻ�и��ڵ��size��������
int fa[N],s[N];

// ��ʼ��n��Ԫ��
void init(int n)
{
    // ��ʼ��ʱÿ���ڵ�ָ��������ÿ�����ϵĴ�СΪ1
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
        s[i]=1;
    }
}

// ��ѯ���ĸ����ڲ�ѯx�Ĺ�����˳������·��ѹ��
int find(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);// ·��ѹ��
}

int n;
int a[N],b[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    // ����b�д��Ԫ��x����ŵ�λ��i�����ں�����������a���ҵ����򻷵ı�
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        b[x]=i;
    }

    // ���Ի����鼯
    init(n);

    // ��ʼ���кϲ����ϣ�Ҳ������Բ��
    for(int i=1;i<=n;++i){
        // b[x]��ֵ��ʾx������a�е�λ�ã�a[b[x]]��ֵ��ʾa��������Ҫ��x���н�����Ԫ��
        int x=a[i],y=a[b[x]];
        if(find(x)!=find(y)){
            // ��y���ڼ��Ϻϲ���x���ڼ�����
            s[find(x)]+=s[find(y)];
            // ��y���ڼ����и��ڵ��Ϊx���ڼ����еĸ��ڵ�
            fa[find(y)]=fa[find(x)];
        }
    }

    int cnt=0,mx=0;
    for(int i=1;i<=n;++i){
        // �ҵ������Ҽ��ϴ�С����1������м����͸�����󳤶�
        if(fa[i]==i&&s[i]>1){
            cnt++;
            mx=max(mx,s[i]);
        }
    }
    if(!cnt)mx=-1;
    cout<<cnt<<" "<<mx<<endl;
    return 0;
}