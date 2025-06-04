class Solution {
private:
    void solve(vector<vector<int>>& result, vector<int>& nums, vector<int>& current, vector<bool>& used)
    {
        if(current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(used[i])
            {
                continue;
            }
            if(i>0 && nums[i]==nums[i-1] && !used[i-1])
            {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            solve(result, nums, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(n, false);
        solve(result, nums, current, used);
        return result;
    }
};
