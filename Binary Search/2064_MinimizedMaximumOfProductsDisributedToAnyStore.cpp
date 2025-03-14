class Solution 
{
private:
    bool canDistribute(vector<int>& quantities, int mid, int n)
    {
        int stores = 0;
        int len = quantities.size();
        for(int i = 0; i<len; i++)
        {
            stores += (quantities[i] + mid - 1) / mid;
        }
        return stores <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        while(left <= right)
        {
            int mid = (right+left)/2;
            if(canDistribute(quantities, mid, n))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
