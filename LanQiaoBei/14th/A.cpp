#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;
int year, month, day, h, m, s;
vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> v;

/* �����˼·���ǳ���˼·����ʱ��ת��Ϊһ���������֣���λ���룩��������ʱ��ת���õ������ֽ��������Ȼ��ÿ��������֮����������Щ��ͳ�������������մ��� */
int main() 
{
    freopen("LanQiaoBei/14th/record.txt", "r", stdin);
    while (scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &h, &m, &s) == 6) 
    {
        printf("%d-%d-%d %d:%d:%d\n", year, month, day, h, m, s);
        assert(year == 2022);
        int sum = 0;
        for (int i = 1; i < month; ++i) {
            sum += days[i];
        }
        sum += day;
        sum = sum * 24 + h;
        sum = sum * 60 + m;
        sum = sum * 60 + s;
        v.push_back(sum);
    }
    assert(v.size() % 2 == 0);
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i += 2) {
        ans += v[i + 1] - v[i];
    }
    cout << ans << endl;
    // cout << 5101913 << endl;
    return 0;
}