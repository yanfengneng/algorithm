#include <iostream>

using namespace std;

const int N=1e5+10;
// count ����ͳ��ÿ�����ֳ��ֵ�Ƶ��
int a[N],count[N];
int n;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];

    int res=0;
    for(int right=0,left=0;right<n;++right)
    {
        count[a[right]]++;
        // �����ڳ����ظ����֣�����left��ʼ����
        // ����Ҫ�������������У����ڱ��������ƶ�
        while(count[a[right]]>1)
        {
            count[a[left]]--;
            left++;
        }
        res=max(res,right-left+1);
    }
    cout<<res<<endl;
    return 0;
}