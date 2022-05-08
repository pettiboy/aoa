//dynamic programming
//longest common subsequence
// The longest common subsequence in C++

#include <bits/stdc++.h>
using namespace std;

void lcs(char *S1, char *S2, int m, int n) {
    //making lcs_table
    int lcs_table[m + 1][n + 1];
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
            lcs_table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
            lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
            else
            lcs_table[i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);
        }
    }
    //printing lcs table
    cout << "LCS TABLE : "<<endl;
    for (int i =0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << lcs_table[i][j] << " ";
        }
        cout << endl;
    }
    //finding out lcs from table
    int index = lcs_table[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (S1[i - 1] == S2[j - 1]) 
        {
            lcs[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (lcs_table[i - 1][j] > lcs_table[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcs << "\n";
}

int main() {
    char S1[] = "ACADBABCBABC";
    char S2[] = "CBDAABCA";
    int m = strlen(S1);
    int n = strlen(S2);

    lcs(S1, S2, m, n);
}