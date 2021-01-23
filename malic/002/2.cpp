#include <iostream>
#include <string>
using namespace std;

// 滑动窗口
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    // 第一次遍历：将不和要求的数字，排除
    for(int i=0;i<n;++i)
        if(s[i]!='1'&&s[i]!='4')
        {
            printf("NO\n");
            return 0;
        }
    if(s[0]!='1')
    {
        printf("NO\n");
        return 0;
    }

    // 统计4个个数，若连续4的个数超过2，则输出NO；遇到1，则将count重置为0
    int count=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='4')
        {
            count++;
            if(count>2)
            {
                printf("NO\n");
                return 0;
            }
        }
        else count=0;
    }

    // 整个字符串是合法的
    printf("YES");
    return 0;
}