class Solution {
private:
    bool canRob(vector<int>& nums, int k, int mid)
    {
        int count = 0;
        int i = 0;
        int n = nums.size();
        while(i<n)
        {
            if(nums[i] <= mid)
            {
                count++;
                i += 2;
            }
            else
            {
                i += 1;
            }
        }
        return count >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) 
    {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while(left <= right)
        {
            int mid = (right + left) / 2;
            if(canRob(nums, k, mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
