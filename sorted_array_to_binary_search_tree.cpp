#include<iostream>
#include<cassert>
#include<vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        return rec(nums, 0, nums.size());
    }
private:
    TreeNode* rec(const std::vector<int>& nums, int beg, int end)
    {
        if(beg==end) return nullptr;

        int root=-1;
        int l_beg=-1;
        int l_end=-1;
        int r_beg=-1;
        int r_end=-1;
        
        partition(beg, end
                , root
                , l_beg, l_end
                , r_beg, r_end);

        return merge(nums, root, rec(nums, l_beg, l_end), rec(nums, r_beg, r_end));
    }

    void partition(int beg, int end
            , int& root
            , int& l_beg, int& l_end
            , int& r_beg, int& r_end)
    {
        assert(beg<end);

        if(beg+1==end)
        {
            root=beg;
            return;
        }

        if(beg+2==end)
        {
            root=beg;
            r_beg=beg+1;
            r_end=end;
            return;
        }

        int mid=beg+(end-beg)/2;

        root=mid;
        l_beg=beg;
        l_end=mid;
        r_beg=mid+1;
        r_end=end;
    }

    TreeNode* merge(const std::vector<int>& nums
            , int index
            , TreeNode* left
            , TreeNode* right)
    {
        auto root=new TreeNode(nums[index]);
        root->left=left;
        root->right=right;
        return root;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

