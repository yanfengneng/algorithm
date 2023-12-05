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

        // ����>=x����Сֵλ��
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=l+r>>1;
            // ÿ�ζ�Ҫѡ������ڵ�����
            if(q[mid]>=x)r=mid;// ���������䣬����ƽ���mid�п��ܾ��Ǵ�
            else l=mid+1;// ���������䣬���ұƽ���mid���Ǵ𰸣���ȻҪmid+1
        }
        if(q[l]!=x)cout<<"-1 -1"<<endl;
        else{
            cout<<l<<" ";
            // Ѱ��<=x�����ֵ
            int l=0,r=n-1;
            while(l<r)
            {
                // ����ȡ������left��right���1ʱ����left����ȡ��right����������ѭ��
                int mid=l+r+1>>1;
                if(q[mid]<=x)l=mid;// ���������䣬���ұƽ���mid����Ϊ��
                else r=mid-1;// ���������䣬����ƽ���mid��Ϊ�𰸣�����Ҫmid-1
            }
            cout<<l<<endl;
        }
    }
    return 0;
}