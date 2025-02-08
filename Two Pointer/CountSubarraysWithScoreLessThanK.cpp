class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0;
        int right = 0;
        long long count = 0;
        long long sum = 0;
        while(right<nums.size())
        {
            sum += nums[right];
            while((sum*(right-left+1))>=k)
            {
                sum -= nums[left];
                left+=1;
            }
            count += right-left+1;
            right+=1;
        }
        return count;
    }
};
