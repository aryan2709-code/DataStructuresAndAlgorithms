#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;
    // Take two pointers
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

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

    // Copy the elements from this temp array to the actual array
    for(int i=low; i<=high; i++)
    {
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int>& arr,int low, int high)
{

    if(low >= high)
    return;

  int mid = low + (high - low) / 2;
  // Call the same algorithm on both the halves
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