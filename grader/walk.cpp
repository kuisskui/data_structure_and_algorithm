#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n_gas_stations, destination, fuel, walk, temp, result;
    result = 0;
    cin >> n_gas_stations >> destination >> fuel >> walk;

    int current_position = 0;
    vector<int> positions;
    for (int i = 0; i < n_gas_stations; i++)
    {
        cin >> temp;
        positions.push_back(temp);
    }

    int next_position;
    while (true)
    {
        next_position = current_position + fuel;
        auto lower = lower_bound(positions.begin(), positions.end(), next_position);
        if (current_position + walk >= destination)
        {
            break;
        }
        if (*lower - next_position > walk)
        {
            current_position = *(--lower);
        }
        else
        {
            current_position = next_position;
        }
        result++;
    }
    cout << result - 1 << endl;
}