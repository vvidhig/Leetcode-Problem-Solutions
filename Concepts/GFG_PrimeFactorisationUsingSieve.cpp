//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        vector<bool> isPrime(N+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int p = 2; p*p<=N; p++)
        {
            if(isPrime[p]==true)
            {
                for(int m = p*p; m<=N; m+=p)
                {
                    isPrime[m] = false;
                }
            }
        }
        vector<int> res;
        for(int i = 2; i*i<=N; i++)
        {
            while(isPrime[i]==true && N%i==0)
            {
                res.push_back(i);
                N = N/i;
            }
        }
        if(N > 1)
        {
            res.push_back(N);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
