#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r) {
  // 区间内只有一个数或者没有数时，不用划分了
  if (l >= r) return;

  // c++中+的优先级大于>>。因此先进行相加在进行右移一位
  // x作为分界点，x有四种取法，l，r，mid，随机
  // 由于指针i、j交换完一次后都要往中间移动一个位置
  int i = l - 1, j = r + 1, x = q[l + r >> 1];
  while (i < j) {
    // do while
    // 语句先执行do里面的语句，再判断while条件，因此前面要将i和j都移动一个偏移量
    // i找到大于等于x的，j找到小于等于x的，然后二者swap
    do {
      ++i;
    } while (q[i] < x);
    do {
      --j;
    } while (q[j] > x);
    /*
    不想写 do while 可以写下面两句
    while(q[++i]<x);
    while(q[--j]>x);
    */
    if (i < j) swap(q[i], q[j]);
  }
  // 递归地处理左右两段
  quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &q[i]);

  quick_sort(q, 0, n - 1);

  for (int i = 0; i < n; ++i) printf("%d ", q[i]);

  return 0;
}
