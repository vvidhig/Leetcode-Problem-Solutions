class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i<n-1; i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int zero = -1;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]==0)
            {
                zero = i;
                break;
            }
        }
        if(zero == -1)
        {
            return nums;
        }
        for(int i = zero+1; i<n; i++)
        {
            if(nums[i] != 0)
            {
                int temp = nums[i];
                nums[i] = nums[zero];
                nums[zero] = temp;
                zero++;
            }
        }
        return nums;
    }
};
