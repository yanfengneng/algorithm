#include <iostream>
using namespace std;

const int N=1e5+10;

int n,m;
int q[N];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i)scanf("%d",&q[i]);
    while(m--)
    {
        int x;
        cin>>x;

        // 查找>=x的最小值位置
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=l+r>>1;
            // 每次都要选择答案所在的区间
            if(q[mid]>=x)r=mid;// 答案在左区间，向左逼近。mid有可能就是答案
            else l=mid+1;// 答案在右区间，向右逼近，mid不是答案，必然要mid+1
        }
        if(q[l]!=x)cout<<"-1 -1"<<endl;
        else{
            cout<<l<<" ";
            // 寻找<=x的最大值
            int l=0,r=n-1;
            while(l<r)
            {
                // 向上取整，当left与right相差1时，让left可以取到right，来避免死循环
                int mid=l+r+1>>1;
                if(q[mid]<=x)l=mid;// 答案在右区间，向右逼近，mid可能为答案
                else r=mid-1;// 答案在左区间，向左逼近，mid不为答案，所以要mid-1
            }
            cout<<l<<endl;
        }
    }
    return 0;
}