#include <bits/stdc++.h>
using namespace std;

// x��Ϊ2���ݣ���ֱ�ӷ���x-1��
int dfs(int x)
{
    if(x==0||x==1)return 0;
    int two=1;
    // ��� <=x ��2�������
    while(two*2<=x)two*=2;
    // two Ϊ 2 ���ݣ�����two-1���ɣ�ʣ�µļ����ݹ鼴��
    return two-1+dfs(x-two);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x;
        cin>>x;
        cout<<dfs(x)<<endl;
    }
    return 0;
}