#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> smallHeap;
    priority_queue<int,vector<int>,less<int>> bigHeap;
    priority_queue<int>heap;
    for(int i=0;i<10;i++)
    {
        bigHeap.push(i);
        smallHeap.push(i);
        heap.push(i);
    }
    return 0;
}