#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> PII;

int n,m;
const int N=3e5+10;
// ����a��ʾ�������������s��ʾǰ׺��
int a[N],s[N];
// alls�����������ɢ����ֵ
vector<int> alls;
// all������¼x��c�ģ���ʾ��xλ���ϼ���c�¡�query��ʾ������ѯ��
vector<PII> add,query;

// ���֣��ҵ�>=x����Сλ��
int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    // ��xӳ�䵽1��2��3...n����Ϊǰ׺���Ǵ�1��ʼ��
    return r+1;
}
vector<int>::iterator unique(vector<int>& a)
{
    int j=0;
    // ������ͬ��Ԫ��ֱ�Ӹ���������ǰ��
    for(int i=0;i<a.size();++i)
        if(!i||a[i]!=a[i-1])
            a[j++]=a[i];
    return a.begin()+j;
}
// ��ɢ���ı��ʣ���ӳ�䣬������ܴ�ĵ㣬ӳ�䵽���ڵ�����Ԫ���У������ٶԿռ����������Ҳ���ټ�����
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int x,c;
        cin>>x>>c;
        // ��¼����λ��x�ϼ���c
        add.push_back({x,c});
        // ���±�x���뵽��ɢ����������ȥ
        alls.push_back(x);
    }

    for(int i=0;i<m;++i)
    {
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});

        // ������������ӵ���ɢ�������У�����Ժ�����ɢ�����������cû��Ӱ��
        // Ҳ����ǰ׺��û��Ӱ�죬��Ϊ��λ������Ӧ��ֵΪ0
        alls.push_back(l);
        alls.push_back(r);
    }

    // ��������ȥ��
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    // �������
    for(auto item:add)
    {
        // xΪ��ɢ��֮��������±꣬�ٸ��±���λ���ϼ���Ҫ�ӵ���c
        int x=find(item.first);
        a[x]+=item.second;
    }

    // Ԥ����ǰ׺��
    for(int i=1;i<=alls.size();++i)s[i]=s[i-1]+a[i];

    // ����ѯ��
    for(auto item:query)
    {
        // [l,r]Ϊ��ɢ�������������±�
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}