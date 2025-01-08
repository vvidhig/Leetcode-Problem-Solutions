class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int pt = 1;
        int count = 0, max1 = 0;
        if(nums.size()==1)
        {
            if(nums[0]==0)
            {
                return 0;
            }
            else if(nums[0]==1)
            {
                return 1;
            }
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                count = 0;
                pt = i+1;
            }
            else
            {
                count += 1;
            }
            max1 = max(max1, count);
        }
        return max1;
    }
};
