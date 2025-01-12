//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> result;
        int left = 0;
        int right = arr.size()-1;
        int high = -1;
        int low = -1;
        int mid;
        sort(arr.begin(), arr.end());
        while(left<=right)
        {
            mid = (left+right)/2;
            if(arr[mid]>x)
            {
                right = mid-1;
            }
            if(arr[mid]<=x)
            {
                low = mid;
                left = mid+1;
            }
        }
        if(low==-1)
            result.push_back(-1);
        else
            result.push_back(arr[low]);
        left = 0;
        right = arr.size()-1;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(arr[mid]>=x)
            {
                high = mid;
                right = mid-1;
            }
            if(arr[mid]<x)
            {
                left = mid+1;
            }
        }
        if(high==-1)
            result.push_back(-1);
        else
            result.push_back(arr[high]);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends
