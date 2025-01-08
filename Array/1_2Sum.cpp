class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> hashMap;
        vector<int> result;
        for(int i = 0; i<n; i++)
        {
            int rem = target - nums[i];
            if(hashMap.find(rem)!=hashMap.end())
            {
                int k = hashMap[rem];
                result.push_back(i);
                result.push_back(k);
            }
            if(hashMap.find(rem)==hashMap.end())
            {
                hashMap[nums[i]] = i;
            }
        }
        return result;
    }
};
