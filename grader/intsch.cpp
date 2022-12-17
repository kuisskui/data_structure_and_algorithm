#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 100010;

int n;
int s[MAX_N], t[MAX_N];
vector<pair<int, int> > items;

void read_input()
{
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> s[i] >> t[i];
        items.push_back(make_pair(t[i], i));
    }
}

void print_items(int n, vector<pair<int, int> > items)
{
    for (int i = 0; i < n;i++)
        cout << "Items: " << "";
}

int main()
{
    int counter = 0;
    int t_current_job, s_next_job;
    read_input();
    sort(items.begin(), items.end());
    t_current_job = t[items[0].second];
    for (int i = 1; i < n; i++)
    {
        s_next_job = s[items[i].second];
        if (t_current_job <= s_next_job)
        {
            t_current_job = t[items[i].second];
            counter += 1;
        }
    }
    cout << counter << endl;
}