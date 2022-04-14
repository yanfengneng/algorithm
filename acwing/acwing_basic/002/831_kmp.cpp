#include <iostream>
using namespace std;

const int N = 1e5+10,M = 1e6+10;

int n,m;
char p[N],s[M];
int ne[N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    // p和s都是从下标1开始存的
    cin>>n>>p+1>>m>>s+1;

    // 求next数组过程
    // next[1]=0表示第一个字母失败了，只能从0开始
    for(int i=2,j=0;i<=n;++i)
    {
        // 匹配不成功时，j指针后退
        while(j&&(p[i]!=p[j+1]))j=ne[j];
        // 匹配成功，j右移一位
        if(p[i]==p[j+1])j++;
        // ne[i]的最大前缀和后缀长度为j了，最差情况ne[i]还为0
        ne[i]=j;
    }

    // kmp 匹配过程
    // 最差情况就是p的第一个字符和s的所有字符都不匹配，那么j一直为0，i循环到m结束
    for(int i=1,j=0;i<=m;++i)
    {
        // j=0表示j指针回退到p的开头了
        // 当j=0时或者它两匹配成功时，循环结束
        while(j&&s[i]!=p[j+1])j=ne[j];

        // 如果它两匹配了，那么j指针右移一位
        if(s[i]==p[j+1])j++;

        if(j==n)
        {
            // 匹配成功之后，j还得回退，继续匹配相同的位置
            cout<<i-n<<" ";
            j=ne[j];
        }
    }
    return 0;
}