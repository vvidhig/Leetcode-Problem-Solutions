class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        int height, width;
        for(int i = 0; i<=heights.size(); i++)
        {
            while(!st.empty() && (i==heights.size() || heights[st.top()] >= heights[i]))
            {
                height = heights[st.top()];
                st.pop();
                if(st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i-st.top()-1;
                }
                res = max(res, height*width);
            }
            st.push(i);
        }
        return res;
    }
};
