#include <bits/stdc++.h>
using namespace std;

class MinHeap {
 private:
  vector<int> heap;

  // 获得父节点索引
  int parent(int i) { return (i - 1) / 2; }
  // 获得左孩子节点索引
  int left(int i) { return i * 2 + 1; }
  // 获得右孩子节点索引
  int right(int i) { return i * 2 + 2; }

  // 小元素上浮
  void up(int i) {
    while (i > 0 and heap[i] < heap[parent(i)]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);  // 继续上浮
    }
  }

  // 大元素下沉
  void down(int i) {
    int min_idx = i, size = heap.size();
    int l = left(i), r = right(i);
    // 寻找左右孩子节点中最小值的索引号
    if (l < size and heap[l] < heap[min_idx]) min_idx = l;
    if (r < size and heap[r] < heap[min_idx]) min_idx = r;
    if (min_idx != i) {  // 根节点不是最小值，则进行进行下沉
      swap(heap[min_idx], heap[i]);
      down(min_idx);  // 继续下沉
    }
  }

 public:
  void push(int x) {  // 在堆底添加元素并将该元素上浮到合适位置
    heap.push_back(x);
    up(heap.size() - 1);
  }

  void pop() {  // 删除堆顶元素
    if (heap.empty()) throw out_of_range("Heap is empty");
    // 删除堆顶元素：将堆顶元素与堆尾元素进行交换，然后将新堆底元素进行删除，将新堆顶元素进行下沉
    swap(heap[0], heap.back());
    heap.pop_back();
    if (!heap.empty()) down(0);
  }

  int top() {  // 获取堆顶元素
    if (heap.empty()) throw out_of_range("Heap is empty");
    return heap[0];
  }

  // 判断堆是否为空
  bool empty() { return heap.empty(); }

  // 获取堆大小
  size_t size() { return heap.size(); }
};
int main() {
  MinHeap heap;
  // 初始化随机数随机数种子
  srand(time(0));  // 用当前时间作为种子
  for (int i = 0; i < 10; i++) {
    int x = rand() % 100 + 1; // 范围 [1, 100]
    heap.push(x);
    cout << x << " ";
  }
  cout << endl;
  while(heap.size()) {
    cout << heap.top() << " ";
    heap.pop();
  }
  cout << endl;
  return 0;
}
