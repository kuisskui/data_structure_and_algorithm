#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 100010;

int babies, total_gems;
int start[MAX_N], termi[MAX_N];
vector<pair<int, int>> items;

void read_input()
{
    cin >> total_gems >> babies;
    for (int i = 0; i < babies; i++)
    {
        cin >> start[i] >> termi[i];
        if (termi[i] <= total_gems)
        {
            items.push_back(make_pair(termi[i], i));
        }
    }
}

int main()
{
    int counter = 0;
    int time_line = 0;
    int index_current_baby;
    read_input();
    sort(items.begin(), items.end());
    for (int i = 0; i < babies; i++)
    {
        index_current_baby = items[i].second;
        if (start[index_current_baby] > time_line)
        {
            ++counter;
            time_line = termi[index_current_baby];
        }
    }
    cout << counter << endl;
}