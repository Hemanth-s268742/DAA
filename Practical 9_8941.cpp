#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int selected[10] = {0};
    selected[0] = 1;

    int edges = 0;
    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = 9999;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (selected[j] == 0 && graph[i][j] != 0)
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << min << endl;

        totalCost += min;
        selected[y] = 1;
        edges++;
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}