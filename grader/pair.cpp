#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, G, T, temp;
    int count = 0;
    cin >> N >> G >> T;

    vector<int> X;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        X.push_back(temp);
    }

    sort(X.begin(), X.end());
    for (auto i = X.begin(); i != X.end(); i++)
    {
        auto lower = lower_bound(i+1, X.end(), G - T - *i);

        while(*lower + *i <= G+T && *lower + *i >= G-T)
        {
            lower++;
            count++;
        }

    }

    cout << count << endl;
}