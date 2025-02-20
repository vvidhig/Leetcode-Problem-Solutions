class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==0)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int N = intervals.size();
        int cnt = 0;
        vector<int> prev = intervals[0];
        for(int i = 1; i<N; i++)
        {
            vector<int> curr = intervals[i];
            if(prev[1]>curr[0])
            {
                cnt++;
                prev[1] = min(prev[1], curr[1]);
            }
            else
            {
                prev = curr;
            }
        }
        return cnt;
    }
};
