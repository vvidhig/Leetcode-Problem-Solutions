class Solution {
public:
    string reverseWords(string s) {
       string word = "";
       string result = "";

       s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    // Remove trailing spaces
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());

       s += ' ';
       int n = s.length();
       for(int i = 0; i<n; i++)
       {
        char ch = s[i];
        if(ch!=' ')
        {
            word += s[i];
        }
        else if (s[i+1] != ' ')
        {
            result = word + " " + result;
            word = "";
        }
       }
       result = result.substr(0, result.length()-1);
       return result; 
    }
};
