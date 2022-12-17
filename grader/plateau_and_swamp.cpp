#include <iostream>
using namespace std;

int main()
{
    int n_mountain, left_pointer, right_pointer, current_pointer;
    int status_left;
    int status_right;
    cin >> n_mountain;
    int array_mountain[n_mountain];
    int plateau = 0;
    int swamp = 0;

    for (int i = 0; i < n_mountain; i++)
    {
        cin >> array_mountain[i];
    }

    for (int i = 1; i < n_mountain - 1; i++)
    {
        current_pointer = i;
        left_pointer = i;
        right_pointer = i;
        status_left = 0;
        status_right = 0;

        // check left mountain
        while (status_left == 0)
        {
            left_pointer--;
            if (left_pointer == -1)
            {
                break;
            }
            if (array_mountain[left_pointer] < array_mountain[i])
            {
                status_left = -1;
            }
            else if (array_mountain[left_pointer] > array_mountain[i])
            {
                status_left = 1;
            }
        }

        // check right mountain
        while (status_right == 0)
        {
            right_pointer++;
            if (right_pointer == n_mountain)
            {
                break;
            }
            if (array_mountain[right_pointer] < array_mountain[i])
            {
                status_right = -1;
            }
            else if (array_mountain[right_pointer] > array_mountain[i])
            {
                status_right = 1;
            }
        }
        if (status_left == 1 && status_right == 1)
        {
            swamp++;
        }
        else if (status_left == -1 && status_right == -1)
        {
            plateau++;
        }
    }
    cout << plateau << ' ' << swamp << endl;
}