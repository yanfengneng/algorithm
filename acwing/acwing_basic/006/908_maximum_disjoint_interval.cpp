#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
const int N = 1e5+10;
using PII = pair<int,int>;
PII q[N];
int n;

/*������905����ѡ�����һ��һ�����������£�
    ����ѡ�����ǽ����仮��Ϊ��ͬ�ļ��ϣ�ÿ�������и������䶼������һ�����ཻ����ѡ���������ཻ�����䣬��ô��������ض��ڲ�ͬ�ļ����У�
    ������ཻ���������Ǽ���������Ҳ��������ѡ����������������������ͬ
*/
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>q[i].x>>q[i].y;

    // ���Ҷ˵���С�����������
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.y<b.y;
    });

    int res=1,last=q[0].y;
    for(int i=1;i<n;++i){
        // ��һ��������Ҷ˵�û�б������ڵ�ǰ�����ڣ������lastΪ��ǰ������Ҷ˵㣬������+1
        if(last<q[i].x){
            res++;
            last=q[i].y;
        }
    }
    cout<<res<<endl;
    return 0;
}