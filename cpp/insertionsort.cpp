#include <bits/stdc++.h>
using namespace std;

void printarr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionsort(int arr[],int size){
    for (int i = 1;i<size;i++)
    {
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > temp){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}
int main(){
    int n;
    cout << "Enter the number of the elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Original Array : " <<endl; 
    printarr(arr,n);
    insertionsort(arr,n);
    cout << "Sorted Array : " << endl;
    printarr(arr,n);
}