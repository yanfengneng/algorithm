#include <bits/stdc++.h>
using namespace std;

int n,m;
int dist[100010];
map<int,vector<pair<int,int>>> adjacent;

//dijstra���Ż���ʱ�临�Ӷ�O((V+E)*logV)����ֵ�������Сֵȡ��ʹ��С���ѣ����������͸��Ӷ�
//�Ż����dijkstra�������ֵ�Ĳ��루���£���ȡ����Сֵ�����Ż���
//ȡ����Сֵ��ʱ�临�Ӷ�ΪO(logV)����Ϊ������V������
//�ѵĲ���͸��µ���ʱ�临�Ӷ�ΪO(E)����Ϊ���ºͲ���ÿ���߶����������Ȼ����ӵ�������ֻ��V��Ԫ��
int dijstra2(int s){
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    //pair��first��ʾ���·����second��ʾԴ��s
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //С����
    q.push(make_pair(0, s));
    while(!q.empty()){
        //��Ϊ������V��Ԫ�أ�����ȡ����С��ʱ�临�Ӷ�ΪO(logV)
        pair<int,int> p=q.top();q.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;//ȡ������Сֵ������̾��룬������ֵ
        for (const auto &edge : adjacent[v]){//��������v���ڽӵ㣬�������¶���v���ڽڵ����̾���
            //���¶���v���ڽӵ����̾��룬����ӵ�q�У�firstΪ����v���ڽӵ㣬secondΪ��v first��Ȩֵ
            if (dist[edge.first] > dist[v] + edge.second){
                dist[edge.first] = dist[v] + edge.second;
                q.push(make_pair(dist[edge.first], edge.first));
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)return -1;
    return dist[n];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    while (m--){ //�����ڽӱ�
        int a, b, c;
        cin>>a>>b>>c;
        adjacent[a].push_back(make_pair(b, c));
    }
    cout << dijstra2(1) << endl;
    return 0;
}