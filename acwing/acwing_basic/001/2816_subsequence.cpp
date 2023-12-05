#include <iostream>
using namespace std;

const int N = 1e5+10;
int a[N],b[N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=0;i<m;++i)scanf("%d",&b[i]);

    // 用指针i来扫描数组a，指针j来扫描数组b
    // 整个过程中j指针不断移动，而指针i只有元素匹配成功时，才移动一位
    int i=0;
    for(int j=0;j<m;++j)
    {
        if(i<n&&a[i]==b[j])i++;
    }
    if(i==n)printf("Yes\n");
    else printf("No\n");
    return 0;
}