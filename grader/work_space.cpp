#include <iostream>
#include <vector>

using namespace std;

int n_nodes, n_edges;
int my_speed;
int n_questions;
int start;
int target;
int power;

const int MAX_NODES = 10000;
vector<int> adjacency[MAX_NODES];

int degree[MAX_NODES];
int layer[MAX_NODES];
int min_speed[MAX_NODES][MAX_NODES];
bool seen[MAX_NODES];
bool is_possible = false;

void read_input()
{
    cin >> n_nodes >> n_edges >> my_speed >> n_questions;
    // for (int i = 0; i < n_nodes; i++)
    // {
    //     degree[i] = 0;
    // }

    for (int i = 0; i < n_edges; i++)
    {
        int u, v, s;
        cin >> u >> v >> s;
        u--;
        v--;
        min_speed[u][v] = s;
        min_speed[v][u] = s;

        adjacency[u].push_back(v);
        degree[u]++;
        adjacency[v].push_back(u);
        degree[v]++;
    }
}

void print_min_speed()
{
    for (int i = 0; i < n_edges;i++)
    {
        for (int j = 0; j < n_edges;j++)
        {
            cout << min_speed[i][j] << ' ';
        }
        cout << endl;
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

void bfs(int s, bool seen_local[MAX_NODES])
{
    if (s == target)
    {
        is_possible = true;
        return;
    }
    seen_local[s] = true;
    for (auto i = adjacency[s].begin(); i != adjacency[s].end(); i++)
    {
        if (my_speed >= min_speed[s][*i])
        {
            // if (difference > 0)
            // {
            //     power -= difference;
            // }
            bfs(*i, seen_local);
        }
    }
    return;
}

int main()
{
    read_input();
    print_adjacency(adjacency, n_nodes);
    print_min_speed();
    while(true)
    {
        is_possible = false;
        init_bfs();
        cin >> start >> target;
        start--;
        target--;
        bfs(start, seen);
        if (is_possible)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
