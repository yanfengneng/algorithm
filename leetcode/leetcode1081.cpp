#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string text) {
        //每个位置有26个int表示后面最近的字母的位置
        vector<vector<int>> next(text.size(), vector<int>(26, 0));
        //每个位置表示后面有哪些字符
        vector<int> bit(text.size(), 0);
        //total表示我们需要构造的字母
        int total = 0;
        //ret表示最终构造的字符串
        string ret = "";
        
        //预处理开始 
        int n = text.size();
        bit[n - 1] = (1 << (text[n - 1] - 'a'));
        next[n - 1][text[n - 1] - 'a'] = n - 1;
        for (int i = n - 2;i >= 0;i--) {
            bit[i] = bit[i + 1] | (1 << (text[i] - 'a'));
            for (int j = 0;j < 26;j++) {
                next[i][j] = next[i + 1][j];
            }
            next[i][text[i] - 'a'] = i;
        }
        total = bit[0];
        
        //res表示当前的位置
        int res = 0;
        //贪心开始
        while (1) {
            //判断下一个字母应该填什么
            int a = -1;
            for (int i = 0;i < 26;i++) {
                if (total & (1 << i)) {
                    //判断是否能填'a' + i
                    int pos = next[res][i];
                    if ((bit[pos] & total) == total) {
                        a = i;
                        break;
                    }
                }
            }
            if (a == -1) {
                break;
            }
            ret.push_back(a + 'a');
            total -= 1 << a;
            res = next[res][a];
        }
        return ret;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string text = stringToString(line);
        
        string ret = Solution().smallestSubsequence(text);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}