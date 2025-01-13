//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        vector<int> nums;
        for(int i = 0; i<=n; i++)
        {
            nums.push_back(i);
        }
        int left = 0;
        int right = n-1;
        int ans;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(mid*mid<=n)
            {
                ans = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
