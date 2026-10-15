
#include <iostream>
using namespace std;

int main() {
    int n, cost[10][10], visited[10] = {0};
    int current = 0, totalCost = 0;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    visited[current] = 1;
    cout << "Path: " << current + 1;

    for (int count = 1; count < n; count++) {
        int next = -1, minCost = 99999;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && cost[current][j] < minCost) {
                minCost = cost[current][j];
                next = j;
            }
        }

        if (next == -1) {
            cout << "\nNo complete tour exists.\n";
            return 0;
        }

        visited[next] = 1;
        totalCost += minCost;
        current = next;

        cout << " -> " << current + 1;
    }

    if (cost[current][0] == 0) {
        cout << "\nNo return path to starting city.\n";
        return 0;
    }

    totalCost += cost[current][0];
    cout << " -> 1";
    cout << "\nMinimum cost (greedy tour): " << totalCost;

    return 0;
}
