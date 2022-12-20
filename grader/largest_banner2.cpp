#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else
    {
        // If the element is not
        // present in the vector
        return -1;
    }
}

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
        cout << "Pole: " << *i << endl;
        while (true)
        {
            j = lower_bound(j + 1, all_poles.end(), *i - difference);
            if (j == all_poles.end())
            {
                break;
            }
            if (abs(*i - *j) <= difference && find(i + 1, j, *j) == j && find(i + 1, j, *i) == j)
            {
                cout << "size: " << getIndex(all_poles, *j) - getIndex(all_poles, *i) << endl;
                banner_size = max(banner_size, getIndex(all_poles, *j) - getIndex(all_poles, *i));
            }
        }
        cout << endl;
    }

    cout << banner_size << endl;
}
