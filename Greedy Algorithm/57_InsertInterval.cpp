class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> res;
        int n = intervals.size();
        bool inserted = false;
        for(int i = 0; i<n; i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!inserted && start > newInterval[1])
            {
                res.push_back(newInterval);
                inserted = true;
            }
            if(end>=newInterval[0] && start<=newInterval[1])
            {
                newInterval[0] = min(start, newInterval[0]);
                newInterval[1] = max(end, newInterval[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        if(!inserted)
        {
            res.push_back(newInterval);
        }
        return res;
    }
};
