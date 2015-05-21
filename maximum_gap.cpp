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

    int maximumGap_sort(const std::vector<int>& nums)
    {
        return 0;
    }

    void radix_sort(std::vector<int>& nums)
    {
    }

    //see introductoin to algorithm
    std::vector<int> count_sort(const std::vector<int>& A, int max_val)
    {
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


};


using namespace std;
class Solution_
{
public:
    int getMax(vector<int> num){
        int m = INT_MIN;
        for (int i=0;i<num.size();i++){
            m = max(m,num[i]);
        }
        return m;
    }
     
    void countSort(vector<int> &num, int nd){
        int n = num.size();
        vector<int> output(n,0);
        vector<int> count(10,0);
  
        for (int i = 0; i < n; i++){
            count[ (num[i]/nd)%10 ]++;
        }
  
        for (int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
  
        for (int i = n - 1; i >= 0; i--){
            output[ count[(num[i]/nd)%10] - 1] = num[i];
            count[ (num[i]/nd)%10 ]--;
        }
  
        for (int i = 0; i < n; i++){
            num[i] = output[i];
        }
    }
 
    void radixsort(vector<int> &num){
         int max_n = getMax(num);
         for (int nd = 1; max_n/nd > 0; nd *= 10){
             countSort(num, nd);
         }
    }
     
    int maximumGap(vector<int> &num) {
        if (num.size()<2){
            return 0;
        }
        radixsort(num);
        int res = abs(num[1] - num[0]);
        for (int i=2;i<num.size();i++){
            if (num[i]-num[i-1]>res){
                res = abs(num[i] - num[i-1]);
            }
        }
        return res;
         
    }
};

int main()
{
    Solution s;
    //std::cout<<s.maximumGap({1,10000000})<<std::endl;
    std::vector<int> v{1, 123, 2341, 2234, 523, 34, 36, 1234};
    auto r = s.count_sort(v, 2341);
    for(int x : r)
    {
        std::cout<<x<<std::endl;
    }
    return 0;
}

