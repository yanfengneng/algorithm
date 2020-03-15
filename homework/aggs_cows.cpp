#include <iostream>
#include <algorithm>
using namespace std;

int n,c;
int a[100000];

bool check(int mid){
    int pre=0,count=1;//pre表示上一头牛放的位置，count用来计数
    for(int i=1;i<n;++i){
        if(a[i]-a[pre]>=mid){
            pre=i;
            count++;
        }
    }
    if(count>=c)return true;
    return false;
}

int main()
{
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int left=0,right=1000000000;
    while(left<right){//二分法：求小于等于x的最大值
        //mid为最近两头牛的距离，我们要使d的值最大，用二分搜索，使其满足a[i]-a[pre]>=mid
        int mid=left+((right-left+1)>>1);//取右中位数，避免死循环
        if(check(mid))left=mid;
        else right=mid-1;
    }
    printf("%d\n",left);
}
/*
5 3
1
2
8
4
9
*/