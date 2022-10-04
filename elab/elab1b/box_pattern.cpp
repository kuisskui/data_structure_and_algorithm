#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int out_put = j + i - 1;
            if (out_put > n)
            {
                cout << out_put - n;
            }
            else
            {
                cout << out_put;
            }
        }
        cout << endl;
    }
}
