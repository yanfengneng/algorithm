#include <iostream>
#include <vector>

using namespace std;

class UF
{
private:
    //count��¼��ͨ������������parent������ʾ���׽ڵ㣬������˫�ױ�ʾ����rank������ʾ���ĸ߶ȡ�
    int count;
    vector<int> parent,rank;
public:
    UF(int n)
    {
        this->count=n;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;++i)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    // ��ѯ���ĸ�
    int find(int x)
    {
        if(parent[x]==x)return x;
        // �ݹ��ѯx�ĸ���˳�����·��ѹ��
        else parent[x]=find(parent[x]);
    }

    // �ϲ� x �� y �����ļ���
    void unite(int x,int y)
    {
        x=find(x);
        y=find(y);
        // x y ����ͬ������Ҫ�ϲ�
        if(x==y)return;

        // rankС����rank�������
        if(rank[x]<rank[y])parent[x]=y;// x�ĸ��ڵ�����y
        else{
            parent[y]=x;
            // x y �߶���ͬ����������֮�����ĸ߶�+1
            if(rank[x]==rank[y])rank[x]++;
        }
        // ��ͨ����-1
        count--;
    }


    // �ж� x �� y �Ƿ��໥��ͨ
    bool connected(int x,int y)
    {
        return find(x)==find(y);
    }

    // �����ͨ������
    int size()
    {
        return this->count;
    }
};

int main()
{
    UF uf(10);
    cout<<uf.size()<<endl;
    uf.unite(1,2);
    cout<<uf.size()<<endl;
    return 0;
}