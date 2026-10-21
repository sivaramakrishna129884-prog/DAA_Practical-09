#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10], visited[10] = {0};
    int edges = 0, minCost = 0;
    int min, u = 0, v = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    visited[0] = 1;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        min = 9999;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (min == 9999) {
            cout << "Graph is disconnected";
            return 0;
        }

        cout << u << " - " << v
             << " : " << min << endl;

        minCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "Minimum Cost: " << minCost;

    return 0;
}
