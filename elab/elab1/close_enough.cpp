#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int house = 0;
    int distance = 0;

    cin >> house >> distance;

    int house_array[house];
    int i = 0;
    int total = 0;

    while (i < house)
    {
        cin >> house_array[i];
        for (int j = 0; j < i; j++)
        {
            if (abs(house_array[j] - house_array[i]) <= distance)
            {
                total++;
            }
        }
        i++;
    }
    
    cout << total;
}
