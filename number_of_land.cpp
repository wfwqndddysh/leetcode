#include<vector>
#include<iostream>
#include<cassert>
#include<stack>
#include<tuple>

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> grid)
    {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;

        high_ = grid.size()-1;
        width_ = grid[0].size()-1;

        int num_of_lands = 0;
        for(size_t h =0; h<=high_; ++h)
        {
            for(size_t v=0; v<=width_; ++v)
            {
                if(grid[h][v]=='1')
                {
                    num_of_lands++;
                    grid[h][v]='v';
                    st_.push(std::make_tuple(h, v));
                    while(!st_.empty())
                    {
                        std::tuple<int ,int> e = st_.top();
                        st_.pop();
                        process_one(e, grid);
                    }
                }
            }
        }
        return num_of_lands;
    }

    int numIslandsRec(std::vector<std::vector<char>> grid)
    {
        if(grid.size()==0 || grid[0].size()==0)
            return 0;

        size_t num_of_rows = grid.size();
        size_t num_of_columns = grid[0].size();
        int num_of_lands = 0;
        for(size_t h =0; h<=num_of_rows; ++h)
            for(size_t v=0; v<=num_of_columns; ++v)
                num_of_lands += visit(grid, h, v) ? 1 : 0;

        return num_of_lands;
    }

private:
    void process_one(const std::tuple<size_t, size_t>& e, std::vector<std::vector<char>>& grid)
    {
        size_t h = std::get<0>(e);
        size_t v = std::get<1>(e);

        //top
        if(h!=0 && grid[h-1][v]=='1')
        {
            grid[h-1][v] = 'v';
            st_.push(std::make_tuple(h-1, v));
        }

        //low
        if(h!=high_ && grid[h+1][v]=='1')
        {
            grid[h+1][v] = 1;
            st_.push(std::make_tuple(h+1, v));
        }

        //left
        if(v!=0 && grid[h][v-1]=='1')
        {
            grid[h][v-1] = 1;
            st_.push(std::make_tuple(h, v-1));
        }

        //right
        if(v!=width_ && grid[h][v+1]=='1')
        {
            grid[h][v+1] = 1;
            st_.push(std::make_tuple(h, v+1));
        }
    }

    bool visit(std::vector<std::vector<char>>& grid, size_t h, size_t v)
    {
        size_t num_of_rows = grid.size();
        size_t num_of_columns = grid[0].size();

        if((int)h < 0 || h>= num_of_rows || (int)v < 0 || v>= num_of_columns || grid[h][v] != '1')
            return false;

        grid[h][v] = 'v';

        visit(grid, h-1, v);
        visit(grid, h+1, v);
        visit(grid, h, v-1);
        visit(grid, h, v+1);

        return true;
    }

    size_t high_;
    size_t width_;
    std::stack<std::tuple<size_t, size_t>> st_;
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> grid;
    std::vector<char> a(3, '1');
    std::vector<char> b(3, '1');
    b[1] = '0';
    std::vector<char> c(3, '1');

    grid.push_back(a);
    grid.push_back(b);
    grid.push_back(c);

    std::cout<<s.numIslands(grid)<<std::endl;
    return 0;
}

