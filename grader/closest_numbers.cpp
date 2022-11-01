#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sort(array, array + n);

    int min = 9999;
    int diff;
    for (int i = 0; i < n - 1; i++)
    {
        diff = abs(array[i] - array[i + 1]);
        if (diff < min)
        {
            min = diff;
        }
    }
    cout << min;
}
