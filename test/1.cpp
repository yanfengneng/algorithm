#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a='a',B='B';
    // С��Сд�������Ѷ����������5λ����0��1 �� ��1��0
    cout<<char(a^32)<<"---"<<char(B^32)<<endl;
    // ��ĸת��ΪСд���Ѷ��������ĵ�5λ��Ϊ1
    cout<<char(a|32)<<"---"<<char(B|32)<<endl;
    // ��ĸת��Ϊ��д���Ѷ��������ĵ�5λ��Ϊ0
    cout<<char(a&-33)<<"---"<<char(B&-33)<<endl;
    return 0;
}