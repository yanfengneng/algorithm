#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
const int N = 1e5+10;
PII q[N];

int n;
int st,ed;

int main()
{
    cin>>st>>ed;
    cin>>n;
    for(int i=0;i<n;++i)cin>>q[i].x>>q[i].y;
    // �Ȱ���˵���С�����������
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.x<b.x;
    });
    // ��ǰ����ö��ÿһ������
    int res=0;
    bool success = false;
    // �����[i,j]��ʹ�õ�˫ָ�룬���Խ�ʱ�临�Ӷȿ�����O(n)����Ϊÿ��Ѱ�����䶼��i��j����ͬʱ��[0,n-1]���ƶ��ģ�����ij���ظ������������Եĸ��Ӷ�
    for(int i=0;i<n;++i){
        int j=i,r=-2e9;
        // Ѱ���ܰ����߶���˵�����䣬��������Щ������ѡ��һ���Ҷ˵��������䣬����st����Ϊ�Ҷ˵����ֵ
        while(j<n&&q[j].x<=st){// ��ǰ�������˵�С�ڵ����߶ε���˵㣬��ʾ���԰����߶ε���˵�
            r=max(r,q[j].y);
            j++;
        }
        // û��Ѱ�Һ��ʵ���������߶���˵㣬��ʾ������������Ŀ��������������߶��ˣ�ֱ������ѭ������
        if(r<st){
            res=-1;
            break;
        }
        // ������+1
        res++;
        // ���а����߶ε����������ˣ�ֱ������ѭ��
        if(r>=ed){
            success=true;
            break;
        }
        // �����߶ε���ʼ�˵�Ϊ�������������Ҷ˵�
        st=r;
        // ����ʹ��j-1����Ϊ�������whileѭ����ʱ�� q[j].x>st �ˣ�����һ������q[j-1]�Ű���st������Ҫʹ��j-1��������֤�����޼��
        i=j-1;
    }
    if(!success)res=-1;
    cout<<res<<endl;
    return 0;
}