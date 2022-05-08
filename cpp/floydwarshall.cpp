#include <bits/stdc++.h>
#define INF 9999
using namespace std;
typedef vector<vector<int>> int_matrix;
typedef vector<int> int_row;
void floydWarshal(int_matrix& graph, int_matrix& shortestPath) 
{
    shortestPath.insert(shortestPath.end(), graph.begin(), graph.end());
    int V = graph.size();
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][k] + shortestPath[k][j]);
}
void displaygraph(int_matrix graph) {
    for (int i=0;i<graph.size();i++){
        for (int j=0;j<graph[i].size();j++){
            cout << "Shortest Path from " <<i << " to "<< j <<" is " << graph[i][j];
            cout << endl;
        }
    }
}
int main() {
    int_matrix graph;
    graph.push_back(int_row{0, 3, INF, 5});
    graph.push_back(int_row{2, INF, INF, 4});
    graph.push_back(int_row{INF, 1, 0, INF});
    graph.push_back(int_row{INF, INF, 2, 0});
    int_matrix shortestPath;
    floydWarshal(graph, shortestPath);
    cout << "The shortest path matrix is: " << endl;
    displaygraph(shortestPath);
    return 0;}