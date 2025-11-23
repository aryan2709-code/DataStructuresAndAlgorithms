#include <iostream>
using namespace std;


/*
Information about heaps:

-> A Heap is a complete binary tree
-> All levels are completely filled except the last level.
-> At the last level, the nodes should be filled from left to right
-> Max Heap: Parent node should be greater than or equal to child node (For every node)
-> Min Heap: Parent node should be less than or equal to its child node

-> Implementation through linked list:
-> Linked list implementation has these shortcomings:
-> Finding the node where the node will be inserted O(n)
-> Maintaining the heap property
-> These shortcomings make it very cumbersome to implement a heap using linked list

-> Implementation through array:

-> Parent Index : i 
-> Left Child : 2 * i + 1
-> Right Child: 2 * i + 2

->Child Index: i
-> Parent Index: (i-1)/2

-> Every new element is inserted at the end of the array, then we compare it with its parent node, if the heap property follows,
then it's ok else we swap it with the parent element and continue the process till the newly inserted node is in its correct
position

-> Time complexity of the creation(Insertion) of heap:

-> Approach 1 :
-> The Standard or naive way to create a heap from a given list of n elements is to
-> take an empty heap and insert elements one by one
-> Since there are n elements and each insertion takes logn time in bubbling the element upwards in its
-> correct position, the time complexity will be nlogn

-> Approach 2:
(Heapify approach)
-> This method involves taking an entire unsorted array and treating it as an unsorted array and fixing it from the bottom-up
-> The fixing involves starting from the last non-leaf node and work backward to the root calling heapify or sift-down function on
   each of the nodes
-> This takes o(n) time because: Heapify takes logn time
-> The leaves (50% of the nodes) don't move at all, they are at the bottom already
-> The above level (25% of the nodes) move at most 1 step
-> Only the root (1 node) moves for logn height (the entire height of the complete binary tree)
-> Because the vast majority of the data lies in the bottom of the tree, where the work is zero or cheap, the total work sums
-> up to O(n) despite heapify taking O(logn) time

-> Deletion of element in a Heap:
-> We only talk about the root node when talking about deletion
-> The root node is deleted and then replaced with the last node of the heap, to maintain the complete binary tree property
-> Now this newly replaced root node is adjusted from top to bottom using sift-down or heapify operation
-> This takes O(logn) time
*/


class MaxHeap {
public:
    int* arr;
    int size;       // Current elements in the heap
    int total_size; // Max capacity of the array

    // Constructor
    MaxHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // DESTRUCTOR (New addition)
    // This automatically cleans up memory when the class is destroyed
    ~MaxHeap() {
        delete[] arr;
        cout << "Memory freed successfully.\n";
    }

    void insert(int value) {
        if (size == total_size) {
            cout << "Heap overflow \n";
            return;
        }
        
        arr[size] = value;
        int index = size;
        size++;

        // Bubble up (Compare with parent)
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        
        // Added a space before "is inserted" for cleaner output
        cout << arr[index] << " is inserted into the heap\n";
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Check if left child exists and is greater than root
        if (left < size && arr[left] > arr[largest])
            largest = left;
        
        // Check if right child exists and is greater than largest so far
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void Delete() {
        if (size == 0) {
            cout << "Heap Underflow \n";
            return;
        }
        
        cout << arr[0] << " deleted from the heap \n";
        
        // Replace root with last element
        arr[0] = arr[size - 1];
        size--;

        if (size > 0) {
            heapify(0);
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver Code to test your logic
int main() {
    MaxHeap h(10); // Create a heap of size 10

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    cout << "Current Heap: ";
    h.print();

    h.Delete(); // Should delete 55 (the max)

    cout << "After Deletion: ";
    h.print();

    return 0;
}