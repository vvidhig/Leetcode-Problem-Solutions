class Solution {
public:
    int maxAreaHistogram(vector<int> heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxarea = 0;
        for(int i = 0; i<=n; i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.top() - 1;
                }
                maxarea = max(maxarea, height*width);
            }
            st.push(i);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0, area = 0;
        vector<int>dp(m, 0);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[j]+=1;
                }
                else
                {
                    dp[j]=0;
                }
            }
            area = maxAreaHistogram(dp);
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};
