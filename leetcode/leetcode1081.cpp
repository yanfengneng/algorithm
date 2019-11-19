#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string text) {
        //ÿ��λ����26��int��ʾ�����������ĸ��λ��
        vector<vector<int>> next(text.size(), vector<int>(26, 0));
        //ÿ��λ�ñ�ʾ��������Щ�ַ�
        vector<int> bit(text.size(), 0);
        //total��ʾ������Ҫ�������ĸ
        int total = 0;
        //ret��ʾ���չ�����ַ���
        string ret = "";
        
        //Ԥ����ʼ 
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
        
        //res��ʾ��ǰ��λ��
        int res = 0;
        //̰�Ŀ�ʼ
        while (1) {
            //�ж���һ����ĸӦ����ʲô
            int a = -1;
            for (int i = 0;i < 26;i++) {
                if (total & (1 << i)) {
                    //�ж��Ƿ�����'a' + i
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