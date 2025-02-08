class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        unordered_map<int, int>mp;
        int part = -1;
        for(int i = nums.size()-1; i>=0; i-=1)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                part=i+1;
                break;
            }
            ++mp[nums[i]];
        }
        if(part==-1)
        {
            return 0;
        }
        return ceil((double)part/3);
    }
};
