#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int mid,int lb,int ub)
{
    int n1 = mid - lb + 1;
    int n2 = ub - mid;
    int L[n1],R[n2];
    for (int i = 0;i < n1; i++)
    {
        L[i] = arr[lb + i];
    }
    for (int j = 0;j < n2; j++)
    {
        R[j] = arr[mid + 1 +j];
    }
    int i=0;
    int j=0;
    int k=lb;
    while(i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int lb,int ub)
{
    if(lb < ub){
        int mid = (lb + ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    mergesort(arr,0,n-1);
    cout << "Sorted array: ";
    for(int i = 0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}