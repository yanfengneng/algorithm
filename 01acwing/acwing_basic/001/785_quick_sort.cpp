#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r) {
  // ������ֻ��һ��������û����ʱ�����û�����
  if (l >= r) return;

  // c++��+�����ȼ�����>>������Ƚ�������ڽ�������һλ
  // x��Ϊ�ֽ�㣬x������ȡ����l��r��mid�����
  // ����ָ��i��j������һ�κ�Ҫ���м��ƶ�һ��λ��
  int i = l - 1, j = r + 1, x = q[l + r >> 1];
  while (i < j) {
    // do while
    // �����ִ��do�������䣬���ж�while���������ǰ��Ҫ��i��j���ƶ�һ��ƫ����
    // i�ҵ����ڵ���x�ģ�j�ҵ�С�ڵ���x�ģ�Ȼ�����swap
    do {
      ++i;
    } while (q[i] < x);
    do {
      --j;
    } while (q[j] > x);
    /*
    ����д do while ����д��������
    while(q[++i]<x);
    while(q[--j]>x);
    */
    if (i < j) swap(q[i], q[j]);
  }
  // �ݹ�ش�����������
  quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &q[i]);

  quick_sort(q, 0, n - 1);

  for (int i = 0; i < n; ++i) printf("%d ", q[i]);

  return 0;
}
