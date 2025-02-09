class Solution {
public:
    int atmost(vector<int> nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int, int> mp;
        while(right<n)
        {
            mp[nums[right]] += 1;
            while(mp.size()>k)
            {
                mp[nums[left]] -= 1;
                if(mp[nums[left]]==0)
                {
                    mp.erase(nums[left]);
                }
                left += 1;
            }
            count += (right-left+1);
            right += 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return (atmost(nums, k) - atmost(nums, k-1));
    }
};
