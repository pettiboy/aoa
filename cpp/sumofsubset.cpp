#include <bits/stdc++.h>
using namespace std;
static int total_nodes;
void printValues(int A[], int size){
   for (int i = 0; i < size; i++) {
      cout << A[i] << " ";
   }
   printf("\n");
}
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
   total_nodes++;
   if (target_sum == sum) {
        cout << "Subset : ";
        printValues(t, t_size);
        subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
   }
   else {
    for (int i = ite; i < s_size; i++) {   //backtracking
        t[t_size] = s[i]; 
        subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
      }
   }
}
void generateSubsets(int s[], int size, int target_sum){
   int* tuplet_vector = (int*)malloc(size * sizeof(int));
   subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
   free(tuplet_vector);
}
int main(){
    int size,ele;
    cout << "Enter the size of the set : ";
    cin >> size;
    int set[size];
    cout << "Enter the elements of the set : ";
    for (int i=0;i<size;i++){
        cin >> set[i];
    }
    int target_sum;
    cout << "Enter the target Sum ";
    cin >> target_sum;
    cout << "The set is ";
    printValues(set , size);
    generateSubsets(set, size, target_sum);
    cout << "Total Nodes generated : " << total_nodes;
    return 0;
}