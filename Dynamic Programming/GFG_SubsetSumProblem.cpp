//Brute Force
class Solution {
  private:
    void findSubSequence(int idx, vector<int>& arr, vector<int>& subSeq, bool& isSum, int& sum)
    {
        if(idx >= arr.size())
        {
            int s = accumulate(subSeq.begin(), subSeq.end(),0);
            if(s==sum)
            {
                isSum = true;
            }
            return;
        }
        subSeq.push_back(arr[idx]);
        findSubSequence(idx+1, arr, subSeq, isSum, sum);
        subSeq.pop_back();
        findSubSequence(idx+1, arr, subSeq, isSum, sum);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<int> subSeq;
        bool isSum = false;
        findSubSequence(0, arr, subSeq, isSum, sum);
        return isSum;
        
    }
};
// Tabulation Optimised
class Solution {
  private:
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i = 0; i<n; i++)
        {
            dp[i][0] = true;
        }
        if(arr[0]<=sum)
        {
            dp[0][arr[0]] = sum;
        }
        for(int i = 1; i<n; i++)
        {
            for(int j = 1; j<=sum; j++)
            {
                bool notTaken = dp[i-1][j];
                bool taken = false;
                if(arr[i]<=j)
                {
                    taken = dp[i-1][j - arr[i]];
                }
                dp[i][j] = notTaken || taken;
            }
        }
        return dp[n-1][sum];
    }
};
