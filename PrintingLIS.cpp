#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> printLIS(int arr[], int n)
{
 if(n == 0) return {};
 vector<int> dp(n,1); // dp[i] signifies the length of the longest increasing subsequence ending at index i
 vector<int> hash(n,1); // hash array is used to trace the path
 for(int i=0; i<n; i++) hash[i] = i;
 int maxLengthIndex = -1;
 int maxi = 1;
 for(int i=0; i<n; i++)
 {
    for(int prev=0; prev<i; prev++)
    {
        if(arr[prev] < arr[i])
        {
            if(1 + dp[prev] > dp[i])
            {
                // Update dp[i]
                dp[i] = 1 + dp[prev];
                hash[i] = prev; // For tracing the path
            }
        }
        if(dp[i] > maxi)
        {
            maxi = dp[i];
            maxLengthIndex = i;
        }
    }
 }

 // Now trace back the array
 if(maxi == 1) return {arr[0]};
 vector<int> ans;
 int index = maxLengthIndex;
 while(true)
 {
   ans.push_back(arr[index]);
   if(hash[index] == index)
   break;
   index = hash[index];
 }
 reverse(ans.begin(),ans.end());
 return ans;
}

int main()
{
    int arr[] = {};
    vector<int> ans = printLIS(arr,0);

    // Printing the LIS
    for(int x:ans) cout << x << " ";
    return 0;
}