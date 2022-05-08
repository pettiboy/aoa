#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> int_matrix;
typedef vector<int> int_row;
typedef vector<int> int_column;

void displayMatrix(int_matrix& matrix) {
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[i].size();j++) 
            cout << matrix[i][j] << "    ";
            cout << endl;
    }
}
int TSP(set<int>& nodes, int_matrix& dist, int source) {
    if (nodes.size() == 1)
        return dist[source][*(nodes.begin())];
    else {
        vector<int> costs;
        for(set<int>::iterator node = nodes.begin(); node != nodes.end(); node++) {
            set<int> subsetOfNodes = nodes;
            subsetOfNodes.erase(*node);
            costs.push_back(dist[source][*node] + TSP(subsetOfNodes, dist, *node));
        }
        return *min_element(costs.begin(), costs.end());
    }
}
int findTSPDistance(set<int>& nodes, int_matrix& dist, int source) {
    set<int> subsetOfNodes = nodes;
    subsetOfNodes.erase(source);
    return TSP(subsetOfNodes, dist, source);
}
int main() {
    set<int> nodes;
    nodes.insert(0);
    nodes.insert(1);
    nodes.insert(2);
    nodes.insert(3);

    int_matrix dist;
    dist.push_back(vector<int> ({0, 10, 15, 20}));
    dist.push_back(vector<int> ({5, 0, 9, 10}));
    dist.push_back(vector<int> ({6, 13, 0, 12}));
    dist.push_back(vector<int> ({8, 8, 9, 0}));

    displayMatrix(dist);

    cout << "The least cost is starting from node 1 is: " << findTSPDistance(nodes, dist, 0) << endl;
    cout << "The least cost is starting from node 2 is: " << findTSPDistance(nodes, dist, 1) << endl;
    cout << "The least cost is starting from node 3 is: " << findTSPDistance(nodes, dist, 2) << endl;
    cout << "The least cost is starting from node 4 is: " << findTSPDistance(nodes, dist, 3) << endl;

    return 0;
}