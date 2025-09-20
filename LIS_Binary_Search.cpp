#include<iostream>
#include<vector>
using namespace std;

int lowerBound(vector<int>& temp,int x) // return the first index of the arr whose value is equal to or greater than x
{
  int low = 0;
  int high = temp.size()-1;

  while(low <= high)
  {
    int mid = low + (high - low)/2;
    if(temp[mid] >= x)
    {
        high = mid-1; //look for even smaller value
    }
    else
    {
        low = mid+1; // look for larger values
    }
  }
  return low;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1; i<n; i++)
    {
        if(arr[i] > temp.back())
        temp.push_back(arr[i]);
        else
        {
            int ind = lowerBound(temp,arr[i]);
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}

int main()
{
    int arr[] = {5,4,11,1,16,8};
    cout<<longestIncreasingSubsequence(arr,6);
    return 0;
}