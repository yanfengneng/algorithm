#include <iostream>
using namespace std;

// ѧһ��malic��˼·�ɣ�����������̰�ĺϲ��������ģ�����ʦ�õ������¼һ�³��ֵ����֣�����ڱ������������

int cnt[400];
int n;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;++i)cnt[i]=1;
    }

    int res=0;
    for(int i=1;i<=366;++i)
        if(cnt[i])res++;
    printf("%d\n",res);
    return 0;
}