#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int MAX = 20;

char map[MAX][MAX];
int seen_map[MAX][MAX];
int row, column;
int largest = 0;
int counter = 0;
pair<int, int> resides;

char land_letter;

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
void print_seen()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << seen_map[i][j] << ' ';
        }
        cout << endl;
    }
}
void clear_seen()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            seen_map[i][j] = 0;
        }
    }
}

void bfs(int r, int c)
{
    if (c < 0)
    {
        c = column - 1;
    }
    if (c >= column)
    {
        c = 0;
    }

    if (r < 0 || r >= row || c < 0 || c >= column)
    {
        return;
    }
    if (seen_map[r][c])
    {
        return;
    }
    if (map[r][c] != land_letter)
    {
        return;
    }
    seen_map[r][c] = 1;
    ++counter;

    bfs(r + 1, c);
    bfs(r - 1, c);
    bfs(r, c + 1);
    bfs(r, c - 1);
}

int main()
{
    while (cin >> row)
    {
        cin >> column;

        char *input_row = new char[MAX];

        for (int i = 0; i < row; i++)
        {
            cin >> input_row;
            for (int j = 0; j < column; j++)
            {
                map[i][j] = input_row[j];
            }
        }
        cin >> resides.first >> resides.second;

        counter = 0;
        land_letter = map[resides.first][resides.second];
        bfs(resides.first, resides.second);
        largest = 0;

        // print_seen();
        // print_map();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                counter = 0;
                bfs(i, j);
                if (counter > largest)
                {
                    largest = counter;
                }
            }
        }
        cout << largest << endl;
        delete input_row;
        clear_seen();
    }
}