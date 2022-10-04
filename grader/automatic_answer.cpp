#include <iostream>
#include <cstdlib>

using namespace std;

int automatic_answer(int n)
{
    n = n * 567;
    n = n / 9;
    n = n + 7492;
    n = n * 235;
    n = n / 47;
    n = n - 498;
    n = n / 10;
    n = n % 10;
    return abs(n);
}

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << automatic_answer(n) << endl;
    }
}
