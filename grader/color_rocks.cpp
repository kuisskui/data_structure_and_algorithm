#include <iostream>
using namespace std;

int main()
{
    int n;
    int stack;
    bool state = false;
    cin >> n >> stack;
    int result = n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int loop = i - (stack - 1);
        for (int j = loop; j < i; j++)
        {
            if (j < 0)
            {
                break;
            }
            else if (a[j] == a[i])
            {
                state = true;
                continue;
            }
            else
            {
                state = false;
                break;
            }
        }
        if (state)
        {
            i -= stack;
            result -= stack;
            state = false;
        }
    }
    cout << result;

    // for (int i = 0; i < n;i++){
    //     cout << a[i] << endl;
    // }
}