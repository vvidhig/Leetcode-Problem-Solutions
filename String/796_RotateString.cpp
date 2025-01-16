class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n!=m)
        {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};
