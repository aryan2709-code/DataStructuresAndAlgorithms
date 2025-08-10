#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    // The idea behind insertion sort is to insert an element at its correct position
    for(int i=0; i<n; i++)
    {
        int j = i;
        while(j>0 && arr[j]<arr[j-1]) // An element at bigger index is having a smaller value than an element at a smaller index
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        // If this loop stops then the element is at its correct position as of now, considering the elements in the sorted part
    }

    cout << "The sorted sequence is : "<<endl;
    for(int num:arr)
    cout<<num<<" ";
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    insertionSort(arr);
    return 0;
}