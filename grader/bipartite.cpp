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

void clear_adjacency()
{
    for (int i = 0; i < n_edges; i++)
    {
        adjacency[i].clear();
    }
}

void print_adjacency(vector<int> adjacency[], int n_nodes)
{
    for (int node = 0; node < n_nodes; node++)
    {
        cout << "adjacency: " << node << ", contain: [";
        for (int each_node = 0; each_node < adjacency[node].size(); each_node++)
        {
            cout << adjacency[node][each_node] << ", ";
        }
        cout << ']' << endl;
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

bool find_member(vector<int> vector, int value)
{
    for (auto i = vector.begin(); i != vector.end(); i++)
    {
        int u = *i;
        if (u == value)
        {
            return true;
        }
    }
    return false;
}

bool bfs(int s)
{
    vector<int> last_layer;
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
            // cout << "visite: " << u << ",layer: " << layer[u] << endl;

            // iterate over nodes in adjacency[u]
            for (int d = 0; d < degree[u]; d++)
            {
                int v = adjacency[u][d];

                // ad "new" nodes to the next layer
                if (layer[u] == layer[v])
                {
                    return false;
                }
                if (!seen[v])
                {
                    next_layer.push_back(v);
                    seen[v] = true;
                    layer[v] = layer[u] + 1;
                }
                // if (seen[v])
                // {
                //     return false;
                // }
            }
        }

        if (next_layer.size() == 0)
        {
            break;
        }
        current_layer = next_layer;
        next_layer.clear();
    }
    return true;
}

int main()
{
    int rounds;
    cin >> rounds;
    while (rounds--)
    {
        bool state = true;
        read_input();
        init_bfs();

        // print_adjacency(adjacency, n_nodes);
        state = bfs(0);
        if (state)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        clear_adjacency();
    }
}