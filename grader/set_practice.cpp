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
    int n, m, input, min;
    cin >> n >> m;
    set<int> x;
    int array[100010];

    if (n < m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> input;
            x.insert(input);
        }
        min = n;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            x.insert(input);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> array[i];
        }
        min = m;
    }
    set<int>::iterator upper, lower;
    for (int i = 0; i < min; i++)
    {
        upper = x.upper_bound(array[i]);
        lower = x.lower_bound(array[i]);
        cout << "i: " << array[i] << endl;
        cout << "upper: "<< *upper << endl;
        cout << "lower: "<< *lower << endl;
        if (abs(array[i] - *upper) < abs(array[i] - *lower))
        {
            cout << *upper << endl;
        }
        else
        {
            cout << *lower << endl;
        }
    }
}