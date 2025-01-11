class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        result.push_back(intervals[0]);
        vector<int> last;
        vector<int> current;
        int k = 0;
        for(int i = 1; i<n; i++)
        {
            last = result.back();
            if(last[1]>=intervals[i][0])
            {
                int max1 = max(last[1], intervals[i][1]);
                current = {last[0], max1};
                result.pop_back();
                result.push_back(current);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
