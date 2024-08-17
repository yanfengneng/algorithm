#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;
int year, month, day, h, m, s;
vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> v;

/* 这里的思路就是常见思路：将时间转换为一个具体数字（单位：秒），将所有时间转换得到的数字进行排序后，然后每两个数字之间计算差，最后将这些差统计起来就是最终答案了 */
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