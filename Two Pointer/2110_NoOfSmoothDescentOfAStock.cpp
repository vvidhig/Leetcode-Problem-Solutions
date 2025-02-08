class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 0;
        long long sum = 0;
        int left = 0;
        int right = 0;
        while(right<prices.size())
        {
            while((prices[left]-prices[right])!=(right-left))
            {
                left+=1;
            }
            count += right-left+1;
            right+=1;
        }
        return count;
    }
};
