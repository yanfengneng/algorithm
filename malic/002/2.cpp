#include <iostream>
#include <string>
using namespace std;

// ��������
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    // ��һ�α�����������Ҫ������֣��ų�
    for(int i=0;i<n;++i)
        if(s[i]!='1'&&s[i]!='4')
        {
            printf("NO\n");
            return 0;
        }
    if(s[0]!='1')
    {
        printf("NO\n");
        return 0;
    }

    // ͳ��4��������������4�ĸ�������2�������NO������1����count����Ϊ0
    int count=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='4')
        {
            count++;
            if(count>2)
            {
                printf("NO\n");
                return 0;
            }
        }
        else count=0;
    }

    // �����ַ����ǺϷ���
    printf("YES");
    return 0;
}