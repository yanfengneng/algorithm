#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> wins, match;
    for (char c : t) match[c]++;
    // valid记录wins中的有效字符个数是否包含了match
    int vaild = 0;
    int start = 0, len = INT_MAX;
    for (int l = 0, r = 0, n = s.size(); r < n; r++) {
      wins[s[r]]++;
      // s中子串的字符s[r]涵盖了t中的字符s[r]的个数
      if (match.count(s[r]) && wins[s[r]] == match[s[r]]) vaild++;
      // 若wins内的有效字符已经包括match了，那么就收缩窗口，更新最优解
      while (vaild == match.size()) {
        // 更新长度更小的子串
        if (r - l + 1 < len) {
          start = l, len = r - l + 1;
        }
        // 移出窗口中的左边界时，需要更新窗口中的有效字符的个数
        if (match.count(s[l]) && match[s[l]] == wins[s[l]]) vaild--;
        // 窗口左边界进行收缩
        wins[s[l++]]--;
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};

int main() {
  string s = "ADOBECODEBANC", t = "ABC";
  cout << Solution().minWindow(s, t) << endl;
  return 0;
}