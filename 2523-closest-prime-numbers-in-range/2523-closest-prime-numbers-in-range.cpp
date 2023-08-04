class Solution {
public:
    vector<int> closestPrimes(int left, int right) 
    {
        vector<bool>isPrime(right + 1, true); //Sieve of Eratosthenes
        isPrime[1] = false;
        vector<int>primes;
        for (int num = 2; num * num <= right; num++)
        {
            if (isPrime[num])
            {
                for (int j = num * num; j <= right; j = j + num) isPrime[j] = false;
            }
        }
        //==============================================================================================
        for (int i = left; i <= right; i++)  //push all the prime numbers in "primes" array
        {
            if (isPrime[i]) primes.push_back(i);  
        }
        //==================================================================================================
        int mnDiff = INT_MAX;
        int leftAns = -1, rightAns = -1;
        for (int i = 0; primes.size() != 0 && i < primes.size() - 1; i++) //check for minimum difference between consecutive primes
        {
            int diff = primes[i + 1] - primes[i];
            if (diff < mnDiff)
            {
                mnDiff = diff;
                leftAns = primes[i];
                rightAns = primes[i+1];
            }
            
        }
        //===================================================================================================
        if (leftAns != -1 && rightAns != -1) return {leftAns, rightAns};
        else return {-1, -1};
    }
};