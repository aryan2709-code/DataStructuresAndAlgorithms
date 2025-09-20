#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    // dp[i] signifies the longest increasing subsequence that ends at index i
    int maxi = 1;
    for(int i=0; i<n; i++)
    {
        for(int prev = 0; prev<i; prev++)
        {
            if(arr[prev] < arr[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    return maxi;
}

// Time complexity of this method is O(n**2)

int main()
{
    int arr[] = {5,4,11,1,16,8};
    int ans = longestIncreasingSubsequence(arr,6);
    cout << ans << endl;
    return 0;
}

