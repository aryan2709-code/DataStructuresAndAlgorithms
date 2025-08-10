#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
    // Left part [low ----- mid] Right Part [mid+1 ----- high]
    int left = low;
    int right = mid+1;

    vector<int> temp;

    while(left <= mid && right <= high)
    {
          if(arr[left] <= arr[right])
          {
            temp.push_back(arr[left]);
            left++;
          }
          else // arr[left] > arr[right]
          {
            temp.push_back(arr[right]);
            right++;
          }
    }
    // Either the left portion or the right portion will have remaining elements
    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Now copy the elements from left to right
    copy(temp.begin(),temp.end(),arr.begin()+low);
    // temp.begin() -> Iterator pointing to the first element in the range you want to copy from
    // temp.end() -> Iterator pointing one past the last element in the range you want to copy from
    // arr.begin() + low -> The Destination where you want the elements to get copied 
}

void mergeSort(vector<int>& arr, int low, int high)
{
    if(low >= high)
    return;

    int mid = low + (high - low) / 2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    vector<int> arr = {7,6,1,5,3,2,4};
    mergeSort(arr,0,arr.size()-1);
    // print the array
    cout << "The sorted sequence is : ";
    for(int num:arr)
    cout << num << " ";

    return 0;
}