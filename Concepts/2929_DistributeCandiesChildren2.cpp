class Solution {
public:
    long long distributeCandies(int n, int limit) 
    {
        long long count = 0;
        for(int i = 0; i <= min(n, limit); i++)
        {
            int sum = n-i;
            if(sum <= (2*limit))
            {
                count += min(sum, limit) - max(0, sum-limit) + 1;
            }
        }
        return count;
    }
};
