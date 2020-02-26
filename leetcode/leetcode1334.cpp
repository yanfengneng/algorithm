#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>
#include <iterator>
using namespace std; 

class Solution {
public:
    //���·���������⣬�������������ڸ�ϰͼ�㷨�������д
    //���1��floyd�㷨��ʱ�临�Ӷ�O(n^3)����άdp������Ϊ�˼򻯽���άdp��Ϊ��άdp���ˣ�����ɲο�����ս������ƾ�����
    int findTheCity_1(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //1����������ʼ��dp���飬��(i,j)֮����ڱߣ�dp[i][j]��Ϊ��ij��Ȩֵ������Ϊ0x3f3f3f3f
        int dp[n][n];
        memset(dp,0x3f,sizeof(dp));
        for(const auto& edge:edges){
            dp[edge[0]][edge[1]]=dp[edge[1]][edge[0]]=edge[2];
        }
        //2����ʼ����floyd�㷨��dp����
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        //3����������
        int res=0,minNum=INT_MAX;
        for(int i=0;i<n;++i){
            int count=0;
            //����i���ھӳ�����С�ڵ���distance�ĳ��и���
            for(int j=0;j<n;++j){
                if(i!=j&&dp[i][j]<=distanceThreshold){
                    count++;
                }
            }
            //����i���ھӳ��о���С��distance�ĳ��и������٣������Ϊ��С�ĳ��е���Ŀ��
            //����i��������ģ����������������Ҫ���£����Ǹ��¸����iΪres��
            if(count<=minNum){
                minNum=count;
                res=i;
            }
        }
        return res;
    }

    //���2��Bellman-Ford�㷨��ʱ�临�Ӷ�ΪO(V^2 * E)
    int findTheCity_2(int n,vector<vector<int>>& edges,int distanceThreshold){
        //1����ʼ��dist��dist��ʾ����k�����������ж�������·��
        int dist[n];
        memset(dist,0x3f,sizeof(dist));
        int t=edges.size();
        //2����������ͼΪ����ͼ
        for(int i=0;i<t;++i){
            edges.push_back({edges[i][1],edges[i][0],edges[i][2]});
        }
        //��ʾ���first��second��ʾС�ڵ�����ֵ����С���������͸ó��е���ʼ���
        pair<int,int> res(0x3f3f3f3f,n);
        //3��bellman-ford�㷨���k+1������������·��
        for(int k=0;k<n;++k){
            dist[k]=0;
            //�������·���ᾭ��ͬһ�������Σ��������·�����n-1���ߣ������Щʱ���������������ʼ��ͼ�Ƿ���ڸ�Ȧ
            for(int j=0;j<n-1;++j){
                for(int i=0;i<edges.size();++i){
                    int a=edges[i][0],b=edges[i][1],w=edges[i][2];
                    //���±�ab���յ�b�����·��ֵ
                    if(dist[a]!=0x3f3f3f3f&&dist[b]>dist[a]+w){
                        dist[b]=dist[a]+w;
                    }
                }
            }
            //ͳ�ƴӶ���k���������·��С����ֵ�ĳ��и���
            int count=0;
            for(int i=0;i<n;++i)if(dist[i]<=distanceThreshold)count++;
            //��С��С����������ʼ��ţ�����k���������ģ�������·����ͬʱ����ѡ�ñ������
            if(count<=res.first){
                res.first=count;
                res.second=k;
            }
            //����dist��������һ��������k+1������������·
            memset(dist,0x3f,sizeof(dist));
        }
        return res.second;
    }

    //���3��dijkstra�㷨��ʱ�临�Ӷ�O()����ֵ�������Сֵȡ��ʹ��С���ѣ����������͸��Ӷ�
    int findTheCity(int n,vector<vector<int>>& edges,int distanceThreshold){
        //1����ʼ��dist��visited���飬dist��ʾ��Դ��s��������������������·��visit��ʾ��Ƕ����Ƿ񱻼������·��
        int dist[n];
        memset(dist,0x3f,sizeof(dist));
        //2�������ڽӱ�
        map<int,set<pair<int,int>>> adjacent;
        for(const auto& edge:edges){
            int a=edge[0],b=edge[1],w=edge[2];
            adjacent[a].insert(make_pair(b,w));
            adjacent[b].insert(make_pair(a,w));
        }
        //res��firstΪ��С��������secondΪ���б��
        pair<int,int> res(0x3f3f3f3f,0);
        //3������dijkstra�㷨����Դ��s���������·��
        for(int s=0;s<n;++s){
            memset(dist,0x3f,sizeof(dist));
            dist[s]=0;
            //pair��first��ʾ���·����second��ʾԴ��s
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//С����
            q.push(make_pair(0,s));
            while(!q.empty()){
                pair<int,int> p=q.top();q.pop();
                int v=p.second;
                if(dist[v]<p.first)continue;//ȡ������Сֵ������̾��룬������ֵ
                for(const auto& edge:adjacent[v]){//��������v���ڽӵ㣬�������¶���v���ڽڵ����̾���
                    //���¶���v���ڽӵ����̾��룬����ӵ�q�У�firstΪ����v���ڽӵ㣬secondΪ��v first��Ȩֵ
                    if(dist[edge.first]>dist[v]+edge.second){
                        dist[edge.first]=dist[v]+edge.second;
                        q.push(make_pair(dist[edge.first],edge.first));
                    }
                }
            }
            //ͳ�ƴ�Դ��s����С�ڵ�����ֵ�ĳ�����
            int count=0;
            for(int i=0;i<n;++i)if(dist[i]<=distanceThreshold)count++;
            //���³������ͳ��б��
            if(count<=res.first){
                res.first=count;
                res.second=s;
            }
        }
        return res.second;
    }
};

int main()
{
    vector<vector<int>> edges={{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout<<Solution().findTheCity(4,edges,4)<<endl;
}