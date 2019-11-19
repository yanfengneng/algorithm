#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool flag=false;
        for(int x=0;x<board.size();++x)
        {
            for(int y=0;y<board[0].size();++y)
                if(backtrack(board,word,0,x,y))
                    return true;
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board,string word,int i,int x,int y)
    {
        if(x<0||x==board.size()||y<0||y==board[0].size())return false;//�����ݹ�߽�
         if(board[x][y]=='#'||word[i]!=board[x][y])return false;//�ݹ鷽�򲻶�
        if(i==word.size()-1)return true;        
        //choose���̣��������·��
        char temp=board[x][y];
        board[x][y]='#';
        //������һ������
        bool flag= backtrack(board,word,i+1,x-1,y)||backtrack(board,word,i+1,x+1,y)|| backtrack(board,word,i+1,x,y-1)|| backtrack(board,word,i+1,x,y+1);
        //unchoose���̣��Ƴ�����·��
        board[x][y]=temp;
        return flag;
     
    }
};

int main()
{
    vector<vector<char>> board(1,vector<char>(1,'a'));
    bool b=Solution().exist(board,"a");
    cout<<b<<endl;
}