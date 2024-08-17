#include <iostream>
using namespace std;

// 试除法判断质数
bool is_prime(int n)
{
    if(n<2)return false;
    // n的两个约数为i和n/i，我们规定小约数为i，大约数为n/i，小约数小于等于大约数，这样就可以把时间复杂度控制在O(sqrt(n))了
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