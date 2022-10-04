#include <iostream>
using namespace std;

int main()
{
    int n_mountain;
    cin >> n_mountain;
    int array_mountain[n_mountain];
    int array_hid_mountain[n_mountain];
    int lost_mountain = 0;
    int plateau = 0;
    int swamp = 0;

    cin >> array_mountain[0];
    for (int i = 1; i < n_mountain; i++)
    {
        cin >> array_mountain[i];
        if (array_mountain[i] == array_mountain[i - 1])
        {
            array_hid_mountain[lost_mountain] = array_mountain[i];
            lost_mountain++;
            i--;
        }
    }
    // for (int i = 0; i < n_mountain - lost_mountain; i++){
    //     cout << "height : " << array_mountain[i] << endl;
    // }
    int current_mountain = n_mountain - lost_mountain;
    for (int i = 1; i < current_mountain - 1; i++)
    {
        if (array_mountain[i] > array_mountain[i - 1] && array_mountain[i] > array_mountain[i + 1])
        {
            plateau++;
            for (int j = 0; j < lost_mountain; j++)
            {
                if (array_mountain[i] == array_hid_mountain[j])
                {
                    plateau++;
                }
            }
        }
        if (array_mountain[i] < array_mountain[i - 1] && array_mountain[i] < array_mountain[i + 1])
        {
            swamp++;
            for (int j = 0; j < lost_mountain; j++)
            {
                if (array_mountain[i] == array_hid_mountain[j])
                {
                    plateau++;
                }
            }
        }
    }
    cout << "plateau : " << plateau << endl;
    cout << "swamp : " << swamp << endl;
}