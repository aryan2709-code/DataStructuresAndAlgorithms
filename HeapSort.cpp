#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& nums, int index, int size)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < size && nums[left] > nums[largest])
    largest = left;
    if(right < size && nums[right] > nums[largest])
    largest = right;

    if(largest != index)
    {
        swap(nums[largest],nums[index]);
        heapify(nums,largest,size);
    }
}
void heapSort(vector<int>& nums)
{
   int n = nums.size();
   // Step 1 : Build the max heap out of this unsorted array
   // Consider nums as the unsorted array space , now we have to convert this to a max heap
   // In the Step-Down or sift-down or the heapify approach, we start from the first non-leaf element of the complete binary tree
   // representing the heap and try to fit them in their correct position
   // First non-leaf node is n/2 - 1
   for(int i = n/2 - 1; i>=0; i--)
   {
     heapify(nums,i,n);
   }

   // Step 2:
   // In the max-Heap the root element is always the greatest
   // Swap the root element with the last element of the heap space, now move the last element from the heap space to the sorted
   // space. The heap space is reduced by 1.
   // Now heapify the newly swapped root to its correct position so that the root again starts holding the greatest element of the
   // heap space
   // Continue the above process until the heap space size becomes 1

   for(int i = n-1; i>0; i--) // i represents the size of the heap space after moving the root to the sorted space
   {
      swap(nums[0],nums[i]);

      heapify(nums,0,i);
   }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array:   ";
    for (int i : arr) cout << i << " ";
    cout << endl;
}