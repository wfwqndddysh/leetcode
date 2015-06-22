#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        if(board.size()==0) return word.empty();

        int l=board.size();
        int c=board[0].size();

        flags_.resize(l, std::vector<bool>(c, false));

        for(int i=0; i<l; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(backtrack(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }

private:
    bool backtrack(std::vector<std::vector<char>>& board
            , int i
            , int j
            , const std::string& word
            , int k)
    {
        if(k==(int)word.size()) return true;

        int l=board.size();
        int c=board[0].size();

        if(i<0 || j<0 || i==l || j==c) return false;
        if(board[i][j]!=word[k]) return false;

        char tmp=board[i][j];
        board[i][j] = '\0';
        
        bool found = backtrack(board, i, j+1, word, k+1)
            || backtrack(board, i+1, j, word, k+1)
            || backtrack(board, i-1, j, word, k+1)
            || backtrack(board, i, j-1, word, k+1);

        board[i][j] = tmp;
        return found;
    }

private:
    std::vector<std::vector<bool>> flags_;
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> board{{'a', 'a'}};
    std::cout<<s.exist(board, "aaa")<<std::endl;
    return 0;
}

