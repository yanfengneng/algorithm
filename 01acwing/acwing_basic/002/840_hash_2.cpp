#include <iostream>
#include <cstring>
using namespace std;

// ���ŵ�ַ������0x3f3f3f3f����ʾ����hash���е���
const int N = 2e5+3,Max=0x3f3f3f3f;
int h[N];

int find(int x)
{
    int k=(x%N+N)%N;

    // Ѱ�Ҳ����λ��
    while(h[k]!=Max&&h[k]!=x)
    {
        ++k;
        if(k==N)k=0;
    }

    // kҪ��Ѱ�ҵ���λ�ã�Ҫô��Ӧ�ò���Ŀ�λ��
    return k;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(h,0x3f,sizeof h);
    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);

        // ���ҵ�x��λ��
        int k=find(x);

        // ���ǲ��룬��k�ǲ����λ��
        if(op[0]=='I')h[k]=x;
        // ���ǲ��ң���k�ǲ��ҵ�λ�ã�Ȼ���жϸ�λ�õ����Ƿ������ݷ�Χ��
        else
        {
            if(h[k]!=Max)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}