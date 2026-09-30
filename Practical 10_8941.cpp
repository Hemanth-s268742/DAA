#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int parent[10];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return find(parent[x]);
}

void unite(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootB] = rootA;
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[20];

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges according to weight
    sort(edges, edges + e, [](Edge a, Edge b)
    {
        return a.weight < b.weight;
    });

    // Initially every vertex is its own parent
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int rootU = find(edges[i].u);
        int rootV = find(edges[i].v);

        // Add edge only if it does not form a cycle
        if (rootU != rootV)
        {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unite(rootU, rootV);

            count++;
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}