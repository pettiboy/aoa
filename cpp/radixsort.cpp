#include <bits/stdc++.h>
using namespace std;

void radix(int a[],int n,int place_value) 
{
    int bucket[50][10],count[10],digit,exp=1,col;
    for (int k = 1;k<=place_value;k++)
    {
        for (int i=0;i<=9;i++)
        {
            count[i] = -1; //count arry is initialised as -1
        }
        for(int i=0;i<=n;i++)  //count array ka code
        {
            int row;
            digit = (a[i]/exp) % 10;
            count[digit]++;
            row = count[digit];
            col = digit;
            bucket[row][col] = a[i];
        }
        int i=0;
        for (col = 0;col <= 9;col++) //significant digits ke acc buckets mai dalne wala code
        {
            if(count[col]!= -1)
            {
                for(int row = 0;row<=count[col];row++)
                {
                    a[i] = bucket[row][col];
                    i++;
                }
            }
        }
        exp = exp*10;
    }
}

int main(){
    int a[50] , n,i;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter elements: ";
    for(i = 0;i<n;i++){
        cin >> a[i];
    }
    radix(a,n,4);
    cout << "Sorted Elements: ";
    for(i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}