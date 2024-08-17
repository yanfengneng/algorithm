#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
using PII = pair<int,int>;
const int N = 1e5+10;
PII q[N];

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)cin>>q[i].x>>q[i].y;

    // ����˵���С�����������
    sort(q,q+n,[](const auto& a,const auto& b){
        return a.x<b.x;
    });

    // ����С���ѣ�������ÿ��������������Ҷ˵����Сֵ
    priority_queue<int,vector<int>,greater<int>> heap;

    // �����ǰ���˵���С�������ö�ٵģ�������˵��ϸ񲻴��ڽ���������ÿ�ξͽ����ж϶����Ҷ˵���Сֵ�뵱ǰ�������˵��С����
    for(int i=0;i<n;++i)
    {
        // ����Ϊ�ջ��߶����Ҷ˵����Сֵ���ڵ��ڵ�ǰ�������˵㣬��ʾ��ǰ���������з�����ڽ���������Ҫ����һ�����飬���ѵ�ǰ������Ҷ˵���ӽ�ȥ
        if(heap.empty()||heap.top()>=q[i].x)heap.push(q[i].y);
        // �����ʾ��ǰ���������ӵ��Ҷ˵���Сֵ�ķ����У����Ҷ˵���Сֵ����ɾ��������ӵ�ǰ������Ҷ˵�
        else{
            int t=heap.top();heap.pop();
            heap.push(q[i].y);
        }
    }
    cout<<heap.size()<<endl;
    return 0;
}