class Solution {
private:
    bool isPossible(vector<int>& bloomDay, int mid, int m, int k)
    {
        int total = 0;
        int n = bloomDay.size();
        for(int i = 0; i<n; i++)
        {
            int count = 0;
            while(i<n && count < k && bloomDay[i] <= mid)
            {
                count += 1;
                i += 1;
            }
            if(count==k)
            {
                total += 1;
                i -= 1;
            }
            if(total >= m)
            {
                return true;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        long long n = bloomDay.size();
        if(((long long)m*k)>n)
        {
            return -1;
        }
        int left = 1;
        int right = 1e9;
        while(left<right)
        {
            int mid = left + (right - left)/2;
            if(isPossible(bloomDay, mid, m, k))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
