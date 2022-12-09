#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
int main()
{
    int n_testcases, n_battlefields, n_green, n_blue, x;
    list<int> green_lemmings, blue_lemmings;
    cin >> n_testcases;
    while (n_testcases--)
    {
        green_lemmings.clear();
        blue_lemmings.clear();

        cin >> n_battlefields >> n_green >> n_blue;
        for (int i = 0; i < n_green; i++)
        {
            cin >> x;
            green_lemmings.push_back(x);
        }
        for (int i = 0; i < n_blue; i++)
        {
            cin >> x;
            blue_lemmings.push_back(x);
        }
    }
    cout << "Green lemming" << endl;
    for (auto i = green_lemmings.begin(); i != green_lemmings.end(); i++)
    {
        cout << *i << endl;
    }
    cout << endl;
    green_lemmings.sort(greater<int>());
    cout << "Reversed Green lemming" << endl;
    for (auto i = green_lemmings.begin(); i != green_lemmings.end(); i++)
    {
        cout << *i << endl;
    }
    cout << endl;
}