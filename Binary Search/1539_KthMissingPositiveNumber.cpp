class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int mid, missing;
        while(left<=right)
        {
            mid = (left+right)/2;
            missing = arr[mid] - mid - 1;
            if(missing < k)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }  
        return right+1+k;      
    }
};
