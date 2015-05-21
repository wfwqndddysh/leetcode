#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int maximumGap(const std::vector<int>& nums)
    {
        auto sz = nums.size();
        if(sz<2) return 0;

        //get global max, min
        int g_max = nums[0];
        int g_min = nums[0];
        for(auto x : nums)
        {
            if(x < g_min)
                g_min = x;
            else if(x > g_max)
                g_max = x;
        }

        //get num of buckets
        size_t buckets_len = (g_max-g_min)/sz+1;
        size_t buckets_num = (g_max-g_min)/buckets_len+1;
        std::vector<std::vector<int>> buckets(buckets_num);

        for(int x : nums)
        {
            int loc = (x-g_min)/buckets_len;
            if(buckets[loc].empty())
            {
                //more effective
                buckets[loc].reserve(2);
                buckets[loc].push_back(x);
                buckets[loc].push_back(x);
            }
            else
            {
                buckets[loc][0] = std::min(buckets[loc][0], x);
                buckets[loc][1] = std::max(buckets[loc][1], x);
            }
        }

        int max_gap = 0;
        for(size_t i=0, prev=0; i<buckets.size(); ++i)
        {
            if(buckets[i].empty()) continue;
            max_gap = std::max(max_gap, buckets[i][0]-buckets[prev][1]);
            prev = i;
        }
        return max_gap;
    }

    int maximumGap_sort(std::vector<int>& nums)
    {
        auto sz = nums.size();
        if(sz<2)
        {
            return 0;
        }

        radix_sort(nums);

        int max_gap = 0;
        for(size_t i=1; i<nums.size(); ++i)
        {
            max_gap = std::max(max_gap, nums[i]-nums[i-1]);
        }
        return max_gap;
    }

    void radix_sort(std::vector<int>& nums)
    {
        int max_n = INT_MIN;
        for(int n : nums)
        {
            max_n = std::max(max_n, n);
        }

        for(int nd=1; max_n/nd>0; nd*=10)
        {
            count_sort(nums, nd);
        }
    }

    //see introductoin to algorithm
    std::vector<int> count_sort(const std::vector<int>& A)
    {
        int max_val = INT_MIN;;
        for(int n : A)
        {
            max_val = std::max(n, max_val);
        }

        std::vector<int> C(max_val+1, 0);
        std::vector<int> B(A.size(), 0);

        for(int n : A)
        {
            C[n]++;
        }

        for(size_t i=1; i<C.size(); ++i)
        {
            C[i] += C[i-1];
        }

        for(int i=A.size()-1; i>=0; --i)
        {
            B[C[A[i]]-1] = A[i];
            C[A[i]]--;
        }
        return B;
    }

    void count_sort(std::vector<int>& A, int nd)
    {
        std::vector<int> C(10, 0);
        std::vector<int> B(A.size(), 0);

        for(int n : A)
        {
            C[n/nd%10]++;
        }

        for(size_t i=1; i<C.size(); ++i)
        {
            C[i] += C[i-1];
        }

        for(int i=A.size()-1; i>=0; --i)
        {
            int cmp = (A[i]/nd)%10;
            B[C[cmp]-1] = A[i];
            C[cmp]--;
        }
        A=B;
    }
};

int main()
{
    Solution s;
    std::vector<int> v{100, 3, 2, 1};
    std::cout<<s.maximumGap_sort(v)<<std::endl;
    return 0;
}

