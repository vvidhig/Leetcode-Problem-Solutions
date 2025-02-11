//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    vector<int> merger(vector<int>arr1, vector<int>arr2)
    {
        int i = 0, j = 0, A = arr1.size(), B = arr2.size();
        vector<int> arr;
        while(i<A && j<B)
        {
            if(arr1[i]<=arr2[j])
            {
                arr.push_back(arr1[i++]);
            }
            else
            {
                arr.push_back(arr2[j++]);
            }
        }
        while(i<A)
        {
            arr.push_back(arr1[i++]);
        }
        while(j<B)
        {
            arr.push_back(arr2[j++]);
        }
        return arr;
    }
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        if(K==1)
        {
            return arr[0];
        }
        if(K==2)
        {
            return merger(arr[0], arr[1]);
        }
        vector<int> res = merger(arr[0], arr[1]);
        for(int i = 2; i<K; i++)
        {
            res = merger(res, arr[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends
