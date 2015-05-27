#include<iostream>
#include<cassert>
#include<unordered_map>
#include<list>

/*
 细节上没有想到的是尽量把信息放到hash表里，而不是list里
 这样可以最大限度地减少间接访问次数
 */
class LRUCache
{
public:
    LRUCache(int capacity)
        : capacity_(capacity), count_(0)
    {
    }

    int get(int key)
    {
        auto itr = cache_map_.find(key);
        if(itr==cache_map_.cend())
            return -1;

        int val = itr->second->second;
        shift_to_first(key, itr);
        return val;
    }

    void set(int key, int val)
    {
        auto itr = cache_map_.find(key);
        if(itr!=cache_map_.cend())
        {
            itr->second->second = val;
            shift_to_first(key, itr);
        }
        else
        {
            if(count_==capacity_)
            {
                cache_map_.erase(cache_map_.find(cache_list_.back().first));
                cache_list_.pop_back();
                count_--;
            }
            cache_list_.push_front(std::make_pair(key, val));
            cache_map_[key] = cache_list_.begin();
            count_++;
        }
    }

private:

    void shift_to_first(int key, std::unordered_map<int
            , std::list<std::pair<int, int>>::iterator>::iterator itr)
    {
        auto l_itr = itr->second;
        auto first = l_itr;
        auto last = ++l_itr;

        cache_list_.insert(cache_list_.begin(), first, last);
        cache_list_.erase(first);

        cache_map_.erase(itr);
        cache_map_[key] = cache_list_.begin();
    }

    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map_;
    std::list<std::pair<int, int>> cache_list_;
    int capacity_;
    int count_;
};

int main()
{
    LRUCache lru(2048);
    //[set(2,1),get(2),set(3,2),get(2),get(3)]
    //std::cout<<lru.get(0)<<std::endl;
    return 0;
}

