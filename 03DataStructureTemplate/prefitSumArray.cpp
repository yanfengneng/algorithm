#include <bits/stdc++.h>
using namespace std;


// ǰ׺��+hashmap������·��ͳ���������ж��ٶ���ͬ�����֣�ʹ���Ȳ�ѯ�ٲ���ķ���
int solve1(vector<int> pre)
{
    unordered_map<int,int> cnt; 
    int res=0;
    // 0 0 1 1 0 0 2 3 5
    for(int x:pre){
        // ����˵��ѯ�����ĸ� 0 ʱ��֮ǰ������ 0 ���������ˣ���ʱ���ĸ� 0 ��ǰ������� 0 ������ͬ�����ԣ������ԡ�
        // ���Զ���������ͳ����ͬ���ֵĶ���ʱ��ʹ��hashmap�ľ�����·���Ȳ�ѯ�����
        res+=cnt[x]++;
    }
    return res;
}

int main()
{
    vector<int> pre={0,0,1,1,0,0,2,3,5};
    cout<<solve1(pre)<<endl;
    return 0;
}