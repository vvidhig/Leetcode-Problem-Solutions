class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            pq.push(nums[i]);
        }
        int count = 0;
        while(pq.top()<k)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long add = min(x,y)*2 + max(x,y);
            pq.push(add);
            count += 1;
        }
        return count;
    }
};
