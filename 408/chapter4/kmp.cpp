#include <iostream>
#include <string>
#include <vector>
using namespace std;

class KMP
{
public:
    //txtΪ�ı�����patΪģʽ����pat����ƥ��txt��
    int search(const string &txt, const string &pat)
    {
        if (pat.empty())
            return 0;
        int i = 0, m = txt.size();
        int j = 0, n = pat.size();
        //����Ҳ���Ի�Ϊget_next
        vector<int> next = get_nextVal(pat);
        while (i < m && j < n)
        {
            //j=-1��txt[i]==pat[j]����ƥ����һ���ַ�
            if (j == -1 || txt[i] == pat[j])
            {
                i++;
                j++;
            }
            //�ַ�ʧ�䣬������Ҫ��ָ��j���˵�����ǰ׺�ַ���β��λ��
            else
                j = next[j];
        }
        //ָ��ƥ����ɷ��룿��ȫƥ���һ���ַ���λ�ã�-1
        return j == n ? i - j : -1;
    }

    vector<int> get_next(const string &pat)
    {
        vector<int> next;
        next.push_back(-1);
        //ָ��jָ���׺��ָ��kָ��ǰ׺��
        int j = 0, k = -1, n = pat.size();
        while (j < n - 1)
        {
            //��k==-1��pat[j]==pat[k]��ָ��j��kͬʱ����һ����λ����ô��ʱ��next[j]��ֵΪk����Ϊ��ʱk����������1��
            if (k == -1 || pat[j] == pat[k])
            {
                k++;
                j++;
                next.push_back(k);
            }
            //��k������-1��pat[j]������pat[k]ʱ��ָ��k��Ҫ���˵�next[k]��λ��
            //��û�п���ƥ���ǰ׺�ͺ�׺����ôk���ջ�ص�-1��λ��
            else
            {
                k = next[k];
            }
        }
        return next;
    }

    //�Ż����next�������
    vector<int> get_nextVal(const string &pat)
    {
        //j��ʾ��׺�ַ�����βָ�룬k��ʾǰ׺�ַ�����βָ��
        //���仰˵nextVal[j]=k����jָ��֮ǰ��ͬǰ׺�ͺ�׺�������Ϊk
        //ע�������k��ΪnextVal[j]�����Խ���ѭ��ʱ��ÿ�����ǱȽϵ���j��nextVal[j]=k
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
            ��k��j��λ֮������pat[k]��pat[j]����ȣ���ô���ǵ�nextVal[j]��ֵΪk����ʾ��ԭ�г���k�Ļ�����+1��
            ����׺�ַ�����βָ���ַ���ǰ׺�ַ�����βָ���ַ�����ȣ���ô���Ǹ���next[j]Ϊk��ԭ��k�����ϼ���1������һ��ѭ��ƥ����һ���ַ�
            ������ΪP[j]������P[k]����ô����kmpʱ����P[j]��S[i]��ƥ��ʱ��ָ��j����λ��k����ôS[i]���������ַ�P[k]����ƥ��
            */
                if (pat[j] != pat[k])
                    nextVal[j] = k;
                /*
            ��k��j��λ֮������pat[k]��pat[j]��ȣ���ô���ǵ�nextVal[j]��Ҫ���˵�nextVal[k]��λ�ã�Ȼ�������´�ѭ��ƥ��Pat[i]��Pat[k]
            pat[j]==pat[k] => pat[j]==pat[next[j]]��������Ҫ��ָ��j���˵�λ��next[k]����λ��k��next��Ҳ����k���ǰ׺�ַ�����β��ָ��λ�ã����������Ա����ظ�����
            ע�����ﲢ����������ָ��j�����ˣ�ֻ���ڽ���kmp����ʧ��ʱ��ָ��j����˵�next[k]��λ��
            */
                else
                    nextVal[j] = nextVal[k];
            }
            //��k������-1��pat[j]������pat[k]ʱ��������Ҫ��k���˵�k��nextλ�ã�Ҳ���ǻ��˵�k��ǰ׺�ַ�����β��ָ��λ��
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