#include <iostream>
#include <vector>
using namespace std;

int n_nodes, n_edges;
const int MAX_NODES = 110;
vector<int> adjacency[MAX_NODES];

int in_degree[MAX_NODES];
int out_degree[MAX_NODES];
vector<int> output;

void read_input()
{
    cin >> n_nodes >> n_edges;
    if ((n_nodes == 0) && (n_edges == 0))
        return;

    for (int i = 0; i < n_nodes; i++)
    {
        in_degree[i] = out_degree[i] = 0;
        adjacency[i].clear();
    }

    for (int i = 0; i < n_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adjacency[u].push_back(v);
        // cout << "push " << v + 1 << " in " << u + 1 << endl;
        out_degree[u]++;
        in_degree[v]++;
    }
}

void print_adjacecy()
{
    for (int i = 0; i < n_nodes; i++)
    {
        cout << "Node: " << i + 1 << " Contains : ";
        for (auto j = adjacency[i].begin(); j != adjacency[i].end(); j++)
        {
            cout << *j + 1 << ", ";
        }
        cout << endl;
    }
}

void topo_order()
{
    vector<int> s;

    output.clear();

    for (int u = 0; u < n_nodes; u++)
        if (in_degree[u] == 0)
            s.push_back(u);

    for (int i = 0; i < n_nodes; i++)
    {
        int u = s.back();
        s.pop_back();
        output.push_back(u);

        for (int d = 0; d < out_degree[u]; d++)
        {
            int v = adjacency[u][d];
            in_degree[v]--;
            if (in_degree[v] == 0)
            {
                s.push_back(v);
            }
        }
    }
}

int main()
{
    while (true)
    {
        read_input();
        if (n_nodes == 0 && n_edges == 0)
        {
            return 0;
        }
        topo_order();
        for (int i = 0; i < n_nodes; i++)
        {
            if (i == n_nodes - 1)
            {
                cout << output[i] + 1;
            }
            else
            {
                cout << output[i] + 1 << ' ';
            }
        }
        cout << endl;
    }
}