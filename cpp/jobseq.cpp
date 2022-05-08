#include <bits/stdc++.h>
using namespace std;
struct Job{
  char id;
  int deadline;
  int profit;
};

bool comparison(Job a, Job b){
    return (a.profit > b.profit);
}

void jobsequencing(Job arr[],int n)
{
    sort(arr,arr+n,comparison);
    int result[n];
    int slot[n];
    for (int i=0;i<n;i++)
    {
     slot[i] = false;   
    }
    for(int i=0;i<n;i++)
    {
        for (int j=min(n,arr[i].deadline);j>=0;j--)
        {
           if (slot[j] == false)
            {
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if (slot[i])
            cout << arr[result[i]].id << " ";
    }
}

int main()
{
    Job arr[] = {{'a',1,12},
                {'b',2,10},
                {'c',3,8},
                {'d',4,9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    jobsequencing(arr,n);
}