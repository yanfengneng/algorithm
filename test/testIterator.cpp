#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vc{1,2,3,4,5,6,7};
    vector<int>::iterator beg=vc.begin();
    cout<<"beg指向的元素值为："<<*beg<<endl;
    advance(beg,2);
    cout<<"将beg右移两个单位后指向的元素值为："<<*beg<<endl;
    advance(beg,-1);
    cout<<"将beg左移一个单位后指向的元素值为："<<*beg<<endl;
    auto it=next(beg,2);
    cout<<*it<<endl;
    system("pause");
    return 0;
}