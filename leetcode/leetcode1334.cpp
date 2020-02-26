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
    //最短路径的练手题，哈哈，不错，刚在复习图算法，这就来写
    //题解1：floyd算法，时间复杂度O(n^3)，三维dp，不过为了简化将三维dp简化为二维dp罢了，具体可参考《挑战程序设计竞赛》
    int findTheCity_1(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //1、建立并初始化dp数组，若(i,j)之间存在边，dp[i][j]则为边ij的权值，否则为0x3f3f3f3f
        int dp[n][n];
        memset(dp,0x3f,sizeof(dp));
        for(const auto& edge:edges){
            dp[edge[0]][edge[1]]=dp[edge[1]][edge[0]]=edge[2];
        }
        //2、开始进行floyd算法求dp数组
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        //3、求解最后结果
        int res=0,minNum=INT_MAX;
        for(int i=0;i<n;++i){
            int count=0;
            //计算i的邻居城市中小于等于distance的城市个数
            for(int j=0;j<n;++j){
                if(i!=j&&dp[i][j]<=distanceThreshold){
                    count++;
                }
            }
            //城市i的邻居城市距离小于distance的城市个数更少，则更新为更小的城市的数目。
            //由于i是逐渐增大的，所以在满足题意得要求下，我们更新更大的i为res。
            if(count<=minNum){
                minNum=count;
                res=i;
            }
        }
        return res;
    }

    //题解2：Bellman-Ford算法，时间复杂度为O(V^2 * E)
    int findTheCity_2(int n,vector<vector<int>>& edges,int distanceThreshold){
        //1、初始化dist，dist表示顶点k到达其他所有顶点的最短路径
        int dist[n];
        memset(dist,0x3f,sizeof(dist));
        int t=edges.size();
        //2、补充有向图为无向图
        for(int i=0;i<t;++i){
            edges.push_back({edges[i][1],edges[i][0],edges[i][2]});
        }
        //表示结果first，second表示小于等于阈值的最小城市数，和该城市的起始编号
        pair<int,int> res(0x3f3f3f3f,n);
        //3、bellman-ford算法求第k+1个点出发的最短路径
        for(int k=0;k<n;++k){
            dist[k]=0;
            //由于最短路不会经过同一顶点两次，所以最短路最多有n-1条边，因此有些时候可以利用这个性质检查图是否存在负圈
            for(int j=0;j<n-1;++j){
                for(int i=0;i<edges.size();++i){
                    int a=edges[i][0],b=edges[i][1],w=edges[i][2];
                    //更新边ab，终点b的最短路径值
                    if(dist[a]!=0x3f3f3f3f&&dist[b]>dist[a]+w){
                        dist[b]=dist[a]+w;
                    }
                }
            }
            //统计从顶点k出发的最短路径小于阈值的城市个数
            int count=0;
            for(int i=0;i<n;++i)if(dist[i]<=distanceThreshold)count++;
            //更小最小城市数和起始编号，由于k是连续变大的，所以在路径相同时，会选用编号最大的
            if(count<=res.first){
                res.first=count;
                res.second=k;
            }
            //重置dist，进行下一次搜索从k+1顶点出发的最短路
            memset(dist,0x3f,sizeof(dist));
        }
        return res.second;
    }

    //题解3：dijkstra算法，时间复杂度O()，数值插入和最小值取出使用小根堆，这样来降低复杂度
    int findTheCity(int n,vector<vector<int>>& edges,int distanceThreshold){
        //1、初始化dist、visited数组，dist表示从源点s出发到达其他顶点的最短路，visit表示标记顶点是否被计算最短路的
        int dist[n];
        memset(dist,0x3f,sizeof(dist));
        //2、构建邻接表
        map<int,set<pair<int,int>>> adjacent;
        for(const auto& edge:edges){
            int a=edge[0],b=edge[1],w=edge[2];
            adjacent[a].insert(make_pair(b,w));
            adjacent[b].insert(make_pair(a,w));
        }
        //res的first为最小城市数，second为城市编号
        pair<int,int> res(0x3f3f3f3f,0);
        //3、进行dijkstra算法，求源点s出发的最短路径
        for(int s=0;s<n;++s){
            memset(dist,0x3f,sizeof(dist));
            dist[s]=0;
            //pair的first表示最短路径，second表示源点s
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//小根堆
            q.push(make_pair(0,s));
            while(!q.empty()){
                pair<int,int> p=q.top();q.pop();
                int v=p.second;
                if(dist[v]<p.first)continue;//取出的最小值不是最短距离，丢弃该值
                for(const auto& edge:adjacent[v]){//遍历顶点v的邻接点，进而更新顶点v的邻节点的最短距离
                    //更新顶点v的邻接点的最短距离，并添加到q中，first为顶点v的邻接点，second为边v first的权值
                    if(dist[edge.first]>dist[v]+edge.second){
                        dist[edge.first]=dist[v]+edge.second;
                        q.push(make_pair(dist[edge.first],edge.first));
                    }
                }
            }
            //统计从源点s出发小于等于阈值的城市数
            int count=0;
            for(int i=0;i<n;++i)if(dist[i]<=distanceThreshold)count++;
            //更新城市数和城市编号
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