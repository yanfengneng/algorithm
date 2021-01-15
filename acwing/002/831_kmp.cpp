#include <iostream>
using namespace std;

const int N = 1e5+10,M = 1e6+10;

int n,m;
char p[N],s[M];
int ne[N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    // p��s���Ǵ��±�1��ʼ���
    cin>>n>>p+1>>m>>s+1;

    // ��next�������
    // next[1]=0��ʾ��һ����ĸʧ���ˣ�ֻ�ܴ�0��ʼ
    for(int i=2,j=0;i<=n;++i)
    {
        // ƥ�䲻�ɹ�ʱ��jָ�����
        while(j&&(p[i]!=p[j+1]))j=ne[j];
        // ƥ��ɹ���j����һλ
        if(p[i]==p[j+1])j++;
        // ne[i]�����ǰ׺�ͺ�׺����Ϊj�ˣ�������ne[i]��Ϊ0
        ne[i]=j;
    }

    // kmp ƥ�����
    // ����������p�ĵ�һ���ַ���s�������ַ�����ƥ�䣬��ôjһֱΪ0��iѭ����m����
    for(int i=1,j=0;i<=m;++i)
    {
        // j=0��ʾjָ����˵�p�Ŀ�ͷ��
        // ��j=0ʱ��������ƥ��ɹ�ʱ��ѭ������
        while(j&&s[i]!=p[j+1])j=ne[j];

        // �������ƥ���ˣ���ôjָ������һλ
        if(s[i]==p[j+1])j++;

        if(j==n)
        {
            // ƥ��ɹ�֮��j���û��ˣ�����ƥ����ͬ��λ��
            cout<<i-n<<" ";
            j=ne[j];
        }
    }
    return 0;
}