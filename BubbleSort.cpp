#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<= i-1; j++)
        {
            if(arr[j] > arr[j+1]) // Smaller Index Element has a larger value
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "The sorted array sequence is as follows: "<<endl;
    for(int i=0; i<arr.size(); i++)
    cout<<arr[i] << " ";
}

int main()
{
    vector<int> arr =  {13, 46, 24, 52, 20, 9};
    bubbleSort(arr);
    return 0;
}

