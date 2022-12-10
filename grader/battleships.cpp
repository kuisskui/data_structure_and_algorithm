#include <iostream>
#include <vector>
using namespace std;
const int MAX = 110;

char map[MAX][MAX];
int seen_map[MAX][MAX];
int fields;
int counter = 0;

bool is_found_ship = false;

void print_map()
{
    for (int i = 0; i < fields; i++)
    {
        for (int j = 0; j < fields; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void print_seen_map()
{
    for (int i = 0; i < fields; i++)
    {
        for (int j = 0; j < fields; j++)
        {
            cout << seen_map[i][j] << ' ';
        }
        cout << endl;
    }
}

void clear_seen()
{
    for (int i = 0; i < fields; i++)
    {
        for (int j = 0; j < fields; j++)
        {
            seen_map[i][j] = 0;
        }
    }
}

void bfs(int r, int c)
{
    if (r < 0 || r >= fields || c < 0 || c >= fields)
    {
        return;
    }
    if (seen_map[r][c])
    {
        return;
    }
    if (map[r][c] == '.')
    {
        return;
    }
    if (map[r][c] == 'x')
    {
        is_found_ship = true;
    }
    seen_map[r][c] = 1;

    bfs(r + 1, c);
    bfs(r - 1, c);
    bfs(r, c + 1);
    bfs(r, c - 1);
}

int main()
{
    int n_testcases;
    cin >> n_testcases;
    for (int i = 0; i < n_testcases; i++)
    {
        cin >> fields;
        counter = 0;
        char *input_row = new char[MAX];

        for (int i = 0; i < fields; i++)
        {
            cin >> input_row;
            for (int j = 0; j < fields; j++)
            {
                map[i][j] = input_row[j];
            }
        }

        for (int i = 0; i < fields; i++)
        {
            for (int j = 0; j < fields; j++)
            {
                is_found_ship = false;

                bfs(i, j);
                if (is_found_ship)
                {
                    ++counter;
                }
            }
        }
        cout << "Case " << i + 1 << ": " << counter << endl;
        delete input_row;
        clear_seen();
    }
}