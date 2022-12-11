#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n_drivers, time, overtime_rate, temp, result;
    vector<int> morning;
    vector<int> evening;

    while (true)
    {
        result = 0;
        morning.clear();
        evening.clear();
        cin >> n_drivers >> time >> overtime_rate;
        if (n_drivers == 0 && time == 0 && overtime_rate == 0)
        {
            break;
        }
        for (int i = 0; i < n_drivers; i++)
        {
            cin >> temp;
            morning.push_back(temp);
        }
        for (int i = 0; i < n_drivers; i++)
        {
            cin >> temp;
            evening.push_back(temp);
        }
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end(), greater<int>());
        for (int i = 0; i < n_drivers; i++)
        {
            temp = morning.at(i) + evening.at(i);
            if (temp > time)
            {
                result += (temp - time) * overtime_rate;
            }
        }
        cout << result << endl;
    }
}