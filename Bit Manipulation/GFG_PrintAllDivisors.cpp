//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        int k = sqrt(n);
        vector<int> arr;
        for(int i = 1; i<=k; i++)
        {
            if(n%i==0)
            {
                arr.push_back(i);
                if(i!=(n/i))
                {
                    arr.push_back(n/i);
                }
            }
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i<arr.size(); i++)
        {
            cout << arr[i] << " "; 
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
