class Solution {
public:
    int sumDigit(int num)
    {
        int sum = 0;
        while(num!=0)
        {
            sum += num%10;
            num = num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) 
    {
        unordered_map<int, priority_queue<int>> mp;
        for(int i = 0; i<nums.size(); i++)
        {
            int sum = sumDigit(nums[i]);
            mp[sum].push(nums[i]);
        }
        int maxsum = -1;
        for(auto& [sum, pq]:mp)
        {
            int max2sum = -1;
            if(pq.size()>=2)
            {
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                max2sum = first+second;
            }
            maxsum = max(maxsum, max2sum);
        }
        return maxsum;
    }
};
