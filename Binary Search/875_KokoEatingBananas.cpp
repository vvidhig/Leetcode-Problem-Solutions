class Solution {
public:
    double timetaken(vector<int> nums, int mid)
    {
        double sum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            sum += ceil((double)(nums[i])/mid);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 0;
        int right = *max_element(piles.begin(), piles.end());
        double val = 0.0;
        while(left<=right)
        {
            int mid = (left+right)/2;
            val = timetaken(piles, mid);
            if(val<=h)
            {
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
