#include<iostream>
#include<cassert>
#include<vector>
#include<fstream>
#include<queue>

class Solution
{
public:
    void solve(std::vector<std::vector<char>>& board)
    {
        if(board.size()<2) return;

        int rows = (board.size());
        int columns(board[0].size());

        std::vector<std::vector<bool>> traveled(rows, std::vector<bool>(columns, false));
        std::vector<std::pair<int, int>> captrued;

        for(int i=0; i<rows; ++i)
        {
            for(int j=0; j<columns; ++j)
            {
                captrued.clear();

                if(traveled[i][j])
                    continue;

                if(board[i][j]=='X')
                {
                    traveled[i][j]=true;
                    continue;
                }

                if(be_surrounded_bfs(board, i, j, traveled, captrued))
                {
                    for(auto& b : captrued)
                    {
                        board[b.first][b.second] = 'X';
                    }
                }
            }
        }
    }
private:
    //BFS
    bool be_surrounded_bfs(const std::vector<std::vector<char>>& board
            , int rows
            , int columns
            , std::vector<std::vector<bool>>& traveled
            , std::vector<std::pair<int, int>>& captrued)
    {
        std::queue<std::pair<int, int>> bfs;

        bool surrounded = true;
        bfs.push({rows, columns});
        while(!bfs.empty())
        {
            auto cur=bfs.front();
            bfs.pop();
            int r = cur.first;
            int l = cur.second;

            if(be_out_of_range(board, r, l) || traveled[r][l])
                continue;

            traveled[r][l] = true;

            if(board[r][l]=='X')
                continue;

            if(be_borderline(board, r, l))
                surrounded = false;

            captrued.push_back({r, l});

            if(!be_out_of_range(board, r-1, l) && board[r-1][l]=='O' && !traveled[r-1][l])
                bfs.push({r-1, l});

            if(!be_out_of_range(board, r+1, l) && board[r+1][l]=='O' && !traveled[r+1][l])
                bfs.push({r+1, l});

            if(!be_out_of_range(board, r, l-1) && board[r][l-1]=='O' && !traveled[r][l-1])
                bfs.push({r, l-1});

            if(!be_out_of_range(board, r, l+1) && board[r][l+1]=='O' && !traveled[r][l+1])
                bfs.push({r, l+1});
        }
        return surrounded;
    }

    bool be_borderline(const std::vector<std::vector<char>>& board, int r, int l)
    {
        return r==0 || r==(int)board.size()-1 || l==0 || l==(int)board[0].size()-1;
    }

    bool be_out_of_range(const std::vector<std::vector<char>>& board, int r, int l)
    {
        return r<0 || r>(int)board.size()-1 || l<0 || l>(int)board[0].size()-1;
    }
};

int main()
{
    Solution s;

    /*
    std::vector<std::vector<char>> board;
    std::ifstream data("/tmp/t.txt");
    while(!data.eof())
    {
        std::string str;
        std::getline(data, str);
        std::vector<char> line;
        for(auto c : str)
        {
            line.push_back(c);
        }
        board.push_back(line);
    }
    board.pop_back();
    */

    std::vector<std::vector<char>> board {{'X', 'O', 'X'},
                                          {'O', 'X', 'O'},
                                          {'X', 'O', 'X'}};

    s.solve(board);
    for(const auto& v : board)
    {
        for(char c : v)
            std::cout<<c<<" ";
        std::cout<<std::endl;
    }
    return 0;
}

