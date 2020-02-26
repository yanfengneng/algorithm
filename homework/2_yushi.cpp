#include<iostream>
using namespace std;

int main() {
	int n, * prisoner;
	cin >> n;
	prisoner = new int[n + 1];
	for (int i = 0; i <= n; i++)
		prisoner[i] = 1;
	for (int i = 1; i <= n; i++)    //i--->��ʾ�����ǵڼ����߹�
		for (int j = i; j <= n; j = j + i)          //j--->��Ҫ�ı�����ı��  
			prisoner[j] = 1 - prisoner[j];
	for (int i = 1; i <= n; i++)
		if (prisoner[i] == 0)
			cout << i << " ";
    system("pause");
	return 0;
}