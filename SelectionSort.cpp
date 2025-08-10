#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*The intuition behind selection sort is selecting the minimum element out of the unsorted array and then swapping it to bring it at its correct index*/

void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    // n-1 iterations
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i; j<n; j++)
        {
           if(arr[j] < arr[minIndex])
           {
            minIndex = j;
           }
        }
        // After Inner iteration is complete, swap it with the current Index
        swap(arr[i],arr[minIndex]);
    }
}

int main()
{
    vector<int> arr = {7,1,5,3,4};
    selectionSort(arr);
    for(int num:arr) cout << num << " ";
    return 0;
}