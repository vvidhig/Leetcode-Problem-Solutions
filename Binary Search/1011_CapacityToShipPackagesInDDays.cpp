class Solution {
public:
    int noOfDays(vector<int> weights, int mid)
    {
        int curr_cap = 0;
        int day = 1;
        for(int i = 0; i<weights.size(); i++)
        {
            if((curr_cap+weights[i]) > mid)
            {
                curr_cap = weights[i];
                day += 1;
            }
            else
            {
                curr_cap += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            int day = noOfDays(weights, mid);
            if(day<=days)
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
