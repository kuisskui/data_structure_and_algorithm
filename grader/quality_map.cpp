#include <iostream>
#include <vector>
using namespace std;
const int MAX = 31;

char map[MAX][MAX];
int seen_map[MAX][MAX];
int row, column;
int counter = 0;

bool is_found_star = false;
bool is_found_dollar = false;

int great = 0;
int good = 0;

void print_map()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void bfs(int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= column)
    {
        return;
    }
    if (seen_map[r][c])
    {
        return;
    }
    seen_map[r][c] = true;
    if (map[r][c] == '#')
    {
        return;
    }
    ++counter;

    if (map[r][c] == '*')
    {
        is_found_star = true;
    }
    else if (map[r][c] == '$')
    {
        is_found_dollar = true;
    }
    bfs(r + 1, c);
    bfs(r - 1, c);
    bfs(r, c + 1);
    bfs(r, c - 1);
}

int main()
{
    cin >> row >> column;

    char *input_row = new char[MAX];

    for (int i = 0; i < row; i++)
    {
        cin >> input_row;
        for (int j = 0; j < column; j++)
        {
            map[i][j] = input_row[j];
        }
    }
    print_map();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            counter = 0;

            is_found_star = false;
            is_found_dollar = false;

            bfs(i, j);
            if (is_found_star && is_found_dollar)
            {
                great = great + counter;
            }
            else if (is_found_star || is_found_dollar)
            {
                good = good + counter;
            }
        }
    }
    cout << great << " " << good;
}