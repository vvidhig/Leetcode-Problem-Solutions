class Solution {
  public:
    long long solve(vector<int>& bt) {
        long long avgwaitingtime = 0;
        long long waitingtime = 0;
        int n = bt.size();
        sort(bt.begin(), bt.end());
        for(int i = 0; i<n-1; i++)
        {
            waitingtime +=  bt[i];
            avgwaitingtime += waitingtime;
        }
        return (avgwaitingtime/n);
    }
};
