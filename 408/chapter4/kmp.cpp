#include <iostream>
#include <string>
#include <vector>
using namespace std;

class KMP
{
public:
    //txt为文本串，pat为模式串，pat用来匹配txt的
    int search(const string &txt, const string &pat)
    {
        if (pat.empty())
            return 0;
        int i = 0, m = txt.size();
        int j = 0, n = pat.size();
        //这里也可以换为get_next
        vector<int> next = get_nextVal(pat);
        while (i < m && j < n)
        {
            //j=-1或txt[i]==pat[j]继续匹配下一个字符
            if (j == -1 || txt[i] == pat[j])
            {
                i++;
                j++;
            }
            //字符失配，我们需要将指针j回退到它的前缀字符串尾后位置
            else
                j = next[j];
        }
        //指针匹配完成否与？完全匹配第一个字符的位置：-1
        return j == n ? i - j : -1;
    }

    vector<int> get_next(const string &pat)
    {
        vector<int> next;
        next.push_back(-1);
        //指针j指向后缀，指针k指向前缀。
        int j = 0, k = -1, n = pat.size();
        while (j < n - 1)
        {
            //若k==-1或pat[j]==pat[k]，指针j、k同时右移一个单位，那么此时的next[j]赋值为k，因为此时k长度已增加1了
            if (k == -1 || pat[j] == pat[k])
            {
                k++;
                j++;
                next.push_back(k);
            }
            //若k不等于-1和pat[j]不等于pat[k]时，指针k需要回退到next[k]的位置
            //若没有可以匹配的前缀和后缀，那么k最终会回到-1的位置
            else
            {
                k = next[k];
            }
        }
        return next;
    }

    //优化后的next数组代码
    vector<int> get_nextVal(const string &pat)
    {
        //j表示后缀字符串的尾指针，k表示前缀字符串的尾指针
        //换句话说nextVal[j]=k，即j指针之前相同前缀和后缀的最长长度为k
        //注意这里的k就为nextVal[j]，所以进行循环时，每次我们比较的是j和nextVal[j]=k
        int j = 0, k = -1, n = pat.size();
        vector<int> nextVal(n, 1);
        nextVal[0] = -1;
        while (j < n - 1)
        {
            if (k == -1 || pat[j] == pat[k])
            {
                k++;
                j++;
                /*
            在k，j移位之后，由于pat[k]与pat[j]不相等，那么我们的nextVal[j]的值为k（表示再原有长度k的基础上+1）
            即后缀字符串的尾指针字符与前缀字符串的尾指针字符不相等，那么我们更新next[j]为k（原有k基础上加了1），下一次循环匹配下一个字符
            正是因为P[j]不等于P[k]，那么进行kmp时，当P[j]与S[i]不匹配时，指针j回退位置k，那么S[i]可以用新字符P[k]进行匹配
            */
                if (pat[j] != pat[k])
                    nextVal[j] = k;
                /*
            在k，j移位之后，由于pat[k]与pat[j]相等，那么我们的nextVal[j]需要回退到nextVal[k]的位置，然后我们下次循环匹配Pat[i]与Pat[k]
            pat[j]==pat[k] => pat[j]==pat[next[j]]，我们需要将指针j回退到位置next[k]，即位置k的next（也就是k的最长前缀字符串的尾后指针位置），这样可以避免重复计算
            注意这里并不是真正将指针j回退了，只是在进行kmp发生失配时，指针j会回退到next[k]的位置
            */
                else
                    nextVal[j] = nextVal[k];
            }
            //若k不等于-1和pat[j]不等于pat[k]时，我们需要将k回退到k的next位置，也就是回退到k的前缀字符串的尾后指针位置
            else
            {
                k = nextVal[k];
            }
        }
        return nextVal;
    }
};

int main()
{
  cout<<KMP().search("BBC ABCDAB ABCDABCDABDE","ABCDABD")<<endl;
}