#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+10;
bool flag[N];
int n,l;

int main()
{
    cin>>n>>l;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        flag[2*x]=true;
    }
    int res=0;
    // ��ʼö��ÿ���㣬���Ƿ�����ȫ����
    for(int i=1;i<l*2;++i)
    {
        bool valid=true;
        // ��i�㿪ʼ���������߽�����չ
        for(int step=1;i-step>=0&&i+step<=l*2;step++)
            if(flag[i-step]!=flag[i+step])
            {
                valid=false;
                break;
            }
        if(valid)res++;
    }
    cout<<res<<endl;
    return 0;
}