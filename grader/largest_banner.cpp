#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n_poles, temp;
    vector<int> all_poles;
    int banner_size = -1;

    cin >> n_poles;
    for (int i = 0; i < n_poles; i++)
    {
        cin >> temp;
        all_poles.push_back(temp);
    }

    for (auto i = all_poles.begin(); i != all_poles.end(); i++)
    {
        int counter = 0;
        auto x = i + 1;
        for (auto j = x; j != all_poles.end(); j++)
        {
            counter++;
            if (*i == *j)
            {
                if (counter > banner_size)
                {
                    banner_size = counter;
                }
                break;
            }
        }
    }
    cout << banner_size << endl;
}