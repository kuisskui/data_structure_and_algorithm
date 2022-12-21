#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n_poles, difference, temp;
    vector<int> all_poles;

    int banner_size = -1;

    cin >> n_poles >> difference;
    for (int i = 0; i < n_poles; i++)
    {
        cin >> temp;
        all_poles.push_back(temp);
    }

    for (auto i = all_poles.begin(); i != all_poles.end(); i++)
    {
        auto j = i;
        // cout << "Pole: " << *i << endl;
        while (true)
        {
            j = lower_bound(j + 1, all_poles.end(), *i - difference);
            // cout << "hello: " << *j << endl;
            if (j == all_poles.end())
            {
                break;
            }
            if (abs(*i - *j) <= difference && find(i + 1, j, *j) == j && find(i + 1, j, *i) == j)
            {
                int x = (j - all_poles.begin()) - (i - all_poles.begin());
                // cout << "size: " << x << endl;
                banner_size = max(banner_size, x);
            }
            // if(*i == *j)
            // {
            //     break;
            // }
        }
        // cout << endl;
    }

    cout << banner_size << endl;
}
