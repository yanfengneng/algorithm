#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int dis, k, oil;
	dis = 500; k = 1; oil = 500;
	while (dis < 1000)
	{
        printf("%d %d %d\n", k, oil, 1000 - dis);
		k = k + 1;
		dis = dis + 500 / (2 * k + 1);
		oil = 500 * k;
	}
	oil = 500 * (k - 1) + (1000 - dis) * (2 * k - 1);
	printf("%d %d %d\n", k, oil, dis);
    system("pause");
	return 0; 
}
