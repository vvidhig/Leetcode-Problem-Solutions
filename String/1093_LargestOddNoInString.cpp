class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.length()-1;
        while(i>=0)
        {
            int ch = num[i] - '0';
            if(ch%2==0)
            {
                i--;
                continue;
            }
            else
            {
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
