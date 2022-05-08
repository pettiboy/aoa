#include <bits/stdc++.h>
using namespace std;
int main()
{
int n =15;
int arr[n],input,row,inv=0;
for (int i=1;i<=n;i++)
{
    cin >> arr[i];
    if(arr[i-1] == 0)
    {
        row = n -i + 1;
    }
}
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        if(i==0 && j==0 && arr[i]!= 0 && arr[j]!=0)
        {
            inv++;
        }
    }
}
cout << "Number of Inversions: " << inv <<endl;
if ((n%2==0 && inv%2==0) || (n%2==0 && inv%2==1 && row%2==0) || (n%2==0 && inv%2==0 && row%2==1))
{
    cout << "Solvable puzzle";
}
else
{
    cout << "Not Solvable Puzzle";
}
}
