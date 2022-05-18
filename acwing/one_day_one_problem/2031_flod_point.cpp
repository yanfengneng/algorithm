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
    // 开始枚举每个点，看是否能完全对齐
    for(int i=1;i<l*2;++i)
    {
        bool valid=true;
        // 从i点开始向左右两边进行扩展
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