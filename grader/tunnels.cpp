#include <iostream>
#include <vector>

using namespace std;

int n_nodes, n_edges;
int start;
int target;
int power;

const int MAX_NODES = 3010;
vector<int> adjacency[MAX_NODES];

int layer[MAX_NODES];
int heights[MAX_NODES][MAX_NODES];
int my_heights;
int result = -1;
bool seen[MAX_NODES];

void read_input()
{
    cin >> n_nodes >> n_edges;
    // for (int i = 0; i < n_nodes; i++)
    // {
    //     degree[i] = 0;
    // }

    for (int i = 0; i < n_edges; i++)
    {
        int u, v, h;
        cin >> u >> v >> h;
        u--;
        v--;
        heights[u][v] = h;
        heights[v][u] = h;

        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
}

void clear_adjacency()
{
    for (int i = 0; i < n_edges; i++)
    {
        adjacency[i].clear();
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

void bfs(int s, int counter)
{
    if (s == target)
    {
        if (result == -1)
        {
            result = counter;
        }
        if (counter < result)
        {
            result = counter;
        }
        return;
    }
    layer[s] = counter;
    seen[s] = true;
    for (auto i = adjacency[s].begin(); i != adjacency[s].end(); i++)
    {
        if (my_heights <= heights[s][*i])
        {
            if (seen[*i] == false)
            {
                bfs(*i, counter + 1);
            }

            else
            {
                if (layer[*i] >= layer[s])
                {
                    bfs(*i, counter + 1);
                }
            }
        }
    }
    return;
}

int main()
{
    read_input();
    init_bfs();
    cin >> start >> target >> my_heights;
    start--;
    target--;
    bfs(start, 0);

    cout << result << endl;
}
