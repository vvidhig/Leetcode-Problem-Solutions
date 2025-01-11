class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suff = 1;
        int max1 = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(pre==0)
            {
                pre = 1;
            }
            if(suff==0)
            {
                suff = 1;
            }
            pre = pre*nums[i];
            suff = suff*nums[n-i-1];
            max1 = max(max1, max(pre, suff));
        }
        return max1;
    }
};
