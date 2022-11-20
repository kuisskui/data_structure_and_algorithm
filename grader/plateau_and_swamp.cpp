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

    for (int i = 0; i < n_mountain; i++)
    {
        cin >> array_mountain[i];
    }

    for (int i = 1; i < n_mountain - 1; i++)
    {
        
    }

    cout << "plateau : " << plateau << endl;
    cout << "swamp : " << swamp << endl;
}