#include <iostream>

using namespace std;

int n;

// ȡ�����λ��1
int lowbit(int x)
{
    // -x����x�Ĳ��룬����������Ǳ���x�����λ��1��λ���䣬��������λ��Ϊ0��
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
        // ��ȥ���λ��x��ֱ��x����Ϊ0
        while(x)x-=lowbit(x),res++;
        cout<<res<<" ";
    }
    cout<<endl;
    return 0;
}