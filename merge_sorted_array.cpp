#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        std::vector<int> nums13;
        int i=0, j=0;
        for(; i<m && j<n;)
        {
            if(nums2[j]<nums1[i])
            {
                nums13.push_back(nums2[j]);
                j++;
            }
            else
            {
                nums13.push_back(nums1[i]);
                i++;
            }
        }

        for(; i<m; i++)
        {
            nums13.push_back(nums1[i]);
        }

        for(; j<n; j++)
        {
            nums13.push_back(nums2[j]);
        }

        nums1 = nums13;
    }
};

class SolutionConstantSpace
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        if(n<=0) return;

        for(int i=0; i<m; ++i)
            nums1[m+n-i-1] = nums1[m-1-i];

        int i=n, j=0;
        for(; i<m+n && j<n;)
        {
            if(nums2[j]<nums1[i])
            {
                nums1[i+j-n]=nums2[j];
                j++;
            }
            else
            {
                nums1[i+j-n]=nums1[i];
                i++;
            }
        }

        for(; j<n; j++)
        {
            nums1[i+j-n]=nums2[j];
        }
    }
};

int main()
{
    SolutionConstantSpace s;
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{4, 5, 6};

    s.merge(nums1, 3, nums2, 3);

    for(int n : nums1)
        std::cout<<n<<" ";

    std::cout<<std::endl;
    return 0;
}

