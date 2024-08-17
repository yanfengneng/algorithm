#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> PII;

int n;
vector<PII> segs;

void merge(vector<PII>& segs)
{
    vector<PII> res;
    // ��������Ҳû�����⣬Ҳ�����ҵ����ظ���������
    // pair�������ǣ�����˵㲻ͬ������˵���С������������˵���ͬ�����Ҷ˵���С��������
    sort(segs.begin(),segs.end());

    int st=-2e9,ed=-2e9;
    // ��ǰ֮��ɨ�����е�����
    for(auto seg:segs)
    {
        // ά��������Ҷ˵�С�ڱ��������˵㣬��ʾ�ҵ�һ���µ�����
        if(ed<seg.first)
        {
            if(st!=-2e9)res.push_back({st,ed});
            st=seg.first,ed=seg.second;
        }
        // ά������ͱ��������н����ģ�������Ҷ˵㣬���ϲ�����
        else
        {
            ed=max(ed,seg.second);
        }
    }

    // ҲҪ������������ӵ�������ȥ
    // �����if�ж��Ƿ�ֹ���������һ���յ�����
    if(st!=-2e9)res.push_back({st,ed});

    // ����segs
    segs=res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    // �ϲ�����
    merge(segs);

    cout<<segs.size()<<endl;

    return 0;
}