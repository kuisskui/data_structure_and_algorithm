#include <iostream>
#include <vector>

using namespace std;

int n_nodes, n_edges;
const int MAX_NODES = 100010;
vector<int> adjacency[MAX_NODES];
int degree[MAX_NODES];

void read_input()
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

int layer[MAX_NODES];
bool seen[MAX_NODES];

void init_bfs()
{
    for (int u = 0; u < n_nodes; u++)
    {
        layer[u] = -1;
        seen[u] = false;
    }
}

void bfs(int s)
{
    vector<int> current_layer;
    vector<int> next_layer;

    current_layer.push_back(s);
    layer[s] = 0;
    seen[s] = true;

    while (true)
    {
        // look at all the nodes in current layer
        for (auto i = current_layer.begin(); i != current_layer.end(); i++)
        {
            int u = *i;
            cout << "visite: " << u << ",layer: " << layer[u] << endl;

            // iterate over nodes in adjacency[u]
            for (int d = 0; d < degree[u]; d++)
            {
                int v = adjacency[u][d];

                // ad "new" nodes to the next layer
                if (!seen[v])
                {
                    next_layer.push_back(v);
                    seen[v] = true;
                    layer[v] = layer[u] + 1;
                }
            }
        }

        if (next_layer.size() == 0)
        {
            break;
        }

        current_layer = next_layer;
        next_layer.clear();
    }
}

int main()
{
    read_input();
    int count = 0;
    for (int i=0;i<n_nodes;i++){
        if (!seen[i]){
            bfs(i);
            count++;
        }
    }
    cout << count;
}