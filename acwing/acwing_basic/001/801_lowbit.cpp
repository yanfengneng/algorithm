#include <iostream>

using namespace std;

int n;

// 取出最低位的1
int lowbit(int x)
{
    // -x就是x的补码，二者相与就是本来x的最低位是1的位不变，其余所有位都为0了
    return x&-x;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        int res = 0;
        // 减去最低位的x，直到x被减为0
        while(x)x-=lowbit(x),res++;
        cout<<res<<" ";
    }
    cout<<endl;
    return 0;
}