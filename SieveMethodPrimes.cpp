#include<iostream>
#include<vector>
using namespace std;

vector<int> findprimesBySieve(int n) // We can find which numbers are primes till the given n in O(1) through the sieve method
{
    vector<int> prime(n+1,1); // Initially all numbers will be marked as 1, at the end of the process, the numbers which retain these 
    // ones will be the prime numbers
    for(int i=2; i*i <= n; i++) // This loop will only run till the square root of n, because the inner loop begins from the sqaure of this index
    {
        if(prime[i] == 1) // if the current number is a prime, mark all the multiples as non prime
        {
           for(int j = i*i; j<=n; j += i) // For 2 - 2*2,2*3,2*4 till 2*18 in case of 36, For 3 - 3*3,3*4,--- till 3*12 in case of 36
           {
             prime[j] = 0;
           }
        }
    }
    return prime;
}


int main()
{
    vector<int> ans = findprimesBySieve(36);
    for(int i=2; i<ans.size(); i++)
    {
        if(ans[i] == 1)
        cout<< i << " ";
    }
    return 0;
}

// Time Complexity of this method is : O(NloglogN)