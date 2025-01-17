class Solution {
    
public:
    long long max = pow(2,31)-1;
    int myAtoi(string s) {
        string str;
        bool isPos = true,isNumStarted = false;
        long long res = 0;
        for(auto &ch : s){
            
            if(isdigit(ch)){
                if(!isNumStarted)
                    isNumStarted = true;
                res =  res* 10 + (ch-'0');    
            }
            else if(!isNumStarted && (ch==' '||ch=='+')){
                if(ch=='+')
                    isNumStarted = true;
                continue;
            }
            else if(ch=='-' && !isNumStarted){
                isNumStarted = true;
                isPos = false;
            }
            else
                break;
            if( res > max)
                return isPos ? max : -1*(max+1);
        }
        
        if(!isPos)
            return -1*res;
        return res;
    }
};
