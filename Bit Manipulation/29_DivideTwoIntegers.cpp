class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if(dividend == divisor)
            return 1;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        bool sign = (dividend<0 == divisor<0); //true is positive - false is negative
        int ans = 0;
        while(a >= b)
        {
            int q = 0;
            while(a > (b<<(q+1)))
            {
                q+=1;
            }
            ans += (1<<q);
            a -= (b<<q);
        }
         if(ans == (1<<31) and sign)   // if ans cannot be stored in signed int
            return INT_MAX;
        return sign ? ans : -ans;
    }
};
