class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        int min1 = INT_MAX;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[left]<=nums[mid])
            {
                min1 = min(min1, nums[left]);
                left = mid+1;
            }
            else
            {
                min1 = min(min1, nums[mid]);
                right = mid-1;
            }
        }
        return min1;
    }
};
