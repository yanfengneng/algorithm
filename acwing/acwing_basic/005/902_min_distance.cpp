#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n,m;
char a[N],b[N];
// f[i][j]表示所有将a[1~i]变成b[1~j]的操作方式的操作次数的最小值
int f[N][N];

int main()
{
    scanf("%d%s",&n,a+1);
    scanf("%d%s",&m,b+1);

    // f[0][j]表示用a的前0个字母匹配b的前j个字母，需要在a中进行添加字符操作，添加次数与b的长度相等
    for(int j=0;j<=m;++j)f[0][j]=j;
    // f[i][0]表示用a的前i个字母匹配b的前0个字母，需要在a中进行删除字符操作，删除次数与a的长度相等
    for(int i=0;i<=n;++i)f[i][0]=i;

    // 开始进行状态转移
    // 由于i j都是从小到大进行枚举的，所以枚举到f[i][j]时，前面的f[i-1][j-1] f[i-1][j] f[i][j-1]都被计算过了，是最小值，可以直接拿来用
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            // 三种转移状态：删除、添加、修改
            // 在a中删除一个a[i]：再删除a[i]之前需要a[1~i-1]与b[1~j]相匹配，所以转移状态为f[i-1][j]+1
            // 在a中添加一个b[j]：再添加b[j]之前需要a[1~i]与b[1~j-1]相匹配，所以转移状态为f[i][j-1]+1
            // 修改：之前的a[1~i-1]与b[1~j-1]已经相匹配上了，现在就需要看a[i]用不用修改为b[j]了；若本身a[i]==b[j]就不需要进行修改；本身a[i]!=b[j]，那么需要修改一次。所以转移状态为f[i-1][j-1]+1/0
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
            if(a[i]==b[j])f[i][j]=min(f[i][j],f[i-1][j-1]);
            else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
        }
    cout<<f[n][m]<<endl;
    return 0;
}