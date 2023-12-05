#include <iostream>
using namespace std;

// �Գ����ж�����
bool is_prime(int n)
{
    if(n<2)return false;
    // n������Լ��Ϊi��n/i�����ǹ涨СԼ��Ϊi����Լ��Ϊn/i��СԼ��С�ڵ��ڴ�Լ���������Ϳ��԰�ʱ�临�Ӷȿ�����O(sqrt(n))��
    for(int i=2;i<=n/i;++i)
        if(n%i==0)return false;

    return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(is_prime(x))puts("Yes");
        else puts("No");
    }
    return 0;
}