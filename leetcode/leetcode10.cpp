#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return regex_match(s,regex(p));
    }
};