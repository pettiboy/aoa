#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int n,int arr[])
{
    int min_index;
    for (int i=0;i < n-1;i++)
    {
        min_index=i;
        for (int j=i+1 ;j < n;j++)
        {   
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp;
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Original Array: " << endl;
    for (int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    SelectionSort(n,arr);
    cout << "Selection Sort" << endl;
    for (int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
}

