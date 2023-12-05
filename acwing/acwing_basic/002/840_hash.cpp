#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5+3;

// hash����������������ڽӱ�Ҳ���Ǻ��ڽӱ�һ����
// idx��ʾ��ǰ����ʹ�õĽڵ��ţ��������ʾ���ڽӱ�ĵ������У�ÿ���ڵ㶼��һ�������ı�ţ���idx��ʾ
int h[N],e[N],ne[N],idx=0;

void insert(int x)
{
    // ��c++�У���xΪ����ʱ��ȡ��Ľ��Ϊ���������Ϊ����ȡ��Ľ��Ϊ�������ͱ���ʹ������ȡ�෽ʽ
    // ֻҪ������Ϊ������ȡģ�Ľ����Ϊ����������c++�������涨��
    int k=(x%N+N)%N;
    
    // ͷ�巨���µĽڵ���Ϊidx��Ȼ���½ڵ��nextָ��ָ��ͷ�ڵ�ָ���λ�ã��ڵ��ţ���Ȼ����ͷ�ڵ�ָ���µĽڵ���
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

bool find(int x)
{
    int k=(x%N+N)%N;
    // -1��ʾ�սڵ���
    for(int i=h[k];i!=-1;i=ne[i])
        if(e[i]==x)return true;
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(h,-1,sizeof h);
    while(n--)
    {
        char op[2];
        int x;
        // %s�ַ�����ʽ���Կո����Ϊ���������־�ģ�������ʹ��%c������%c����ո����
        scanf("%s%d",op,&x);

        if(op[0]=='I')insert(x);
        else
        {
            if(find(x))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}