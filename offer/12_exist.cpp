#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   bool exist(vector<vector<char>>& board, string word) {
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
        if(x<0||x==board.size()||y<0||y==board[0].size())return false;//超过递归边界
        if(board[x][y]=='#'||board[x][y]!=word[i])return false;//递归方向不对
        if(i==word.size()-1)return true;
        char temp=board[x][y];
        board[x][y]='#';
        bool flag=  backtrack(board,word,i+1,x-1,y)||backtrack(board,word,i+1,x+1,y)
                    ||backtrack(board,word,i+1,x,y-1)||backtrack(board,word,i+1,x,y+1);
        board[x][y]=temp;
        return flag;
    }
};

int main()
{
    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word= "ABCCED";
    cout<<Solution().exist(board,word)<<endl;
}