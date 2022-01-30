#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;
const int N = 2510;
PII cows[N];

int n,m;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>cows[i].first>>cows[i].second;
    map<int,int> spfs;
    for(int i=0;i<m;++i){
        int spf,cover;
        cin>>spf>>cover;
        spfs[spf]+=cover;
    }
    sort(cows,cows+n);
    int res=0;
    // Ϊ�˷�����ƽ�������������Сֵ�����Ǽ��������ڱ�
    spfs[0]=spfs[1001]=n;
    for(int i=n-1;i>=0;i--){
        auto cow=cows[i];
        // upper֮���ټ�1���ҵ�С�ڵ���maxSPF���������
        auto spf=spfs.upper_bound(cow.second);
        spf--;
        if(spf->first>=cow.first&&spf->first<=cow.second){
            res++;
            if(--spf->second==0)spfs.erase(spf);
        }

    }
    cout<<res<<endl;
    return 0;
}