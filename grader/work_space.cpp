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
    cin >> n_poles;
    for (int i = 1; i <= n_poles; i++)
    {
        all_poles.push_back(i);
    }
    auto j = all_poles.begin() + 5; // number 6
    auto it = find(all_poles.begin(), j, 6);
    bool al = it == j;
    cout << *it << endl;
    cout << al << endl;
}
