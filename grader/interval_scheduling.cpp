#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 100010;

int n;
int s[MAX_N], t[MAX_N];
vector<pair<int, int>> items;

void read_input()
{
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> s[i] >> t[i];
        items.push_back(make_pair(t[i], i));
    }
}

int main()
{
    int counter = 0;
    int time_line = 0;
    int index_current_job, s_next_job;
    read_input();
    sort(items.begin(), items.end());
    for (int i = 0; i < n; i++)
    {
        index_current_job = items[i].second;
        if (s[index_current_job] >= time_line)
        {
            ++counter;
            time_line = t[index_current_job];
        }
    }
    cout << counter << endl;
}