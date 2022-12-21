#include <iostream>

using namespace std;

int main()
{
    int n_house, frence, s[100010], t[100010];
    int track_frence = 0;
    int counter_frence = 0;
    cin >> n_house >> frence;
    for (int i = 0; i < n_house; i++)
    {
        cin >> s[i] >> t[i];
        if (track_frence < t[i])
        {
            track_frence = s[i];
        }
        while (track_frence < t[i])
        {
            counter_frence++;
            track_frence += frence;
        }
    }

    cout << counter_frence << endl;
}