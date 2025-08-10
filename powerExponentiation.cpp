#include<iostream>
using namespace std;

double myPow(double x, int n)
{
    long long N = n;

    // Handle negative powers first
    if(n < 0)
    {
        x = 1/x;
        N = -N;
    }

    double result = 1.0;
    while(N > 0)
    {
        if(N % 2 == 1)
        {
            result = result * x;
        }

        x = x * x;
        N = N / 2;
    }

    return result;
}

int main()
{
    cout << myPow(3.5,4);
    return 0;
}