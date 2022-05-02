#include <bits/stdc++.h>
using namespace std;

const int N = 15,M = 1010;
int f[N][N];
char str[M][N];
int n,m;

int edit_distance(char* a,char *b)
{
    // 计算字符串a b从下标1开始的长度
    int la=strlen(a+1),lb=strlen(b+1);
    // 初始化f[i][0]，表示想把a的前i个字符与b的前0个字符相匹配，只能用删除操作了，删除次数与a的长度相等
    for(int i=0;i<=la;++i)f[i][0]=i;
    // 初始化f[0][j]，表示想把a的前0个字符与b的前j个字符相匹配，只能用添加操作了，添加次数与b的长度相等
    for(int j=0;j<=lb;++j)f[0][j]=j;
    // 开始进行状态转移
    for(int i=1;i<=la;++i)
        for(int j=1;j<=lb;++j)
        {
            // 删除a[i]、添加b[j]
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
            // 修改a[i]为b[j]与否，不相等就修改一次，相等就不需要修改
            f[i][j]=min(f[i][j],f[i-1][j-1]+(a[i]!=b[j]));
        }
    return f[la][lb];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%s",str[i]+1);// 从下标1开始输入

    while(m--)
    {
        char s[N];int limit;
        scanf("%s%d",s+1,&limit);
        int cnt=0;
        // 计算当前输入的字符串与n个字符串的编辑距离小于等于limit的字符串个数
        for(int i=0;i<n;++i)
            if(edit_distance(str[i],s)<=limit)cnt++;
        cout<<cnt<<endl;
    }

    return 0;
}