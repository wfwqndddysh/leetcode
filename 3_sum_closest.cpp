#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<climits>

class SolutionLeetCode
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        std::vector<int> v(nums.begin(), nums.end()); // I didn't wanted to disturb original array.
        int n = 0;
        int ans = 0;
        int sum;

        sort(v.begin(), v.end());

        // If less then 3 elements then return their sum
        while (v.size() <= 3)
        {
            return accumulate(v.begin(), v.end(), 0);
        }

        n = v.size();

        /* v[0] v[1] v[2] ... v[i] .... v[j] ... v[k] ... v[n-2] v[n-1]
         *                    v[i]  <=  v[j]  <= v[k] always, because we sorted our array. 
         * Now, for each number, v[i] : we look for pairs v[j] & v[k] such that 
         * absolute value of (target - (v[i] + v[j] + v[k]) is minimised.
         * if the sum of the triplet is greater then the target it implies
         * we need to reduce our sum, so we do K = K - 1, that is we reduce
         * our sum by taking a smaller number.
         * Simillarly if sum of the triplet is less then the target then we
         * increase out sum by taking a larger number, i.e. J = J + 1.
         */
        ans = v[0] + v[1] + v[2];
        for (int i = 0; i < n-2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                sum = v[i] + v[j] + v[k];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                    if (ans == target) return ans;
                }
                (sum > target) ? k-- : j++;
            }
        }
        return ans;
    }
};

int main()
{
    SolutionLeetCode s;

    /*
    std::vector<int> nums{0, 0, 0};
    int sum=s.threeSumClosest(nums, 1);
    */

    /*
    std::vector<int> nums{1,2,4,8,16,32,64,128};
    int sum=s.threeSumClosest(nums, 82);
    */

    /*
    std::vector<int> nums{1, 1, 1, 0};
    int sum=s.threeSumClosest(nums, 100);
    */

    /*
    std::vector<int> nums{1, 1, 1, 0};
    int sum=s.threeSumClosest(nums, -100);
    */

    /*
    std::vector<int> nums{0, 2, 1, -3};
    int sum=s.threeSumClosest(nums, 0);
    */

    std::vector<int> nums{13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
    int sum=s.threeSumClosest(nums, -59);

    std::cout<<sum<<std::endl;
    return 0;
}

