//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        i = i-1;
        int n1 = (num >> i)&1;
        int n2 = num|(1 << i);
        int n3 = num&~(1 << i);
        cout<<n1<<" "<<n2<<" "<<n3;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
