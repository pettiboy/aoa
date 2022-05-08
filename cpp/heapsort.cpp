#include <iostream>

using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapifyMax(int arr[], int size, int i) {
    int child[] = {2*i+1, 2*i+2};
    int childToSwap;
    if (child[0] < size) 
    {
        if (child[1] < size) 
        { // Both children exist
            childToSwap = arr[child[0]] > arr[child[1]] ? child[0] : child[1];
        }
        else 
        { // Single child exists
            childToSwap = child[0];
        }
        if (arr[childToSwap] > arr[i]) {
            swap(arr, i, childToSwap);
            heapifyMax(arr, size, childToSwap);
        }
    } else { // No child exists
        return;
    }
}

void buildMaxHeap(int arr[], int size) {
    for (int i = size; i >= 0; i--) {
        heapifyMax(arr, size, i);
    }
}

void heapSort(int arr[], int size) {
    buildMaxHeap(arr, size);
    for (int n = size; n > 1; n--) {
        swap(arr, 0, n-1);
        heapifyMax(arr, n-1, 0);
    }
}

int main() {
    int N;
    cout << "This program will demonstrate Heap Sort" << endl;
    cout << "Enter number of elements: ";
    cin >> N;

    int list[N];
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }

    heapSort(list, N);
    
    cout << "Sorted list: ";
    for (int i = 0; i < N; i++) {
        cout << list[i] << " ";
    }

    return 0;
}