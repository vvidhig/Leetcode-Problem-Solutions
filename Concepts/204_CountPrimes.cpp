class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
        {
            return 0;
        }
        vector<bool> isPrime(n,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int p=2; p*p<n; p++)
        {
            if(isPrime[p]==true)
            {
                for(int m = p*p; m<n; m+=p)
                {
                    isPrime[m] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};
