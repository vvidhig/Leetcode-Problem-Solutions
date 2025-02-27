class Solution {
private:
    string res;
    bool backtrack(unordered_set<string>& s, string& curr, int n)
    {
        if(curr.length()==n)
        {
            if(s.find(curr) == s.end())
            {
                res = curr;
                return true;
            }
            else
            {
                return false;
            }
        }
        for(char ch : {'0', '1'})
        {
            curr.push_back(ch);
            backtrack(s, curr, n);
            curr.pop_back();
        }
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        string curr = "";
        backtrack(st, curr, n);
        return res;
    }
};
