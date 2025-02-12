//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i<N; i++)
        {
            minHeap.push({arr[i], i});
        }
        int rank = 1;
        int prev = -1;
        vector<int> rankarr(N);
        while(!minHeap.empty())
        {
            pair<int, int> topElement = minHeap.top();
            int val = topElement.first;
            int idx = topElement.second;
            minHeap.pop();
            if(val != prev)
            {
                prev = val;
                rankarr[idx] = rank++;
            }
            else
            {
                rankarr[idx] = rank-1;
            }
        }
        return rankarr;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
