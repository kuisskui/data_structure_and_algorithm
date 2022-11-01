#include <iostream>
#include <vector>

using namespace std;

int n_nodes, n_edges;
const int MAX_NODES = 100010;
vector<int> adjacency[MAX_NODES];
int degree[MAX_NODES];

int main()
{
    cin >> n_nodes >> n_edges;
    for (int i = 0; i < n_nodes; i++)
    {
        degree[i] = 0;
    }

    for (int i = 0; i < n_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adjacency[u].push_back(v);
        degree[u]++;
        adjacency[v].push_back(u);
        degree[v]++;
    }
}