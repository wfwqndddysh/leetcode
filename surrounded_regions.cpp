#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    void sovle(std::vector<std::vector<char>>& board)
    {
        if(board.size()<2) return;

        int rows = (board.size());
        int columns(board[0].size());

        std::vector<std::vector<bool>> flags(rows, std::vector<bool>(columns, false));

        for(int i=0; i<rows; ++i)
        {
            bool surrounded(true);
            for(int j=0; j<columns; ++j)
            {
                surrounded = surrounded && be_surrounded(i, j, flags);
            }
        }
    }
private:
    bool be_surrounded(int rows, int columns, std::vector<std::vector<bool>>& flags)
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

