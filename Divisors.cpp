#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printDivisors(int n)
{
    vector<int> divisors;
    for(int i=1; i * i <= n; i++) // Checking till the square root is enough
    {
      if(n % i == 0)
      {
        divisors.push_back(i);
        if(n / i != i)
        divisors.push_back(n/i);
      }
    }
    sort(divisors.begin(),divisors.end());
    for(auto num: divisors)
    cout << num << " ";
}

int main()
{
    printDivisors(36);
    return 0;
}