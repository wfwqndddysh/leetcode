#include<iostream>
#include<cassert>
#include<vector>
#include<climits>
#include<tuple>

class Solution
{
public:
    using Elem = std::tuple<int, int, int, int>;

    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon)
    {
        if(dungeon.size()==0)
            return 0;


        auto rows = dungeon.size();
        auto columns = dungeon.front().size();
        //first: mini to here, second:hp when leave here
        //third: mini to here where hp is largest
        //four: largest hp
        std::vector<std::vector<Elem>> mini_hp;
        mini_hp.resize(rows);
        for(auto& n : mini_hp)
        {
            n.resize(columns);
        }

        for(size_t r=0; r<rows; ++r)
        {
            for(size_t c=0; c<columns; ++c)
            {
                if(c==0 && r==0)
                {
                    int cur = dungeon[r][c];
                    bool hurt = cur <= 0;
                    int mini = hurt ? std::abs(cur)+1 : 0;
                    int hp = hurt ? 1 : cur;
                    mini_hp[r][c] = std::make_tuple(mini, hp, mini, hp);
                    continue;
                }
                else if(r==0)
                {
                    const auto& right = mini_hp[r][c-1];
                    mini_hp[r][c] = do_one(dungeon[r][c], right);
                }
                else if(c==0)
                {
                    const auto& up = mini_hp[r-1][c];
                    mini_hp[r][c] = do_one(dungeon[r][c], up);
                }
                else
                {
                    const auto& up = mini_hp[r-1][c];
                    const auto& right = mini_hp[r][c-1];
                    do_it(dungeon[r][c], up, right, mini_hp[r][c]);
                }
            }
        }
        int init_hp = std::get<0>(mini_hp[rows-1][columns-1]);
        return init_hp > 0 ? init_hp : 1;
    }

    void do_it(int hp
            , const Elem& up
            , const Elem& right
            , Elem& cur)
    {
        if(hp>=0)
        {
            const auto& prev = up.first<right.first ? up : right;
            cur.first = prev.first;
            cur.second = prev.second + hp;
        }
        else
        {
            const auto from_up = do_one(hp, up);
            const auto from_right = do_one(hp, right);
            cur = from_up.first < from_right.first ? from_up : from_right;
        }
    }

    std::pair<int, int, int, int> do_one(int hp, const std::pair<int, int, int, int>& prev)
    {
        std::pair<int, int> ret;
        int diff = prev.second+hp;
        if(diff>0)
        {
            ret.first = prev.first;
            ret.second = diff;
        }
        else
        {
            ret.first = prev.first+std::abs(diff)+1;
            ret.second = 1;
        }
        return ret;
    }
private:
};

int main()
{
    Solution s;
    //std::vector<std::vector<int>> dungeon {{0,-3}};
    //std::vector<std::vector<int>> dungeon {{0,5}, {-2, -3}};
    std::vector<std::vector<int>> dungeon {{1}, {-2}, {1}};
    std::cout<<s.calculateMinimumHP(dungeon)<<std::endl;
    return 0;
}

