#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vc{1,2,3,4,5,6,7};
    vector<int>::iterator beg=vc.begin();
    cout<<"begָ���Ԫ��ֵΪ��"<<*beg<<endl;
    advance(beg,2);
    cout<<"��beg����������λ��ָ���Ԫ��ֵΪ��"<<*beg<<endl;
    advance(beg,-1);
    cout<<"��beg����һ����λ��ָ���Ԫ��ֵΪ��"<<*beg<<endl;
    auto it=next(beg,2);
    cout<<*it<<endl;
    system("pause");
    return 0;
}