class Solution {
private:
    long long carsRepaired(vector<int>& ranks, long long mid)
    {
        long long numCars = 0;
        for(int i = 0; i<ranks.size(); i++)
        {
            numCars += sqrt(mid/(double)ranks[i]);
        }
        return numCars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        long long left = 1;
        long long right = (long long)*min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;
        long long ans = right;
        while(left <= right)
        {
            long long mid = left + (right-left)/2;
            long long numCars = carsRepaired(ranks, mid);
            if(numCars >= (long long)cars)
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
};
