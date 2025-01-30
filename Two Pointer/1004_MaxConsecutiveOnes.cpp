class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right = 0;
        int left = 0;
        int maxlen = 0;
        int zero = 0;
        while(right<nums.size())
        {
            if(nums[right]==0)
            {
                zero+=1;
            }
            while(zero>k)
            {
                if(nums[left]==0)
                {
                    zero-=1;
                }
                left+=1;
            }
            maxlen = max(maxlen, right-left+1);
            right+=1;
        }
        return maxlen;
    }
};
