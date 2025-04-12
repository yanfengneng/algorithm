#include <bits/stdc++.h>
using namespace std;

// 进行堆排序
void down(vector<int>& a, int u) {
  int size = a.size();
  while (u * 2 < size) {
    // 左孩子的节点编号为 2*i+1, 右孩子的节点编号为 2*i+2
    int j = u * 2 + 1;
    // 寻找左右孩子节点中的较小值
    if (j + 1 < size and a[j] > a[j + 1]) j++;
    // 根节点已经是三个节点中的最小值了，不需要继续下沉了
    if (a[u] <= a[j]) break;
    swap(a[u], a[j]);
    u = j;
  }
}

// 递归版
void down_2(vector<int>& a, int u) {
  int t = u, size = a.size();
  // 寻找左右孩子节点中的最小值
  if (u * 2 + 1 < size and a[u * 2 + 1] < a[t]) t = u * 2 + 1;
  if (u * 2 + 2 < size and a[u * 2 + 2] < a[t]) t = u * 2 + 2;
  if (t != u) {  // 根节点不是最小值则进行下沉
    swap(a[t], a[u]);
    down_2(a, t);
  }
}

int main() {
  vector<int> a{5, 3, 2, 10, 13, 19, -1, 3, 6};
  // 从[n/2, 1] 开始下沉元素，时间复杂度为O(n)
  for (int i = a.size() / 2; i >= 0; i--) down(a, i);
  while (a.size()) {
    // cout << a[0] << " ";
    printf("%d ", a[0]);
    a[0] = a.back();
    a.pop_back();
    down_2(a, 0);
  }
  printf("\n");
  return 0;
}
