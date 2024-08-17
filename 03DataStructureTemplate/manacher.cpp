#include <vector>
#include <iostream>
#include <string>

using namespace std;

string Mannacher(string s)
{
    //����"#"
    string t="$#";
    for(int i=0;i<s.size();++i)
    {
        t+=s[i];
        t+="#";
    }

   
    vector<int> p(t.size(),0);

    //mx��ʾĳ�����Ĵ����������Ҷ˰뾶�����꣬id��ʾ��������Ӵ����м�λ������
    //resLen��ʾ��Ӧ��s�е�����ӻ��Ĵ��İ뾶��resCenter��ʾ����ӻ��Ĵ����м�λ��
    int mx=0,id=0,resLen=0,resCenter=0;

     //����p����
    for(int i=1;i<t.size();++i)
    {
        p[i]=mx>i?min(p[2*id-i],mx-i):1;

        //��������������������Ҫ����������չ��
        while(t[i+p[i]]==t[i-p[i]])++p[i];

        //�뾶����i+p[i]�����߽�mx����Ҫ����
        if(mx<i+p[i]){
            mx=i+p[i];
            id=i;
        }

        //�����������Ӵ�����Ϣ
        if(resLen<p[i]){
            resLen=p[i];
            resCenter=i;
        }
    }

    //������Ӵ�����Ϊ�뾶-1����ʼλ��Ϊ�м�λ�ü�ȥ�뾶�ٳ���2
    return s.substr((resCenter-resLen)/2,resLen-1);
}

int main()
{
    cout<<Mannacher("12212")<<endl;
    cout<<Mannacher("122122")<<endl;
    cout<<Mannacher("noon")<<endl;
    system("pause");
}