#include<iostream>
using namespace std;

// Using Euclidean theorem to find out the gcd of two numbers 
// gcd(a,b) => if a > b => gcd(a-b,b) else if b > a => gcd(a,b-a) => Continue this process until one of them becomes zero, the other non zero number
// is the required gcd
// To improve time complexity, instead of repeated subtractions, we can take modulus operation

int gcd(int a , int b)
{
    while(a > 0 && b > 0)
    {
        if(a >= b)
        a = a % b;
        else
        b = b % a;
    }
    if(a == 0)
    return b;

    return a;
}

int main()
{
    cout << gcd(4,18)<<endl;
    cout << gcd(4,7)<<endl;
    cout << gcd(14,77)<<endl;
    return 0;
}