#include <bits/stdc++.h>
using namespace std;
struct Item {
	int profit, weight;
	Item(int profit, int weight): profit(profit), weight(weight){}
};
bool comparison(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / a.weight;
	double r2 = (double)b.profit / b.weight;
	return r1 > r2;
}
double fractionalKnapsack(struct Item arr[],int N, int size)
{
	sort(arr, arr + size, comparison);
	int currentweight = 0;
	double finalprofit = 0.0;
	for (int i = 0; i < size; i++) {
		if (currentweight + arr[i].weight <= N) 
        {
			currentweight += arr[i].weight;
			finalprofit += arr[i].profit;
		}
		else {
			int remain = N - currentweight;
			finalprofit += arr[i].profit* ((double)remain / arr[i].weight);
			break;
		}
	}
	return finalprofit;
}

int main()
{
	int N = 60;
	Item arr[] = { { 100, 10 },
				{ 280, 40 },
				{ 120, 20 },
				{ 120, 24 } };

	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum profit earned = " << fractionalKnapsack(arr, N, size);
	return 0;
}
