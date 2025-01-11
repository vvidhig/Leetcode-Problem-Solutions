class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        vector<int> result;
        int m = floor(n/3);
        for(int i = 0; i<n; i++)
        {
            mp[nums[i]]+=1;
        }
        for(auto i:mp)
        {
            if(i.second>m)
            {
                result.push_back(i.first);
            }
        }
        return result;
    }
};
