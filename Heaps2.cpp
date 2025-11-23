#include<iostream>
using namespace std;

/* 
Trying to Build a Heap using the step down or the Heapify or the sift-down approach
In this approach, we are given an array of elements before hand
We treat this entire unsorted array as a heap and start fixing it from the bottom to the root node
We start from the last non-leaf node and apply heapify on each one of these nodes

Important: the last non-leaf node is the (n/2 - 1)th node
*/

void heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < n && arr[left] > arr[largest])
    largest = left;
    if(right < n && arr[right] > arr[largest])
    largest = right;

    if(largest != index)
    {
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}

void printHeap(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BuildMaxHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i>=0; i--)
    heapify(arr,i,n);
}

int main()
{
    int arr[] = {52,54,53,50,55};
    printHeap(arr,5);
    BuildMaxHeap(arr,5);
    printHeap(arr,5);
    return 0;
}