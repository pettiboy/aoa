#include <bits/stdc++.h>
using namespace std;
int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
	int cost[n][n];
	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];
	for (int k = 2; k <= n; k++)
	{
		for (int i = 0; i <= n-k+1; i++)
		{
			int j = i+k-1;
			cost[i][j] = INT_MAX;
			for (int r = i; r <= j; r++)
			{
				int c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + sum(freq, i, j);
				if (c < cost[i][j])
					cost[i][j] = c;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
	cout << cost[0][n-1];
	return 0;
}

void pairsort(int a[],int b[],int n)
{
	pair<int,int> pair1[n];
	for (int i=0;i<n;i++)
	{
		pair1[i].first = a[i];
		pair1[i].second = b[i];
	}
	sort(pair1,pair1+n);
	for (int i=0;i<n;i++)
	{
		a[i] = pair1[i].first;
		b[i] = pair1[i].second;
	}
}
int main()
{
	int keys[] = {10, 12};
	int freq[] = {34, 50};
	int n = sizeof(keys)/sizeof(keys[0]);
	pairsort(keys,freq,n);
	cout << "OBST TABLE" << endl;
	optimalSearchTree(keys, freq, n);
	return 0;
}

