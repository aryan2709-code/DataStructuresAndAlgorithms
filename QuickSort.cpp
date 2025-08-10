#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
        // Move i until we do not find an element that is larger than the pivot
        // Move j until we do not find an element that is equal to or smaller than the pivot,
        // J will track smaller and equal elements
        // if i < j , we will swap the elements present at these positions
        // Finally, we will swap the pivot element with the element at index j
        // j will also be our partition index as it is the correct sorted position of the pivot element, all the elements to the left of the
        // pivot are now smaller or equal and all the elements to the right of the pivot are larger than the pivot 
        // Return the partition index j
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low]; // We have picked the first element of the array as the pivot
    int i = low;
    int j = high;
    while(i < j)
    {
        while(i <= high-1 && arr[i] <= pivot)
        i++;

        while(j >= low+1 && arr[j] > pivot)
        j--;

        if(i < j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]); // Placing the pivot element at its correct Index
    return j;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
       int partitionIndex = partition(arr,low,high); // The pivot will be correctly placed, now perform the same process for the left and the 
       // right parts excluding the pivot 
       quickSort(arr,low,partitionIndex-1);
       quickSort(arr,partitionIndex+1,high);
    }
}

int main()
{
    vector<int> arr = {7,6,1,3,2,8,5,4};
    quickSort(arr,0,arr.size()-1);
    for(int num:arr)
    cout << num << " ";
    return 0;
}
