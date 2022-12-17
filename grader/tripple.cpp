#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers;
    int n_number, temp, result;
    result = 0;
    cin >> n_number;
    for (int i = 0; i < n_number; i++)
    {
        cin >> temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());
    numbers.push_back(-1);
    // for (auto i = numbers.begin(); i != numbers.end(); i++)
    // {
    //     cout << *i << ", ";
    // }
    // cout << endl;

    temp = 1;
    int last_number = numbers.front();
    for (auto i = numbers.begin() + 1; i != numbers.end(); i++)
    {
        if (*i == last_number)
        {
            temp++;
        }
        else
        {
            temp = 1;
            last_number = *i;
        }
        if (temp >= 3)
        {
            result++;
            i = upper_bound(numbers.begin(), numbers.end(), *i);
            i--;
        }
    }
    cout << result << endl;
}