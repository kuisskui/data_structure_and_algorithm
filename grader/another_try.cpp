#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n_nodes;
int n_distance;
const int MAX_NODES = 1010;
vector<int> adjacency[MAX_NODES];
int degree[MAX_NODES];

struct Node
{
    int x;
    int y;
};
Node all_nodes[MAX_NODES];
void print_all_nodes(int n_nodes)
{
    for (int node = 0; node < n_nodes + 2; node++)
    {
        cout << "Node: " << node << ", (x, y) = (" << all_nodes[node].x << ", " << all_nodes[node].y << ')' << endl;
    }
}
void read_input()
{
    cin >> n_nodes >> n_distance;
    all_nodes[0].x = 0;
    all_nodes[0].y = 0;
    for (int node = 1; node < n_nodes + 1; node++)
    {
        cin >> all_nodes[node].x;
        cin >> all_nodes[node].y;
    }
    all_nodes[n_nodes + 1].x = 100;
    all_nodes[n_nodes + 1].y = 100;
}
int find_distance(Node first_node, Node last_node)
{
    int x_difference, y_difference;
    x_difference = abs(first_node.x - last_node.x);
    y_difference = abs(first_node.y - last_node.y);
    return sqrt(pow(x_difference, 2) + pow(y_difference, 2));
}
void create_adjacency(Node *all_nodes, int n_nodes)
{
    for (int node = 0; node < n_nodes + 2; node++)
    {
        for (int next_node = node + 1; next_node < n_nodes + 2; next_node++)
        {
            if (find_distance(all_nodes[node], all_nodes[next_node]) <= n_distance)
            {
                adjacency[node].push_back(next_node);
                adjacency[next_node].push_back(node);
                degree[node]++;
                degree[next_node]++;
            }
        }
    }
}
void print_adjacency(vector<int> adjacency[], int n_nodes)
{
    for (int node = 0; node < n_nodes + 2; node++)
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

void bfs(int s, int *counter)
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
            // cout << "visite: " << u << ",layer: " << layer[u] << endl;
            *counter = layer[u];

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

void init_bfs()
{
    for (int u = 0; u < n_nodes; u++)
    {
        layer[u] = -1;
        seen[u] = false;
    }
}

int main()
{
    read_input();
    // print_all_nodes(n_nodes);
    create_adjacency(all_nodes, n_nodes);
    // print_adjacency(adjacency, n_nodes);
    init_bfs();
    int counter = 0;
    for (int i = 0; i < n_nodes; i++)
    {
        if (!seen[i])
        {
            bfs(i, &counter);
        }
    }
    cout << counter;

    return 0;
}



int main()
{
    for (int i = 0; i < n_nodes;i++)
}
