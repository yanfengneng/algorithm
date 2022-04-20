#include <bits/stdc++.h>
using namespace std;

int n,d;
const int N = 1e3+10;
const double eps = 1e-6, INF = 1e10;
#define x first
#define y second
using PDD = pair<double,double>;
PDD q[N];

// ˼·����С��ת��Ϊx���ϵ����䣬��ĿҪ������״����С��Ŀ��Ҳ����ת��Ϊ��������ѡ�����ٵĵ㣬ʹ��ÿ�����������ٰ���һ��ѡ���ĵ�
int main()
{
    cin>>n>>d;

    // ��ʾ�״��ܷ�̽�������е�С��
    bool success=true;
    for(int i=0;i<n;++i)
    {
        int x,y;cin>>x>>y;
        if(y>d)// �״�̽��ʧ�ܣ�ֱ������ѭ����
        {
            success=false;
            break;
        }
        // ���ù��ɶ�����ת��Ϊ��x���ϵ����䣬��(x,y)ΪԲ�ģ�dΪ�뾶��x�����������������
        auto len=sqrt(d*d-y*y);
        q[i]={x-len,x+len};
    }
    if(!success)puts("-1");
    else
    {
        // ���������䰴�Ҷ˵���С�����������
        sort(q,q+n,[](const auto& a,const auto& b){
            return a.y<b.y;
        });

        // ��ʼ��ǰ��������ö��ÿ������
        int res=0;
        double last=-INF;
        for(int i=0;i<n;++i)
        {
            // ��ǰ���䲻������һ�������е���˵㣬��ʾ���ҵ���һ�����䣬�����lastΪ��������Ҷ˵㼴��
            if(eps+last<q[i].x){
                res++;
                last=q[i].y;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}