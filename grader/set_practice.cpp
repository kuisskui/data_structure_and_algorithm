#include <iostream>
#include <set>

using namespace std;

void display(set<int> s)
{
    for (auto itr : s)
    {
        cout << itr << " ";
    }
    cout << endl;
}

int main()
{
    int n, m, input;
    cin >> n >> m;
    set<int> x;
    int array[100010];

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        x.insert(input);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> array[i];
    }

    set<int>::iterator upper, lower;
    for (int i = 0; i < m; i++)
    {

        // if (x.find(array[i]) != x.end())
        // {
        //     // std::cout << "Element is present in the set" << std::endl;
        //     cout << array[i] << endl;
        //     state = false;
        //     continue;
        // }
        // else
        // {
        //     x.insert(array[i]);
        //     state = true;
        // }
        // cout << "show all:" << endl;
        // for (std::set<int>::iterator i = x.begin(); i != x.end(); ++i)
        //             std::cout
        //      << ' ' << *i;

        // std::cout << ' ' << endl;

        lower = x.lower_bound(array[i]);
        if (lower == x.begin())
        {
            lower = x.lower_bound(array[i]);
            cout << *lower << endl;
            continue;
        }
        lower = x.lower_bound(array[i]);
        if (lower == x.end())
        {
            cout << *(--lower) << endl;
            continue;
        }
        lower = x.lower_bound(array[i]);
        // cout << "------------------------------" << endl;
        // cout << "element: " << array[i] << endl;
        // cout << "upper: " << *lower << endl;
        // cout << "lower: " << *(--lower) << endl;
        int more = abs(array[i] - *lower);
        int less = abs(array[i] - *(--lower));
        if (less <= more)
        {
            cout << *lower << endl;
        }
        else
        {
            lower++;
            cout << *lower << endl;
        }
    }
}